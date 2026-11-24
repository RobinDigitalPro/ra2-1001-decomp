#include "recovered/recovery_b175.hpp"
#include "recovered/floating_b39_memory.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b175 {
namespace {
void require(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
std::uint64_t original_table_length(Memory&m,std::uint32_t sum,platform::x87::State&fp){
 // Root's FILD/FSTP argument conversion precedes the existing recovered
 // call-free approximation helper. Its writable argument is local scratch.
 fp.load_integer32(sum);const auto operand=fp.pop64();
 Memory local=m;std::array<unsigned char,256>bytes{};
 leaf::Memory stack(bytes.data(),0x7c000000,bytes.size());local.add(stack);
 constexpr unsigned entry=0x7c000040,continuation=0x62ceda;
 local.w32(entry,continuation);local.w32(entry+4,unsigned(operand));local.w32(entry+8,unsigned(operand>>32));
 floating_b39::State s{};s.fp=fp;
 floating_b39::Frame f{};f.entry_sp=f.sp=f.return_sp=entry;f.outer_return=continuation;
 const auto&functions=floating_b39::entries_a();
 const auto found=std::find_if(functions.begin(),functions.end(),[](const auto&e){return e.rva==0xba080;});
 require(found!=functions.end(),"175 existing approximate-length helper missing");
 found->function(local,s,f,{}); // Call-free implementation; no callback boundary.
 fp=s.fp;return fp.pop64(); // Root FSTP [receiver+58].
}
}
std::uint32_t fun_0062ce70(Memory&m,const Inputs&i){
 const auto p=i.cx;
 require(m.r8(p)==0&&m.r8(p+1)==0,"175 first initialization with rendering disabled");
 std::array<unsigned,3>d{};unsigned sum=0;
 for(unsigned k=0;k<3;++k){d[k]=m.r32(p+0x28+4*k)-m.r32(p+0x1c+4*k);const auto signed_delta=global_b26::s32(d[k]);require(signed_delta>=-32&&signed_delta<=32,"175 bounded coordinate delta");sum+=d[k]*d[k];}
 require(m.r32(0x785738)==0,"175 pinned comparison constant");
 m.w8(p,1);
 for(unsigned k=0;k<3;++k)m.w32(p+0x4c+4*k,d[k]);
 const auto length=original_table_length(m,sum,i.fp);
 m.w32(p+0x58,unsigned(length));m.w32(p+0x5c,unsigned(length>>32));
 const auto next=m.r32(p+0x6c)+1,limit=m.r32(p+0x34);
 m.w32(p+0x6c,next);
 const unsigned finished=global_b26::s32(next)>=global_b26::s32(limit);
 return (next&0xffffff00u)|finished;
}
}
