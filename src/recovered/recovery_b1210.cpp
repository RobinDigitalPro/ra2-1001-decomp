#include "recovered/recovery_b1210.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::b1210{
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}using U=unsigned;
std::u16string wide(Memory&m,U p,U limit){std::u16string s;for(U k=0;k<=limit;++k){const auto c=m.r16(p+2*k);if(!c)return s;s+=char16_t(c);}throw std::domain_error("1210 unterminated bounded wide string");}
std::string narrow(Memory&m,U p){std::string s;for(U k=0;k<32;++k){auto c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1210 label bound");}
U lookup(Memory&m,const char*key){const auto n=m.r32(0xab7eb8u),a=m.r32(0xab7ec0u);need(n==1&&a,"1210 positive one-label original CSF catalog");need(narrow(m,a)==key&&m.r32(a+32)==1&&m.r32(a+36)==0,"1210 exact sorted original positive catalog label/index");return m.r32(m.r32(0xab7ec4u));}
void put(Memory&m,U p,const std::u16string&s){for(U k=0;k<s.size();++k)m.w16(p+2*k,s[k]);m.w16(p+2*U(s.size()),0);}
void digit(Memory&m){using Atomic=long(__attribute__((stdcall))*)(volatile long*);need(m.r32(0xb10e20u)==0&&m.r32(0xb10530u)==0&&m.r32(0xb10e24u)==0,"1210 actual cold C locale atomic-only route");const auto p=reinterpret_cast<volatile long*>(std::uintptr_t(0xb10e24u));const auto inc=reinterpret_cast<Atomic>(std::uintptr_t(m.r32(0x7851bcu))),dec=reinterpret_cast<Atomic>(std::uintptr_t(m.r32(0x7851c0u)));need(inc&&dec&&inc(p)==1&&dec(p)==0,"1210 actual unchanged atomic exports/results");}
std::u16string number(Memory&m,U v){need(v<=40000u,"1210 positive bounded original signed decimal");std::u16string s;do{s.insert(s.begin(),char16_t('0'+v%10u));v/=10u;}while(v);for(auto c:s){(void)c;digit(m);}return s;}
}
unsigned run(unsigned r,Memory&m,const Inputs&i,State&fp){need(r==0x2eb670u,"1210 exact formatter root");const U h=m.r32(0xaa8dc0u);need(h&&m.r32(h)==0x78579cu,"1210 actual snapshot constructor");if(!m.r32(h+16)||!i.dx){put(m,i.cx,wide(m,lookup(m,"MSG:NavEmpty"),32));return i.cx;}
 auto label=wide(m,i.dx,6);need(!label.empty(),"1210 bounded public nonempty label");for(auto&c:label)if(c>=u'a'&&c<=u'z')c-=32;const U n=m.r32(0xa288b0u);std::u16string output;
 if(!n){need(wide(m,lookup(m,"MSG:NoUnitsSel"),32)==u"NONE %s","1210 finite genuine CSF format");output=u"NONE "+label;}
 else{need(n<=4&&m.r32(h+16)==n,"1210 coherent populated snapshot/selection");U total=0;for(U j=0;j<n;++j){const U actor=m.r32(m.r32(0xa288a4u)+4*j);need(actor&&m.r32(actor)==0x78e540u&&(m.r8(actor+20)&1),"1210 actual active Infantry");const U type=m.r32(actor+0x5a8u),house=m.r32(actor+0x1b4u);need(m.r32(type)==0x78ea78u&&house&&m.r32(m.r32(house+0x34u)+0x114u)==0x3f800000u,"1210 actual InfType16 and original HouseType multiplier1");const U cost=m.r32(type+0x550u);need(cost>=1&&cost<=9999,"1210 genuine INI Cost input range");fp.load32(0x3f800000u);const auto factor=fp.pop32();fp.load_integer32(cost);fp.multiply32(factor);fp.load_control_masked(0xe7fu);total+=U(fp.pop_integer64());}
 need(wide(m,lookup(m,"MSG:UnitsWorth"),32)==u"%d %s %d","1210 exact bounded genuine integer/wide format");output=number(m,n)+u" "+label+u" "+number(m,total);}
 put(m,i.cx,output);return U(output.size());}
}
