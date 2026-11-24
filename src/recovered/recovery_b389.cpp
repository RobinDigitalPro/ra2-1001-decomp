#include "recovered/recovery_b389.hpp"
#include "recovered/recovery_b359.hpp"

#include <array>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b389 {
namespace {
using U=std::uint32_t;
void require(bool ok,const char*message){if(!ok)throw std::domain_error(message);}

// Exact accepted 0x32030 read path, specialized to its two original B389
// call sites and the one-entry A map in the staged B359 graph.
U lookup_a(Memory&m){
    const U font=m.r32(0x836d30u);require(font!=0u,"B389 requires the staged font global");
    const U descriptor=m.r32(font+4u);if(!descriptor)return 0u;
    const U table=m.r32(descriptor+0x18u);if(!table)return 0u;
    const U entry=m.r16(table+0x41u*2u);if(!entry)return 0u;
    const U row=m.r32(descriptor+0x14u)*(entry-1u)+m.r32(descriptor+0x1cu);
    return row?m.r8(row):0u;
}

// Exact accepted 0x36f406 search behavior for the root's UTF-16 delimiter 9.
U find_delimiter_9(Memory&m,U text){
    for(U k=0;k<0x100u;++k){const U ch=m.r16(text+2u*k);if(ch==9u)return text+2u*k;if(ch==0u)return 0u;}
    throw std::domain_error("B389 UTF-16 text lacks a bounded NUL terminator");
}
}

U fun_00497ac0(Memory&caller,const Inputs&i){
    std::array<std::uint8_t,0x400> private_bytes{};
    constexpr U scratch=0xf0000000u;
    leaf::Memory private_span(private_bytes.data(),scratch,private_bytes.size());
    Memory m=caller;m.add(private_span);
    // Entry contract from original 0x97ac0: ECX is the result pair, EDX is a
    // UTF-16 source pointer; arg[2] is the initial cursor pair; arg[6] bounds
    // the scan; arg[7] is the optional range pointer. This draft accepts only
    // one A, a scalar (null-range) route, and the B359 zero-flags renderer.
    require(i.cx!=0u&&i.dx!=0u,"B389 requires result receiver and UTF-16 source");
    require(i.arg[0]!=0u&&i.arg[1]!=0u&&i.arg[2]!=0u&&i.arg[3]!=0u,
            "B389 requires surface, clip, cursor pair and color arguments");
    require(i.arg[4]==0u&&i.arg[5]==0u,"B389 only covers forwarded zero auxiliary/flags words");
    require(i.arg[6]>=3u&&i.arg[6]<=7u&&i.arg[7]==0u,"B389 requires width3..7 and null optional range pointer");
    require(m.r16(i.dx)==0x41u&&m.r16(i.dx+2u)==0u,
            "B389 covers exactly one terminated UTF-16 A");
    require(m.r32(i.arg[2])==0u&&m.r32(i.arg[2]+4u)==0u,
            "B389 requires the staged zero cursor pair");
    const U width=lookup_a(m);
    require(width==2u,
            "B389 requires the pinned one-entry A glyph to fit the width bound without the truncation lookup");

    const U private_text=scratch+0x200u;
    // 0x36efc9 copies bounded UTF-16 units through the first NUL. The source
    // check above and private destination preserve its positive copy path.
    for(U k=0;k<0x100u;++k){const U ch=m.r16(i.dx+2u*k);m.w16(private_text+2u*k,ch);if(ch==0u)break;}
    require(find_delimiter_9(m,private_text)==0u,
            "B389 delimiter scan must reach the one-A terminator without a tab");

    // At the original 0x97610 call (0x497be4), root forwards stack args0/1/3/4/5 and substitutes a private
    // cursor pair forarg2 and pushes constant 1 as arg[6]. Its ECX/EDX point at private
    // stack locals. Compose the accepted B359 one-A renderer on equivalent
    // private guest state; only its authentic font/surface effects survive.
    const U local_result=scratch+0x100u;
    m.w32(local_result,m.r32(i.arg[2]));m.w32(local_result+4u,m.r32(i.arg[2]+4u));
    Inputs child{};child.cx=local_result;child.dx=private_text;
    child.arg[0]=i.arg[0];child.arg[1]=i.arg[1];child.arg[2]=local_result;
    child.arg[3]=i.arg[3];child.arg[4]=i.arg[4];child.arg[5]=i.arg[5];child.arg[6]=1u;
    const U rendered=ra2::recovered::recovery_b359::fun_00497610(m,child);
    require(rendered==local_result,"B389 B359 composition did not return the local result pair");
    const U out_x=m.r32(local_result),out_y=m.r32(local_result+4u);
    m.w32(i.cx,out_x);m.w32(i.cx+4u,out_y);
    return i.cx;
}
}
