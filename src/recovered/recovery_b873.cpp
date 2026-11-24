#include "recovered/recovery_b873.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::recovery_b873 {
namespace {using U=std::uint32_t;using Memory=global_b26::Memory;using Heap=platform::ordinary_heap::Heap;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string z(const Memory&m,U p){need(p,"873 nonnullstring");std::string s;for(U k=0;k<128;++k){auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("873 boundedstring");}
void put(Memory&m,U p,const std::string&s){for(U k=0;k<s.size();++k)m.w8(p+k,U(static_cast<unsigned char>(s[k])));m.w8(p+U(s.size()),0);}
void child(Memory&m,const SerializerCase&c,Heap&h){const U o=c.object,section=o+0x24;need(m.r32(o+0x9c)==6,"873 allsixpositiveslots");need(!probe_section(m,h,c.ini_root,section),"873 childclearabsent");write_absent(m,h,c.ini_root,section,0x7b9234,o+0x64);if(m.r8(o+0x3d))write_absent(m,h,c.ini_root,section,0x7b922c,o+0x3d);
 for(U k=0;k<6;++k){auto pair=o+0xa4+8*k;auto count=global_b26::s32(m.r32(pair));auto type=m.r32(pair+4);need(count>=1&&count<=9&&type,"873 positivepair");auto value=std::to_string(count)+","+z(m,type+0x24);put(m,0x83dc90,value);put(m,c.key_scratch,std::to_string(k));write_absent(m,h,c.ini_root,section,c.key_scratch,0x83dc90);}
 put(m,c.value_scratch,std::to_string(global_b26::s32(m.r32(o+0x98))));write_absent(m,h,c.ini_root,section,0x7e063c,c.value_scratch);
}
}
std::uint32_t fun_006ac360(Memory&m,const global_b26::Inputs&i,const SerializerCase&c,Heap&h){
 need(i.cx==c.ini_root,"873 outerINIreceiver");auto count=m.r32(0xa284f0);need(count>=1&&count<=4&&m.r32(0xa284e4),"873 boundedregistry");need(z(m,0x7e0630)=="TaskForces"&&!probe_section(m,h,i.cx,0x7e0630),"873 originalcountmiss");need(!probe_section(m,h,i.cx,0x7e0630),"873 originalclearabsent");unsigned matched=0;
 for(U k=0;k<m.r32(0xa284f0);++k){auto object=m.r32(m.r32(0xa284e4)+4*k);need(object,"873 nonnullregistrymember");if(m.r32(object+0xa0)!=i.dx)continue;need(matched++==0&&object==c.object&&m.r32(object)==0x797748&&m.r32(0x7977b0)==0x6ac520,"873 oneauthenticvirtualmember");put(m,c.key_scratch,"0");write_absent(m,h,i.cx,0x7e0630,c.key_scratch,object+0x24);child(m,c,h);}
 need(matched==1,"873 positiveonematch");return m.r32(0xa284f0);
}
}
