#include "recovered/recovery_b1438.hpp"
#include <stdexcept>
namespace ra2::recovered::b1438 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// Actual 6EEDC0, with its read-only input on one of the two real heap owners.
U narrow_owner(Memory&m,Heap&h,U owner){
 const U slot=m.r32(0xab7edc);need(slot<8,"1438 valid actual string ring");const U out=0xaa8dec+(slot<<10);U k=0;
 while((h.r8(owner+2*k)|(h.r8(owner+2*k+1)<<8))!=0){need(k<5,"1438 bounded terminated actual owner name");m.w8(out+k,h.r8(owner+2*k));++k;}
 m.w8(out+k,0);m.w8(out+0x3ff,0);m.w32(0xab7edc,(slot+1)&7);return out;
}
// Actual 491B70 modulo-DWORD sum, with the compatible finite descriptor bound.
U sum(Memory&m,U descriptor){const U count=m.r32(descriptor+8);need(count>=1&&count<=2,"1438 real positive counter span");U value=0;const U data=m.r32(descriptor+4);for(U k=0;k<count;++k)value+=m.r32(data+4*k);return value;}
// Count2/DL0 or DL1 extension of the original 48DFF0 route. B96's source
// explicitly accepts only count1/DL0 and is not silently used outside that scope.
void aggregate(Memory&m,Heap&h,U out,U dl){
 const U count=m.r32(0xa1a5d8),table=m.r32(0xa1a5cc);need(count==2&&dl<=1,"1438 genuine two-record selector");U record=0;
 for(U k=0;k<count;++k){const U p=m.r32(table+4*k);if(!p)continue;if(m.r8(m.r32(p+0x34)+0x1a6)==1||m.r8(p+0x134)==0)continue;if(dl){dl=0;continue;}record=p;break;}
 need(record!=0,"1438 actual eligible record exists");h.w32(out+0x2c,0);
 U k=0;for(;;++k){need(k<=5,"1438 bounded actual UTF16 copy");const U c=m.r16(record+0x15f16+2*k);h.w8(out+2*k,c);h.w8(out+2*k+1,c>>8);if(c==0)break;}
 for(U off:{0x30u,0x40u,0x50u,0x60u})h.w32(out+off,0);
 h.w32(out+0x28,m.r32(record+0x15f40));if(m.r8(record+0x13d)==0)h.w32(out+0x2c,1);
 U total=0;for(U n=0;n<20;++n)total+=m.r32(record+0x5310+4*n);for(U n=0;n<count;++n)total+=m.r32(record+0x5364+4*n);h.w32(out+0x40,total);
 const U basic=m.r32(record+0x5360)+m.r32(record+0x53b4);h.w32(out+0x30,basic);U extra=0;for(U off:{0x5460u,0x5470u,0x5480u,0x5490u})extra+=sum(m,record+off);h.w32(out+0x50,basic+extra);
 const U tail=m.r32(record+0x5418);if(global_b26::s32(tail)>0)h.w32(out+0x60,tail);
 (void)narrow_owner(m,h,out); // Actual 4068F0 is bare RET, preserving this result.
}
}
std::uint32_t configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1438 actual CRT setter argument");m.w32(0x817554,0);return 1;}
std::uint32_t fun_0048e4f0(Memory&m,const Inputs&i,Heap&h){
 const U report=i.cx,vector=i.arg[0],output=i.arg[1];need(m.r8(report+0x6c)==1&&m.r32(vector+0x10)==0&&m.r32(vector+8)==2&&m.r32(vector+4),"1438 positive report and borrowed empty capacity2 vector");
 need(m.r32(vector)==0x7918b8&&m.r8(vector+0xc)==1&&m.r8(vector+0xd)==0&&m.r32(vector+0x14)==10,"1438 actual constructor-compatible vector");
 need(m.r32(report+0x38)==0,"1438 fresh accepted B912 report");for(U off=0x48;off<=0x68;off+=4)need(m.r32(report+off)==0,"1438 produced fresh report counters");
 U first=h.allocate(112);need(first,"1438 actual allocation1");aggregate(m,h,first,0);U second=h.allocate(112);need(second,"1438 actual allocation2");i.arg[0]=second;aggregate(m,h,second,1);
 const U narrow=narrow_owner(m,h,first);bool equal=true;for(U n=0;;++n){need(n<=5,"1438 bounded report label");const U a=m.r8(report+n),b=m.r8(narrow+n);if(a!=b){equal=false;break;}if(a==0)break;}
 if(!equal){const U old=first;first=second;second=old;i.arg[0]=second;}
 for(U k=0;k<2;++k){const U p=k?second:first;h.w32(p+0x40,m.r32(report+0x48+4*k));h.w32(p+0x50,m.r32(report+0x50+4*k));h.w32(p+0x30,m.r32(report+0x58+4*k));h.w32(p+0x2c,m.r32(report+0x38));h.w32(p+0x60,m.r32(report+0x60+4*k));const U count=m.r32(vector+0x10);need(count<m.r32(vector+8),"1438 actual spare-capacity append");m.w32(vector+0x10,count+1);m.w32(m.r32(vector+4)+4*count,p);}
 const U value=m.r32(report+0x68);m.w32(output,value);return(value&0xffffff00u)|1;
}
}
