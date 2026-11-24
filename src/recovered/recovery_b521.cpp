#include "recovery_b521.hpp"
#include "recovered/indirect_b32_memory.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b521 {
namespace {
std::uint32_t fixed_cell(std::uint32_t value) {
  const auto signed_value=static_cast<std::int32_t>(value);
  return static_cast<std::uint32_t>((signed_value+(signed_value<0?0xff:0))>>8);
}
}
// Bounded horizontal line-walk through 2..8 valid map cells whose accepted
// type-6 lists are empty. This composes the actual accepted 0x713b0 body for
// every visited cell, including its gate, list-head read, callee-save and
// return path. Diagonal interpolation and occupied-object callbacks are out.
std::uint32_t fun_00566da0(Memory& m,const Inputs& i) {
  const auto out=i.arg[0],from=i.arg[1],to=i.arg[2];
  if(!out||!from||!to)throw std::runtime_error("B521 null pointer outside positive route");
  const auto fx=fixed_cell(m.r32(from)),fy=fixed_cell(m.r32(from+4));
  const auto tx=fixed_cell(m.r32(to)),ty=fixed_cell(m.r32(to+4));
  if(fy!=ty||tx<=fx||tx-fx<2u||tx-fx>8u||m.r32(from+8)!=m.r32(to+8))
    throw std::runtime_error("B521 input outside horizontal clear-line route");
  if(m.r8(0xa285a8u)==0)throw std::runtime_error("B521 helper gate must be enabled");
  const auto table=m.r32(0x81a958u); constexpr std::uint32_t limit=0x40000u;
  for(std::uint32_t x=fx;x<tx;++x){
    const auto index=fy*512u+x;
    if(index>=limit)throw std::runtime_error("B521 traversed cell outside table bound");
    const auto cell=m.r32(table+index*4u);
    if(!cell||m.r32(cell+0xe4u)!=0)
      throw std::runtime_error("B521 route cell must have an initialized empty list");

    using namespace indirect_b32;
    State s{};s.cx=cell;
    Frame f{};f.entry_sp=out+0x100u;f.sp=f.entry_sp;f.outer_return=0xb521713bu;
    std::array<std::uint32_t,18> saved{};
    for(unsigned n=0;n<saved.size();++n)saved[n]=m.r32(f.entry_sp-4u+4u*n);
    m.w32(f.entry_sp,f.outer_return);
    for(unsigned n=0;n<s.arg.size();++n)m.w32(f.entry_sp+4u+4u*n,0x51000000u+n);
    const Operations no_virtual_calls{nullptr,nullptr};
    bool called=false;
    for(const auto& entry:entries_b())if(entry.rva==0x713b0u){entry.function(m,s,f,no_virtual_calls);called=true;break;}
    if(!called)throw std::runtime_error("B521 accepted 0x713b0 body missing from B32 dispatcher");
    for(unsigned n=0;n<saved.size();++n)m.w32(f.entry_sp-4u+4u*n,saved[n]);
    if(s.ax!=0)throw std::runtime_error("B521 empty helper list returned a type-6 node");
  }
  // Original clear-line completion at 0x567239 copies these globals to arg0.
  m.w32(out,m.r32(0xa575e8u));
  m.w32(out+4,m.r32(0xa575ecu));
  m.w32(out+8,m.r32(0xa575f0u));
  return out;
}
}
