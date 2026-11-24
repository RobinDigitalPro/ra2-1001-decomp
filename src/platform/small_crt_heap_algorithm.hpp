#pragma once

// Bounded first small-block allocation path; acceptance is per caller contract.
#include <cstdint>

namespace ra2::platform::small_crt_heap {

class X86Memory {
public:
    virtual ~X86Memory() = default;
    virtual std::uint8_t r8(std::uint32_t address) const = 0;
    virtual std::uint32_t r32(std::uint32_t address) const = 0;
    virtual void w8(std::uint32_t address, std::uint8_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};

// Production implementations must forward to genuine Win32 APIs. The abstract
// seam exists for native call instrumentation, not for fabricated results.
class RealWin32Api {
public:
    virtual ~RealWin32Api() = default;
    virtual std::uint32_t heap_alloc(std::uint32_t heap, std::uint32_t flags,
                                     std::uint32_t bytes) = 0;
    virtual std::uint32_t virtual_alloc(std::uint32_t address, std::uint32_t bytes,
                                        std::uint32_t allocation_type,
                                        std::uint32_t protection) = 0;
};

// Concrete real-API implementation for a 32-bit Windows process. Allocation
// results are the real process addresses returned by Kernel32.
class Kernel32RealApi final : public RealWin32Api {
public:
    std::uint32_t heap_alloc(std::uint32_t heap, std::uint32_t flags,
                             std::uint32_t bytes) override;
    std::uint32_t virtual_alloc(std::uint32_t address, std::uint32_t bytes,
                                std::uint32_t allocation_type,
                                std::uint32_t protection) override;
};

// Translations of the reachable normal-success paths only. Input globals are
// read/written at their original fixed VAs through X86Memory.
std::uint32_t fun_007739dc_create_region(X86Memory& m, RealWin32Api& api);
std::uint32_t fun_00773a8d_commit_first_available_chunk(X86Memory& m,
                                                         RealWin32Api& api,
                                                         std::uint32_t record);
std::uint32_t fun_007736d3_allocate_first_small_block(X86Memory& m,
                                                       RealWin32Api& api,
                                                       std::uint32_t request,
                                                       std::uint32_t entry_esp); // mutates [entry_esp+4] like [EBP+8]

// Second/third allocation from the same page-zero class-63 residual extent.
// No free blocks, exhaustion, region growth or new OS allocation on this route.
std::uint32_t fun_007736d3_allocate_existing_first_chunk(X86Memory& m,
                                                       std::uint32_t request,
                                                       std::uint32_t entry_esp);

// Exact request-9 temporary after the 9,40,3,2 sequence: empty class-1
// insertion with allocated physical neighbors and three surviving allocations.
void fun_007733a8_release_class1_temporary(X86Memory& m, std::uint32_t user);

} // namespace ra2::platform::small_crt_heap
