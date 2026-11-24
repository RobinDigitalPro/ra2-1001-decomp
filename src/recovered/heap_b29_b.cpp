#include "recovered/heap_b29_memory.hpp"
#include <array>
#include <cstdint>

// Portable views of byte-verified original wrappers. Numeric tags and field
// offsets are retained as evidence; this code makes no original type claim.
namespace ra2::recovered::heap_b29 {
namespace {
inline void rel(Memory& m,State& s,const Operations& o,std::uint32_t p){release(m,s,o,p);}

void fun_005ce5d0(Memory&m,State&s,const Operations&o){
 auto al=m.r8(0xa5ab58);s.ax=with_al(s.ax,al);
 if(al){auto p=m.r32(0xa5ab48);s.ax=p;rel(m,s,o,p);m.w8(0xa5ab58,0);}
 if(m.r8(0xa5ab59)){auto p=m.r32(0xa5ab4c);s.cx=p;rel(m,s,o,p);m.w8(0xa5ab59,0);}
 if(m.r8(0xa5ab5a)){auto p=m.r32(0xa5ab50);s.dx=p;rel(m,s,o,p);m.w8(0xa5ab5a,0);}
 if(m.r8(0xa5ab5b)){auto p=m.r32(0xa5ab54);s.ax=p;rel(m,s,o,p);m.w8(0xa5ab5b,0);}
}
void fun_005d0700(Memory&m,State&s,const Operations&o){auto obj=s.cx,p=m.r32(obj);s.ax=p;rel(m,s,o,p);s.ax=0;m.w32(obj,0);m.w32(obj+4,0);m.w32(obj+8,0);m.w8(obj+0xc,0);m.w32(obj+0x10,0);}
void fun_005f80b0(Memory&m,State&s,const Operations&o){
 const auto receiver=s.cx,target=s.arg[0];auto eax=m.r32(receiver+0x34);std::uint32_t edx=0;
 if(eax){if(eax!=target){for(;;){edx=eax;eax=m.r32(eax);if(!eax||eax==target)break;}}
  if(eax){if(edx){const auto next=m.r32(eax);s.cx=next;m.w32(edx,next);rel(m,s,o,eax);return;}edx=m.r32(eax);s.dx=edx;s.ax=eax;m.w32(receiver+0x34,edx);rel(m,s,o,eax);return;}}
 s.ax=eax;s.dx=edx;
}
void fun_00616930(Memory&m,State&s,const Operations&o){auto obj=s.cx,al=m.r8(obj+0x58);s.ax=with_al(s.ax,al);m.w32(obj,0x7933fc);if(al){auto p=m.r32(obj+0x54);s.ax=p;rel(m,s,o,p);m.w8(obj+0x58,0);}m.w32(obj+0x54,0);}
void fun_006169f0(Memory&m,State&s,const Operations&o){auto obj=s.cx,al=m.r8(obj+0x58);s.ax=with_al(s.ax,al);if(al){auto p=m.r32(obj+0x54);s.ax=p;rel(m,s,o,p);m.w8(obj+0x58,0);}m.w32(obj+0x54,0);}

void fun_0062f900(Memory&m,State&s,const Operations&o){auto obj=s.cx;auto flag=m.r8(obj+0x19);s.ax=with_al(s.ax,flag);m.w32(obj,0x793bf4);m.w8(obj+0x18,0);if(flag){auto p=m.r32(obj+4);s.ax=p;rel(m,s,o,p);m.w32(obj+4,0);m.w8(obj+0x19,0);}m.w32(obj,0x793c3c);}
void fun_0062fc00(Memory& m, State& s, const Operations& o) {
    const auto obj = s.cx;
    const auto p = m.r32(obj + 4);
    const auto flag = m.r8(obj + 0x19);
    s.ax = with_al(s.ax, flag);
    m.w32(obj, 0x793bf4);
    m.w8(obj + 0x18, 0);
    if (flag) {
        rel(m, s, o, p);
        m.w32(obj + 4, 0);
        m.w8(obj + 0x19, 0);
    }
    const auto al = s.arg[0] & 0xffu;
    m.w32(obj, 0x793c3c);
    if (al & 1u) rel(m, s, o, obj);
    s.ax = obj;
}
void remove_front_repeatedly(Memory& m, State& s, const Operations& o,
                             std::uint32_t obj) {
    for (;;) {
        const auto base = m.r32(obj + 4);
        const auto p = m.r32(base);
        s.cx = p;
        rel(m, s, o, p);

        auto count = m.r32(obj + 0x10);
        s.ax = count;
        if (s32(count) <= 0) break;

        const auto next_count = count - 1u;
        s.cx = next_count;
        m.w32(obj + 0x10, next_count);
        s.ax = 0;
        if (s32(next_count) > 0) {
            const auto entries = m.r32(obj + 4);
            s.cx = entries;
            std::uint32_t index = 0;
            do {
                ++index;
                s.ax = index;
                const auto shifted = m.r32(entries + index * 4u);
                s.dx = shifted;
                m.w32(entries + (index - 1u) * 4u, shifted);
                count = m.r32(obj + 0x10);
                s.cx = count;
            } while (s32(index) < s32(count));
        }
        if (s32(m.r32(obj + 0x10)) == 0) break;
    }
}
void fun_00636460(Memory& m, State& s, const Operations& o) {
    const auto obj = s.cx;
    if (s32(m.r32(obj + 0x10)) != 0) {
        remove_front_repeatedly(m, s, o, obj);
    }
    m.w8(obj + 0x18, 0);
    m.w32(obj + 0x1c, 0);
}
void fun_006364b0(Memory& m, State& s, const Operations& o) {
    const auto obj = s.cx;
    if (s32(m.r32(obj + 0x10)) > 0) {
        remove_front_repeatedly(m, s, o, obj);
    }
    const auto p = m.r32(obj + 4);
    m.w32(obj, 0x793eb4);
    s.ax = p;
    if (p != 0 && m.r8(obj + 0x0d) != 0) {
        rel(m, s, o, p);
        m.w32(obj + 4, 0);
    }
    m.w8(obj + 0x0d, 0);
    m.w32(obj + 8, 0);
}
void simple_owned(Memory& m, State& s, const Operations& o, std::uint32_t tag) {
    const auto obj = s.cx;
    const auto p = m.r32(obj + 4);
    s.ax = p;
    m.w32(obj, tag);
    if (p != 0 && m.r8(obj + 0x0d) != 0) {
        rel(m, s, o, p);
        m.w32(obj + 4, 0);
    }
    m.w8(obj + 0x0d, 0);
    m.w32(obj + 8, 0);
}
void fun_006498b0(Memory&m,State&s,const Operations&o){simple_owned(m,s,o,0x7889d4);}
void fun_006498e0(Memory&m,State&s,const Operations&o){simple_owned(m,s,o,0x78e118);}
void fun_00649910(Memory&m,State&s,const Operations&o){simple_owned(m,s,o,0x794000);}
std::uint32_t clear_counter(Memory& m) {
    auto value = m.r32(0xa9eaa8) - 1u;
    m.w32(0xa9eaa8, value);
    if (value != 0) return value;
    value = 0xa9eab4;
    while (value < 0xa9eacc) {
        m.w32(value - 4u, 0);
        m.w8(value, 0);
        value += 8u;
    }
    return value;
}
void counted_free(Memory& m, State& s, const Operations& o, bool self_free) {
    const auto obj = s.cx;
    const auto p = m.r32(obj + 0x0c);
    const auto owner = m.r8(obj + 0x10);
    s.ax = with_al(s.ax, owner);
    m.w32(obj, 0x794148);
    if (p != 0 && owner == 1) {
        rel(m, s, o, p);
        m.w32(obj + 0x0c, 0);
        m.w8(obj + 0x10, 0);
    }
    s.ax = clear_counter(m);
    if (!self_free) return;
    const auto al = s.arg[0] & 0xffu;
    if (al & 1u) rel(m, s, o, obj);
    s.ax = obj;
}
void fun_0065e860(Memory&m,State&s,const Operations&o){counted_free(m,s,o,false);}void fun_0065f380(Memory&m,State&s,const Operations&o){counted_free(m,s,o,true);}void fun_0065f3e0(Memory&m,State&s,const Operations&o){counted_free(m,s,o,true);}void fun_0065f440(Memory&m,State&s,const Operations&o){counted_free(m,s,o,true);}
void fun_006268a0(Memory&m,State&s,const Operations&o){auto al=m.r8(0xa9deb1);s.ax=with_al(s.ax,al);if(al){auto p=m.r32(0xa9de98);s.ax=p;rel(m,s,o,p);m.w8(0xa9deb1,0);}al=m.r8(0xa9deb0);s.ax=with_al(s.ax,al);m.w32(0xa9de98,0);if(al){auto p=m.r32(0xa9de60);s.cx=p;rel(m,s,o,p);m.w8(0xa9deb0,0);}m.w32(0xa9de60,0);}
void fun_0066ab20(Memory& m, State& s, const Operations& o) {
    const auto obj = s.cx;
    if (m.r8(obj + 0x5c) == 0) return;
    const auto p = m.r32(obj + 0x58);
    s.ax = p;
    if (p == 0) return;
    rel(m, s, o, p);
    m.w32(obj + 0x58, 0);
    m.w8(obj + 0x5c, 0);
    m.w32(obj + 0x14, 0);
    m.w32(obj + 0x18, 0);
}
void shift_header(Memory&m,State&s,const Operations&o){auto esi=s.cx;const auto cl=s.arg[0]&0xffu;s.cx=(s.cx&0xffffff00u)|cl;if(cl&2){s.ax=m.r32(esi-4);esi-=4;s.ax-=1;}if(cl&1)rel(m,s,o,esi);s.ax=esi;}
void fun_00677c70(Memory&m,State&s,const Operations&o){shift_header(m,s,o);}
void fun_00690790(Memory&m,State&s,const Operations&o){auto p=m.r32(s.cx+0x14);s.ax=p;if(p){rel(m,s,o,p);s.cx=p;}}
void fun_00695b90(Memory&m,State&s,const Operations&o){auto i=s.cx;auto al=m.r8(i+0xaa5e34);s.ax=with_al(s.ax,al);if(al){auto p=m.r32(0xaa53a8+i*4);rel(m,s,o,p);m.w8(i+0xaa5e34,0);}m.w32(0xaa53a8+i*4,0);}
void fun_00700390(Memory&m,State&s,const Operations&o){auto p=m.r32(0xab8094);s.ax=p;if(p){rel(m,s,o,p);m.w32(0xab8094,0);}}
void fun_00706830(Memory&m,State&s,const Operations&o){auto p=m.r32(0xab8220);s.ax=p;if(p){rel(m,s,o,p);m.w32(0xab8220,0);}}
void three_slots(Memory& m, State& s, const Operations& o) {
    const auto obj = s.cx;
    for (unsigned slot = 0; slot < 3; ++slot) {
        const auto p = m.r32(obj + 0x10u + 4u * slot);
        s.ax = p;
        if (slot != 0) m.w32(obj + 0x0cu + 4u * slot, 0);
        if (p != 0) rel(m, s, o, p);
    }
    m.w32(obj + 0x18, 0);
}
void fun_0070dc80(Memory&m,State&s,const Operations&o){three_slots(m,s,o);}void fun_0070dcd0(Memory&m,State&s,const Operations&o){three_slots(m,s,o);}
void fun_00710930(Memory&m,State&s,const Operations&o){auto obj=s.cx;auto flag=m.r32(obj+0x18);s.ax=flag;if(flag){auto p=m.r32(obj+0x10);rel(m,s,o,p);}flag=m.r32(obj+0x1c);s.ax=flag;if(flag){auto p=m.r32(obj+0x14);s.cx=p;rel(m,s,o,p);}}
void header_free(Memory& m, State& s, const Operations& o,
                 bool early_clear, bool tag_write, std::uint32_t tag,
                 bool self_free, bool load_owner) {
    const auto obj = s.cx;
    const auto p = m.r32(obj + 4);
    s.ax = p;
    if (early_clear) m.w32(obj + 0x10, 0);
    if (tag_write) m.w32(obj, tag);

    if (p != 0) {
        const auto owner = m.r8(obj + 0x0d);
        if (load_owner) s.cx = (s.cx & 0xffffff00u) | owner;
        if (owner != 0) {
            const auto header = m.r32(p - 4);
            s.cx = header;
            const auto allocation_base = p - 4;
            rel(m, s, o, allocation_base);
            m.w32(obj + 4, 0);
        }
    }

    if (self_free) s.ax = with_al(s.ax, s.arg[0] & 0xffu);
    m.w8(obj + 0x0d, 0);
    m.w32(obj + 8, 0);
    if (self_free && (s.arg[0] & 1u)) {
        rel(m, s, o, obj);
    }
    if (self_free) s.ax = obj;
}
void fun_006b59b0(Memory&m,State&s,const Operations&o){header_free(m,s,o,true,false,0,false,false);}
void fun_006b5c00(Memory&m,State&s,const Operations&o){header_free(m,s,o,false,false,0,false,false);}
void fun_006b5e80(Memory&m,State&s,const Operations&o){header_free(m,s,o,false,true,0x797908,true,true);}
void fun_006b5ee0(Memory&m,State&s,const Operations&o){shift_header(m,s,o);}
void fun_006b5f20(Memory&m,State&s,const Operations&o){header_free(m,s,o,false,true,0x797908,true,true);}
void fun_00719e90(Memory&m,State&s,const Operations&o){header_free(m,s,o,true,false,0,false,false);}void fun_00719f90(Memory&m,State&s,const Operations&o){header_free(m,s,o,false,true,0x799e3c,true,true);}void fun_00719ff0(Memory&m,State&s,const Operations&o){header_free(m,s,o,false,true,0x799e3c,true,true);}void fun_0071a1c0(Memory&m,State&s,const Operations&o){header_free(m,s,o,false,false,0,false,false);}
void fun_00727810(Memory&m,State&s,const Operations&o){simple_owned(m,s,o,0x7874fc);}
void fun_00757080(Memory& m, State& s, const Operations& o) {
    const auto obj = s.cx;
    if (m.r32(obj + 0x18) == 0) {
        m.w32(obj + 0x4385c, 0);
        m.w32(obj + 0x43850, 0);
        return; // The original never writes EAX on this entry path.
    }

    for (;;) {
        const auto array = m.r32(obj + 0x0c);
        const auto node = m.r32(array);
        s.ax = node;
        if (m.r8(node + 0x46) != 0) {
            rel(m, s, o, node);
        } else {
            m.w8(node + 0x45, 0);
            s.ax = m.r32(obj + 0x4385c) - 1u;
            m.w32(obj + 0x4385c, s.ax);
        }

        auto count = m.r32(obj + 0x18);
        s.ax = count;
        if (s32(count) <= 0) break; // Preserve the loaded count at cleanup.

        const auto next_count = count - 1u;
        s.cx = next_count;
        m.w32(obj + 0x18, next_count);
        s.ax = 0;
        if (s32(next_count) > 0) {
            const auto entries = m.r32(obj + 0x0c);
            s.cx = entries;
            std::uint32_t index = 0;
            do {
                ++index;
                s.ax = index;
                const auto shifted = m.r32(entries + index * 4u);
                s.dx = shifted;
                m.w32(entries + (index - 1u) * 4u, shifted);
                count = m.r32(obj + 0x18);
                s.cx = count;
            } while (s32(index) < s32(count));
        }
        if (m.r32(obj + 0x18) == 0) break;
    }
    m.w32(obj + 0x4385c, 0);
    m.w32(obj + 0x43850, 0);
}
void fun_007582e0(Memory& m, State& s, const Operations& o) {
    const auto obj = s.cx;
    auto count = m.r32(obj + 0x43b0c);
    s.ax = count;
    if (count == 0) return;

    for (;;) {
        const auto array = m.r32(obj + 0x43b00);
        const auto p = m.r32(array);
        s.ax = p;
        s.cx = p;
        rel(m, s, o, p);

        count = m.r32(obj + 0x43b0c);
        s.ax = count;
        if (s32(count) <= 0) return;

        const auto next_count = count - 1u;
        s.cx = next_count;
        m.w32(obj + 0x43b0c, next_count);
        s.ax = 0;
        if (s32(next_count) > 0) {
            const auto entries = m.r32(obj + 0x43b00);
            s.cx = entries;
            std::uint32_t index = 0;
            do {
                ++index;
                s.ax = index;
                const auto shifted = m.r32(entries + index * 4u);
                s.dx = shifted;
                m.w32(entries + (index - 1u) * 4u, shifted);
                count = m.r32(obj + 0x43b0c);
                s.cx = count;
            } while (s32(index) < s32(count));
        }
        count = m.r32(obj + 0x43b0c);
        s.ax = count;
        if (count == 0) return;
    }
}
void ptr_slot(Memory&m,State&s,const Operations&o){auto obj=s.cx,p=m.r32(obj);s.ax=p;if(p)rel(m,s,o,p);m.w32(obj,0);}
void fun_00759320(Memory&m,State&s,const Operations&o){ptr_slot(m,s,o);}void fun_00759f70(Memory&m,State&s,const Operations&o){ptr_slot(m,s,o);}void fun_0075b390(Memory&m,State&s,const Operations&o){ptr_slot(m,s,o);}void fun_0075bc70(Memory&m,State&s,const Operations&o){ptr_slot(m,s,o);}
void fun_00776b01(Memory&m,State&s,const Operations&o){auto obj=s.cx;const auto condition=m.r32(obj+8);m.w32(obj,0x79c81c);if(condition){auto p=m.r32(obj+4);rel(m,s,o,p);s.cx=p;}}
}

const std::array<Entry,43>& entries_b(){static const std::array<Entry,43> e{{
 {0x1ce5d0,fun_005ce5d0},{0x1d0700,fun_005d0700},{0x1f80b0,fun_005f80b0},{0x216930,fun_00616930},{0x2169f0,fun_006169f0},{0x2268a0,fun_006268a0},
 {0x22f900,fun_0062f900},{0x22fc00,fun_0062fc00},
 {0x236460,fun_00636460},{0x2364b0,fun_006364b0},{0x2498b0,fun_006498b0},{0x2498e0,fun_006498e0},{0x249910,fun_00649910},
 {0x25e860,fun_0065e860},{0x25f380,fun_0065f380},{0x25f3e0,fun_0065f3e0},{0x25f440,fun_0065f440},{0x26ab20,fun_0066ab20},
 {0x277c70,fun_00677c70},{0x290790,fun_00690790},{0x295b90,fun_00695b90},
 {0x2b59b0,fun_006b59b0},{0x2b5c00,fun_006b5c00},{0x2b5e80,fun_006b5e80},{0x2b5ee0,fun_006b5ee0},{0x2b5f20,fun_006b5f20},
 {0x300390,fun_00700390},{0x306830,fun_00706830},{0x30dc80,fun_0070dc80},{0x30dcd0,fun_0070dcd0},
 {0x310930,fun_00710930},{0x319e90,fun_00719e90},{0x319f90,fun_00719f90},{0x319ff0,fun_00719ff0},{0x31a1c0,fun_0071a1c0},
 {0x327810,fun_00727810},{0x357080,fun_00757080},{0x3582e0,fun_007582e0},
 {0x359320,fun_00759320},{0x359f70,fun_00759f70},{0x35b390,fun_0075b390},{0x35bc70,fun_0075bc70},{0x376b01,fun_00776b01}
}};return e;}
} // namespace ra2::recovered::heap_b29
