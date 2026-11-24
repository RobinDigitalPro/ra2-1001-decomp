#pragma once

#include <cstdint>

// Private bounded translation of the CRT small-block split/free operations
// reached by the successful 32DA70 INI-file route. It deliberately excludes
// Win32 API calls; the route's 0x1000 line-buffer allocation is ordinary
// HeapAlloc/HeapFree and is observed separately.
namespace ra2::platform::file_heap249 {

class Memory {
public:
    virtual ~Memory() = default;
    virtual std::uint8_t r8(std::uint32_t address) const = 0;
    virtual std::uint32_t r32(std::uint32_t address) const = 0;
    virtual void w8(std::uint32_t address, std::uint8_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};

// The caller supplies the already initialized first region/chunk. For the
// actual route, the first 0x0c request is done through the existing fresh
// region/first-chunk helpers; this exact same-class split handles later
// requests {0x44,0x04,0x28,0x04,0x10,0x50,0x50}.
std::uint32_t allocate_class63_split(Memory& memory,
                                     std::uint32_t record,
                                     std::uint32_t request);

// Translation of the successful single-region/chunk branch in RVA 3733A8.
// Only requests from the fixed file route are in scope; ordinary-heap
// pointers must be handled by the real HeapFree boundary instead.
void release_file_small_block(Memory& memory,
                              std::uint32_t record,
                              std::uint32_t user_pointer);

} // namespace ra2::platform::file_heap249
