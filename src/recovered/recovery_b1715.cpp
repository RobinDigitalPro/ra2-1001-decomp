#include "recovered/recovery_b1715.hpp"
#include "recovered/recovery_b1085.hpp"
#include "recovered/recovery_b1176.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_0072a500(Memory&,const Inputs&);}
namespace ra2::recovered::b1715 {
namespace {
constexpr std::uint32_t owner=0xa5a860u;      // optional owned object, deleted first
constexpr std::uint32_t online=0xb10128u;     // byte: subsystem initialized by 0x736950
constexpr std::uint32_t module=0xb0e7e8u;     // module torn down by 0x751EA0
constexpr std::uint32_t events=0xb0df70u,events_end=0xb0dfb8u; // 18 event handles
constexpr std::uint32_t providers[3]{0xa5a874u,0xa5a878u,0xa5a87cu}; // COM providers
[[noreturn]] void excluded(const char*what){throw std::domain_error(what);}
}
unsigned run(Memory&m,const Inputs&,Heap&heap,State&fp,Close close,Destroy destroy){
 if(!close||!destroy)excluded("1715 actual CloseHandle/DeleteCriticalSection providers required");
 // 736645..736661: a nonnull [A5A860] is torn down by 0x615020(this), deleted by
 // 0x76D67B and cleared. Excluded from the accepted domain.
 if(m.r32(owner)!=0u)excluded("1715 excluded route: nonnull [A5A860] owner (615020 + delete)");
 // 736667..73667E: lookup of registry id 0x11E through accepted 0x72A500; a hit
 // would call 0x72A3A0(hit, EDX=0). Excluded from the accepted domain.
 Inputs query{};query.cx=0x11eu;const std::uint32_t hit=global_b26::fun_0072a500(m,query);
 if(hit!=0u)excluded("1715 excluded route: registry entry 0x11E present (72A3A0)");
 // 73667E/736684: uninitialized subsystem returns with EAX from the lookup.
 if(m.r8(online)==0u)return hit;
 // 73668A: accepted 0x5C27C0 frees the six owned buffers and empties A27DA8.
 // ECX still holds 0x11E from the lookup; 0x5C27C0 does not read it.
 Inputs cleanup{};cleanup.cx=0x11eu;b1085::run(m,cleanup,heap,fp,0x1c27c0u);
 // 73668F..7367E8: each nonnull provider runs QueryInterface(0x79AB38) ->
 // FindConnectionPoint -> Unadvise(cookie B10108/B1010C/B10110) -> Release x3.
 // Every dispatch is skipped when all three providers are null (accepted domain).
 for(std::uint32_t p:providers)if(m.r32(p)!=0u)excluded("1715 excluded route: nonnull COM provider at A5A874/78/7C");
 // 7367F2..7367FE: clear the three provider pointers.
 for(std::uint32_t p:providers)m.w32(p,0u);
 // 736804..736817: CloseHandle on B0DF70..B0DFB4 in address order. The slots
 // keep their (now stale) handle values; the root does not clear them.
 for(std::uint32_t a=events;a<events_end;a+=4u)close(reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(a))));
 // 736819..73681E: accepted 0x751EA0(B0E7E8) deletes the module critical sections.
 Inputs teardown{};teardown.arg[0]=module;const unsigned eax=b1176::run(m,teardown,fp,destroy);
 // 736823: subsystem marked uninitialized; EAX is the 0x751EA0 result.
 m.w8(online,0u);
 return eax;
}
}
