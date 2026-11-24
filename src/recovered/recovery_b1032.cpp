#include "recovered/recovery_b1032.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::b1032 {
namespace {void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}}
unsigned run(Memory&m,const Inputs&i,Heap&h,unsigned root){
 const unsigned p=i.cx;const bool owned_self=root==0x1b56a0u;
 const auto r=[&](unsigned a){return owned_self?h.r32(a):m.r32(a);};
 const auto w=[&](unsigned a,unsigned x){if(owned_self)h.w32(a,x);else m.w32(a,x);};
 const auto b=[&](unsigned a,unsigned x){if(owned_self)h.w8(a,x);else m.w8(a,x);};
 const auto rb=[&](unsigned a){return owned_self?h.r8(a):m.r8(a);};
 unsigned last=0u;const auto release=[&](unsigned a){need(a!=0u,"1032 positive genuine owned block");last=h.release(a);need(last!=0u,"1032 successful actual HeapFree");};
 const auto clear=[&](unsigned off,unsigned vt,bool dynamic){const unsigned q=p+off;need(r(q)==vt&&r(q+4u)!=0u&&rb(q+13u)==1u,"1032 authentic vector Clear and owned nonempty backing");if(dynamic)w(q+16u,0u);release(r(q+4u));w(q+4u,0u);b(q+13u,0u);w(q+8u,0u);};
 const auto holders=[&](unsigned off,bool zero){const unsigned n=r(p+off+16u),table=r(p+off+4u);need(n>=1u&&n<=4u,"1032 positive holder count");for(unsigned j=0;j<n;++j){const unsigned owner=h.r32(table+j*4u);need(owner!=0u,"1032 positive holder owner");release(h.r32(owner));if(zero)h.w32(owner,0u);release(owner);}};
 if(root==0x1ad310u){holders(0x44u,true);clear(0x44u,0x791e7cu,true);w(p+0x18u,0u);w(p+0x1cu,0u);w(p+0x20u,640u);w(p+0x24u,400u);holders(0x2cu,true);clear(0x2cu,0x791e9cu,true);need(r(p+0x10u)==0u,"1032 auxiliary object vector has no polymorphic children");clear(0u,0x791ebcu,true);return last;}
 if(root==0x1af850u){w(p,0x791ffcu);holders(0x30u,false);clear(0x30u,0x79200cu,true);need(r(p+0x28u)==0u,"1032 auxiliary object vector reserved storage only");clear(0x18u,0x79202cu,true);clear(8u,0x790e98u,false);for(unsigned off:{0x30u,0x18u,8u}){w(p+off,off==0x30u?0x79206cu:off==0x18u?0x79204cu:0x790e98u);need(r(p+off+4u)==0u,"1032 Clear already consumed all backing ownership");b(p+off+13u,0u);w(p+off+8u,0u);}return 0u;}
 if(root==0x1b3930u||owned_self){w(p,0x792188u);need(r(p+0x18u)==0u&&r(p+0x38u)==0u,"1032 reserved child vector and no external parser cache");clear(8u,0x79223cu,true);for(unsigned off:{0x30u,0x2cu,0x24u,0x20u}){release(r(p+off));w(p+off,0u);}need(r(p+0xcu)==0u,"1032 original final backing load is full EAX zero");w(p+8u,0x79225cu);b(p+0x15u,0u);w(p+0x10u,0u);if(owned_self){need((i.arg[0]&1u)!=0u,"1032 actual deleting destructor flag");release(p);return p;}return 0u;}
 need(root==0x267900u,"1032 exact selected root");const unsigned n=r(p+0x650u),table=r(p+0x644u);need(n>=1u&&n<=4u,"1032 positive nested content graph");
 for(unsigned j=0;j<n;++j){const unsigned child=h.r32(table+j*4u);h.w32(child+0x1a4u,0x7944ecu);const unsigned holders=h.r32(child+0x1a8u),count=h.r32(holders-4u);need(h.r8(child+0x1b1u)==1u&&count>=1u&&count<=4u,"1032 authentic owned cookie array");for(unsigned k=count;k>0u;--k){const unsigned slot=holders+(k-1u)*4u;release(h.r32(slot));h.w32(slot,0u);}release(holders-4u);h.w32(child+0x1a8u,0u);h.w8(child+0x1b1u,0u);h.w32(child+0x1acu,0u);h.w32(child+0x188u,0x7944ccu);need(h.r8(child+0x195u)==1u,"1032 positive raw child backing ownership");release(h.r32(child+0x18cu));h.w32(child+0x18cu,0u);h.w8(child+0x195u,0u);h.w32(child+0x190u,0u);release(child);}
 clear(0x640u,0x79444cu,true);for(unsigned off:{0x28b8u,0x28a0u}){const unsigned count=r(p+off+16u),array=r(p+off+4u);need(count>=1u&&count<=4u,"1032 positive raw content rows");for(unsigned j=0;j<count;++j)release(h.r32(array+j*4u));clear(off,off==0x28b8u?0x78955cu:0x79440cu,true);}return last;
}
}
