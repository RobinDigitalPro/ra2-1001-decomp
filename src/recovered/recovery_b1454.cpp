#include "recovered/recovery_b1454.hpp"
#include <windows.h>
#include <ocidl.h>
#include <cstdint>

namespace {
struct FloatingScope {
    const ra2::recovered::b1454::Inputs& input;
    ra2::platform::x87::Image host;
    explicit FloatingScope(const ra2::recovered::b1454::Inputs& x) : input(x), host(ra2::platform::x87::capture_host()) {
        input.fp.require_masked();
        ra2::platform::x87::restore_host(input.fp.image);
    }
    ~FloatingScope() {
        input.fp.image=ra2::platform::x87::capture_host();
        ra2::platform::x87::restore_host(host);
    }
};
}

namespace ra2::recovered::b1454 {
std::uint32_t fun_0074a8a0(Memory& m, const Inputs& i) {
    FloatingScope fp_scope(i);
    IID query_iid{};
    auto* raw = reinterpret_cast<std::uint8_t*>(&query_iid);
    for (std::uint32_t n = 0; n != 16u; ++n)
        raw[n] = static_cast<std::uint8_t>(m.r8(0x0079ab38u + n));

    auto* provider = reinterpret_cast<IUnknown*>(static_cast<std::uintptr_t>(i.arg[0]));
    auto* sink = reinterpret_cast<IUnknown*>(static_cast<std::uintptr_t>(i.arg[1]));
    auto* outgoing_iid = reinterpret_cast<const IID*>(static_cast<std::uintptr_t>(i.arg[2]));
    auto* cookie = reinterpret_cast<DWORD*>(static_cast<std::uintptr_t>(i.arg[3]));

    IConnectionPointContainer* container = nullptr;
    IConnectionPoint* point = nullptr;
    HRESULT result = provider->QueryInterface(query_iid, reinterpret_cast<void**>(&container));
    if (SUCCEEDED(result)) {
        result = container->FindConnectionPoint(*outgoing_iid, &point);
        if (SUCCEEDED(result))
            result = point->Advise(sink, cookie);
    }
    if (point)
        point->Release();
    if (container)
        container->Release();
    return static_cast<std::uint32_t>(result);
}
}
