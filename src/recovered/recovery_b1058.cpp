#include "recovered/recovery_b1058.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1058 {namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned fold(unsigned x){return x>='A'&&x<='Z'?x+32u:x;}
std::string text(Memory&m,unsigned a){std::string s;for(unsigned k=0;k<64u;++k){const unsigned ch=m.r8(a+k);if(!ch)return s;need(ch<128u,"1058 original C-locale ASCII filename boundary");s+=char(ch);}throw std::domain_error("1058 terminated bounded original filename");}
void put(Observation&o,unsigned a,unsigned v){for(unsigned k=0;k<4u;++k)o.file.at(a+k)=static_cast<unsigned char>(v>>(8u*k));}
void progression(Memory&m,const std::string&s,Observation&o){for(unsigned table:{0x7d2460u,0x7d23c0u}){unsigned index=0xffffffffu;for(unsigned j=0;j<12u;++j){const auto key=text(m,m.r32(table+j*12u));++o.table_compares;bool same=key.size()==s.size();for(unsigned k=0;same&&k<s.size();++k)same=fold(unsigned(key[k]))==fold(unsigned(s[k]));if(same){index=j;break;}}const unsigned dst=table==0x7d2460u?0xa28798u:0xa2879cu;need(m.r32(dst)==0xffffffffu,"1058 actual original fresh progression max reset");if(index!=0xffffffffu){m.w32(dst,index);++o.index_updates;}}}
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,Observation&o){need(m.r32(0xa588e0u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0xb10adcu)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1058 original C-locale physical CCFile/ordinaryheap closure");need(i.dx!=0u,"1058 original caller provides actual filename output");
 auto s=text(m,i.cx);const auto dot=s.find('.');if(dot!=std::string::npos)s.resize(dot);need(s.size()==8u,"1058 genuine original twelve-entry campaign filename stem");progression(m,s,o);need(o.index_updates==1u,"1058 positive actual literal-table filename match");s+=".BIK";for(unsigned k=0;k<=s.size();++k)o.candidate[k]=k<s.size()?s[k]:0;
 // Actual468B70/46FD50/630110: owned filename clone, initialized CCFile.
 const unsigned name=h.allocate(unsigned(s.size()+1u));need(name!=0u,"1058 actual positive filename allocation");o.cloned=name;for(unsigned k=0;k<=s.size();++k)h.w8(name+k,k<s.size()?unsigned(s[k]):0u);
 put(o,0u,0x7856a0u);put(o,4u,1u);put(o,0xcu,0xffffffffu);put(o,0x10u,0xffffffffu);put(o,0x14u,name);o.file[0x1cu]=1u;put(o,0x3cu,0xffffffffu);put(o,0x40u,0xffffffffu);
 // Genuine468DC0 checks archiveName through5928A0. Even with empty archive
 // list that helper uppercases the OWNED filename before its unsuccessful
 // archive search; caller's local candidate retains its source stem casing.
 for(unsigned k=0;k<s.size();++k){const unsigned x=h.r8(name+k);if(x>='a'&&x<='z')h.w8(name+k,x-32u);}
 HANDLE file=a.create_file_a(reinterpret_cast<const char*>(std::uintptr_t(name)),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(file!=INVALID_HANDLE_VALUE,"1058 genuine present first BIK physical variant");put(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(file)));need(a.close_handle(file)!=FALSE,"1058 genuine original probe handle close");put(o,0x10u,0xffffffffu);
 // Actual buffer is unowned/null; raw file destructor releases its owned name.
 o.final_free=h.release(name);need(o.final_free!=0u,"1058 actual owned filename lifetime");put(o,0u,0x793c3cu);put(o,0x14u,0u);o.file[0x1cu]=0u;
 for(unsigned k=0;k<=s.size();++k)m.w8(i.dx+k,k<s.size()?unsigned(s[k]):0u);
 //59EAC5 loads strlen+NUL;59EADA writes onlyAL. Selected names length12.
 return (unsigned(s.size()+1u)&0xffffff00u)|1u;
}
}
