#include "recovery_b305.hpp"

#include "recovered/name_hash.hpp"

#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b305 {
namespace {
void need(bool ok,const char* why) {
    if(!ok) throw std::domain_error(why);
}
std::vector<std::uint8_t> read_string(const Memory& memory,std::uint32_t at) {
    need(at!=0,"0x10da40 null string is outside this positive route");
    std::vector<std::uint8_t> bytes;
    for(std::uint32_t n=0;n<0x10000u;++n) {
        const auto byte=static_cast<std::uint8_t>(memory.r8(at+n));
        bytes.push_back(byte);
        if(!byte) return bytes;
    }
    throw std::domain_error("0x10da40 input string exceeds the bounded route");
}
std::uint32_t name_hash(const std::vector<std::uint8_t>& nul_terminated) {
    need(!nul_terminated.empty()&&nul_terminated.back()==0,"name buffer must include its terminator");
    return ini_name_hash(nul_terminated.data(),nul_terminated.size()-1,nullptr);
}
std::uint32_t duplicate(GuestHeap& heap,const std::vector<std::uint8_t>& bytes) {
    const auto result=heap.allocate(static_cast<std::uint32_t>(bytes.size()));
    need(result!=0,"positive route excludes allocator failure");
    for(std::uint32_t n=0;n<bytes.size();++n) heap.w8(result+n,bytes[n]);
    return result;
}
void init_link(GuestHeap& heap,std::uint32_t at) {
    heap.w32(at,0x785afc);
    heap.w32(at+4,0);
    heap.w32(at+8,0);
}
void insert_after(GuestHeap& heap,std::uint32_t position,std::uint32_t node) {
    const auto next=heap.r32(position+4);
    heap.w32(node+8,position);
    heap.w32(node+4,next);
    if(next) heap.w32(next+8,node);
    heap.w32(position+4,node);
}
std::uint32_t append_root_entry(Memory& memory,GuestHeap& heap,std::uint32_t root,
                                std::uint32_t key,std::uint32_t value) {
    const auto index=root+0x20;
    need(memory.r32(index+4)==0&&memory.r32(index+8)==0,
         "positive route requires empty root index");
    const auto old=memory.r32(index);
    const auto fresh=heap.allocate(80);
    need(fresh!=0,"positive route excludes root-index allocation failure");
    (void)heap.release(old); // Exact original 0x36df28 null-release early return.
    heap.w32(fresh,key); heap.w32(fresh+4,value);
    memory.w32(index,fresh); memory.w32(index+8,10); memory.w32(index+0x10,0);
    memory.w8(index+0xc,0); memory.w32(index+4,1);
    return fresh;
}
std::uint32_t append_section_entry(GuestHeap& heap,std::uint32_t index,
                                   std::uint32_t key,std::uint32_t value) {
    need(heap.r32(index+4)==0&&heap.r32(index+8)==0,
         "positive route requires empty section key index");
    const auto old=heap.r32(index);
    const auto fresh=heap.allocate(80);
    need(fresh!=0,"positive route excludes section-index allocation failure");
    (void)heap.release(old); // Same exact null-release branch as 0x110150 growth.
    heap.w32(fresh,key); heap.w32(fresh+4,value);
    heap.w32(index,fresh); heap.w32(index+8,10); heap.w32(index+0x10,0);
    heap.w8(index+0xc,0); heap.w32(index+4,1);
    return fresh;
}
}

