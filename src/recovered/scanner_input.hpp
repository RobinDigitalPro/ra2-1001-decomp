#pragma once
#include "recovered/crt_classify.hpp"
#include <cstdint>

namespace ra2::recovered {
// Portable views of observed fields, not an original FILE class or ABI.
// remaining/counters are modulo-32 bits; fetch tests the sign bit AFTER decrement.
// Pointer arithmetic requires one valid backing allocation (including the byte
// before cursor for pushback). No pointer wrap, overlapping state or concurrency.
struct ScannerBuffer {
    std::uint8_t* cursor;
    std::uint32_t remaining;
    std::uint8_t* base;
    std::uint32_t flags;
    std::uint32_t descriptor;
    std::uint32_t scratch;
    std::uint32_t capacity;
};
struct ScannerInputOperations {
    void (*allocate)(ScannerBuffer&, void*);
    std::uint32_t (*read)(std::uint32_t, std::uint8_t*, std::uint32_t, void*);
    std::uint8_t (*descriptor_flags)(std::uint32_t, void*);
    void* context;
};
// Callbacks supply unresolved allocation/I/O/descriptor-table dependencies.
// They must provide coherent storage/state; only reached callbacks are required.
// Original memory streams have flags 0x49 and bypass refill I/O entirely.
std::uint32_t fun_007742c3(ScannerBuffer&, const ScannerInputOperations&);
std::uint32_t fun_00775d29(ScannerBuffer&, const ScannerInputOperations&);
std::uint32_t fun_0077dd78(std::uint32_t, ScannerBuffer&, const ScannerInputOperations&);
void fun_00775d43(std::uint32_t, ScannerBuffer&, const ScannerInputOperations&);
std::uint32_t fun_00775d5a(std::uint32_t& consumed, ScannerBuffer&,
                         const ScannerInputOperations&, const CrtClassification&);

using ScannerCallback = std::int32_t (*)(ScannerBuffer&, const std::uint8_t*, void*, void*);
// RVA 0x36f070: input is a finite nonnull string, length <= INT32_MAX. The
// argument-list pointer is opaque; callbacks adapt variadic outputs explicitly.
// Only cursor/count/base/flags were initialized by the original wrapper. The
// callback must not observe descriptor/scratch/capacity on this memory path.
std::int32_t fun_0076f070(const std::uint8_t*, const std::uint8_t*, void*,
                        ScannerCallback, void*);
}
