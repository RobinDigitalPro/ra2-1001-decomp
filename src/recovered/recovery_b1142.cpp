#include "recovered/recovery_b1142.hpp"
#include <stdexcept>
namespace ra2::recovered::b1142 {namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned index(Memory&m,unsigned d,Observation&z){const auto vt=m.r32(d),target=m.r32(vt+0x40u);need((vt==0x78ea78u&&target==0x50a3d0u)||(vt==0x7881f8u&&target==0x45e990u),"1142 genuine original descriptor index callback entry");++z.virtual_callbacks;return m.r32(d+0xb90u);}
unsigned kind(Memory&m,unsigned d,Observation&z){const auto vt=m.r32(d),target=m.r32(vt+0x2cu);++z.virtual_callbacks;if(vt==0x78ea78u&&target==0x50a3b0u)return 16u;need(vt==0x7881f8u&&target==0x45e970u,"1142 genuine original descriptor constantkind callback entry");return 7u;}
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){need(i.cx==base+0x1000u,"1142 exact prepared original receiver extent");
 if(root==0xcd5c0u){need(i.arg[0]==base+0x4000u&&m.r32(i.cx)==0x78e540u&&m.r32(0x78e540u+0x434u)==0x4cd680u&&m.r32(i.cx+0x4b4u)==29u&&m.r32(i.cx+0x4b8u)==base+0x5000u&&m.r32(i.cx+0x4bcu)==0u&&m.r8(i.cx+0x4c1u)==0u&&m.r32(base+0x5000u)==0x788b04u&&m.r32(base+0x5024u)==0u,"1142 genuine infantry constructor/positive29 override/borrowedCell producer projection and authentic clear callback");const unsigned command=m.r8(i.arg[0]+12u);need(command<29u,"1142 original non29 command domain0through28");m.w32(i.cx+0x4b4u,0xffffffffu);m.w32(i.cx+0x4b8u,0u);m.w32(i.cx+0x4bcu,0u);m.w8(i.cx+0x4c1u,0u);z.cancellations=1u;z.virtual_callbacks=1u;return command;}
 need((root==0x1cd50u||root==0x1d0f0u)&&i.arg[0]==base+0x3000u&&i.arg[1]==base+0x9000u&&m.r32(i.cx)==0x786780u&&m.r32(i.cx+0xd8u)==base+0x2000u,"1142 original rule/namedtype producer and two distinct positive house arguments");
 const unsigned d=m.r32(i.cx+0xd8u),ix=index(m,d,z),type=kind(m,d,z),house=root==0x1cd50u?i.arg[1]:i.arg[0],v=house+(type==16u?0x5480u:0x5460u);need(ix==1u&&m.r32(v)==0x7895acu&&m.r32(v+8u)==11u&&m.r8(v+12u)==1u&&m.r8(v+13u)==1u,"1142 genuine initialized positive count table, index1 strictly below actualcapacity11");const unsigned count=h.r32(m.r32(v+4u)+ix*4u),selector=m.r32(i.cx+0xe8u);need(count>0u&&count<0x80000000u&&selector<6u,"1142 positive count/six signed comparison domain");const int n=global_b26::s32(count),threshold=global_b26::s32(m.r32(i.cx+0xe4u));bool result=false;switch(selector){case 0:result=n<threshold;break;case 1:result=n<=threshold;break;case 2:result=n==threshold;break;case 3:result=n>=threshold;break;case 4:result=n>threshold;break;case 5:result=n!=threshold;break;}
 z.count_lookups=1u;z.signed_comparisons=1u;return(count&0xffffff00u)|unsigned(result);
}
}
