#include "recovered/recovery_b1463.hpp"
#include "recovered/recovery_b253.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/index_b74.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1463 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
std::int32_t classify(std::uint8_t b,U mask,void*context){auto&m=*static_cast<Memory*>(context);need(m.r32(0x81776c)<=1,"1463 original initial singlebytectype route");return std::int32_t(m.r8(m.r32(0x817560)+2u*b)&mask);}
}
U produce_record(Memory&m,const Inputs&i){need(i.cx==0xb0ee70&&m.r32(i.cx)==0&&m.r32(i.cx+4)==10&&m.r32(i.cx+8)&&i.arg[1]==0,"1463 actual sparecapacity10 firstrecord producer");return global_b26::fun_00752d70(m,i);}
U fun_00743f10(Memory&m,const Inputs&i,U entry){
 need(m.r32(0xa255c8)==0&&m.r32(0xa255d4)==0&&(i.dx&255)==0,"1463 explicit receivedquery mode0/no notification");
 std::array<std::uint8_t,128>local;U length=0;for(;;){need(length<local.size(),"1463 original producedlocal boundedinput");const auto b=std::uint8_t(m.r8(i.cx+0xe0+length));local[length++]=b;if(!b)break;}
 const U begin=entry-0x84;leaf::Memory private_span(local.data(),begin,length);Memory joined=m;joined.add(private_span);global_b26::Inputs child{};child.arg[0]=begin;child.arg[1]=0x7b9950;
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
  std::array<U,3>values{};const DecimalOperations ops{&classify,&joined};
  for(U k=0;k<3;++k){child.arg[0]=k?0:begin;child.arg[1]=0x7b9950;const U token=recovery_b253::fun_0076e802(joined,child);need(token>=begin&&token<begin+length,"1463 genuine nonempty producedtoken");values[k]=ra2::recovered::fun_0076e6b2(local.data()+token-begin,ops);}
  const U version=m.r32(0x7c39a0); // Actual72C6B0 consists solely of this MOV andRET.
  need(values[0]==version,"1463 compatible originalversion");const U hash=m.r32(0xb100e4)^m.r32(0xb100e8)^m.r32(0xb100e0);need(values[1]==hash,"1463 matching fullsigned32XOR bits");const U sum=m.r32(i.cx+0xc)+values[2];need(sum<m.r32(i.cx+8),"1463 useful spareplace query");
  const U result=(sum&0xffffff00u)|1;i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
