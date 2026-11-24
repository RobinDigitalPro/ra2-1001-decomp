#include "recovered/recovery_b1090.hpp"
#include "recovered/leaf_b21_a.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/leaf_b57_b.hpp"
#include <stdexcept>
namespace ra2::recovered::b1090 {
static void need(bool b){if(!b)throw std::domain_error("1090 positive real768-byte PAL/onebyte BASE owner");}
static void word(Observation&o,unsigned p,unsigned n){for(unsigned k=0;k<4u;++k)o.file.at(p+k)=static_cast<unsigned char>(n>>(8u*k));}
static unsigned nearest(leaf::Memory&m,unsigned palette,unsigned target){unsigned best=~0u,index=0u;for(unsigned n=0;n<256u;++n){leaf::Inputs q{};q.cx=target;q.arg[0]=palette+3u*n;const auto d=leaf::fun_006343a0(m,q);if(n==0u||d<best){best=d;index=n;}}return index;}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,State&,Observation&o){
 need(m.r32(i.cx)!=0u&&m.r32(0xa588e0u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);
 const auto source=m.r32(i.cx);unsigned length=0u;while(length<31u&&m.r8(source+length))++length;need(length==9u);
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
}
