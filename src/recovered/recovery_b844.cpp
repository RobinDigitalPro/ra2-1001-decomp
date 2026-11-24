#include "recovered/recovery_b844.hpp"
#include <algorithm>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::recovery_b844 {
using U=std::uint32_t;
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// Same within-segment arithmetic as accepted text_b76::fun_004090e0.
U advance(Memory&m,U o,U amount){
 U left=m.r32(o+0x34)-m.r32(o+0x38)-m.r32(o+0x2c);
 need(left>0&&left<0x10000&&amount<left,"844 positive stream remainder");
 const U segment=m.r32(o+0xc),index=m.r32(o+0x14)*8+0x20;
 auto available=[&](){return (m.r8(o+0x10)&1)?left:std::min(left,m.r32(segment+index+4)-m.r32(o+4)+m.r32(segment+index));};
 need(amount<available(),"844 segment transition excluded");
 m.w32(o+4,m.r32(o+4)+amount);left-=amount;m.w32(o+8,available());
 const U total=m.r32(o+0x2c)+amount,cursor=m.r32(o+0x30)+amount,cycle=m.r32(m.r32(o)+0x14);
 need(cycle&&m.r32(o+0x18),"844 valid cycle and refill-disabled field");
 m.w32(o+0x2c,total);m.w32(o+0x30,cursor%cycle);return amount;
}
}
U fun_00468c80(Memory&m,const Inputs&i){
 const U o=i.cx,v=m.r32(o),src=m.r32(o+0x54),pos=m.r32(o+0x60),length=m.r32(o+0x58);
 need(v==0x7856a0&&m.r32(v+0x18)==0x468e00&&src&&pos<=length&&length<=256&&i.arg[1]<=256,"844 cached-file bounds");
 const U n=std::min(i.arg[1],length-pos);std::vector<std::uint8_t> bytes(n);
 for(U k=0;k<n;++k)bytes[k]=m.r8(src+pos+k);
 for(U k=0;k<n;++k)m.w8(i.arg[0]+k,bytes[k]);
 if(n)m.w32(o+0x60,pos+n);return n;
}
U fun_00408ea0(Memory&m,const Inputs&i){
 const U o=i.cx,file=i.dx,count=i.arg[1];U pending=i.arg[0];
 need(count&&pending>0&&pending<=63&&m.r32(o+0x14)==0,"844 bounded stream read");
 need(m.r32(file)==0x7856a0&&m.r32(0x7856c4)==0x468c80,"844 original cached read dispatch");
 advance(m,o,0);m.w32(count,0);
 while(pending){const U n=std::min(pending,m.r32(o+8));if(!n)break;
  Inputs call;call.cx=file;call.arg[0]=m.r32(o+4);call.arg[1]=n;
  const U got=fun_00468c80(m,call);if(!got)return 2;
  advance(m,o,got);pending-=got;m.w32(count,m.r32(count)+got);
 }return 1;
}
}
