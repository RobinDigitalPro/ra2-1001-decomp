#include "recovery_b448.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b448 {
namespace {
unsigned last(Memory&m,unsigned group){
 auto count=m.r32(group+0x14);
 if(count<1||count>4)throw std::domain_error("448 positive outer record bounds");
 return m.r32(m.r32(group+8)+4*(count-1));
}
bool lists(Memory&m,unsigned a,unsigned b){
 auto ra=last(m,a),rb=last(m,b),na=m.r32(ra+0x10),nb=m.r32(rb+0x10);
 if(na<1||na>4||nb<1||nb>4)throw std::domain_error("448 positive nested record bounds");
 auto ta=m.r32(a),tb=m.r32(b);bool found=false;
 for(unsigned j=0;j<na;++j)if(m.r32(m.r32(m.r32(ra+4)+4*j))==tb){found=true;break;}
 if(!found)return false;
 for(unsigned j=0;j<nb;++j)if(m.r32(m.r32(m.r32(rb+4)+4*j))==ta)return true;
 return false;
}
}
unsigned fun_0060d9c0(Memory&m,const Inputs&){
 if(!m.r8(0xa5e2fc)||!m.r8(0xa5e220))throw std::domain_error("448 active selection with prior notification required");
 auto count=m.r32(0xa288b0),objects=m.r32(0xa288a4);
 if(count<2||count>4)throw std::domain_error("448 nonempty multi-object selection bound");
 auto first=m.r32(objects);
 if(!first||!(m.r8(first+0x14)&1))throw std::domain_error("448 first object must be selected");
 auto initial=m.r32(first+0x408);
 for(unsigned j=0;j<count;++j){
  auto object=m.r32(objects+4*j);
  if(!object||!(m.r8(object+0x14)&1))throw std::domain_error("448 all objects selected");
  auto other=m.r32(object+0x408);
  if(!initial||!other)throw std::domain_error("448 positive relation objects");
  if(!lists(m,initial,other))return 0;
 }
 return 1;
}
}
