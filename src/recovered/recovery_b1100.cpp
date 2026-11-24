#include "recovered/recovery_b1100.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/leaf_b57_b.hpp"
#include <stdexcept>
#include "recovered/name_hash.hpp"
#include <vector>
namespace ra2::recovered::b1100 {
static void need(bool b){if(!b)throw std::domain_error("1100 positive real768-byte PAL/onebyte BASE owner");}
template<class O>static void word(O&o,unsigned p,unsigned n){for(unsigned k=0;k<4u;++k)o.file.at(p+k)=static_cast<unsigned char>(n>>(8u*k));}
static unsigned nearest(leaf::Memory&m,unsigned palette,unsigned target){unsigned best=~0u,index=0u;for(unsigned n=0;n<256u;++n){leaf::Inputs q{};q.cx=target;q.arg[0]=palette+3u*n;const auto d=leaf::fun_006343a0(m,q);if(n==0u||d<best){best=d;index=n;}}return index;}
static unsigned cached(Memory&m,unsigned source){need(m.r32(0xb10530u)==0u);std::vector<unsigned char>text;for(unsigned k=0;k<32u;++k){const auto c=m.r8(source+k);if(!c)break;need(c>=32u&&c<127u&&!(c>='a'&&c<='z'));text.push_back(static_cast<unsigned char>(c));}need(text.size()==9u||text.size()==12u);NameHashState state{};const auto key=fun_00493da0(state,text.data(),int(text.size()));auto owner=m.r32(0xa588e0u);for(unsigned chain=0;owner&&chain<3u;++chain){const auto next=m.r32(owner+4u),previous=m.r32(owner+8u);if(!next||!previous)return 0u;auto count=m.r32(owner+20u),table=m.r32(owner+32u);need(count==0u||count==4u);while(count){const auto middle=count/2u,entry=table+12u*middle,hash=m.r32(entry);if(global_b26::s32(hash)>global_b26::s32(key))count=middle;else if(hash==key){const auto backing=m.r32(owner+36u);need(backing);return backing+m.r32(entry+4u);}else{table=entry+12u;count-=middle+1u;}}owner=next;}return 0u;}
static unsigned palette_owner(Memory&m,const Inputs&i,Heap&h,Api&a,State&,PalObservation&o){
 need(m.r32(i.cx)!=0u&&m.r32(0xa588e0u)!=0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);
 const auto source=m.r32(i.cx);unsigned length=0u;while(length<31u&&m.r8(source+length))++length;need(length==9u&&cached(m,source)==0u);
 o.name=h.allocate(length+1u);need(o.name);for(unsigned k=0;k<=length;++k)h.w8(o.name+k,m.r8(source+k));
 word(o,0u,0x7856a0u);word(o,4u,1u);word(o,0xcu,0xffffffffu);word(o,0x10u,0xffffffffu);word(o,0x14u,o.name);o.file[0x1cu]=1u;word(o,0x3cu,0xffffffffu);word(o,0x40u,0xffffffffu);
 // Actual5928A0 folds the OWNED filename before physical availability.
 for(unsigned k=0;k<length;++k){auto ch=h.r8(o.name+k);if(ch>='a'&&ch<='z')h.w8(o.name+k,ch-32u);}
 const auto path=reinterpret_cast<const char*>(std::uintptr_t(o.name));
 const auto close=[&](HANDLE p){need(a.close_handle(p)!=FALSE);word(o,0x10u,0xffffffffu);};
 const auto probe=[&](){auto p=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(p!=INVALID_HANDLE_VALUE);word(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));close(p);};
 const auto open=[&](bool known){probe();auto p=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(p!=INVALID_HANDLE_VALUE);word(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));if(known)need(a.seek(p,0,nullptr,FILE_BEGIN)==0u);return p;};
 probe();probe();probe();auto file=open(false);need(a.size(file,nullptr)==768u);word(o,0xcu,768u);close(file);
 o.payload=h.allocate(768u);need(o.payload);file=open(true);need(a.seek(file,0,nullptr,FILE_CURRENT)==0u);o.bytes_read=0u;need(a.read_file(file,reinterpret_cast<void*>(std::uintptr_t(o.payload)),768u,&o.bytes_read,nullptr)!=FALSE&&o.bytes_read==768u);m.w8(0xa9e184u,0u);close(file);
 for(unsigned k=0;k<768u;++k)m.w8(0x820a50u+k,h.r8(o.payload+k)<<2u);
 need(h.release(o.payload)!=0u);const unsigned palette=0x820a50u;
 const auto object=h.allocate(392u);need(object);leaf::Memory object_span(reinterpret_cast<unsigned char*>(std::uintptr_t(object)),object,392u);auto v=m;v.add(object_span);const auto surface=m.r32(0x821c90u);need(m.r32(surface)==0x78bbe4u&&m.r32(0x78bc54u)==0x4aa970u&&m.r32(surface+16u)==1u);v.w32(object,0x788f70u);v.w32(object+4u,1u);for(unsigned off=8u;off<=0x17cu;off+=4u)v.w32(object+off,0u);v.w32(object+0x16cu,1u);
 const auto half=h.allocate(256u);v.w32(object+0x178u,half);h.w8(half,0u);std::array<unsigned char,800>scratch{};leaf::Memory sm(scratch.data(),0x10000u,unsigned(scratch.size()));for(unsigned k=0;k<768u;++k)sm.w8(0x10000u+k,m.r8(palette+k));for(unsigned n=1;n<256u;++n){leaf::Inputs q{};q.cx=0x10000u+3u*n;q.arg[0]=0x10300u;leaf::fun_006343f0(sm,q);sm.w8(0x10302u,sm.r8(0x10302u)>>1u);q.cx=0x10300u;q.arg[0]=0x10310u;leaf::fun_004fe550(sm,q);h.w8(half+n,nearest(sm,0x10000u,0x10310u));}
 const auto identity=h.allocate(256u);v.w32(object+0x170u,identity);v.w32(object+0x174u,identity);h.w8(identity,0u);for(unsigned n=1;n<256u;++n)h.w8(identity+n,nearest(sm,0x10000u,0x10000u+3u*n));Inputs q{};q.cx=object;b1063::fun_004838e0(v,q,h);const auto count=m.r32(0x839490u),data=m.r32(0x839484u);need(count>=1u&&count<=3u&&m.r32(0x839488u)==10u);m.w32(data+count*4u,object);m.w32(0x839490u,count+1u);o.object=object;
 // Original raw buffer/raw file destructor: no reader owner, final filename free.
 o.final_free=h.release(o.name);need(o.final_free!=0u);word(o,0u,0x793c3cu);word(o,0x14u,0u);o.file[0x1cu]=0u;return object;
}
static void construct_file(Memory&m,unsigned holder,Heap&h,FileObservation&o){const auto p=m.r32(holder);unsigned n=0u;while(m.r8(p+n)){need(n<31u);++n;}need(n==9u||n==12u);o.name=h.allocate(n+1u);need(o.name);for(unsigned k=0;k<=n;++k)h.w8(o.name+k,m.r8(p+k));word(o,0u,0x7856a0u);word(o,4u,1u);word(o,12u,0xffffffffu);word(o,16u,0xffffffffu);word(o,20u,o.name);o.file[28u]=1u;word(o,60u,0xffffffffu);word(o,64u,0xffffffffu);}
static void destroy_file(Heap&h,FileObservation&o){need(h.release(o.name)!=0u);word(o,0u,0x793c3cu);word(o,20u,0u);o.file[28u]=0u;}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,Clock clock,State&s,Observation&o){need(clock&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u);const auto self=i.cx,registry=i.arg[1];
 m.w32(self,0x78dbd0u);m.w32(self+4u,i.arg[0]);m.w8(self+8u,0u);m.w8(self+9u,1u);m.w32(self+12u,0u);for(unsigned k=0;k<4u;++k)m.w32(self+16u+4u*k,m.r32(i.arg[3]+4u*k));m.w32(self+32u,0u);m.w32(self+36u,0u);m.w32(self,0x78db98u);
 construct_file(m,i.arg[4],h,o.shp);construct_file(m,i.arg[5],h,o.outer_pal);auto v=m;leaf::Memory sn(reinterpret_cast<unsigned char*>(std::uintptr_t(o.shp.name)),o.shp.name,13u),pn(reinterpret_cast<unsigned char*>(std::uintptr_t(o.outer_pal.name)),o.outer_pal.name,10u);v.add(sn);v.add(pn);need(cached(v,o.shp.name)!=0u&&cached(v,o.outer_pal.name)==0u);
 const auto file=a.create_file_a(reinterpret_cast<LPCSTR>(std::uintptr_t(o.outer_pal.name)),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(file!=INVALID_HANDLE_VALUE);word(o.outer_pal,16u,unsigned(reinterpret_cast<std::uintptr_t>(file)));need(a.close_handle(file)!=FALSE);word(o.outer_pal,16u,0xffffffffu);
 o.holder=h.allocate(10u);need(o.holder);const auto pal_name=m.r32(i.arg[5]);for(unsigned k=0;k<10u;++k)h.w8(o.holder+k,m.r8(pal_name+k));std::array<unsigned char,4>cell{};const auto cell_address=unsigned(reinterpret_cast<std::uintptr_t>(cell.data()));leaf::Memory cn(cell.data(),cell_address,4u),hn(reinterpret_cast<unsigned char*>(std::uintptr_t(o.holder)),o.holder,10u);v.add(cn);v.add(hn);v.w32(cell_address,o.holder);Inputs pi{};pi.cx=cell_address;const auto palette=palette_owner(v,pi,h,a,s,o.inner);m.w32(self+36u,palette);need(h.release(o.holder)!=0u);v.w32(cell_address,0u);
 o.animation=h.allocate(64u);need(o.animation);const auto p=o.animation;h.w32(p+4u,m.r32(i.arg[2]));h.w32(p+8u,m.r32(i.arg[2]+4u));h.w8(p+12u,1u);h.w32(p+16u,clock()>>4u);h.w32(p+24u,0u);h.w32(p+32u,palette);h.w32(p+36u,i.arg[6]);h.w32(p+40u,0u);h.w8(p+52u,i.arg[7]);h.w32(p+56u,0u);h.w32(p,0x791d38u);h.w8(p+60u,0u);const auto shp=cached(m,m.r32(i.arg[4]));need(shp);h.w32(p+28u,shp);h.w32(p+44u,0u);h.w32(p+48u,unsigned(int(static_cast<std::int16_t>(m.r16(shp+6u)))-1));
 need(m.r32(registry+24u)==0x79202cu&&m.r32(0x79203cu)==0x5b0730u);const auto count=m.r32(registry+40u),capacity=m.r32(registry+32u),data=m.r32(registry+28u);need(count>=3u&&count<=6u&&capacity==10u&&m.r8(registry+36u)==1u&&m.r8(registry+37u)==0u);m.w32(registry+40u,count+1u);m.w32(data+4u*count,p);unsigned found=0u;while(found<count+1u&&m.r32(data+4u*found)!=p)++found;need(found==count);
 destroy_file(h,o.outer_pal);destroy_file(h,o.shp);return self;
}
}
