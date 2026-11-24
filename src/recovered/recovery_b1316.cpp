#include "recovery_b1316.hpp"
#include "recovered/recovery_b1314.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&,const Inputs&);
}
namespace ra2::recovered::b1316 {
namespace {
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
unsigned run(unsigned root,Memory&m,const Inputs&i){
 const unsigned pointer=i.arg[0];
 need(m.r32(pointer)==0x00050005u,"1316 original center coordinate 5,5");
 const unsigned old=root==0x15aa90u?0x5cu:0xdfu;
 const unsigned lower=root==0x15aa90u?0x4au:0xcdu;
 const unsigned upper=root==0x15aa90u?0x65u:0xe8u;
 // Original inline lookup uses 81A958; the genuine neighbor helper uses
 // global receiver+138, which is the same address. All three cells exist.
 const unsigned grid=m.r32(0x81a958u);
 const unsigned center=m.r32(grid+4u*(512u*5u+5u));
 need(center&&m.r32(center+0x44u)==old,"1316 positive category arm");
 std::array<std::uint8_t,4> bytes{};constexpr unsigned p=0x7a000000u;
 leaf::Memory scratch(bytes.data(),p,unsigned(bytes.size()));Memory view=m;view.add(scratch);
 global_b26::Inputs q{};q.cx=0x81a820u;q.arg[0]=p;
 // Entry S: SUB8 and two saved registers leave S-10. The original
 // [ESP+14]/[ESP+16] WORD stores overwrite caller arg0 at S+4.
 i.arg[0]=0x00040005u;scratch.w32(p,i.arg[0]);
 const auto first=global_b26::fun_00545500(view,q);
 const auto first_category=std::int32_t(m.r32(first+0x44u));
 need(first!=0xa57610u&&first_category>=int(lower)&&first_category<=int(upper),
      "1316 populated first neighbor in family");
 i.arg[0]=0x00030005u;scratch.w32(p,i.arg[0]);
 const auto second=global_b26::fun_00545500(view,q);
 need(second!=0xa57610u&&m.r32(second+0x44u)==0u,"1316 populated second neighbor outside family");
 // ESI retained the original arena pointer. The nested argument slot is
 // private; it must not replace the outer caller's final packed probe.
 Inputs nested=i;nested.arg[0]=pointer;
 const auto eax=root==0x15aa90u?b1314::fun_0055ace0(m,nested):b1314::fun_0055be10(m,nested);
 i.fp=nested.fp;
 return eax; // Original POP/ADD/RET4 preserve the child's full EAX0.
}
}
std::uint32_t fun_0055aa90(Memory&m,const Inputs&i){return run(0x15aa90u,m,i);}
std::uint32_t fun_0055bba0(Memory&m,const Inputs&i){return run(0x15bba0u,m,i);}
}
