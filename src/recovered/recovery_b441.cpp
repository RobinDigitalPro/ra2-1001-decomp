#include "recovered/recovery_b441.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::gdi441 {
namespace {
constexpr std::uint32_t kEnabled=0xa58b22u, kOwner=0xa58b24u, kWindow=0xa58b28u;
constexpr std::uint32_t kFont=0xa58b2cu, kBk=0xa58a00u, kText=0xa58a18u;
constexpr std::uint32_t kGlyphState=0x7d0u, kGlyphByte=0u;
std::uint32_t transform(std::uint32_t c) {
    switch(static_cast<std::uint8_t>(c)) {
    case 0x0a: return 0x20; case 0xb3: return 0x7c; case 0xc4: return 0x2d;
    case 0xcd: return 0x3d;
    case 0xb4: case 0xda: case 0xc2: case 0xbf: case 0xc6: case 0xc3:
    case 0xd1: case 0xc5: case 0xd8: case 0xb5: case 0xc0: case 0xc1:
    case 0xd9: case 0xd5: return 0x2b;
    default: return static_cast<std::uint8_t>(c);
    }
}
std::uint32_t glyph_bk(void* p,std::uint32_t dc,std::uint32_t color) {
    auto& o=*static_cast<const Ops*>(p); return o.set_bk_color(o.context,dc,color);
}
std::uint32_t glyph_text_color(void* p,std::uint32_t dc,std::uint32_t color) {
    auto& o=*static_cast<const Ops*>(p); return o.set_text_color(o.context,dc,color);
}
std::uint32_t glyph_text(void* p,std::uint32_t dc,std::int32_t x,std::int32_t y,std::uint32_t str,std::uint32_t n) {
    auto& o=*static_cast<const Ops*>(p); return o.text_out_a(o.context,dc,x,y,str,n);
}
void require_ops(const Ops& o) {
    if(!o.get_dc||!o.set_bk_mode||!o.select_object||!o.set_bk_color||
       !o.set_text_color||!o.text_out_a||!o.release_dc||!o.nested_stack_address)
        throw std::domain_error("B441 requires the complete observed Win32 API route and mapped nested stack");
}
}

std::uint32_t fun_0059b880(Memory& m,const Inputs& i,const Ops& o) {
    require_ops(o);
    const auto active=m.r8(kEnabled);
    if(!active || i.cx!=m.r32(kOwner)) return (i.ax&0xffffff00u)|active;
    const auto hwnd=m.r32(kWindow);
    const auto dc=o.get_dc(o.context,hwnd);
    (void)o.set_bk_mode(o.context,dc,2u);
    (void)o.set_bk_color(o.context,dc,m.r32(kText));
    (void)o.set_text_color(o.context,dc,m.r32(kBk));
    const auto old_font=o.select_object(o.context,dc,m.r32(kFont));
    const auto start_index=i.arg[0], start_offset=i.arg[1];
    const auto end_index=start_index+i.arg[2], end_offset=start_offset+i.arg[3];
    i.arg[1]=end_offset; // original MOV [ESP+0x18],EAX writes caller word 1
    for(auto offset=start_offset;offset<end_offset;++offset) {
        for(auto index=start_index;index<end_index;++index) {
            const auto base=o.nested_stack_address;
            m.w32(base,0x44105a5au); m.w32(base+4u,dc); m.w32(base+8u,index); m.w32(base+12u,offset);
            Inputs glyph{}; glyph.cx=i.cx; glyph.arg[0]=dc; glyph.arg[1]=index; glyph.arg[2]=offset;
            ra2::recovered::gdi438::Ops go{const_cast<Ops*>(&o),glyph_bk,glyph_text_color,glyph_text};
            (void)ra2::recovered::gdi438::fun_0059b7c0(m,glyph,base+8u,go);
        }
    }
    (void)o.select_object(o.context,dc,old_font);
    return o.release_dc(o.context,hwnd,dc);
}

std::uint32_t fun_0059b4c0(Memory& m,const Inputs& i,const Ops& o) {
    require_ops(o);
    if(!m.r8(kEnabled)) return (i.ax&0xffffff00u)|m.r8(kEnabled);
    const auto receiver=i.cx;
    const auto src=i.arg[0];
    m.w8(receiver+0x2734u,0u);
    std::uint32_t length=0; while(m.r8(src+length)) ++length;
    const auto base=m.r32(receiver+0x2728u)+m.r32(receiver+0x2720u);
    const auto start=m.r32(receiver+0x2724u)+m.r32(receiver+0x271cu);
    const auto limit=m.r32(receiver+0x272cu)+m.r32(receiver+0x2724u);
    auto end=length+start;
    if(static_cast<std::int32_t>(end)>static_cast<std::int32_t>(limit)) end=limit;
    std::uint8_t last_input=0;
    if(static_cast<std::int32_t>(start)<static_cast<std::int32_t>(end)) {
        for(auto index=start;index<end;++index) {
            const auto c=m.r8(src+(index-start));
            last_input=std::uint8_t(c);
            const auto mapped=transform(c);
            m.w8(receiver+base+kGlyphByte+25u*index,mapped);
            m.w32(receiver+kGlyphState+4u*base+100u*index,m.r32(receiver+0x2710u));
            if(c==0x0au) { m.w32(receiver+0x271cu,0u); m.w32(receiver+0x2720u,m.r32(receiver+0x2720u)+1u); }
            else m.w32(receiver+0x271cu,m.r32(receiver+0x271cu)+1u);
        }
    }
    if(static_cast<std::int32_t>(start)<static_cast<std::int32_t>(end))
        i.arg[0]=(i.arg[0]&0xffffff00u)|last_input; // original MOV [ESP+0x24],AL writes caller word 0 low byte
    Inputs draw{}; draw.cx=receiver; draw.ax=i.ax;
    draw.arg[0]=start; draw.arg[1]=base; draw.arg[2]=end-start; draw.arg[3]=1u;
    return fun_0059b880(m,draw,o);
}
}
