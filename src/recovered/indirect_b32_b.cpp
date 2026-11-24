#include "recovered/indirect_b32_memory.hpp"
#include <stdexcept>
#include <string>

namespace ra2::recovered::indirect_b32 {
namespace {
void call(Memory& m, State& s, Frame& f, const Operations& op, std::uint32_t target) {
    invoke(m, s, f, op, target);
}
void complete(Memory& m, State& s, Frame& f, std::uint32_t cleanup) {
    if (f.sp != f.entry_sp)
        throw std::runtime_error("B32 caller stack delta=" + std::to_string(std::int64_t(f.sp)-std::int64_t(f.entry_sp)));
    finish(m, s, f, cleanup);
}
std::uint32_t vcall_target(Memory& m, State& s, std::uint32_t object, std::uint32_t slot) {
    s.ax = m.r32(object);
    return m.r32(s.ax + slot);
}
void pop_esi(Memory& m, State& s, Frame& f) { s.si = f.pop(m); }
void pop_edi(Memory& m, State& s, Frame& f) { s.di = f.pop(m); }

void linked_search(Memory& m, State& s, Frame& f, const Operations& op,
                   std::uint32_t sentinel, bool use_second_head, bool has_selector,
                   bool has_sentinel, std::uint32_t outer_cleanup, bool push_edi) {
    const bool gate = m.r8(0x00a285a8u) != 0;
    f.push(m, s.si);
    if (push_edi) f.push(m, s.di);
    if (!gate) {
        if (push_edi) pop_edi(m, s, f);
        s.ax = 0;
        pop_esi(m, s, f);
        complete(m, s, f, outer_cleanup);
        return;
    }

    std::uint32_t receiver = s.cx;
    if (has_selector) {
        const std::uint32_t selector_address = f.sp + (push_edi ? 0x10u : 0x8u);
        use_second_head = m.r8(selector_address) != 0;
    }
    std::uint32_t node = m.r32(receiver + (use_second_head ? 0xe8u : 0xe4u));
    if (has_sentinel) {
        const std::uint32_t sentinel_address = f.sp + 0x0cu;
        sentinel = m.r32(sentinel_address);
    }

    while (node != 0) {
        s.si = node;
        s.cx = node;
        const auto target = vcall_target(m, s, node, 0x2cu);
        s.cx = node;
        call(m, s, f, op, target);
        const bool found = has_sentinel ? s.ax == sentinel : s.ax == sentinel;
        if (found) {
            s.ax = s.si;
            if (push_edi) pop_edi(m, s, f);
            pop_esi(m, s, f);
            complete(m, s, f, outer_cleanup);
            return;
        }
        node = m.r32(s.si + 0x30u);
    }

    if (push_edi) pop_edi(m, s, f);
    s.ax = 0;
    pop_esi(m, s, f);
    complete(m, s, f, outer_cleanup);
}

void fun_00471360(Memory& m, State& s, Frame& f, const Operations& op) {
    // The original pushes ESI, then EDI, and reads argument 1 as the head selector.
    f.push(m, s.si);
    const bool gate = m.r8(0x00a285a8u) != 0;
    f.push(m, s.di);
    if (!gate) {
        pop_edi(m,s,f); s.ax=0; pop_esi(m,s,f); complete(m,s,f,8); return;
    }
    const auto selector = m.r8(f.sp + 0x10u);
    std::uint32_t node = m.r32(s.cx + (selector ? 0xe8u : 0xe4u));
    s.di = m.r32(f.sp + 0x0cu);
    while (node) {
        s.si=node; s.cx=node;
        const auto target=vcall_target(m,s,node,0x2cu); s.cx=node;
        call(m,s,f,op,target);
        if (s.ax==s.di) { s.ax=s.si; pop_edi(m,s,f); pop_esi(m,s,f); complete(m,s,f,8); return; }
        node=m.r32(s.si+0x30u);
    }
    pop_edi(m,s,f); s.ax=0; pop_esi(m,s,f); complete(m,s,f,8);
}

void fun_004713b0(Memory& m, State& s, Frame& f, const Operations& op) {
    const bool gate=m.r8(0x00a285a8u)!=0; f.push(m,s.si);
    if(!gate){s.ax=0;pop_esi(m,s,f);complete(m,s,f,0);return;}
    auto node=m.r32(s.cx+0xe4u);
    while(node){s.si=node;s.cx=node;const auto target=vcall_target(m,s,node,0x2cu);s.cx=node;call(m,s,f,op,target);
        if(s.ax==6u){s.ax=s.si;pop_esi(m,s,f);complete(m,s,f,0);return;}node=m.r32(s.si+0x30u);}
    s.ax=0;pop_esi(m,s,f);complete(m,s,f,0);
}

void fun_004713e0(Memory& m, State& s, Frame& f, const Operations& op) {
    linked_search(m,s,f,op,0x24u,false,true,false,4,false);
}
void fun_00473a30(Memory& m, State& s, Frame& f, const Operations& op) {
    linked_search(m,s,f,op,1u,false,true,false,4,false);
}
void fun_00473a80(Memory& m, State& s, Frame& f, const Operations& op) {
    linked_search(m,s,f,op,2u,false,true,false,4,false);
}
void fun_00473ad0(Memory& m, State& s, Frame& f, const Operations& op) {
    linked_search(m,s,f,op,0x0fu,false,true,false,4,false);
}

void fun_00478340(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m,s.si); s.si=m.r32(s.cx+0xe4u);
    while(s.si){s.ax=m.r32(s.si);s.cx=s.si;const auto target=m.r32(s.ax+0xf4u);call(m,s,f,op,target);s.si=m.r32(s.si+0x30u);}
    pop_esi(m,s,f);complete(m,s,f,0);
}

void fun_0047c9d0(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m,s.si);f.push(m,s.di);s.di=s.cx;
    s.ax=with_al(s.ax,m.r8(s.di+0x11cu));
    if((s.ax&0xffu)!=0){pop_edi(m,s,f);s.ax=with_al(s.ax,0);pop_esi(m,s,f);complete(m,s,f,0);return;}
    s.ax=with_al(s.ax,m.r8(0x00a285a8u));
    if((s.ax&0xffu)!=0){
        s.si=m.r32(s.di+0xe4u);
        while(s.si){
            s.ax=m.r32(s.si);s.cx=s.si;const auto target=m.r32(s.ax+0x2cu);s.cx=s.si;call(m,s,f,op,target);
            if(s.ax==6u){if(s.si!=0){pop_edi(m,s,f);s.ax=with_al(s.ax,0);pop_esi(m,s,f);complete(m,s,f,0);return;}break;}
            s.si=m.r32(s.si+0x30u);
        }
    }
    s.ax=m.r32(s.di+0xecu);pop_edi(m,s,f);pop_esi(m,s,f);
    s.cx=s.ax+(s.ax*8u);s.ax=with_al(s.ax,m.r8(0x008391f0u+s.cx*4u));complete(m,s,f,0);
}

