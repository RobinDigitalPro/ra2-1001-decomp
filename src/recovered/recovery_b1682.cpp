#include "recovered/recovery_b1682.hpp"
#include <stdexcept>
namespace ra2::recovered::b1682 { namespace {
void need(bool b){if(!b)throw std::domain_error("268410 bounded positive progress composition");}
std::uint64_t q(const Memory&m,unsigned p){return m.r32(p)|(std::uint64_t(m.r32(p+4u))<<32u);}
}
unsigned run(Memory&m,const Inputs&i,State&f,Observation&o){
 // Authentic caller receiver A255C8; +27F0 is the public peer count A27DB8.
 need(i.cx==0xa255c8u&&m.r8(0xa28953u)==0u&&m.r32(i.cx+0x27f0u)==1u);
 const auto context=m.r32(0xa255c0u);need(context&&m.r8(context+0x223bu)==0u);
 const auto count=m.r8(0xa5e5a1u);need(count==1u||count==2u);
 need(i.arg[0]>=50u&&i.arg[0]<=100u);
 need(m.r32(0xa5e540u)==0x7933fcu&&m.r32(0xa5e544u)==0u&&m.r8(0xa5e5a0u)==0u&&m.r32(0xa5e5a4u)==0u);
 need(q(m,0xa5e548u)==0x4034000000000000ull&&q(m,0xa5e588u)==0x4059000000000000ull);
 if(count==2u)need(q(m,0xa5e550u)==0x4044000000000000ull);
 need(q(m,0x786610u)==0u&&q(m,0x7867f0u)==0x4059000000000000ull&&q(m,0x787518u)==0x3f847ae147ae147bull&&m.r32(0x7c3a04u)==0x0e7fu);
 const auto cw=f.image.word(0);need(cw==0x037fu||cw==0x077fu||cw==0x0b7fu||cw==0x0f7fu);f.require_masked();
 // Exact Root preface: FILD32; FSTP64; FLD64/FDIV64/FMUL64/FCOMP64.
 // Real State operations preserve all raw registers/status, with no normalization.
 f.load_integer32(i.arg[0]);o.percentage=f.pop64();
 f.load64(q(m,0xa5e548u));f.divide64(q(m,0xa5e588u));f.multiply64(q(m,0x7867f0u));f.compare_pop64(o.percentage);
 o.prefix_status=f.status();need((o.prefix_status&0x100u)!=0u);
 Inputs child{};child.cx=0xa5e540u;child.ax=unsigned(o.percentage);child.dx=unsigned(o.percentage>>32u);
 child.arg[0]=0;child.arg[1]=unsigned(o.percentage);child.arg[2]=unsigned(o.percentage>>32u);child.arg[3]=0xffffffffu;child.arg[4]=0xffffffffu;
 // Only five actual produced child arguments are modeled/read. Remaining child
 // Inputs cells are unused adapters, not a claim about private physical words.
 o.helper_result=b1264::run(0x217d70u,m,child,f);
 // CMP receiver+27F0,1; taken early return does not overwrite helper fullEAX.
 return o.helper_result;
}
unsigned run(Memory&m,const Inputs&i,State&f){Observation o{};return run(m,i,f,o);}

}
