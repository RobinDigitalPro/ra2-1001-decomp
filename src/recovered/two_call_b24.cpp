#include "two_call_b24.hpp"
#include <stdexcept>

namespace ra2::recovered::two_call_b24 {
const std::array<Entry, 37>& entries() {
    static const std::array<Entry, 37> value{{
    Entry{0x8cad0u, 59u, 0x8u, 0x7892bcu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cad0},
    Entry{0x8cb10u, 59u, 0x8u, 0x7892acu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cb10},
    Entry{0x8cb50u, 59u, 0xcu, 0x78929cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cb50},
    Entry{0x8cb90u, 59u, 0x8u, 0x78928cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cb90},
    Entry{0x8cbd0u, 59u, 0x8u, 0x78927cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cbd0},
    Entry{0x8cc10u, 59u, 0x8u, 0x78926cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cc10},
    Entry{0x8ccf0u, 59u, 0x8u, 0x78920cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048ccf0},
    Entry{0x8cd30u, 59u, 0xcu, 0x7891fcu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cd30},
    Entry{0x8cd70u, 59u, 0x8u, 0x7891ecu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cd70},
    Entry{0x8cdb0u, 59u, 0x8u, 0x7891dcu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cdb0},
    Entry{0x8cdf0u, 59u, 0x8u, 0x7891ccu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cdf0},
    Entry{0x8ce30u, 59u, 0x8u, 0x7891bcu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048ce30},
    Entry{0x8ce70u, 59u, 0x8u, 0x7891acu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048ce70},
    Entry{0x8ceb0u, 59u, 0x8u, 0x78919cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048ceb0},
    Entry{0x8cef0u, 59u, 0x8u, 0x78918cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cef0},
    Entry{0x8cf30u, 59u, 0xcu, 0x78917cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cf30},
    Entry{0x8cf70u, 59u, 0x8u, 0x78916cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cf70},
    Entry{0x8cfb0u, 59u, 0x8u, 0x78915cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cfb0},
    Entry{0x8cff0u, 59u, 0x8u, 0x78914cu, 0x78952cu, 0x8198f8u, 0x1e510u, &fun_0048cff0},
    Entry{0x8d2d0u, 59u, 0x8u, 0x789044u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d2d0},
    Entry{0x8d310u, 59u, 0xcu, 0x789038u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d310},
    Entry{0x8d350u, 59u, 0x8u, 0x78902cu, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d350},
    Entry{0x8d390u, 59u, 0x8u, 0x789020u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d390},
    Entry{0x8d3d0u, 59u, 0x8u, 0x789014u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d3d0},
    Entry{0x8d410u, 59u, 0x8u, 0x789008u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d410},
    Entry{0x8d450u, 59u, 0xcu, 0x788ffcu, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d450},
    Entry{0x8d490u, 59u, 0x8u, 0x788ff0u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d490},
    Entry{0x8d4d0u, 59u, 0x8u, 0x788fe4u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d4d0},
    Entry{0x8d510u, 59u, 0x8u, 0x788fd8u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d510},
    Entry{0x8d550u, 59u, 0x8u, 0x788fccu, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d550},
    Entry{0x8d590u, 59u, 0x8u, 0x788fc0u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d590},
    Entry{0x8d5d0u, 59u, 0x8u, 0x788fb4u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d5d0},
    Entry{0x8d610u, 59u, 0x8u, 0x788fa8u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d610},
    Entry{0x8d650u, 59u, 0xcu, 0x788f9cu, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d650},
    Entry{0x8d690u, 59u, 0x8u, 0x788f90u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d690},
    Entry{0x8d6d0u, 59u, 0x8u, 0x788f84u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d6d0},
    Entry{0x8d710u, 59u, 0x8u, 0x788f78u, 0x78953cu, 0x8198f8u, 0x1e510u, &fun_0048d710}
    }};
    return value;
}

std::uint32_t fun_0048cad0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x7892bcu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cb10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x7892acu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cb50(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0xcu);
    memory.w32(receiver, 0x78929cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0xcu, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cb90(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78928cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cbd0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78927cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cc10(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78926cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048ccf0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78920cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cd30(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0xcu);
    memory.w32(receiver, 0x7891fcu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0xcu, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cd70(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x7891ecu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cdb0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x7891dcu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cdf0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x7891ccu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048ce30(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x7891bcu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048ce70(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x7891acu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048ceb0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78919cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cef0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78918cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cf30(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0xcu);
    memory.w32(receiver, 0x78917cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0xcu, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cf70(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78916cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cfb0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78915cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048cff0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78914cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78952cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d2d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x789044u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d310(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0xcu);
    memory.w32(receiver, 0x789038u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0xcu, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d350(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x78902cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d390(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x789020u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d3d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x789014u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d410(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x789008u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d450(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0xcu);
    memory.w32(receiver, 0x788ffcu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0xcu, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d490(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788ff0u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d4d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788fe4u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d510(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788fd8u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d550(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788fccu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d590(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788fc0u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d5d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788fb4u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d610(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788fa8u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d650(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0xcu);
    memory.w32(receiver, 0x788f9cu);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0xcu, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d690(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788f90u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d6d0(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788f84u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

std::uint32_t fun_0048d710(leaf::Memory& memory, const leaf::Inputs& inputs, const Operations& operations) {
    const std::uint32_t receiver = inputs.cx;
    const std::uint32_t old_pointer = memory.r32(receiver + 0x8u);
    memory.w32(receiver, 0x788f78u);
    if (!operations.first) throw std::invalid_argument("Block24 wrapper requires first-call observer");
    operations.first(0x1e510u, 0x8198f8u, old_pointer, operations.context);
    memory.w32(receiver + 0x8u, 0u);
    memory.w32(receiver, 0x78953cu);
    if ((inputs.arg[0] & 1u) != 0u) {
        (void)ra2::recovered::fun_0076d67b(receiver, operations.heap);
    }
    return receiver;
}

} // namespace ra2::recovered::two_call_b24
