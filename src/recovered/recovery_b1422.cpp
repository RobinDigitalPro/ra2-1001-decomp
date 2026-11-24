#include "recovery_b1422.hpp"
#include "recovered/recovery_b1421.hpp"
#include "recovered/recovery_b108.hpp"
#include "recovered/recovery_b517.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1422 {
namespace {
using U=std::uint32_t;
void slot(Memory& m,U object,U offset,U target){
 if(m.r32(m.r32(object)+offset)!=target)throw std::domain_error("B1422 requires the actual pinned actor dispatch");
}
// Actual 6B6910 delegates +80 to +84; actual 41B600 returns the supplied type.
U actor_type(Memory& m,U actor){slot(m,actor,0x80u,0x6b6910u);slot(m,actor,0x84u,0x41b600u);return m.r32(actor+0x5acu);}
U ordinary_entry(Memory& m,const Inputs& in,U actor,U index){
 // Actual 6CDAB0. No alternate/ranked weapon branch is in this finite domain.
 if(index==0xffffffffu)return 0u;
 in.fp.load64(floating_b61::read64(m,actor+0x118u));
 in.fp.compare_pop64(floating_b61::read64(m,0x7856f8u));
 const U compare=(in.fp.status()&0x100u)?0u:1u; // 707FE0 full EAX result.
 if(compare!=0u)throw std::domain_error("B1422 excludes the alternate weapon entry");
 const U type=actor_type(m,actor);
 // Actual 6D4B30: ((index*8)-index)*4 + type+74C, RET4.
 return type+(index*8u-index)*4u+0x74cu;
}
U selected_entry(Memory& m,const Inputs& in,U actor){
 slot(m,actor,0x398u,0x6cdb10u);
 const U type=actor_type(m,actor);
 const U ranked=global_b26::s32(m.r32(type+0x704u))>0?1u:0u; // 6D4BF0.
 const U index=ranked?m.r32(actor+0x10cu):0u;
 slot(m,actor,0x39cu,0x6cdab0u);return ordinary_entry(m,in,actor,index);
}
U has_entry(Memory& m,const Inputs& in,U actor){
 slot(m,actor,0x28cu,0x6c2be0u);
 const U entry=selected_entry(m,in,actor);
 return entry!=0u&&m.r32(entry)!=0u?1u:0u; // Actual 6C2BE0, full EAX.
}
U unarmed_query(Memory& m,const Inputs& in,U actor){
 // 6CAF40, 6CAE70 and 6CADE0 all call the actual +28C provider, then their
 // selected false branch executes XOR EAX,EAX. Its FP effects remain live.
 if((has_entry(m,in,actor)&255u)!=0u)throw std::domain_error("B1422 excludes armed-query branches");
 return 0u;
}
}
std::uint32_t fun_004ea790(Memory& original,const Inputs& in){
 const U self=in.cx,actor=in.arg[1];
 const U first=unarmed_query(original,in,actor); // 6CAF40
 const U second=unarmed_query(original,in,actor); // 6CAE70
 const U third=unarmed_query(original,in,actor); // 6CADE0
 // Original MOV EBX,0 does not change the ADD flags used by JNZ.
 if(first+second+third!=0u)throw std::domain_error("B1422 excludes mode1..4 selection");
 std::array<std::uint8_t,0x100> bytes{};
 constexpr U t=0x7db00000u;
 leaf::Memory local(bytes.data(),t,U(bytes.size()));Memory m=original;m.add(local);
 for(U k=0;k<16u;++k)m.w32(t+0x28u+4u*k,in.arg[k]);
 Inputs call=in;call.cx=self;call.arg[0]=t+0x2cu;call.arg[1]=0u;
 const U generated=b1421::fun_004ebf50(m,call);in.fp=call.fp;
 m.w32(t+0x10u,m.r32(generated));
 m.w16(t+0x0cu,0u);m.w16(t+0x0eu,0u);
 m.w32(t+0x20u,m.r32(actor+0x90u));
 m.w16(t+0x2cu,std::uint16_t(global_b26::s32(m.r32(actor+0x88u))/256));
 m.w16(t+0x2eu,std::uint16_t(global_b26::s32(m.r32(actor+0x8cu))/256));
 // B108 receives exactly three arguments; the ten previously pushed words
 // belong to B517. All pointers reference produced storage in this frame.
 call=in;call.cx=0x81a820u;call.ax=t+0x2cu;call.dx=t+0x0cu;
 call.arg[0]=t+0x2cu;call.arg[1]=0u;call.arg[2]=0u;
 const U zone=recovery_b108::fun_0054cd80(m,call);in.fp=call.fp;
 call=in;call.cx=0x81a820u;call.ax=zone;call.dx=t+0x14u;
 const std::array<U,14> args{{t+0x14u,t+0x10u,1u,zone,0u,0u,1u,1u,0u,0u,0u,1u,t+0x0cu,0u}};
 for(U k=0;k<args.size();++k)call.arg[k]=args[k];
 const U chosen=recovery_b517::fun_0054d770(m,call);in.fp=call.fp;
 const U out=m.r32(t+0x28u);m.w32(out,m.r32(chosen));
 in.arg[1]=m.r32(t+0x2cu);return out;
}
}
