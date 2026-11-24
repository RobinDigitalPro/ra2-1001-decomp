#include "recovered/leaf_b17_fields.hpp"

namespace ra2::recovered::leaf {

// Original RVA 0x1940; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00401940(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x14u);
}

// Original RVA 0x6320; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00406320(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x24u);
}

// Original RVA 0x6530; field_store; defined EAX mask 0x0.
std::uint32_t fun_00406530(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x138u,i.dx);
    return 0;
}

// Original RVA 0x6540; field_store; defined EAX mask 0x0.
std::uint32_t fun_00406540(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x13cu,i.dx);
    return 0;
}

// Original RVA 0x6550; field_store; defined EAX mask 0x0.
std::uint32_t fun_00406550(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x40u,i.dx);
    return 0;
}

// Original RVA 0x65d0; field_store; defined EAX mask 0x0.
std::uint32_t fun_004065d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x14u,i.dx);
    return 0;
}

// Original RVA 0x65e0; field_store; defined EAX mask 0x0.
std::uint32_t fun_004065e0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x48u,i.dx);
    return 0;
}

// Original RVA 0x65f0; field_store; defined EAX mask 0x0.
std::uint32_t fun_004065f0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x50u,i.dx);
    return 0;
}

// Original RVA 0x6600; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00406600(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x54u,value);
    return value;
}

// Original RVA 0x6650; field_store; defined EAX mask 0x0.
std::uint32_t fun_00406650(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4cu,i.dx);
    return 0;
}

// Original RVA 0x8520; field_store; defined EAX mask 0x0.
std::uint32_t fun_00408520(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x14u,0x0u);
    return 0;
}

// Original RVA 0x8c70; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00408c70(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x14u);
}

// Original RVA 0x112c0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004112c0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x4u);
}

// Original RVA 0x112d0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004112d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x8u);
}

// Original RVA 0x113b0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004113b0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x10u);
}

// Original RVA 0x22680; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00422680(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x15cu,value);
    return value;
}

// Original RVA 0x22690; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00422690(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x160u,value);
    return value;
}

// Original RVA 0x22c10; field_store; defined EAX mask 0x0.
std::uint32_t fun_00422c10(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x17eu,0x1u);
    return 0;
}

// Original RVA 0x22c20; field_store; defined EAX mask 0x0.
std::uint32_t fun_00422c20(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x17eu,0x0u);
    return 0;
}

// Original RVA 0x31790; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00431790(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x20u,value);
    return value;
}

// Original RVA 0x35eb0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00435eb0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x30u);
}

// Original RVA 0x52f60; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00452f60(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x564u);
}

// Original RVA 0x637d0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_004637d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x118u,value);
    return value;
}

// Original RVA 0x637e0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004637e0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x118u);
}

// Original RVA 0x64d80; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00464d80(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x2b8u,value);
    return value;
}

// Original RVA 0x68630; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00468630(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x4u);
}

// Original RVA 0x7ca30; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_0047ca30(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0xf8u,value);
    return value;
}

// Original RVA 0x7ca40; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_0047ca40(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0xf8u);
}

// Original RVA 0x805d0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004805d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x1cu);
}

// Original RVA 0x805e0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004805e0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x20u);
}

// Original RVA 0xaa970; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004aa970(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x10u);
}

// Original RVA 0xb9090; field_load; defined EAX mask 0xff.
std::uint32_t fun_004b9090(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r8(i.cx+0x58u);
}

// Original RVA 0xb9560; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004b9560(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x24u);
}

// Original RVA 0xb95a0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_004b95a0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x54u);
}

// Original RVA 0xcf180; field_store; defined EAX mask 0x0.
std::uint32_t fun_004cf180(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x1cu,0x1u);
    return 0;
}

// Original RVA 0xe0010; field_store; defined EAX mask 0x0.
std::uint32_t fun_004e0010(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0xcu,0x2u);
    return 0;
}

// Original RVA 0xf2660; field_store; defined EAX mask 0x0.
std::uint32_t fun_004f2660(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x143u,0x1u);
    return 0;
}

// Original RVA 0x124450; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00524450(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x44u);
}

// Original RVA 0x1a9270; field_store; defined EAX mask 0x0.
std::uint32_t fun_005a9270(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x791d10u);
    return 0;
}

// Original RVA 0x1aa3f0; field_store; defined EAX mask 0x0.
std::uint32_t fun_005aa3f0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x40u,0x0u);
    return 0;
}

// Original RVA 0x1ab0f0; argument_field_store; defined EAX mask 0xff.
std::uint32_t fun_005ab0f0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0] & 0xffu;
    m.w8(i.cx+0x30u,value);
    return value;
}

// Original RVA 0x1c89e0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_005c89e0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x3cu);
}

// Original RVA 0x1d02b0; field_store; defined EAX mask 0x0.
std::uint32_t fun_005d02b0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x1u,0x47u);
    return 0;
}

// Original RVA 0x1d2a60; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_005d2a60(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x8u);
}

