#include "recovered/leaf_b17_init.hpp"

namespace ra2::recovered::leaf {

// Original RVA 0x3820; zero_and_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00403820(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0);
    m.w32(i.cx+0x4u,0);
    m.w32(i.cx+0x8u,0);
    m.w32(i.cx+0xcu,0);
    m.w32(i.cx+0x10u,0);
    m.w32(i.cx+0x14u,0);
    m.w32(i.cx+0x18u,0);
    m.w32(i.cx+0x1cu,0);
    m.w32(i.cx+0x28u,0);
    m.w32(i.cx+0x2cu,0);
    m.w32(i.cx+0x48u,0);
    m.w32(i.cx+0x50u,0);
    m.w32(i.cx+0x40u,0x1388u);
    m.w32(i.cx+0x44u,0);
    m.w32(i.cx+0x30u,0);
    m.w32(i.cx+0x34u,0);
    m.w32(i.cx+0x38u,0);
    m.w32(i.cx+0x3cu,0);
    m.w32(i.cx+0x54u,0);
    m.w32(i.cx+0x4cu,0);
    return 0;
}

// Original RVA 0xff60; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0040ff60(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x8u,0x785e44u);
    m.w32(i.cx+0xcu,0x785e3cu);
    m.w32(i.cx,0x785dd8u);
    m.w32(i.cx+0x4u,0x785dbcu);
    m.w32(i.cx+0x8u,0x785db4u);
    m.w32(i.cx+0xcu,0x785dacu);
    return i.cx;
}

// Original RVA 0xe07c0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_004e07c0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w8(i.cx,0x0u);
    return i.cx;
}

// Original RVA 0x10a540; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0050a540(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x7889f4u);
    return i.cx;
}

// Original RVA 0x10a550; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0050a550(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x78eb3cu);
    return i.cx;
}

// Original RVA 0x10a6a0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0050a6a0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x78eb7cu);
    return i.cx;
}

// Original RVA 0x11cdb0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0051cdb0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x78f4b4u);
    return i.cx;
}

// Original RVA 0x11ce50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0051ce50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x78f4dcu);
    return i.cx;
}

// Original RVA 0x11cef0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0051cef0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x78f504u);
    return i.cx;
}

// Original RVA 0x1371d0; zero_and_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_005371d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0);
    m.w32(i.cx+0x8u,0);
    return 0;
}

// Original RVA 0x13b1d0; constant_field_initializer; defined EAX mask 0x0.
std::uint32_t fun_0053b1d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x78e3b4u);
    m.w32(i.cx+0x4u,0x78e2ecu);
    m.w32(i.cx+0xcu,0x0u);
    return 0;
}

// Original RVA 0x215010; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00615010(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x0u);
    return i.cx;
}

// Original RVA 0x286ed0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00686ed0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x7968b8u);
    return i.cx;
}

// Original RVA 0x2871d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006871d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x7968e8u);
    return i.cx;
}

// Original RVA 0x2877d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006877d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796948u);
    return i.cx;
}

// Original RVA 0x287950; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00687950(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796960u);
    return i.cx;
}

// Original RVA 0x287ad0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00687ad0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796978u);
    return i.cx;
}

// Original RVA 0x287c50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00687c50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796990u);
    return i.cx;
}

// Original RVA 0x287f50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00687f50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x7969c0u);
    return i.cx;
}

// Original RVA 0x2880d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006880d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x7969d8u);
    return i.cx;
}

// Original RVA 0x288250; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00688250(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x7969f0u);
    return i.cx;
}

// Original RVA 0x2883d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006883d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796a08u);
    return i.cx;
}

// Original RVA 0x288550; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00688550(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796a20u);
    return i.cx;
}

// Original RVA 0x288850; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00688850(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796a50u);
    return i.cx;
}

// Original RVA 0x2889d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006889d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796a68u);
    return i.cx;
}

// Original RVA 0x288b50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00688b50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796a80u);
    return i.cx;
}

// Original RVA 0x288cd0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00688cd0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796a98u);
    return i.cx;
}

// Original RVA 0x288e50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00688e50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796ab0u);
    return i.cx;
}

// Original RVA 0x289150; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00689150(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796ae0u);
    return i.cx;
}

// Original RVA 0x2892d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006892d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796af8u);
    return i.cx;
}

// Original RVA 0x289450; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00689450(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796b10u);
    return i.cx;
}

// Original RVA 0x2895d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006895d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796b28u);
    return i.cx;
}

// Original RVA 0x289750; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00689750(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796b40u);
    return i.cx;
}

