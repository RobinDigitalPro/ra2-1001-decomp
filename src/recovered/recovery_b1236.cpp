#include "recovery_b1236.hpp"
#include <stdexcept>
namespace ra2::recovered::b1236 {
static void need(bool x){if(!x)throw std::domain_error("1236 finite two-cell middle-level region projection");}
static unsigned r16(Heap&h,unsigned a){return h.r8(a)|(h.r8(a+1u)<<8u);}
static void w16(Heap&h,unsigned a,unsigned x){h.w8(a,x);h.w8(a+1u,x>>8u);}
struct Rect{int x,y,w,h;};
struct Fill{unsigned skip,scratch;};
// Original561080's reached flat same-base-region scanline route. The private
// rectangle/coordinate producers are explicit scalar inputs; no stack seeds.
static Fill fill(Memory&m,Heap&h,unsigned self,unsigned p,unsigned level,unsigned label,const Rect&b,int x,int y){
 need(level==1u&&label==1u&&r16(h,p+6u)==1u&&h.r8(p+8u)==0u);
 const unsigned step=10u*(m.r32(self+0xf0u)+m.r32(self+0xf4u)+1u);const int xmax=b.x+b.w-1,ymax=b.y+b.h-1;
 unsigned left=p,right=p;int lx=x,rx=x;
 while(lx>=b.x){need(h.r8(left+8u)==0u);w16(h,left+2u*level,label);left-=10u;--lx;if(r16(h,left+6u)!=1u)break;}
 while(rx<=xmax&&r16(h,right+6u)==1u){need(h.r8(right+8u)==0u);w16(h,right+2u*level,label);right+=10u;++rx;}
 // In this one-region finite domain all other existing labels are zero or1;
 // no distinct-region edge insertion or membership callback is reached.
 unsigned q=left-step;
 for(int k=lx;k<=rx;++k,q+=10u){const auto old=r16(h,q+2u*level);need(old==0u||old==label);if(old==0u&&y>b.y&&k>=b.x&&k<=xmax&&r16(h,q+6u)==1u){need(h.r8(q+8u)==0u);fill(m,h,self,q,level,label,b,k,y-1);}}
 q=left+step;
 for(int k=lx;k<=rx;++k,q+=10u){const auto old=r16(h,q+2u*level);need(old==0u||old==label);if(old==0u&&y<ymax&&k>=b.x&&k<=xmax&&r16(h,q+6u)==1u){need(h.r8(q+8u)==0u);fill(m,h,self,q,level,label,b,k,y+1);}}
 return {(right-p)/10u-1u,q};
}
static void node(Heap&h,unsigned p){h.w32(p,0x790ab8u);h.w32(p+4u,0u);h.w32(p+8u,0u);h.w8(p+12u,1u);h.w8(p+13u,0u);h.w32(p+16u,0u);h.w32(p+20u,10u);w16(h,p+24u,0u);h.w32(p+28u,0u);h.w32(p+32u,0u);}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){
 need(root==0x160b70u||root==0x161080u);const auto self=i.cx;need(m.r32(self)==0x79091cu&&m.r32(self+0xf0u)==7u&&m.r32(self+0xf4u)==11u&&m.r32(self+0x68u)==361u);
 const auto cache=m.r32(self+0x6cu);
 if(root==0x161080u){need(i.arg[1]==1u&&i.arg[2]==1u);const auto rect=i.arg[3],point=i.arg[4];const Rect b{int(m.r32(rect)),int(m.r32(rect+4u)),int(m.r32(rect+8u)),int(m.r32(rect+12u))};const int x=int(short(m.r16(point))),y=int(short(m.r16(point+2u)));const auto z=fill(m,h,self,i.arg[0],i.arg[1],i.arg[2],b,x,y);i.arg[0]=z.scratch;i.arg[4]=unsigned(y);return z.skip;}
 need(i.arg[0]==1u&&m.r32(0x81a910u)==7u&&m.r32(0x81a914u)==11u);const unsigned v=self+0xa0u,header=m.r32(self+0x80u),buckets=h.r32(header),base=m.r32(self+0x64u);
 need(h.r32(header+8u)==256u&&h.r32(header+12u)==20u&&h.r32(buckets-4u)==256u&&m.r32(0x790a44u)==0x567ba0u);
 for(unsigned j=0;j<256u;++j){const auto q=buckets+24u*j;need(h.r32(q)==0x790a38u&&h.r32(q+4u)==0u&&h.r32(q+8u)==0u&&h.r32(q+16u)==0u&&h.r8(q+13u)==0u);h.w32(q+16u,0u);h.w8(q+13u,0u);h.w32(q+8u,0u);}
 for(unsigned j=0;j<361u;++j){w16(h,cache+10u*j+2u,0u);w16(h,cache+10u*j+6u,r16(h,base+4u*j+2u));h.w8(cache+10u*j+8u,h.r8(base+4u*j+1u));}
 need(m.r32(v)==0x7909b8u&&m.r32(v+4u)==0u&&m.r32(v+8u)==0u&&m.r32(v+16u)==0u&&m.r32(v+20u)==10u&&m.r32(0x7909c0u)==0x568630u);
 m.w8(v+12u,0u);const auto cookie=h.allocate(364u);need(cookie!=0u);h.w32(cookie,10u);const auto nodes=cookie+4u;for(unsigned j=0;j<10u;++j)node(h,nodes+36u*j);m.w8(v+12u,1u);m.w32(v+4u,nodes);m.w32(v+8u,10u);m.w8(v+13u,1u);
 // Actual567CD0(0,0) and569840(0,0) temporaries have innercapacity0;
 // 5690D0 copies them without allocation. No operator_new(0) is reached.
 m.w32(v+16u,1u);w16(h,nodes+24u,0u);h.w32(nodes+28u,7u);
 unsigned count=1u;for(unsigned j=0;j<361u;){const auto p=cache+10u*j;if(h.r8(base+4u*j)!=7u&&r16(h,p+2u)==0u){const unsigned x=j%19u,y=j/19u;const Rect b{int(x&~3u),int(y&~3u),4,4};m.w32(0xa5784cu,0u);const auto z=fill(m,h,self,p,1u,count,b,int(x),int(y));need(count<10u);const auto q=nodes+36u*count;w16(h,q+24u,r16(h,p+4u));h.w32(q+28u,h.r8(base+4u*j));h.w32(q+20u,16u);h.w32(q+32u,131u+(y/4u)*130u+x/4u);++count;m.w32(v+16u,count);j+=z.skip;}else ++j;}
 m.w32(self+0x74u,count);need(m.r32(self+0x5cu)==0u);
 unsigned result=0u;for(unsigned j=0;j<256u;++j){result=buckets+24u*j;need(h.r32(result+16u)==0u);}return result;
}
}
