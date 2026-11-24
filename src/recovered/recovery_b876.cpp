#include "recovered/recovery_b876.hpp"
#include <string>
namespace ra2::recovered::recovery_b876 {using U=std::uint32_t;
U fun_0065a300(global_b26::Memory&m,const global_b26::Inputs&i,const Eb750Case&c,platform::ordinary_heap::Heap&h){if(i.cx!=c.object||i.arg[0]!=c.ini_root)throw std::domain_error("876 originalreceiver/INIargument");U section=m.r32(0x7940c0);if(section!=0x7cdeb4||probe_section(m,h,c.ini_root,section))throw std::domain_error("876 absent Waypoints");U writes=0,result=0;auto put=[&](U p,const std::string&s){for(U k=0;k<s.size();++k)m.w8(p+k,std::uint8_t(s[k]));m.w8(p+U(s.size()),0);};
 for(U k=0;k<101;++k){U p=i.cx+0x632+4*k,x=m.r16(p),y=m.r16(p+2);if(x==m.r16(0xa9e990)&&y==m.r16(0xa9e992))continue;if(writes++)throw std::domain_error("876 one selectedpositive waypoint");put(c.key_scratch,std::to_string(k));auto value=global_b26::s32(global_b26::sx16(x))+1000*global_b26::s32(global_b26::sx16(y));put(c.value_scratch,std::to_string(value));result=write_absent(m,h,c.ini_root,section,c.key_scratch,c.value_scratch);}
 if(writes!=1)throw std::domain_error("876 positive route");return result;}
}
