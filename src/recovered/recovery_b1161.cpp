#include "recovered/recovery_b1161.hpp"
#include <stdexcept>
namespace ra2::recovered::b1161 {namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void remove(Memory&m,Heap&h,unsigned reg,unsigned self,Observation&z){const unsigned ptr=m.r32(reg+4u),count=m.r32(reg+16u);need(count==2u&&m.r32(reg+8u)==10u&&m.r8(reg+12u)==1u&&m.r8(reg+13u)==1u,"1161 original populated owned registry");unsigned at=0;while(at<count&&h.r32(ptr+at*4u)!=self)++at;need(at<count,"1161 receiver present");m.w32(reg+16u,count-1u);for(unsigned j=at+1u;j<count;++j)h.w32(ptr+4u*(j-1u),h.r32(ptr+4u*j));++z.registry_unpublications;++z.removals;++z.virtual_callbacks;}
void failed_cast(Memory&m,unsigned vt){const unsigned col=m.r32(vt-4u);need(m.r32(col+4u)==0u&&m.r32(col+8u)==0u,"1161 original zero RTTI top offsets");const unsigned ch=m.r32(col+16u),n=m.r32(ch+8u),bca=m.r32(ch+12u);need(n==9u&&(m.r32(ch+4u)&2u)==0u,"1161 actual nonvirtual hierarchy");bool source=false;for(unsigned j=0;j<n;++j){const unsigned bc=m.r32(bca+4u*j),type=m.r32(bc);need(type!=0x7b91f0u,"1161 target AbstractType absent from complete original hierarchy");if(type==0x7b91d0u){need(m.r32(bc+8u)==0u&&m.r32(bc+12u)==0xffffffffu&&m.r32(bc+16u)==0u,"1161 actual Abstract source PMD");source=true;}}need(source,"1161 original Abstract source present");}
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){need(root==0x2acdc0u,"1161 exact Team cleanup root");const unsigned self=i.cx,vt=0x7977f8u;need((self==base+0x1000u||self==base+0x4000u)&&m.r32(self)==vt&&(m.r8(self+0x14u)&2u)==0u&&m.r32(self+0x24u)==0u&&m.r8(self+0x74u)==0u,"1161 original2ACA80 arg0null read-field projection");need(m.r32(0xa255a0u)==0u&&m.r32(0xaa8730u)==0u&&m.r8(0xa285a8u)==0u&&m.r32(0x81b9c0u)!=self&&m.r32(0x81b9c4u)!=self,"1161 genuine fresh auxiliary/global state");need(m.r32(vt+44u)==0x6b3d80u,"1161 authentic kind34 getter");++z.virtual_callbacks;failed_cast(m,vt);++z.rtti_casts;
 // Original failed-cast dispatch kind34 reaches6E211D. Its real AA8720
 // registry has count0 from6E1C50, so no notification callback is invoked.
 for(unsigned reg:{0xaa8838u,0xaa8868u,0xaa87b8u,0xaa8760u,0x84e4a8u})remove(m,h,reg,self,z);
 const unsigned finalvt[]{0x785dd8u,0x785dbcu,0x785db4u,0x785dacu};for(unsigned k=0;k<4u;++k)m.w32(self+4u*k,finalvt[k]);
 // Last Find/shift result is0/1. MOV AL,[self+74]=0 removes its low byte;
 // original40FF90 preserves EAX. Both selected positions therefore return0.
 return 0u;
}}
