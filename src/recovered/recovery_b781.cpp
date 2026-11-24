#include "recovery_b781.hpp"

#include "recovered/leaf_memory.hpp"
#include <array>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b781 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint32_t heap16(const Heap&h,std::uint32_t p){return h.r8(p)|(std::uint32_t(h.r8(p+1u))<<8);}
std::string read_ansi(const Memory&m,std::uint32_t p,std::uint32_t bound=64){
 need(p,"B781 requires non-null string input");std::string s;
 for(std::uint32_t k=0;k<bound;++k){const auto c=static_cast<char>(m.r8(p+k));if(!c)return s;s.push_back(c);}
 throw std::domain_error("B781 bounded ANSI input is not terminated");
}
std::uint32_t copy_ansi(Heap&h,const std::string&s){
 const auto p=h.allocate(static_cast<std::uint32_t>(s.size()+1));need(p,"B781 excludes allocator failure");
 for(std::uint32_t k=0;k<=s.size();++k)h.w8(p+k,k<s.size()?static_cast<unsigned char>(s[k]):0u);
 return p;
}
std::uint32_t copy_wide(Heap&h,const Memory&m,std::uint32_t source,std::uint32_t bytes){
 need(bytes==6,"B781 positive table value is exactly two UTF-16 characters plus NUL");
 const auto p=h.allocate(bytes);need(p,"B781 excludes allocator failure");
 for(std::uint32_t k=0;k<bytes;++k)h.w8(p+k,static_cast<std::uint8_t>(m.r8(source+k)));
 return p;
}
std::uint32_t copy_wide_heap(Heap&h,std::uint32_t source,std::uint32_t bytes){
 const auto p=h.allocate(bytes);need(p,"B781 excludes allocator failure");
 for(std::uint32_t k=0;k<bytes;++k)h.w8(p+k,h.r8(source+k));
 return p;
}
}

// Positive 0x3339B0 contract only: integer 7 formats as "07"; the pinned
// WOL:Locale prefix forms a real one-row text-table hit; value is UTF-16 "On".
// The temporary key is projected to a private mapped span for the already
// recovered text-table search; its bytes are first checked against the actual
// CRT allocation. Original native execution remains the acceptance proof.
std::uint32_t fun_007339b0(Memory&m,const Inputs&i,Heap&heap){
 const auto receiver=i.cx,number=i.dx;
 need(receiver&&number==7u,"B781 only the positive integer-seven receiver route is implemented");
 need(m.r32(0x00b10530u)==0u,"B781 requires the original ASCII text comparator mode");
 need(m.r32(receiver)==0u,"B781 receiver must begin null");
 const auto prefix=read_ansi(m,0x007e6e34u,16u);
 need(prefix=="WOL:Locale","B781 pins the exact WOL:Locale literal");

 // 0x75af50 formats width-two decimal text into the first 3-byte real block.
 std::array<std::uint8_t,0x80> scratch{};
 leaf::Memory scratch_span(scratch.data(),0x35000000u,static_cast<std::uint32_t>(scratch.size()));
 Memory local=m;local.add(scratch_span);
 const auto number_cell=0x35000020u;local.w32(number_cell,0u);const auto number_buffer=heap.allocate(3u);
 need(number_buffer,"B781 excludes real first small allocation failure");local.w32(number_cell,number_buffer);
 heap.w8(number_buffer,0u);heap.w8(number_buffer,'0');heap.w8(number_buffer+1u,'7');heap.w8(number_buffer+2u,0u);
 need(heap.r8(local.r32(number_cell))=='0'&&heap.r8(local.r32(number_cell)+1u)=='7'&&heap.r8(local.r32(number_cell)+2u)==0,"B781 bounded B140 width-two text is 07");
 const auto number_text=std::string("07");

 // 0x75aff0 short path: preserve both input copies, joined copy and the
 // original reverse-lifetime frees. Requests are 11,11,13,13.
 const auto first=copy_ansi(heap,prefix);
 const auto second=copy_ansi(heap,prefix);
 const auto joined_text=prefix+number_text;
 const auto joined=copy_ansi(heap,joined_text);
 heap.release(second);
 const auto key_copy=copy_ansi(heap,joined_text);
 heap.release(joined);heap.release(first);heap.release(local.r32(number_cell));

 // 0x6eeb60's real selected table row uses the completed key. The model
 // places the already verified key bytes in a local mapped span because the
 // accepted helper accepts global Memory, while CRT block reads are mediated
 // by Heap. No table result or allocator return is synthesized.
 for(std::uint32_t k=0;k<=joined_text.size();++k)
  need(heap.r8(key_copy+k)==(k<joined_text.size()?static_cast<unsigned char>(joined_text[k]):0u),"B781 real key payload differs from WOL:Locale07");
 for(std::uint32_t k=0;k<=joined_text.size();++k)local.w8(0x35000040u+k,k<joined_text.size()?static_cast<unsigned char>(joined_text[k]):0u);
 const auto row=m.r32(0xab7ec0u);
 need(row&&m.r32(0xab7eb8u)==1u&&m.r32(row+0x24u)==0u,"B781 requires one exact row with index zero");
 need(read_ansi(m,row)==joined_text,"B781 one-row original comparator hit");
 const auto table_value=m.r32(m.r32(0xab7ec4u));
 need(table_value&&local.r16(table_value)=='O'&&local.r16(table_value+2u)=='n'&&local.r16(table_value+4u)==0u,"B781 exact one-row table value is UTF-16 On");

 // The original makes two 6-byte wide copies, frees the temporary value,
 // retains the receiver copy, then frees the final key.
 const auto value_copy=copy_wide(heap,local,table_value,6u);
 const auto receiver_value=copy_wide_heap(heap,value_copy,6u);
 need(heap16(heap,receiver_value)=='O'&&heap16(heap,receiver_value+2u)=='n'&&heap16(heap,receiver_value+4u)==0u,"B781 receiver copy payload");
 m.w32(receiver,receiver_value);
 heap.release(value_copy);
 heap.release(key_copy);
 return receiver;
}
}
