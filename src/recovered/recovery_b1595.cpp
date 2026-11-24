#include "recovered/recovery_b1595.hpp"
#include "recovered/preallocated_b66.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1595 {
namespace {
void need(bool v) { if (!v) throw std::domain_error("B1595 finite Air allocation/constructor route"); }
struct Span { U address, size; };
bool overlaps(U a,U n,U b,U m) {
  return std::uint64_t(a)<std::uint64_t(b)+m && std::uint64_t(b)<std::uint64_t(a)+n;
}
void validate_spans(Memory& memory,U object,U air,U descriptor,U coords,U table) {
  const std::array<Span,12> spans{{
    {air,0x5b0u}, {descriptor,0x128u}, {coords,12u}, {table,16u},
    {0x786000u,0x1000u}, {0xa28000u,0x1000u}, {0xa56000u,0x1000u},
    {0xaa7000u,0x1000u}, {0x785000u,0x1000u}, {0x817000u,0x1000u},
    {0xab7000u,0x1000u}, {0xb10000u,0x1000u}
  }};
  if(object)need(std::uint64_t(object)+0x60u<=0x100000000ull);
  for (U k=0;k<spans.size();++k) {
    const auto&s=spans[k];
    need(s.address && std::uint64_t(s.address)+s.size<=0x100000000ull);
    (void)memory.r8(s.address);(void)memory.r8(s.address+s.size-1);
    if(object)need(!overlaps(object,0x60u,s.address,s.size));
    for(U j=0;j<k;++j)need(!overlaps(s.address,s.size,spans[j].address,spans[j].size));
  }
}
U color24(const Memory& m,U p) {
  return (m.r8(p)&0xffu)|((m.r8(p+1u)&0xffu)<<8)|((m.r8(p+2u)&0xffu)<<16);
}
}
U fun_006bf3c0(Memory& original,const Inputs& i,ra2::platform::ordinary_heap::Heap& heap) {
  const U air=i.arg[0], descriptor=i.arg[2], coords=i.arg[3];
  need(air && i.cx==air && descriptor && coords && (original.r8(air+0x14u)&2u));
  need(original.r32(air)==0x78612cu && original.r32(0x78612cu+0xa0u)==0x0041b240u && original.r32(0x78612cu+0x48u)==0x005cd4d0u);
  need(original.r8(descriptor+0x123u)==0);
  const U sentinel=original.r32(0x00aa7c90u);
  need(original.r32(coords)!=sentinel);
  const U table=original.r32(0x00a562ccu);
  // The unchanged B66 constructor has its own exact spare-capacity registry.
  need(original.r32(0x00a562d8u)==0 && original.r32(0x00a562d0u)==4u);
  validate_spans(original,0,air,descriptor,coords,table);
  (void)original.r32(table); (void)original.r32(table+12u);
  (void)original.r32(0x00a2896cu);

  // Freeze both coordinate triples and the three packed RGB values before the
  // root's caller word 3 is replaced with the returned allocation pointer.
  const std::array<U,3> direct_xyz{{original.r32(coords),original.r32(coords+4u),original.r32(coords+8u)}};
  const std::array<U,3> air_xyz{{original.r32(air+0x88u),original.r32(air+0x8cu),original.r32(air+0x90u)}};
  const U strength=global_b26::sx8(original.r8(descriptor+0x124u));
  const U rgb0=color24(original,descriptor+0xfcu),rgb1=color24(original,descriptor+0xffu),rgb2=color24(original,descriptor+0x102u);
  const std::array<U,16> child_args{{direct_xyz[0],direct_xyz[1],direct_xyz[2],
    air_xyz[0],air_xyz[1],air_xyz[2],0u,1u,rgb0,rgb1,rgb2,strength,0u,1u,0x3f800000u,0u}};

  const auto host=ra2::platform::x87::capture_host();
  ra2::platform::x87::restore_host(i.fp.image);
  U object=0;
  try {
    object=heap.allocate(0x58u);
    i.fp.image=ra2::platform::x87::capture_host();
    ra2::platform::x87::restore_host(host);
  } catch (...) {
    i.fp.image=ra2::platform::x87::capture_host();
    ra2::platform::x87::restore_host(host);
    throw;
  }
  need(object);
  i.arg[3]=object;
  validate_spans(original,object,air,descriptor,coords,table);

  std::array<std::uint8_t,0x58> object_bytes{};
  for (U k=0;k<object_bytes.size();++k) object_bytes[k]=std::uint8_t(heap.r8(object+k));
  ra2::recovered::leaf::Memory object_span(object_bytes.data(),object,U(object_bytes.size()));
  Memory local=original;
  local.add(object_span);
  Inputs child=i;
  child.cx=object;
  child.arg=child_args;
  const U constructed=global_b26::fun_00531370(local,child);
  need(constructed==object);
  for (U k=0;k<object_bytes.size();++k) heap.w8(object+k,local.r8(object+k));
  return object;
}
}

