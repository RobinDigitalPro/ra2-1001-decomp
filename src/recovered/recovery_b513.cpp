#include "recovery_b513.hpp"
// Private reuse of reviewed bounded helpers; historical sources stay unchanged.
#include "recovery_b331.cpp"
#include "recovery_b504.cpp"
namespace ra2::recovered::recovery_b513 {
unsigned fun_0049ab70(Memory&m,const Inputs&i){
 if(i.arg[2]!=1||i.arg[3]!=0xffffffff||i.arg[4]!=0)
  throw std::domain_error("513 bounded movement selector/height/flags");
 const auto table=m.r32(i.cx+0x138);
 auto cell=[&](unsigned xy){
  const unsigned x=m.r16(xy),y=m.r16(xy+2);
  if(x<1||x>31||y<1||y>31)throw std::domain_error("513 bounded valid map coordinates");
  const auto c=m.r32(table+4*(512*y+x));
  if(!c)throw std::domain_error("513 requires supplied nonnull map cell");return c;
 };
 const auto first=cell(i.arg[0]),second=cell(i.arg[1]);
 for(const auto c:{first,second}){
  Inputs t=i;t.cx=c;t.arg[0]=1;t.arg[1]=1;t.arg[2]=1;t.arg[3]=0xffffffff;t.arg[4]=0;t.arg[5]=0xffffffff;t.arg[6]=1;
  const auto r=recovery_b331::fun_00478360(m,t);i.fp=t.fp;
  if(!(r&255))return r;
 }
 std::array<std::uint8_t,8>query{};
 leaf::Memory local(query.data(),0x7d510000,query.size());Memory view=m;view.add(local);
 for(const auto c:{first,second}){
  Inputs t=i;t.cx=c;t.arg[0]=local.base();t.arg[1]=0;t.arg[2]=0;
  const auto r=recovery_b504::fun_00471260(view,t);i.fp=t.fp;
  if(r)return r&0xffffff00;
 }
 return 1;
}
}
