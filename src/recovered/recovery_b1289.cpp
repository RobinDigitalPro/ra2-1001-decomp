#include "recovery_b1289.hpp"
#include <stdexcept>
namespace ra2::recovered::b1289 {
namespace {
void need(bool x,const char*why){if(!x)throw std::domain_error(why);}
constexpr unsigned packed(unsigned x,unsigned y){return (y<<16u)|x;}
void fallback(Memory&m,unsigned value){
 // Both coordinates are explicitly outside the original 512x512 grid.
 const unsigned x=value&0xffffu,y=value>>16u;
 need(x>=1000u&&x<=1036u&&y>=999u&&y<=1031u&&
      x+512u*y>=0x40000u,"1289 genuine out-of-map fallback");
 m.w32(0xa57634u,value); // Original fallback object A57610 + 24.
 need(m.r32(0xa57654u)==0u,"1289 real fallback cell category zero");
}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){
 need(root==0x154ca0u||root==0x154fa0u,"1289 exact vertical root pair");
 need(m.r32(0x81a958u)==0u,"1289 pinned map-grid pointer unused on out-of-range route");
 const auto entry=m.r32(i.arg[0]);
 const unsigned x=entry&0xffffu,y=entry>>16u;
 need(x>=1000u&&x<=1036u&&y>=1000u&&y<=1030u,
      "1289 borrowed finite far-out packed coordinate");
 const unsigned view=m.r32(0x821cacu);
 need(view!=0u&&m.r8(view+0xd7cu)==0u,
      "1289 genuine writable borrowed viewport dirty byte");
 // Both root scans immediately reject the pinned fallback's category 0.
 fallback(m,packed(x,y-1u));fallback(m,packed(x,y+1u));
 // 15AA90/15BBA0 run three real category-zero early returns. The source
 // models their reached instructions: bounds test, fallback publication,
 // category tests, XOR AL,AL, RET4. No nested missing helper is called.
 i.arg[0]=packed(x,y);
 for(unsigned n=0;n<3u;++n)fallback(m,packed(x,y));
 i.arg[0]=packed(x,y+1u);
 fallback(m,packed(x,y+1u));
 b1279::Inputs nested{};nested.cx=i.cx;
 const auto label=b1279::run(0x14c060u,m,nested,h);
 m.w8(view+0xd7cu,1u);
 return label; //554E01/55510D reload ECX; EAX remains best-region label1.
}
}
