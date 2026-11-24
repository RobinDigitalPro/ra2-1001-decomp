#include "recovered/recovery_b991.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b991 {
std::uint32_t fun_0077b220(Memory&m,const Inputs&i,Boundary&api,Observation&o){
 if(m.r32(0xb106fcu)!=1u||m.r32(0xb10530u)!=0u)throw std::domain_error("B991 positive abbreviated-language/C-locale route");
 std::uint32_t lcid=0;unsigned digits=0;
 for(auto p=i.arg[0];;p++){auto c=m.r8(p);if(!c)break;unsigned d;if(c>='0'&&c<='9')d=c-'0';else if(c>='a'&&c<='f')d=c-'a'+10;else if(c>='A'&&c<='F')d=c-'A'+10;else throw std::domain_error("B991 hex locale string");if(++digits>8u)throw std::domain_error("B991 bounded locale string");lcid=(lcid<<4u)+d;}
 if(!digits)throw std::domain_error("B991 nonempty locale string");
 o.pointer=reinterpret_cast<std::uintptr_t>(o.bytes.data());
 const int count=api.get(lcid,3u,reinterpret_cast<char*>(o.bytes.data()),120);
 if(count<=0||count>120||o.bytes[count-1]!=0)throw std::domain_error("B991 actual positive GetLocaleInfoA");
 auto fold=[](unsigned c){return c>='A'&&c<='Z'?c+32u:c;};
 for(unsigned k=0;;++k){if(k>=120u)throw std::domain_error("B991 bounded match");const unsigned a=m.r8(m.r32(0xb10700u)+k),b=o.bytes[k];if(fold(a)!=fold(b))throw std::domain_error("B991 positive case-insensitive exact match");if(!a)break;}
 m.w32(0xb10708u,m.r32(0xb10708u)|4u);m.w32(0xb1070cu,lcid);m.w32(0xb106f0u,lcid);return 0u;
}
}
