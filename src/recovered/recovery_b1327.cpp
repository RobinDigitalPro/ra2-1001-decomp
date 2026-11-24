#include "recovery_b1327.hpp"
#include "recovered/map_b106.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1327 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
U cell_at(Memory&m,U point){
 // Actual545490 signed division256 toward zero, count bound and real cell.
 const auto x=std::int32_t(m.r32(point))/256,y=std::int32_t(m.r32(point+4u))/256;
 const auto index=std::int64_t(y)*512+x;
 need(x==3&&y==2&&index>=0&&index<std::int32_t(m.r32(0x81a95cu)),"1327 occupied finite coordinate lookup");
 const U cell=m.r32(m.r32(0x81a958u)+4u*U(index));need(cell,"1327 real populated cell");return cell;
}
U height(Memory&memory,U point,const Inputs&i){
 const U cell=cell_at(memory,point);
 need(memory.r32(point)==896u&&memory.r32(point+4u)==640u&&memory.r32(point+8u)==0u,"1327 bounded supplied world coordinate");
 need(memory.r8(cell+0x11bu)==0u&&memory.r8(cell+0x11cu)==0u&&(memory.r8(0x838f70u)&7u)==7u,"1327 warm flat terrain");
 // Original557070 creates exactly an8-byte XY scratch, not a third Z word.
 std::array<std::uint8_t,8> bytes{};constexpr U scratch=0x7a400000u;
 leaf::Memory local(bytes.data(),scratch,8u);Memory m=memory;m.add(local);
 local.w32(scratch,m.r32(point));local.w32(scratch+4u,m.r32(point+4u));
 Inputs h{};h.cx=cell;h.arg[0]=scratch;h.fp=i.fp;
 const U z=map_b106::fun_004702c0(m,h);i.fp=h.fp;return z;
}
U actor_flag(Memory&m,U point,const Inputs&i,bool set){
 // Actual5CCFF0/5CD070 both invoke557070 before deciding128 versus124.
 const U z=height(m,point,i),offset=m.r32(0xa5aa98u);
 need(offset==0u&&z==0u&&std::int32_t(z+offset)<=std::int32_t(m.r32(point+8u)),"1327 actual upper flag arm");
 const U first=cell_at(m,point);need((m.r32(first+0x140u)&0x100u)!=0u,"1327 real cell140 bit100");
 const U second=cell_at(m,point),address=second+0x128u,flags=m.r32(address);
 m.w32(address,set?flags|0x40u:flags&0xffffffbfu);return address;
}
U run(Memory&m,const Inputs&i,U cache){
 const U point=i.arg[0],selector=i.arg[1],self=i.cx;
 need(m.r32(point)!=m.r32(cache),"1327 supplied coordinate differs at first cache DWORD");
 need(m.r8(self+0x60u)==1u,"1327 bypass motion table via real self60");
 need(selector==0u||selector==1u||selector==3u,"1327 useful flag selectors0/1/3");
 const U actor=m.r32(self+0xcu);need(actor&&m.r32(actor)==0x78612cu,"1327 constructor-proven actor provider");
 const U slot=selector==0u?0xecu:0xe8u,target=selector==0u?0x5cd070u:0x5ccff0u;
 need(m.r32(0x78612cu+slot)==target,"1327 exact original actor vtable bytes");
 return actor_flag(m,point,i,selector!=0u);
}
}
U fun_004a08e0(Memory&m,const Inputs&i){return run(m,i,0x83acc8u);}
U fun_0066c4a0(Memory&m,const Inputs&i){return run(m,i,0xaa0cc8u);}
}
