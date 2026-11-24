#include "recovery_b1692.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b1692 {
namespace {
void need(bool v){if(!v)throw std::domain_error("125CE0 supplied placed one-cell removal");}
U rounded(U v){return global_b26::sar(v+((v>>31u)?0xffu:0u),8u)&0xffffu;}
U coordinate(Memory&m,U self){return rounded(m.r32(self+0x88u))|(rounded(m.r32(self+0x8cu))<<16u);}
struct Range{U base,size;};
void disjoint(Range a,Range b){
 need(a.base&&b.base&&std::uint64_t(a.base)+a.size<=0x100000000ull&&std::uint64_t(b.base)+b.size<=0x100000000ull);
 need(std::uint64_t(a.base)+a.size<=b.base||std::uint64_t(b.base)+b.size<=a.base);
}
U blob_byte(U off){
 if(off<16u)return off==0u||off==4u?1u:0u;
 const U k=off-20u;
 return k>=0x2bu&&k<0x31u?((k-0x2bu)*47u)&255u:(k*37u)&255u;
}
// 526450 MOV EAX,11h; RET0. The exact table binding is checked, not replaced.
U kind17(){return 17u;}
// Actual40DC20: kind17 decrements to16, unsigned16>14, XOR EAX,EAX/RET0.
U kind_filter(){const U k=kind17()-1u;need(k>14u);return 0u;}
U deactivate(Memory&m,U self){
 need(m.r32(self)==0x78f7b0u&&m.r32(0x78f7dcu)==0x526450u);
 need(m.r8(self+0x76u)==0u);
 const U kind=kind17();need(kind!=6u); //5CC838 bypasses+418/BF0.
 const U filtered=kind_filter();need(filtered==0u); //No owner callbacks/output.
 const U active=m.r8(self+0x74u);need(active!=0u);
 m.w8(self+0x74u,0u); //5CC8AD BL=operation0; fullEAX afterNULL/MOVAL1 is1.
 return 1u;
}
bool root_membership(Memory&m,U packed){
 const U x=global_b26::sx16(packed),y=global_b26::sx16(packed>>16u);
 const U w=m.r32(0x81a910u),h=m.r32(0x81a914u);
 return global_b26::s32(x+y)>global_b26::s32(w)&&global_b26::s32(x-y)<global_b26::s32(w)&&
        global_b26::s32(y-x)<global_b26::s32(w)&&global_b26::s32(x+y)<=global_b26::s32(w+2u*h);
}
void fp_domain(const ra2::platform::x87::Image&e){
 const U cw=e.word(0),sw=e.word(4),tags=e.word(8),top=(sw>>11u)&7u;
 need(cw==0x037fu||cw==0x027fu||cw==0x077fu||cw==0x0e7fu);
 need(sw==((top<<11u)|0x20u));
 U depth=0;while(depth<8u&&((tags>>(2u*((top+depth)&7u)))&3u)==0u)++depth;
 need(depth<8u); //One genuine FLD scratch slot; no depth8 extension.
 for(U k=depth;k<8u;++k)need(((tags>>(2u*((top+k)&7u)))&3u)==3u);
}
}

