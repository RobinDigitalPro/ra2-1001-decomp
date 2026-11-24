#include "misc_b90.hpp"
#include "leaf_b15_b.hpp"
#include "leaf_b57_c.hpp"
#include <array>
#include <algorithm>
namespace ra2::recovered::misc_b90 {
namespace {
// Copy only the fields read by the unchanged accepted predicates. Native tests
// execute the original helper instructions at both original call sites.
bool index_allied(Memory&m,std::uint32_t receiver,std::uint32_t index){
 std::array<std::uint8_t,0x5800> bytes{};leaf::Memory local(bytes.data(),0x1000,bytes.size());
 local.w32(0x1030,m.r32(receiver+0x30));local.w32(0x6674,m.r32(receiver+0x5674));leaf::Inputs in{};in.cx=0x1000;in.arg[0]=index;return (leaf::fun_004e4ba0(local,in)&255)!=0;
}
bool object_allied(Memory&m,std::uint32_t receiver,std::uint32_t other){
 std::array<std::uint8_t,0xb000> bytes{};leaf::Memory local(bytes.data(),0x1000,bytes.size());
 local.w32(0x1030,m.r32(receiver+0x30));local.w32(0x6674,m.r32(receiver+0x5674));local.w32(0x6830,m.r32(other+0x30));leaf::Inputs in{};in.cx=0x1000;in.arg[0]=receiver==other?0x1000:0x6800;return (leaf::fun_004e4be0(local,in)&255)!=0;
}
std::uint32_t raster(Memory&m,std::uint32_t buffer,std::uint32_t&cursor,std::uint32_t x,std::uint32_t y,std::uint32_t xx,std::uint32_t yy,unsigned side,unsigned skip){
 std::array<std::uint8_t,0x300> bytes{};leaf::Memory local(bytes.data(),0x1000,bytes.size());
 for(unsigned k=0;k<256;++k)local.w8(0x1100+k,m.r8(buffer+k));local.w32(0x1000,0x1100+cursor);
 leaf::Inputs in{};in.cx=x;in.dx=y;in.arg[0]=xx;in.arg[1]=yy;in.arg[2]=side;in.arg[3]=skip;in.arg[4]=0x1000;
 const auto value=leaf::fun_00613c80(local,in);cursor=local.r32(0x1000)-0x1100;
 for(unsigned k=0;k<256;++k)m.w8(buffer+k,local.r8(0x1100+k));return value;
}
}
std::uint32_t fun_0042eee0(Memory&m,const Inputs&i){
 if(!m.r32(i.cx+0x60))return 0;bool any=false;const auto player=m.r32(0xa1e0e4),table=m.r32(0xa1a5cc);
 for(unsigned g=0;g<8;++g)for(unsigned j=0;j<3;++j){const auto p=m.r32(i.cx+g*12+j*4);if(!p||!(m.r8(p+12)&1))continue;const auto id=m.r32(p+0x110);if(index_allied(m,player,id)&&object_allied(m,m.r32(table+id*4),player)){any=true;break;}}
 if(!any)return 0;const auto remainder=s32(m.r32(0xa2896c))%s32(m.r32(i.cx+0x7c));return remainder<s32(m.r32(0x836c90)+1);
}
std::uint32_t fun_0049c420(Memory&m,const Inputs&){
 std::int32_t x=0,y=0,count=0;const auto n=m.r32(0xa28870),array=m.r32(0xa28864);
 for(unsigned k=0;k<n;++k){const auto p=m.r32(array+k*4);if(!m.r8(p+0x76)&&m.r8(p+0x372)){x+=s32(m.r32(p+0x88));y+=s32(m.r32(p+0x8c));++count;}}
 if(count){x/=count;y/=count;}const auto packed=std::uint32_t(std::uint16_t(x/256))|(std::uint32_t(std::uint16_t(y/256))<<16),r=m.r32(0xa255c0);
 for(unsigned offset=0x2214;offset<=0x2220;offset+=4)m.w32(r+offset,packed);m.w32(r+0x210,m.r32(r+0x20c));return r;
}
std::uint32_t fun_00613a20(Memory&m,const Inputs&i){
 const auto vertices=m.r32(i.cx+4),n=m.r32(i.cx),out=i.dx,buffer=m.r32(out+8);
 if(n!=4||!buffer)throw std::domain_error("Block90 supplied rectangle route required");
 auto x=[&](unsigned k){return m.r32(vertices+k*8);};auto y=[&](unsigned k){return m.r32(vertices+k*8+4);};
 unsigned min_index=0,max_index=0;for(unsigned k=1;k<n;++k){if(s32(y(k))<s32(y(min_index)))min_index=k;else if(s32(y(k))>s32(y(max_index)))max_index=k;}
 const auto low=y(min_index),high=y(max_index);unsigned forward=min_index;while(y(forward)==low)forward=(forward+1)%n;forward=(forward+n-1)%n;
 unsigned backward=min_index;while(y(backward)==low)backward=(backward+n-1)%n;backward=(backward+1)%n;
 // Distinct top corners select the nondegenerate rectangular path at 613ade.
 if(x(backward)==x(forward))throw std::domain_error("Block90 nondegenerate top edge required");
 int direction=-1;if(s32(x(backward))>s32(x(forward))){std::swap(backward,forward);direction=1;}
 m.w32(out,high-low);m.w32(out+4,low);std::uint32_t result=0,cursor=0;unsigned at=backward;
 do{const auto next=(at+n+direction)%n;result=raster(m,buffer,cursor,x(at),y(at),x(next),y(next),1,0);at=next;}while(at!=max_index);
 cursor=0;at=forward;direction=-direction;
 do{const auto next=(at+n+direction)%n;result=raster(m,buffer,cursor,x(at)-1,y(at),x(next)-1,y(next),0,0);at=next;}while(at!=max_index);
 return result;
}
}
