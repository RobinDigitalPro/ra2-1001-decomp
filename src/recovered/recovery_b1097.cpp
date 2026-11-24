#include "recovered/recovery_b1097.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/leaf_b57_b.hpp"
#include <stdexcept>
namespace ra2::recovered::b1097 {
static void need(bool b){if(!b)throw std::domain_error("1097 cold font positive cachedSHP andreal768-byte PAL/onebyte owner");}
static void word(Observation&o,unsigned p,unsigned n){for(unsigned k=0;k<4u;++k)o.file.at(p+k)=static_cast<unsigned char>(n>>(8u*k));}
static unsigned nearest(leaf::Memory&m,unsigned palette,unsigned target){unsigned best=~0u,index=0u;for(unsigned n=0;n<256u;++n){leaf::Inputs q{};q.cx=target;q.arg[0]=palette+3u*n;const auto d=leaf::fun_006343a0(m,q);if(n==0u||d<best){best=d;index=n;}}return index;}
unsigned cached(Memory&m,unsigned name){
 need(m.r32(0xb10530u)==0u);std::vector<unsigned char>s;
 for(unsigned k=0;k<32u;++k){const auto c=m.r8(name+k);if(!c)break;need(c>=0x20u&&c<=0x7eu&&!(c>='a'&&c<='z'));s.push_back(static_cast<unsigned char>(c));}
 need(s.size()==12u);NameHashState state{};const auto key=fun_00493da0(state,s.data(),static_cast<int>(s.size()));auto owner=m.r32(0xa588e0u);
 for(unsigned chain=0;owner&&chain<2u;++chain){const auto next=m.r32(owner+4u);need(next&&m.r32(owner+8u));auto count=m.r32(owner+0x14u),table=m.r32(owner+0x20u);need(count==0u||count==4u);
  while(count){const auto middle=count/2u,entry=table+middle*12u,hash=m.r32(entry);if(global_b26::s32(hash)>global_b26::s32(key))count=middle;else if(hash==key){const auto backing=m.r32(owner+0x24u);need(backing);return backing+m.r32(entry+4u);}else{table=entry+12u;count-=middle+1u;}}owner=next;
 }throw std::domain_error("1097 genuine positive loaded FULLFNT3.SHP cache hit required");
}
unsigned run(Memory&m,Inputs&i,Heap&h,Api&a,State&,Observation&o){
 need(m.r32(0xa59470u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);for(unsigned p=0x83b2e8u;p<0x83b300u;p+=4u)need(m.r32(p)==0u);
 const auto self=i.cx;need(m.r32(self)==0x79208cu);m.w8(self+0x1cu,0u);const auto shp=cached(m,0x7d0844u);m.w32(self+0x14u,shp);
 const auto name=(i.arg[0]&255u)==1u?0x7d0810u:0x7d0800u;unsigned length=0u;while(m.r8(name+length)){need(length<31u);++length;}need(length==12u);o.name=h.allocate(13u);need(o.name);for(unsigned k=0;k<13u;++k)h.w8(o.name+k,m.r8(name+k));
 word(o,0u,0x7856a0u);word(o,4u,1u);word(o,0xcu,0xffffffffu);word(o,0x10u,0xffffffffu);word(o,0x14u,o.name);o.file[0x1cu]=1u;word(o,0x3cu,0xffffffffu);word(o,0x40u,0xffffffffu);
 const auto path=reinterpret_cast<const char*>(std::uintptr_t(o.name));
 const auto close=[&](HANDLE p){need(a.close_handle(p)!=FALSE);word(o,0x10u,0xffffffffu);};
 const auto probe=[&](){auto p=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(p!=INVALID_HANDLE_VALUE);word(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));close(p);};
 const auto open=[&](bool known){probe();auto p=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(p!=INVALID_HANDLE_VALUE);word(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));if(known)need(a.seek(p,0,nullptr,FILE_BEGIN)==0u);return p;};
 probe();probe();auto file=open(false);need(a.size(file,nullptr)==768u);word(o,0xcu,768u);close(file);
 o.payload=h.allocate(768u);need(o.payload);file=open(true);need(a.seek(file,0,nullptr,FILE_CURRENT)==0u);o.bytes_read=0u;need(a.read_file(file,reinterpret_cast<void*>(std::uintptr_t(o.payload)),768u,&o.bytes_read,nullptr)!=FALSE&&o.bytes_read==768u);m.w8(0xa9e184u,0u);close(file);
 for(unsigned k=0;k<768u;++k)m.w8(0x820a50u+k,h.r8(o.payload+k)<<2u);
 i.arg[0]=(i.arg[0]&0xffff0000u)|(h.r8(o.payload+765u)<<2u)|(h.r8(o.payload+766u)<<10u);
 for(unsigned k=0;k<3u;++k)m.w8(self+12u+k,h.r8(o.payload+204u+k)<<2u);
 const auto channel=[&](unsigned k,unsigned right,unsigned left){return((h.r8(o.payload+204u+k)<<2u)>>(m.r32(right)&31u))<<(m.r32(left)&31u);};m.w32(self+16u,channel(0u,0x83b2ecu,0x83b2e8u)|channel(2u,0x83b2f4u,0x83b2f0u)|channel(1u,0x83b2fcu,0x83b2f8u));
 need(h.release(o.payload)!=0u);const unsigned palette=0x820a50u;
 const auto object=h.allocate(392u);need(object);leaf::Memory object_span(reinterpret_cast<unsigned char*>(std::uintptr_t(object)),object,392u);auto v=m;v.add(object_span);const auto surface=m.r32(0x821c90u);need(m.r32(surface)==0x78bbe4u&&m.r32(0x78bc54u)==0x4aa970u&&m.r32(surface+16u)==1u);v.w32(object,0x788f70u);v.w32(object+4u,1u);for(unsigned off=8u;off<=0x17cu;off+=4u)v.w32(object+off,0u);v.w32(object+0x16cu,1u);
 const auto half=h.allocate(256u);v.w32(object+0x178u,half);h.w8(half,0u);std::array<unsigned char,800>scratch{};leaf::Memory sm(scratch.data(),0x10000u,unsigned(scratch.size()));for(unsigned k=0;k<768u;++k)sm.w8(0x10000u+k,m.r8(palette+k));for(unsigned n=1;n<256u;++n){leaf::Inputs q{};q.cx=0x10000u+3u*n;q.arg[0]=0x10300u;leaf::fun_006343f0(sm,q);sm.w8(0x10302u,sm.r8(0x10302u)>>1u);q.cx=0x10300u;q.arg[0]=0x10310u;leaf::fun_004fe550(sm,q);h.w8(half+n,nearest(sm,0x10000u,0x10310u));}
 const auto identity=h.allocate(256u);v.w32(object+0x170u,identity);v.w32(object+0x174u,identity);h.w8(identity,0u);for(unsigned n=1;n<256u;++n)h.w8(identity+n,nearest(sm,0x10000u,0x10000u+3u*n));Inputs q{};q.cx=object;b1063::fun_004838e0(v,q,h);const auto count=m.r32(0x839490u),data=m.r32(0x839484u);need(count>=1u&&count<=3u&&m.r32(0x839488u)==10u);m.w32(data+count*4u,object);m.w32(0x839490u,count+1u);o.object=object;
m.w32(self+0x18u,object);const auto signed_word=[&](unsigned p){return unsigned(int(static_cast<std::int16_t>(m.r8(p)|(m.r8(p+1u)<<8u))));};m.w32(self+4u,signed_word(shp+2u));m.w32(self+8u,signed_word(shp+4u));need(m.r32(0x819778u)!=0u);
 o.final_free=h.release(o.name);need(o.final_free!=0u);word(o,0u,0x793c3cu);word(o,0x14u,0u);o.file[0x1cu]=0u;return(o.final_free&0xffffff00u)|1u;
}
}
