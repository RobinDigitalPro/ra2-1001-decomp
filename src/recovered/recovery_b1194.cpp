#include "recovery_b1194.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::recovered::b1194{
static unsigned word(const unsigned char*p,unsigned o){unsigned v;std::memcpy(&v,p+o,4u);return v;}
static void need(bool x){if(!x)throw std::domain_error("1194 bounded owned realDirectDraw successful query");}
unsigned run(Memory&m,const Inputs&,Api&api,Observation&seen){
 need(m.r32(0x83a6fcu)==0u);seen.create_hr=api.create(0u,0x83a6fcu,0u);++seen.calls;need(seen.create_hr==0u);seen.object=m.r32(0x83a6fcu);need(seen.object!=0u);
 // Original initializes only dwSize beforeGetCaps. The remaining312 bytes are
 // indeterminate private storage. Zero here is a model-local safe initialization,
 // not an original-stack producer claim: actual provider must overwrite all316
 // bytes as independently checked with A5/5A/zero reference inputs.
 alignas(4) Caps caps{};caps[0]=0x3cu;caps[1]=1u;seen.caps_hr=api.caps(seen.object,caps,0u);++seen.calls;need(seen.caps_hr==0u);seen.hardware=caps;
 alignas(4) Mode mode{};mode[0]=108u;seen.mode_hr=api.mode(seen.object,mode);++seen.calls;need(seen.mode_hr==0u);seen.display=mode;
 unsigned total=word(caps.data(),0x3cu);unsigned bytes=word(mode.data(),0x54u)>>3u;bytes*=word(mode.data(),0xcu);bytes*=word(mode.data(),8u);total+=bytes;total+=0x20000u;total&=0xfff00000u;
 seen.release_result=api.release(seen.object);++seen.calls;need(seen.release_result==0u);m.w32(0x83a6fcu,0u);return total;
}
}
