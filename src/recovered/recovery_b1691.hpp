#pragma once
#include "recovered/global_b26_memory.hpp"
#include "recovered/recovery_b1279.hpp"

namespace ra2::recovered::recovery_b1691 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = b1279::Heap;

// Qualified standard-library boundary only. Implementations invoke actual
// strtok/atoi semantics on owned addressable text and real CRT thread state.
// This is not an interface for calling Original game methods or test oracles.
class StandardCrt {
public:
    virtual ~StandardCrt() = default;
    virtual std::uint32_t tokenize(std::uint32_t text_va,
                                   std::uint32_t delimiter_va) = 0;
    virtual std::uint32_t integer(std::uint32_t token_va) = 0;
};

// Static finite contract: mode1, sixteen freshly produced normal vector
// headers, first comma-delimited token exactly1, at most sixteen following
// signed int32 decimal tokens, and a NUL within512 bytes. Empty comma fields
// are skipped by the real provider. No original class identity is implied.
// Preflight performs no writes or provider calls; use before the observed run.
void preflight(Memory&, const Inputs&);
std::uint32_t run(Memory&, const Inputs&, Heap&, StandardCrt&);
} // namespace ra2::recovered::recovery_b1691
