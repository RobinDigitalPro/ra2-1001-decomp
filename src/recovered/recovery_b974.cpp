#include "recovered/recovery_b974.hpp"
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b974 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
U flag_offset(U root){if(root==0x000f1350u)return 0x11d8u;if(root==0x000f14f0u)return 0x11dcu;if(root==0x000f1690u)return 0x11e0u;throw std::domain_error("B974 root outside three reviewed entries");}
std::string text(const Memory&m,U p){need(p,"B974 nonnull string");std::string s;for(U k=0;k<128u;++k){const U c=m.r8(p+k);if(!c)return s;need(c<0x80u,"B974 positive route requires ASCII names");s.push_back(char(c));}throw std::domain_error("B974 bounded NUL string");}
char lower_ascii(char c){return c>='A'&&c<='Z'?char(c+('a'-'A')):c;}
bool equal_ascii(const std::string&a,const std::string&b){if(a.size()!=b.size())return false;for(U k=0;k<a.size();++k)if(lower_ascii(a[k])!=lower_ascii(b[k]))return false;return true;}
U name_index(const Memory&m,const std::string&q){const U count=m.r32(0x00a1e048u),table=m.r32(0x00a1e03cu);need(count>0u&&count<=32u&&table,"B974 bounded original name table");for(U j=0;j<count;++j){const U record=m.r32(table+4u*j);if(equal_ascii(q,text(m,record+0x64u))||equal_ascii(q,text(m,record+0x24u)))return m.r32(record+0xb8u);}throw std::domain_error("B974 exact positive existing name-table hit required");}
bool prerequisites(const Memory&m,U candidate,U vector,U candidate_table,U candidate_count){const U n=m.r32(candidate+0x570u),indices=m.r32(candidate+0x564u),data=m.r32(vector+4u),count=m.r32(vector+0x10u);need(n>=1u&&n<=3u&&indices,"B974 positive finite prerequisite list");need(data&&count>=1u&&count<=8u,"B974 bounded prerequisite vector");for(U j=0;j<n;++j){const auto index=global_b26::s32(m.r32(indices+4u*j));need(index>=0&&U(index)<candidate_count,"B974 callback-free nonnegative valid prerequisite index");const U expected=m.r32(candidate_table+4u*U(index));bool found=false;for(U k=0;k<count;++k)if(m.r32(data+4u*k)==expected){found=true;break;}if(!found)return false;}return true;}
}
U run(Memory&m,const Inputs&i,Heap&h,U root,Observation&o){
 const U flag=flag_offset(root),context=i.cx,output=i.arg[0],vector=i.arg[1];need(context&&output&&vector,"B974 nonnull context/output/prerequisite vector");
 need(m.r32(0x0078d76cu)==0x004d97c0u&&m.r32(0x0078d790u)==0x004d9730u,"B974 exact original read-only append/clear target provenance");
 need(m.r32(0x00b10530u)==0u,"B974 verified ASCII comparison mode");const U name_holder=m.r32(context+0x34u);need(name_holder,"B974 query-name holder");const auto query=text(m,name_holder+0x98u);const U bit_index=name_index(m,query);need(bit_index<32u,"B974 shift range 0..31");const U bit=U(1u)<<bit_index;
 const U count=m.r32(0x00a1e018u),table=m.r32(0x00a1e00cu),level=m.r32(context+0x11cu);need(count>=1u&&count<=8u&&table,"B974 bounded candidate table");
 o={};o.selected.reserve(8u);
 for(U j=0;j<count;++j){const U candidate=m.r32(table+4u*j);need(candidate,"B974 nonnull candidate record");if(!(m.r32(candidate+0x5e8u)&bit))continue;if(global_b26::s32(m.r32(candidate+flag))<=0)continue;if(global_b26::s32(m.r32(candidate+0x55cu))>global_b26::s32(level))continue;if(!prerequisites(m,candidate,vector,table,count))continue;
  if(!o.temporary){o.temporary=h.allocate(40u);need(o.temporary,"B974 successful 10-cell temporary allocation");}
  need(o.selected.size()<8u,"B974 candidate result bound");h.w32(o.temporary+4u*U(o.selected.size()),candidate);o.selected.push_back(candidate);
 }
 need(!o.selected.empty()&&o.selected.size()<=8u,"B974 positive selected-candidate route");
 // The original output starts as empty ownership state, then clear-helper
 // 0x4D9730 sees a null pointer and does not free anything.
 m.w32(output,0x0078d784u);m.w32(output+4u,0);m.w32(output+8u,0);m.w8(output+0x0cu,1u);m.w8(output+0x0du,0u);
 m.w32(output+8u,10u);o.output=h.allocate(40u);need(o.output,"B974 successful 10-cell output allocation");m.w32(output+4u,o.output);m.w8(output+0x0du,1u);
 // The original copies all ten capacity cells; the final eight rounded
 // allocation bytes remain untouched in the output block.
 for(U j=0;j<10u;++j)h.w32(o.output+4u*j,h.r32(o.temporary+4u*j));
 m.w32(output+0x10u,U(o.selected.size()));m.w32(output+0x14u,10u);m.w32(output,0x0078d764u);
 for(U j=0;j<o.temporary_before_free.size();++j)o.temporary_before_free[j]=std::uint8_t(h.r8(o.temporary+j));
 need(h.release(o.temporary)!=0u,"B974 successful temporary free after output copy");return output;
}
}