// Original RVA 0x289a50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00689a50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796b70u);
    return i.cx;
}

// Original RVA 0x289bd0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00689bd0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796b88u);
    return i.cx;
}

// Original RVA 0x289d50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00689d50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796ba0u);
    return i.cx;
}

// Original RVA 0x289ed0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00689ed0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796bb8u);
    return i.cx;
}

// Original RVA 0x28a050; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068a050(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796bd0u);
    return i.cx;
}

// Original RVA 0x28a350; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068a350(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796c00u);
    return i.cx;
}

// Original RVA 0x28a4d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068a4d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796c18u);
    return i.cx;
}

// Original RVA 0x28a650; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068a650(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796c30u);
    return i.cx;
}

// Original RVA 0x28a7d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068a7d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796c48u);
    return i.cx;
}

// Original RVA 0x28a950; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068a950(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796c60u);
    return i.cx;
}

// Original RVA 0x28ac50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068ac50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796c90u);
    return i.cx;
}

// Original RVA 0x28add0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068add0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796ca8u);
    return i.cx;
}

// Original RVA 0x28af50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068af50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796cc0u);
    return i.cx;
}

// Original RVA 0x28b250; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068b250(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796cf0u);
    return i.cx;
}

// Original RVA 0x28b3d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068b3d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796d08u);
    return i.cx;
}

// Original RVA 0x28b550; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068b550(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796d20u);
    return i.cx;
}

// Original RVA 0x28b850; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068b850(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796d50u);
    return i.cx;
}

// Original RVA 0x28bb50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068bb50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796d80u);
    return i.cx;
}

// Original RVA 0x28bcd0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068bcd0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796d98u);
    return i.cx;
}

// Original RVA 0x28be50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068be50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796db0u);
    return i.cx;
}

// Original RVA 0x28c150; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068c150(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796de0u);
    return i.cx;
}

// Original RVA 0x28c2d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068c2d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796df8u);
    return i.cx;
}

// Original RVA 0x28c450; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068c450(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796e10u);
    return i.cx;
}

// Original RVA 0x28c5d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068c5d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796e28u);
    return i.cx;
}

// Original RVA 0x28c750; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068c750(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796e40u);
    return i.cx;
}

// Original RVA 0x28c8d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068c8d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796e58u);
    return i.cx;
}

// Original RVA 0x28ca50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068ca50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796e70u);
    return i.cx;
}

// Original RVA 0x28cbd0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068cbd0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796e88u);
    return i.cx;
}

// Original RVA 0x28cd50; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068cd50(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796ea0u);
    return i.cx;
}

// Original RVA 0x28ced0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068ced0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796eb8u);
    return i.cx;
}

// Original RVA 0x28d050; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068d050(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796ed0u);
    return i.cx;
}

// Original RVA 0x28d1d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068d1d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796ee8u);
    return i.cx;
}

// Original RVA 0x28d350; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068d350(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796f00u);
    return i.cx;
}

// Original RVA 0x28d4d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068d4d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796f18u);
    return i.cx;
}

// Original RVA 0x28d650; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068d650(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796f30u);
    return i.cx;
}

// Original RVA 0x28d7d0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068d7d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796f48u);
    return i.cx;
}

// Original RVA 0x28d950; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0068d950(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0x0u);
    m.w32(i.cx,0x796f60u);
    return i.cx;
}

// Original RVA 0x290b80; zero_and_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00690b80(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx+0x4u,0);
    m.w32(i.cx+0x8u,0);
    return 0;
}

// Original RVA 0x2d4e00; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006d4e00(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x79402cu);
    return i.cx;
}

// Original RVA 0x2d4e10; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006d4e10(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x788a94u);
    return i.cx;
}

// Original RVA 0x2d4e20; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_006d4e20(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x78df28u);
    return i.cx;
}

// Original RVA 0x307f00; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00707f00(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x0u);
    m.w32(i.cx+0x4u,0x0u);
    return i.cx;
}

// Original RVA 0x3080d0; constant_field_initializer; defined EAX mask 0x0.
std::uint32_t fun_007080d0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x0u);
    m.w32(i.cx+0x4u,0x0u);
    return 0;
}

// Original RVA 0x359250; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_00759250(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x0u);
    return i.cx;
}

// Original RVA 0x35b2f0; opaque_tag_or_constant_initializer; defined EAX mask 0xffffffff.
std::uint32_t fun_0075b2f0(Memory& m,const Inputs& i) {
    (void)m; (void)i;
    m.w32(i.cx,0x0u);
    return i.cx;
}

}
