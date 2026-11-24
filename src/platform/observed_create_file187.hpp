// Forward and observe the actual original CreateFileA boundary.
#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>

namespace ra2::platform::file187 {
// This observer records exact arguments and immediately forwards every call
// to Kernel32. It never fabricates a HANDLE or error code. The game import
// slot points here only so the native harness can observe the actual call.
class Observer {
    struct Event {
        std::array<char, 20> filename{};
        DWORD access{}, share{}, disposition{}, attributes{}, error{};
        std::uint32_t result{};
        bool null_security{}, null_template{};
    };
    inline static Observer* active_{};
    std::array<Event, 2> events_{};
    unsigned count_{};
    bool violation_{};

    static void copy_name(Event& e, LPCSTR p) noexcept {
        if (!p) { e.filename[0] = '\0'; return; }
        unsigned n = 0;
        for (; n + 1 < e.filename.size() && p[n]; ++n) e.filename[n] = p[n];
        e.filename[n] = '\0';
        if (p[n] != '\0') e.filename[0] = '\1';
    }
    static bool require(bool ok, const char* message) {
        if (!ok) throw std::runtime_error(message);
        return ok;
    }
public:
    Observer() { static_assert(sizeof(void*) == 4, "original IAT function pointer width"); }
    Observer(const Observer&) = delete;
    Observer& operator=(const Observer&) = delete;
    ~Observer() { if (active_ == this) active_ = nullptr; }

    void begin() {
        require(active_ == nullptr, "CreateFileA observer already active");
        events_ = {};
        count_ = 0;
        violation_ = false;
        active_ = this;
    }

    static HANDLE WINAPI forward(LPCSTR name, DWORD access, DWORD share,
                                 LPSECURITY_ATTRIBUTES security, DWORD disposition,
                                 DWORD attributes, HANDLE template_file) noexcept {
        auto* self = active_;
        Event* event = nullptr;
        if (!self || self->count_ >= self->events_.size()) {
            if (self) self->violation_ = true;
        } else {
            event = &self->events_[self->count_++];
            copy_name(*event, name);
            event->access = access;
            event->share = share;
            event->disposition = disposition;
            event->attributes = attributes;
            event->null_security = security == nullptr;
            event->null_template = template_file == nullptr;
        }

        // Preserve the real API's last-error value across observer bookkeeping.
        const HANDLE result = ::CreateFileA(name, access, share, security,
                                            disposition, attributes, template_file);
        const DWORD error = GetLastError();
        if (event) {
            event->error = error;
            event->result = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(result));
        }
        if (self && result != INVALID_HANDLE_VALUE) self->violation_ = true;
        SetLastError(error);
        return result;
    }

    // Used by the recovered C++ body. The same forwarding function is bound
    // into the original image IAT for native-original execution.
    static HANDLE create_file_a(LPCSTR name, DWORD access, DWORD share,
                                LPSECURITY_ATTRIBUTES security, DWORD disposition,
                                DWORD attributes, HANDLE template_file) noexcept {
        return forward(name, access, share, security, disposition, attributes,
                       template_file);
    }

    template<class Memory> void bind(Memory& memory) const {
        memory.w32(0x007851b0u, static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&forward)));
    }
    static void bind_native_iat() {
        *reinterpret_cast<volatile std::uint32_t*>(0x007851b0u) =
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&forward));
    }

    void finish() {
        if (active_ == this) active_ = nullptr;
        require(!violation_ && count_ == 2, "unexpected CreateFileA call count/result");
        constexpr const char* names[] = {"PBEACON.SHP", "RDRBEACN.SHP"};
        for (unsigned n = 0; n < 2; ++n) {
            const auto& e = events_[n];
            require(std::strcmp(e.filename.data(), names[n]) == 0,
                    "CreateFileA filename/order mismatch");
            require(e.access == 0x80000000u && e.share == 1u &&
                    e.disposition == OPEN_EXISTING && e.attributes == FILE_ATTRIBUTE_NORMAL &&
                    e.null_security && e.null_template,
                    "CreateFileA argument mismatch");
            require(e.result == 0xffffffffu && e.error == ERROR_FILE_NOT_FOUND,
                    "fresh-empty-CWD CreateFileA did not return real file-not-found");
        }
    }
};
} // namespace ra2::platform::file187
