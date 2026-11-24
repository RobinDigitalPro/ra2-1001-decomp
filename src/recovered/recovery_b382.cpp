#include "recovered/recovery_b382.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b382 {
namespace {
constexpr std::uint32_t kStatus=0x7e98e2u;
constexpr std::uint32_t kModel =0x7e98e3u;
constexpr std::uint32_t kFamily=0x7e98e4u;
constexpr std::uint32_t kVendor=0x7e98e5u;
constexpr std::uint32_t kCpuCap0=0x7e98e0u;
constexpr std::uint32_t kCpuCap1=0x7e98e1u;
constexpr std::uint32_t kMode=0x00b10530u;
constexpr std::uint32_t kAc=0x00040000u;
constexpr std::uint32_t kId=0x00200000u;
constexpr std::uint32_t kAuthenticAmd=0x007c395cu;
constexpr std::uint32_t kCyrixInstead=0x007c394cu;
constexpr std::uint32_t kClassifierTable=0x004d2224u;

std::uint32_t run_36ab4f(Memory& m,const Inputs& in,const Operations& op) {
    // Exact accepted 0x36ab4f behavior: unsigned model threshold, leaf 1
    // EDX[15], then model > 5 split. Its no-argument target preserves ECX and
    // EBX, writes these two capability bytes, and returns full EAX 0 or 1.
    const auto model=m.r8(kModel);
    if(model<5u) {
        m.w8(kCpuCap0,0);m.w8(kCpuCap1,0);return 0;
    }
    const auto feature=op.cpuid(1,in.cx,op.context);
    if((feature.dx&0x00008000u)==0) {
        m.w8(kCpuCap0,0);m.w8(kCpuCap1,0);return 0;
    }
    m.w8(kCpuCap0,model>5u?1u:0u);
    m.w8(kCpuCap1,1);
    return 1;
}

std::uint8_t lower_ascii(std::uint8_t c) {
    return c>='A'&&c<='Z'?static_cast<std::uint8_t>(c+0x20u):c;
}
std::uint32_t compare_string(Memory& m,const std::array<std::uint8_t,64>& left,
                             std::uint32_t right) {
    // Accepted 0x76d860 mode-zero route: full NUL-terminated ASCII-insensitive
    // strcmp; the eight-byte push/cleanup is argument size, not compare length.
    for(unsigned n=0;n<left.size();++n) {
        const auto a=left[n];
        const auto b=static_cast<std::uint8_t>(m.r8(right+n));
        if(a==b) { if(!a)return 0; continue; }
        const auto la=lower_ascii(a),lb=lower_ascii(b);
        if(la!=lb)return la<lb?0xffffffffu:1u;
        if(!la)return 0;
    }
    throw std::domain_error("B382 classifier string lacks a NUL within 64 bytes");
}

std::uint32_t classify_table_target(Memory&,std::uint32_t model) {
    // Literal result map from pinned original table4d2224, executed separately
    // in native comparisons. The source does not read executable guest memory.
    constexpr std::uint32_t values[]={3,2,3,5,4,4,2,4};
    return model>=3 && model<=10?values[model-3]:2;
}
} // namespace

std::uint32_t fun_0076aa8d(Memory& m,const Inputs& in) {
    const auto op=ra2::platform::cpu382::native_operations();
    std::uint32_t result=0;
    ra2::platform::cpu382::require_operations(op);
    const auto flags=op.probe_flags(op.context);
    // The target restores AC after its trial and can leave the successful ID test
    // inverted. The adapter's domain forces AC=0; keep ID as explicit guest
    // state rather than changing the real host EFLAGS.
    in.flags_out=(in.arithmetic_flags&kId);
    m.w8(kFamily,0);
    std::uint8_t status=0;
    std::uint32_t leaf1_ecx=0;
    if(!flags.ac_toggled) {
        status=3;
    } else {
        status=4;
        if(flags.id_toggled) {
            in.flags_out^=kId;
            // Leaf0/1 ignore subleaf ECX on the supported real CPU route.
            // Original ECX before leaf0 is its saved EFLAGS, then leaf0 ECX.
            const auto base=op.cpuid(0,flags.entry,op.context);
            m.w32(kVendor+0,base.bx);
            m.w32(kVendor+4,base.dx);
            m.w32(kVendor+8,base.cx);
            m.w32(kVendor+12,0x20u);
            if(ra2::recovered::global_b26::s32(base.ax)>=1) {
                const auto version=op.cpuid(1,base.cx,op.context);
                leaf1_ecx=version.cx;
                m.w8(kFamily,(version.ax>>4)&0x0fu);
                status=static_cast<std::uint8_t>((version.ax>>8)&0x0fu);
            }
        }
    }
    m.w8(kModel,status);
    if(status<5u) {
        m.w8(kStatus,0);
        result=0;
    } else {
        const auto features=op.cpuid(1,leaf1_ecx,op.context);
        const bool mmx=(features.dx&0x00800000u)!=0;
        m.w8(kStatus,mmx?1u:0u);
        result=mmx?1u:0u;
    }
    return result;
}

std::uint32_t fun_004d2130(Memory& m,const Inputs& in) {
    const auto op=ra2::platform::cpu382::native_operations();
    std::uint32_t result=0;
    ra2::platform::cpu382::require_operations(op);
    // Original no-argument routine: SUB ESP,40h; PUSH ESI; calls 0x36aa8d
    // and accepted 0x36ab4f without stack arguments. Keep the copied vendor
    // string in a private native local, never as an exposed guest stack write.
    (void)fun_0076aa8d(m,in);
    (void)run_36ab4f(m,in,op);
    const auto status_byte=m.r8(kModel);
    const auto status=(status_byte&0x80u)?static_cast<std::int32_t>(status_byte)-256:
                                              static_cast<std::int32_t>(status_byte);
    const auto family=static_cast<std::uint8_t>(m.r8(kFamily));

    std::array<std::uint8_t,64> vendor{};
    for(unsigned n=0;n<vendor.size();++n) {
        const auto c=static_cast<std::uint8_t>(m.r8(kVendor+n));
        vendor[n]=c;
        if(c==0)break; // 0x76dd10 zero-fills the rest of this private array
    }

    if(status==0||family==0) { result=0xffffffffu;return result; }

    // Image literals recovered from the pinned target: VA 0x7c395c is
    // "AuthenticAMD" and VA 0x7c394c is "CyrixInstead". The compare helper
    // returns zero on equality, producing the original 7/8 branches.
    if(m.r32(kMode)!=0) throw std::domain_error("B382 excludes nonzero 0x76d860 mode");
    if(compare_string(m,vendor,kAuthenticAmd)==0) { result=7;return result; }
    if(compare_string(m,vendor,kCyrixInstead)==0) { result=8;return result; }

    if(status==4) { result=0;return result; }
    if(status==5) { result=1;return result; }
    if(status==6) { result=classify_table_target(m,family);return result; }
    result=6;
    return result;
}
} // namespace ra2::recovered::recovery_b382
