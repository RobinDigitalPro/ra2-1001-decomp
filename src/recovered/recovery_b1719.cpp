#include "recovered/recovery_b1719.hpp"
#include <stdexcept>
namespace ra2::recovered::b1719 {
namespace {
constexpr std::uint32_t patched=0x4ba0f0u;   // first dword of the code at 0x4BA0F0
[[noreturn]] void excluded(const char*what){throw std::domain_error(what);}
}
unsigned run(Memory&m,const Inputs&,State&,const Api&api){
 if(!api.query||!api.protect||!api.last_error||!api.process||!api.flush)excluded("1719 actual Kernel32 providers required");
 // 4BA903..4BA92D: zeroed 28-byte MEMORY_BASIC_INFORMATION, VirtualQuery(0x4BA0F0).
 MEMORY_BASIC_INFORMATION info{};
 const SIZE_T queried=api.query(reinterpret_cast<LPCVOID>(std::uintptr_t(patched)),&info,0x1cu);
 // 4BA92D: a failed query returns with EAX = 0 and no other effect.
 if(queried==0u)return 0u;
 // 4BA933..4BA95A: VirtualProtect(region base, region size, PAGE_WRITECOPY, &old).
 DWORD old=0;
 if(api.protect(info.BaseAddress,info.RegionSize,PAGE_WRITECOPY,&old)==FALSE)
  excluded("1719 excluded route: first VirtualProtect failed (GetLastError + 0x4068F0 report)");
 // 4BA97D: clear the dword.
 m.w32(patched,0u);
 // 4BA984..4BA98D: VirtualProtect(same region, PAGE_EXECUTE, &old).
 if(api.protect(info.BaseAddress,info.RegionSize,PAGE_EXECUTE,&old)==FALSE)
  excluded("1719 excluded route: second VirtualProtect failed (GetLastError + 0x4068F0 report)");
 // 4BA9A4..4BA9AF: FlushInstructionCache(GetCurrentProcess(), NULL, 0); EAX is its result.
 return unsigned(api.flush(api.process(),nullptr,0u));
}
}
