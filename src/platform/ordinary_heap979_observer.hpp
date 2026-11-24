#pragma once

// Passive platform observer; its current compiled use requires qualification.
// Borrowed fixed storage must be initialized and validated outside Root.
#include <cstddef>
#include <cstdint>
#include <type_traits>

#if !defined(_WIN32) || !defined(__i386__) || !defined(__GNUC__)
#error "passive979 observation requires Windows x86 GNU-compatible assembly"
#endif

namespace ra2::recovered::b979 {

enum class passive979Sdk : std::uint32_t {
    heap_alloc, heap_free, enter_lock, leave_lock
};

enum class passive979Stage : std::uint32_t {
    provider_entry, sdk_before, sdk_return, observer_post
};

struct alignas(16) passive979Raw {
    std::uint32_t eax, ecx, edx, ebx, esi, edi, ebp, esp;
    std::uint32_t eflags;
    std::uint32_t fs_selector;
    std::uint32_t exception_head;
    std::uint32_t stack_base;
    std::uint32_t stack_limit;
    std::uint32_t teb_self;
    std::uint32_t last_error;
    std::uint32_t reserved_alignment;
    alignas(16) unsigned char fx[512];
    unsigned char host108[108];
};

struct alignas(16) passive979Call {
    std::uint32_t sequence;
    passive979Sdk api;
    std::uint32_t target;
    std::uint32_t argument_count;
    std::uint32_t arguments[3];
    std::uint32_t result;
    std::uint32_t completed_mask;
    passive979Raw point[4];
};

struct passive979Ledger {
    passive979Call* calls;
    std::uint32_t capacity;
    std::uint32_t used;
    std::uint32_t overflow;
    std::uint32_t invalid;
};

static_assert(sizeof(void*) == 4u);
static_assert(sizeof(passive979Sdk) == 4u && sizeof(passive979Stage) == 4u);
static_assert(static_cast<std::uint32_t>(passive979Stage::provider_entry) == 0u);
static_assert(static_cast<std::uint32_t>(passive979Stage::sdk_before) == 1u);
static_assert(static_cast<std::uint32_t>(passive979Stage::sdk_return) == 2u);
static_assert(static_cast<std::uint32_t>(passive979Stage::observer_post) == 3u);
static_assert(std::is_standard_layout_v<passive979Raw>);
static_assert(std::is_trivially_copyable_v<passive979Raw>);
static_assert(alignof(passive979Raw) == 16u && sizeof(passive979Raw) == 688u);
static_assert(offsetof(passive979Raw, eax) == 0u);
static_assert(offsetof(passive979Raw, ecx) == 4u);
static_assert(offsetof(passive979Raw, edx) == 8u);
static_assert(offsetof(passive979Raw, ebx) == 12u);
static_assert(offsetof(passive979Raw, esi) == 16u);
static_assert(offsetof(passive979Raw, edi) == 20u);
static_assert(offsetof(passive979Raw, ebp) == 24u);
static_assert(offsetof(passive979Raw, esp) == 28u);
static_assert(offsetof(passive979Raw, eflags) == 32u);
static_assert(offsetof(passive979Raw, fs_selector) == 36u);
static_assert(offsetof(passive979Raw, exception_head) == 40u);
static_assert(offsetof(passive979Raw, stack_base) == 44u);
static_assert(offsetof(passive979Raw, stack_limit) == 48u);
static_assert(offsetof(passive979Raw, teb_self) == 52u);
static_assert(offsetof(passive979Raw, last_error) == 56u);
static_assert(offsetof(passive979Raw, reserved_alignment) == 60u);
static_assert(offsetof(passive979Raw, fx) == 64u);
static_assert(offsetof(passive979Raw, host108) == 576u);
static_assert(sizeof(passive979Raw::fx) == 512u);
static_assert(sizeof(passive979Raw::host108) == 108u);
static_assert(std::is_standard_layout_v<passive979Call>);
static_assert(std::is_trivially_copyable_v<passive979Call>);
static_assert(alignof(passive979Call) == 16u && sizeof(passive979Call) == 2800u);
static_assert(offsetof(passive979Call, sequence) == 0u);
static_assert(offsetof(passive979Call, api) == 4u);
static_assert(offsetof(passive979Call, target) == 8u);
static_assert(offsetof(passive979Call, argument_count) == 12u);
static_assert(offsetof(passive979Call, arguments) == 16u);
static_assert(offsetof(passive979Call, result) == 28u);
static_assert(offsetof(passive979Call, completed_mask) == 32u);
static_assert(offsetof(passive979Call, point) == 48u);
static_assert(std::is_standard_layout_v<passive979Ledger>);
static_assert(std::is_trivially_copyable_v<passive979Ledger>);
static_assert(sizeof(passive979Ledger) == 20u);
static_assert(offsetof(passive979Ledger, calls) == 0u);
static_assert(offsetof(passive979Ledger, capacity) == 4u);
static_assert(offsetof(passive979Ledger, used) == 8u);
static_assert(offsetof(passive979Ledger, overflow) == 12u);
static_assert(offsetof(passive979Ledger, invalid) == 16u);

extern "C" {

// Records actual state at sampler entry. raw.esp is the sampler's entry ESP,
// including its own return address, BEFORE PUSHFL/PUSHAL. No state correction.
// Requires writable 16-byte-aligned, nonaliasing, preinitialized fixed storage.
void __attribute__((cdecl)) passive979_sample(passive979Raw* out) noexcept
    __asm__("passive979_sample");

// Calls the actual supplied stdcall SDK address with exactly three/one words.
// before/after point pointers are mandatory; wrappers do not publish ledger
// masks or allocate. They return the real EAX (also retained for a void SDK,
// whose EAX must NOT be treated as a promised result).
std::uint32_t __attribute__((cdecl)) passive979_call3(
    std::uint32_t target, std::uint32_t arg0, std::uint32_t arg1,
    std::uint32_t arg2, passive979Raw* before, passive979Raw* after) noexcept
    __asm__("passive979_call3");

std::uint32_t __attribute__((cdecl)) passive979_call1(
    std::uint32_t target, std::uint32_t arg0,
    passive979Raw* before, passive979Raw* after) noexcept
    __asm__("passive979_call1");

} // extern "C"

} // namespace ra2::recovered::b979
