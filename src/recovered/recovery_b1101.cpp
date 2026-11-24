#include "recovered/recovery_b1101.hpp"
#include "recovered/name_hash.hpp"
#include <string>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1101{
static void need(bool v){if(!v)throw std::domain_error("1101 positive physical/cached building image refresh and onebyte surface");}
static std::string text(Memory&m,unsigned p){std::string s;for(unsigned k=0;k<25u;++k){const auto c=m.r8(p+k);if(!c)return s;need(c>=0x20u&&c<=0x7eu&&!(c>='a'&&c<='z'));s+=char(c);}throw std::domain_error("1101 bounded original config string");}
static unsigned cached(Memory&m,const std::string&s){need(!s.empty()&&s.size()<25u&&m.r32(0xb10530u)==0u);NameHashState state{};const auto key=fun_00493da0(state,reinterpret_cast<const unsigned char*>(s.data()),int(s.size()));auto owner=m.r32(0xa588e0u);
 for(unsigned chain=0;chain<2u&&owner;++chain){need(m.r32(owner+4u)&&m.r32(owner+8u));auto count=m.r32(owner+0x14u),table=m.r32(owner+0x20u);need(count>=4u&&count<=10u);while(count){auto middle=count/2u,entry=table+12u*middle,hash=m.r32(entry);if(global_b26::s32(hash)>global_b26::s32(key))count=middle;else if(hash==key){need(m.r32(owner+0x24u));return m.r32(owner+0x24u)+m.r32(entry+4u);}else{table=entry+12u;count-=middle+1u;}}owner=m.r32(owner+4u);}
 throw std::domain_error("1101 requires every actual loaded filename cache hit");
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,State&fp,Observation&o){need(i.cx<=2u&&m.r32(0x8385e8u)==0u);b1094::run(m,i,h,a,fp,o);m.w32(0x8385ecu,cached(m,text(m,0x7bad64u)));m.w32(0x8385f0u,cached(m,text(m,0x7bad58u)));
 const auto count=m.r32(0xa1e018u),array=m.r32(0xa1e00cu);need(count>=2u&&count<=4u&&array);const auto extension=text(m,0x785bacu+104u*i.cx);unsigned maximum=0u;
 for(unsigned j=0;j<count;++j){const auto p=m.r32(array+4u*j);const auto radius=global_b26::sx8(m.r8(p+0x138bu));need(radius>=1u&&radius<=31u);if(radius>=maximum)maximum=radius;need(m.r8(p+0x1fcu)==1u&&m.r8(p+0x13e0u)==0u&&m.r8(p+0x13e1u)==0u);
  m.w32(p+0xa4u,cached(m,text(m,p+0x1c8u)+"."+extension));const auto buildup=cached(m,text(m,p+0xbf4u)+"."+extension);m.w32(p+0xb98u,buildup);const auto frames=global_b26::sx16(m.r16(buildup+6u));need(frames>=1u&&frames<=31u);m.w32(p+0xc8cu,0u);m.w32(p+0xc90u,frames);m.w32(p+0xc94u,75u/frames);
 }
 need(maximum>0u);const auto dim=maximum+16u,bytes=dim*dim,surface=h.allocate(32u);need(surface);h.w32(surface+0xcu,0u);h.w32(surface,0x785f8cu);h.w32(surface+4u,dim);h.w32(surface+8u,dim);h.w32(surface+0x10u,1u);
 // Exact438140(receiver=surface+14, pointer0, size=bytes): leaves pixels fresh.
 h.w32(surface+0x14u,0u);h.w32(surface+0x18u,bytes);h.w8(surface+0x1cu,0u);const auto pixels=h.allocate(bytes);need(pixels);h.w32(surface+0x14u,pixels);h.w8(surface+0x1cu,1u);h.w32(surface,0x785ef8u);m.w32(0x8385e8u,surface);return surface+0x14u;
}
}
