#include "recovered/recovery_b943.hpp"
#include <string>
#include <vector>
namespace ra2::recovered::recovery_b943 {
U fun_00779bb7(Memory&m,const Inputs&,platform::ordinary_heap::Heap&h,ModulePath&api){
 if(!m.r32(0xb10e30))throw std::domain_error("943 initialized charset");
 std::array<std::uint8_t,260> path;for(U k=0;k<260;++k)path[k]=std::uint8_t(m.r8(0xb105a4+k));
 U len=api.current(path);if(!len||len>=260)throw std::domain_error("943 successful module path");for(U k=0;k<260;++k)m.w8(0xb105a4+k,path[k]);m.w32(0xb10484,0xb105a4);
 U pos=m.r32(0xb10e28),start=pos;auto next=[&](){U c=m.r8(pos++);if(pos-start>240||c>=128||(m.r8(0xb10be1+c)&4))throw std::domain_error("943 ASCII extent");return c;};
 if(next()!=34)throw std::domain_error("943 quoted program");std::vector<std::string> rows(1);for(;;){U c=next();if(c==34)break;if(!c||c==92)throw std::domain_error("943 program grammar");rows[0]+=char(c);}if(rows[0].empty())throw std::domain_error("943 positive program");
 while(m.r8(pos)){while(m.r8(pos)==32||m.r8(pos)==9)++pos;if(!m.r8(pos))break;std::string s;while(m.r8(pos)&&m.r8(pos)!=32&&m.r8(pos)!=9){U c=next();if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')))throw std::domain_error("943 unquoted grammar");s+=char(c);}rows.push_back(s);}
 if(rows.size()<2||rows.size()>4)throw std::domain_error("943 argument count");U chars=0;for(auto&s:rows)chars+=U(s.size()+1);U count=U(rows.size()),table=h.allocate((count+1)*4+chars),dst=table+(count+1)*4;
 for(U k=0;k<count;++k){h.w32(table+k*4,dst);for(auto c:rows[k])h.w8(dst++,std::uint8_t(c));h.w8(dst++,0);}h.w32(table+count*4,0);m.w32(0xb1046c,table);m.w32(0xb10468,count);return count;
}}
