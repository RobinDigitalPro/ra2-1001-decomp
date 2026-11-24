#include "recovered/recovery_b456.hpp"
#include "recovered/floating_b39_memory.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b456 {
namespace {
using U=std::uint32_t;using FP=platform::x87::State;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
U integer(Memory&m,FP&fp){const auto cw=std::uint16_t(m.r32(0x7c3a04));if(fp.control()!=cw)fp.load_control(cw);return U(fp.pop_integer64());}
void approximate(Memory&m,FP&fp,std::uint64_t argument){
 Memory local=m;std::array<std::uint8_t,256>bytes{};
 leaf::Memory span(bytes.data(),0x5f200000,bytes.size());local.add(span);
 constexpr U sp=0x5f200040,continuation=0x42e771;
 local.w32(sp,continuation);local.w32(sp+4,U(argument));local.w32(sp+8,U(argument>>32));
 floating_b39::State s{};s.fp=fp;floating_b39::Frame f{};f.entry_sp=f.sp=f.return_sp=sp;f.outer_return=continuation;
 const auto& list=floating_b39::entries_a();auto at=std::find_if(list.begin(),list.end(),[](const auto&e){return e.rva==0xba080;});
 need(at!=list.end(),"456 original-table square-root helper missing");at->function(local,s,f,{});fp=s.fp;
}
U norm(Memory&m,FP&fp,U first,U second,U third){
 fp.load_integer32(first);fp.load_integer32(second);fp.load_integer32(third);
 fp.load_st0();fp_extended::multiply_st1(fp);
 fp.load_st2();fp_extended::multiply_st3(fp);fp.add_pop();
 fp_extended::load_st3(fp);fp_extended::multiply_st4(fp);fp.add_pop();
 const auto sum=fp.pop64();fp.pop_st0();fp.pop_st0();fp.pop_st0();
 approximate(m,fp,sum);return integer(m,fp);
}
U live_cell(Memory&m,U x,U y){
 const auto tx=s32(x)/256,ty=s32(y)/256;const auto index=ty*512+tx;
 need(index>=0&&index<s32(m.r32(0x81a95c)),"456 positive live-cell index");
 const auto p=m.r32(m.r32(0x81a958)+4*U(index));need(p,"456 requires live cell");return p;
}
}
std::uint32_t fun_0042e6f0(Memory&m,const Inputs&i){
 need(i.cx==0x836c18&&m.r32(i.cx+0x60)!=0&&m.r32(0xa288b0)==0,"456 bounded global coordinate selection");
 for(U k=0;k<24;++k){const auto p=m.r32(i.cx+4*k);if(!p)continue;
  const auto dx=i.arg[0]-m.r32(p),dy=i.arg[1]-m.r32(p+4),dz=i.arg[2]-m.r32(p+8);
  const auto distance=norm(m,i.fp,dy,dz,dx);
  if(s32(distance)<128){
   // Actual 82960 empty-selection-list path, followed by 2eb5e0 and2e7e0.
   m.w32(0xaa8db4,0);m.w8(0xaa8db8,0);
   U last=0;for(U j=0;j<24;++j){last=m.r32(i.cx+4*j);if(last)m.w8(last+12,m.r8(last+12)&0xfd);}
   m.w8(p+12,m.r8(p+12)|2);return with_al(last,1);
  }
 }
 return 0; // EAX outer-loop index8 with AL cleared on exhausted positive list.
}
std::uint32_t fun_00436e70(Memory&m,const Inputs&i){
 const auto p=i.cx;auto&fp=i.fp;
 fp.load32(m.r32(p+0x18));const U x=integer(m,fp);
 fp.load32(m.r32(p+0x1c));const U y=integer(m,fp);
 fp.load32(m.r32(p+0x20));(void)integer(m,fp);
 const U cell=live_cell(m,x,y);
 need((m.r8(0x838f70)&7)==7&&m.r8(cell+0x11c)==0,"456 initialized flat cell height route");
 fp.load_integer32(sx8(m.r8(cell+0x11b))*m.r32(0x838f80));fp.add64(read64(m,0x785728));
 const auto height=integer(m,fp);
 fp.load_integer32(height);fp_extra::reverse_subtract32(fp,m.r32(p+0x20));U above=integer(m,fp);
 if((m.r32(cell+0x140)&0x100)&&s32(above)>=s32(m.r32(0x836fb0)))above-=m.r32(0x836fb0);
 fp.load32(m.r32(p+0x24));const U vx=integer(m,fp);
 fp.load32(m.r32(p+0x28));const U vy=integer(m,fp);
 fp.load_integer32(above);fp.multiply64(read64(m,p+8));fp.add32(m.r32(p+0x2c));const U vz=integer(m,fp);
 const U result=norm(m,fp,vy,vx,vz);fp.load_integer32(result);return result;
}
}
