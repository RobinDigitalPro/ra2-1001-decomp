#include "recovered/state_b103.hpp"
#include "recovered/text_b96.hpp"
#include "recovered/global_b60_a.hpp"
#include "recovered/buffer_b95.hpp"
#include "recovered/hash_wrappers.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/state_b93.hpp"
#include "recovered/leaf_b21_b.hpp"
#include <algorithm>
#include <array>
#include <cstdint>

namespace ra2::recovered::state_b103 {
using global_b26::s32;
namespace {
std::uint32_t score(std::uint32_t v){return (v*40799u>>5)&0x3fffu;}
}

std::uint32_t fun_0047f5d0(Memory& m,const Inputs& i){
 const auto out=i.arg[4];if(s32(i.arg[1])<=0)return 0;
 m.w32(out,0xf4d37c12u);m.w32(out+4u,0x3fe921d9u);
 return (out&0xffffff00u)|1u;
}

std::uint32_t fun_00674e10(Memory& m,const Inputs& i){
 const auto p=i.cx;m.w8(p+0x18u,1);
 // 0x674e10 composes the same accepted row init/list callback closure as
 // 0x674090, with this body's additional activation-byte store.
 return state_b93::fun_00674090(m,i);
}

std::uint32_t fun_00757b10(Memory& m,const Inputs& i){
 const auto p=i.cx;
 m.w32(p,0x0079a8b4u);m.w32(p+0x38u,0x0079a934u);m.w32(p+0x20u,0x0079a934u);m.w32(p+8u,0x0079a934u);
 m.w8(p+0x45u,0);m.w8(p+0x2du,0);m.w8(p+0x15u,0);
 m.w32(p+0x40u,0);m.w32(p+0x28u,0);m.w32(p+0x10u,0);
 return p;
}

std::uint32_t fun_006720d0(Memory& m,const Inputs& i){
 const auto p=i.cx;unsigned k=0;for(;k<4;++k)if(s32(m.r32(p+0x1590u+k*0xe64u))>0)break;
 if(k==4&&m.r32(0x00aa4838u)){m.w32(p+0x4ed4u,1);m.w32(p+0x4ed0u,0);}
 const auto index=i.arg[0];const auto tab=0x00aa1008u+index*96u;
 if(m.r8(tab+0x1eu)==0 && index==m.r32(p+0x4ed8u))return 1;
 return 1;
}

std::uint32_t fun_005c1bd0(Memory& m,const Inputs& i){
 if(i.cx!=0xffffffffu)return 0;
 m.w32(0x00a25e44u,0);m.w8(0x00a25e48u,0);m.w32(0x00a25e4cu,0);
 m.w16(0x00a25672u,0);m.w8(0x00a25c20u,0);m.w8(0x00a25e22u,0);return 0;
}

std::uint32_t fun_00636f30(Memory& m,const Inputs& i){
 const auto p=i.cx,count=m.r32(p+0x10u),table=m.r32(p+4u);const auto id=i.arg[0];
 for(std::uint32_t n=0;n<count;++n){const auto r=m.r32(table+n*4u);if(std::int8_t(m.r8(r))==std::int8_t(id)){m.w8(r+0x27u,0);m.w8(r+0x25u,0);}}
 return count&0xffffff00u;
}

std::uint32_t fun_00530820(Memory& m,const Inputs& i){
 const auto p=i.cx;Inputs q=i;q.arg[0]=1;q.arg[1]=i.arg[3];
 if(m.r32(0x00a28984u)==0&&m.r32(0x00a39eecu)!=0&&m.r32(p+0x314u)==2&&m.r32(p+0x318u)==0){
   (void)buffer_b95::fun_00530730(m,q);
 }
 return 1;
}

std::uint32_t fun_007581a0(Memory& m,const Inputs& i){
 const auto p=i.cx;
 m.w32(p,0x0079a964u);m.w8(p+0x43868u,0);
 m.w32(p+0x43afcu,0x0079a9e4u);m.w32(p+0x43b14u,0x0079a9e4u);
 m.w8(p+0x43b09u,0);m.w8(p+0x43b21u,0);m.w32(p+0x43b04u,0);m.w32(p+0x43b1cu,0);
 // The finite contract selects the actual inactive/null-resource base cleanup.
 Inputs base=i;base.cx=p;return state_b93::fun_00756ea0(m,base);
}

std::uint32_t fun_00758da0(Memory& m,const Inputs& i){
 const auto p=i.cx; m.w32(p,0x0079a964u);m.w8(p+0x43868u,0);
 m.w32(p+0x43afcu,0x0079a9e4u);m.w32(p+0x43b14u,0x0079a9e4u);
 m.w8(p+0x43b09u,0);m.w8(p+0x43b21u,0);m.w32(p+0x43b04u,0);m.w32(p+0x43b1cu,0);
 Inputs base{};base.cx=p;(void)state_b93::fun_00756ea0(m,base);return p;
}

std::uint32_t fun_0076b2a2(Memory& m,const Inputs& i){
 const auto desc=i.arg[0],source=m.r32(desc),out=m.r32(desc+4u);auto predictor=m.r32(desc+0x14u);auto state=m.r16(desc+0x22u);
 // Exact mono16 zero-input path. The original transition and increment tables
 // are read from the pinned image for every sample; no replacement table is used.
 for(unsigned n=0;n<8;++n){
   const auto input_byte=m.r8(source+(n/2u));
   const auto nibble=(input_byte>>((n&1u)*4u))&0xfu;
   const auto table=(n&1u)?0x00812c94u:0x00812b94u;
   state=std::uint16_t(state|m.r8(table+nibble));
   const auto delta=m.r32(0x00810a34u+std::uint32_t(state)*2u);
   predictor=std::uint32_t(std::clamp<std::int64_t>(std::int64_t(s32(predictor))+s32(delta),-32768,32767));
   state=m.r16(0x00812074u+std::uint32_t(state));
   m.w16(out+n*2u,std::uint16_t(predictor));
 }
 m.w32(desc+0x14u,predictor);m.w16(desc+0x22u,state);return i.arg[1];
}

std::uint32_t fun_0076f8f9(Memory& m,const Inputs& i){
 const auto descriptor=i.arg[1],hdr=m.r32(descriptor+0x10u),outer_table=m.r32(hdr+0x0cu),outer=m.r32(outer_table);
 if(m.r32(hdr+8u)==0)return 0;
 const auto outer_query=i.arg[4];if(m.r32(outer)==outer_query){
  const auto inner_table=outer_table+4u,inner=m.r32(inner_table);if(m.r32(outer+4u)==0)return 0;
  if(m.r32(inner)==i.arg[2]){
   const auto obj=inner+8u,base=m.r32(obj+4u),offset=m.r32(obj+8u);std::uint32_t value=m.r32(obj);
   if(s32(base)>=0){const auto ptr=m.r32(base+i.arg[0]);value+=base+m.r32(ptr+offset);}
   return value==i.arg[3]?outer:0;
  }
 }
 return 0;
}

std::uint32_t fun_00773b88(Memory& m,const Inputs& i){
 const auto heap=i.arg[0],p=i.arg[1],requested=i.arg[2],meta=m.r32(heap+0x10u);
 const auto old_size=m.r32(p-4u)&~1u,aligned=(requested+0x17u)&~0xfu;
 const auto remainder=old_size-aligned,free_block=p+aligned-4u;
 m.w32(p-4u,aligned|1u);m.w32(p+aligned-8u,aligned|1u);
 if(remainder>0){const auto tagged=remainder; m.w32(free_block,tagged);m.w32(p+old_size-8u,tagged);
   const auto bucket=meta+0x144u+((remainder>>4)-1u)*8u;
   const auto next=m.r32(bucket+4u),prev=m.r32(bucket+8u);
   m.w32(free_block+4u,next);m.w32(free_block+8u,bucket);m.w32(next+8u,free_block);m.w32(bucket+4u,free_block);
   if(next==bucket){const auto mask=0x80000000u>>(((remainder>>4)-1u)&31u);const auto old_count=m.r8(meta+5u);i.arg[1]=(free_block&0x00ffffffu)|(old_count<<24);m.w8(meta+5u,old_count+1u);m.w32(meta+0x44u,m.r32(meta+0x44u)|0x40000000u);m.w32(heap,m.r32(heap)|mask);}
   (void)prev;i.arg[2]=remainder;
 }
 return 1;
}

std::uint32_t fun_005a58e0(Memory& m,const Inputs& i){
 const auto out=i.cx,divisor=m.r32(i.dx);unsigned bits=0;for(auto t=divisor;t;t>>=1)++bits;
 std::uint32_t local=1u<<(bits-1u),mask=1u<<bits,result=0;
 for(unsigned n=0;n<bits;++n){std::array<std::uint8_t,4> scratch{};leaf::Memory span(scratch.data(),0x7c000000u,4);Memory work=m;work.add(span);Inputs sh{};sh.cx=0x7c000000u;sh.dx=1;sh.arg[0]=1;span.w32(sh.cx,local);(void)global_b26::fun_005a46f0(work,sh);local=span.r32(sh.cx);if(local>=divisor){local-=divisor;result|=mask;}mask>>=1;}
 m.w32(out,result);return 0;
}

std::uint32_t fun_005a5260(Memory& m,const Inputs& i){
 const auto rem_out=i.cx,quot_out=i.dx,n=m.r32(i.arg[0]),divisor=m.r32(i.arg[1]);
 std::uint32_t rem=0,quot=0;int high=7;while(high>0&&((n>>high)&1u)==0)--high;
 for(int bit=high;bit>=0;--bit){std::array<std::uint8_t,4> scratch{};leaf::Memory span(scratch.data(),0x7c000000u,4);Memory work=m;work.add(span);Inputs sh{};sh.cx=0x7c000000u;sh.dx=1;sh.arg[0]=1;span.w32(sh.cx,rem);(void)global_b26::fun_005a46f0(work,sh);rem=span.r32(sh.cx)|((n>>bit)&1u);if(rem>=divisor){rem-=divisor;quot|=1u<<bit;}}
 m.w32(rem_out,rem);m.w32(quot_out,quot);return 0;
}

std::uint32_t fun_005a5ff0(Memory& m,const Inputs& i){
 const auto out=i.cx,b=m.r32(i.dx),a=m.r32(i.arg[0]);
 const auto scratch=0x00a58f74u;
 std::array<std::uint8_t,16> bytes{};
 leaf::Memory local(bytes.data(),0x7c000000u,std::uint32_t(bytes.size()));
 const auto local_scratch=0x7c000000u,local_source=local_scratch+12u;
 local.w16(local_source,b);local.w16(local_source+2u,b>>16);
 leaf::Inputs mul{};mul.cx=local_scratch;mul.dx=local_source;mul.arg[0]=a;mul.arg[1]=2;
 (void)leaf::fun_005a5d00(local,mul);
 mul.cx=local_scratch+2u;mul.arg[0]=a>>16;(void)leaf::fun_005a5d00(local,mul);
 // The original clears two dwords, accumulates the product through the
 // accepted word multiply-add leaf, then writes its zero sentinel at +8.
 for(unsigned k=0;k<8;++k)m.w8(scratch+k,local.r8(local_scratch+k));
 m.w32(scratch+8u,0);
 const auto result=m.r32(scratch);
 m.w32(out,result);return 0;
}

std::uint32_t fun_005a77c0(Memory& m,const Inputs& i){
 const auto count=m.r32(0x00a1a5d8u),table=m.r32(0x00a1a5ccu);m.w32(0x00a278b8u,0);
 if(count==0)return 0;const auto obj=m.r32(table);if(!obj)return 0;
 const auto record=m.r32(obj+0x34u);if(m.r8(record+0x1a6u))return 0;
 const auto out=0x00a27534u;m.w32(0x00a278b8u,1);
 auto src=obj+0x15f16u;for(unsigned n=0;n<16;++n){const auto c=m.r16(src+n*2u);m.w16(out+n*2u,c);if(!c)break;}
 m.w32(out+0x28u,m.r32(obj+0x15f40u));m.w32(out+0x2cu,0);
 std::uint32_t sum=0;for(unsigned n=0;n<20;++n)sum+=m.r32(obj+0x5310u+n*4u);sum+=m.r32(obj+0x5364u);
 m.w32(out+0x40u,sum);
 const auto a=m.r32(obj+0x5360u),b=m.r32(obj+0x53b4u);m.w32(out+0x30u,a+b);
 sum=0;for(unsigned k=0;k<4;++k){const auto h=obj+0x54a0u+k*0x10u,num=m.r32(h+8u),arr=m.r32(h+4u);for(unsigned j=0;j<num;++j)sum+=m.r32(arr+j*4u);}m.w32(out+0x50u,sum);
 const auto c=m.r32(obj+0x5418u);m.w32(out+0x60u,s32(c)>0?c:0u);return 1;
}

std::uint32_t fun_00591e40(Memory& m,const Inputs& i){
 const auto p=i.cx,state_addr=i.arg[0];(void)text_b96::fun_005cd1a0(m,i);NameHashState h{};h.accumulator=m.r32(state_addr);h.pending=m.r32(state_addr+4u);
 for(unsigned n=0;n<4;++n)h.scratch[n]=std::uint8_t(m.r8(state_addr+8u+n));h.completion_byte=std::uint8_t(m.r8(state_addr+12u));
 std::uint32_t result=0;for(auto off:{0x98u,0x9cu,0xa0u,0xa8u})result=fun_00493d10(h,m.r32(p+off));
 const auto begin=m.r32(p+0xb0u),cap=m.r32(p+0xb8u);std::uint32_t duration=cap;
 if(begin!=0xffffffffu){const auto elapsed=m.r32(0x00a2896cu)-begin;if(s32(elapsed)<s32(cap))duration=cap-elapsed;else duration=0;}
 result=fun_00493d10(h,duration);result=fun_00493d10(h,m.r32(p+0xacu));
 m.w32(state_addr,h.accumulator);m.w32(state_addr+4u,h.pending);for(unsigned n=0;n<4;++n)m.w8(state_addr+8u+n,h.scratch[n]);m.w8(state_addr+12u,h.completion_byte);return result;
}

std::uint32_t fun_0053c670(Memory& m,const Inputs& i){
 const auto src=i.cx,n=i.dx,out=i.arg[0],sizep=i.arg[1],dict=i.arg[2];
 std::uint32_t last_index=0;
 for(unsigned pos=0;pos<4;++pos){
   const auto b0=m.r8(src+pos),b1=m.r8(src+pos+1u),b2=m.r8(src+pos+2u);
   const auto rolling=(b2<<10)^(b1<<5)^b0;last_index=score(rolling);
   m.w32(dict+last_index*4u,src+pos);
 }
 // At scan position source+4, the original reuses the fourth rolling hash,
 // reads its prior pointer, then replaces that slot with source+4.
 const auto prior=m.r32(dict+last_index*4u);m.w32(dict+last_index*4u,src+4u);
 // The finite route has prior==source+3; the first byte comparison rejects
 // that candidate, then the short-input end check selects the literal tail.
 if(m.r8(prior)!=m.r8(src+4u) && src+5u>=src+n-13u){
   m.w8(out,std::uint8_t(n+17u));for(std::uint32_t k=0;k<n;++k)m.w8(out+1u+k,m.r8(src+k));
   m.w32(sizep,n+1u);i.arg[2]=n;
 }
 return 0;
}
}
