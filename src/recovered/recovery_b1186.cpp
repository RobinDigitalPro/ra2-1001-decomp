#include "recovery_b1186.hpp"
#include <stdexcept>
namespace ra2::recovered::b1186{
static void need(bool x){if(!x)throw std::domain_error("1186 exact cold original singleton ownership");}
static unsigned allocate(Heap&h,unsigned n){const auto p=h.allocate(n);need(p!=0u);return p;}
//4911C0,5FD980 and5FCC00 constructor fields; preserve all unspecified bytes.
static void vector(Heap&h,unsigned p,unsigned vt){h.w32(p,vt);h.w32(p+4u,0u);h.w32(p+8u,0u);h.w8(p+12u,1u);h.w8(p+13u,0u);h.w32(p+16u,0u);h.w32(p+20u,10u);}
static void empty(Heap&h,unsigned p,unsigned vt){need(h.r32(p)==vt&&h.r32(p+4u)==0u&&h.r32(p+8u)==0u&&h.r32(p+16u)==0u&&h.r8(p+13u)==0u);}
//1FBE30 cold positive route: genuine scalar/array deleting destructor targets.
static unsigned destroy(Heap&h,unsigned o){const auto a=h.r32(o+4u),b=h.r32(o+8u),header=h.r32(o+12u),array=h.r32(header);need(a&&b&&header&&array&&h.r32(header+8u)==31u&&h.r32(array-4u)==31u&&h.r32(header+4u)==0x5fb1f0u&&h.r32(header+12u)==10u);empty(h,a,0x78955cu);empty(h,b,0x792b18u);
 //Both +C clear calls retain the derived vptr. Scalar delete publishes base vptr.
 h.w32(a+16u,0u);h.w8(a+13u,0u);h.w32(a+8u,0u);h.w32(b+16u,0u);h.w8(b+13u,0u);h.w32(b+8u,0u);
 h.w32(a,0x78957cu);h.w8(a+13u,0u);h.w32(a+8u,0u);need(h.release(a)!=0u);
 h.w32(b,0x792bb8u);h.w8(b+13u,0u);h.w32(b+8u,0u);need(h.release(b)!=0u);
 for(unsigned j=0;j<31u;++j){const auto p=array+24u*j;empty(h,p,0x792b38u);h.w32(p+16u,0u);h.w8(p+13u,0u);h.w32(p+8u,0u);}
 //5FD220 flag3 walks backward over cookie31 and releases original raw cookie base.
 for(unsigned j=31u;j;--j){const auto p=array+24u*(j-1u);h.w32(p,0x792b98u);h.w8(p+13u,0u);h.w32(p+8u,0u);}need(h.release(array-4u)!=0u);return h.release(header);
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&){need(root==0x1fb330u||root==0x1fb930u);need(m.r32(0xa5df68u)==0u);if(root==0x1fb330u)need(i.cx<3u);
 const auto o=allocate(h,16u);h.w32(o,0xffffffffu);const auto a=allocate(h,24u);vector(h,a,0x78955cu);h.w32(o+4u,a);const auto b=allocate(h,24u);vector(h,b,0x792b18u);h.w32(o+8u,b);const auto header=allocate(h,16u);h.w32(header+4u,0x5fb1f0u);h.w32(header+8u,31u);h.w32(header+12u,10u);const auto raw=allocate(h,748u);h.w32(raw,31u);
 //1FB330 uses40AED0(stride24,count31,ctor5FD2D0);1FB930 uses5FCC00.
 //Both exact original constructors write identical fields and preserve every unspecified byte.
 for(unsigned j=0;j<31u;++j)vector(h,raw+4u+24u*j,0x792b38u);h.w32(header,raw+4u);h.w32(o+12u,header);m.w32(0xa5df68u,o);
 if(root==0x1fb330u)h.w32(o,i.cx); //Actual5193E0 forwards authentic4828B0 three-record index0..2.
 //Both cold roots traverse all31 genuine empty buckets. No stored hash/element callback runs.
 for(unsigned j=0;j<31u;++j)need(h.r32(raw+4u+24u*j+16u)==0u);
 //1FB330 resets EAX0 at each bucket;1FB930 returns its zero local count. Preserve full DWORD.
 return 0u;
}
unsigned cleanup(unsigned root,Memory&m,Heap&h){need(root==0x1fb330u||root==0x1fb930u);const auto o=m.r32(0xa5df68u);need(o);need(destroy(h,o)!=0u);const auto result=h.release(o);need(result!=0u);m.w32(0xa5df68u,0u);return result;}
}
