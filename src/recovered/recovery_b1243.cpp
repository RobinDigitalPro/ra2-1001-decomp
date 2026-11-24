#include "recovery_b1243.hpp"
#include <stdexcept>
namespace ra2::recovered::b1243 {namespace {
void need(bool x){if(!x)throw std::domain_error("1243 positive original wide decimal scanner");}
struct Scanner{
 Memory&m;unsigned file;Observation&o;
 unsigned get(){const unsigned count=m.r32(file+4u);need(count>=2u&&count<1024u&&m.r32(file+12u)==0x49u);m.w32(file+4u,count-2u);const unsigned p=m.r32(file),ch=m.r16(p);need(ch<128u&&ch!=0u);m.w32(file,p+2u);++o.reads;return ch;}
 void unget(unsigned ch){need(ch<128u&&m.r32(file)!=m.r32(file+8u));m.w32(file+4u,m.r32(file+4u)+2u);m.w32(file,m.r32(file)-2u);m.w32(file+12u,(m.r32(file+12u)&~0x10u)|1u);m.w16(m.r32(file),ch);++o.ungets;}
 bool space(unsigned ch){return(m.r16(m.r32(0x817564u)+2u*ch)&8u)!=0u;}
 bool digit(unsigned ch){return(m.r16(m.r32(0x817560u)+2u*ch)&4u)!=0u;}
 unsigned decimal(){unsigned ch=get();while(space(ch)){++o.whitespace;ch=get();}bool neg=false;if(ch=='-'||ch=='+'){neg=ch=='-';ch=get();}unsigned n=0,nd=0;while(digit(ch)){need(++nd<=7u);n=n*10u+ch-'0';ch=get();}need(nd&&n<=999999u);unget(ch);return neg?0u-n:n;}
};
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 need(root==0x37762du&&m.r32(0x81776cu)==1u&&m.r32(0x817560u)==0x81756au&&m.r32(0x817564u)==0x81756au);
 const unsigned file=i.arg[0],format=i.arg[1];const char expected[]="V=%d,%d";for(unsigned k=0;k<sizeof(expected);++k)need(m.r16(format+2u*k)==unsigned(expected[k]));
 need(m.r32(file)==m.r32(file+8u)&&m.r32(file+12u)==0x49u);Scanner s{m,file,o};
 // The initial 777640 private-14 read is dead on this positive route:
 // first literal input read 77809A -> 77809F defines EBX before every use.
 need(s.get()=='V');need(s.get()=='=');
 i.arg[1]=format+6u;const unsigned a=m.r32(i.arg[2]);i.arg[2]+=4u;const unsigned av=s.decimal();m.w32(a,av);++o.assignments;
 need(s.get()==',');i.arg[1]=format+12u;const unsigned b=m.r32(i.arg[2]);i.arg[2]+=4u;const unsigned bv=s.decimal();m.w32(b,bv);++o.assignments;
 need(m.r16(m.r32(file))=='|'&&o.assignments==2u);return 2u;
}
}
