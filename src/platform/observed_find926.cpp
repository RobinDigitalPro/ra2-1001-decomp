#define NOMINMAX
#include "recovered/recovery_b926.hpp"
#include "platform/observed_find926.hpp"
#include "recovered/crt_b83.hpp"
#include <windows.h>
#include <array>
#include <stdexcept>
#include <string>
#include <utility>
#include <limits>
#include <map>

namespace ra2::platform::find926 {
Observer* Observer::active_ = nullptr;
namespace {
std::string defined_name(const WIN32_FIND_DATAA& d) {
    std::size_t n = 0;
    while (n < MAX_PATH && d.cFileName[n]) ++n;
    return std::string(d.cFileName, n);
}
}
void Observer::begin() {
    if (active_ && active_ != this) throw std::logic_error("B926 observer already active");
    events_.clear(); active_ = this; active_lifecycle_ = true;
    Event marker{}; marker.kind = Event::Kind::begin; events_.push_back(marker);
}
void Observer::finish() {
    if (!active_lifecycle_ || active_ != this) throw std::logic_error("B926 observer lifecycle mismatch");
    Event marker{}; marker.kind = Event::Kind::finish; events_.push_back(marker);
    active_ = nullptr; active_lifecycle_ = false;
}
void Observer::bind(ra2::recovered::recovery_b926::Memory& m) {
    static_assert(sizeof(void*) == 4, "B926 native IAT binding requires the 32-bit runner");
    m.w32(0x7851fcu, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&iat_first)));
    m.w32(0x785200u, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&iat_next)));
    m.w32(0x7852f8u, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&iat_close)));
}
std::vector<Event> Observer::normalized_trace() const {
    std::map<std::uintptr_t, std::uint32_t> handles, buffers;
    std::uint32_t next_handle = 1, next_buffer = 1;
    std::vector<Event> out = events_;
    for (auto& e : out) {
        if (e.handle) {
            auto it = handles.find(e.handle);
            if (it == handles.end()) it = handles.emplace(e.handle, next_handle++).first;
            e.normalized_handle = it->second; e.handle = 0;
        }
        if (e.data) {
            auto it = buffers.find(e.data);
            if (it == buffers.end()) it = buffers.emplace(e.data, next_buffer++).first;
            e.normalized_data = it->second; e.data = 0;
        }
    }
    return out;
}
bool Observer::same_normalized_trace(const Observer& other) const {
    const auto a = normalized_trace(), b = other.normalized_trace();
    if (a.size() != b.size()) return false;
    for (std::size_t k = 0; k < a.size(); ++k) {
        if (a[k].kind != b[k].kind || a[k].normalized_handle != b[k].normalized_handle ||
            a[k].normalized_data != b[k].normalized_data || a[k].result != b[k].result ||
            a[k].query != b[k].query || a[k].attributes != b[k].attributes || a[k].name != b[k].name) return false;
    }
    return true;
}
HANDLE Observer::first(LPCSTR q, LPWIN32_FIND_DATAA d) {
    Event e{}; e.kind = Event::Kind::first; e.query = q ? q : "";
    e.data = reinterpret_cast<std::uintptr_t>(d);
    HANDLE h = first_(q, d); e.handle = reinterpret_cast<std::uintptr_t>(h);
    e.result = h != INVALID_HANDLE_VALUE;
    if (e.result && d) { e.attributes = d->dwFileAttributes; e.name = defined_name(*d); }
    events_.push_back(std::move(e)); return h;
}
BOOL Observer::next(HANDLE h, LPWIN32_FIND_DATAA d) {
    Event e{}; e.kind = Event::Kind::next; e.handle = reinterpret_cast<std::uintptr_t>(h);
    e.data = reinterpret_cast<std::uintptr_t>(d);
    e.result = next_(h, d);
    if (e.result && d) { e.attributes = d->dwFileAttributes; e.name = defined_name(*d); }
    events_.push_back(std::move(e)); return events_.back().result;
}
BOOL Observer::close(HANDLE h) {
    Event e{}; e.kind = Event::Kind::close; e.handle = reinterpret_cast<std::uintptr_t>(h);
    e.result = close_(h); events_.push_back(e); return e.result;
}
HANDLE WINAPI Observer::first_thunk(LPCSTR q, LPWIN32_FIND_DATAA d) {
    return active_ ? active_->first(q, d) : INVALID_HANDLE_VALUE;
}
BOOL WINAPI Observer::next_thunk(HANDLE h, LPWIN32_FIND_DATAA d) {
    return active_ ? active_->next(h, d) : FALSE;
}
BOOL WINAPI Observer::close_thunk(HANDLE h) { return active_ ? active_->close(h) : FALSE; }
HANDLE WINAPI Observer::iat_first(LPCSTR q, LPWIN32_FIND_DATAA d) { return first_thunk(q, d); }
BOOL WINAPI Observer::iat_next(HANDLE h, LPWIN32_FIND_DATAA d) { return next_thunk(h, d); }
BOOL WINAPI Observer::iat_close(HANDLE h) { return close_thunk(h); }
HANDLE Observer::first_active(LPCSTR q, LPWIN32_FIND_DATAA d) { return first_thunk(q, d); }
BOOL Observer::next_active(HANDLE h, LPWIN32_FIND_DATAA d) { return next_thunk(h, d); }
BOOL Observer::close_active(HANDLE h) { return close_thunk(h); }

