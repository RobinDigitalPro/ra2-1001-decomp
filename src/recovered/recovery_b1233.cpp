#include "recovered/recovery_b1233.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1233 {
unsigned run(Memory&m,Inputs&,Heap&heap,Provider&api,unsigned root){
 if(root!=0x307d90u||m.r8(0x7e3180u)!=1u)throw std::domain_error("1233 finite cold positive versiongetter");m.w8(0x7e3180u,0u);
 std::array<char,260>path{};const unsigned n=api.module_path(m.r32(0xb0dbf8u),path.data(),260u);if(!n||n>=260u)throw std::domain_error("1233 real mainmodule path fits260");unsigned handle=1u;const unsigned bytes=api.version_size(path.data(),handle);if(bytes!=1476u||handle!=0u)throw std::domain_error("1233 actual bound version resource size/handle");
 const unsigned block=heap.allocate(bytes);if(!block)throw std::runtime_error("1233 real owned versionallocation");if(!api.version_info(path.data(),handle,bytes,block))throw std::runtime_error("1233 actual versionInfo success required");const auto translation=api.query(block,"\\VarFileInfo\\Translation");if(!translation.result||translation.length!=4u)throw std::domain_error("1233 actual translation shape");const unsigned language=heap.r8(block+translation.offset)|(heap.r8(block+translation.offset+1u)<<8u),codepage=heap.r8(block+translation.offset+2u)|(heap.r8(block+translation.offset+3u)<<8u);if(language||codepage)throw std::domain_error("1233 neutral source resource translation");
 // Original %04d%04d is decimal. The authentic neutral(0,0) fixture yields the
 // valid 00000000 table spelling without assuming general hex compatibility.
 const auto value=api.query(block,"\\StringFileInfo\\00000000\\ProductVersion");if(!value.result||value.length!=16u)throw std::domain_error("1233 actual fifteen-byte product plusNUL");unsigned length=0;while(length<value.length&&heap.r8(block+value.offset+length))++length;if(length!=15u||heap.r8(block+value.offset+15u))throw std::domain_error("1233 complete bounded ProductVersion");for(unsigned k=0;k<=length;++k)m.w8(0x7e2f80u+k,heap.r8(block+value.offset+k));if(!heap.release(block))throw std::runtime_error("1233 actual target free success");return 0x7e2f80u;
}
}
