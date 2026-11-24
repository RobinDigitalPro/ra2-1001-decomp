#include "recovered/recovery_b958.hpp"
#include "platform/ole_storage958.hpp"
namespace ra2::recovered::recovery_b958 {
std::uint32_t fun_00651430(Memory&m,const Inputs&i){namespace ole=ra2::platform::ole_storage958;ole::need(i.arg[0]==ole::Storage::current().address(),"958 actualstorageidentity");std::array<char,127>bytes;for(unsigned k=0;k<bytes.size();++k)bytes[k]=char(m.r8(i.arg[2]+k));bytes[0]=0;auto result=ole::convert_selector(i.arg[1],bytes.data());for(unsigned k=0;k<bytes.size();++k)m.w8(i.arg[2]+k,std::uint8_t(bytes[k]));return result;}
}
