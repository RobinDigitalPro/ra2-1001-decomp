#include "recovered/recovery_b895.hpp"
#include <string>
#include <array>
namespace ra2::recovered::recovery_b895 {using U=std::uint32_t;
U fun_005d1b70(Memory&m,const Inputs&i,platform::ordinary_heap::Heap&h,U entry,U thread){U selector=m.r16(i.cx+0x3e);if(selector==0xffff||selector<0x4000){U v=selector==0xffff?0x8813:selector+0x4000;m.w16(0xa285ea,((v<<8)|(v>>8))&0xffff);}std::string text;for(U k=0;k<16;++k){U c=m.r8(i.cx+0x4c+k);if(!c)break;text+=char(c);}if(text.empty()||text.size()>12||text.back()!='.')throw std::domain_error("895fourhexcomponents");U a=h.allocate(U(text.size()+1));if(!a)throw std::domain_error("895successheap");for(U k=0;k<=text.size();++k)h.w8(a+k,k<text.size()?std::uint8_t(text[k]):0);std::array<U,4>bytes{};U pos=0;
for(U row=0;row<4;++row){U value=0,digits=0;while(pos<text.size()&&text[pos]!='.'){U c=std::uint8_t(text[pos++]),v;if(c>='0'&&c<='9')v=c-'0';else if(c>='A'&&c<='F')v=c-'A'+10;else if(c>='a'&&c<='f')v=c-'a'+10;else throw std::domain_error("895hexgrammar");if(++digits>2)throw std::domain_error("895twohexmax");value=value*16+v;}if(!digits||pos>=text.size())throw std::domain_error("895completedot");h.w8(a+pos,0);++pos;m.w32(thread+24,a+pos);bytes[row]=value;}
if(pos!=text.size())throw std::domain_error("895exactlyfour");m.w32(thread+24,a+pos);m.w32(0xa2792c,1);for(U k=0;k<4;++k)m.w8(0xa27930+k,bytes[k]);for(U k=4;k<10;++k)m.w8(0xa27930+k,255);return ((entry-12)&0xffff0000)|0xffff;
}}
