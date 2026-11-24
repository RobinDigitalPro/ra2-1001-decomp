#include "recovered/recovery_b480.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/direct_b33_integer.hpp"

#include <array>
#include <cstdint>
#include <mutex>
#include <stdexcept>

namespace ra2::recovered::recovery_b480 {
namespace {
namespace b39 = ra2::recovered::floating_b39;
namespace b40 = ra2::recovered::floating_callers_b40;
using State = b39::State;
using Frame = b39::Frame;
using Function = b39::Function;

Function find_b39(std::uint32_t rva) {
  for (const auto& e : b39::entries_a()) if (e.rva == rva) return e.function;
  for (const auto& e : b39::entries_b()) if (e.rva == rva) return e.function;
  throw std::runtime_error("B480 missing accepted B39 numeric helper");
}
Function find_b40(std::uint32_t rva) {
  for (const auto& e : b40::entries_a()) if (e.rva == rva) return e.function;
  throw std::runtime_error("B480 missing accepted B40 numeric helper");
}
void call_b39(Memory& m, State& s, Frame& parent, std::uint32_t target, std::uint32_t ret) {
  parent.push(m, ret);
  Frame child{}; child.entry_sp=parent.sp; child.return_sp=parent.sp; child.sp=parent.sp; child.outer_return=ret;
  find_b39(target)(m,s,child,b39::Operations{});
  parent.sp=child.sp;
}
void call_b40(Memory& m, State& s, Frame& parent, std::uint32_t target, std::uint32_t ret) {
  parent.push(m, ret);
  Frame child{}; child.entry_sp=parent.sp; child.return_sp=parent.sp; child.sp=parent.sp; child.outer_return=ret;
  find_b40(target)(m,s,child,b39::Operations{});
  parent.sp=child.sp;
}
void push_double(Memory& m, Frame& f, std::uint64_t value) {
  f.sp-=8u; b39::write64(m,f.sp,value);
}
constexpr std::uint32_t kReturnBase=0x4f100000u;
struct FirstTableCache {
  std::array<std::uint16_t,180000> value{};
  std::array<std::uint8_t,180000> ready{};
  std::array<std::uint32_t,21u*1024u+1u> signature{};
  bool valid=false;
};
FirstTableCache& first_table_cache(){static FirstTableCache c;return c;}
std::mutex& first_table_cache_mutex(){static std::mutex m;return m;}
std::array<std::uint32_t,21u*1024u+1u> first_table_signature(Memory& m,std::uint16_t control){
  std::array<std::uint32_t,21u*1024u+1u> key{};
  std::size_t next=0;
  for(const auto page:{0x785000u,0x788000u,0x7c3000u})
    for(std::uint32_t off=0;off<4096u;off+=4u)key[next++]=m.r32(page+off);
  for(std::uint32_t page=0x800000u;page<0x812000u;page+=4096u)
    for(std::uint32_t off=0;off<4096u;off+=4u)key[next++]=m.r32(page+off);
  key[next]=control;return key;
}
}

std::uint32_t fun_007167b0(Memory& original, const Inputs& input) {
  State s{};
  s.ax=input.ax; s.cx=input.cx; s.dx=input.dx;
  s.bx=0x13579bdfu; s.bp=0x2468ace0u; s.si=0x10293847u; s.di=0x55667788u;
  const auto saved_bx=s.bx, saved_bp=s.bp, saved_si=s.si, saved_di=s.di;
  s.arithmetic_flags=input.arithmetic_flags; s.fp=input.fp;

  // The original establishes an 8-byte-aligned local frame. Keep all private
  // helper stack writes out of declared guest regions.
  std::array<std::uint8_t,0x10000> stack{};
  constexpr std::uint32_t base=0x7c100000u, entry=base+0x8004u;
  ra2::recovered::leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));
  Memory m=original; m.add(local);
  m.w32(entry,kReturnBase);
  for (unsigned n=0;n<input.arg.size();++n) m.w32(entry+4u+4u*n,input.arg[n]);
  Frame f{}; f.entry_sp=entry; f.return_sp=entry; f.sp=entry; f.outer_return=kReturnBase;
  f.push(m,s.bp); s.bp=f.sp; f.sp&=~7u; f.sp-=8u;
  f.push(m,s.bx); f.push(m,s.bp); f.push(m,s.si); f.push(m,s.di);

  // 0x7167c6..0x71680a writes 300 rows by 300 columns. Each input is the exact
  // integer i*i+j*j, converted through the original BA080 and 76AA50 helpers.
  // For the bounded finite-state contract, this helper composition is a pure
  // function of the integer and exact pinned scalar/table bytes. Memoize by its full
  // input so repeated grid sums and later cases avoid recomputing the same
  // conversion. Cache eligibility requires the exact empty default x87 image.
  // The first element must execute because it transitions the control word to
  // the pinned 36AA50 value; the final element executes to reproduce the
  // terminal comparison/status/tag state. Bounded nonintegral inputs may set
  // sticky PE; the final nonintegral conversion also sets PE. No other exception
  // occurs for these pinned finite inputs. Every helper pair empties its stack,
  // and all following 500 sine conversions execute normally.
  const auto empty_default=ra2::platform::x87::Image::empty(0x037fu);
  const bool cache_allowed=input.fp.image.bytes==empty_default.bytes;
  auto& cache=first_table_cache();
  std::unique_lock<std::mutex> cache_lock(first_table_cache_mutex(),std::defer_lock);
  if(cache_allowed)cache_lock.lock();
  const auto signature=cache_allowed?first_table_signature(m,s.fp.control()):decltype(cache.signature){};
  if(cache_allowed&&(!cache.valid||cache.signature!=signature)){
    cache.ready.fill(0);cache.signature=signature;cache.valid=true;
  }
  s.bp=0; s.bx=0; s.di=0;
  for (std::uint32_t row=0; row<300u; ++row) {
    s.bp=row; s.bx=row*row; s.si=0;
    for (std::uint32_t col=0; col<300u; ++col) {
      const std::uint32_t n=col*col+s.bx;
      const bool boundary=(row==0u&&col==0u)||(row==299u&&col==299u);
      if(!cache_allowed||!cache.ready[n]||boundary){
        s.fp.load_integer32(n);
        push_double(m,f,s.fp.pop64());
        call_b39(m,s,f,0xba080u,kReturnBase+1u);
        f.sp+=8u;
        call_b39(m,s,f,0x36aa50u,kReturnBase+2u);
        if(cache_allowed){cache.value[n]=std::uint16_t(s.ax);cache.ready[n]=1;}
      }else s.ax=cache.value[n];
      m.w16(0x00ae1098u+2u*(row*300u+col),std::uint16_t(s.ax));
      ++s.si;
    }
    s.di+=0x258u; // exact 300 WORD stride
  }

  // 0x71680c..0x716857 constructs a 500-entry WORD table from the original
  // BA0F0 lookup, then the original scale/add constants and 76AA50 conversion.
  std::uint32_t index=0;
  for (std::uint32_t off=0; off<1000u; off+=2u) {
    s.fp.load_integer32(index);
    s.fp.multiply64(b39::read64(m,0x00799b28u));
    push_double(m,f,s.fp.pop64());
    call_b40(m,s,f,0xba0f0u,kReturnBase+3u);
    f.sp+=8u;
    s.fp.multiply64(b39::read64(m,0x00790df8u));
    s.fp.add64(b39::read64(m,0x00791038u));
    call_b39(m,s,f,0x36aa50u,kReturnBase+4u);
    m.w16(0x00ae0c60u+off,std::uint16_t(s.ax));
    ++index;
  }

  // The final loop writes 13 dwords: 0x6e, 0x76, ..., 0xce.
  std::uint32_t value=0x6eu, address=0x00ae1050u;
  while (value<0xd6u) {
    m.w32(address,value);
    value+=8u; address+=4u;
  }
  m.w8(0x00b0cfccu,1u);

  // Restore the saved callee-preserved registers. The final loop's CMP EAX,0xd6
  // leaves ZF/PF set, with CF/SF/OF clear, before RET.
  s.di=saved_di; s.si=saved_si; s.bp=saved_bp; s.bx=saved_bx;
  s.ax=0xd6u; s.cx=address; s.dx=index;
  auto flags=s.arithmetic_flags;
  (void)ra2::recovered::direct_b33::integer::sub(s.ax,0xd6u,32,flags);
  s.arithmetic_flags=flags;
  input.fp=s.fp;
  return s.ax;
}
}
