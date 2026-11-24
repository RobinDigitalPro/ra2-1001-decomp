#include "recovered/recovery_b447.hpp"

#include "recovered/direct_b34_memory.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/strings_b37_memory.hpp"
#include "recovered/leaf_memory.hpp"

#include <array>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b447 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}

std::uint32_t c_string(Memory& m,std::uint32_t object){
  need(object,"0x10c320 positive route needs a nonnull IniByteString object");
  const auto text=m.r32(object);
  need(text,"0x10c320 positive route needs a nonnull contained string");
  for(unsigned n=0;n<64;++n)if(!m.r8(text+n)){
    need(n!=0,"0x10c320 positive route needs a nonempty name");
    return text;
  }
  throw std::domain_error("0x10c320 name exceeds the bounded 64-byte route");
}

unsigned text_length(const Memory& m,std::uint32_t p){
  for(unsigned n=0;n<64;++n)if(!m.r8(p+n))return n;
  throw std::domain_error("0x10c320 selected key exceeds 64 bytes");
}

struct StringCalls { Heap* heap; };
void string_call(direct_b34::Memory& m,direct_b34::State& s,
                 const direct_b34::Call& call,void* opaque){
  auto& h=*static_cast<StringCalls*>(opaque)->heap;
  need(call.target==0x76d957u&&call.argument_words==1u&&call.cleanup==0u,
       "0x359260 route reaches only the real one-argument CRT allocation boundary");
  s.ax=h.allocate(m,m.r32(call.sp+4u));
}

void assign_with_original_string_helper(Memory& m,Heap& heap,std::uint32_t output,
                                         std::uint32_t source,unsigned n){
  static constexpr std::uint32_t stack_base=0x5f100000u;
  std::array<std::uint8_t,0x300> stack_bytes{};
  leaf::Memory stack_span(stack_bytes.data(),stack_base-0x100u,
                          static_cast<std::uint32_t>(stack_bytes.size()));
  Memory local=m;local.add(stack_span);

  const strings_b37::Entry* entry=nullptr;
  for(const auto& e:strings_b37::entries_a())if(e.rva==0x359260u){entry=&e;break;}
  if(!entry)for(const auto& e:strings_b37::entries_b())if(e.rva==0x359260u){entry=&e;break;}
  need(entry,"accepted 0x359260 string helper is unavailable");

  direct_b34::State s{};s.cx=output;s.ax=0xa7130000u^n;s.bx=0xb4190000u^n;
  s.bp=0x91ad0000u^n;s.si=source;s.di=0x671d0000u^n;
  direct_b34::Frame f{};f.entry_sp=stack_base;f.sp=stack_base;
  f.outer_return=0xfefefefeu;f.call_return=0xfefefefeu;
  f.callback_cleanup=0u;f.argument_words=1u;f.boundary_count=1u;
  f.boundaries[0]={0x76d957u,stack_base+0x70u,0u,1u};
  local.w32(stack_base,0xfefefefeu);local.w32(stack_base+4u,source);
  StringCalls calls{&heap};direct_b34::Operations operations{string_call,&calls};
  strings_b37::Operations string_operations{operations};
  try{entry->function(local,s,f,string_operations);}
  catch(const std::exception&e){throw std::domain_error(std::string("B447 0x359260: ")+e.what());}
}
}

std::uint32_t fun_0010c320(Memory& m,Inputs& in,Heap& heap){
  const auto root=in.cx;
  const auto output=in.arg[0],query_object=in.arg[1],ordinal=in.arg[2];
  need(root&&output&&query_object,"0x10c320 positive route requires receiver/output/query");
  need(ordinal==0,"0x10c320 finite route covers the first key only");
  need(m.r32(output)==0,"0x10c320 finite route requires an empty output string");
  const auto query=c_string(m,query_object);

  unsigned length=0;
  while(length<64&&m.r8(query+length))++length;
  need(length<64,"0x10c320 query exceeds 64 bytes");
  const std::array<std::uint8_t,64> bytes=[&](){
    std::array<std::uint8_t,64> x{};
    for(unsigned j=0;j<=length;++j)x[j]=static_cast<std::uint8_t>(m.r8(query+j));
    return x;
  }();
  const auto hash=ini_name_hash(bytes.data(),length,nullptr);
  // Original 0x50c373 spills EDI to [ESP+0x24]. At that instruction ESP is
  // entry-0x1c, so the destination is caller word A1 (entry+8).
  in.arg[1]=hash;

  // Positive branch at 0x50c37a requires a nonempty sorted section index.
  // The accepted B381 route proves this initialized sorted/cache-hit state;
  // requiring a matching cache avoids the original sort callback at 0x5106d0.
  const auto index=root+0x20u;
  const auto entries=m.r32(index),count=m.r32(index+4u),capacity=m.r32(index+8u);
  const auto cached=m.r32(index+0x10u);
  need(count==1u&&capacity>=count&&entries&&m.r8(index+0x0cu)!=0,
       "0x10c320 bounded route requires one sorted initialized section index row");
  need(cached==entries&&m.r32(entries)==hash,
       "0x10c320 bounded route requires the exact B381-style matching section cache");
  const auto section=m.r32(entries+4u);
  need(section,"0x10c320 matching section row must contain a section pointer");
  need(m.r32(section+0x30u)==1u,
       "0x10c320 bounded route requires exactly one key in the section");
  const auto node=m.r32(section+0x18u);
  need(node&&m.r32(node+4u)&&m.r32(node+8u),
       "0x10c320 first key node requires valid nonzero links");
  const auto selected=m.r32(node+0x0cu);
  need(selected&&text_length(m,selected)>0,
       "0x10c320 selected key must be a nonempty readable string");

  // Original 0x50c3e4 passes node+0xc as source to accepted 0x759260.
  // That helper performs the null-output assignment and one actual CRT
  // allocation, writes the terminator, then copies the selected key bytes.
  try{assign_with_original_string_helper(m,heap,output,selected,
                                     static_cast<unsigned>(in.arg[0]^in.arg[2]));}
  catch(const std::exception&e){throw std::domain_error(std::string("B447 assignment setup: ")+e.what());}
  return output;
}
} // namespace ra2::recovered::recovery_b447