// Original RVA 0x1f8d90; field_store; defined EAX mask 0x0.
std::uint32_t fun_005f8d90(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x792ae8u);
    return 0;
}

// Original RVA 0x1f8e20; field_load; defined EAX mask 0xff.
std::uint32_t fun_005f8e20(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r8(i.cx+0x8u);
}

// Original RVA 0x1f8e30; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_005f8e30(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x4u);
}

// Original RVA 0x20b740; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_0060b740(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x14u);
}

// Original RVA 0x2169e0; field_store; defined EAX mask 0x0.
std::uint32_t fun_006169e0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x60u,0x0u);
    return 0;
}

// Original RVA 0x216a20; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00616a20(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x80u,value);
    return value;
}

// Original RVA 0x216a30; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00616a30(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x80u);
}

// Original RVA 0x216cf0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00616cf0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x78u,value);
    return value;
}

// Original RVA 0x217f80; field_store; defined EAX mask 0x0.
std::uint32_t fun_00617f80(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x64u,0x0u);
    return 0;
}

// Original RVA 0x217f90; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00617f90(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x4u,value);
    return value;
}

// Original RVA 0x22ccd0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_0062ccd0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x4u,value);
    return value;
}

// Original RVA 0x22cd20; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_0062cd20(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x34u,value);
    return value;
}

// Original RVA 0x22cd70; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_0062cd70(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x48u,value);
    return value;
}

// Original RVA 0x230cb0; field_store; defined EAX mask 0x0.
std::uint32_t fun_00630cb0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x793cd4u);
    return 0;
}

// Original RVA 0x250340; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00650340(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x4u,value);
    return value;
}

// Original RVA 0x250360; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00650360(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx,value);
    return value;
}

// Original RVA 0x250370; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00650370(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx);
}

// Original RVA 0x2503f0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_006503f0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x188u,value);
    return value;
}

// Original RVA 0x250400; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00650400(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x188u);
}

// Original RVA 0x250410; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00650410(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x18cu,value);
    return value;
}

// Original RVA 0x250420; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00650420(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x18cu);
}

// Original RVA 0x2505a0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_006505a0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x3f0u,value);
    return value;
}

// Original RVA 0x2505b0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_006505b0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x3f0u);
}

// Original RVA 0x269140; field_load; defined EAX mask 0xff.
std::uint32_t fun_00669140(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r8(i.cx+0x299cu);
}

// Original RVA 0x26ab50; argument_field_store; defined EAX mask 0xff.
std::uint32_t fun_0066ab50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0] & 0xffu;
    m.w8(i.cx+0x5cu,value);
    return value;
}

// Original RVA 0x290b90; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00690b90(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0xcu,value);
    return value;
}

// Original RVA 0x292650; argument_field_store; defined EAX mask 0xff.
std::uint32_t fun_00692650(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0] & 0xffu;
    m.w8(i.cx+0x57u,value);
    return value;
}

// Original RVA 0x2a1e00; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_006a1e00(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0xdb0u);
}

// Original RVA 0x2a95e0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_006a95e0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x30u,value);
    return value;
}

// Original RVA 0x2c6990; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_006c6990(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x408u,value);
    return value;
}

// Original RVA 0x2c69a0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_006c69a0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x408u);
}

// Original RVA 0x2cc3c0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_006cc3c0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x1b0u,value);
    return value;
}

// Original RVA 0x2cd9e0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_006cd9e0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x100u);
}

// Original RVA 0x2d0250; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_006d0250(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x550u);
}

// Original RVA 0x2e0ac0; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_006e0ac0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x228u,value);
    return value;
}

// Original RVA 0x2e2e30; field_store; defined EAX mask 0x0.
std::uint32_t fun_006e2e30(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x40u,0x0u);
    return 0;
}

// Original RVA 0x311da0; field_store; defined EAX mask 0x0.
std::uint32_t fun_00711da0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx+0x548u,0x0u);
    return 0;
}

// Original RVA 0x311df0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00711df0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x504u);
}

// Original RVA 0x311e70; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00711e70(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x508u,value);
    return value;
}

// Original RVA 0x311ec0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00711ec0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x510u);
}

// Original RVA 0x311ed0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00711ed0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x514u);
}

// Original RVA 0x320f60; field_load; defined EAX mask 0xff.
std::uint32_t fun_00720f60(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r8(i.cx+0x48u);
}

// Original RVA 0x324e90; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00724e90(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x4u);
}

// Original RVA 0x324ee0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00724ee0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x4u);
}

// Original RVA 0x324ef0; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_00724ef0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x4u);
}

// Original RVA 0x325d50; argument_field_store; defined EAX mask 0xffffffff.
std::uint32_t fun_00725d50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    const auto value=i.arg[0];
    m.w32(i.cx+0x2cu,value);
    return value;
}

// Original RVA 0x32a080; field_load; defined EAX mask 0xffffffff.
std::uint32_t fun_0072a080(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    return m.r32(i.cx+0x5cu);
}

// Original RVA 0x3524d0; field_store; defined EAX mask 0x0.
std::uint32_t fun_007524d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x0u);
    return 0;
}

}
