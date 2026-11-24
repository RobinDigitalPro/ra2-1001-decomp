#include "recovered/recovery_b887.hpp"
#include <string>
#include <algorithm>
namespace ra2::recovered::recovery_b887 {using U=std::uint32_t;using Heap=ra2::platform::ordinary_heap::Heap;
static std::string text(Memory&m,U p){if(!p)throw std::domain_error("887 nullinput");std::string s;for(U k=0;k<16;++k){U c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("887 boundedtext");}
static U copy(Heap&h,const std::string&s){U p=h.allocate(U(s.size()+1));if(!p)throw std::domain_error("887 allocation");for(U k=0;k<s.size();++k)h.w8(p+k,U(std::uint8_t(s[k])));h.w8(p+U(s.size()),0);return p;}
static U token(Heap&h,const std::string&suffix,const std::string&part){U whole=copy(h,suffix),scratch=copy(h,part);h.release(whole);U result=copy(h,part);h.release(scratch);return result;}
U fun_005ae190(Memory&m,const Inputs&i,Heap&h){const U d=i.cx;auto name=text(m,m.r32(i.arg[0])),s=text(m,m.r32(i.arg[1]));auto cut=s.find(',');auto end=s.find(',',cut+1);if(!d||!m.r32(0x819778)||name.empty()||name.size()>6||cut<1||cut>4||end!=s.size()-1||end<=cut+1)throw std::domain_error("887 positiveinput grammar");U value=0;for(U k=U(cut+1);k<end;++k){if(s[k]<'0'||s[k]>'9')throw std::domain_error("887 numeric token");value=value*10+U(s[k]-'0');}if(value<1||value>150)throw std::domain_error("887 percentage domain");U empty=copy(h,"");m.w32(d,empty);m.w8(d+4,0);m.w32(d+8,0);m.w32(d+12,255);U first=token(h,s,s.substr(0,cut));U second=token(h,s.substr(cut+1),s.substr(cut+1,end-cut-1));m.w32(d+12,std::min(value,100u)*255/100);h.release(empty);U owned=copy(h,name);m.w32(d,owned);h.release(second);h.release(first);return d;}
}
