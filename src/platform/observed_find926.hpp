#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>
#include "recovered/recovery_b926.hpp"

namespace ra2::platform::find926 {
struct Event {
    enum class Kind { begin, first, next, close, finish } kind{};
    std::uintptr_t handle = 0;
    std::uintptr_t data = 0;
    BOOL result = FALSE;
    std::string query;
    DWORD attributes = 0;
    std::string name;
    std::uint32_t normalized_handle = 0;
    std::uint32_t normalized_data = 0;
};

class Observer {
    using First = HANDLE (WINAPI*)(LPCSTR, LPWIN32_FIND_DATAA);
    using Next = BOOL (WINAPI*)(HANDLE, LPWIN32_FIND_DATAA);
    using Close = BOOL (WINAPI*)(HANDLE);
    static Observer* active_;
    First first_ = nullptr;
    Next next_ = nullptr;
    Close close_ = nullptr;
    std::vector<Event> events_;
    bool active_lifecycle_ = false;
    static HANDLE WINAPI first_thunk(LPCSTR, LPWIN32_FIND_DATAA);
    static BOOL WINAPI next_thunk(HANDLE, LPWIN32_FIND_DATAA);
    static BOOL WINAPI close_thunk(HANDLE);
public:
    explicit Observer(First f = ::FindFirstFileA, Next n = ::FindNextFileA, Close c = ::FindClose)
        : first_(f), next_(n), close_(c) {}
    ~Observer() { if (active_ == this) active_ = nullptr; }
    void begin();
    void finish();
    void end() { finish(); }
    // Bind the three guest IAT slots to real forwarding thunks in a 32-bit
    // native bridge. The portable model uses the same public observer seam.
    void bind(ra2::recovered::recovery_b926::Memory&);
    const std::vector<Event>& events() const { return events_; }
    std::vector<Event> normalized_trace() const;
    bool same_normalized_trace(const Observer&) const;
    HANDLE first(LPCSTR, LPWIN32_FIND_DATAA);
    BOOL next(HANDLE, LPWIN32_FIND_DATAA);
    BOOL close(HANDLE);
    static HANDLE first_active(LPCSTR, LPWIN32_FIND_DATAA);
    static BOOL next_active(HANDLE, LPWIN32_FIND_DATAA);
    static BOOL close_active(HANDLE);
    static HANDLE WINAPI iat_first(LPCSTR, LPWIN32_FIND_DATAA);
    static BOOL WINAPI iat_next(HANDLE, LPWIN32_FIND_DATAA);
    static BOOL WINAPI iat_close(HANDLE);
};

// A private, uniquely named directory owned by this harness. It contains only
// the two files needed by B926, and is removed only after restoring the CWD.
class Fixture {
    std::wstring dir_;
    std::wstring old_cwd_;
    bool entered_ = false;
    bool save_owned_ = false;
    bool aux_owned_ = false;
    bool finished_ = false;
    bool placeholder_owned_ = false;
    bool directory_owned_ = false;
    bool create_file(const wchar_t*);
    void remove_owned_checked();
public:
    Fixture();
    ~Fixture();
    // mode 1: SAVEGAME.NET only; 2: AUXDATA.NET only; 3: both.
    void reset(unsigned mode);
    void finish();
    const std::wstring& path() const { return dir_; }
    Fixture(const Fixture&) = delete;
    Fixture& operator=(const Fixture&) = delete;
};
}
