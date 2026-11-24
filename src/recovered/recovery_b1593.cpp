#include "recovered/recovery_b1593.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/recovery_b607.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1593 {
namespace {
void need(bool v) { if (!v) throw std::domain_error("B1593 selected low-height reset route"); }
struct Span { U address, size; };
void disjoint(Memory& m,U self,U owner,U cell,U table) {
  const std::array<Span, 13> spans{{
    {self, 0x80u}, {owner, 0x14c0u},
    {cell, 0x200u}, {table, 1540u*4u},
    {0x785000u,0x1000u}, {0x78d000u,0x1000u}, {0x798000u,0x1000u},
    {0x79a000u,0x1000u}, {0x7c3000u,0x1000u}, {0x81a000u,0x1000u},
    {0x838000u,0x1000u}, {0x7d000000u,0x8000u}, {0x7d020000u,0x1000u}
  }};
  for (U j=0;j<spans.size();++j) {
    const auto& a=spans[j];
    need(a.address && a.size && std::uint64_t(a.address)+a.size<=0x100000000ull);
    if (j<11) { (void)m.r8(a.address); (void)m.r8(a.address+a.size-1); }
    for (U k=0;k<j;++k) {
      const auto& b=spans[k];
      need(std::uint64_t(a.address)+a.size<=b.address || std::uint64_t(b.address)+b.size<=a.address);
    }
  }
}
}
U fun_004bda60(Memory& m,const Inputs& i) {
  const U self=i.cx, owner=m.r32(self+0x0cu), table=m.r32(0x81a958u);
  const U cell=m.r32(table+1539u*4u);
  constexpr U xy=0x7d020000u, iid=0x7c3198u;
  std::array<std::uint8_t,0x1000> private_xy{};
  leaf::Memory xy_span(private_xy.data(),xy,U(private_xy.size()));
  Memory local=m; local.add(xy_span);
  disjoint(local,self,owner,cell,table);
  constexpr std::uint16_t valid_cw[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};
  bool known_cw=false;for(auto c:valid_cw)known_cw=known_cw||i.fp.image.word(0)==c;
  need(known_cw && (i.fp.image.word(4)&~0x3800u)==0 && i.fp.image.word(8)==0xffffu);
  need(i.cx==self && m.r32(self+0x0c)==owner);
  need(m.r32(0x81a95cu)>=1540u && m.r32(owner)==0x798c88u &&
       m.r32(0x798c88u)==0x410000u && m.r32(0x798c88u+0x1b0u)==0x5ccea0u &&
       m.r8(owner+0x79u)==0);
  need(m.r32(self+0x38u)==16u && m.r8(self+0x50u)!=0 && m.r8(self+0x51u)!=0);
  need(m.r32(owner+0x88u)==768u && m.r32(owner+0x8cu)==768u);
  const U z=m.r32(owner+0x90u); need(z<=7u);
  need(m.r32(table+1539u*4u)==cell && m.r8(cell+0x11bu)==0 &&
       m.r8(cell+0x11cu)==0 && (m.r32(cell+0x140u)&0x100u)==0);
  need(m.r8(0x838f70u)==7u && m.r32(0x838f80u)!=0 &&
       floating_b61::read64(m,0x785728u)==0x3fe0000000000000ull &&
       m.r32(0x7c3a04u)==0x0e7fu);

  // The proven 5CCEA0 -> 557070 -> 4702C0 composition. Coordinates are passed
  // as a private XY pair; the selected flat cell has no 11C sidecar path.
  local.w32(xy,768u); local.w32(xy+4,768u);
  Inputs height{}; height.cx=cell; height.arg[0]=xy; height.fp=i.fp;
  const U cell_height=map_b106::fun_004702c0(local,height);
  i.fp=height.fp;
  need(cell_height==0u && z-cell_height<=7u);

  // Genuine unsupported IID call: B607's unchanged implementation writes the
  // output pointer to NULL and returns E_NOINTERFACE. The following BF830 arm
  // observes NULL and therefore performs no callback or owned-object action.
  Inputs qi{}; qi.arg[0]=owner; qi.arg[1]=iid; qi.arg[2]=xy; qi.fp=i.fp;
  const U hr=recovery_b607::fun_00410000(local,qi); i.fp=qi.fp;
  need(hr==0x80004002u && local.r32(xy)==0u);
  // Root's signed-height branch selects 4BDBFE for height <= self+38/2 (8).
  need(z-cell_height<=m.r32(self+0x38u)/2u);
  m.w8(self+0x50u,0); m.w8(self+0x51u,0);
  return 1u;
}
}

