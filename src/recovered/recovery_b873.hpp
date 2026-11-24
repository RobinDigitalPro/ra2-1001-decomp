#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::recovery_b873 {
struct SerializerCase {std::uint32_t object,ini_root,key_scratch,value_scratch;};
std::uint32_t fun_006ac360(global_b26::Memory&,const global_b26::Inputs&,const SerializerCase&,platform::ordinary_heap::Heap&);
std::uint32_t write_absent(global_b26::Memory&,platform::ordinary_heap::Heap&,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::uint32_t probe_section(global_b26::Memory&,platform::ordinary_heap::Heap&,std::uint32_t,std::uint32_t);
}
