#include "recovered/recovery_b990.hpp"
#include "platform/observed_cp990.hpp"
#include "platform/ole_property990.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::recovery_b990 {
namespace ole = ra2::platform::ole_property990;

std::uint32_t fun_006515d0(Memory& m, const Inputs& input) {
    auto& i = const_cast<Inputs&>(input); // Original writes caller stack arg2 through IPropertySetStorage::Open.
    const std::uint32_t output = i.arg[2];
    m.w8(output, 0);
    i.arg[2] = 0;

    auto& owner = ole::Storage::current();
    ole::need(i.arg[0] == owner.address(), "990 genuine IPropertySetStorage identity");
    IPropertyStorage* property = nullptr;
    const HRESULT opened = owner.get()->Open(ole::fmtid, 0x12u, &property);
    ole::need(opened == S_OK && property, "990 positive existing-FMTID Open");
    ra2::platform::cp990::model_property()=ole::pointer(property);
    i.arg[2] = ole::pointer(property); // Deliberately preserve the original's stale released pointer word.

    PROPSPEC spec{};
    spec.ulKind = PRSPEC_PROPID;
    spec.propid = i.arg[1];
    PROPVARIANT value{};
    const HRESULT read = property->ReadMultiple(1u, &spec, &value);
    ole::need(read == S_OK && value.vt == VT_LPWSTR && value.pwszVal,
              "990 positive ReadMultiple VT_LPWSTR route");
    ra2::platform::cp990::record_model_read_pointer(value.pwszVal);

    // Memory exposes numeric guest reads/writes, not a host_view. Keep a bounded
    // host buffer for the real API call, then project exactly its returned bytes.
    std::array<char, 128> converted{};
    const int count = ra2::platform::cp990::convert(CP_ACP, 0u, value.pwszVal, -1,
                                                     converted.data(), int(converted.size()), nullptr, nullptr);
    ole::need(count >= 1 && count <= int(converted.size()), "990 actual complete ACP conversion");
    for (int k = 0; k < count; ++k) m.w8(output + std::uint32_t(k), std::uint8_t(converted[std::size_t(k)]));

    // Original bytes release IPropertyStorage but do not call PropVariantClear.
    property->Release();
    return std::uint32_t(read);
}
}