std::uint32_t fun_0010da40(Memory& memory,Inputs& in,GuestHeap& heap) {
    const auto root=in.cx;
    const auto section_input=in.arg[0],key_input=in.arg[1],value_input=in.arg[2];
    need(root&&section_input&&key_input&&value_input,
         "0x10da40 positive route requires four nonnull input addresses");
    need(section_input!=key_input&&section_input!=value_input&&key_input!=value_input,
         "0x10da40 bounded fixture uses distinct string buffer addresses");
    const auto section_bytes=read_string(memory,section_input);
    const auto key_bytes=read_string(memory,key_input);
    const auto value_bytes=read_string(memory,value_input);
    need(section_bytes.size()>1&&key_bytes.size()>1&&value_bytes.size()>1,
         "0x10da40 positive route requires nonempty strings");

    // Entry 0x50da98 hashes and probes root+0x20. The bounded fixture's
    // initialized root index is empty, so this is the section-creation branch.
    const auto section_lookup_hash=name_hash(section_bytes);
    (void)section_lookup_hash;
    need(memory.r32(root+0x24)==0&&memory.r32(root+0x28)==0,
         "0x10da40 existing-section route is outside this bounded contract");
    need(memory.r32(root+4)==0x78ebac&&memory.r32(root+8)==0x785afc&&
         memory.r32(root+0x0c)==root+0x14&&memory.r32(root+0x10)==0&&
         memory.r32(root+0x14)==0x785afc&&memory.r32(root+0x18)==0&&
         memory.r32(root+0x1c)==root+8,
         "0x10da40 bounded route requires the exact initialized empty root list");
    const auto section=heap.allocate(0x44);
    need(section!=0,"positive route excludes section-object allocation failure");
    init_link(heap,section);
    const auto section_copy=duplicate(heap,section_bytes);
    heap.w32(section,0x78eba4);
    heap.w32(section+0x0c,section_copy);

    // Exact 0x510000 embedded value-list initialization at section+0x10.
    heap.w32(section+0x10,0x78ebac);
    init_link(heap,section+0x14);
    init_link(heap,section+0x20);
    heap.w32(section+0x18,section+0x20);
    heap.w32(section+0x28,section+0x14);
    // Exact 0x510130 embedded index initialization at section+0x2c.
    heap.w32(section+0x2c,0); heap.w32(section+0x30,0); heap.w32(section+0x34,0);
    heap.w8(section+0x38,0); heap.w32(section+0x3c,0); heap.w32(section+0x40,0);

    // 0x40e180 inserts after [root+0x1c], the initialized empty-list head.
    const auto root_position=memory.r32(root+0x1c);
    need(root_position==root+8,"root list must be the exact empty head/tail sentinel chain");
    const auto root_next=memory.r32(root_position+4);
    heap.w32(section+8,root_position); heap.w32(section+4,root_next);
    if(root_next) memory.w32(root_next+8,section);
    memory.w32(root_position+4,section);

    const auto section_insert_hash=name_hash(section_bytes);
    (void)append_root_entry(memory,heap,root,section_insert_hash,section);

    // 0x510220 returns AL=0 for the new section's zero-count index. This skips
    // 0x50dcaa's indirect call without inventing a target or callback result.
    const auto key_lookup_hash=name_hash(key_bytes);
    (void)key_lookup_hash;
    need(heap.r32(section+0x30)==0,"positive route requires an absent new key");

    const auto node=heap.allocate(0x28);
    need(node!=0,"positive route excludes value-node allocation failure");
    const auto value_copy=duplicate(heap,value_bytes); // Original order: value, then key.
    const auto key_copy=duplicate(heap,key_bytes);
    // Exact 0x50ffb0 construction with [key,value,0,0,0,0,0].
    init_link(heap,node);
    heap.w32(node,0x78eb9c);
    heap.w32(node+0x0c,key_copy); heap.w32(node+0x10,value_copy);
    for(std::uint32_t off=0x14;off<=0x24;off+=4) heap.w32(node+off,0);
    insert_after(heap,heap.r32(section+0x28),node);

    // The exact 0x110150 empty-index route grows 0->10, inserts one pair,
    // increments count 0->1, and finishes with EAX=1 (including upper bits).
    const auto stored_key_hash=name_hash(key_bytes);
    (void)append_section_entry(heap,section+0x2c,stored_key_hash,node);
    in.arg[0]=0; in.arg[1]=stored_key_hash; // Original 50db92 / 50dd8d overwrite caller A1/A2.
    return 1;
}
} // namespace ra2::recovered::recovery_b305
