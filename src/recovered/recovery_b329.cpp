#include "recovery_b329.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b329 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
std::uint32_t length_guest(Memory& m, std::uint32_t p) {
    need(p != 0, "329 requires a nonnull guest byte string");
    for (std::uint32_t n = 0; n != 1018u; ++n)
        if (m.r8(p+n) == 0u) return n;
    throw std::domain_error("329 string is not terminated inside the selected 1018-byte bound");
}
std::uint32_t length_heap(Heap& h, std::uint32_t p) {
    need(p != 0, "329 requires a nonnull heap byte string");
    for (std::uint32_t n = 0; n != 1018u; ++n)
        if (h.r8(p+n) == 0u) return n;
    throw std::domain_error("329 copied string is not terminated inside the selected bound");
}
std::uint32_t clone_guest(Memory& m, Heap& h, std::uint32_t source, std::uint32_t n) {
    const auto p = h.allocate(n+1u);
    need(p != 0, "329 original ordinary HeapAlloc success branch required");
    for (std::uint32_t k = 0; k <= n; ++k) h.w8(p+k, m.r8(source+k));
    return p;
}
// Route specialization of 0x75a7b0: it copies a nonnull guest-owned string
// through two independent real ordinary allocations, lowercases ASCII only,
// frees the temporary, and stores the result in the caller's local holder.
// Selected inputs use only spaces/commas, so the 0x76fb34 uppercase callback
// branch is unreachable and no locale state is touched.
std::uint32_t helper_35a7b0_delimiter(Memory& m, Heap& h,
                                      std::uint32_t source, bool owned) {
    const auto n = owned ? length_heap(h,source) : length_guest(m,source);
    const auto temporary=h.allocate(n+1);
    for(unsigned k=0;k<=n;++k)h.w8(temporary+k,owned?h.r8(source+k):m.r8(source+k));
    for (std::uint32_t k = 0; k < n; ++k) {
        const auto c = h.r8(temporary+k);
        if (c >= 'A' && c <= 'Z') h.w8(temporary+k, c+0x20u);
    }
    const auto result = h.allocate(n+1u);
    need(result != 0, "329 0x75a7b0 second ordinary allocation must succeed");
    for (std::uint32_t k = 0; k <= n; ++k) h.w8(result+k, h.r8(temporary+k));
    need(h.release(temporary) == 1u, "329 0x75a7b0 HeapFree BOOL success required");
    return result;
}
bool literal_delimiter_span(Memory& m, Heap& h, std::uint32_t p, std::uint32_t n) {
    constexpr std::uint32_t set = 0x007e7decu; // pinned original bytes " ,;\0"
    std::uint32_t accepted = 0;
    while (accepted < n) {
        bool found = false;
        for (std::uint32_t k = 0; k != 4u; ++k)
            if (h.r8(p+accepted) == m.r8(set+k)) { found = true; break; }
        if (found) break;
        ++accepted;
    }
    return accepted == n;
}
bool equal_bytes(Heap& h, std::uint32_t a, std::uint32_t b, std::uint32_t n) {
    for (std::uint32_t k = 0; k <= n; ++k)
        if (h.r8(a+k) != h.r8(b+k)) return false;
    return true;
}
std::uint32_t clone_null_slot(Memory& m, Heap& h, std::uint32_t source) {
    // Exact selected branch of 0x759570: destination starts null, source is
    // nonnull, so no old-pointer compare/free occurs; allocate NUL inclusive.
    const auto n = length_guest(m, source);
    const auto p = clone_guest(m, h, source, n);
    return p;
}
}

// RVA 0x344960 / VA 0x744960. Finite useful route: 1017-byte a query,
// different service string, and one visited c candidate. It passes the global
// inequality check and 0x75b260's literal delimiter-span condition, visits one
// real registry object, compares unequal, frees each owned copy, then returns
// true after exhausting the one-entry registry.
std::uint32_t rva_00344960(Memory& m, const Inputs& i, Heap& h) {
    const auto receiver = i.cx;
    need(receiver != 0u && (i.arithmetic_flags & 0x400u) == 0u,
         "329 requires nonnull receiver and DF clear");
    const auto query = m.r32(receiver);
    const auto n = length_guest(m, query);
    need(n == 1017u, "329 exact ordinary allocation request is 1018 bytes");
    for (std::uint32_t k = 0; k < n; ++k)
        need(m.r8(query+k) == 'a', "329 query must be 1017 literal a bytes");

    // Root 0x74496b calls 0x7592c0; its selected source-nonnull branch makes
    // the query-owned local clone and returns its destination holder in EAX.
    const auto query_copy = clone_guest(m, h, query, n);

    const auto service_holder = 0x00b0e5f0u;
    const auto service = m.r32(service_holder);
    need(length_guest(m, service) == n, "329 service string length must match query");
    for (std::uint32_t k = 0; k < n; ++k)
        need(m.r8(service+k) == 'b', "329 service literal must differ from query a bytes");
    const auto service_copy = helper_35a7b0_delimiter(m, h, service,false);

    // Private original holders are represented by local values; query_copy
    // belongs to Heap, so its bytes are read through that address space.
    const auto normalized_query=helper_35a7b0_delimiter(m,h,query_copy,true);
    const bool same_as_service = equal_bytes(h, service_copy, normalized_query, n);
    // Root destroys its second helper result local first (ESP+0xc), then the
    // service helper result local (ESP+0x10 after the first destructor).
    need(h.release(normalized_query) == 1u && h.release(service_copy) == 1u,
         "329 root destructor frees query result before service result");
    need(!same_as_service, "329 selected route must pass initial service inequality");

    // Root 0x7449e3 calls 0x75b260 with the pinned " ,;" set. Its 0x771310
    // strcspn result equals N, so SBB/NEG returns zero and the root enters the
    // one-entry registry loop.
    need(literal_delimiter_span(m, h, query_copy, n),
         "329 query must be free of the original delimiters");

    need(m.r32(0x00b0e390u) == 1u, "329 contract visits exactly one registry element");
    const auto vector = m.r32(0x00b0e398u);
    need(vector != 0u, "329 registry array must be nonnull");
    const auto entry_string = m.r32(vector);
    need(entry_string != 0u, "329 visited entry object must be nonnull");
    need(length_guest(m, entry_string) == n, "329 entry string length must be 1017");
    for (std::uint32_t k = 0; k < n; ++k)
        need(m.r8(entry_string+k) == 'c', "329 visited entry is 1017 literal c bytes");
    const auto entry_copy = clone_null_slot(m, h, entry_string);
    const bool matches = equal_bytes(h, entry_copy, query_copy, n);
    need(h.release(entry_copy) == 1u, "329 candidate destructor HeapFree BOOL success");
    need(!matches, "329 positive route requires the visited entry to mismatch");

    need(h.release(query_copy) == 1u, "329 final query destructor HeapFree BOOL success");
    // At this point original 0x759320 returns the real HeapFree BOOL 1;
    // MOV AL,1 preserves the zero high words, giving full EAX=1. The root is
    // RET with zero callee-pop bytes, and does not mutate caller argument words.
    return 1u;
}
}
