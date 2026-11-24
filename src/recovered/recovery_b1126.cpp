#include "recovery_b1126.hpp"
#include <stdexcept>
namespace ra2::recovered::b1126 {
static void need(bool v){if(!v)throw std::domain_error("1126 positive original video member-file read");}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,Api&api){
 need((root==0x311f00u||root==0x312070u)&&i.arg[0]==5u&&i.arg[2]>=32u&&i.arg[2]<=240u);
 const unsigned file=i.cx+4u,name=m.r32(file+0x14u),requested=i.arg[2];
 need(m.r32(file)==0x7856a0u&&m.r32(file+4u)==1u&&m.r32(file+8u)==0u&&m.r32(file+0xcu)==0xffffffffu&&m.r32(file+0x10u)==0xffffffffu&&name&&m.r8(file+0x1cu)==1u&&m.r32(file+0x54u)==0u&&m.r32(file+0x60u)==0u&&m.r8(i.cx+0x68u)==0u);
 for(unsigned p:{0x20u,0x21u,0x22u,0x23u,0x24u,0x25u,0x50u})need(m.r8(file+p)==0u);
 constexpr char text[]="whole.bin";for(unsigned k=0;k<10u;++k)need(h.r8(name+k)==unsigned(text[k])&&m.r8(i.cx+0x69u+k)==unsigned(text[k]));
 // Both original tables index(action-1); index4 is the complete read arm.
 // The member is in the authentic closed-after-action4 state, retaining its
 // genuinely owned filename created through action3/401980/46FD50/630110.
 const auto path=reinterpret_cast<const char*>(std::uintptr_t(name));
 HANDLE probe=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(probe!=INVALID_HANDLE_VALUE);m.w32(file+0x10u,unsigned(reinterpret_cast<std::uintptr_t>(probe)));need(api.close_handle(probe)!=FALSE);m.w32(file+0x10u,0xffffffffu);
 HANDLE active=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(active!=INVALID_HANDLE_VALUE);m.w32(file+0x10u,unsigned(reinterpret_cast<std::uintptr_t>(active)));m.w32(file+4u,1u);
 DWORD read=0u;need(api.read_file(active,reinterpret_cast<void*>(std::uintptr_t(i.arg[1])),requested,&read,nullptr)!=FALSE&&read==requested);m.w8(0xa9e184u,0u);need(api.close_handle(active)!=FALSE);m.w32(file+0x10u,0xffffffffu);
 // 68C80 returns requested; the complete wrapper compares that count and
 // clears fullEAX via ECX, returning0. No callerword is modified; RET12.
 return 0u;
}
unsigned cleanup(Memory&m,unsigned file,Heap&h){
 need(m.r32(file)==0x7856a0u&&m.r32(file+0x10u)==0xffffffffu&&m.r32(file+0x54u)==0u&&m.r8(file+0x5cu)==0u);
 m.w32(file,0x7856a0u);m.w32(file+0x60u,0u);m.w32(file+0x54u,0u);m.w32(file+0x58u,0u);m.w8(file+0x5cu,0u);
 m.w32(file,0x785658u);m.w32(file,0x78773cu);m.w32(file+0x2cu,0u);m.w32(file+0x30u,0u);for(unsigned k:{0x21u,0x23u,0x24u,0x25u})m.w8(file+k,0u);
 m.w32(file,0x793c84u);need(m.r8(file+0x1cu)==1u&&m.r32(file+0x14u));need(h.release(m.r32(file+0x14u))!=0u);m.w32(file+0x14u,0u);m.w8(file+0x1cu,0u);m.w32(file,0x793c3cu);return file;
}
}
