#pragma once
#include "recovered/allocation_wrappers.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::two_call_b24 {
struct Operations {
    void (*first)(std::uint32_t target_rva, std::uint32_t receiver, std::uint32_t argument, void* context);
    void* context;
    AllocationWrapperOperations heap;
};
using Function = std::uint32_t (*)(leaf::Memory&, const leaf::Inputs&, const Operations&);
struct Entry {
    std::uint32_t rva, size, pointer_offset, initial_tag, final_tag, first_receiver, first_target;
    Function function;
};
const std::array<Entry, 37>& entries();
std::uint32_t fun_0048cad0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cb10(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cb50(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cb90(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cbd0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cc10(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048ccf0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cd30(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cd70(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cdb0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cdf0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048ce30(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048ce70(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048ceb0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cef0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cf30(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cf70(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cfb0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048cff0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d2d0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d310(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d350(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d390(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d3d0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d410(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d450(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d490(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d4d0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d510(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d550(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d590(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d5d0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d610(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d650(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d690(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d6d0(leaf::Memory&, const leaf::Inputs&, const Operations&);
std::uint32_t fun_0048d710(leaf::Memory&, const leaf::Inputs&, const Operations&);
} // namespace ra2::recovered::two_call_b24
