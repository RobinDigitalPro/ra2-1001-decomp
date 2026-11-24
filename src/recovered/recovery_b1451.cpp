#include "recovered/recovery_b1451.hpp"
#include <stdexcept>
namespace ra2::recovered::b1451 {
namespace {
using U=std::uint32_t;void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
void emptyhead(Heap&h,U p){need(h.r32(p+4)==p+4&&h.r32(p+8)==p+4&&h.r32(p+12)==p+4,"1451 actualemptyhead");}
//Exactempty-list408990/408B50 resetstores. No otherprovider is reached.
U reset(Heap&h,U p){emptyhead(h,p);for(U d:{p+0x18,p+0x58}){h.w32(d+0x28,0);h.w32(d+0x34,0xfffffc17);h.w32(d+0x38,0xfffffc17);h.w32(d+0x30,0);h.w32(d+0x2c,0);h.w32(d+0xc,0);h.w32(d+4,0);h.w32(d+8,0);h.w32(d+0x10,h.r32(d+0x10)&~1u);}const U v=h.r32(p+0x14)+h.r32(p+0x4c);h.w32(p+0x4c,v);return v;}
void release_ref(Heap&h,U d){const U p=h.r32(d);const U count=h.r32(d+0x1c)-1;h.w32(d+0x1c,std::int32_t(count)<0?0:count);const U total=h.r32(p+0x98)-1;h.w32(p+0x98,std::int32_t(total)<0?0:total);}
void reset_descriptor(Heap&h,U d){const U node=h.r32(d+0x28);need(node==0,"1451 actual408850 emptydescriptor");h.w32(d+0x2c,0);h.w32(d+0xc,node);h.w32(d+4,0);h.w32(d+8,0);h.w32(d+0x10,h.r32(d+0x10)&~1u);}
}
U configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1451 actual CRTsetter argument");m.w32(0x817554,0);return 1;}
U producer(unsigned step,Memory&m,const Inputs&i,Heap&h){need(m.r32(0x817554)==0,"1451 producedordinary config");if(step==0){const U p=h.allocate(0xa4);need(p!=0,"1451 actualsuccessfulowner");for(U k=0;k<41;++k)h.w32(p+4*k,0);h.w32(p+4,p+4);h.w32(p+8,p+4);h.w32(p+12,p+4);h.w32(p+0x98,0);for(U k=0;k<2;++k){const U d=p+0x18+64*k;h.w32(d,p);h.w32(d+0x1c,0);h.w32(d+0x14,k);h.w32(d+0x24,0);h.w32(d+0x18,0);}return p;}
 const U p=i.cx;emptyhead(h,p);need(h.r32(p+0x14)==0,"1451 produceremptypayload");if(step==1)return reset(h,p);need(step==2||step==3,"1451 exactproducerstep");need(i.dx==step-2,"1451 real408B50 selector");const U d=p+0x18+64*i.dx;need(h.r32(d+0x1c)==0,"1451 noalreadyacquiredref");if(h.r32(p+0x98)==0)(void)reset(h,p);h.w32(d+0x1c,h.r32(d+0x1c)+1);h.w32(p+0x98,h.r32(p+0x98)+1);return d;
}
U fun_00521e70(Memory&m,const Inputs&,Heap&h){
 for(U a:{0xa39ef0u,0xa39ef4u,0xa39f00u,0xa39efcu})need(m.r32(a)==0,"1451 excludedoptionalreleasegraph");
 const U p=m.r32(0xa39f04),a=m.r32(0xa39f08),b=m.r32(0xa39f0c);need(p&&a==p+0x18&&b==p+0x58&&h.r32(a)==p&&h.r32(b)==p,"1451 coherentactualowner/interiorrefs");need(h.r32(a+0x1c)==1&&h.r32(b+0x1c)==1&&h.r32(p+0x98)==2,"1451 producedtwoactualreferences");emptyhead(h,p);need(h.r32(p+0x14)==0,"1451 actualemptyowner payload");
 m.w32(0xa39ef8,0);release_ref(h,a);m.w32(0xa39f08,0);release_ref(h,b);m.w32(0xa39f0c,0);
 //408760 emptylist: no unlink, no nodeallocation and nointeriorfree.
 for(U d:{a,b}){h.w32(d+0x28,0);h.w32(d+0x34,0xfffffc17);h.w32(d+0x38,h.r32(d+0x34));h.w32(d+0x30,0);reset_descriptor(h,d);}h.w32(p+0x4c,h.r32(p+0x4c)+h.r32(p+0x14));
 const U result=h.release(p);m.w32(0xa39f04,0);m.w32(0xa39ef0,0);return result;
}
}
