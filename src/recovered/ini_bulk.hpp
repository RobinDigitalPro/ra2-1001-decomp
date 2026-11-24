#pragma once
#include "recovered/ini_lookup.hpp"

namespace ra2::recovered {
// Portable logical views. Same valid-memory/sort contracts as ini_lookup.hpp.
// Names must be NUL-terminated with length <= INT32_MAX and must not alias
// writable index state. No allocator, original class identity, or binary-compatible
// layout is implied. Cache probes specify only AL; upper return bits are ignored.
IniIndex* fun_00510130(IniIndex&);
std::uint8_t fun_00510580(const IniIndex&, const std::int32_t*);
std::uint8_t fun_005106b0(const IniIndex&, const std::int32_t*);
std::uint8_t fun_00510440(IniIndex&, const std::int32_t*, const IniOperations&);
// Returns the ADDRESS of a value slot, even on failure. The caller-supplied
// fallback slot models global VA b10ab0 / b10aac, including pointer identity.
void** fun_005102c0(IniIndex&, const std::int32_t*, void*& fallback, const IniOperations&);
void** fun_005104e0(IniIndex&, const std::int32_t*, void*& fallback, const IniOperations&);
// Raw signed searches: count <= 0 returns null without reading table/query.
IniIndexEntry* fun_00510780(IniIndexEntry*, std::int32_t, const std::int32_t*);
IniIndexEntry* fun_00510800(IniIndexEntry*, std::int32_t, const std::int32_t*);

struct IniByteString { const std::uint8_t* bytes; };
// Null contained pointer resolves to a shared readable empty string; the object
// pointer itself must be valid. Original uses VA 8248a4 (verified zero byte).
const std::uint8_t* fun_0075a070(const IniByteString&);
IniSection* fun_0050be00(IniIndex*, const std::uint8_t*, const IniOperations&);
IniValue* fun_0050f620(IniIndex*, const std::uint8_t*, const IniOperations&);
std::int32_t fun_0050bf50(IniIndex*, const std::uint8_t*, const IniOperations&);
std::int32_t fun_0050c020(IniIndex*, const IniByteString&, const IniOperations&);
// Valid finite linked chains only. The original checks position < count but
// has no separate negative-position rejection. Sentinel next/previous fields
// are checked before name access. The decrement uses x86 modulo-32 behavior.
const std::uint8_t* fun_0050c250(IniIndex*, const std::uint8_t*, std::int32_t, const IniOperations&);
} // namespace ra2::recovered
