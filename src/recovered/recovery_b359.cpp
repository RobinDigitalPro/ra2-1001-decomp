#include "recovery_b359.hpp"

#include "recovered/leaf_memory.hpp"


#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b359 {
namespace {
using U=std::uint32_t;
void require(bool ok,const char* what){if(!ok)throw std::domain_error(what);}
}

U fun_00497610(Memory&m,const Inputs&i) {
    require(i.cx&&i.dx,"B359 requires receiver and UTF-16 input");
    require(i.arg[5]==0,"B359 covers flags zero");
    require(m.r16(i.dx)=='A'&&m.r16(i.dx+2u)==0,"B359 covers one UTF-16 A");
    const U surface=i.arg[0],clip=i.arg[1],point=i.arg[2],color=i.arg[3];
    const U font=m.r32(0x836d30u);
    require(surface==m.r32(0x836d18u)&&font,"B359 requires the staged surface/font globals");
    require(m.r32(surface)==0x785ef8u&&m.r32(surface+4u)==8u&&
            m.r32(surface+8u)==8u&&m.r32(surface+0x10u)==2u,
            "B359 requires the constructor-proven 8x8 16-bit surface");
    require(m.r32(font+4u)&&m.r16(m.r32(m.r32(font+4u)+0x18u)+0x41u*2u)==1u,
            "B359 requires the parsed one-entry A map");
    const U desc=m.r32(font+4u),glyph=m.r32(desc+0x1cu);
    require(m.r32(desc+0x14u)==3u&&m.r32(desc+8u)==2u&&
            m.r8(glyph)==2u&&m.r8(glyph+1u)==0xc0u&&m.r8(glyph+2u)==0x80u,
            "B359 requires the literal 2x2 A glyph record");
    require(m.r32(clip)==2u&&m.r32(clip+4u)==2u&&
            m.r32(clip+8u)==2u&&m.r32(clip+12u)==2u&&
            m.r32(point)==0u&&m.r32(point+4u)==0u,
            "B359 requires a 2x2 clip at surface origin (2,2)");

    // Specialize the already-reviewed metrics semantics to one mapped A.
    // There is no newline/tab/wrapping; width2 fits the caller's width2 limit.
    require(m.r32(font+0x1cu)==2u && m.r32(font+0x2cu)==0u && m.r32(font+0x18u)==1u,
            "B359 finite height/spacing/bitmap stride");
    const U width=m.r8(glyph)+m.r32(font+0x2cu),height=m.r32(font+0x1cu);
    i.arg[1]=height;i.arg[2]=width;

    // Exact field effects of the accepted one-field setter bodies at 0x31310,
    // 0x31320, 0x312f0 and 0x31790.
    m.w8(font+0x41u,1u);
    const U root_x=m.r32(clip)+m.r32(point),root_y=m.r32(clip+4u)+m.r32(point+4u);
    m.w32(font+0x30u,root_x);m.w32(font+0x34u,root_y);
    m.w32(font+0x38u,root_x+2u);m.w32(font+0x3cu,root_y+2u);
    m.w16(font+0x24u,color);m.w32(font+0x20u,root_x);

    // The route locks the 16-bit surface, visits the one mapped glyph, writes
    // only set row-mask bits, then reaches the original unlock effects.
    m.w32(surface+0x0cu,m.r32(surface+0x0cu)+1u);
    m.w32(font+0x0cu,m.r32(surface+0x14u));
    m.w32(font+0x10u,8u);
    for(U row=0;row<2u;++row) {
        const U mask=m.r8(glyph+1u+row);
        for(U col=0;col<2u;++col) {
            const U x=root_x+col,y=root_y+row;
            if(x>=2u&&x<4u&&y>=2u&&y<4u&&((mask>>(7u-col))&1u))
                m.w16(m.r32(surface+0x14u)+2u*(y*8u+x),color);
        }
    }
    m.w32(font+0x0cu,0u);m.w32(font+0x10u,0u);
    m.w32(surface+0x0cu,m.r32(surface+0x0cu)-1u);
    m.w32(i.cx,root_x);m.w32(i.cx+4u,root_y);
    return i.cx;
}
}
