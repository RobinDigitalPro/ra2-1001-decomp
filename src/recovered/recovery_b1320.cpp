#include "recovery_b1320.hpp"
#include "recovered/recovery_b110.hpp"
#include "recovered/leaf_memory.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1320 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
constexpr U kVptr=0x0078612cu,kMap=0x0081a820u,kTableGlobal=0x0084e4fcu;
constexpr U kCurrent=0x0084e230u,kRoute=0x00a255c8u,kFallback=0x00a57610u;
int16_t sx16(U x){return static_cast<int16_t>(x&0xffffu);}
U pack(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16u);}
U round_full(U fixed){const auto s=static_cast<std::int32_t>(fixed);return U((s+(s<0?255:0))>>8);}
U round_coord(U fixed){return round_full(fixed)&0xffffu;}
U current_pair(Memory&m,U self){need(m.r32(self)==kVptr&&m.r32(kVptr+0x48u)==0x005cd4d0u,"B1320 original +48 coordinate slot");const U x=round_coord(m.r32(self+0x88u)),y=round_coord(m.r32(self+0x8cu));return (x&0xffffu)|((y&0xffffu)<<16u);}
U map_cell(Memory&m,U p){const int x=sx16(p),y=sx16(p>>16u);const std::int64_t idx=std::int64_t(y)*512+x;if(idx<0||idx>=0x40000){m.w32(0x00a57634u,p);return kFallback;}const U table=m.r32(kMap+0x138u);need(table!=0,"B1320 borrowed map table");const U cell=m.r32(table+4u*U(idx));if(!cell){m.w32(0x00a57634u,p);return kFallback;}return cell;}
void require_map_accept(Memory&m,U p){const int x=sx16(p),y=sx16(p>>16u);need(x==4&&y==4,"B1320 finite initial 0x557450 point (4,4)");const std::int64_t idx=std::int64_t(y)*512+x;need(idx>=0&&idx<0x40000,"B1320 0x557450 signed grid bounds");const U table=m.r32(kMap+0x138u);need(table!=0,"B1320 0x557450 map table");const U cell=m.r32(table+4u*U(idx));need(cell!=0,"B1320 0x557450 selected nonnull map cell");const int lo=static_cast<std::int8_t>(m.r8(cell+0x11bu));const int flag=m.r8(cell+0x11cu);need(flag==0&&lo==0,"B1320 0x557450 branch bypasses cell-bound correction with signed cell fields zero");const int f0=static_cast<int>(m.r32(kMap+0xf0u)),f4=static_cast<int>(m.r32(kMap+0xf4u)),f8=static_cast<int>(m.r32(kMap+0xf8u)),fc=static_cast<int>(m.r32(kMap+0xfcu)),f100=static_cast<int>(m.r32(kMap+0x100u)),f104=static_cast<int>(m.r32(kMap+0x104u));need(f0==1&&f4==0&&f8==0&&fc==0&&f100==10&&f104==9,"B1320 exact borrowed row-limit fixture for 0x557450");const int sum=x+y,delta=x-y,reverse=y-x;need(sum>=f0+2*fc+4,"B1320 original 557450 lower diagonal arm");need(sum>f0+2*(f4+fc)+lo,"B1320 original 557450 first upper diagonal arm");need(sum<=f0+2*(f104+fc)+2+lo,"B1320 original 557450 second upper diagonal arm");need(delta<2*(f100+f8)-f0,"B1320 original 557450 x-minus-y arm");need(reverse<f0-2*f8,"B1320 original 557450 y-minus-x arm");}
U projected_pair(Memory&m,U self){const int index=static_cast<std::int8_t>(m.r8(self+0x574u));need(index>=0,"B1320 finite nonnegative +574 0x4CA2F0 branch");const U types=m.r32(kTableGlobal);need(types!=0,"B1320 explicit borrowed 0x84E4FC type table");const U record=m.r32(types+4u*U(index));need(record!=0,"B1320 borrowed selected projection record");const U fixed=m.r32(record+0x28u);const int x=sx16(fixed),y=sx16(fixed>>16u);return pack(x,y);}
// Calls accepted 0x54CC50 using caller-provided local pair addresses.
U query_map_at(Memory&m,const Inputs&i,U projected_ptr,U input_ptr,U b8result,U type){recovery_b110::Inputs q{};q.cx=kMap;q.arg[0]=projected_ptr;q.arg[1]=input_ptr;q.arg[2]=type;q.arg[3]=b8result;q.fp=i.fp;const U r=recovery_b110::fun_0054cc50(m,q);i.fp=q.fp;return r;}

