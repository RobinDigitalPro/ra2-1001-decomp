#include "recovered/recovery_b1165.hpp"
#include <stdexcept>
namespace ra2::recovered::b1165 {
namespace{void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){
 need(root==0xc0a40u,"1165 exact fresh FoggedObject cleanup");const auto s=i.cx;
 need((s==base+0x1000u||s==base+0x4000u)&&m.r32(s)==0x78c148u&&m.r32(s+0x30u)==0u&&m.r32(s+0x34u)==0u&&m.r32(s+0x38u)==0u&&m.r32(s+0x60u)==0u&&m.r32(s+0x64u)==0u&&m.r32(s+0x6cu)==0u&&m.r8(s+0x68u)==1u&&m.r8(s+0x69u)==0u,"1165 exact BFC90 read-field constructor poststate");
 need(m.r32(0x84e1c0u)==0x78817cu&&m.r32(0x78818cu)==0x454100u&&m.r32(0x84e1c8u)==10u&&m.r8(0x84e1ccu)==1u&&m.r8(0x84e1cdu)==1u&&m.r32(0x84e1d0u)==2u,"1165 genuine owned cap10 registry and actual Find vtable slot10");
 need(m.r32(0x84e170u)==0u&&m.r32(0x84e174u)==0u&&m.r32(0x84e178u)==0u&&m.r8(0x84e17cu)==0u&&m.r32(0x84e180u)==0u&&m.r32(0x821cacu)==0u,"1165 actual4BFBD0 spatial-index initializer and untouched PE BSS UI pointer");
 const unsigned constructorvt[]{0x78c148u,0x78c12cu,0x78c124u,0x78c11cu};for(unsigned k=0;k<4u;++k)m.w32(s+k*4u,constructorvt[k]);
 // Actual454100 RET4 dereferences its pointer-to-query and performs signed
 // count-controlled linear Find. It is typed here, not a canned callback result.
 const auto data=m.r32(0x84e1c4u),count=m.r32(0x84e1d0u);unsigned at=0u;while(at<count&&h.r32(data+at*4u)!=s)++at;need(at<count,"1165 positive actual receiver membership");++z.virtual_callbacks;
 m.w32(0x84e1d0u,count-1u);for(unsigned j=at+1u;j<count;++j)h.w32(data+(j-1u)*4u,h.r32(data+j*4u));++z.removals;++z.registry_unpublications;
 // Constructor type/coordinates0 compute a deterministic integer key, but the
 // genuine index count0 performs no sort/search/removal. Type0 also skips the
 // type6 map-cell side effects, and original BSS821CAC0 skips UI redraw.
 // The final MOV EAX,[self60] is full-width0, then40FF90 preserves it.
 m.w32(s+0x5cu,0x78c1d0u);m.w8(s+0x69u,0u);m.w32(s+0x64u,0u);const unsigned basevt[]{0x785dd8u,0x785dbcu,0x785db4u,0x785dacu};for(unsigned k=0;k<4u;++k)m.w32(s+k*4u,basevt[k]);return 0u;
}
}
