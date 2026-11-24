#include "recovered/recovery_b902.hpp"
#include <vector>
#include <string>
namespace ra2::recovered::recovery_b902 {using U=std::uint32_t;
U fun_00779afe(Memory&m,const Inputs&,platform::ordinary_heap::Heap&h){if(!m.r32(0xb10e30))throw std::domain_error("902 initializedCRTgate");U source=m.r32(0xb104b8),pos=0;std::vector<std::string>rows;while(h.r8(source+pos)){std::string s;for(;;){if(pos>=16)throw std::domain_error("902 boundedmultisz");U c=h.r8(source+pos++);if(!c)break;s+=char(c);}if(s[0]!='=')rows.push_back(s);}if(rows.empty()||rows.size()>3)throw std::domain_error("902 positiveentrycount");U table=h.allocate(4*U(rows.size()+1));m.w32(0xb10474,table);for(U k=0;k<rows.size();++k){U copy=h.allocate(U(rows[k].size()+1));h.w32(table+4*k,copy);for(U j=0;j<rows[k].size();++j)h.w8(copy+j,std::uint8_t(rows[k][j]));h.w8(copy+U(rows[k].size()),0);}U result=h.release(source);m.w32(0xb104b8,0);h.w32(table+4*U(rows.size()),0);m.w32(0xb10e2c,1);return result;}
}
