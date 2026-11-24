#include "recovered/recovery_b1088.hpp"
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1088{
static void need(bool v){if(!v)throw std::domain_error("1088 positive nonempty ASCII currentname/C-locale route");}
static unsigned lower(unsigned c){return c>='A'&&c<='Z'?c+32u:c;}
static unsigned copy(Heap&h,unsigned source,unsigned bytes){const auto dest=h.allocate(bytes);need(dest!=0u);for(unsigned k=0;k<bytes;++k)h.w8(dest+k,h.r8(source+k));return dest;}
static void drop(Heap&h,unsigned p){need(h.release(p)!=0u);}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&,unsigned root){need(root==0x332330u&&m.r32(0xb10530u)==0u);const auto borrowed=m.r32(i.cx);need(borrowed!=0u);std::vector<unsigned>ascii,wide;for(unsigned n=0;n<=12u;++n){const auto c=m.r8(borrowed+n);if(!c)break;need(c<128u&&((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='_'));ascii.push_back(c);}need(!ascii.empty()&&ascii.size()<=12u&&m.r8(borrowed+unsigned(ascii.size()))==0u);for(unsigned n=0;n<=12u;++n){const auto c=m.r8(0xa2793eu+2u*n)|(m.r8(0xa2793fu+2u*n)<<8u);if(!c)break;need(c<128u);wide.push_back(c);}need(wide.size()==ascii.size()&&m.r8(0xa2793eu+2u*unsigned(wide.size()))==0u&&m.r8(0xa2793fu+2u*unsigned(wide.size()))==0u);for(unsigned k=0;k<ascii.size();++k)need(lower(ascii[k])==lower(wide[k]));const auto narrow_bytes=unsigned(ascii.size())+1u,wide_bytes=2u*narrow_bytes;
 const auto original=h.allocate(narrow_bytes);need(original);for(unsigned k=0;k<narrow_bytes;++k)h.w8(original+k,m.r8(borrowed+k));
 const auto tmp=copy(h,original,narrow_bytes);for(unsigned k=0;k<ascii.size();++k)h.w8(tmp+k,lower(h.r8(tmp+k)));const auto normalized=copy(h,tmp,narrow_bytes);drop(h,tmp);
 const auto current=h.allocate(wide_bytes);need(current);for(unsigned k=0;k<wide_bytes;++k)h.w8(current+k,m.r8(0xa2793eu+k));const auto wtmp=copy(h,current,wide_bytes);for(unsigned k=0;k<wide.size();++k){const auto c=lower(h.r8(wtmp+2u*k)|(h.r8(wtmp+2u*k+1u)<<8u));h.w8(wtmp+2u*k,c);h.w8(wtmp+2u*k+1u,c>>8u);}const auto wnormalized=copy(h,wtmp,wide_bytes);drop(h,wtmp);
 const auto converted=h.allocate(wide_bytes);need(converted);for(unsigned k=0;k<narrow_bytes;++k){h.w8(converted+2u*k,h.r8(normalized+k));h.w8(converted+2u*k+1u,0u);}const auto intermediate=copy(h,converted,wide_bytes);drop(h,converted);const auto final=copy(h,intermediate,wide_bytes);drop(h,intermediate);bool equal=true;for(unsigned k=0;k<wide_bytes;++k)equal=equal&&(h.r8(final+k)==h.r8(wnormalized+k));need(equal);
 drop(h,final);drop(h,wnormalized);drop(h,current);drop(h,normalized);drop(h,original);return 1u;
}}
