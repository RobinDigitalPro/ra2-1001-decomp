#include "recovered/records_b75.hpp"
#include "recovered/leaf_state.hpp"
#include "recovered/leaf_containers.hpp"
#include "recovered/leaf_b15_b.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::records_b75 {
using namespace global_b26;
namespace {
void unlink_one(Memory& m,std::uint32_t node) {
    const auto next=m.r32(node+8),prev=m.r32(node+4);
    if(next && prev) { m.w32(next+4,prev); m.w32(prev+8,next); m.w32(node+8,0); m.w32(node+4,0); }
}
void unlink_head(Memory& m,std::uint32_t head,std::uint32_t tag,bool first) {
    m.w32(head,tag);
    auto node=m.r32(head+8);
    for(unsigned n=0;node && m.r32(node+4) && m.r32(node+8);++n) {
        if(n==512) throw std::domain_error("Block75 list exceeds 512 nodes");
        const auto next=m.r32(node+8),prev=m.r32(node+4);
        m.w32(next+4,prev); m.w32(prev+8,next); m.w32(node+8,0); m.w32(node+4,0);
        node=m.r32(head+8);
    }
    (void)first;
}
void unlink_embedded(Memory& m,std::uint32_t head,std::uint32_t tag) {
    m.w32(head,tag);const auto prev=m.r32(head+4),next=m.r32(head+8);
    if(prev && next){m.w32(next+4,prev);m.w32(prev+8,next);m.w32(head+8,0);m.w32(head+4,0);}
}
}

