#include "recovered/recovery_b912.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::recovery_b912{using U=std::uint32_t;
namespace{void need(bool b,const char*s){if(!b)throw std::domain_error(s);}U digit(U c){if(c>='0'&&c<='9')return c-'0';if(c>='a'&&c<='f')return c-'a'+10;if(c>='A'&&c<='F')return c-'A'+10;throw std::domain_error("912 hex digit");}
void decode(Memory&m,U src,U dst){need(src,"912 nonnull label");std::string out;for(U k=0;k<40;){U c=m.r8(src+k++);if(!c)break;if(c=='='){U h=m.r8(src+k++),l=m.r8(src+k++);c=16*digit(h)+digit(l);}need(c>0&&c<128,"912 nonzero ASCII decodedbyte");out.push_back(char(c));}need(!out.empty()&&out.size()<=12,"912 bounded label");for(U k=0;k<=out.size();++k){U c=k<out.size()?std::uint8_t(out[k]):0;m.w8(0x8398a0+k,c);m.w8(dst+k,c);}}
}
U fun_0048f5b0(Memory&m,Inputs&i,ra2::platform::ordinary_heap::Heap&h){const U o=i.cx,index=i.arg[1],source=i.arg[0];need(index<m.r32(source+0x54)&&index<3&&i.arg[6]==1&&m.r32(o+0x3c)==0&&i.arg[3]&&!(i.arg[5]&0xff00)&&m.r32(i.arg[3])==0,"912 bounded selected record andborrowedindices");const U rec=m.r32(source+0x50)+68*index;need(m.r8(rec+8)==1,"912 source count1");i.arg[1]=rec;m.w32(o+0x38,0xffffffff);for(U off=0x48;off<=0x68;off+=4)m.w32(o+off,0);m.w32(o+0x44,index);m.w8(o+0x6c,1);m.w32(o+0x3c,0);m.w32(o+0x40,0);U table=h.allocate(4),child=h.allocate(260);need(table&&child,"912 allocations success");m.w32(o+0x3c,table);h.w32(table,child);U input=m.r32(rec+0xc);bool ended=false;for(U k=0;k<259;++k){U c=ended?0:m.r8(input+k);ended|=c==0;h.w8(child+k,c);}m.w32(o+0x40,1);m.w32(o+0x38,0);decode(m,i.arg[9],o);decode(m,i.arg[8],o+0x1c);return (i.arg[3]&0xffffff00u)|1;}
}
