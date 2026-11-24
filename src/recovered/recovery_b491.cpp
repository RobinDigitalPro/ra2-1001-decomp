#include "recovered/recovery_b491.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::numeric_b491 {
namespace {
using U = std::uint32_t;
void require(bool ok, const char* what) { if (!ok) throw std::domain_error(what); }

U map_index(const Memory& m, U xy) {
    const auto x = sx16(m.r16(xy));
    const auto y = sx16(m.r16(xy + 2));
    const auto width = m.r32(0x81a910);
    const U dx = U(x - y) + width - 1;
    const U dy = U(x - width + y - 1);
    return dy * width + sar(dx, 1);
}

U lookup_cell(Memory& m, U xy) {
    const auto x = sx16(m.r16(xy));
    const auto y = sx16(m.r16(xy + 2));
    const auto linear = (y << 9) + x;
    const auto table = m.r32(0x81a958);
    require(linear >= 0 && U(linear) < 0x40000, "B491 bounded map-cell index");
    const auto cell = m.r32(table + U(linear) * 4);
    require(cell != 0, "B491 initialized positive map cell");
    return cell;
}

U random_word(Memory& m, U state) {
    if (m.r8(state)) return 0;
    auto i = m.r32(state + 4), j = m.r32(state + 8);
    m.w32(state + 12 + 4 * i, m.r32(state + 12 + 4 * i) ^ m.r32(state + 12 + 4 * j));
    i = m.r32(state + 4); j = m.r32(state + 8);
    const auto value = m.r32(state + 12 + 4 * i);
    ++i; ++j;
    m.w32(state + 4, i >= 250 ? 0 : i);
    m.w32(state + 8, j >= 250 ? 0 : j);
    return value;
}
}

// Bounded direct insertion route for the original priority-queue feeder.
// The owner and heap are initialized as ordinary state; this does not claim
// constructor or gameplay reachability. The original map lookup and RNG
// effects are represented explicitly, without callback substitution.
U fun_006dfb40(Memory& m, const Inputs& i) {
    const U owner = i.cx, xy = i.arg[0];
    const U index = map_index(m, xy);
    const U cell = lookup_cell(m, xy);
    const U flags = m.r32(owner + 0x114);
    const U count = m.r32(owner + 0x10c);
    const U records = m.r32(owner + 0x118);
    const U heap = m.r32(owner + 0x110);
    require(count < 4 && m.r32(heap) == count && m.r32(heap + 4) >= count + 2,
            "B491 finite one-entry heap insertion capacity");
    require(m.r32(0x81a910) == 8 && m.r32(0x81a914) == 8 && index < 64,
            "B491 bounded 8x8 map fixture");
    require(m.r8(cell + 0x11e) < 11 && m.r8(flags + index) == 0,
            "B491 positive unoccupied map-cell route");
    const auto available = (m.r32(0x81a914) + 4) * m.r32(0x81a910) * 2;
    require(count <= available - 10, "B491 no-growth heap capacity route");

    const U item = records + count * 8;
    m.w32(item, m.r32(xy));
    const U raw = random_word(m, m.r32(0x00a255c0) + 0x218);
    const auto signed_raw = static_cast<std::int32_t>(raw);
    const U magnitude = signed_raw < 0 ? U(0) - raw : raw;
    const U residue = magnitude % 50;
    const U priority = m.r32(0x00a2896c) + residue;
    i.fp.load_integer32(priority);
    const U stored_priority=i.fp.pop32();
    m.w32(item + 4, stored_priority);
    i.arg[0] = stored_priority; // Later MOV [ESP+0x18],EAX overwrites entry caller word 0.

    const U heap_count = m.r32(heap) + 1;
    const U heap_array = m.r32(heap + 8);
    U slot = heap_count;
    const U new_entry = item;
    if (heap_count < m.r32(heap + 4) && heap_count > 1) {
        U parent = heap_count >> 1;
        while (parent != 0) {
            const U parent_entry = m.r32(heap_array + parent * 4);
            const auto parent_value = m.r32(parent_entry + 4);
            const auto new_value = m.r32(new_entry + 4);
            i.fp.load32(parent_value);
            i.fp.compare_pop32(new_value);
            if (i.fp.status() & 0x4100u) break;
            m.w32(heap_array + slot * 4, parent_entry);
            slot = parent;
            parent >>= 1;
        }
    }
    m.w32(heap_array + slot * 4, new_entry);
    m.w32(heap, heap_count);
    if (new_entry > m.r32(heap + 12)) m.w32(heap + 12, new_entry);
    if (new_entry < m.r32(heap + 16)) m.w32(heap + 16, new_entry);
    m.w32(owner + 0x10c, count + 1);
    m.w8(flags + index, 1);
    return flags;
}

