#include "recovery_b475.hpp"
#include "platform/observed_winsock475.hpp"
namespace ra2::recovered::recovery_b475 {
std::uint32_t fun_007579c0(Memory&m,const Inputs&i){
 const auto socket=i.arg[0]==0xffffffff?m.r32(i.cx+0x4386c):i.arg[0];
 const int first=platform::winsock475::Socket::configure(socket,SO_RCVBUF,int(m.r32(0x7e906c)));
 const int last=platform::winsock475::Socket::configure(socket,SO_SNDBUF,int(m.r32(0x7e9068)));
 if(first!=0||last!=0)throw std::domain_error("475 only successful owned-socket configuration");
 // Actual diagnostic 4068F0 is a one-byte RET. Final MOV AL,1 preserves
 // the zero high bytes returned by the successful second setsockopt.
 return 1;
}
}
