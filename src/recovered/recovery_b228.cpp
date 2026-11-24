#include "recovery_b228.hpp"
#include "platform/console228_win32.hpp"
#include <array>
namespace ra2::recovered::recovery_b228 {
std::uint32_t fun_00781e84(Memory&m,const Inputs&){using ra2::platform::console228::Console;using ra2::platform::console228::need;
 need(m.r32(0x818dd8)==0xffffffff,"228 uncached predicate");const auto handle=reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(0x818de0)));DWORD count=0;
 if(!Console::count(handle,&count)||count==0)return 0;need(count<=8,"228 finite record bound");std::array<INPUT_RECORD,8> records{};DWORD read=0;
 if(!Console::peek(handle,records.data(),count,&read)||read==0||read>count)return 0;
 for(unsigned n=0;n<read;++n){const auto&r=records[n];if(r.EventType==KEY_EVENT&&r.Event.KeyEvent.bKeyDown){need(r.Event.KeyEvent.uChar.AsciiChar!=0,"228 extended-key route excluded");return 1;}}
 return 0;}
}
