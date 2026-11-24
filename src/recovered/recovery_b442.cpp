#include "recovered/recovery_b442.hpp"
#include "recovered/ini_bulk.hpp"

#include <array>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b442 {
namespace {
void need(bool value,const char* why){if(!value)throw std::domain_error(why);}
std::vector<std::uint8_t> guest_string(const Memory& m,std::uint32_t at) {
    need(at!=0,"B442 null IniByteString object excluded");
    const auto bytes=m.r32(at);
    need(bytes!=0,"B442 null contained string excluded on nonempty route");
    std::vector<std::uint8_t> out;
    for(std::uint32_t i=0;i<0x10000u;++i){
        const auto v=static_cast<std::uint8_t>(m.r8(bytes+i));out.push_back(v);
        if(v==0)return out;
    }
    throw std::domain_error("B442 bounded INI name exceeds 64 KiB");
}
std::uint32_t child_insert(Memory& m,Inputs& child,GuestHeap& heap) {
    return ra2::recovered::recovery_b305::fun_0010da40(m,child,heap);
}
}
std::uint32_t fun_0050cbb0(Memory& m,Inputs& in,GuestHeap& heap) {
    // Root 0x50cbb0's original argument order is [section object, key object,
    // unsigned value, mode]. The two calls at +0x12/+0x20 pass key then section
    // to the accepted 0x75a070 accessor and invert them for 0x10da40's ABI.
    need(in.arg[0]&&in.arg[1],"B442 requires key and section object addresses");
    need(in.arg[3]==1,"B442 selects the original exact %Xh mode only");
    need((in.arg[2]&0x80000000u)!=0,"B442 high-bit route guarantees eight output hex digits");
    const auto key_obj=guest_string(m,in.arg[1]);
    const auto section_obj=guest_string(m,in.arg[0]);
    need(key_obj.size()>1&&section_obj.size()>1,"B442 requires nonempty names");
    // Accepted 0x75a070's positive non-null contract is pointer passthrough.
    // These temporary host views preserve that contract while guest bytes are
    // subsequently copied by the accepted 0x10da40 model.
    ra2::recovered::IniByteString key_view{key_obj.data()};
    ra2::recovered::IniByteString section_view{section_obj.data()};
    [[maybe_unused]] const auto* key_bytes=ra2::recovered::fun_0075a070(key_view);
    [[maybe_unused]] const auto* section_bytes=ra2::recovered::fun_0075a070(section_view);

    // Exact positive %Xh behavior: eight uppercase hexadecimal digits (high-bit input),
    // full-width because bit 31 is set in the bounded input domain.
    constexpr char digits[]="0123456789ABCDEF";
    std::array<std::uint8_t,10> formatted{};
    for(unsigned i=0;i<8;++i)
        formatted[i]=static_cast<std::uint8_t>(digits[(in.arg[2]>>(28u-4u*i))&15u]);
    formatted[8]=static_cast<std::uint8_t>('h');
    const auto scratch=in.cx+0x1000u;
    std::array<std::uint8_t,10> saved{};
    for(unsigned i=0;i<saved.size();++i)saved[i]=static_cast<std::uint8_t>(m.r8(scratch+i));
    for(unsigned i=0;i<formatted.size();++i)m.w8(scratch+i,formatted[i]);

    Inputs nested=in;
    nested.arg[0]=m.r32(in.arg[0]);
    nested.arg[1]=m.r32(in.arg[1]);
    nested.arg[2]=scratch;
    const auto eax=child_insert(m,nested,heap);
    for(unsigned i=0;i<saved.size();++i)m.w8(scratch+i,saved[i]);
    return eax;
}
}


