#include "recovered/recovery_b1464.hpp"
#include <stdexcept>
namespace ra2::recovered::b1464 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
std::uint32_t fun_0077081c(Memory&m,const Inputs&i,platform::cleanup1464::Provider&api){
 need(i.arg[0]==0&&i.arg[1]==1&&i.arg[2]==1&&m.r32(0xb10494)==0,"1464 finite nonterminating quick cleanup");
 need(m.r32(0x8172ac)==api.lock()&&m.r32(0x7b782c)==0&&m.r32(0x7b7830)==0x77e415,"1464 actual warm lock and termination table");
 namespace fp=platform::x87;const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{api.enter(m.r32(0x8172ac));m.w32(0xb10490,1);m.w8(0xb1048c,std::uint8_t(i.arg[2]));
  for(std::uint32_t p=0x7b782c;p<0x7b7834;p+=4){const auto callback=m.r32(p);if(callback){need(callback==0x77e415,"1464 reached actual restore callback");api.restore(m.r32(0xb107d4));}}
  const auto result=api.leave(m.r32(0x8172ac));i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
