#include "recovery_b949.hpp"
#include "platform/observed_locks949.hpp"
#include <stdexcept>

namespace b949_model {
std::uint32_t fun_007716d4(Memory& m,const Inputs& i) {
    const auto category=i.arg[0];
    // This private contract covers only categories 1..5 and locale argument NULL.
    if(category<1u||category>5u||i.arg[1]!=0u) throw std::domain_error("outside B949 query contract");
    auto& lock=locks_b949::ActualLock::current();
    lock.enter_model(m);                 // genuine OS EnterCriticalSection through adapter
    m.w32(kCounter,m.r32(kCounter)+1u);   // original INC [B10E20]
    // The valid fixture requires zero here; the original otherwise enters its Sleep retry loop.
    if(m.r32(kBackground)!=0u) {
        lock.leave_model(m);
        m.w32(kCounter,m.r32(kCounter)-1u);
        throw std::domain_error("B949 background busy state excluded");
    }
    const auto result=m.r32(kTable+12u*category); // original indexed pointer load
    lock.leave_model(m);                 // genuine OS LeaveCriticalSection through adapter
    m.w32(kCounter,m.r32(kCounter)-1u);   // original DEC [B10E20]
    return result;                        // full EAX pointer, no setter path
}
} // namespace b949_model
