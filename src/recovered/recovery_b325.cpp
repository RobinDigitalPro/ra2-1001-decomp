#include "recovery_b325.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b325 {
static void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
static unsigned widen(unsigned ch){Counter::enter();Counter::leave();return ch;}
unsigned fun_0075ca70(Memory&m,const Inputs&i,Heap&h,Counter&counter){
 need(i.cx&&i.arg[0]==3&&i.dx<=999,"325 finite width3 and nonnegative three-digit range");
 constexpr unsigned fmt[]={'%','%','0','%','d','d',0};
 for(unsigned k=0;k<7;++k)need(m.r16(0x7e9614+2*k)==fmt[k],"325 pinned format");
 need(m.r32(0xb10e20)==0&&m.r32(0xb10e24)==0&&m.r32(0xb10530)==0&&m.r32(0x81776c)==1,"325 initialized C locale");
 const unsigned digits=i.dx>=100?3:i.dx>=10?2:1;
 counter.begin(1+digits);
 // First formatter emits %0, one converted width digit, d. The second
 // formatter emits leading zero padding directly through3764eb; only
 // actual decimal digits pass through37dc05 and its atomic pair.
 unsigned short format[5]={'%','0',static_cast<unsigned short>(widen('3')),'d',0};
 need(format[2]=='3',"325 intermediate width");
 unsigned short out[4]={static_cast<unsigned short>('0'+i.dx/100),static_cast<unsigned short>('0'+i.dx/10%10),static_cast<unsigned short>('0'+i.dx%10),0};
 for(unsigned k=3-digits;k<3;++k)out[k]=static_cast<unsigned short>(widen(out[k]));
 counter.finish();
 m.w32(i.cx,0);const auto p=h.allocate(8);need(p!=0,"325 allocation success");m.w32(i.cx,p);
 for(unsigned k=0;k<4;++k){h.w8(p+2*k,out[k]&255);h.w8(p+2*k+1,out[k]>>8);}
 return i.cx;
}
}
