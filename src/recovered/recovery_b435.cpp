#include "recovered/recovery_b435.hpp"
#include <stdexcept>
namespace ra2::recovered::entry435 {
namespace { void require(bool ok,const char* s){if(!ok)throw std::domain_error(s);} }
std::uint32_t fun_0076f545(Memory&m,State&s,const Ops&o){
 // Bounded useful path: [EBP+8] is nonnull; original loads [arg0], then
 // reads owner from that pointer minus four and probes the DWORD stored at
 // owner+0xC for eight bytes.
 const std::uint32_t p=s.arg[0];require(p!=0,"B435 requires nonnull first caller word");
 const std::uint32_t q=m.r32(p);require(q>=4,"B435 pointer-to-pointer target must be readable");
 const std::uint32_t owner=m.r32(q-4);require(owner!=0,"B435 owner pointer must be nonnull");
 const std::uint32_t field=owner+0x0cu;require(field>=owner,"B435 field pointer overflow");const std::uint32_t payload=m.r32(field);require(payload!=0,"B435 payload pointer must be nonnull");
 require(o.is_bad_read_ptr!=nullptr,"B435 requires actual IsBadReadPtr forwarder");
 const std::uint32_t bad=o.is_bad_read_ptr(o.context,payload,8);
 require(bad==0,"B435 bounded positive route requires readable 8-byte payload");
 s.ax=payload;return s.ax;
}
}