U eligible(Memory&m,const Inputs&i){
 const U self=i.cx,point=i.arg[0];
 need(m.r32(self)==kVptr&&m.r32(kVptr+0x4cu)==0x4ca2f0u&&m.r32(kVptr+0xb8u)==0x4cc0b0u&&m.r32(kVptr+0x80u)==0x6b6910u&&m.r32(kVptr+0x84u)==0x41b600u&&m.r32(kVptr+0x194u)==0x418e00u,"1320 actual reached virtual identities");
 const U point_value=m.r32(point);require_map_accept(m,point_value);
 need(m.r32(kRoute)!=0u,"1320 bounded live-map route");
 const U projected=projected_pair(m,self);
 std::uint8_t bytes[8]{};leaf::Memory local(bytes,0x7d200000u,8u);Memory view=m;view.add(local);
 local.w32(0x7d200000u,projected);
 // Original +4C output is converted to a pair in callerarg0, not its pointee.
 i.arg[0]=projected;
 const U type=m.r32(self+0x5acu);need(type&&m.r32(type+0x500u)==7u,"1320 actual type7 field");
 const U query=query_map_at(view,i,0x7d200000u,point,m.r32(self)&0xffffff00u,7u);
 need((query&255u)==1u,"1320 useful equal-region query");
 const U cell=map_cell(m,point_value);
 need(cell!=kFallback&&m.r32(cell+0xecu)==5u,"1320 positive type5 cell");
 need(m.r32(self+0x4c4u)==0u&&m.r32(cell+0xe4u)==0u,"1320 actual418E00 route guards");
 // 418E00 passes literal4 to478360 (AL1), then A255C8!=0 reaches
 // XOR EAX,EAX. Root TEST preserves0 and MOV AL,1 returns full EAX1.
 return 1u;
}
void make_empty(leaf::Memory&m,U local){
 // Independently recovered original CE2F0 count0 arm, outside old B73 scope.
 m.w32(local+4u,0u);m.w32(local+8u,0u);m.w8(local+12u,1u);m.w8(local+13u,0u);
 m.w32(local,0x78c7d4u);m.w32(local,0x78c7fcu);m.w32(local+20u,10u);m.w32(local+16u,0u);
}
void clear_empty(leaf::Memory&m,U local,bool clear_count){
 need(m.r32(local+4u)==0u&&m.r8(local+13u)==0u,"1320 original-produced null local buffer");
 if(clear_count)m.w32(local+16u,0u);
 m.w8(local+13u,0u);m.w32(local+8u,0u);
}
U current(Memory&m,const Inputs&i){
 std::uint8_t bytes[24]{};leaf::Memory local(bytes,0x7d210000u,24u);
 make_empty(local,0x7d210000u);
 need(m.r32(local.r32(0x7d210000u)+12u)==0x4ce3a0u,"1320 genuine local clear slot");
 clear_empty(local,0x7d210000u,true);
 const U point=current_pair(m,i.cx),cell=map_cell(m,point);
 need(cell!=kFallback&&m.r32(cell+0xecu)==5u,"1320 actual early type5 current-cell route");
 m.w32(i.arg[0],point);
 local.w32(0x7d210000u,0x78c7d4u);clear_empty(local,0x7d210000u,false);
 return i.arg[0];
}
}
std::uint32_t run(std::uint32_t root,Memory&m,const Inputs&i){
 switch(root){case 0xcb2d0u:return eligible(m,i);case 0xcb740u:return current(m,i);default:throw std::domain_error("1320 exact two roots");}
}
}
