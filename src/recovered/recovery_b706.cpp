#include "recovery_b706.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b706 {
namespace {
using U=std::uint32_t;
void require(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
constexpr U font_global=0x836d30u;
constexpr U font_off=0x2000u,desc_off=0x3000u,glyph_off=0x5000u;
constexpr U pixels_off=0x7000u,text_off=0x8000u;

U draw_a(Memory&m,U font,U x,U y) {
    const U desc=m.r32(font+4u);
    const U code=0x41u;
    const U ordinal=m.r16(m.r32(desc+0x18u)+code*2u);
    require(ordinal==1u,"text706 requires the constructor-seeded A glyph mapping");
    const U glyph=m.r32(desc+0x1cu)+(ordinal-1u)*m.r32(desc+0x14u);
    const U width=m.r8(glyph),height=m.r32(desc+8u);
    require(width==2u&&height==2u&&m.r8(glyph+1u)==0xc0u&&m.r8(glyph+2u)==0x80u,
            "text706 requires the pinned 2x2 A glyph record");
    require(m.r8(font+0x41u)!=0u,"text706 uses the clipped drawing path selected by font+0x41");
    const U pixel_base=m.r32(font+0x0cu),surface_width=m.r32(font+0x10u),glyph_row_stride=m.r32(font+0x18u);
    require(pixel_base&&surface_width==8u&&glyph_row_stride==1u,
            "text706 requires the pinned 8-pixel surface and one-byte glyph row stride");

    // The original CALL [0x7854A8] receives SetRect(left=x,top=y,
    // right=x+width-1,bottom=y+height-1). Its output is clipped by the
    // accepted 0x31EC0 helper semantics; the bounded fixture is fully visible.
    const U clip_l=m.r32(font+0x30u),clip_t=m.r32(font+0x34u);
    const U clip_r=m.r32(font+0x38u),clip_b=m.r32(font+0x3cu);
    const U left=x>clip_l?x:clip_l,top=y>clip_t?y:clip_t;
    const U right=(x+width-1u)<clip_r?(x+width-1u):clip_r;
    const U bottom=(y+height-1u)<clip_b?(y+height-1u):clip_b;
    if(static_cast<std::int32_t>(left)>static_cast<std::int32_t>(right)||
       static_cast<std::int32_t>(top)>static_cast<std::int32_t>(bottom))
        return m.r32(font+0x2cu)+width+x;

    const U color=m.r16(font+0x24u);
    for(U row=0;row<height;++row) {
        const U mask=m.r8(glyph+1u+row*glyph_row_stride);
        for(U col=0;col<width;++col) {
            const U px=x+col,py=y+row;
            if(px>=left&&px<=right&&py>=top&&py<=bottom&&((mask>>(7u-col))&1u))
                m.w16(pixel_base+2u*(py*surface_width+px),color);
        }
    }
    return m.r32(font+0x2cu)+width+x;
}
}

U fun_004317a0(Memory&m,const Inputs&i) {
    const U font=i.cx;
    require(font==m.r32(font_global)&&i.arg[0]==0x41u,
            "text706 0x317A0 contract requires the global font and UTF-16 A code");
    require(i.arg[1]==2u&&i.arg[2]==2u&&i.arg[3]==0xffffffffu,
            "text706 0x317A0 contract requires visible (2,2) position and default color");
    const U eax=draw_a(m,font,i.arg[1],i.arg[2]);
    // The original writes its selected WORD color through entry arg0 at
    // [ESP+0x44] after its prologue; preserve the caller word's upper half.
    // Its row-scan loop also reuses caller arg2 as a decrementing temporary
    // and leaves zero on this fully visible two-row route.
    i.arg[0]=(i.arg[0]&0xffff0000u)|m.r16(font+0x24u);
    i.arg[2]=0u;
    const U desc=m.r32(font+4u),glyph=m.r32(desc+0x1cu);
    i.arg[3]=m.r8(glyph);
    return eax;
}

U fun_00431b80(Memory&m,const Inputs&i) {
    const U font=i.cx,text=i.arg[0];
    require(font==m.r32(font_global)&&m.r16(text)==0x41u&&m.r16(text+2u)==0u,
            "text706 0x31B80 contract requires one UTF-16 A");
    require(i.arg[1]==2u&&i.arg[2]==2u&&i.arg[3]==1u&&i.arg[4]==0u,
            "text706 0x31B80 contract requires one character, visible position and modulation disabled");
    const U saved_color=m.r16(font+0x24u);
    Inputs glyph{};glyph.cx=font;glyph.arg[0]=0x41u;glyph.arg[1]=i.arg[1];glyph.arg[2]=i.arg[2];glyph.arg[3]=0xffffffffu;
    const U eax=fun_004317a0(m,glyph);
    // Original 0x31B80 stores its returned pen position into caller arg1 and
    // advances caller arg0 by one UTF-16 code unit, decrements caller arg3
    // once, then restores the saved foreground word.
    i.arg[0]=text+2u;i.arg[1]=eax;i.arg[3]=0u;m.w16(font+0x24u,saved_color);
    return eax;
}
}
