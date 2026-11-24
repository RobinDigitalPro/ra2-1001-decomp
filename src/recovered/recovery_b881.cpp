#include "recovered/recovery_b881.hpp"
#include <array>
#include <string>
namespace ra2::recovered::recovery_b881 {using U=std::uint32_t;namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
U fun_007752cd(Memory&m,const Inputs&i){U stream=i.arg[0],fmt=i.arg[1],ap=i.arg[2];need(stream&&fmt&&ap&&m.r32(0x81776c)==1&&m.r32(stream+12)==0x49,"881 originalmemorystream");const char grammar[]="%d,%d,%d,%s";for(U k=0;k<sizeof(grammar);++k)need(m.r8(fmt+k)==U(grammar[k]),"881 explicitfinitegrammar");U start=m.r32(stream),at=start;
 for(U k=0;k<3;++k){bool minus=m.r8(at)=='-';if(minus)++at;std::uint64_t value=0;U digits=0;while(m.r8(at)>='0'&&m.r8(at)<='9'){value=value*10+m.r8(at++)-'0';need(++digits<=10&&value<=(minus?2147483648ull:2147483647ull),"881 signed32decimal");}need(digits&&m.r8(at++)==',',"881 completedecimalcomma");m.w32(m.r32(ap+4*k),minus?0u-U(value):U(value));}
 U dest=m.r32(ap+12),len=0;while(m.r8(at)>='A'&&m.r8(at)<='Z'){need(len<12,"881 boundedASCII token");m.w8(dest+len++,m.r8(at++));}need(len&&m.r8(at)==' '&&at-start<m.r32(stream+4),"881 retainedspacedelimiter");m.w8(dest+len,0);m.w32(stream,at);m.w32(stream+4,m.r32(stream+4)-(at-start));i.arg[1]=fmt+sizeof(grammar)-1;i.arg[2]=ap+16;return 4;}
}
