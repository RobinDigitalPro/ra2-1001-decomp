#include "recovered/global_b27_memory.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::global_b27 {
namespace {
inline std::uint32_t arg(const State&s,unsigned n){return s.arg[n];}
inline std::uint32_t sdivq(std::uint32_t a,std::uint32_t b){
    if(!b || (a==0x80000000u&&b==0xffffffffu)) throw std::domain_error("excluded x86 IDIV fault");
    return static_cast<std::uint32_t>(static_cast<std::int64_t>(s32(a))/static_cast<std::int64_t>(s32(b)));
}
inline std::uint32_t sdivr(std::uint32_t a,std::uint32_t b){
    if(!b || (a==0x80000000u&&b==0xffffffffu)) throw std::domain_error("excluded x86 IDIV fault");
    return static_cast<std::uint32_t>(static_cast<std::int64_t>(s32(a))%static_cast<std::int64_t>(s32(b)));
}
struct U64Division {std::uint32_t q, qhigh, ecx; std::uint64_t remainder;};
inline U64Division divide_u64(std::uint32_t nl,std::uint32_t nh,std::uint32_t dl,std::uint32_t dh){
 const std::uint64_t n=(std::uint64_t(nh)<<32)|nl,d=(std::uint64_t(dh)<<32)|dl;
 if(!d)throw std::domain_error("excluded original unsigned DIV fault");
 if(!dh){const auto qhi=nh/dl,remhi=nh%dl;const auto low=(std::uint64_t(remhi)<<32)|nl;const auto qlo=low/dl;return {static_cast<std::uint32_t>(qlo),qhi,dl,n%d};}
 std::uint64_t sn=n,sd=d;while((sd>>32)!=0){sn>>=1;sd>>=1;} if(!sd||sn/sd>0xffffffffull)throw std::domain_error("excluded normalized DIV quotient overflow");
 const auto q0=static_cast<std::uint32_t>(sn/sd);const auto intermediate=static_cast<std::uint32_t>(std::uint64_t(q0)*dh);const auto q=static_cast<std::uint32_t>(q0-(std::uint64_t(q0)>n/d));
 return {q,0,intermediate,n%d};
}
}

