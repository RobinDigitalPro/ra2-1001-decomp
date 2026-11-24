#include "two_call_b23.hpp"

#include <stdexcept>

namespace ra2::recovered::two_call_b23 {
std::uint32_t fun_00401950(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00785658u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0002f250u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0040e2e0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0010ad20u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0041b610(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00013da0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00423ed0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00020a90u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004538f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000390c0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0045e9a0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00057e40u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00463b30(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0005f200u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00468aa0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00137180u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0046c790(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00206640u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0046c7b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0035f240u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0046c7d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0035f0d0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0047cba0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00070a80u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00480d80(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0007fdf0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00483350(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00497100(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0049ea10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0049ea50(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00145020u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0049ea70(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002906b0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0049eae0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00206640u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004a5490(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000b2770u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004a54b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0026aa70u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004a54d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004c1cf0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000c0a40u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004cda10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000c2920u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004cf2f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00137180u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004d0850(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004d0870(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004de580(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0010ad20u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004de5a0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000ddf10u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004f60a0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000e2750u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_004fe400(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0013b1d0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00508c60(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000fee80u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0050feb0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0010fca0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0050ff50(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002906b0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0050ff90(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00206640u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00523260(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0078f644u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00081140u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00525ab0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00123f20u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0052c910(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001273f0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00537110(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x007905bcu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000850f0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00538d20(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00279ff0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005677c0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00145020u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0058a850(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00139310u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00592a40(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000354b0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00592b40(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002906b0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00599970(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00215020u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0059f2c0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00791690u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b3930u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0059f3b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b63e0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a2eb0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0019f8f0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a3db0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x007918ecu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b3930u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a40f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x007919b4u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b3930u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a7370(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00791a7cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b3930u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a7400(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b63e0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a8780(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00791b64u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b3930u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a8aa0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00791c2cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b63e0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a8ad0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00791c3cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b63e0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005a90f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00791c5cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b3930u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005b0420(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001af850u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005b1250(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001b0b50u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005cdbd0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001cabc0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005d0680(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001ce1f0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_005f90e0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0035b390u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00604c10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00202a60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00614e00(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00226710u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0062c050(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0062f530(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0022e950u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00677b70(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00677b90(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00680100(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0027f180u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00694330(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00291f50u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006a9930(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002a9040u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006aa520(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002a9d00u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006b3d90(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002acdc0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006cecc0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002b7720u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006d4d10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002cfec0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006d9e10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002d82c0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006dc7f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006dfcb0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002dde20u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006e11b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002e0650u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006e41b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002e32f0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006e6670(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0013b1d0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006e6aa0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x000cec60u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_006feef0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002ef460u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00702b50(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00301a00u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_007072f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x003049b0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071b680(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799eb4u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071b6b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799ebcu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071b700(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799e6cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071b730(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799e74u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071c880(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799e7cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071c8b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799f64u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071c8e0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799f5cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071c910(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799f88u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071c9b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0031d230u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071d7f0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x00799fa8u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230cb0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071db60(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a034u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071fac0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a04cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001a9270u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071faf0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0031dfb0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0071fc80(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a074u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00721590(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a168u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230cb0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_007215c0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00320e90u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00724e50(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00322550u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00727840(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a29cu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001a9270u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0072cfe0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a3acu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x002e0650u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0072ec80(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a3dcu);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00230ab0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0074a870(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    memory.w32(receiver, 0x0079a584u);
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x001f8d90u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00752990(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00359320u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_007529b0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00359320u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_007529d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00359320u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_00756ba0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x00356ea0u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0075f050(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    
    if (!operations.first) throw std::invalid_argument("two-call wrapper requires first-call observer");
    operations.first(0x0035d500u, receiver, operations.context);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

const std::array<Entry, 110>& entries() {
    static const std::array<Entry, 110> value{{
    {0x00001950u, 36u, 0x0002f250u, 0x00785658u, true, fun_00401950},
    {0x0000e2e0u, 30u, 0x0010ad20u, 0x00000000u, false, fun_0040e2e0},
    {0x0001b610u, 30u, 0x00013da0u, 0x00000000u, false, fun_0041b610},
    {0x00023ed0u, 30u, 0x00020a90u, 0x00000000u, false, fun_00423ed0},
    {0x000538f0u, 30u, 0x000390c0u, 0x00000000u, false, fun_004538f0},
    {0x0005e9a0u, 30u, 0x00057e40u, 0x00000000u, false, fun_0045e9a0},
    {0x00063b30u, 30u, 0x0005f200u, 0x00000000u, false, fun_00463b30},
    {0x00068aa0u, 30u, 0x00137180u, 0x00000000u, false, fun_00468aa0},
    {0x0006c790u, 30u, 0x00206640u, 0x00000000u, false, fun_0046c790},
    {0x0006c7b0u, 30u, 0x0035f240u, 0x00000000u, false, fun_0046c7b0},
    {0x0006c7d0u, 30u, 0x0035f0d0u, 0x00000000u, false, fun_0046c7d0},
    {0x0007cba0u, 30u, 0x00070a80u, 0x00000000u, false, fun_0047cba0},
    {0x00080d80u, 30u, 0x0007fdf0u, 0x00000000u, false, fun_00480d80},
    {0x00083350u, 30u, 0x000cec60u, 0x00000000u, false, fun_00483350},
    {0x00097100u, 30u, 0x000cec60u, 0x00000000u, false, fun_00497100},
    {0x0009ea10u, 30u, 0x000cec60u, 0x00000000u, false, fun_0049ea10},
    {0x0009ea50u, 30u, 0x00145020u, 0x00000000u, false, fun_0049ea50},
    {0x0009ea70u, 30u, 0x002906b0u, 0x00000000u, false, fun_0049ea70},
    {0x0009eae0u, 30u, 0x00206640u, 0x00000000u, false, fun_0049eae0},
    {0x000a5490u, 30u, 0x000b2770u, 0x00000000u, false, fun_004a5490},
    {0x000a54b0u, 30u, 0x0026aa70u, 0x00000000u, false, fun_004a54b0},
    {0x000a54d0u, 30u, 0x000cec60u, 0x00000000u, false, fun_004a54d0},
    {0x000c1cf0u, 30u, 0x000c0a40u, 0x00000000u, false, fun_004c1cf0},
    {0x000cda10u, 30u, 0x000c2920u, 0x00000000u, false, fun_004cda10},
    {0x000cf2f0u, 30u, 0x00137180u, 0x00000000u, false, fun_004cf2f0},
    {0x000d0850u, 30u, 0x000cec60u, 0x00000000u, false, fun_004d0850},
    {0x000d0870u, 30u, 0x000cec60u, 0x00000000u, false, fun_004d0870},
    {0x000de580u, 30u, 0x0010ad20u, 0x00000000u, false, fun_004de580},
    {0x000de5a0u, 30u, 0x000ddf10u, 0x00000000u, false, fun_004de5a0},
    {0x000f60a0u, 30u, 0x000e2750u, 0x00000000u, false, fun_004f60a0},
    {0x000fe400u, 30u, 0x0013b1d0u, 0x00000000u, false, fun_004fe400},
    {0x00108c60u, 30u, 0x000fee80u, 0x00000000u, false, fun_00508c60},
    {0x0010feb0u, 30u, 0x0010fca0u, 0x00000000u, false, fun_0050feb0},
    {0x0010ff50u, 30u, 0x002906b0u, 0x00000000u, false, fun_0050ff50},
    {0x0010ff90u, 30u, 0x00206640u, 0x00000000u, false, fun_0050ff90},
    {0x00123260u, 36u, 0x00081140u, 0x0078f644u, true, fun_00523260},
    {0x00125ab0u, 30u, 0x00123f20u, 0x00000000u, false, fun_00525ab0},
    {0x0012c910u, 30u, 0x001273f0u, 0x00000000u, false, fun_0052c910},
    {0x00137110u, 36u, 0x000850f0u, 0x007905bcu, true, fun_00537110},
    {0x00138d20u, 30u, 0x00279ff0u, 0x00000000u, false, fun_00538d20},
    {0x001677c0u, 30u, 0x00145020u, 0x00000000u, false, fun_005677c0},
    {0x0018a850u, 30u, 0x00139310u, 0x00000000u, false, fun_0058a850},
    {0x00192a40u, 30u, 0x000354b0u, 0x00000000u, false, fun_00592a40},
    {0x00192b40u, 30u, 0x002906b0u, 0x00000000u, false, fun_00592b40},
    {0x00199970u, 30u, 0x00215020u, 0x00000000u, false, fun_00599970},
    {0x0019f2c0u, 36u, 0x001b3930u, 0x00791690u, true, fun_0059f2c0},
    {0x0019f3b0u, 30u, 0x001b63e0u, 0x00000000u, false, fun_0059f3b0},
    {0x001a2eb0u, 30u, 0x0019f8f0u, 0x00000000u, false, fun_005a2eb0},
    {0x001a3db0u, 36u, 0x001b3930u, 0x007918ecu, true, fun_005a3db0},
    {0x001a40f0u, 36u, 0x001b3930u, 0x007919b4u, true, fun_005a40f0},
    {0x001a7370u, 36u, 0x001b3930u, 0x00791a7cu, true, fun_005a7370},
    {0x001a7400u, 30u, 0x001b63e0u, 0x00000000u, false, fun_005a7400},
    {0x001a8780u, 36u, 0x001b3930u, 0x00791b64u, true, fun_005a8780},
    {0x001a8aa0u, 36u, 0x001b63e0u, 0x00791c2cu, true, fun_005a8aa0},
    {0x001a8ad0u, 36u, 0x001b63e0u, 0x00791c3cu, true, fun_005a8ad0},
    {0x001a90f0u, 36u, 0x001b3930u, 0x00791c5cu, true, fun_005a90f0},
    {0x001b0420u, 30u, 0x001af850u, 0x00000000u, false, fun_005b0420},
    {0x001b1250u, 30u, 0x001b0b50u, 0x00000000u, false, fun_005b1250},
    {0x001cdbd0u, 30u, 0x001cabc0u, 0x00000000u, false, fun_005cdbd0},
    {0x001d0680u, 30u, 0x001ce1f0u, 0x00000000u, false, fun_005d0680},
    {0x001f90e0u, 30u, 0x0035b390u, 0x00000000u, false, fun_005f90e0},
    {0x00204c10u, 30u, 0x00202a60u, 0x00000000u, false, fun_00604c10},
    {0x00214e00u, 30u, 0x00226710u, 0x00000000u, false, fun_00614e00},
    {0x0022c050u, 30u, 0x000cec60u, 0x00000000u, false, fun_0062c050},
    {0x0022f530u, 30u, 0x0022e950u, 0x00000000u, false, fun_0062f530},
    {0x00277b70u, 30u, 0x000cec60u, 0x00000000u, false, fun_00677b70},
    {0x00277b90u, 30u, 0x000cec60u, 0x00000000u, false, fun_00677b90},
    {0x00280100u, 30u, 0x0027f180u, 0x00000000u, false, fun_00680100},
    {0x00294330u, 30u, 0x00291f50u, 0x00000000u, false, fun_00694330},
    {0x002a9930u, 30u, 0x002a9040u, 0x00000000u, false, fun_006a9930},
    {0x002aa520u, 30u, 0x002a9d00u, 0x00000000u, false, fun_006aa520},
    {0x002b3d90u, 30u, 0x002acdc0u, 0x00000000u, false, fun_006b3d90},
    {0x002cecc0u, 30u, 0x002b7720u, 0x00000000u, false, fun_006cecc0},
    {0x002d4d10u, 30u, 0x002cfec0u, 0x00000000u, false, fun_006d4d10},
    {0x002d9e10u, 30u, 0x002d82c0u, 0x00000000u, false, fun_006d9e10},
    {0x002dc7f0u, 30u, 0x000cec60u, 0x00000000u, false, fun_006dc7f0},
    {0x002dfcb0u, 30u, 0x002dde20u, 0x00000000u, false, fun_006dfcb0},
    {0x002e11b0u, 30u, 0x002e0650u, 0x00000000u, false, fun_006e11b0},
    {0x002e41b0u, 30u, 0x002e32f0u, 0x00000000u, false, fun_006e41b0},
    {0x002e6670u, 30u, 0x0013b1d0u, 0x00000000u, false, fun_006e6670},
    {0x002e6aa0u, 30u, 0x000cec60u, 0x00000000u, false, fun_006e6aa0},
    {0x002feef0u, 30u, 0x002ef460u, 0x00000000u, false, fun_006feef0},
    {0x00302b50u, 30u, 0x00301a00u, 0x00000000u, false, fun_00702b50},
    {0x003072f0u, 30u, 0x003049b0u, 0x00000000u, false, fun_007072f0},
    {0x0031b680u, 36u, 0x00230ab0u, 0x00799eb4u, true, fun_0071b680},
    {0x0031b6b0u, 36u, 0x00230ab0u, 0x00799ebcu, true, fun_0071b6b0},
    {0x0031b700u, 36u, 0x00230ab0u, 0x00799e6cu, true, fun_0071b700},
    {0x0031b730u, 36u, 0x00230ab0u, 0x00799e74u, true, fun_0071b730},
    {0x0031c880u, 36u, 0x00230ab0u, 0x00799e7cu, true, fun_0071c880},
    {0x0031c8b0u, 36u, 0x00230ab0u, 0x00799f64u, true, fun_0071c8b0},
    {0x0031c8e0u, 36u, 0x00230ab0u, 0x00799f5cu, true, fun_0071c8e0},
    {0x0031c910u, 36u, 0x00230ab0u, 0x00799f88u, true, fun_0071c910},
    {0x0031c9b0u, 30u, 0x0031d230u, 0x00000000u, false, fun_0071c9b0},
    {0x0031d7f0u, 36u, 0x00230cb0u, 0x00799fa8u, true, fun_0071d7f0},
    {0x0031db60u, 36u, 0x00230ab0u, 0x0079a034u, true, fun_0071db60},
    {0x0031fac0u, 36u, 0x001a9270u, 0x0079a04cu, true, fun_0071fac0},
    {0x0031faf0u, 30u, 0x0031dfb0u, 0x00000000u, false, fun_0071faf0},
    {0x0031fc80u, 36u, 0x00230ab0u, 0x0079a074u, true, fun_0071fc80},
    {0x00321590u, 36u, 0x00230cb0u, 0x0079a168u, true, fun_00721590},
    {0x003215c0u, 30u, 0x00320e90u, 0x00000000u, false, fun_007215c0},
    {0x00324e50u, 30u, 0x00322550u, 0x00000000u, false, fun_00724e50},
    {0x00327840u, 36u, 0x001a9270u, 0x0079a29cu, true, fun_00727840},
    {0x0032cfe0u, 36u, 0x002e0650u, 0x0079a3acu, true, fun_0072cfe0},
    {0x0032ec80u, 36u, 0x00230ab0u, 0x0079a3dcu, true, fun_0072ec80},
    {0x0034a870u, 36u, 0x001f8d90u, 0x0079a584u, true, fun_0074a870},
    {0x00352990u, 30u, 0x00359320u, 0x00000000u, false, fun_00752990},
    {0x003529b0u, 30u, 0x00359320u, 0x00000000u, false, fun_007529b0},
    {0x003529d0u, 30u, 0x00359320u, 0x00000000u, false, fun_007529d0},
    {0x00356ba0u, 30u, 0x00356ea0u, 0x00000000u, false, fun_00756ba0},
    {0x0035f050u, 30u, 0x0035d500u, 0x00000000u, false, fun_0075f050}
    }};
    return value;
}
} // namespace ra2::recovered::two_call_b23
