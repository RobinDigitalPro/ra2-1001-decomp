#pragma once
#include "recovered/ini_bulk.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/scanner_input.hpp"

namespace ra2::recovered {
enum class GetterHexFormat { dollar_prefix, h_suffix };
// Behavioral subset of unrecovered RVA 0x3752cd. ONLY "$%x" and "%xh",
// initial single-byte classification and memory flags 0x49 are supported.
// Not a recovery of general scanf, variadics, width, suppression, locale or I/O.
// Input cursor/base/count must describe a finite readable memory string span;
// output is separate writable storage. Return/output AND buffer mutations are
// observed; a failed conversion preserves the caller's output bits.
std::int32_t scan_getter_hex32(ScannerBuffer&, GetterHexFormat, std::uint32_t&,
                             const CrtClassification&);
struct GetterHexContext { const CrtClassification* classification; };
// Callback format precondition: the exact "$%x" or "%xh" string. arguments
// points at ONE uint32 output, an explicit adapter for the original va-list.
std::int32_t scan_getter_hex32_callback(ScannerBuffer&, const std::uint8_t*, void*, void*);

struct IntegerReadOperations {
    IniOperations lookup;
    DecimalOperations decimal;
    std::int32_t (*lowercase)(std::int32_t, void*);
    ScannerCallback scan;
    void* context;
};
// Original RVAs 0x10cc40 and 0x10ce20. The getter ignores scanner return status;
// its default persists unless the output is assigned. A non-$ empty value
// reads text[-1] for the suffix decision: the caller MUST supply that readable
// prefix byte within the same allocation. No invented empty-string behavior.
// Null names return default before receiver access. All lookup contracts apply.
std::uint32_t fun_0050cc40(IniIndex*, const std::uint8_t* section,
                         const std::uint8_t* key, std::uint32_t fallback,
                         const IntegerReadOperations&);
std::uint32_t fun_0050ce20(IniIndex*, const IniByteString& section,
                         const IniByteString& key, std::uint32_t fallback,
                         const IntegerReadOperations&);
}
