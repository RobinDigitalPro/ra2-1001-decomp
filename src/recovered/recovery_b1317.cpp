#include "recovery_b1317.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&,const Inputs&);
}
namespace ra2::recovered::b1317 {
namespace {
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&heap){
 need(root==0x14fa00u||root==0x152ef0u,"1317 exact early-search roots");
 const unsigned input_pointer=i.arg[0];
 need(m.r32(input_pointer)==0x00030003u,"1317 original arena input3,3");
 // Original X-outer/Y-inner search starts at(-2,-2). This finite scope
 // covers a real first match: the existing populated B1315 center(1,1).
 const auto x=std::uint16_t(m.r16(input_pointer)-2u);
 const auto y=std::uint16_t(m.r16(input_pointer+2u)-2u);
 const unsigned matched=unsigned(x)|(unsigned(y)<<16u);
 need(matched==0x00010001u,"1317 first original search coordinate");
 i.arg[0]=matched;
 // FA00 stable SP=S-60, slot+64=S+4; 2EF0 SP=S-58, slot+5C=S+4.
 // Both pass a pointer to that caller word. It is represented explicitly
 // in a private span distinct from B1296's own geometry scratch.
 std::array<std::uint8_t,4> bytes{};constexpr unsigned p=0x7a100000u;
 leaf::Memory caller_word(bytes.data(),p,unsigned(bytes.size()));
 Memory view=m;view.add(caller_word);caller_word.w32(p,matched);
 global_b26::Inputs q{};q.cx=0x81a820u;q.arg[0]=p;
 const unsigned cell=global_b26::fun_00545500(view,q);
 need(cell!=0xa57610u,"1317 populated positive first match");
 const auto category=std::int32_t(m.r32(cell+0x44u));
 const int lower=root==0x14fa00u?0x4a:0xcd,upper=root==0x14fa00u?0x65:0xe8;
 need(category>=lower&&category<=upper,"1317 original signed family membership");
 const unsigned child=root==0x14fa00u?0x15def0u:0x15e130u;
 Inputs nested=i;nested.arg[0]=p;
 const auto eax=b1315::run(child,view,nested,heap);
 i.fp=nested.fp;
 // B1315 overwrites its own argument slot, not the pointed-to caller
 // word. Outer arg0 remains packed1,1 and arena input remains packed3,3.
 need(caller_word.r32(p)==matched,"1317 original pointed-to caller word preserved");
 return eax; // Actual final HeapFree BOOL1; POP/ADD/RET4 preserve EAX.
}
}