bool Fixture::create_file(const wchar_t* name) {
    std::wstring path = dir_ + L"\\" + name;
    HANDLE f = CreateFileW(path.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (f == INVALID_HANDLE_VALUE) return false;
    if (name[0] == L'S') save_owned_ = true; else aux_owned_ = true;
    const char byte = 'x'; DWORD wrote = 0;
    const BOOL ok = WriteFile(f, &byte, 1, &wrote, nullptr);
    const BOOL closed = CloseHandle(f);
    return ok && wrote == 1 && closed != FALSE;
}
void Fixture::remove_owned_checked() {
    if (entered_) {
        if (!SetCurrentDirectoryW(old_cwd_.c_str())) throw std::runtime_error("B926 restore CWD failed");
        entered_ = false;
        std::wstring actual(32768, L'\0'); const DWORD n = GetCurrentDirectoryW(static_cast<DWORD>(actual.size()), actual.data());
        if (!n || n >= actual.size()) throw std::runtime_error("B926 verify CWD failed"); actual.resize(n);
        if (CompareStringOrdinal(actual.c_str(), -1, old_cwd_.c_str(), -1, TRUE) != CSTR_EQUAL) throw std::runtime_error("B926 restored CWD mismatch");
    }
    if (save_owned_) { if (!DeleteFileW((dir_ + L"\\SAVEGAME.NET").c_str()) && GetLastError() != ERROR_FILE_NOT_FOUND) throw std::runtime_error("B926 delete owned SAVEGAME.NET failed"); save_owned_ = false; }
    if (aux_owned_) { if (!DeleteFileW((dir_ + L"\\AUXDATA.NET").c_str()) && GetLastError() != ERROR_FILE_NOT_FOUND) throw std::runtime_error("B926 delete owned AUXDATA.NET failed"); aux_owned_ = false; }
}
Fixture::Fixture() {
    const wchar_t* parent = L"analysis\\recovery100_after6133\\source_families\\after79\\draft926\\owned_fixtures";
    if (!CreateDirectoryW(parent, nullptr) && GetLastError() != ERROR_ALREADY_EXISTS) throw std::runtime_error("B926 create owned fixture parent failed");
    wchar_t unique[MAX_PATH + 1]{};
    if (!GetTempFileNameW(parent, L"r92", 0, unique)) throw std::runtime_error("B926 GetTempFileNameW failed");
    wchar_t absolute[32768]{};const DWORD length=GetFullPathNameW(unique,32768,absolute,nullptr);if(!length||length>=32768)throw std::runtime_error("926 canonical fixture path");dir_.assign(absolute,length);
    try {
        placeholder_owned_ = true;
        if (!DeleteFileW(dir_.c_str())) throw std::runtime_error("B926 remove generated placeholder failed");
        placeholder_owned_ = false;
        if (!CreateDirectoryW(dir_.c_str(), nullptr)) throw std::runtime_error("B926 CreateDirectoryW failed");
        directory_owned_ = true;
        const DWORD need = GetCurrentDirectoryW(0, nullptr);
        if (!need || need > 32768) throw std::runtime_error("B926 GetCurrentDirectoryW size failed");
        old_cwd_.resize(need);
        const DWORD got = GetCurrentDirectoryW(need, old_cwd_.data());
        if (!got || got >= need) throw std::runtime_error("B926 GetCurrentDirectoryW failed");
        old_cwd_.resize(got);
        if (!SetCurrentDirectoryW(dir_.c_str())) throw std::runtime_error("B926 SetCurrentDirectoryW failed");
        entered_ = true;
        reset(3);
    } catch (...) {
        try { remove_owned_checked(); } catch (...) {}
        if (directory_owned_) { RemoveDirectoryW(dir_.c_str()); directory_owned_ = false; }
        if (placeholder_owned_) { DeleteFileW(dir_.c_str()); placeholder_owned_ = false; }
        throw;
    }
}
void Fixture::reset(unsigned mode) {
    if (mode < 1 || mode > 3 || finished_) throw std::invalid_argument("B926 invalid fixture mode/lifecycle");
    if (save_owned_) { if (!DeleteFileW((dir_ + L"\\SAVEGAME.NET").c_str())) throw std::runtime_error("B926 reset SAVEGAME.NET failed"); save_owned_ = false; }
    if (aux_owned_) { if (!DeleteFileW((dir_ + L"\\AUXDATA.NET").c_str())) throw std::runtime_error("B926 reset AUXDATA.NET failed"); aux_owned_ = false; }
    if ((mode & 1u) && !create_file(L"SAVEGAME.NET")) throw std::runtime_error("B926 create owned SAVEGAME.NET failed");
    if ((mode & 2u) && !create_file(L"AUXDATA.NET")) throw std::runtime_error("B926 create owned AUXDATA.NET failed");
}
void Fixture::finish() {
    if (finished_) throw std::logic_error("B926 fixture already finished");
    remove_owned_checked();
    if (!directory_owned_ || !RemoveDirectoryW(dir_.c_str())) throw std::runtime_error("B926 remove owned fixture directory failed");
    directory_owned_ = false;
    DWORD attr = GetFileAttributesW(dir_.c_str());
    if (attr != INVALID_FILE_ATTRIBUTES) throw std::runtime_error("B926 owned fixture directory still exists");
    finished_ = true;
}
Fixture::~Fixture() {
    if (finished_) return;
    try { remove_owned_checked(); } catch (...) {}
    if (directory_owned_) { RemoveDirectoryW(dir_.c_str()); directory_owned_ = false; }
    if (placeholder_owned_) { DeleteFileW(dir_.c_str()); placeholder_owned_ = false; }
}
}
