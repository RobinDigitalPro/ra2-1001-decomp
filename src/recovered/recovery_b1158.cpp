#include "recovered/recovery_b1158.hpp"
#include "recovered/name_hash.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::b1158 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string heap_z(Heap&h,unsigned p){need(p!=0u,"1158 nonnull owned text");std::string s;for(unsigned n=0;n<32u;++n){const auto c=h.r8(p+n);if(!c)return s;s+=char(c);}throw std::domain_error("1158 owned text bound");}
std::string pe_z(Memory&m,unsigned p){need(p!=0u,"1158 nonnull original literal");std::string s;for(unsigned n=0;n<32u;++n){const auto c=m.r8(p+n);if(!c)return s;s+=char(c);}throw std::domain_error("1158 original literal bound");}
unsigned hash(const std::string&s){return ini_name_hash(reinterpret_cast<const unsigned char*>(s.data()),s.size(),nullptr);}
int signed_key(unsigned k){return k<=0x7fffffffu?int(k):-1-int(0xffffffffu-k);}
struct Graph {
 Memory&m;Heap&h;unsigned ini;
 unsigned count()const{return m.r32(ini+0x24u);}
 unsigned table()const{return m.r32(ini+0x20u);}
 unsigned search(unsigned key){need(count()<=2u,"1158 at most two authentic sections");if(!count())return 0u;need(m.r8(ini+0x2cu)==1u,"1158 authentic prior read has sorted the section index");unsigned first=table();int n=int(count());while(n>0){const int half=n/2;const auto row=first+unsigned(half)*8u;const auto other=h.r32(row);if(signed_key(key)<signed_key(other))n=half;else if(key==other)return row;else{first=row+8u;n-=half+1;}}return 0u;}
 unsigned member(unsigned key){if(!count())return 0u;const auto old=m.r32(ini+0x30u);if(old&&h.r32(old)==key)return old;const auto row=search(key);if(row)m.w32(ini+0x30u,row);return row;}
 unsigned named(const std::string&s){const auto key=hash(s);if(!member(key))return 0u;const auto row=member(key);need(row,"1158 original repeated lookup stable");return h.r32(row+4u);}
 unsigned key_count(const std::string&s){const auto section=named(s);return section?h.r32(section+0x30u):0u;}
 std::string key_at(const std::string&s,unsigned n){const auto section=named(s);need(section&&n<h.r32(section+0x30u),"1158 positive catalog key position");auto node=h.r32(section+0x18u);for(unsigned j=0;j<n;++j)node=h.r32(node+4u);need(h.r32(node+4u)&&h.r32(node+8u),"1158 actual populated key ring");return heap_z(h,h.r32(node+0xcu));}
 std::string read_value(const std::string&section_name,const std::string&key_name){const auto section=named(section_name);if(!section)return {};need(h.r32(section+0x30u)==1u&&h.r8(section+0x38u)==1u,"1158 prior positive read sorted selected one-key index");const auto row=h.r32(section+0x3cu);need(row==h.r32(section+0x2cu),"1158 actual key-cache pointer");if(h.r32(row)!=hash(key_name))return {};const auto node=h.r32(row+4u);const auto p=h.r32(node+0x10u);return p?heap_z(h,p):std::string{};}
 void link(unsigned a,unsigned v){if(a==ini+0xcu||a==ini+0x1cu)m.w32(a,v);else h.w32(a,v);}
 void release(unsigned p){need(p!=0u,"1158 complete genuine owned identity");need(h.release(p)!=0u,"1158 forwarded actual successful HeapFree BOOL");}
 void destroy(unsigned s){
  need(h.r32(s)==0x78eba4u&&m.r32(0x78eba4u)==0x50feb0u&&m.r32(0x78eb9cu)==0x50fe00u,"1158 genuine section/node deleting vtables");
  need(h.r32(s+0x40u)==0u&&h.r32(s+0x30u)==1u,"1158 one real key and null parser chain");
  const auto node=h.r32(s+0x18u),head=s+0x14u,tail=s+0x20u;
  need(h.r32(node)==0x78eb9cu&&h.r32(node+4u)==tail&&h.r32(node+8u)==head&&h.r32(tail+8u)==node,"1158 exact live one-node key graph");
  need(h.r32(node+0x14u)==0u&&h.r32(node+0x18u)==0u,"1158 original node ownership flags/chain");
  // 50FCA0 first releases the section name, then calls the actual 50FE00
  // deleting node target with flag1. Full bodies are pinned, not invoked here.
  h.w32(s,0x78eba4u);release(h.r32(s+0xcu));h.w32(s+0xcu,0u);
  h.w32(node,0x78eb9cu);release(h.r32(node+0xcu));h.w32(node+0xcu,0u);release(h.r32(node+0x10u));h.w32(node+0x10u,0u);h.w32(node+0x18u,0u);h.w32(node,0x785afcu);
  h.w32(head+4u,tail);h.w32(tail+8u,head);h.w32(node+8u,0u);h.w32(node+4u,0u);release(node);
  release(h.r32(s+0x2cu));h.w32(s+0x2cu,0u);h.w32(s+0x30u,0u);h.w32(s+0x34u,0u);h.w8(s+0x38u,0u);h.w32(s+0x3cu,0u);
  // The second original index teardown sees NULL; it has no OS heap event.
  h.w32(s+0x10u,0x785af4u);h.w32(tail,0x785afcu);h.w32(head,0x785afcu);h.w32(s,0x785afcu);
  // Newly exercised 50FDD1..FDF8 parent unlink, followed by 50FEB0 flag1
  // ordinary delete. Both neighboring identities remain exact raw pointers.
  const auto next=h.r32(s+4u),prev=h.r32(s+8u);need(next&&prev,"1158 section genuinely linked into parent INI");link(prev+4u,next);link(next+8u,prev);h.w32(s+8u,0u);h.w32(s+4u,0u);release(s);
 }
 void erase(const std::string&name){const auto s=named(name);if(!s)return;const auto row=search(hash(heap_z(h,h.r32(s+0xcu))));need(row,"1158 section's own exact hash lookup");const auto first=table();const auto index=(row-first)/8u;const auto n=count();for(unsigned j=index+1u;j<n;++j){h.w32(first+(j-1u)*8u,h.r32(first+j*8u));h.w32(first+(j-1u)*8u+4u,h.r32(first+j*8u+4u));}m.w32(ini+0x24u,n-1u);h.w32(first+(n-1u)*8u,0u);h.w32(first+(n-1u)*8u+4u,0u);m.w32(ini+0x30u,0u);destroy(s);}
};
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,ra2::platform::x87::State&fp){
 (void)fp;need(root==0x2e3d60u||root==0x1a6c0u||root==0x1061c0u,"1158 reviewed cleanup entry");need(m.r32(i.cx)==0x78db34u&&m.r32(i.cx+0x34u)==0u,"1158 original initialized INI receiver");need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1158 actual ordinary heap route");Graph g{m,h,i.cx};
 if(root==0x2e3d60u){need(m.r32(0x84e548u)==0u,"1158 actual4D24E0 fresh type registry");const auto primary=pe_z(m,m.r32(0x7988f8u));for(unsigned catalog_global:{0x7988f8u,0x798900u,0x7988fcu}){const auto catalog=pe_z(m,m.r32(catalog_global));const auto count=g.key_count(catalog);for(unsigned j=0;j<count;++j){const auto key=g.key_at(catalog,j);const auto target=g.read_value(primary,key);need(target.size()<32u,"1158 actual32-byte bounded text result");g.erase(target);}g.erase(catalog);}return m.r32(0x84e548u);}
 const auto registry=root==0x1a6c0u?0xa27ff8u:0xa1e188u;need(m.r32(registry)==0u,"1158 actual registry constructor count zero");g.erase(pe_z(m,m.r32(root==0x1a6c0u?0x7860d0u:0x78e3f0u)));return 0u;
}
void cleanup(Memory&m,unsigned ini,Heap&h){Graph g{m,h,ini};while(g.count()){const auto s=h.r32(g.table()+4u);g.erase(heap_z(h,h.r32(s+0xcu)));}g.release(g.table());m.w32(ini+0x20u,0u);m.w32(ini+0x24u,0u);m.w32(ini+0x28u,0u);m.w8(ini+0x2cu,0u);m.w32(ini+0x30u,0u);}
}
