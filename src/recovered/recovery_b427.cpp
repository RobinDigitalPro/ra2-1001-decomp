#include "recovery_b427.hpp"
#include "recovered/leaf_b21_c.hpp"
#include "recovered/leaf_text_rng.hpp"
#include "recovered/text_bytes.hpp"
#include <array>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b427 {
namespace {
void require(bool ok, const char* what) { if (!ok) throw std::domain_error(what); }
std::uint32_t length_a(Memory& m, std::uint32_t p, std::uint32_t bound) {
    require(bound<=0x10000u,"374ea6 finite direct route bounds byte count to 64K");
    std::vector<std::uint8_t> bytes(bound+1u);
    for(std::uint32_t k=0;k<=bound;++k) bytes[k]=static_cast<std::uint8_t>(m.r8(p+k));
    leaf::Memory local(bytes.data(),p,static_cast<std::uint32_t>(bytes.size()));
    leaf::Inputs in{}; in.arg[0]=p; in.arg[1]=bound;
    return leaf::fun_00774ea6(local,in);
}
std::uint32_t length_w(Memory& m, std::uint32_t p, std::uint32_t bound) {
    require(bound<=0x8000u,"37e917 finite direct route bounds code-unit count to 32K");
    std::vector<std::uint8_t> bytes(2u*(bound+1u));
    for(std::uint32_t k=0;k<=bound;++k) {
        const auto w=m.r16(p+2u*k); bytes[2u*k]=std::uint8_t(w);bytes[2u*k+1u]=std::uint8_t(w>>8);
    }
    leaf::Memory local(bytes.data(),p,static_cast<std::uint32_t>(bytes.size()));
    leaf::Inputs in{}; in.arg[0]=p; in.arg[1]=bound;
    return leaf::fun_0077e917(local,in);
}
}

void fun_0078101b(Memory& m, State& s, const Ops& o) {
    require(o.locale_info_w && m.r32(0xb10824u)==1u,"38101b requires cached W mode and real GetLocaleInfoW forwarder");
    s.ax=o.locale_info_w(o.context,s.arg[0],s.arg[1],s.arg[2],s.arg[3]);
}
void fun_0078112e(Memory& m, State& s, const Ops& o) {
    require(o.locale_info_a && m.r32(0xb10828u)==2u,"38112e requires cached A mode and real GetLocaleInfoA forwarder");
    s.ax=o.locale_info_a(o.context,s.arg[0],s.arg[1],s.arg[2],s.arg[3]);
}
void fun_0077d5af(Memory& m, State& s, const Ops& o) {
    require(o.string_type_a && m.r32(0xb10714u)==2u,"37d5af requires cached A mode and real GetStringTypeA forwarder");
    const auto lcid=s.arg[5] ? s.arg[5] : m.r32(0xb10530u);
    require(lcid!=0,"37d5af finite direct route requires nonzero effective LCID");
    s.ax=o.string_type_a(o.context,lcid,s.arg[0],s.arg[1],s.arg[2],s.arg[3]);
}
void fun_0077e549(Memory& m, State& s, const Ops& o) {
    require(o.string_type_w && m.r32(0xb107d8u)==1u,"37e549 requires cached W mode and real GetStringTypeW forwarder");
    s.ax=o.string_type_w(o.context,s.arg[0],s.arg[1],s.arg[2],s.arg[3]);
}
void fun_00774c82(Memory& m, State& s, const Ops& o) {
    require(o.map_a && m.r32(0xb1055cu)==2u,"374c82 requires cached A mode and real LCMapStringA forwarder");
    if(static_cast<std::int32_t>(s.arg[3])>0) s.arg[3]=length_a(m,s.arg[2],s.arg[3]);
    s.ax=o.map_a(o.context,s.arg[0],s.arg[1],s.arg[2],s.arg[3],s.arg[4],s.arg[5]);
}
void fun_0077e70e(Memory& m, State& s, const Ops& o) {
    require(o.map_w && m.r32(0xb107dcu)==1u,"37e70e requires cached W mode and real LCMapStringW forwarder");
    if(static_cast<std::int32_t>(s.arg[3])>0) s.arg[3]=length_w(m,s.arg[2],s.arg[3]);
    s.ax=o.map_w(o.context,s.arg[0],s.arg[1],s.arg[2],s.arg[3],s.arg[4],s.arg[5]);
}
void fun_0072ba70(Memory& m, State& s, const Ops& o) {
    require(o.version_a,"32ba70 requires real GetVersionExA forwarder");
    Ops::VersionA v{}; v.size=0x94u;
    require(o.version_a(o.context,v),"GetVersionExA failed on the current host");
    const auto self=s.cx;
    m.w32(self+0, v.major); m.w32(self+4, v.minor); m.w32(self+8, v.build);
    m.w8(self+0x8c,static_cast<std::uint8_t>(v.platform==1u));
    m.w8(self+0x8d,static_cast<std::uint8_t>(v.platform==2u));
    // Original calls accepted 0x36dd10 with count 0x7f, then explicitly zeros
    // byte self+0x8b. The helper's bounded copy/zero-pad semantics are composed
    // here without asserting a source-level class or constructor signature.
    std::array<std::uint8_t,0x7f> copied{};
    (void)ra2::recovered::fun_0076dd10(copied.data(),v.csd.data(),0x7fu);
    for(std::uint32_t k=0;k<copied.size();++k) m.w8(self+0x0cu+k,copied[k]);
    m.w8(self+0x8bu,0);
    s.ax=self;
}
}
