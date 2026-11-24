#include "recovered/recovery_b909.hpp"
#include <stdexcept>
#include <vector>
namespace ra2::recovered::recovery_b909{using U=std::uint32_t;
U fun_0042eb70(Memory&m,const Inputs&i){const U mode=m.r32(0xa255c8);if(mode!=0&&mode!=5)throw std::domain_error("909 local mode only");U target=0;
if(i.arg[1]==0xffffffffu&&i.arg[2]==0xffffffffu){if(!m.r32(i.cx+0x60))throw std::domain_error("909 positive flagged table");for(U k=0;k<24;++k){const U p=m.r32(i.cx+4*k);if(p&&(m.r8(p+0xc)&2)){target=p;break;}}}
else {if(i.arg[1]>7||i.arg[2]>2)throw std::domain_error("909 valid index");target=m.r32(i.cx+4*(3*i.arg[1]+i.arg[2]));}
if(!target||!i.arg[0])throw std::domain_error("909 positive text and selection");std::vector<U>text;for(U k=0;k<=130;++k){U c=m.r16(i.arg[0]+2*k);if(!c)break;text.push_back(c);}if(text.empty()||text.size()>130)throw std::domain_error("909 finite text");for(U k=0;k<128;++k)m.w16(target+0xeu +2*k,k<127&&k<text.size()?text[k]:0);return mode;}
}
