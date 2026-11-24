#pragma once
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::b1688 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using U = std::uint32_t;

// Adapter boundary for the actual CRT calls only. Implementations must pass
// these guest pointers/bit values to genuine fopen/fprintf/fclose providers.
// No guest FILE representation or formatter result is synthesized here.
class Stdio {
public:
    virtual ~Stdio() = default;
    virtual U open(U filename, U mode) = 0;
    virtual U print(U file, U format, U value_bits) = 0;
    virtual U close(U file) = 0;
};

struct Observation {
    U stage{}, opens{}, prints{}, closes{}, file{};
    U open_return{}, close_return{}, last_print_return{};
    U container{}, flags_checked{}, nonzero_flag_index{0xffffffffu}, nonzero_flag{};
    std::array<U, 5> formats{}, values{}, print_returns{};
};

// Finite positive domain only: A255C8==4, 0x821F90==0, and the eight
// byte flags at A258B4+n*0x68 are all zero. This executes the real five
// fprintf calls and real fclose. Unsupported domain branches throw and are
// not useful behavior or recovery credit. CX is intentionally not modeled:
// this Root's ECX is an output of its own code, not an opaque caller input.
U run(Memory&, const Inputs&, Stdio&, Observation&);
U run(Memory&, const Inputs&, Stdio&);
} // namespace ra2::recovered::b1688
