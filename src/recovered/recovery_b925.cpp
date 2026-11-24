#include "recovered/recovery_b925.hpp"
#include "platform/observed_registry925.hpp"
#include <string>
namespace ra2::recovered::recovery_b925{using U=unsigned;using platform::registry925::Observer;
static std::string text(Memory&m,U p){std::string s;for(U k=0;k<128;++k){auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("925 boundedkey");}
static U query(Memory&m,U path,U name){auto a=text(m,path),b=text(m,name);HKEY key{};DWORD value=0,type=0,size=4;if(Observer::open(HKEY_LOCAL_MACHINE,a.c_str(),0,0xf003f,&key)!=0)throw std::domain_error("925 positiveopen");if(Observer::query(key,b.c_str(),nullptr,&type,reinterpret_cast<BYTE*>(&value),&size)!=0||type!=REG_DWORD||size!=4)throw std::domain_error("925 positiveDWORDquery");if(Observer::close(key)!=0)throw std::domain_error("925 successfulclose");return value;}
U fun_004fe700(Memory&m,const Inputs&i){m.w8(i.cx+4,0);U value=query(m,0x7c5f24,0x7c5f1c);m.w8(i.cx+4,1);m.w32(i.cx,value);return 1;}
U fun_00680a20(Memory&m,const Inputs&i){m.w32(i.cx,m.r32(i.cx)&0xfffffff8u);U value=query(m,0x7ddcb0,0x7ddca0);m.w32(i.cx,(m.r32(i.cx)&0xfff88087u)|((0x1010u|(value&1))<<3));return 0;}
}