U fun_006df090(Memory& m, const Inputs& i) {
    const U owner=i.cx,xy=i.arg[0];
    const U index=map_index(m,xy),cell=lookup_cell(m,xy);
    const U flags=m.r32(owner+0xf8),count=m.r32(owner+0xf0),records=m.r32(owner+0xfc),heap=m.r32(owner+0xf4);
    require(count<4&&m.r32(heap)==count&&m.r32(heap+4)>=count+2,"B491 finite secondary queue insertion capacity");
    require(m.r32(0x81a910)==8&&m.r32(0x81a914)==8&&index<64,"B491 bounded secondary 8x8 map fixture");
    require(m.r8(flags+index)==0,"B491 unoccupied secondary map cell");
    require((m.r8(m.r32(0xa255c0))&0x80u)!=0,"B491 original cell predicate enabled by config bit");
    const U object=m.r32(m.r32(0xa1e11c));
    require(m.r8(object+0x279)!=0&&m.r32(0xaa8648)==1,"B491 original type-owner lookup domain");
    const U type=m.r32(m.r32(0xaa863c));
    require(m.r32(m.r32(type+0xe0)+0x264)==0&&m.r32(type+0xe8)==1&&m.r32(cell+0x44)==0&&m.r8(cell+0x11c)==0,
            "B491 0x5d4730 first-owner exact route");
    i.fp.load64(read64(m,type+0xa0));i.fp.compare_pop64(read64(m,0x787520));
    require((i.fp.status()&0x0100u)==0,"B491 original 0x478550 positive double comparison");
    require(m.r32(cell+0xe4)==0,"B491 original 0x478550 zero cell word");
    const U available=(m.r32(0x81a914)+4)*m.r32(0x81a910)*2;
    require(count<available-20,"B491 no-growth secondary heap path");

    const U item=records+count*8;m.w32(item,m.r32(xy));
    const U raw=random_word(m,m.r32(0x00a255c0)+0x218);
    const U magnitude=(static_cast<std::int32_t>(raw)<0)?U(0)-raw:raw;
    const U priority=m.r32(0xa2896c)+(magnitude%50);
    i.fp.load_integer32(priority);const U stored_priority=i.fp.pop32();m.w32(item+4,stored_priority);
    const U heap_count=m.r32(heap)+1,heap_array=m.r32(heap+8);U slot=heap_count;
    if(heap_count<m.r32(heap+4)&&heap_count>1){U parent=heap_count>>1;while(parent){
      const U parent_entry=m.r32(heap_array+parent*4);i.fp.load32(m.r32(parent_entry+4));i.fp.compare_pop32(stored_priority);
      if(i.fp.status()&0x4100u)break;
      m.w32(heap_array+slot*4,parent_entry);slot=parent;parent>>=1;
    }}
    m.w32(heap_array+slot*4,item);m.w32(heap,heap_count);m.w32(owner+0xf0,count+1);
    if(item>m.r32(heap+12))m.w32(heap+12,item);if(item<m.r32(heap+16))m.w32(heap+16,item);
    m.w8(flags+index,1);
    return index;
}
}
