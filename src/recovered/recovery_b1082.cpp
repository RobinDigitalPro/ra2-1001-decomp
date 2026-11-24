#include "recovered/recovery_b1082.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/leaf_b57_b.hpp"
#include <array>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1082{
static void need(bool v){if(!v)throw std::domain_error("1082 cold onebyte software surface and palette plus2cacheassets");}
static unsigned cached(Memory&m,unsigned name){need(name&&m.r32(0xb10530u)==0u);std::vector<unsigned char>s;for(unsigned k=0;k<32u;++k){auto c=m.r8(name+k);if(!c)break;if(c>='a'&&c<='z'){c-=32u;m.w8(name+k,c);}s.push_back(static_cast<unsigned char>(c));}need(!s.empty()&&s.size()<32u);NameHashState hs{};const auto key=fun_00493da0(hs,s.data(),static_cast<int>(s.size()));auto owner=m.r32(0xa588e0u);for(unsigned chain=0;owner&&chain<2u;++chain){const auto next=m.r32(owner+4u);need(next&&m.r32(owner+8u));auto count=m.r32(owner+0x14u),table=m.r32(owner+0x20u);need(count==2u);while(count){const auto middle=count/2u,entry=table+middle*12u,hash=m.r32(entry);if(global_b26::s32(hash)>global_b26::s32(key))count=middle;else if(hash==key){need(m.r32(owner+0x24u));return m.r32(owner+0x24u)+m.r32(entry+4u);}else{table=entry+12u;count-=middle+1u;}}owner=next;}throw std::domain_error("1082 actual loaded asset required");}
static unsigned nearest(leaf::Memory&m,unsigned palette,unsigned target){unsigned best=~0u,index=0u;for(unsigned n=0;n<256u;++n){leaf::Inputs q{};q.cx=target;q.arg[0]=palette+3u*n;const auto d=leaf::fun_006343a0(m,q);if(n==0u||d<best){best=d;index=n;}}return index;}
static unsigned palette_context(Memory&m,Heap&h,unsigned surface){const auto palette=0x820150u; const auto object=h.allocate(392u);need(object);leaf::Memory object_span(reinterpret_cast<unsigned char*>(std::uintptr_t(object)),object,392u);auto v=m;v.add(object_span);need(h.r32(surface)==0x785ef8u&&m.r32(0x785f68u)==0x4113b0u&&h.r32(surface+16u)==1u);v.w32(object,0x788f70u);v.w32(object+4u,1u);for(unsigned off=8u;off<=0x17cu;off+=4u)v.w32(object+off,0u);v.w32(object+0x16cu,1u);
 const auto half=h.allocate(256u);v.w32(object+0x178u,half);h.w8(half,0u);std::array<unsigned char,800>scratch{};leaf::Memory sm(scratch.data(),0x10000u,unsigned(scratch.size()));for(unsigned k=0;k<768u;++k)sm.w8(0x10000u+k,m.r8(palette+k));for(unsigned n=1;n<256u;++n){leaf::Inputs q{};q.cx=0x10000u+3u*n;q.arg[0]=0x10300u;leaf::fun_006343f0(sm,q);sm.w8(0x10302u,sm.r8(0x10302u)>>1u);q.cx=0x10300u;q.arg[0]=0x10310u;leaf::fun_004fe550(sm,q);h.w8(half+n,nearest(sm,0x10000u,0x10310u));}
 const auto identity=h.allocate(256u);v.w32(object+0x170u,identity);v.w32(object+0x174u,identity);h.w8(identity,0u);for(unsigned n=1;n<256u;++n)h.w8(identity+n,nearest(sm,0x10000u,0x10000u+3u*n));Inputs q{};q.cx=object;b1063::fun_004838e0(v,q,h);const auto count=m.r32(0x839490u),data=m.r32(0x839484u);need(count>=1u&&count<=3u&&m.r32(0x839488u)==10u);m.w32(data+count*4u,object);m.w32(0x839490u,count+1u);return object;}
unsigned run(Memory&m,const Inputs&,Heap&h,State&,unsigned root){need(root==0x2ff4c0u&&m.r32(0xab8084u)==0u&&m.r32(0xab8088u)==0u);const auto surface=h.allocate(32u);need(surface);h.w32(surface,0x785f8cu);h.w32(surface+4u,256u);h.w32(surface+8u,256u);h.w32(surface+12u,0u);h.w32(surface+16u,1u);const auto pixels=h.allocate(65536u);need(pixels);h.w32(surface+20u,pixels);h.w32(surface+24u,65536u);h.w8(surface+28u,1u);h.w32(surface,0x785ef8u);m.w32(0xab8084u,surface);
 // Original760760 obtains two actual fullsurface rects, then75FD00's genuine
 // onebyte path locks, fills256 complete rows with0, and unlocks. Netlock0.
 need(m.r32(0x785f10u)==0x760760u&&m.r32(0x785f70u)==0x411290u&&m.r32(0x785f08u)==0x75fd00u);for(unsigned k=0;k<65536u;++k)h.w8(pixels+k,0u);m.w32(0xab8088u,palette_context(m,h,surface));m.w32(0xab808cu,cached(m,0x7e2884u));const auto last=cached(m,0x7e2874u);m.w32(0xab8090u,last);return last;
}
}
