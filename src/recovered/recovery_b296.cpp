#include "recovery_b296.hpp"
#include <cstdint>
#include <limits>
#include <stdexcept>
namespace ra2::recovered::recovery_b296 {
namespace {
void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint32_t add(std::uint32_t a,std::uint32_t b){require(a<=std::numeric_limits<std::uint32_t>::max()-b,"B296 excludes address wrap");return a+b;}
std::uint32_t bytes(Heap& h,std::uint32_t p,std::uint32_t limit){require(p,"B296 requires nonnull string");for(std::uint32_t n=0;n<limit;++n)if(h.r8(add(p,n))==0)return n;throw std::domain_error("B296 string lacks bounded NUL");}
std::uint32_t clone_lower(Heap& h,std::uint32_t source,std::uint32_t n){
 auto p=h.allocate(n+1u);require(p,"B296 original clone allocation must succeed");
 for(std::uint32_t k=0;k<n;++k){auto c=h.r8(add(source,k));if(c>='A'&&c<='Z')c=static_cast<std::uint8_t>(c+0x20u);h.w8(add(p,k),c);}h.w8(add(p,n),0);return p;
}
}
// Finite positive route for original 0x5ad3d0: one or two nonnull entries,
// long printable ASCII query/entries equal after mode-zero ASCII lowercasing.
std::uint32_t rva_001ad3d0(Memory& m,const Inputs& i,Heap& h){
 const auto collection=i.cx,query_object=i.arg[0];
 require(collection&&query_object&&(i.arithmetic_flags&0x400u)==0,"B296 requires collection, query object and DF clear");
 const auto count=m.r32(add(collection,0x10u));
 require(count==1u||count==2u,"B296 bounds collection count to one or two");
 require(m.r32(0x00b10530u)==0,"B296 closes the actual ASCII comparator on mode-zero branch");
 const auto vector=m.r32(add(collection,4u));require(vector,"B296 requires vector storage");
 const auto query=m.r32(query_object);require(query,"B296 requires nonnull query characters");
 const auto n=bytes(h,query,4098u);require(n>=1017u&&n<=1032u,"B296 query must be long ordinary-heap ASCII");
 for(std::uint32_t k=0;k<n;++k){auto c=h.r8(add(query,k));require(c>=0x20u&&c<=0x7eu,"B296 route uses printable ASCII");}
 for(std::uint32_t index=0;index<count;++index){
  // The original re-enters 0x5ad3f0 after every miss, so it reclones the
  // original query object for each candidate rather than retaining a clone.
  auto normalized_query=clone_lower(h,query,n);
  const auto entry_object=m.r32(add(vector,index*4u));require(entry_object,"B296 requires nonnull entry object");
  const auto entry_chars=m.r32(entry_object);require(entry_chars,"B296 requires nonnull entry characters");
  const auto entry_n=bytes(h,entry_chars,4098u);require(entry_n==n,"B296 route requires equal bounded lengths");
  for(std::uint32_t k=0;k<n;++k){auto c=h.r8(add(entry_chars,k));require(c>=0x20u&&c<=0x7eu,"B296 route uses printable ASCII");}
  // The native second clone writes its temporary pointer into the root's
  // argument stack word; the destructor clears that word on both outcomes.
  const auto normalized_entry=clone_lower(h,entry_chars,n);i.arg[0]=normalized_entry;
  bool equal=true;for(std::uint32_t k=0;k<=n;++k)if(h.r8(add(normalized_query,k))!=h.r8(add(normalized_entry,k))){equal=false;break;}
  require(h.release(normalized_entry)!=0,"B296 entry clone free must succeed");i.arg[0]=0;
  require(h.release(normalized_query)!=0,"B296 per-iteration query clone free must succeed");
  if(equal)return entry_object;
 }
 return 0;
}
}
