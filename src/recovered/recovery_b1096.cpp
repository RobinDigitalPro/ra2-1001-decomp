#include "recovered/recovery_b1096.hpp"
#include "recovered/recovery_b253.hpp"
#include "recovered/text_bytes.hpp"
#include <string>
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1096{
static void need(bool b){if(!b)throw std::domain_error("1096 positive ordinary3..5paths/initializedactualTLS/coldownedlist");}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&){
 need(i.cx&&m.r32(0x838be0u)==0u&&m.r8(0x838becu)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);std::string input;for(unsigned k=0;k<192u;++k){auto c=m.r8(i.cx+k);if(!c)break;need(c<128u);input+=char(c);}need(!input.empty()&&input.size()<192u);
 const unsigned temporary=h.allocate(unsigned(input.size())+1u);need(temporary&&temporary!=0x838becu);for(unsigned k=0;k<=input.size();++k)h.w8(temporary+k,k<input.size()?static_cast<unsigned char>(input[k]):0u);
 m.w8(0x838becu,';');for(unsigned k=0;k<=input.size();++k)m.w8(0x838bedu+k,k<input.size()?static_cast<unsigned char>(input[k]):0u);
 leaf::Memory temp_span(reinterpret_cast<unsigned char*>(std::uintptr_t(temporary)),temporary,unsigned(input.size())+1u);auto view=m;view.add(temp_span);Inputs token{};token.arg[0]=temporary;token.arg[1]=0x7bd77cu;unsigned address=ra2::recovered::recovery_b253::fun_0076e802(view,token),count=0u,tail=0u;
 while(address){std::string path;for(unsigned k=0;k<128u;++k){auto ch=h.r8(address+k);if(!ch)break;path+=char(ch);}need(!path.empty()&&path.size()<128u);if(path.back()!=':'&&path.back()!='\\')path+='\\';std::array<unsigned char,3>sentinel{static_cast<unsigned char>(m.r8(0x7bd778u)),static_cast<unsigned char>(m.r8(0x7bd779u)),0u};need(fun_0076f150(reinterpret_cast<const unsigned char*>(path.c_str()),sentinel.data(),2u)!=0);
  auto node=h.allocate(8u);need(node);auto text=h.allocate(unsigned(path.size())+1u);need(text);for(unsigned k=0;k<=path.size();++k)h.w8(text+k,k<path.size()?static_cast<unsigned char>(path[k]):0u);h.w32(node+4u,text);h.w32(node,0u);if(!tail)m.w32(0x838be0u,node);else h.w32(tail,node);tail=node;++count;need(count<=5u);
  token.arg[0]=0u;token.arg[1]=0x7bd77cu;address=ra2::recovered::recovery_b253::fun_0076e802(view,token);
 }
 need(count>=3u);need(h.release(temporary)!=0u);return 0u;
}
}
