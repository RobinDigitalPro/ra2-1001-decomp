#include "recovered/recovery_b1218.hpp"
#include <string>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1218 {namespace{
void need(bool x){if(!x)throw std::domain_error("1218 genuine positive type deselection / highest group cost");}
std::string name(Memory&m,unsigned p){std::string s;for(unsigned k=0;k<25u;++k){const unsigned c=m.r8(p+k);if(!c)return s;need(c>='0'&&c<='Z');s+=char(c);}throw std::domain_error("1218 bounded constructor TypeID");}
struct Graph{Memory&m;Heap&h;Observation&z;
 unsigned allocate(unsigned n){const unsigned p=h.allocate(n);need(p);++z.allocations;return p;}
 unsigned header(unsigned vt){const unsigned p=allocate(24u);h.w32(p,vt);h.w32(p+4u,0u);h.w32(p+8u,0u);h.w8(p+12u,1u);h.w8(p+13u,0u);h.w32(p+16u,0u);h.w32(p+20u,10u);return p;}
 void append(unsigned p,unsigned v){const unsigned n=h.r32(p+16u);need(n<10u);if(!n){h.w8(p+12u,0u);const unsigned a=allocate(40u);h.w8(p+12u,1u);h.w32(p+4u,a);h.w32(p+8u,10u);h.w8(p+13u,1u);++z.virtual_callbacks;}h.w32(h.r32(p+4u)+n*4u,v);h.w32(p+16u,n+1u);++z.insertions;}
 void destroy(unsigned p,unsigned base){++z.virtual_callbacks;h.w32(p,base);need(h.release(h.r32(p+4u)));++z.frees;h.w32(p+4u,0u);h.w8(p+13u,0u);h.w32(p+8u,0u);need(h.release(p));++z.frees;}
 unsigned type(unsigned actor){need(m.r32(actor)==0x78e540u&&m.r32(0x78e5c4u)==0x505da0u);++z.virtual_callbacks;const unsigned p=m.r32(actor+0x5a8u);need(m.r32(p)==0x78ea78u);return p;}
};
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){need(root==0x2ebe70u||root==0x2ed400u);Graph g{m,h,z};
 if(root==0x2ebe70u){need(m.r8(0xaa8db9u)==0u&&m.r32(0xa255c8u)==0u&&m.r32(0x821cacu)==base+0x1000u&&m.r32(0xa1e0e4u)==base+0xa000u&&m.r8(0x81a820u+0x1198u)==0u);const auto filter=name(m,i.cx);const unsigned temp=g.header(0x78579cu),n=m.r32(base+0x1db0u);need(n>=3u&&n<=6u);for(unsigned j=0;j<n;++j){const unsigned actor=m.r32(0xaa6100u+12u*j);need(actor&&(m.r8(actor+20u)&1u)&&m.r8(actor+0x7du)==1u&&m.r8(m.r32(actor+0x1b4u)+0x135u)==1u);++z.predicate_calls;if(name(m,g.type(actor)+0x24u)==filter)g.append(temp,actor);}
  const unsigned matched=h.r32(temp+16u);need(matched&&matched<n&&m.r32(0xa288a0u)==0x788b7cu);for(unsigned j=0;j<matched;++j){const unsigned actor=h.r32(h.r32(temp+4u)+4u*j);need(m.r8(actor+0x77u)==1u);++z.virtual_callbacks; // Actual Inf+144=5CB480.
   const unsigned a=m.r32(0xa288a4u),count=m.r32(0xa288b0u);unsigned k=0;for(;k<count&&h.r32(a+4u*k)!=actor;++k){}need(k<count);++z.virtual_callbacks; // Actual788B7C+10 Find40CDF0.
   m.w32(0xa288b0u,count-1u);for(unsigned t=k;t+1u<count;++t)h.w32(a+4u*t,h.r32(a+4u*t+4u));m.w8(actor+0x77u,0u);++z.removals;
  }g.destroy(temp,0x7857fcu);return temp; // Actual40BBC0 returns former header address after freeing it.
 }
 need(i.dx==0u&&i.arg[0]==0x7fffffffu&&i.arg[1]==base+0xf000u&&m.r32(0xaa8dc0u)==i.cx&&h.r32(i.cx)==0x78579cu);const unsigned n=h.r32(i.cx+16u),input=h.r32(i.cx+4u);need(n>=3u&&n<=6u);const unsigned names=g.header(0x7915ccu);std::vector<std::string>ids;std::vector<unsigned>rawids;
 for(unsigned j=0;j<n;++j){const unsigned p=g.type(h.r32(input+4u*j))+0x24u;const auto s=name(m,p);unsigned k=0;for(;k<ids.size()&&ids[k]!=s;++k){}if(k==ids.size()){ids.push_back(s);rawids.push_back(p);g.append(names,p);++z.groupings;}}
 need(ids.size()>=2u&&ids.size()<=3u);const unsigned scores=g.header(0x788a94u);for(unsigned j=0;j<ids.size();++j)g.append(scores,0u);ra2::platform::x87::State fp;fp.image=ra2::platform::x87::capture_host();
 for(unsigned j=0;j<n;++j){const unsigned actor=h.r32(input+4u*j),type=g.type(actor),house=m.r32(actor+0x1b4u);const auto s=name(m,type+0x24u);unsigned k=0;for(;k<ids.size()&&ids[k]!=s;++k){}need(k<ids.size()&&m.r32(m.r32(house+0x34u)+0x114u)==0x3f800000u);const unsigned cost_type=g.type(actor);need(cost_type==type);const unsigned cost=m.r32(cost_type+0x550u);need(cost>=1u&&cost<=9000u);z.virtual_callbacks+=3u;++z.cost_calls; // Type+84 Cost,Type+2C kind16,Type+AC rawCost.
  fp.load32(0x3f800000u);const unsigned factor=fp.pop32();fp.load_integer32(cost);fp.multiply32(factor);fp.load_control_masked(0xe7fu);const unsigned actual=unsigned(fp.pop_integer64());need(actual==cost);const unsigned a=h.r32(scores+4u)+k*4u;h.w32(a,h.r32(a)+actual);
 }
 unsigned best=0u,max=0u;for(unsigned k=0;k<ids.size();++k){const unsigned v=h.r32(h.r32(scores+4u)+k*4u);if(v>max){max=v;best=k;}}need(max>0u);m.w32(i.arg[1],max);const unsigned output=g.allocate(100u);for(unsigned j=0;j<=ids[best].size();++j)h.w8(output+j,j==ids[best].size()?0u:unsigned(static_cast<unsigned char>(ids[best][j])));++z.key_copies;g.destroy(names,0x7915ecu);g.destroy(scores,0x7889d4u);ra2::platform::x87::restore_host(fp.image);return output;
}
}
