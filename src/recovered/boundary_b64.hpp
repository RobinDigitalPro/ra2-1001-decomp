#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>
#include <vector>

namespace ra2::recovered::boundary_b64 {
using ra2::recovered::global_b26::Inputs;
using ra2::recovered::global_b26::Memory;

struct Operations {
    std::uint32_t (*invoke)(Memory&,std::uint32_t callee,
                            const std::vector<std::uint32_t>& args,void*){};
    void* context{};
};

using Function=std::uint32_t(*)(Memory&,const Inputs&,const Operations&);
std::uint32_t fun_00522ca0(Memory&,const Inputs&,const Operations&);
std::uint32_t fun_0069e1b0(Memory&,const Inputs&,const Operations&);
}
