#include "recovered/recovery_b898.hpp"
#include <string>
#include <algorithm>
namespace ra2::recovered::recovery_b898 {namespace {using U=std::uint32_t;
std::string text(Memory&m,U p){if(!p)throw std::domain_error("898nonnullstring");std::string s;for(U k=0;k<128;++k){U c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("898shortstring");}
void comments(Memory&m,U p,std::string&out){for(U n=0;p;++n){if(n>=4)throw std::domain_error("898finitecomments");if(U str=m.r32(p))out+=text(m,str)+"\r\n";p=m.r32(p+4);}}
void spaces(std::string&out,std::int32_t n){if(n>0)out.append(std::min(n,256),' ');}
}
U fun_0050ba70(Memory&m,const Inputs&i){const U pipe=i.arg[0];if(m.r32(pipe)!=0x789a08||m.r32(0x789a18)!=0x75f070||m.r32(0x789a10)!=0x46c780||m.r32(0x789a0c)!=0x6066f0||m.r32(pipe+4))throw std::domain_error("898authenticborrowedpipe");std::string out;U section=m.r32(i.cx+12);
for(U sn=0;section&&m.r32(section+4)&&m.r32(section+8);++sn){if(sn>=2)throw std::domain_error("898twosections");U comment=m.r32(section+64);if(!out.empty()&&!comment)out+="\r\n";comments(m,comment,out);out+="["+text(m,m.r32(section+12))+"]\r\n";U node=m.r32(section+24);for(U kn=0;node&&m.r32(node+4)&&m.r32(node+8);++kn){if(kn>=3)throw std::domain_error("898threekeys");comments(m,m.r32(node+20),out);auto key=text(m,m.r32(node+12)),value=text(m,m.r32(node+16));auto before=std::min(global_b26::s32(m.r32(node+28))-std::int32_t(key.size()),256);U padded=before>0?U(before):0;out+=key;spaces(out,before);out+='=';auto after=global_b26::s32(m.r32(node+32))-std::int32_t(padded+key.size())-1;after=std::min(after,256);spaces(out,after);if(after>0)padded+=U(after);out+=value;if(U str=m.r32(node+24)){spaces(out,global_b26::s32(m.r32(node+36))-std::int32_t(padded+value.size()+key.size())-1);out+=';';out+=text(m,str);}out+="\r\n";node=m.r32(node+4);}section=m.r32(section+4);}
comments(m,m.r32(i.cx+52),out);U cursor=m.r32(pipe+24),capacity=m.r32(pipe+16),buffer=m.r32(pipe+12);if(!buffer||out.empty()||cursor>7||out.size()>capacity-cursor)throw std::domain_error("898positivecompletebuffer");for(U k=0;k<out.size();++k)m.w8(buffer+cursor+k,std::uint8_t(out[k]));m.w32(pipe+24,cursor+U(out.size()));return U(out.size());}
}
