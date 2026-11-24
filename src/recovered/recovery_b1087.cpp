#include "recovered/recovery_b1087.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/leaf_b57_b.hpp"
#include <array>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1087 {
static void need(bool v){if(!v)throw std::domain_error("1087 positive cached onebyte palette n1");}
static unsigned cached(Memory&m,unsigned name){need(name&&m.r32(0xb10530u)==0u);std::vector<unsigned char>s;for(unsigned k=0;k<32u;++k){auto c=m.r8(name+k);if(!c)break;if(c>='a'&&c<='z'){c-=32u;m.w8(name+k,c);}s.push_back(static_cast<unsigned char>(c));}need(!s.empty()&&s.size()<32u);NameHashState hs{};const auto key=fun_00493da0(hs,s.data(),static_cast<int>(s.size()));auto owner=m.r32(0xa588e0u);for(unsigned chain=0;owner&&chain<2u;++chain){const auto next=m.r32(owner+4u);need(next&&m.r32(owner+8u));auto count=m.r32(owner+0x14u),table=m.r32(owner+0x20u);need(count==6u);while(count){const auto middle=count/2u,entry=table+middle*12u,hash=m.r32(entry);if(global_b26::s32(hash)>global_b26::s32(key))count=middle;else if(hash==key){need(m.r32(owner+0x24u));return m.r32(owner+0x24u)+m.r32(entry+4u);}else{table=entry+12u;count-=middle+1u;}}owner=next;}throw std::domain_error("1087 actual loaded asset required");}
static unsigned nearest(leaf::Memory&m,unsigned palette,unsigned target){unsigned best=~0u,index=0u;for(unsigned n=0;n<256u;++n){leaf::Inputs q{};q.cx=target;q.arg[0]=palette+3u*n;const auto d=leaf::fun_006343a0(m,q);if(n==0u||d<best){best=d;index=n;}}return index;}
static unsigned palette(Memory&m,const Inputs&i,Heap&h){const auto source=cached(m,i.cx),palette=h.allocate(768u);need(palette);m.w32(i.dx,palette);for(unsigned k=0;k<768u;++k)h.w8(palette+k,0u);for(unsigned n=0;n<256u;++n)for(unsigned lane=0;lane<3u;++lane)h.w8(palette+3u*n+lane,m.r8(source+3u*n+lane)<<2u);
 const auto object=h.allocate(392u);need(object);leaf::Memory object_span(reinterpret_cast<unsigned char*>(std::uintptr_t(object)),object,392u);auto v=m;v.add(object_span);const auto surface=m.r32(0x821c98u);need(m.r32(surface)==0x785ef8u&&m.r32(0x785f68u)==0x4113b0u&&m.r32(surface+16u)==1u);v.w32(object,0x788f70u);v.w32(object+4u,1u);for(unsigned off=8u;off<=0x17cu;off+=4u)v.w32(object+off,0u);v.w32(object+0x16cu,1u);
 const auto half=h.allocate(256u);v.w32(object+0x178u,half);h.w8(half,0u);std::array<unsigned char,800>scratch{};leaf::Memory sm(scratch.data(),0x10000u,unsigned(scratch.size()));for(unsigned k=0;k<768u;++k)sm.w8(0x10000u+k,h.r8(palette+k));for(unsigned n=1;n<256u;++n){leaf::Inputs q{};q.cx=0x10000u+3u*n;q.arg[0]=0x10300u;leaf::fun_006343f0(sm,q);sm.w8(0x10302u,sm.r8(0x10302u)>>1u);q.cx=0x10300u;q.arg[0]=0x10310u;leaf::fun_004fe550(sm,q);h.w8(half+n,nearest(sm,0x10000u,0x10310u));}
 const auto identity=h.allocate(256u);v.w32(object+0x170u,identity);v.w32(object+0x174u,identity);h.w8(identity,0u);for(unsigned n=1;n<256u;++n)h.w8(identity+n,nearest(sm,0x10000u,0x10000u+3u*n));Inputs q{};q.cx=object;b1063::fun_004838e0(v,q,h);const auto count=m.r32(0x839490u),data=m.r32(0x839484u);need(count>=1u&&count<=4u&&m.r32(0x839488u)==10u);m.w32(data+count*4u,object);m.w32(0x839490u,count+1u);m.w32(i.arg[0],object);return object;
}
unsigned run(Memory&m,const Inputs&,Heap&h,State&,unsigned root){need(root==0x2e6c40u&&m.r8(0xaa8c2cu)==1u);constexpr unsigned cells[]{0x7e1fa4u,0x7e1fa8u,0x7e1facu,0x7e1fb0u},outputs[]{0xaa8ca8u,0xaa8cacu,0xaa8cb0u,0xaa8b78u};for(unsigned n=0;n<4u;++n){const auto value=cached(m,m.r32(cells[n]));m.w8(0xaa8cb4u+n,0u);m.w32(outputs[n],value);}unsigned result=0u;for(unsigned n=0;n<2u;++n){Inputs q{};q.cx=m.r32(0x7e1f50u+4u*n);q.dx=0xaa8bc0u+8u*n;q.arg[0]=q.dx+4u;result=palette(m,q,h);}return (result&0xffffff00u)|m.r8(0xaa8c2cu);}

}
