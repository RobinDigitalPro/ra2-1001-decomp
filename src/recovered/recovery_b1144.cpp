#include "recovered/recovery_b1144.hpp"
#include "platform/stream1144_provider.hpp"
#include <array>
namespace ra2::recovered::b1144 {
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){
 if(root!=0x309650u)throw std::domain_error("1144 reviewed root only");
 constexpr unsigned head=0xab8250u;unsigned count=0;
 for(auto p=m.r32(head);p!=head;p=m.r32(p)){if(++count>6u)throw std::domain_error("1144 finite positive circular list");}
 if(count<2u)throw std::domain_error("1144 populated list required");
 // Direct real IStream call, exact stdcall Write slot+10 ABI. This ordinary
 // numeric model never invokes original GAME code or replaces provider results.
 auto*stream=reinterpret_cast<IStream*>(std::uintptr_t(i.cx));
 unsigned result=unsigned(stream->Write(&count,4u,nullptr));
 if(std::int32_t(result)<0)return result;
 auto node=m.r32(head);if(node!=0u&&node==m.r32(node+8u))node=0u;
 while(node){if(m.r32(node+0x14u)!=0u)throw std::domain_error("1144 original null embedded target route");std::array<unsigned,4>record{0xffffffffu,m.r32(node+0x20u),m.r32(node+0x24u),m.r32(node+0x28u)};result=unsigned(stream->Write(record.data(),16u,nullptr));if(std::int32_t(result)<0)return result;node=m.r32(node);if(node!=0u&&node==m.r32(node+8u))node=0u;}
 return result;
}
}
