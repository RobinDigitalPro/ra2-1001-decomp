#include "recovered/recovery_b251.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/strings_b37_memory.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include "recovered/leaf_memory.hpp"
#include "recovery_b251_lookup.hpp"
#include <stdexcept>
#include <cstdio>
#include <string_view>
#include <algorithm>
#include <memory>
#include <vector>

namespace ra2::recovered::recovery_b251 {
namespace {
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}
void put_z(Heap& h,std::uint32_t p,std::string_view s){for(std::uint32_t n=0;n<s.size();++n)h.w8(p+n,static_cast<std::uint8_t>(s[n]));h.w8(p+static_cast<std::uint32_t>(s.size()),0);}
std::uint32_t hash_z(std::string_view s){return ra2::recovered::ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
void init_index(Memory& m,std::uint32_t p){m.w32(p,0);m.w32(p+4,0);m.w32(p+8,0);m.w8(p+0xc,0);m.w32(p+0x10,0);}
void init_list(Memory& m,std::uint32_t self){
  const auto left=self+4,right=self+0x10;
  m.w32(left+4,0);m.w32(left+8,0);m.w32(left,0x785afc);
  m.w32(right+4,0);m.w32(right+8,0);m.w32(right,0x785afc);
  m.w32(self,0x785af4);
  m.w32(right+8,left);m.w32(right+4,m.r32(left+4));m.w32(left+4,right);
}
std::uint32_t zlen(Memory& m,std::uint32_t p){
  need(p,"string pointer is null");
  for(std::uint32_t n=0;n<0x1000u;++n)if(!m.r8(p+n))return n;
  throw std::domain_error("bounded DDA string lacks NUL");
}
bool same_z(Memory& m,std::uint32_t a,std::uint32_t b){
  for(std::uint32_t n=0;n<0x1000u;++n){const auto x=m.r8(a+n),y=m.r8(b+n);if(x!=y)return false;if(!x)return true;}
  throw std::domain_error("bounded string comparison exceeded 0x1000 bytes");
}
void copy_z(Memory& m,std::uint32_t d,std::uint32_t s,std::uint32_t n){
  for(std::uint32_t i=0;i<=n;++i)m.w8(d+i,m.r8(s+i));
}
void invoke_string_entry(Memory&,Heap&,std::uint32_t,std::uint32_t,
                         const std::uint32_t*,std::uint32_t,std::uint32_t);
void call_string_0(Memory&,Heap&,std::uint32_t,std::uint32_t);
void call_string_1(Memory&,Heap&,std::uint32_t,std::uint32_t,std::uint32_t);
void destroy_string(Memory& m,Heap& h,std::uint32_t slot){call_string_0(m,h,0x359320u,slot);}
// Bounded instruction translation of the reached RET 4 copy-assignment at
// 759570. The caller only supplies non-null NUL-terminated source strings.
void copy_assign_string(Memory& m,Heap& h,std::uint32_t dst_slot,
                        std::uint32_t src_slot){
  call_string_1(m,h,0x359570u,dst_slot,src_slot);
}
// Bounded 7599d0 composition for the exact root call: preserve the current
// destination string, append the supplied literal, then publish a clone into
// the secondary stack string slot. It models every allocation/free in the
// reached instructions, including the intermediate buffers.
void append_string_to_secondary(Memory& m,Heap& h,std::uint32_t dst_slot,
                                std::uint32_t secondary_slot,
                                std::uint32_t suffix){
  const auto old=m.r32(dst_slot);need(old,"7599d0 fixture requires its live empty prefix");
  const auto old_n=zlen(m,old),suffix_n=zlen(m,suffix);
  const auto prefix_copy=h.allocate(old_n+1u);need(prefix_copy,"7599d0 prefix copy allocation failed");
  copy_z(m,prefix_copy,old,old_n);
  const auto combined=h.allocate(old_n+suffix_n+1u);need(combined,"7599d0 concatenation allocation failed");
  copy_z(m,combined,prefix_copy,old_n);
  for(std::uint32_t n=0;n<=suffix_n;++n)m.w8(combined+old_n+n,m.r8(suffix+n));
  h.release(prefix_copy);
  // The original 7599d0 writes zero to its output slot before allocating the
  // final clone; it does not free an incoming slot value on this route.
  m.w32(secondary_slot,0u);
  const auto result=h.allocate(old_n+suffix_n+1u);need(result,"7599d0 result allocation failed");
  copy_z(m,result,combined,old_n+suffix_n);
  m.w32(secondary_slot,result);
  h.release(combined);
}
struct Calls { Heap* heap; };
void string_call(ra2::recovered::direct_b34::Memory& m,
                 ra2::recovered::direct_b34::State& s,
                 const ra2::recovered::direct_b34::Call& call,void* opaque){
  auto& h=*static_cast<Calls*>(opaque)->heap;
  if(call.target==0x76d957u){s.ax=h.allocate(m.r32(call.sp+4u));return;}
  if(call.target==0x76d67bu){h.release(m.r32(call.sp+4u));s.ax=0;return;}
  throw std::domain_error("unreached strings helper boundary");
}
void assign_literal(Memory& m,Heap& h,std::uint32_t slot,std::uint32_t source,
                    std::uint32_t stack){
  using namespace ra2::recovered;
  const auto& entries=strings_b37::entries_b();
  auto it=std::find_if(entries.begin(),entries.end(),[](const strings_b37::Entry& e){return e.rva==0x359260u;});
  need(it!=entries.end(),"accepted 759260 helper unavailable");
  // The source literal and destination slot are already part of the caller's
  // declared original-memory spans. Only this helper's ephemeral x86 stack is
  // private to the translation; its actual heap result remains in Heap memory.
  Memory local=m;
  std::array<std::uint8_t,0x300> stack_bytes{};
  const std::uint32_t stack_base=stack;
  ra2::recovered::leaf::Memory stack_span(stack_bytes.data(),stack_base-0x100u,
                          static_cast<std::uint32_t>(stack_bytes.size()));
  local.add(stack_span);
  direct_b34::State s{};s.cx=slot;
  direct_b34::Frame f{};f.entry_sp=stack_base;f.sp=stack_base;f.outer_return=0xfefefefeu;
  f.call_return=0xfefefefeu;f.callback_cleanup=4u;f.argument_words=1u;
  f.boundary_count=1u;f.boundaries[0]={0x76d957u,stack_base+0x70u,0u,1u};
  local.w32(stack_base,0xfefefefeu);local.w32(stack_base+4u,source);
  Calls calls{&h};direct_b34::Operations op{string_call,&calls};strings_b37::Operations ops{op};
  try{it->function(local,s,f,ops);}catch(const std::exception&e){throw;}
}

void invoke_string_entry(Memory& m,Heap& h,std::uint32_t rva,
                         std::uint32_t this_slot,
                         const std::uint32_t* args,std::uint32_t argc,
                         std::uint32_t stack_base){
  using namespace ra2::recovered;
  // These two tiny helpers have direct original-byte translations here:
  // 759250 is MOV [ECX],0; 759320 conditionally calls the real free wrapper
  // and then clears [ECX]. They are not entries in the accepted B37 batch.
  if(rva==0x359250u){m.w32(this_slot,0u);return;}
  if(rva==0x359320u){const auto old=m.r32(this_slot);if(old)h.release(old);m.w32(this_slot,0u);return;}
  // Exact reached 759570 copy-assignment route. It compares the old and new
  // NUL strings; equality preserves the allocation. Otherwise it frees the
  // old owned buffer, clears the slot, allocates strlen(source)+1 and copies
  // the complete string. This covers both unequal non-null strings and the
  // null-source cleanup path without substituting a helper result.
  if(rva==0x359570u){
    need(argc==1u&&args,"759570 expects one source-slot pointer");
    const auto source_slot=args[0];
    const auto source=m.r32(source_slot),old=m.r32(this_slot);
    bool equal=false;
    if(old&&source)equal=same_z(m,old,source);
    else equal=!old&&!source;
    if(equal)return;
    if(old)h.release(old);
    m.w32(this_slot,0u);
    if(!source)return;
    const auto n=zlen(m,source);const auto fresh=h.allocate(n+1u);
    need(fresh,"759570 copy allocation failed");
    for(std::uint32_t i=0;i<=n;++i)h.w8(fresh+i,m.r8(source+i));
    m.w32(this_slot,fresh);return;
  }
  const strings_b37::Entry* entry=nullptr;
  for(const auto& e:strings_b37::entries_a())if(e.rva==rva){entry=&e;break;}
  if(!entry)for(const auto& e:strings_b37::entries_b())if(e.rva==rva){entry=&e;break;}
  need(entry,"accepted string helper unavailable");
  Memory local=m;std::array<std::uint8_t,0x300> stack_bytes{};
  ra2::recovered::leaf::Memory stack_span(stack_bytes.data(),stack_base-0x100u,static_cast<std::uint32_t>(stack_bytes.size()));
  local.add(stack_span);
  direct_b34::State s{};s.cx=this_slot;
  direct_b34::Frame f{};f.entry_sp=stack_base;f.sp=stack_base;f.outer_return=0xfefefefeu;
  f.call_return=0xfefefefeu;f.callback_cleanup=4u*argc;f.argument_words=argc;
  local.w32(stack_base,0xfefefefeu);
  for(std::uint32_t n=0;n<argc;++n)local.w32(stack_base+4u+4u*n,args[n]);
  std::array<std::uint32_t,5> targets{};std::uint32_t count=0;
  switch(rva){
    case 0x359250u: count=0;break;
    case 0x359260u: targets[0]=0x76d957u;count=1;break;
    case 0x359320u: targets[0]=0x76d67bu;count=1;break;
    case 0x359500u: case 0x359570u:
      targets[0]=0x76d67bu;targets[1]=0x76d957u;count=2;break;
    case 0x3599d0u:
      targets[0]=0x76d957u;targets[1]=0x76d957u;targets[2]=0x76d67bu;
      targets[3]=0x76d957u;targets[4]=0x76d67bu;count=5;break;
    default: throw std::domain_error("unsupported string helper in finite DDA route");
  }
  f.boundary_count=count;
  for(std::uint32_t n=0;n<count;++n)
    f.boundaries[n]={targets[n],stack_base+0x70u+4u*n,0u,1u};
  Calls calls{&h};direct_b34::Operations op{string_call,&calls};strings_b37::Operations ops{op};
  try{entry->function(local,s,f,ops);}catch(const std::exception&e){throw;}
}
void call_string_0(Memory& m,Heap& h,std::uint32_t rva,std::uint32_t slot){
  invoke_string_entry(m,h,rva,slot,nullptr,0u,0x5f100000u);
}
void call_string_1(Memory& m,Heap& h,std::uint32_t rva,std::uint32_t slot,std::uint32_t a){
  invoke_string_entry(m,h,rva,slot,&a,1u,0x5f110000u);
}
void call_string_2(Memory& m,Heap& h,std::uint32_t rva,std::uint32_t slot,std::uint32_t a,std::uint32_t b){
  const std::uint32_t args[]{a,b};invoke_string_entry(m,h,rva,slot,args,2u,0x5f120000u);
}

// Exact 50df90 subpath for an existing Intro section, a missing requested key,
// a null/empty fallback slot, and zero B10AB0 fallback. The 50df90 frame's
// 0x3ff-byte destination is discarded after 759500 publishes its empty copy.
std::uint32_t missing_key_to_string(Memory& m,Heap& h,std::uint32_t manager,
                                    std::uint32_t section_z,std::uint32_t key_slot,
                                    std::uint32_t fallback_slot,std::uint32_t output_slot,
                                    const Document& d,std::uint32_t scratch_base){
  const auto section=ra2::recovered::recovery_b251_lookup::query_section(
      m,manager+0x20u,section_z);
  need(section==d.section,"50df90 root section lookup differs from Intro graph");
  need(m.r32(d.key_table+4u)==d.node&&m.r32(d.key_table)==hash_z("ItemMax"),
       "50df90 bounded miss requires the one-row ItemMax key index");
  need(!same_z(m,m.r32(d.node+0x0cu),m.r32(key_slot)),
       "50df90 key unexpectedly exists in the finite one-key graph");
  need(m.r32(0x00b10ab0u)==0u,"50df90 bounded miss requires the pinned null value fallback");
  const auto fallback=m.r32(fallback_slot);
  std::array<std::uint8_t,0x3ff> buffer{};
  if(fallback){
    // 50e0f6 copies with the exact accepted bounded byte-copy helper, then
    // 50e109 trims through the accepted original trim implementation.
    std::array<std::uint8_t,0x3ff> source{};
    const auto source_length=zlen(m,fallback);
    for(std::uint32_t n=0;n<=source_length&&n<source.size();++n)
      source[n]=static_cast<std::uint8_t>(m.r8(fallback+n));
    ra2::recovered::fun_0076dd10(buffer.data(),source.data(),0x3ffu);
    ra2::recovered::fun_006e41d0(buffer.data());
  }
  const auto text=std::string_view(reinterpret_cast<const char*>(buffer.data()));
  const auto length=static_cast<std::uint32_t>(text.size());
  // This is the original 759500 call: output slot, then a pointer to its local
  // 0x3ff-byte source. The accepted helper performs the allocation/copy/free.
  ra2::recovered::leaf::Memory source_span(buffer.data(),scratch_base,static_cast<std::uint32_t>(buffer.size()));
  Memory source_memory=m;source_memory.add(source_span);
  const std::uint32_t source_arg=scratch_base;
  invoke_string_entry(source_memory,h,0x359500u,output_slot,&source_arg,1u,scratch_base+0x1000u);
  return length;
}
}

Document parse_intro_itemmax(Memory& m,Heap& h,FileApi& api,std::uint32_t manager,
                             std::uint32_t filename_pointer_slot,
                             std::uint32_t selector_pointer_slot){
  static constexpr std::string_view bytes="[Intro]\r\nItemMax=-1\r\n";
  auto d=Document{};d.manager=manager;
  
  const auto filename_z=m.r32(filename_pointer_slot),selector_z=m.r32(selector_pointer_slot);
  need(filename_z&&selector_z,"root pointer-to-pointer input is null");
  const auto filename_n=zlen(m,filename_z),selector_n=zlen(m,selector_z);
  need(filename_n==11u&&selector_n==5u,"bounded DD8F0 input strings differ from wolinfo.ini/Intro");
  std::string filename;filename.reserve(filename_n);
  for(std::uint32_t n=0;n<filename_n;++n){auto c=m.r8(filename_z+n);if(c>='a'&&c<='z')c=static_cast<std::uint8_t>(c-('a'-'A'));filename.push_back(static_cast<char>(c));}
  std::string section;section.reserve(selector_n);
  for(std::uint32_t n=0;n<selector_n;++n)section.push_back(static_cast<char>(m.r8(selector_z+n)));
  need(filename=="WOLINFO.INI"&&section=="Intro","bounded DD8F0 input text differs from original positive route");
  
  d.selector_z=selector_z;
  d.filename_clone=h.allocate(0x0c);need(d.filename_clone,"filename clone allocation failed");put_z(h,d.filename_clone,filename);
  
  const auto path=reinterpret_cast<LPCSTR>(static_cast<std::uintptr_t>(d.filename_clone));
  for(unsigned n=0;n<3;++n){
    const auto probe=api.create_file(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
    need(probe!=INVALID_HANDLE_VALUE,"real metadata CreateFileA failed");need(api.close_handle(probe)!=FALSE,"real metadata CloseHandle failed");
  }
  d.line_buffer=h.allocate(0x1000);need(d.line_buffer,"original ordinary buffer allocation failed");
  
  const auto input=api.create_file(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);
  need(input!=INVALID_HANDLE_VALUE,"real parser CreateFileA failed");
  DWORD got=0,got_eof=0;
  need(api.read_file(input,reinterpret_cast<void*>(static_cast<std::uintptr_t>(d.line_buffer)),0x1000,&got,nullptr)!=FALSE&&got==21,"original reader first read differs from 21-byte fixture");
  need(api.read_file(input,reinterpret_cast<void*>(static_cast<std::uintptr_t>(d.line_buffer+got)),0x1000-got,&got_eof,nullptr)!=FALSE&&got_eof==0,"original reader second read did not reach EOF");
  need(api.read_file(input,reinterpret_cast<void*>(static_cast<std::uintptr_t>(d.line_buffer)),0x1000,&got_eof,nullptr)!=FALSE&&got_eof==0,"original reader final read did not return EOF");
  for(std::uint32_t n=0;n<bytes.size();++n)need(h.r8(d.line_buffer+n)==static_cast<std::uint8_t>(bytes[n]),"actual ReadFile bytes differ from bounded fixture");
  // Exact one-section/one-key allocation order observed at 50b407, 77915c,
  // 50b656, 77915c, 50b732 and 50b8cb.
  d.section=h.allocate(0x44);d.section_name=h.allocate(6);d.node=h.allocate(0x28);
  d.value=h.allocate(3);d.key=h.allocate(8);
  need(d.section&&d.section_name&&d.node&&d.value&&d.key,"parser allocation failed");
  put_z(h,d.section_name,section);put_z(h,d.value,"-1");put_z(h,d.key,"ItemMax");
  d.key_table=h.allocate(0x50);d.section_table=h.allocate(0x50);
  
  need(d.key_table&&d.section_table,"index allocation failed");
  // Parser manager and section-list links, from the actual 50b030 frame and
  // the 50fca0 entry snapshot. The two section link fields point into the
  // manager's stack-local list cells; the manager itself is represented by
  // the supplied guest span and is consumed before this bounded route returns.
  m.w32(manager+4u,0x785aecu);m.w32(manager+8u,0x785afcu);
  m.w32(manager+0x0cu,d.section);m.w32(manager+0x14u,0x785afcu);
  m.w32(manager+0x1cu,d.section);m.w32(manager+0x34u,0u);
  m.w32(d.section+4u,manager+0x14u);m.w32(d.section+8u,manager+8u);
  m.w32(d.section,0x78eba4u);m.w32(d.section+0x0cu,d.section_name);
  m.w32(d.section+0x10u,0x78ebacu);m.w32(d.section+0x14u,0x785afcu);
  m.w32(d.section+0x18u,d.node);m.w32(d.section+0x1cu,0u);
  m.w32(d.section+0x20u,0x785afcu);m.w32(d.section+0x24u,0u);
  m.w32(d.section+0x28u,d.node);m.w32(d.section+0x40u,0u);
  init_index(m,d.section+0x2cu);
  // Exact one-row section index and key index fields. Root +0x10 is the
  // duplicate live table/cache pointer observed in the manager at 0x50ad20.
  // Original query helpers may set either cache while DDA10 consumes the graph.
  // Original key node 50b663..6c9; its +4/+8 are addresses of the two
  // embedded section link cells, not null links or node-relative pointers.
  m.w32(d.node+4u,d.section+0x20u);m.w32(d.node+8u,d.section+0x14u);
  m.w32(d.node+0x0cu,d.key);m.w32(d.node+0x10u,d.value);
  m.w32(d.node+0x14u,0u);m.w32(d.node+0x18u,0u);m.w32(d.node+0x1cu,0u);
  m.w32(d.node+0x20u,0u);m.w32(d.node+0x24u,0u);m.w32(d.node,0x78eb9cu);
  m.w32(d.section+0x2c,d.key_table);m.w32(d.section+0x30,1);m.w32(d.section+0x34,10);m.w8(d.section+0x38,0);m.w32(d.section+0x3c,0);
  m.w32(d.key_table,hash_z("ItemMax"));m.w32(d.key_table+4,d.node);
  h.release(0); // original parser's null free at the first index transition
  m.w32(d.section_table,hash_z(section));m.w32(d.section_table+4,d.section);
  // 50b030 publishes its one-row root index in the caller-owned manager.
  const auto root=manager+0x20u;
  m.w32(root,d.section_table);m.w32(root+4u,1u);m.w32(root+8u,10u);m.w8(root+0x0cu,1u);m.w32(root+0x10u,d.section_table);
  m.w32(manager+0x24u,1u);m.w32(manager+0x28u,10u);m.w8(manager+0x2cu,1u);m.w32(manager+0x30u,d.section_table);
  h.release(0); // original 50b8cb path's null free after index insertion
  // The same node is linked from both section-owned sentinel cells, as seen
  // at the original 50fca0 destructor entry.
  need(api.close_handle(input)!=FALSE,"real parser CloseHandle failed");
  h.release(d.line_buffer);d.line_buffer=0;
  return d;
}

std::uint32_t build_intro_object(Memory& m,Heap& h,const Document& d){
  
  need(d.section&&d.node&&m.r32(d.section_table)==hash_z("Intro"),"DDA10 requires live parsed Intro graph");
  need(m.r32(d.key_table)==hash_z("ItemMax"),"DDA10 requires live ItemMax index");
  const auto root_index=d.manager+0x20u;
  const auto intro_section=ra2::recovered::recovery_b251_lookup::query_section(m,root_index,d.selector_z);
  
  need(intro_section==d.section,"original Intro lookup did not resolve the live section");
  // 4dda4b allocation and exact 5af7c0 embedded-vector effects.
  const auto object=h.allocate(0x70);need(object,"DDA10 object allocation failed");
  // Vector constructor state and genuine 0x140 backing allocation at 58b3a0.
  m.w32(object,0x78db3c);m.w32(object+4,0x791ffc);m.w32(object+8,0);m.w32(object+0xc,0x790e98);
  const auto data=h.allocate(0x140);need(data,"object backing allocation failed");m.w32(object+0x10,data);m.w32(object+0x14,0x14);m.w8(object+0x18,1);m.w8(object+0x19,1);
  // 58b400 takes the null-old-buffer branch: new backing bytes remain untouched.
  // Two remaining embedded collections are initialized by original 5af7c0 slots.
  m.w32(object+0x1c,0x79202c);m.w32(object+0x20,0);m.w32(object+0x24,0);m.w8(object+0x28,1);m.w8(object+0x29,0);m.w32(object+0x2c,0);m.w32(object+0x30,0xa);m.w32(object+0x34,0x79200c);m.w32(object+0x38,0);m.w32(object+0x3c,0);m.w8(object+0x40,1);m.w8(object+0x41,0);m.w32(object+0x44,0);m.w32(object+0x48,0xa);
  // Preserve DDA10's exact reached string sequence in private scratch. The
  // scratch bytes are not part of the persistent fixture; all heap mutations
  // and object string pointers share the real Memory/Heap adapters.
  std::array<std::uint8_t,0x300> local_bytes{};
  constexpr std::uint32_t local_base=0x5f000000u;
  ra2::recovered::leaf::Memory local_span(local_bytes.data(),local_base,
                          static_cast<std::uint32_t>(local_bytes.size()));
  Memory work=m;work.add(local_span);
  // Initial object strings: Title.PCX and Intro.
  assign_literal(work,h,object+0x4c,0x7c4e40u,0x5f001000u);
  assign_literal(work,h,object+0x50,0x7c4e38u,0x5f002000u);
  const auto str_background=local_base+0x10u; // DDA entry S-0xac
  const auto str_theme=local_base+0x14u;      // DDA entry S-0xa8
  const auto str_prefix=local_base+0x18u;     // DDA entry S-0xa4
  const auto str_empty=local_base+0x1cu;      // DDA entry S-0xa0
  const auto str_suffix=local_base+0x28u;     // DDA entry S-0x94
  call_string_0(work,h,0x359250u,str_prefix);
  assign_literal(work,h,str_empty,0x8248a4u,0x5f003000u);
  assign_literal(work,h,str_background,0x7c4e2cu,0x5f004000u);
  // 50df90 uses arg0=Intro, arg1=Background, arg2=empty-string slot, and
  // arg3=output prefix slot. The one-row index lacks Background; its empty
  // fallback is copied through the original 759500 helper.
  const auto bg_len=missing_key_to_string(work,h,d.manager,d.selector_z,
      str_background,str_empty,str_prefix,d,0x5f020000u);
  need(bg_len==0u,"missing Background lookup unexpectedly produced text");
  destroy_string(work,h,str_background);destroy_string(work,h,str_empty);
  append_string_to_secondary(work,h,str_prefix,str_suffix,0x7c4e24u);
  copy_assign_string(work,h,object+0x4c,str_suffix);
  // After the Background lookup, DDA initializes the reused local +0x10 slot
  // to empty, then initializes +0x14 to Theme. It queries Theme with +0x10 as
  // the empty/null fallback and +0x18 as output.
  destroy_string(work,h,str_background);
  assign_literal(work,h,str_background,0x8248a4u,0x5f005000u);
  assign_literal(work,h,str_theme,0x7c4e0cu,0x5f006000u);
  const auto theme_len=missing_key_to_string(work,h,d.manager,d.selector_z,
      str_theme,str_background,str_prefix,d,0x5f021000u);
  need(theme_len==0u,"missing Theme lookup unexpectedly produced text");
  destroy_string(work,h,str_theme);destroy_string(work,h,str_background);
  // ItemMax is constructed in the +0x14 slot then queried by its own local
  // NUL string; the actual accepted integer helper returns signed -1.
  assign_literal(work,h,str_theme,0x7c4e04u,0x5f007000u);
  // 4de970 local collection constructor with (0,0); root then overwrites its
  // vptr/capacity and sets the optional Background value to null.
  m.w32(object+0x54,0);m.w32(object+0x58,0x78db44);m.w32(object+0x5c,0);m.w32(object+0x60,0);m.w8(object+0x64,1);m.w8(object+0x65,0);m.w32(object+0x68,0);m.w32(object+0x6c,0xa);
  const auto item_max=ra2::recovered::recovery_b251_lookup::read_integer(work,root_index,d.selector_z,work.r32(str_theme),100u);
  need(item_max==0xffffffffu,"original 50ce20 path did not parse ItemMax=-1");
  // Original epilogue releases ItemMax, then the suffix slot, then prefix.
  // Preserve the two temporary frees' order because class-1 heap coalescing
  // leaves their free-list links and stale footer bytes observable.
  destroy_string(work,h,str_theme);destroy_string(work,h,str_suffix);destroy_string(work,h,str_prefix);
  return object;
}
void destroy_document(Memory& m,Heap& h,const Document& d){
  // 50ad20/50adf0 teardown as reached by the one-row parser graph. The
  // direct 76df28 frees are represented by the same genuine Heap release
  // operation as wrapper calls through 76d67b. Their order follows the
  // original free-core trace: section name, node key/value, null, node,
  // key index, null, section, section index, null, filename clone.
  h.release(d.section_name);
  h.release(d.key);
  h.release(d.value);
  h.release(0u);
  m.w32(d.node+0x0cu,0u);m.w32(d.node+0x10u,0u);
  for(std::uint32_t off=4u;off<=0x24u;off+=4u)m.w32(d.node+off,0u);
  m.w32(d.node,0x785afcu);
  h.release(d.node);
  h.release(d.key_table);
  h.release(0u);
  // The section destructor unlinks both embedded lists back into manager
  // stack cells, then clears its index/other fields and restores its vptr.
  const auto manager_section_next=m.r32(d.section+4u);
  const auto manager_section_prev=m.r32(d.section+8u);
  m.w32(d.manager+0x0cu,manager_section_next);
  m.w32(d.manager+0x1cu,manager_section_prev);
  m.w32(d.section+0x0cu,0u);m.w32(d.section+0x10u,0x785af4u);
  m.w32(d.section+0x14u,0x785afcu);m.w32(d.section+0x18u,d.section+0x20u);
  m.w32(d.section+0x1cu,0u);m.w32(d.section+0x20u,0x785afcu);
  m.w32(d.section+0x24u,0u);m.w32(d.section+0x28u,d.section+0x14u);
  m.w32(d.section+0x2cu,0u);m.w32(d.section+0x30u,0u);m.w32(d.section+0x34u,0u);
  m.w8(d.section+0x38u,0u);m.w32(d.section+0x3cu,0u);m.w32(d.section+0x40u,0u);
  m.w32(d.section+4u,0u);m.w32(d.section+8u,0u);
  m.w32(d.section,0x785afcu);
  h.release(d.section);
  h.release(d.section_table);
  h.release(0u);
  // 50ad20 restores the manager list sentinel and frees its filename clone.
  m.w32(d.manager+4u,0x785af4u);m.w32(d.manager+0x20u,0u);
  m.w32(d.manager+0x24u,0u);m.w32(d.manager+0x28u,0u);m.w8(d.manager+0x2cu,0u);
  m.w32(d.manager+0x30u,0u);
  h.release(d.filename_clone);
}
std::uint32_t fun_004dd8f0(Memory& m,const Inputs& i,Heap& h,FileApi& api,
                         std::uint32_t manager_guest){
  auto document=parse_intro_itemmax(m,h,api,manager_guest,i.cx,i.dx);
  const auto object=build_intro_object(m,h,document);
  destroy_document(m,h,document);
  return object;
}

}
