#pragma once
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::audio376 {
// Real platform boundary. A host must supply an actual DirectSound device,
// critical section and WinMM timer. The recovery layer supplies no API results.
struct Boundary {
    virtual ~Boundary()=default;
    virtual void current_thread_id()=0;
    virtual void initialize_cs(std::uint32_t)=0;
    virtual std::uint32_t get_caps_flags(std::uint32_t device)=0;
    virtual std::uint32_t begin_period16()=0;
    virtual std::uint32_t set_timer(std::uint32_t guest_callback,std::uint32_t receiver)=0;
    virtual std::uint32_t increment(std::uint32_t)=0;
    virtual void decrement(std::uint32_t)=0;
    virtual void enter(std::uint32_t)=0;
    virtual void leave(std::uint32_t)=0;
};
inline Boundary* active=nullptr;
inline Boundary& host(){if(!active)throw std::logic_error("audio376 real platform boundary missing");return *active;}
}
