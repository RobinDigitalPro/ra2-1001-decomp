#pragma once
#include <cstdint>
#include <stdexcept>

namespace ra2::platform::cpu382 {
struct Registers { std::uint32_t ax{},bx{},cx{},dx{}; };
struct FlagObservation {
    std::uint32_t entry{},after_ac{},after_id{};
    bool ac_toggled{},id_tested{},id_toggled{};
};
struct Operations {
    FlagObservation (*probe_flags)(void*){};
    Registers (*cpuid)(std::uint32_t leaf,std::uint32_t subleaf,void*){};
    void* context{};
};

// The entire availability check is one asm region. It follows the target's
// short-circuit rule (ID is attempted only if AC changed), records the guest
// observations, then restores host EFLAGS before any C++ instruction runs.
inline FlagObservation native_flag_probe(void*) {
    FlagObservation out{};
#if defined(__i386__)
    __asm__ volatile(
        "pushfl\n\tpopl %[entry]\n\t"
        "movl %[entry], %%eax\n\txorl $0x40000, %%eax\n\t"
        "pushl %%eax\n\tpopfl\n\tpushfl\n\tpopl %[ac]\n\t"
        "movl %[entry], %%eax\n\txorl %[ac], %%eax\n\t"
        "testl $0x40000, %%eax\n\tjz 1f\n\t"
        "movl %[entry], %%eax\n\txorl $0x200000, %%eax\n\t"
        "pushl %%eax\n\tpopfl\n\tpushfl\n\tpopl %[id]\n\t"
        "1:\n\t"
        "movl %[entry], %%eax\n\tpushl %%eax\n\tpopfl\n\t"
        : [entry] "=m"(out.entry), [ac] "=m"(out.after_ac), [id] "=m"(out.after_id)
        : : "eax","cc","memory");
#elif defined(__x86_64__)
    std::uint64_t entry{},after_ac{},after_id{};
    __asm__ volatile(
        "pushfq\n\tpopq %[entry]\n\t"
        "movq %[entry], %%rax\n\txorq $0x40000, %%rax\n\t"
        "pushq %%rax\n\tpopfq\n\tpushfq\n\tpopq %[ac]\n\t"
        "movq %[entry], %%rax\n\txorq %[ac], %%rax\n\t"
        "testq $0x40000, %%rax\n\tjz 1f\n\t"
        "movq %[entry], %%rax\n\txorq $0x200000, %%rax\n\t"
        "pushq %%rax\n\tpopfq\n\tpushfq\n\tpopq %[id]\n\t"
        "1:\n\t"
        "movq %[entry], %%rax\n\tpushq %%rax\n\tpopfq\n\t"
        : [entry] "=m"(entry), [ac] "=m"(after_ac), [id] "=m"(after_id)
        : : "rax","cc","memory");
    out.entry=static_cast<std::uint32_t>(entry);
    out.after_ac=static_cast<std::uint32_t>(after_ac);
    out.after_id=static_cast<std::uint32_t>(after_id);
#else
#error B382 requires an x86 host
#endif
    out.ac_toggled=((out.entry^out.after_ac)&0x40000u)!=0;
    out.id_tested=out.ac_toggled;
    out.id_toggled=out.id_tested&&((out.entry^out.after_id)&0x200000u)!=0;
    return out;
}

inline Registers native_cpuid(std::uint32_t leaf,std::uint32_t subleaf,void*) {
    Registers r{};
#if defined(__i386__) || defined(__x86_64__)
    __asm__ volatile("cpuid":"=a"(r.ax),"=b"(r.bx),"=c"(r.cx),"=d"(r.dx)
                     :"0"(leaf),"2"(subleaf):"memory");
#else
#error B382 requires x86 CPUID
#endif
    return r;
}
inline Operations native_operations() { return {native_flag_probe,native_cpuid,nullptr}; }
inline void require_operations(const Operations& op) {
    if(!op.probe_flags||!op.cpuid) throw std::invalid_argument("B382 real CPU operations are required");
}
} // namespace ra2::platform::cpu382
