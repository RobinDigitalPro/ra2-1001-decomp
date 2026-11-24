#include "platform/file_heap_adapter249.hpp"

#include <stdexcept>

namespace ra2::platform::file_heap249 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::runtime_error(why);
}
std::uint32_t ptr32(const void* p) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));
}
}

FileHeap::FileHeap(ra2::recovered::global_b26::Memory& globals,
                   Bootstrap& bootstrap, HANDLE crt_heap)
    : globals_(globals), bootstrap_(bootstrap), crt_heap_(crt_heap) {
    need(crt_heap_ != nullptr, "32DA70 requires the real initialized CRT heap");
    need(globals_.r32(0x00b10e14u) == 0 && globals_.r32(0x00b10e18u) != 0,
         "32DA70 starts before the first CRT region allocation");
    need(globals_.r32(0x00b10e1cu) == ptr32(crt_heap_),
         "32DA70 heap handle differs from B10E1C");
}

FileHeap::~FileHeap() {
    if (line_buffer_)
        HeapFree(crt_heap_, 0, reinterpret_cast<void*>(
                     static_cast<std::uintptr_t>(line_buffer_)));
}

void FileHeap::lock() const {
    const auto p = globals_.r32(0x0081729cu);
    need(p != 0, "32DA70 CRT lock pointer is null");
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(
        static_cast<std::uintptr_t>(p)));
}

void FileHeap::unlock() const {
    const auto p = globals_.r32(0x0081729cu);
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(
        static_cast<std::uintptr_t>(p)));
}

std::uint32_t FileHeap::allocate(std::uint32_t request) {
    static constexpr std::uint32_t requests[]{
        0x0cu, 0x44u, 0x04u, 0x28u, 0x04u, 0x10u, 0x50u, 0x50u};
    const bool value_clone_request = allocations_ == 4 &&
        (request == 3u || request == 4u);
    need(allocations_ < 8 &&
         (value_clone_request || request == requests[allocations_]),
         "32DA70 allocation request/order differs from the captured route");
    std::uint32_t p;
    if (allocations_ == 0) {
        // The project adapter performs the genuine first-region/chunk setup,
        // with real HeapAlloc, VirtualAlloc and critical-section calls.
        p = bootstrap_.allocate(request);
    } else {
        const auto record = globals_.r32(0x00b10e18u);
        lock();
        try {
            p = allocate_class63_split(*this, record, request);
        } catch (...) {
            unlock();
            throw;
        }
        unlock();
    }
    need(p != 0, "32DA70 small allocation returned null");
    allocation_ptrs_[allocations_++] = p;
    return p;
}

void FileHeap::release(std::uint32_t user) {
    if (user == 0) return; // Original CRT free returns immediately for null.
    static constexpr std::uint32_t allocation_ordinal[]{2, 5, 4, 3, 6, 1, 7, 0};
    need(allocations_ == 8 && releases_ < 8,
         "32DA70 frees begin only after the complete bounded graph exists");
    const auto expected = allocation_ptrs_[allocation_ordinal[releases_]];
    need(user == expected, "32DA70 free order/pointer differs from the observed route");
    const auto record = globals_.r32(0x00b10e18u);
    lock();
    try {
        release_file_small_block(*this, record, user);
    } catch (...) {
        unlock();
        throw;
    }
    unlock();
    ++releases_;
}

std::uint32_t FileHeap::heap_alloc(std::uint32_t heap, std::uint32_t flags,
                                  std::uint32_t bytes) {
    need(heap == ptr32(crt_heap_) && flags == HEAP_ZERO_MEMORY && bytes == 0x1000u &&
         line_buffer_ == 0,
         "32DA70 only issues its one real zeroed 0x1000 reader allocation");
    auto* p = static_cast<std::uint8_t*>(HeapAlloc(crt_heap_, flags, bytes));
    need(p != nullptr, "real parser HeapAlloc(0x1000) failed");
    line_buffer_ = ptr32(p);
    line_buffer_size_ = bytes;
    need(HeapValidate(crt_heap_, 0, p) && HeapSize(crt_heap_, 0, p) >= bytes,
         "real parser buffer bounds are invalid");
    return line_buffer_;
}

void FileHeap::free_line_buffer() {
    need(line_buffer_ != 0 && line_buffer_size_ == 0x1000u,
         "32DA70 parser buffer has not been allocated");
    need(HeapFree(crt_heap_, 0, reinterpret_cast<void*>(
                      static_cast<std::uintptr_t>(line_buffer_))) != FALSE,
         "real parser HeapFree failed");
    line_buffer_ = 0;
    line_buffer_size_ = 0;
}

std::uint8_t FileHeap::r8(std::uint32_t address) const {
    if (line_buffer_ && address >= line_buffer_ &&
        address - line_buffer_ < line_buffer_size_)
        return reinterpret_cast<const std::uint8_t*>(
            static_cast<std::uintptr_t>(line_buffer_))[address - line_buffer_];
    return static_cast<std::uint8_t>(bootstrap_.r8(address));
}

std::uint32_t FileHeap::r32(std::uint32_t address) const {
    std::uint32_t result = 0;
    for (unsigned n = 0; n != 4; ++n)
        result |= std::uint32_t(r8(address + n)) << (8u * n);
    return result;
}

void FileHeap::w8(std::uint32_t address, std::uint8_t value) {
    if (line_buffer_ && address >= line_buffer_ &&
        address - line_buffer_ < line_buffer_size_) {
        reinterpret_cast<std::uint8_t*>(
            static_cast<std::uintptr_t>(line_buffer_))[address - line_buffer_] = value;
        return;
    }
    bootstrap_.w8(address, value);
}

void FileHeap::w32(std::uint32_t address, std::uint32_t value) {
    for (unsigned n = 0; n != 4; ++n)
        w8(address + n, static_cast<std::uint8_t>(value >> (8u * n)));
}

} // namespace ra2::platform::file_heap249