std::uint32_t fun_00405300(Memory& m,const Inputs& i) {
 const auto o=i.cx; if(m.r8(o+0x18)&1u) return 0;
 const auto child=m.r32(o+0xb0); if(child && m.r32(child+0xc0)==o)throw std::domain_error("Block75 matching-child callback route excluded");
 auto count=m.r32(o+0xa8);if(s32(count)>0 && count>512)throw std::domain_error("Block75 slot count exceeds 512");
 for(std::uint32_t k=0;s32(count)>0 && k<count;++k) { const auto slot=m.r32(o+0x28+4*k); if(!slot)throw std::domain_error("Block75 null release slot");
  std::array<std::uint8_t,16> b{}; constexpr std::uint32_t base=0x1000; leaf::Memory span(b.data(),base,16); leaf::Inputs li{};
  span.w32(base+0xc,m.r32(slot+0xc)); li.cx=base; (void)leaf::fun_00401f90(span,li); m.w32(slot+0xc,span.r32(base+0xc)); m.w32(o+0x28+4*k,0);
 }
 m.w32(o+0xa8,0);m.w32(o+0x1c,4);m.w32(o+0x138,0);m.w32(o+0x278,0);m.w32(o+0x18,m.r32(o+0x18)|1u);return count;
}
std::uint32_t fun_0040e220(Memory& m,const Inputs& i) {
 const auto o=i.cx; unlink_head(m,o,0x785af4,true);unlink_embedded(m,o+0x10,0x785afc);unlink_embedded(m,o+4,0x785afc);
 (void)i.arg[0]; return o;
}
std::uint32_t fun_0040e300(Memory& m,const Inputs& i) { return fun_0040e220(m,i); }
std::uint32_t fun_00444240(Memory& m,const Inputs& i) {
 const auto o=i.cx, type=m.r32(o+0x418), key=m.r32(type+0xc44); if(!key)return 0;
 const auto old=m.r8(o+0x32b),parent=m.r32(o+0x1b4),count=m.r32(parent+0x78);if(s32(count)>512)throw std::domain_error("Block75 peer count exceeds 512");
 bool found=false;std::uint32_t peer=0;const auto want=!!m.r8(type+0xada);
 for(std::uint32_t n=0;s32(count)>0 && n<count;++n){auto q=m.r32(m.r32(parent+0x6c)+4*n);if(!q)throw std::domain_error("Block75 null peer pointer");
  const auto qt=m.r32(q+0x418);if(m.r8(q+0x76)==0 && m.r8(q+0x32b)!=0 && m.r32(qt+0xc44)==key && (!!m.r8(qt+0xada)==want)){found=true;peer=q;break;}}
 if(found){if(i.arg[0]&255u){m.w8(peer+0x32b,0);m.w8(o+0x32b,1);}}else m.w8(o+0x32b,1);
 return (m.r8(o+0x32b)!=old)?1u:0u;
}
std::uint32_t fun_004b95e0(Memory& m,const Inputs& i) {
 const auto o=i.cx;if(m.r32(o+0x54)!=0 && m.r32(o+0x24)==0x36){m.w32(o+0x54,0);}
 else if(m.r32(o+0x64)!=0 && m.r32(o+0x24)==0x36){m.w32(o+0x64,0xffffffffu);}
 else return 0;
 m.w8(o+0x6c,1);m.w8(o+0x59,1);m.w32(o+0x24,0);m.w32(o+0x34,0);m.w32(o+0x28,m.r32(0xa2896c));m.w32(o+0x2c,i.stack_minus8);m.w32(o+0x30,0);return 1;
}
std::uint32_t fun_004ee0a0(Memory& m,const Inputs& i) {
 const auto o=i.cx,count=m.r32(o+0x5504); if(s32(count)<=0)return o;if(count>512)throw std::domain_error("Block75 candidate count exceeds 512");
 const auto arr=m.r32(o+0x54f8), wanted=i.arg[1],delta=i.arg[0];for(std::uint32_t n=0;n<count;++n){const auto e=arr+8*n;if(m.r32(e)==wanted)m.w32(e+4,m.r32(e+4)+delta);}
 i.arg[0]=0; i.arg[1]=count;
 std::uint32_t best=0,bestWeight=0;
 for(std::uint32_t n=0;n<count;++n){const auto e=arr+8*n,p=m.r32(e),weight=m.r32(e+4);i.arg[1]--;
  if(s32(weight)<=0)continue;if(!p)throw std::domain_error("Block75 null positive-weight candidate");
  if(m.r8(p+0x13d)!=0 || p==o)continue;
  const auto cat=m.r32(p+0x30), own=m.r32(o+0x30);if(cat==own)continue;
  if(cat!=0xffffffffu && (m.r32(o+0x5674)&(1u<<(cat&31u)))!=0)continue;
  if(weight>bestWeight){best=p;bestWeight=weight;i.arg[0]=p;}
 }
 m.w32(o+0x54f0,best?m.r32(best+0x30):0xffffffffu);return o;
}
std::uint32_t fun_004f3440(Memory& m,const Inputs& i) {
 if(m.r8(0xa28953)!=0)return 0;
 const auto p=i.arg[0],q=m.r32(p+0x418);if(m.r32(p+0x88)||m.r32(p+0x8c)||m.r32(p+0x90))return 0;
 const auto count=m.r32(i.cx+0x5604);if(!count||count>512) return 0;const auto arr=m.r32(i.cx+0x55f8), key=m.r32(q+0xb90);
 std::uint32_t idx=0;for(;idx<count;++idx){const auto e=arr+16*idx;if(m.r32(e)==key && m.r16(e+4)==0 && m.r16(e+6)==0)break;}
 if(idx==count)return 0;const auto chosen=arr+16*idx, match=m.r32(chosen+4);for(std::uint32_t n=0;n<count;++n){const auto e=arr+16*n+4;if(n!=idx && m.r16(e)==static_cast<std::uint16_t>(match) && m.r16(e+2)==0)m.w32(e,m.r32(0xa28b5c));}
 if(m.r8(q+0x138a)!=0 && m.r32(0xa255c8)!=0){m.w32(chosen,0xffffffff);m.w32(chosen+4,m.r32(0xa28b5c));}
 return q;
}
std::uint32_t fun_00592420(Memory& m,const Inputs& i) {
 const auto o=i.cx;if(m.r32(o+0xc))throw std::domain_error("Block75 unresolved 0x36df28 path excluded");
 if(m.r32(o+0x20))throw std::domain_error("Block75 owned release path excluded");
 const auto owned=m.r32(o+0x24);if(owned && m.r8(o+0x12))throw std::domain_error("Block75 release helper path excluded");
 m.w32(o,0x791458);m.w32(o+0x24,0);
 unlink_one(m,o);m.w32(o,0x785afc);unlink_one(m,o);return 0;
}
std::uint32_t fun_00592b60(Memory& m,const Inputs& i) {const auto o=i.cx;unlink_head(m,o,0x785af4,true);unlink_embedded(m,o+0x10,0x785afc);unlink_embedded(m,o+4,0x785afc);return o;}
std::uint32_t fun_0060e7b0(Memory& m,const Inputs& i) {
 auto a=i.cx,b=i.dx;if(!a&&!b)return 1;if(!a||!b)return 0;
 const auto ca=m.r32(a+0x14),cb=m.r32(b+0x14);if(!ca&&!cb)return 1;if(!ca||!cb)return 0;
 if(ca>512||cb>512)throw std::domain_error("Block75 outer count exceeds 512");
 const auto ra=m.r32(m.r32(a+8)+4*(ca-1)),rb=m.r32(m.r32(b+8)+4*(cb-1));
 const auto na=m.r32(ra+0x10),nb=m.r32(rb+0x10);if(na>512||nb>512)throw std::domain_error("Block75 nested count exceeds 512");
 const auto ta=m.r32(a),tb=m.r32(b);std::uint32_t n=0;
 for(;n<na;++n){const auto e=m.r32(m.r32(ra+4)+4*n);if(m.r32(e)==tb)break;}
 if(n==na)return na&0xffffff00u;if(s32(nb)<=0)return 0;
 for(n=0;n<nb;++n){const auto e=m.r32(m.r32(rb+4)+4*n);if(m.r32(e)==ta)return (n&0xffffff00u)|1u;}
 return nb&0xffffff00u;
}
std::uint32_t fun_00634780(Memory& m,const Inputs& i) {const auto o=i.cx,c=m.r32(o+0xc);const auto off=((c/8u)&255u);if(i.arg[0]&1u)m.w8(o+0x14+off,m.r8(o+0x14+off)^(1u<<(c&7u)));const auto next=c+1;m.w32(o+0xc,next);return next;}
std::uint32_t fun_006367f0(Memory& m,const Inputs& i) {
 const auto o=i.cx,p=i.arg[0];if(!p)return 0xffu;
 std::array<std::uint8_t,32> scratch{};constexpr std::uint32_t b=0x2000u;
 for(unsigned n=0;n<10;++n)scratch[n]=static_cast<std::uint8_t>(m.r8(p+n));
 leaf::Memory local(scratch.data(),b,static_cast<std::uint32_t>(scratch.size()));leaf::Inputs test{};test.cx=b;
 if(ra2::recovered::leaf::fun_00522aa0(local,test))return 0xffu;
 leaf::Inputs copy{};copy.cx=b;copy.arg[0]=b+0x10;copy.arg[1]=b+0x14;
 (void)ra2::recovered::leaf::fun_00522a60(local,copy);i.arg[0]=local.r32(b+0x10);const auto key=local.r32(b+0x14);
 const auto count=m.r32(o+0x10);if(s32(count)<=0)return 0;if(count>512)throw std::domain_error("Block75 membership count exceeds 512");
 const auto arr=m.r32(o+4);std::uint32_t n=0;for(;n<count;++n){const auto p2=m.r32(arr+4*n);if(m.r32(p2+0x21)==key)return (n&0xffffff00u)|(m.r8(p2+0x26)&0xffu);}return count&0xffffff00u;
}
std::uint32_t fun_0067fc60(Memory& m,const Inputs& i) {
 const auto o=i.cx,item=i.arg[0];if(item==m.r32(o+0x68)||item==m.r32(o+0x6c)||item==m.r32(o+0x24))return 0;
 auto count=m.r32(o+0x48);if(s32(count)<=0)return 0;if(count>512)throw std::domain_error("Block75 association count exceeds 512");const auto list=m.r32(o+0x3c);
 for(std::uint32_t n=count;n>0;--n){const auto entry=m.r32(list+4*(n-1));if(m.r32(entry)!=item)continue;const auto child=m.r32(entry);if(s32(m.r32(child+0x6c))>0 && !m.r8(child+0x5b2) && m.r32(entry+0x14)!=1)return 0;
  m.w32(entry,0);m.w32(entry+4,7);const auto rec=m.r32(list+4*(n-1))+8;m.w32(rec,m.r32(0xa2896c));m.w32(rec+4,i.stack_minus8);m.w32(rec+8,m.r32(o+0x30));return rec;}
 return 0;
}
std::uint32_t fun_007570f0(Memory& m,const Inputs& i) {
 const auto o=i.cx;auto compact=[&](unsigned po,unsigned co,unsigned owner,unsigned saved){auto count=m.r32(o+co);if(count>512)throw std::domain_error("Block75 owned array count exceeds 512");const auto list=m.r32(o+po);while(count){const auto child=m.r32(list);if(!child)throw std::domain_error("Block75 null owned child");if(m.r8(child+0x46)!=0)throw std::domain_error("Block75 owned release route excluded");m.w8(child+0x45,0);m.w32(o+owner,m.r32(o+owner)-1);for(std::uint32_t n=1;n<count;++n)m.w32(list+4*(n-1),m.r32(list+4*n));--count;m.w32(o+co,count);}m.w32(o+owner,0);m.w32(o+saved,0);};
 compact(0x24,0x30,0x43860,0x43854);compact(0x3c,0x48,0x43864,0x43858);return 0;
}
std::uint32_t fun_00757600(Memory& m,const Inputs& i) {
 const auto o=i.cx;auto active=m.r32(o+0x4385c);if(active>=128)throw std::domain_error("Block75 full-capacity allocation route excluded");auto idx=m.r32(o+0x43850);if(idx>127)throw std::domain_error("Block75 slot cursor outside 0..127");
 for(unsigned scan=0;scan<128;++scan){const auto next=idx+1;m.w32(o+0x43850,next>127?0:next);const auto slot=o+0x50+idx*0x2d0;if(m.r8(slot+0x45)==0){m.w8(slot+0x45,1);m.w32(o+0x4385c,active+1);m.w8(slot+0x47,0);m.w8(slot+0x48,0);return slot;}idx=next>127?0:next;}return 0;
}
}
