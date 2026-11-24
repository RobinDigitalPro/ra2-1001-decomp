#include "recovered/recovery_b1471.hpp"
#include "recovered/text_b76.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/leaf_b16_a.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
#include <vector>
namespace ra2::recovered::b1471 {
namespace {
using U=std::uint32_t;
void need(bool value,const char* message){if(!value)throw std::domain_error(message);}
U wide_length(Memory&m,U address){
 std::vector<std::uint16_t> text;
 for(U k=0;k<163u;++k){const auto ch=std::uint16_t(m.r16(address+2u*k));text.push_back(ch);if(!ch)return ra2::recovered::fun_0076ef45(text.data());}
 throw std::domain_error("B1471 bounded UTF16 terminator");
}
// The unchanged leaf helper takes one contiguous span. Adapt both real input
// strings to that API, then publish only its appended words (including NUL).
// This local host storage is not a GAME heap allocation or provider callback.
void wide_append(Memory&m,U destination,U source){
 const U old=wide_length(m,destination),count=wide_length(m,source);
 need(old+count<162u,"B1471 wide-append capacity");
 std::array<std::uint8_t,1024> bytes{};
 leaf::Memory local(bytes.data(),0x1000u,std::uint32_t(bytes.size()));
 constexpr U dst=0x1000u,src=0x1200u;
 for(U k=0;k<=old;++k)local.w16(dst+2u*k,m.r16(destination+2u*k));
 for(U k=0;k<=count;++k)local.w16(src+2u*k,m.r16(source+2u*k));
 leaf::Inputs child{};child.arg[0]=dst;child.arg[1]=src;
 need(leaf::fun_0076ef9f(local,child)==dst,"B1471 unchanged wcscat result");
 for(U k=0;k<=count;++k)m.w16(destination+2u*(old+k),local.r16(dst+2u*(old+k)));
}
}
U fun_005b1d50(Memory&m,const Inputs&i){
 const U manager=i.cx,prefix=i.arg[0],append=i.arg[2];
 need(manager==0xa25fa0u&&prefix&&append&&m.r8(manager+0x18u)==1u,"B1471 genuine enabled manager");
 const U node=m.r32(manager);
 need(node&&m.r32(node)==0x798b74u&&m.r32(node+0x28u)==i.arg[1],"B1471 first matching produced node");
 const U prefix_length=wide_length(m,prefix),buffer=m.r32(node+0x30u);
 need(prefix_length==5u&&buffer==manager+0x2c8u,"B1471 declared prefix and slot0");
 for(U k=0;k<2u*prefix_length;++k)need(m.r8(prefix+k)==m.r8(buffer+k),"B1471 original prefix byte comparison");
 const U content=buffer+2u*prefix_length+2u,limit=m.r32(manager+0x10u);
 // At original5B1DD2 two retained cdecl pushes move [ESP+20h] to entryS+4.
 i.arg[0]=limit;
 const U length=wide_length(m,content),extra=wide_length(m,append);
 need(limit==98u&&length==97u&&extra==5u&&length+extra>=limit,"B1471 positive bounded length-overflow branch");
 const U lower=length-limit+extra,maximum=std::max(length,lower);
 global_b26::Inputs trim{};trim.cx=manager;trim.arg={0u,content,lower,maximum,0u};
 (void)text_b76::fun_005b27c0(m,trim);
 wide_append(m,content,append);
 need(i.arg[3]==0xffffffffu,"B1471 explicit indefinite lifetime");
 m.w32(node+0x24u,0u);
 return 1u;
}
}
