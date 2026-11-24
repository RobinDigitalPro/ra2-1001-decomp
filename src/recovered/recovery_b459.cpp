#include "recovered/recovery_b459.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b459 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U type_index(Memory&m,U cell){
 const U resource=m.r32(cell+0x44),array=m.r32(0xa1e11c);
 need(resource==0&&m.r8(m.r32(array)+0x279)!=0&&m.r32(0xaa8648)==1,"459 first live resource/type row");
 const U type=m.r32(m.r32(0xaa863c)),base=m.r32(type+0xe0);
 need(m.r32(base+0x264)==0&&m.r32(type+0xe8)>0&&m.r32(type+0x98)==0,"459 first original type range");
 return 0;
}
U next_cell(Memory&m){
 constexpr U manager=0x81a820;
 const U remaining=m.r32(manager+0x110),at=m.r32(manager+0x114);
 need(remaining>0,"459 bounded active iterator branch");
 m.w32(manager+0x108,m.r32(manager+0x108)+1);
 m.w32(manager+0x10c,m.r32(manager+0x10c)-1);
 m.w32(manager+0x110,remaining-1);m.w32(manager+0x114,at-2044);
 return m.r32(at);
}
U build(Memory&m,const Inputs&i,U off,bool grow){
 const U receiver=i.cx,queue=m.r32(receiver+off+4),array=m.r32(queue+8);
 const U mask=m.r32(receiver+off+8),records=m.r32(receiver+off+12),count=m.r32(queue);
 need(count<=3&&m.r32(queue+4)>=2&&m.r32(0x81a910)==3,"459 finite initialized queue and map width");
 m.w32(receiver+off,0);
 for(U k=0;k<=count;++k)m.w32(array+4*k,0);
 m.w32(queue,0);
 const U bytes=(m.r32(0x81a914)+4)*6;
 need(bytes>=36&&bytes<=60,"459 bounded map mask");
 for(U k=0;k<bytes;++k)m.w8(mask+k,0);
 constexpr U manager=0x81a820;
 m.w32(manager+0x108,1);m.w32(manager+0x10c,3);m.w32(manager+0x110,2);
 m.w32(manager+0x114,m.r32(manager+0x138)+6148);
 const U cell=next_cell(m);
 need(cell&&type_index(m,cell)==m.r32(receiver+0x98),"459 one eligible actual cell");
 const U config=m.r32(0xa255c0),type=m.r32(m.r32(0xaa863c));
 need(m.r8(cell+0x11c)==0&&type_index(m,cell)==0,"459 actual eligibility type lookup");
 if(grow){
  need(m.r8(config+0x222a)!=0&&m.r8(cell+0x11e)<m.r32(type+0xe4)-1,"459 positive growth eligibility");
 }else{
  need((m.r8(config)&0x80)&&m.r8(cell+0x11e)>0&&m.r32(cell+0xe4)==0,"459 positive spread eligibility");
 }
 i.fp.load64(read64(m,type+(grow?0xb0:0xa0)));
 i.fp.compare_pop64(read64(m,0x787520));
 need((i.fp.status()&0x100)==0,"459 nonnegative eligibility rate");
 need(m.r32(cell+0x24)==0x00030001,"459 first flattened cell");
 m.w32(records,m.r32(cell+0x24));m.w32(records+4,0);m.w32(receiver+off,1);
 m.w32(array+4,records);m.w32(queue,1);
 if(records>m.r32(queue+12))m.w32(queue+12,records);
 if(records<m.r32(queue+16))m.w32(queue+16,records);
 m.w8(mask,1);
 const U result=next_cell(m);need(result==0,"459 explicit next-slot null ends iteration");
 return result;
}
}
U fun_006dee50(Memory&m,const Inputs&i){return build(m,i,0xf0,false);}
U fun_006df940(Memory&m,const Inputs&i){return build(m,i,0x10c,true);}
}
