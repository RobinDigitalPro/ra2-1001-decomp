#include "recovered/recovery_b1584.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1584 {
namespace {using U=std::uint32_t;void need(bool ok){if(!ok)throw std::domain_error("B1584 finite plus-command cache invalidation projection");}
void invalidate_owner(Memory&m,U owner){need(owner!=0);m.w32(owner+0xb4,0xffffffffu);const U count=m.r32(owner+0x30),array=m.r32(owner+0x24);need(count>=1&&count<=3&&array!=0);for(U k=0;k<count;++k){const U candidate=m.r32(array+4*k);need(candidate!=0);m.w32(candidate+0x74,0xffffffffu);}m.w32(owner+0xac,0xffffffffu);}
void invalidate_header(Memory&m,U h){const U count=m.r32(h+0x14),array=m.r32(h+8);need(count>=2&&count<=4&&array!=0&&m.r32(h+0x8c)==0xffffffffu&&m.r8(h+0x98)==1);const U selected=m.r32(h+0x94);need(selected<count);const U owner=m.r32(array+4*selected);need(owner!=0);invalidate_owner(m,owner);m.w8(h+0x98,0); // Actual B660 selected-owner pass, followed by full pass from zero when 8C=-1.
for(U k=0;k<count;++k){const U item=m.r32(array+4*k);need(item!=0);invalidate_owner(m,item);}m.w32(h+0x8c,0xffffffffu);}
}
std::uint32_t run(Memory&m,const Inputs&i){need(m.r8(i.cx)==0x2b);const U id=global_b26::sx8(m.r8(i.cx+2)),count=m.r32(0xa28870),array=m.r32(0xa28864);need(id<=7&&count>=2&&count<=4&&array!=0&&m.r32(0xa255c8)==0);for(U j=0;j<count;++j){const U entity=m.r32(array+4*j);need(entity!=0&&m.r32(entity)==0x787bbcu);const U house=m.r32(entity+0x1b4);need(house!=0&&m.r8(house+0x134)==0&&m.r8(house+0x135)==0);const U actual_house_id=m.r32(house+0x30);need(actual_house_id==id);const U h=m.r32(entity+0x408);need(h!=0);const U header_count=m.r32(h+0x14),cache=m.r32(h+0x8c);need(header_count>0&&cache==0xffffffffu);const U was_valid=1;invalidate_header(m,h);const U actual_building_query=m.r32(entity+0x98);need(actual_building_query==5); // Actual 591570 selected getter; no self228 read. D5F0 AL=1, BL=1 skips CF40.
(void)was_valid;}return count;}
}