void walk_object_vtable(Memory& m, State& s, Frame& f, const Operations& op,
                        std::uint32_t slot, bool literal_args) {
    f.push(m,s.si); f.push(m,s.di); s.di=s.cx; s.si=m.r32(s.di+0x54u);
    while(s.si){
        s.ax=m.r32(s.si);
        if(literal_args){f.push(m,0);f.push(m,1);f.push(m,0x00aa7b78u);}
        s.cx=s.si;const auto target=m.r32(s.ax+slot);call(m,s,f,op,target);
        s.si=m.r32(s.si+0x4c8u);
    }
    m.w8(s.di+0x80u,1);
    pop_edi(m,s,f);pop_esi(m,s,f);complete(m,s,f,8);
}
void fun_006b0960(Memory& m,State& s,Frame& f,const Operations& op){walk_object_vtable(m,s,f,op,0x15cu,true);}
void fun_006b1690(Memory& m,State& s,Frame& f,const Operations& op){walk_object_vtable(m,s,f,op,0x4a0u,false);}
void fun_006b1780(Memory& m,State& s,Frame& f,const Operations& op){walk_object_vtable(m,s,f,op,0x49cu,false);}
void fun_006b17b0(Memory& m,State& s,Frame& f,const Operations& op){walk_object_vtable(m,s,f,op,0x498u,false);}

void fun_006b1c00(Memory& m,State& s,Frame& f,const Operations& op){
    f.push(m,s.si);f.push(m,s.di);s.di=s.cx;s.si=m.r32(s.di+0x54u);
    while(s.si){
        s.ax=m.r32(s.si);s.cx=s.si;const auto target=m.r32(s.ax+0x80u);call(m,s,f,op,target);
        s.cx=m.r32(s.ax+0x52cu);s.ax=m.r32(s.si+0xf8u);
        if(s32(s.cx)>s32(s.ax)){pop_edi(m,s,f);pop_esi(m,s,f);complete(m,s,f,8);return;}
        s.si=m.r32(s.si+0x4c8u);
    }
    m.w8(s.di+0x80u,1);pop_edi(m,s,f);pop_esi(m,s,f);complete(m,s,f,8);
}

} // namespace

const std::array<Entry,13>& entries_b(){
    static const std::array<Entry,13> value{{
        {0x71360u,fun_00471360},{0x713b0u,fun_004713b0},{0x713e0u,fun_004713e0},
        {0x73a30u,fun_00473a30},{0x73a80u,fun_00473a80},{0x73ad0u,fun_00473ad0},
        {0x78340u,fun_00478340},{0x7c9d0u,fun_0047c9d0},{0x2b0960u,fun_006b0960},
        {0x2b1690u,fun_006b1690},{0x2b1780u,fun_006b1780},{0x2b17b0u,fun_006b17b0},
        {0x2b1c00u,fun_006b1c00}}};return value;
}
} // namespace ra2::recovered::indirect_b32


