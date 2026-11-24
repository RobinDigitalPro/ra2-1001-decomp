#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b472 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;
class Allocator { public: virtual ~Allocator()=default; virtual std::uint32_t allocate(std::uint32_t)=0; };
class AddressSpace { public: virtual ~AddressSpace()=default; virtual std::uint32_t r8(std::uint32_t)const=0; virtual std::uint32_t r32(std::uint32_t)const=0; virtual void w8(std::uint32_t,std::uint32_t)=0; virtual void w32(std::uint32_t,std::uint32_t)=0; };
std::uint32_t fun_0062c9e0(AddressSpace&, Inputs&, Allocator&);
}
