#include "recovery_b1052.hpp"
#include <stdexcept>
namespace ra2::recovered::b1052 {namespace {
using U=std::uint32_t;using Q=std::uint64_t;using State=ra2::platform::x87::State;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
Q argument(const Inputs&i,U k){return Q(i.arg[k])|(Q(i.arg[k+1u])<<32u);}
U exponent(Q x){return U((x>>52u)&2047u);}
void entry(const Inputs&i,Q x){need(exponent(x)>0u&&exponent(x)<2047u&&i.fp.image.word(8)==0xffffu&&(i.fp.image.word(4)&0x7fffu)==0u,"1052 finite normal and empty clear x87");}
int compare(State&fp,Q a,Q b){fp.load64(a);fp.compare_pop64(b);const auto s=fp.status();return(s&0x4000u)?0:(s&0x100u)?-1:1;}
void replace_exponent(State&fp,Q x,int e){fp.load64(x);auto y=fp.pop64();y=(y&0x800fffffffffffffull)|(Q(U(e+1022)&2047u)<<52u);fp.load64(y);}
U finish(State&fp,unsigned saved,Q output){const auto old=fp.waiting_control();fp.load_control(std::uint16_t(saved));fp.load64(output);return U(std::int32_t(std::int16_t(old)));}
}
U fun_0077cebe(Memory&,const Inputs&i){const auto x=argument(i,0u),y=argument(i,2u);entry(i,x);need(exponent(y)>0u&&exponent(y)<2047u&&x!=y,"1052 distinct normal destination");auto&fp=i.fp;const auto saved=fp.waiting_control();fp.load_control(0x133fu);
 need(compare(fp,y,x)!=0,"1052 actual non-equal branch");need(compare(fp,x,0u)!=0,"1052 nonzero source");bool down=false,up=false;
 if(compare(fp,x,0u)>0&&compare(fp,y,x)<0)down=true;
 else if(compare(fp,x,0u)<0&&compare(fp,y,x)>0)down=true;
 if(!down){if(compare(fp,x,0u)>0&&compare(fp,y,x)>0)up=true;else if(compare(fp,x,0u)<0&&compare(fp,y,x)<0)up=true;}
 need(down||up,"1052 selected adjacent-value branch");const auto output=down?x-1u:x+1u;need(exponent(output)>0u&&exponent(output)<2047u,"1052 adjacent normal finite result");return finish(fp,saved,output);
}
U fun_00780842(Memory&,const Inputs&i){const auto x=argument(i,0u);entry(i,x);const int shift=std::int32_t(i.arg[2]),out=int(exponent(x))+shift;need(shift!=0&&shift>=-128&&shift<=128&&out>=1&&out<=2046,"1052 nonzero scaling with normal finite result");auto&fp=i.fp;const auto saved=fp.waiting_control();fp.load_control(0x133fu);need(compare(fp,x,0u)!=0,"1052 nonzero input");
 fp.load64(x);const auto a=fp.pop64();compare(fp,a,0u);fp.load64(a);const auto copied=fp.pop64();replace_exponent(fp,copied,0);const auto local=fp.pop64();fp.load64(local);
 const auto mantissa=fp.pop64();fp.load64(mantissa);const auto b=fp.pop64();replace_exponent(fp,b,out-1022);const auto output=fp.pop64();return finish(fp,saved,output);
}
}
