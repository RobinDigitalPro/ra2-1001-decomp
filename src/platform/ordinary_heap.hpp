#pragma once
#include <cstdint>
namespace ra2::platform::ordinary_heap {
class Heap {
public:
    virtual ~Heap() = default;
    virtual std::uint32_t allocate(std::uint32_t bytes) = 0;
    virtual std::uint32_t release(std::uint32_t pointer) = 0; // actual EAX/BOOL
    virtual std::uint32_t r8(std::uint32_t address) const = 0;
    virtual std::uint32_t r32(std::uint32_t address) const = 0;
    virtual void w8(std::uint32_t address, std::uint32_t value) = 0;
    virtual void w32(std::uint32_t address, std::uint32_t value) = 0;
};
}