Projection preflight(U root,Memory&m,const Inputs&i,Heap&h,const ra2::platform::x87::Image&entry){
 need(root==0x125ce0u&&i.arg[0]==0u&&i.cx);fp_domain(entry);
 Projection p{};p.receiver=i.cx;
 need(m.r32(p.receiver)==0x78f7b0u&&m.r8(p.receiver+0x74u)==1u&&m.r8(p.receiver+0x76u)==0u);
 need(m.r32(0x78f7dcu)==0x526450u&&m.r32(0x78f818u)==0x5cae40u&&m.r32(0x78f834u)==0x5264a0u&&m.r32(0x78f950u)==0x41b320u);
 p.type=m.r32(p.receiver+0x98u);p.types=m.r32(0xa28914u);
 need(p.type&&p.types&&m.r32(p.types+4u)==p.type&&m.r32(p.type)==0x790188u);
 need(m.r32(0x790224u)==0x527630u&&m.r32(p.type+0x264u)==1u);
 need(m.r32(p.type+0x2b4u)==1u&&m.r32(p.type+0x2b8u)==1u&&m.r8(p.type+0xa8u)==1u);
 p.blob=m.r32(p.type+0xa4u);need(p.blob&&std::uint64_t(p.blob)+80u<=0x100000000ull);
 for(U k=0;k<80u;++k)(void)h.r8(p.blob+k); //Addressability; not ownership provenance.
 need(h.r32(p.blob+0x10u)==p.blob+20u);
 for(U k=0;k<72u;++k)if(k<16u||k>=20u)need(h.r8(p.blob+k)==blob_byte(k));
 need(h.r8(p.blob+20u+0x28u)==0xc8u);
 need(m.r32(p.receiver+0x88u)==0x180u&&m.r32(p.receiver+0x8cu)==0x1480u);
 need(coordinate(m,p.receiver)==0x00140001u);
 need(m.r32(0x81a910u)==20u&&m.r32(0x81a914u)==20u&&m.r32(0x81a918u)==0u&&m.r32(0x81a91cu)==0u&&m.r32(0x81a920u)==20u&&m.r32(0x81a924u)==20u);
 p.table=m.r32(0x81a958u);need(p.table);p.cell=m.r32(p.table+4u*10241u);need(p.cell&&p.cell!=0xa57610u);
 need(m.r32(p.cell)==0x788b04u&&m.r32(p.cell+0x24u)==0x00140001u);
 need(m.r32(p.cell+0x38u)==1u&&m.r8(p.cell+0x11au)==0u&&m.r8(p.cell+0x11bu)==0xc8u);
 need(m.r32(p.cell+0x44u)==0xffffffffu&&m.r32(p.cell+0xe4u)==0u);
 p.rules=m.r32(0x821b88u);need(p.rules&&m.r8(p.rules+0x584u)==0u);
 need(m.r32(0x8391d8u)==0x3f800000u&&m.r32(0x787518u)==0x47ae147bu&&m.r32(0x78751cu)==0x3f847ae1u);
 p.cache4=m.r32(0x81a884u);p.cache10=m.r32(0x81a88cu);need(m.r32(0x81a888u)==1681u);
 const std::array<Range,9> ranges{{{p.receiver,0x9cu},{p.type,0x2dcu},{p.blob,80u},{p.cell,0x11du},{p.table,40968u},{p.types,8u},{p.rules,0x585u},{p.cache4,6736u},{p.cache10,16816u}}};
 for(U a=0;a<ranges.size();++a)for(U b=a+1u;b<ranges.size();++b)disjoint(ranges[a],ranges[b]);
 const std::array<U,7> pages{{0x78f000u,0x790000u,0x81a000u,0x821000u,0x839000u,0x787000u,0xa28000u}};
 for(const auto&r:ranges)for(U page:pages)disjoint(r,{page,4096u});
 for(U k=0;k<6736u;++k)(void)h.r8(p.cache4+k);
 for(U k=0;k<1681u;++k)need(h.r8(p.cache4+4u*k)==7u&&h.r8(p.cache4+4u*k+1u)==0u);
 for(U k=0;k<16816u;++k)(void)h.r8(p.cache10+k); //Fresh bytes/padding unrestricted.
 need(root_membership(m,coordinate(m,p.receiver)));
 return p;
}

U run(U root,Memory&m,const Inputs&i,Heap&h,const Projection&p){
 need(root==0x125ce0u&&i.arg[0]==0u&&i.cx==p.receiver);
 // Actual5CAE40 ->5264A0:[Root+98] ->Type primary+9C warm527630.
 const U type_from_getter=m.r32(p.receiver+0x98u);need(type_from_getter==p.type);
 const U cached=m.r32(type_from_getter+0xa4u);need(cached==p.blob&&cached);
 need(deactivate(m,p.receiver)==1u);
 // Exact row0/column0 iteration. These are private produced values, not writes
 // through outer Inputs.arg or an invented guest output address.
 const U packed=coordinate(m,p.receiver);need(root_membership(m,packed));
 const U index=U(std::int16_t(packed))+512u*U(std::int16_t(packed>>16u));need(index<0x40000u);
 const U cell=m.r32(m.r32(0x81a958u)+4u*index);need(cell==p.cell);
 const U descriptor=m.r32(p.receiver+0x98u),linear=0u;
 const U entry=h.r32(cached+0x10u+4u*linear);need(entry==p.blob+20u&&entry);
 need(m.r32(cell+0x38u)==m.r32(descriptor+0x264u)&&m.r8(cell+0x11au)==linear);
 m.w32(cell+0x38u,0xffffu); //525DEA
 m.w8(cell+0x11au,0u);     //525DF1
 m.w8(cell+0x11bu,(m.r8(cell+0x11bu)-h.r8(entry+0x28u))&255u); //525DF8..E07
 Inputs child{};child.cx=cell;child.arg[0]=0xffffffffu;
 // Unchanged physical x87 implementation: real FLD1/FCOMP .01. No FP image
 // assignment, normalization, callback, allocation or free in this model.
 (void)b1211::run(0x72140u,m,child,h);
 //526091/5260A8 reload descriptor. Mode0 skips final virtual+20 entirely.
 return (m.r32(p.receiver+0x98u)&0xffffff00u)|1u; //5260E7 MOV AL,1 / RET4
}
}
