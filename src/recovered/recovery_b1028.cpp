#include "recovered/recovery_b1028.hpp"
#include <stdexcept>
namespace ra2::recovered::b1028 {
namespace {
void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}
bool self(unsigned root){return root==0xb1200u||root==0x94ed0u;}
unsigned read(Memory&m,Heap&h,unsigned root,unsigned p){return self(root)?h.r32(p):m.r32(p);}
void put(Memory&m,Heap&h,unsigned root,unsigned p,unsigned x){if(self(root))h.w32(p,x);else m.w32(p,x);}
void byte(Memory&m,Heap&h,unsigned root,unsigned p,unsigned x){if(self(root))h.w8(p,x);else m.w8(p,x);}
void timer_init(Memory&m,unsigned p,unsigned window){m.w32(p,0x7987dcu);m.w32(p+4u,0u);m.w32(p+8u,window);m.w8(p+0xcu,0u);m.w32(p+0x228u,0x3e8u);m.w32(p+0x230u,0x2710u);m.w32(p+0x234u,0x7987f8u);m.w32(p+0x238u,0u);m.w32(p+0x23cu,0u);m.w8(p+0x240u,1u);m.w8(p+0x241u,0u);m.w32(p+0x244u,0u);m.w32(p+0x248u,10u);for(unsigned x:{0x24cu,0x250u,0x254u,0x25cu})m.w32(p+x,0u);m.w8(p+0x258u,0u);}
}
void attach(Memory&m,Heap&h,unsigned root,const Fixture&f,unsigned rows){const unsigned p=f.receiver;const auto&a=f.owners;
 if(root==0xb1200u)h.w32(p+0x20u,a.at(1));
 else if(root==0x94640u||root==0x94ed0u){const unsigned first=self(root)?1u:0u;for(unsigned j=0;j<3u;++j)put(m,h,root,p+(j==0u?0x20u:j==1u?0x18u:0x1cu),a.at(first+j));}
 else if(root==0x2e75f0u){for(unsigned j=0;j<3u;++j){m.w32(0xaa8bd0u+j*8u,a.at(j));m.w32(0xaa8bd4u+j*8u,0u);}}
 else if(root==0x320e90u){m.w32(p+8u,a.at(0));m.w32(p+0xcu,a.at(1));m.w32(p+0x10u,a.at(2));m.w32(p+0x24u,rows);m.w32(p+0x44u,a.back());for(unsigned j=0;j<rows;++j)h.w32(a.back()+j*4u,a.at(3u+j));}
 else {need(root==0x2e0650u,"1028 exact attach root");m.w32(p+0x24cu,a.at(0));m.w32(p+0x250u,rows*3u+5u);m.w32(p+0x254u,rows*7u+11u);m.w8(p+0x258u,1u);m.w32(p+0x25cu,rows*13u+17u);m.w32(p+0x238u,a.back());m.w32(p+0x23cu,rows);m.w8(p+0x241u,1u);m.w32(p+0x244u,rows);for(unsigned j=0;j<rows;++j)h.w32(a.back()+j*4u,a.at(1u+j));}
}
Fixture prepare(Memory&m,Inputs&i,Heap&h,unsigned base,unsigned root,unsigned seed,unsigned window,unsigned rows,const std::vector<unsigned>&requests){Fixture f{};for(unsigned j=0;j<requests.size();++j){const auto p=h.allocate(requests[j]);f.owners.push_back(p);for(unsigned k=0;k<requests[j];++k)h.w8(p+k,seed*37u+j*73u+k*131u+(k>>3u));}f.receiver=self(root)?f.owners.at(0):base+0x400u;i.cx=f.receiver;
 if(root==0xb1200u){h.w32(i.cx,0x78bbe4u);h.w8(i.cx+0x18u,0u);h.w32(i.cx+0x1cu,0u);i.arg[0]=(seed*2u+0x10001u)|1u;}
 else if(root==0x94640u||root==0x94ed0u){put(m,h,root,i.cx,0x789704u);put(m,h,root,i.cx+4u,0x7896ecu);put(m,h,root,i.cx+8u,0u);if(self(root))i.arg[0]=(seed*2u+0x20001u)|1u;}
 else if(root==0x320e90u){m.w32(i.cx,0x79a198u);m.w32(i.cx+0x2cu,0x79a1a8u);m.w32(i.cx+0x30u,0u);m.w32(i.cx+0x34u,0u);m.w8(i.cx+0x38u,1u);m.w8(i.cx+0x39u,0u);m.w32(i.cx+0x3cu,0u);m.w32(i.cx+0x40u,10u);}
 else if(root==0x2e0650u)timer_init(m,i.cx,window);
 else need(root==0x2e75f0u,"1028 exact prepare roots");
 attach(m,h,root,f,rows);return f;
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&api,unsigned root,const Fixture&f){const unsigned p=i.cx;need(p==f.receiver,"1028 exact prepared receiver");unsigned last=0u;const auto release=[&](unsigned a){need(a!=0u,"1028 positive nonempty ownership route");last=h.release(a);need(last!=0u,"1028 genuine successful HeapFree");};
 if(root==0xb1200u){need((i.arg[0]&1u)!=0u&&h.r8(p+0x18u)==0u&&h.r32(p+0x1cu)==0u,"1028 deleting scalar owner with no COM surface");h.w32(p,0x78bbe4u);release(h.r32(p+0x20u));h.w32(p+0x20u,0u);h.w32(p+0x1cu,0u);h.w32(p,0x786020u);release(p);return p;}
 if(root==0x94640u||root==0x94ed0u){need(read(m,h,root,p+8u)==0u,"1028 triple owned buffers without COM stream");put(m,h,root,p,0x789704u);put(m,h,root,p+4u,0x7896ecu);for(unsigned off:{0x20u,0x18u,0x1cu}){release(read(m,h,root,p+off));put(m,h,root,p+off,0u);}if(root==0x94ed0u){need((i.arg[0]&1u)!=0u,"1028 selected deleting flag");release(p);return p;}return last;}
 if(root==0x2e75f0u){for(unsigned j=0;j<3u;++j){need(m.r32(0xaa8bd4u+j*8u)==0u,"1028 no virtual provider side route");release(m.r32(0xaa8bd0u+j*8u));m.w32(0xaa8bd0u+j*8u,0u);}return last;}
 if(root==0x320e90u){need(m.r32(p+0x2cu)==0x79a1a8u&&m.r32(p+0x30u)==0u,"1028 original constructed empty auxiliary vector");m.w32(p,0x79a198u);m.w32(p+0x3cu,0u);m.w8(p+0x39u,0u);m.w32(p+0x34u,0u);for(unsigned off:{0xcu,8u,0x10u})release(m.r32(p+off));const unsigned n=m.r32(p+0x24u),table=m.r32(p+0x44u);need(n>=1u&&n<=4u,"1028 populated row ownership");for(unsigned j=0;j<n;++j)release(h.r32(table+j*4u));release(table);m.w32(p+0x2cu,0x79a178u);m.w8(p+0x39u,0u);m.w32(p+0x34u,0u);m.w32(p,0x793cd4u);return last;}
 need(root==0x2e0650u&&m.r32(p+4u)==0u&&m.r32(p+0x234u)==0x7987f8u,"1028 actual timer and original vector fields");m.w32(p,0x7987dcu);need(api.kill(reinterpret_cast<HWND>(std::uintptr_t(m.r32(p+8u))),0x54544950u)!=FALSE,"1028 actual positive KillTimer");release(m.r32(p+0x24cu));for(unsigned off:{0x24cu,0x250u,0x254u,0x25cu})m.w32(p+off,0u);m.w8(p+0x258u,0u);const unsigned n=m.r32(p+0x244u),table=m.r32(p+0x238u);need(n>=1u&&n<=4u&&m.r8(p+0x241u)!=0u,"1028 populated owned timer row vector");for(unsigned j=0;j<n;++j)release(h.r32(table+j*4u));m.w32(p+0x244u,0u);release(table);m.w32(p+0x238u,0u);m.w8(p+0x241u,0u);m.w32(p+0x23cu,0u);
 // Original _free(nullptr) performs no HeapFree, then the base destructor
 // loads the already-cleared vector backing pointer into full EAX.
 for(unsigned off:{0x24cu,0x250u,0x254u,0x25cu})m.w32(p+off,0u);m.w8(p+0x258u,0u);m.w32(p+0x234u,0x798818u);m.w8(p+0x241u,0u);m.w32(p+0x23cu,0u);return 0u;
}
}
