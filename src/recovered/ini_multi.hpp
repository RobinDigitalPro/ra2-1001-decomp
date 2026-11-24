#pragma once
#include "recovered/ini_bulk.hpp"
#include "recovered/scanner_input.hpp"

namespace ra2::recovered {
enum class GetterDecimalFormat { time_hms, four_csv, two_csv, three_csv };
struct DecimalFieldOutputs { std::uint32_t* fields[4]; };
struct GetterDecimalContext { const CrtClassification* classification; };
// Behavioral subset of unrecovered scanner RVA 0x3752cd, exclusively
// "%02d:%02d:%02d" and two/three/four comma-separated %d fields under initial
// single-byte classification.
// Memory state must use flags 0x49 and coherent cursor/base/count (<= INT32_MAX).
// Output fields are writable uint32 words, separate from input/state; fields
// may alias each other and assignments occur in conversion order.
// Return is assignment count or -1 for input failure before any assignment.
// This is not a full scanner recovery or an original variadic ABI declaration.
std::int32_t scan_getter_decimal_fields(ScannerBuffer&, GetterDecimalFormat,
    const DecimalFieldOutputs&, const CrtClassification&);
// Exact supported format only; arguments points at DecimalFieldOutputs.
std::int32_t scan_getter_decimal_callback(ScannerBuffer&, const std::uint8_t*, void*, void*);
struct MultiIntegerReadOperations {
    IniOperations lookup;
    ScannerCallback scan;
    void* context;
};
// Original 0x10f8b0: missing text returns fallback; present text starts three
// zero fields, ignores scan status and computes ((h*60+m)*60+s)*60 modulo32.
std::uint32_t fun_0050f8b0(IniIndex*, const std::uint8_t* section,
    const std::uint8_t* key, std::uint32_t fallback, const MultiIntegerReadOperations&);
// Original 0x10d1a0 and 0x10d3c0: bounded 64-byte copy/trim before scanning,
// preserving unassigned fallback fields; missing stored text scans "0,0,0,0".
// Both return output. Four uint32 words must be readable/writable. Output may
// overlap fallback within a valid shared allocation. The direct getter's
// empty/null-name path copies sequentially; the adapted getter snapshots first.
// Names/text and lookup contracts must be valid; output must not alias them.
std::uint32_t* fun_0050d1a0(IniIndex*, std::uint32_t* output,
    const std::uint8_t* section, const std::uint8_t* key, const std::uint32_t* fallback,
    const MultiIntegerReadOperations&);
std::uint32_t* fun_0050d3c0(IniIndex*, std::uint32_t* output,
    const IniByteString& section, const IniByteString& key, const std::uint32_t* fallback,
    const MultiIntegerReadOperations&);
}
