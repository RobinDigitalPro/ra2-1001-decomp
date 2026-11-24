#include "recovered/recovery_b1615.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1615 {
namespace {
using Byte=std::uint8_t;
void need(bool b){if(!b)throw std::domain_error("B1615 finite ordinary-heap short-string matching query");}
template<std::size_t N> void literal(Memory&m,U p,const char(&value)[N]){
 for(std::size_t k=0;k<N;++k)need(m.r8(p+U(k))==U(static_cast<unsigned char>(value[k])));
}
U allocate(Heap&h,U size){const U p=h.allocate(size);need(p!=0u);return p;}
void destroy(Heap&h,U&holder){
 if(holder){need(h.release(holder)!=0u);holder=0u;}
}
U copy_heap(Heap&h,U from,U bytes){
 const U to=allocate(h,bytes);
 for(U k=0;k<bytes;++k)h.w8(to+k,h.r8(from+k));
 return to;
}
U heap_length(Heap&h,U from,U bound){
 for(U k=0;k<bound;++k)if(h.r8(from+k)==0u)return k;
 throw std::domain_error("B1615 produced string lacks its bounded NUL");
}
bool equal(Heap&h,U left,U right){
 for(U k=0;k<9u;++k){const U a=h.r8(left+k),b=h.r8(right+k);if(a!=b)return false;if(!a)return true;}
 throw std::domain_error("B1615 comparison exceeds produced nine-byte string");
}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 need(root==0x3384e0u&&(i.cx&255u)==0u);
 //738508/50F skips the entire optional INI initialization. No invented
 // initialization marker or B0E600 value is required by this selected branch.
 need(m.r32(0xa255c8u)!=4u&&m.r32(0xb0e5c8u)==2u&&m.r32(0xb100b4u)==1u);
 need(m.r32(0x817554u)==0u&&m.r32(0x81776cu)==1u);
 literal(m,0x7e6b88u,"Lob_33_");literal(m,0x7b994cu,"%d");
 const U records=m.r32(0xb0e5d0u);
 need(records&&std::uint64_t(records)+2u*0x10cu<=0x100000000ull);
 literal(m,records+0x34u,"other");literal(m,records+0x10cu+0x34u,"Lob_33_1");
 for(U k=0;k<2u*0x10cu;++k)(void)m.r8(records+k);
 // Actual75AEC0/default%d1 produces the local ASCII digit and NUL before
 // allocation. This finite integer recipe never invokes the old small-CRT model.
 std::array<Byte,16> decimal_scratch;
 decimal_scratch[0]=Byte('0'+m.r32(0xb100b4u));decimal_scratch[1]=0u;
 U decimal=0u;decimal=allocate(heap,2u);heap.w8(decimal,0u);
 for(U k=0;k<2u;++k)heap.w8(decimal+k,decimal_scratch[k]);
 // Actual759260 constructs the seven-byte prefix, including its NUL.
 U prefix=0u;prefix=allocate(heap,8u);heap.w8(prefix,0u);
 for(U k=0;k<8u;++k)heap.w8(prefix+k,m.r8(0x7e6b88u+k));
 // Actual759B00 first clones the prefix, builds a joined temporary, frees
 // that first clone, then allocates the output clone before freeing the join.
 U prefix_clone=copy_heap(heap,prefix,8u);
 const U prefix_length=heap_length(heap,prefix_clone,8u),digits=heap_length(heap,decimal,2u);
 need(prefix_length==7u&&digits==1u);
 U joined=allocate(heap,prefix_length+digits+1u);
 for(U k=0;k<=prefix_length;++k)heap.w8(joined+k,heap.r8(prefix_clone+k));
 for(U k=0;k<=digits;++k)heap.w8(joined+prefix_length+k,heap.r8(decimal+k));
 destroy(heap,prefix_clone);
 U output=0u;output=copy_heap(heap,joined,prefix_length+digits+1u);
 destroy(heap,joined);
 destroy(heap,prefix);destroy(heap,decimal);
 // The original REP STOSD initializes this actual268-byte local record.
 // Each iteration then copies all268 public bytes before examining name+34.
 std::array<Byte,0x10c> record{};
 for(U index=0u;index<m.r32(0xb0e5c8u);++index){
  for(U k=0;k<record.size();++k)record[k]=Byte(m.r8(records+index*U(record.size())+k));
  U length=0u;while(length<record.size()-0x34u&&record[0x34u+length])++length;
  need(length<record.size()-0x34u&&length==(index?8u:5u));
  U name=0u;name=allocate(heap,length+1u);heap.w8(name,0u);
  for(U k=0;k<=length;++k)heap.w8(name+k,record[0x34u+k]);
  const bool matches=equal(heap,name,output);
  if(matches){destroy(heap,name);destroy(heap,output);return index;}
  destroy(heap,name);
 }
 // Excluded by the exact public names above, rather than forced return data.
 destroy(heap,output);throw std::domain_error("B1615 expected positive name was not found");
}
}
