#include "recovered/recovery_b1093.hpp"
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1093{
static void need(bool b){if(!b)throw std::domain_error("1093 positive cold text install/nonempty UTF16/realclock/spare registry");}
unsigned run(Memory&m,const Inputs&i,Heap&h,Clock clock,State&,unsigned root){need(root==0x324890u||root==0x324960u);const unsigned self=i.cx,slot=root==0x324890u?0x47cu:0x480u,desc=m.r32(self+0x45cu),rect=desc+(root==0x324890u?0x7cu:0x8cu);need(m.r32(self+slot)==0u&&m.r32(self+0x18u)==0x79202cu&&m.r32(0x79203cu)==0x5b0730u);const unsigned source=m.r32(i.arg[0]);need(source&&clock);std::vector<unsigned>wide;for(unsigned k=0;k<48u;++k){auto ch=m.r16(source+k*2u);if(!ch)break;wide.push_back(ch);}need(wide.size()>=1u&&wide.size()<=31u);const unsigned bytes=2u*(unsigned(wide.size())+1u);
 const auto text=[&](){auto p=h.allocate(bytes);need(p);for(unsigned k=0;k<wide.size()+1u;++k){auto c=k<wide.size()?wide[k]:0u;h.w8(p+k*2u,c);h.w8(p+k*2u+1u,c>>8u);}return p;};
 const unsigned temporary=text();i.arg[0]=temporary;const unsigned object=h.allocate(52u);need(object);h.w32(object+4u,m.r32(rect));h.w32(object+8u,m.r32(rect+4u));h.w8(object+0xcu,1u);
 // Actual68FAD0 ignores ECX=object+14; it reads true timeGetTime thenSHR4.
 const unsigned now=clock();h.w32(object+0x10u,now>>4u);h.w32(object+0x18u,0u);h.w32(object,0x791d10u);h.w32(object+0x1cu,text());for(unsigned k=0;k<4u;++k)h.w32(object+0x20u+4u*k,m.r32(rect+4u*k));h.w8(object+0x30u,0u);h.w32(object,0x791e00u);h.w8(object+0x31u,root==0x324890u?1u:0u);m.w32(self+slot,object);h.w8(object+0x30u,1u);
 const unsigned count=m.r32(self+0x28u),capacity=m.r32(self+0x20u),table=m.r32(self+0x1cu);need(count>=3u&&count<=6u&&capacity==10u&&m.r8(self+0x24u)==1u&&m.r8(self+0x25u)==0u);m.w32(self+0x28u,count+1u);m.w32(table+4u*count,object);
 // Genuine79202C slot10 ->5B0730 traverses actual populated pointer table.
 unsigned found=0u;for(;found<count+1u;++found)if(m.r32(table+4u*found)==object)break;need(found==count);
 const unsigned result=h.release(temporary);need(result!=0u);i.arg[0]=0u;return result;
}
}
