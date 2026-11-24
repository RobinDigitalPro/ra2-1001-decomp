#pragma once
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <exception>

namespace locks_b949 {
class ActualLock {
    CRITICAL_SECTION cs_{};
    std::uint32_t expected_pairs_=0, completed_pairs_=0, case_event_calls_=0;
    std::uint32_t total_pairs_=0, total_event_calls_=0;
    mutable std::uint32_t ownership_checks_=0;
    bool callback_fault_=false;
    bool entered_=false;
    static inline ActualLock* active_=nullptr;
    void record(bool enter) {
        ++case_event_calls_; ++total_event_calls_;
        if (enter) {
            if (entered_ || completed_pairs_>=expected_pairs_) throw std::runtime_error("B949 unexpected EnterCriticalSection");
            entered_=true;
        } else {
            if (!entered_) throw std::runtime_error("B949 LeaveCriticalSection without enter");
            entered_=false; ++completed_pairs_; ++total_pairs_;
        }
    }
    void record_callback(bool enter) noexcept {
        try { record(enter); } catch (...) { callback_fault_=true; }
    }
    static void WINAPI enter_thunk(LPCRITICAL_SECTION p) {
        if (!active_ || p!=&active_->cs_) RaiseFailFastException(nullptr,nullptr,0);
        EnterCriticalSection(p); active_->record_callback(true);
    }
    static void WINAPI leave_thunk(LPCRITICAL_SECTION p) {
        if (!active_ || p!=&active_->cs_) RaiseFailFastException(nullptr,nullptr,0);
        LeaveCriticalSection(p); active_->record_callback(false);
    }
    void verify_balanced() const {
        if (callback_fault_ || entered_ || expected_pairs_!=completed_pairs_ || cs_.RecursionCount!=0 || cs_.OwningThread!=0 || cs_.LockCount!=-1)
            throw std::runtime_error("B949 real critical section/event count is unbalanced");
    }
    void verify_unowned() const {
        ++ownership_checks_;
        if (callback_fault_ || entered_ || cs_.RecursionCount!=0 || cs_.OwningThread!=0 || cs_.LockCount!=-1)
            throw std::runtime_error("B949 critical section remains owned after side");
    }
public:
    ActualLock() {
        if (active_) throw std::runtime_error("B949 adapter must be exclusive");
        InitializeCriticalSection(&cs_); active_=this;
    }
    ~ActualLock() noexcept(false) {
        verify_balanced(); active_=nullptr; DeleteCriticalSection(&cs_);
    }
    static ActualLock& current() { if(!active_) throw std::runtime_error("B949 adapter not active"); return *active_; }
    template<class Memory> void bind(Memory& m) {
        static_assert(sizeof(void*)==4,"B949 original bridge requires x86");
        m.w32(0x8172c4u,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&cs_)));
        m.w32(0x7851dcu,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&enter_thunk)));
        m.w32(0x7851e0u,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&leave_thunk)));
    }
    void begin_case(std::uint32_t expected_pairs) {
        if (expected_pairs_!=completed_pairs_ || entered_) throw std::runtime_error("B949 prior case incomplete");
        expected_pairs_=expected_pairs; completed_pairs_=0; case_event_calls_=0; callback_fault_=false;
    }
    template<class Memory> void enter_model(Memory& m) {
        const auto p=m.r32(0x8172c4u);
        if(p!=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&cs_))) throw std::runtime_error("B949 model lock slot drift");
        EnterCriticalSection(&cs_); record(true);
    }
    template<class Memory> void leave_model(Memory& m) {
        const auto p=m.r32(0x8172c4u);
        if(p!=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&cs_))) throw std::runtime_error("B949 model lock slot drift");
        LeaveCriticalSection(&cs_); record(false);
    }
    void verify_model_side() const { if (completed_pairs_ != 1u || case_event_calls_ != 2u || expected_pairs_ != 2u) throw std::runtime_error("B949 model-side event count mismatch"); verify_unowned(); }
    void finish_model_only() const { if (completed_pairs_ != 1u || case_event_calls_ != 2u || expected_pairs_ != 1u) throw std::runtime_error("B949 assurance event count mismatch"); verify_unowned(); verify_balanced(); }
    void finish_case() const { if (completed_pairs_ != 2u || case_event_calls_ != 4u || expected_pairs_ != 2u) throw std::runtime_error("B949 original-side event count mismatch"); verify_unowned(); verify_balanced(); }
    std::uint32_t total_pairs() const { return total_pairs_; }
    std::uint32_t total_event_calls() const { return total_event_calls_; }
    std::uint32_t ownership_checks() const { return ownership_checks_; }
};
} // namespace locks_b949