static void f36abc2(Memory&,State&s){s.ax=(s.flag_toggle_mask&0x200000u)?2u:((s.flag_toggle_mask&0x40000u)?1u:0u);}
static void f36adc0(Memory&m,State&s){auto p=arg(s,0);m.w16(p+0x22,0);m.w16(p+0x20,7);m.w32(p+0x14,0);m.w32(p+0x10,0);m.w16(p+0x36,0);m.w16(p+0x34,7);m.w32(p+0x28,0);m.w32(p+0x24,0);s.ax=p;}
static void f36b280(Memory&m,State&s){auto p=arg(s,0);m.w16(p+0x22,0);m.w32(p+0x14,0);m.w16(p+0x36,0);m.w32(p+0x28,0);s.ax=p;}
static void f36bea0(Memory&m,State&s){auto p=arg(s,0);m.w16(p+4,0);m.w32(p,0);m.w16(p+0xa,0);m.w32(p+6,0);s.ax=p;}
// Portable quotient/remainder helpers preserve both quotient limbs and are
// restricted to inputs whose original DIV instructions do not fault.
static void f36dec0(Memory&,State&s){
 const auto d=divide_u64(s.arg[0],s.arg[1],s.arg[2],s.arg[3]);s.ax=d.q;s.dx=d.qhigh;s.cx=d.ecx;
}
// Entry-SP S has [S]=continuation; page probes and the final push are modeled
// in the explicit guest stack span. No arbitrary control target is invoked.
static void f36f190(Memory&m,State&s,StackContext&c){const auto saved_cx=s.cx;std::uint32_t ecx=c.entry_sp+4u,eax=s.ax;
 m.w32(c.entry_sp-4u,saved_cx);
 while(eax>=0x1000u){ecx-=0x1000u;eax-=0x1000u;(void)m.r32(ecx);}
 ecx-=eax;const auto old_esp=c.entry_sp-4u;(void)m.r32(ecx);const auto out_cx=m.r32(old_esp),out_ax=m.r32(old_esp+4u);m.w32(ecx-4u,out_ax);
 s.cx=out_cx;s.ax=out_ax;c.exit_sp=ecx;c.next_ip=out_ax;(void)c.return_address;
}
static void f370bb2(Memory&m,State&s){m.w32(0x817258u,m.r32(s.bp+8u));m.w32(0x817254u,s.ax);m.w32(0x81725cu,s.bp);}
static void f371310(Memory&m,State&s){const auto set=arg(s,1),str=arg(s,0);bool bits[256]{};auto q=set;for(;m.r8(q);++q)bits[m.r8(q)]=true;s.dx=q;std::uint32_t i=0;for(auto p=str;;++p,++i){const auto c=m.r8(p);if(!c){s.ax=i;s.cx=i;return;}if(bits[c]){s.ax=i;s.cx=i;return;}}}
static void accessor(Memory&m,State&s){auto p=arg(s,0);m.w32(p,m.r32(p)+8u);s.cx=m.r32(p);s.ax=m.r32(s.cx-8u);s.dx=m.r32(s.cx-4u);}
static void f372651(Memory&m,State&s){accessor(m,s);} static void f376562(Memory&m,State&s){accessor(m,s);} static void f382808(Memory&m,State&s){accessor(m,s);}
static void f378d6c(Memory&m,State&s){s.cx=0;s.dx=0;for(std::uint32_t i=0;i<27;++i){auto a=0x817a28u+i*8u;s.dx=m.r32(a);if(s.dx==arg(s,0)){s.ax=m.r32(a+4);s.cx=i;return;}}s.ax=0;s.cx=27;}
static void f379484(Memory&m,State&s){
 auto value=arg(s,0),ecx=arg(s,1),base=arg(s,2);if(base<2||base>36)throw std::domain_error("379484 base outside 2..36");
 if(arg(s,3)){m.w8(ecx++,0x2d);value=0u-value;}auto edi=ecx;std::uint32_t eax=0,edx=0;
 do{eax=value/base;edx=value%base;const auto ebx=edx;value=eax;const auto ch=(ebx<=9u)?((ebx+0x30u)&255u):((ebx+0x57u)&255u);m.w8(ecx++,ch);}while(value);
 m.w8(ecx,0);--ecx;do{edx=(edx&0xffffff00u)|m.r8(edi);eax=(eax&0xffffff00u)|m.r8(ecx);m.w8(ecx,edx);m.w8(edi,eax);--ecx;++edi;}while(edi<ecx);s.ax=eax;s.dx=edx;s.cx=ecx;
}
static void f3797a6(Memory&m,State&s){auto p=arg(s,0),v=arg(s,1);const auto q=sdivq(v,10u);m.w8(p,q+0x30u);++p;const auto rem=sdivr(v,10u);s.dx=rem;s.cx=p;s.ax=p+1u;s.dx=(s.dx&0xffffff00u)|(((s.dx&255u)+0x30u)&255u);m.w8(p,s.dx);}
static void mutate_text(Memory&m,State&s){std::uint32_t p=arg(s,0);s.cx=p;auto al=m.r8(p);s.ax=(s.ax&0xffffff00u)|al;if(!al)return;for(;;){if(al>='0'&&al<='9'){al-=0x30u;s.ax=(s.ax&0xffffff00u)|al;m.w8(p,al);++p;s.cx=p;al=m.r8(p);s.ax=(s.ax&0xffffff00u)|al;if(al)continue;return;}if(al==0x3b){s.ax=p;auto eax=p,esi=p+1u,dl=m.r8(eax+1u);s.dx=(s.dx&0xffffff00u)|dl;m.w8(eax,dl);eax=esi;while(m.r8(eax)!=0){dl=m.r8(eax+1u);s.dx=(s.dx&0xffffff00u)|dl;esi=eax+1u;m.w8(eax,dl);eax=esi;}s.ax=(eax&0xffffff00u)|m.r8(p);al=s.ax&255u;if(!al)return;continue;}++p;s.cx=p;al=m.r8(p);s.ax=(s.ax&0xffffff00u)|al;if(!al)return;}}
static void f37a837(Memory&m,State&s){mutate_text(m,s);}static void f37aa5b(Memory&m,State&s){mutate_text(m,s);}static void f37ad30(Memory&m,State&s){const auto set=arg(s,1),str=arg(s,0);bool bits[256]{};auto q=set;for(;m.r8(q);++q)bits[m.r8(q)]=true;s.dx=q;for(auto p=str;m.r8(p);++p)if(bits[m.r8(p)]){s.ax=p;return;}s.ax=0;}
static void f37b41a(Memory&m,State&s){auto k=arg(s,0)&0xffffu;for(std::uint32_t i=0;i<10;++i)if(m.r16(0x818104u+i*2u)==k){s.ax=0;s.cx=with_ax(s.cx,k);return;}s.ax=1;s.cx=with_ax(s.cx,k);}
static void f37b880(Memory&,State&s){const auto d=divide_u64(s.arg[0],s.arg[1],s.arg[2],s.arg[3]);s.ax=static_cast<std::uint32_t>(d.remainder);s.dx=static_cast<std::uint32_t>(d.remainder>>32);s.cx=d.ecx;}
static void f37b8f5(Memory&m,State&s){auto p=arg(s,0);const auto index=sdivq(arg(s,1),32u);const auto rem=sdivr(arg(s,1),32u);const auto shift=(31u-rem)&31u;const auto mask=~(0xffffffffu<<shift);s.cx=31u-rem;s.dx=mask;if(m.r32(p+index*4u)&mask){s.ax=0;return;}for(std::uint32_t j=index+1u;j<3u;++j)if(m.r32(p+j*4u)){s.ax=0;return;}s.ax=1;}
static void f37f60e(Memory&m,State&s){auto i=arg(s,0)&255u,mask=arg(s,2)&255u;s.cx=(s.cx&0xffffff00u)|mask;if(m.r8(0x00b10be1u+i)&mask){s.ax=1;return;}auto v=arg(s,1);s.ax=v?((m.r16(0x81756au+i*2u)&v)?1u:0u):0u;}
static void f37ffb8(Memory&m,State&s){auto value=arg(s,0),slot=arg(s,1),countp=arg(s,2),p=m.r32(slot);auto count=m.r32(countp);std::uint32_t last_rem=s.dx;if(count>1u){do{last_rem=sdivr(value,10u);const auto q=sdivq(value,10u);m.w8(p++,static_cast<std::uint32_t>(last_rem+'0'));--count;m.w32(countp,count);value=q;s.arg[0]=value;
 }while(s32(value)>0&&count>1u);}auto start=m.r32(slot);m.w32(slot,p);auto ecx=p-1u,eax=start;do{const auto bl=m.r8(eax),dl=m.r8(ecx);last_rem=(last_rem&0xffffff00u)|dl;m.w8(ecx,bl);--ecx;m.w8(eax,dl);++eax;}while(eax<ecx);s.ax=eax;s.cx=ecx;s.dx=last_rem;}
