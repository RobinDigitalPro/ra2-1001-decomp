#include "recovery_b349.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b349 {
unsigned fun_00698660(Memory&m,const Inputs&i){
 if(m.r32(0xaa60c8)!=0||m.r32(0xaa60c0)!=1||!m.r32(0xaa60bc))throw std::domain_error("349 one available slot in empty initialized rectangle array");
 if(i.arg[2]==0||i.arg[2]>1024||i.arg[3]==0||i.arg[3]>1024)throw std::domain_error("349 positive bounded rectangle extent");
 const auto target=m.r32(0xaa60bc);m.w32(0xaa60c8,1);
 for(unsigned k=0;k<4;++k)m.w32(target+4*k,i.arg[k]);
 // Original MOV AL and MOV byte [ESP+64],AL initialize only the flag.
 // MOVSD.REP copies the adjacent three pre-existing private stack bytes too.
 m.w32(target+16,(i.stack_minus8&0xffffff00)|(i.arg[4]&255));
 return 0; // LEA EAX,[old_count*5] with old_count0; full EAX survives copy.
}
}
