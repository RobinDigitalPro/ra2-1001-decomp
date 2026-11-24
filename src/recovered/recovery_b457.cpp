#include "recovered/recovery_b457.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b457 {
namespace{
using U=std::uint32_t;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
U convert(Memory&m,platform::x87::State&fp){const auto cw=std::uint16_t(m.r32(0x7c3a04));if(fp.control()!=cw)fp.load_control(cw);return U(fp.pop_integer64());}
void clamp(Memory&m,platform::x87::State&fp,U p){
 fp.load32(m.r32(p));fp_extended::compare64(fp,read64(m,0x785708));
 if(!(fp.status()&0x100)){fp.pop_st0();fp.load64(read64(m,0x785708));}
 m.w32(p,fp.store32());
}
void control(Memory&m,U p,U level){need(p!=0,"457 initialized volume control");m.w32(p,m.r32(p)|1);m.w32(p+8,level<<16);}
}
std::uint32_t fun_005d1c80(Memory&m,const Inputs&i){
 auto&fp=i.fp;const U p=i.cx;
 for(U k=0;k<3;++k){const U field=p+0x2c+4*k;clamp(m,fp,field);
  if(k==1){fp.multiply64(read64(m,0x78df50));const U v=convert(m,fp);m.w32(0x7e3438,s32(v)<255?v:255);fp.load32(m.r32(field));}
  fp.multiply32(m.r32(0x79276c));const U scaled=convert(m,fp);
  const U slot=k==0?0x819798:k==1?0x819790:0x819794;control(m,m.r32(slot),scaled);
  fp.load32(m.r32(field));(void)fp.pop64(); // Actual logging argument; log helper is RET.
 }
 m.w8(0xa1e0b8,m.r8(p+0x38));m.w8(0xa1e0ba,m.r8(p+0x3a));
 // Last selected TRUE/FALSE string pointer survives the RET-only log and271200.
 const U residue=m.r8(p+0x3a)==1?0x7cca18:0x7cca14;
 m.w8(0x7e09a0,m.r8(p+0x1a));return with_al(residue,m.r8(p+0x19));
}
std::uint32_t fun_0062dea0(Memory&m,const Inputs&i){
 const U p=i.cx,object=i.arg[0];
 need(i.arg[1]==2&&m.r32(p+0x6c)!=0&&object,"457 active command2 append");
 need(m.r32(p)==0x787bbc&&m.r32(object)==0x787bbc&&m.r32(0x787bf8)==0x6bca10,"457 constructor-proven Building owner getter");
 const U owner=m.r32(p+0x1b4);need(owner&&owner==m.r32(object+0x1b4),"457 actual positive same-owner relation");
 const U old=m.r32(p+0xbc);if(old!=2){m.w32(p+0xc4,m.r32(p+0xc0));m.w32(p+0xc0,old);m.w32(p+0xbc,2);}
 const U table=m.r32(p+0xcc),count=m.r32(p+0xd0);need(table&&count>=1&&count<=6,"457 bounded queue");
 for(U k=0;k<count;++k)if(m.r32(table+4*k)==object)return 1;
 for(U k=0;k<count;++k)if(m.r32(table+4*k)==0){m.w32(table+4*k,object);return 1;}
 return 10;
}
}
