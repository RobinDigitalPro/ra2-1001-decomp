#include "recovered/recovery_b880.hpp"
#include <string>
#include <algorithm>
namespace ra2::recovered::recovery_b880 {namespace {using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string integer(U bits,char kind){U base=kind=='o'?8:(kind=='x'||kind=='X')?16:10;bool negative=kind=='d'&&(bits&0x80000000u);U value=negative?0u-bits:bits;std::string out;do{U digit=value%base;out+=char(digit<10?'0'+digit:(kind=='X'?'A':'a')+digit-10);value/=base;}while(value);if(negative)out+='-';std::reverse(out.begin(),out.end());return out;}}
U fun_00771e65(Memory&m,const Inputs&i){need(i.arg[0]&&i.arg[1]&&i.arg[2]&&m.r32(0x81776c)==1,"880 initializedbuffered integerroute");U stream=i.arg[0],fmt=i.arg[1],ap=i.arg[2],start=fmt,used=0;need(m.r32(stream+4)>=256&&m.r32(stream+12)==0x42,"880 writablememorystream");std::string output;
 for(;;){need(fmt-start<128,"880 boundedformat");char ch=char(m.r8(fmt++));if(!ch)break;if(ch!='%'){need(std::uint8_t(ch)>=32&&std::uint8_t(ch)<127,"880 ASCIIliteral");output+=ch;continue;}need(fmt-start<128,"880 completeformat");char kind=char(m.r8(fmt++));if(kind=='%'){output+='%';continue;}need(kind=='d'||kind=='u'||kind=='x'||kind=='X'||kind=='o',"880 supportedintegerconversion");need(++used<=8,"880 boundedvarargs");output+=integer(m.r32(ap),kind);ap+=4;}
 need(used&&output.size()<256,"880 positiveboundedoutput");U dest=m.r32(stream);for(U k=0;k<output.size();++k)m.w8(dest+k,std::uint8_t(output[k]));m.w32(stream,dest+U(output.size()));m.w32(stream+4,m.r32(stream+4)-U(output.size()));i.arg[1]=fmt;i.arg[2]=ap;return U(output.size());}
}
