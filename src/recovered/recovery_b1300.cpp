#include "recovery_b1300.hpp"
#include "numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1300 {
std::uint32_t fun_006df4a0(Memory&m,const Inputs&i){
 auto need=[](bool q,const char*s){if(!q)throw std::domain_error(s);};const auto queue=m.r32(i.cx+0x110u);
 need(queue&&m.r32(queue)==1u&&floating_b61::read64(m,i.cx+0xb0u)==0x3ff0000000000000ull,"1300 nonempty singleton queue,scale1");
 i.fp.load64(floating_b61::read64(m,i.cx+0xb0u));i.fp.compare_pop64(floating_b61::read64(m,0x787520u));need(!(i.fp.status()&0x4100u),"1300 real positive scale");
 i.fp.load_integer32(1u);i.fp.multiply64(floating_b61::read64(m,i.cx+0xb0u));need(numeric_b88::detail::integer(m,i.fp)==1u,"1300 original count scaling");
 const auto rng=m.r32(0xa255c0u)+0x218u,a=m.r32(rng+4u),b=m.r32(rng+8u);
 need(m.r8(rng)==0u&&a<250u&&b<250u&&a!=b,"1300 actual mutable XOR generator");
 const auto result=m.r32(rng+12u+4u*a)^m.r32(rng+12u+4u*b);m.w32(rng+12u+4u*a,result);m.w32(rng+4u,(a+1u)%250u);m.w32(rng+8u,(b+1u)%250u);
 need(std::int32_t(result)>=0&&result%5u==0u,"1300 bounded one-pop random budget");
 const auto capacity=(m.r32(0x81a914u)+4u)*m.r32(0x81a910u)*2u;need(capacity>=3u,"1300 real capacity skips compaction");
 const auto slots=m.r32(queue+8u),node=m.r32(slots+4u);need(node!=0u,"1300 real nonnull stale entry");
 //Actual pop copies last entry over first (same slot), clears it, decrements count.
 m.w32(slots+4u,0u);m.w32(queue,0u); //58BE90 then has no children and preserves numeric state.
 const int x=std::int16_t(m.r16(node)),y=std::int16_t(m.r16(node+2u)),index=x+512*y;
 need(index>=0&&index<0x40000,"1300 valid original cell index");const auto cell=m.r32(m.r32(0x81a958u)+4u*unsigned(index));
 need(cell&&m.r32(cell+0x44u)==0xffffffffu&&m.r32(i.cx+0x98u)!=0xffffffffu,"1300 actual category mismatch");
 return 1u; //Original loop counter after one discarded entry; RET.
}
}