static void f384cb0(Memory&m,State&s){const auto saved=s;auto src=arg(s,0),dst=arg(s,1),len=arg(s,2);if(len<4)throw std::domain_error("384cb0 requires positive pair-loop length >=4");auto count=(len-2u)>>1u;for(std::uint32_t j=0;j<count;++j){const auto x=m.r32(src+2u*j);auto edx=x&0xffffu;auto ebx=x;ebx=(ebx>>8)|(ebx<<24);ebx=(ebx&0xffffff00u)|m.r8(0xa29424u+edx);ebx=(ebx&0xffff00ffu)|((x&0xff00u));auto eax=x&0x00ffff00u;ebx=(ebx>>8)|(ebx<<24);eax>>=8;ebx=(ebx&0xffff00ffu)|(m.r8(0xa29424u+eax)<<8);ebx=(ebx>>16)|(ebx<<16);m.w32(dst+4u*j,ebx);}auto off=2u*count;auto ax=m.r16(src+off);m.w8(dst+4u*count,ax);++dst;m.w8(dst+4u*count,m.r8(0xa29424u+ax));m.w8(dst+4u*count+1u,ax>>8);m.w8(dst+4u*count+2u,0);s=saved;}
static void f384d12(Memory&m,State&s){const auto saved=s;auto a=arg(s,0),b=arg(s,1),out=arg(s,2),count=2u*arg(s,3);if(!count)throw std::domain_error("384d12 zero modulo loop count is outside the bounded domain");for(std::uint32_t j=0;j<count;++j){auto idx=m.r8(a+j)|(m.r8(b+j)<<8);m.w8(out+j,m.r8(0xa29424u+idx));}s=saved;}

const std::array<Entry,24> c_entries{{
 {0x36abc2,f36abc2},{0x36adc0,f36adc0},{0x36b280,f36b280},{0x36bea0,f36bea0},{0x36dec0,f36dec0},{0x36f190,nullptr,nullptr,f36f190},{0x370bb2,f370bb2},{0x371310,f371310},{0x372651,f372651},{0x376562,f376562},{0x378d6c,f378d6c},{0x379484,f379484},{0x3797a6,f3797a6},{0x37a837,f37a837},{0x37aa5b,f37aa5b},{0x37ad30,f37ad30},{0x37b41a,f37b41a},{0x37b880,f37b880},{0x37b8f5,f37b8f5},{0x37f60e,f37f60e},{0x37ffb8,f37ffb8},{0x382808,f382808},{0x384cb0,f384cb0},{0x384d12,f384d12}}};
const std::array<Entry,24>& entries_c(){return c_entries;}
}
