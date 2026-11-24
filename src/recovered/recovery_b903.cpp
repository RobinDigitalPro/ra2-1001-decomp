#include "recovered/recovery_b903.hpp"
#include <vector>
namespace ra2::recovered::recovery_b903{using U=std::uint32_t;
U fun_0071d430(Memory&m,Inputs&i,platform::ordinary_heap::Heap&h){U object=i.arg[1],flags=m.r32(m.r32(object+4)+0x38),field=i.cx+((m.r32(i.cx+8)&flags)?0x14:0x18),format=m.r32(field);if(!format||m.r8(format))throw std::domain_error("903 boundedemptyformat");U temp=h.allocate(1);h.w8(temp,0);i.arg[1]=temp;U dest=i.arg[0],src=m.r32(i.arg[2]);std::vector<U>v;for(U k=0;k<7;++k){U c=m.r16(src+k*2);if(!c)break;v.push_back(c);}if(v.empty()||v.size()>6)throw std::domain_error("903 positiveUnicode");m.w32(dest,0);U copy=h.allocate(2*U(v.size()+1));m.w32(dest,copy);for(U k=0;k<=v.size();++k){U c=k<v.size()?v[k]:0;h.w8(copy+2*k,c&255);h.w8(copy+2*k+1,c>>8);}h.release(temp);i.arg[1]=0;return dest;}
}
