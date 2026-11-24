#include "recovered/recovery_b1008.hpp"
#include <array>
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1008 {
namespace{unsigned error(int n){return unsigned(n);}bool bad(Api&a,unsigned p,unsigned n){return a.is_bad_write_ptr(reinterpret_cast<void*>(std::uintptr_t(p)),n)!=FALSE;}int signed32(unsigned n){return n<=0x7fffffffu?int(n):-1-int(0xffffffffu-n);}}
std::uint32_t fun_00773f4f(Memory&m,const Inputs&,Api&a){
 const auto count=m.r32(0xb10e14u),table=m.r32(0xb10e18u);if(count!=1u)throw std::domain_error("1008 one genuine populated smallheap region");if(bad(a,table,count*20u))return error(-1);
 for(unsigned r=0;r<count;++r){const auto rec=table+r*20u,metadata=m.r32(rec+16u);if(bad(a,metadata,0x41c4u))return error(-2);unsigned groupmask=m.r32(rec+8u),base=m.r32(rec+12u),total_low=0u,total_high=0u;
  for(unsigned group=0;group<32u;++group){unsigned low=0u,high=0u;std::array<unsigned,64>freecounts{};if(signed32(groupmask)>=0){if(bad(a,base,0x8000u))return error(-4);unsigned live=0u;
   for(unsigned page=0;page<8u;++page){const auto start=base+page*4096u,end=start+0xffcu;if(m.r32(start+8u)!=0xffffffffu||m.r32(end)!=0xffffffffu)return error(-5);unsigned p=start+12u;
    while(p<end){const auto tag=m.r32(p);unsigned span=tag;if(tag&1u){span=tag-1u;if(signed32(span)>0x400)return error(-6);++live;}else{const int bin=std::min((signed32(tag)>>4)-1,63);if(bin<0)throw std::domain_error("1008 malformed underflow outside positive contract");++freecounts[unsigned(bin)];}if(signed32(span)<16||(span&15u)||signed32(span)>0xff0)return error(-7);if(m.r32(p+span-4u)!=tag)return error(-8);p+=span;}if(p!=end)return error(-8);
   }
   const auto header=metadata+0x144u+group*0x204u;if(m.r32(header)!=live)return error(-9);
   for(unsigned bin=0;bin<64u;++bin){const auto head=header+bin*8u;unsigned next=m.r32(head+4u),previous=head,seen=0u;while(next!=head){if(next<base||next>=base+0x8000u)return error(-10);unsigned p=(next&0xfffff000u)+12u,end=(next&0xfffff000u)+0xffcu;while(p!=next&&p!=end){const auto step=m.r32(p)&0xfffffffeu;if(!step||step>end-p)throw std::domain_error("1008 invalid positive physical walk");p+=step;}if(p==end)return error(-11);const auto sizeclass=std::min((signed32(m.r32(next))>>4)-1,63);if(sizeclass!=int(bin))return error(-12);if(m.r32(next+8u)!=previous)return error(-13);++seen;if(seen>2048u)throw std::domain_error("1008 cyclic malformed free list excluded");previous=next;next=m.r32(next+4u);}if(m.r32(previous+4u)!=head||seen!=freecounts[bin])return error(-14);if(m.r32(head+8u)!=previous)return error(-15);if(seen){if(bin<32u)low|=0x80000000u>>bin;else high|=0x80000000u>>(bin-32u);}}
  }
  if(m.r32(metadata+0x44u+group*4u)!=low||m.r32(metadata+0xc4u+group*4u)!=high)return error(-16);total_low|=low;total_high|=high;groupmask<<=1u;base+=0x8000u;
 }
 if(m.r32(rec)!=total_low||m.r32(rec+4u)!=total_high)return error(-17);
 }
 return 0u;
}
}
