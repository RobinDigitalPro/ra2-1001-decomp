#include "recovered/map_b79.hpp"
#include <cstdint>

namespace ra2::recovered::map_b79 {
using global_b26::s32;using global_b26::sx16;using global_b26::sx8;using global_b26::sar;
namespace {
using global_b26::imul_high;
std::uint32_t pair(std::uint32_t x,std::uint32_t y){return (x&65535u)|((y&65535u)<<16);}
std::uint32_t add_pair(std::uint32_t a,std::uint32_t b){return pair(a+b,(a>>16)+(b>>16));}
// Scalar adaptations of 545500, 545490, 42add0 and 47cbc0. Original
// stack-local coordinate outputs remain C++ locals, never guest scratch writes.
std::uint32_t lookup(Memory&m,std::uint32_t map,std::uint32_t xy){
 const auto k=(sx16(xy>>16)<<9)+sx16(xy);if(s32(k)>=0&&k<0x40000u){auto p=m.r32(m.r32(map+0x138u)+k*4u);if(p)return p;}
 m.w32(0xa57634u,xy);return 0xa57610u;
}
std::uint32_t fixed_lookup(Memory&m,std::uint32_t p){const auto x=m.r32(p),y=m.r32(p+4u);const auto xx=sar(x+(s32(x)<0?255u:0u),8),yy=sar(y+(s32(y)<0?255u:0u),8),k=(yy<<9)+xx;
 if(s32(k)>=0&&s32(k)<s32(m.r32(0x81a95cu))){const auto q=m.r32(m.r32(0x81a958u)+k*4u);if(q)return q;}
 m.w32(0xa57634u,pair(xx,yy));return 0xa57610u;}
std::uint32_t neighbor(Memory&m,std::uint32_t xy,unsigned direction){return add_pair(xy,m.r32(0x839da0u+(direction&7u)*4u));}
bool status(Memory&m,std::uint32_t p){const auto n=sx16(m.r16(p+0x116u));return s32(n)>=0&&s32(n)<s32(m.r32(0x84e508u))&&m.r32(p+0xecu)==10u;}
bool inside(Memory&m,std::uint32_t p,std::uint32_t xy){const auto x=sx16(xy),y=sx16(xy>>16),d=m.r32(p+0xf0u);return s32(x+y)>s32(d)&&s32(x-y)<s32(d)&&s32(y-x)<s32(d)&&s32(x+y)<=s32(d+m.r32(p+0xf4u)*2u);}
bool diamond(Memory&m,std::uint32_t x,std::uint32_t y){x=sx16(x);y=sx16(y);const auto d=m.r32(0xa58634u);return s32(x+y)>s32(d)&&s32(x-y)<s32(d)&&s32(y-x)<s32(d)&&s32(x+y)<=s32(m.r32(0xa58638u));}
bool range(std::uint32_t v,std::uint32_t start,std::uint32_t length){return s32(v)>=s32(start)&&s32(v)<s32(start+length);}
// Numeric x87 composition of the accepted original 4ba080 lookup approximation.
void root(Memory&m,ra2::platform::x87::State&f,std::uint64_t value){
 f.load64(value);f.compare32(m.r32(0x785738u));auto sw=f.status();
 if(sw&0x4000u){f.pop_st0();f.load32(m.r32(0x785738u));return;}
 f.compare32(m.r32(0x785738u));sw=f.status();if(sw&0x4100u)f.multiply64(floating_b61::read64(m,0x788578u));
 const auto bits=f.pop32();auto exponent=(bits>>23)-127u;auto mantissa=bits&0x7fffffu;if(exponent&1u)mantissa|=0x800000u;
 exponent=sx16(sar(sx16(exponent),1)); // SAR AX retains a signed short result.
 const auto result=m.r32(0x80013cu+(mantissa>>10)*4u)+((exponent+127u)<<23);f.load32(result);
}
void add_integer(ra2::platform::x87::State&f,std::uint32_t value){
 f.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfiaddl %[v]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(value):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
}
std::uint32_t fun_004796c0(Memory&m,const Inputs&i){
 const auto p=fixed_lookup(m,i.arg[0]),xy=m.r32(p+0x24u),x=sx16(xy),y=sx16(xy>>16);
 const auto dx=sx16(m.r16(i.cx+0x24u))-x,dy=sx16(m.r16(i.cx+0x26u))-y;
 const auto code=m.r32(0x7bdbdcu+(dy*3u+dx)*4u);if(!dx||!dy)return code;
 auto a=pair(x+(dx==dy?dx:dy),y),b=pair(x,y+(dx==dy?dy:dx));
 const auto level=s32(sx8(m.r8(fixed_lookup(m,i.arg[0])+0x11bu)))+2;
 const auto first=s32(sx8(m.r8(lookup(m,0x81a820u,a)+0x11bu)))>=level;
 const auto level2=s32(sx8(m.r8(fixed_lookup(m,i.arg[0])+0x11bu)))+2;
 const auto second=s32(sx8(m.r8(lookup(m,0x81a820u,b)+0x11bu)))>=level2;
 if(first&&!second)return (code-1u)&7u;if(!first&&second)return code+1u;return code;
}
std::uint32_t fun_004798f0(Memory&m,const Inputs&i){
 if(status(m,i.cx))return 1;
 auto a=lookup(m,0x81a820u,neighbor(m,m.r32(i.cx+0x24u),0));
 auto b=lookup(m,0x81a820u,neighbor(m,m.r32(a+0x24u),0));
 if(status(m,a)&&!status(m,b))return 1;
 auto c=lookup(m,0x81a820u,neighbor(m,m.r32(b+0x24u),0));if(status(m,b)&&!status(m,c))return 1;
 a=lookup(m,0x81a820u,neighbor(m,m.r32(i.cx+0x24u),6));b=lookup(m,0x81a820u,neighbor(m,m.r32(a+0x24u),6));
 if(status(m,a)&&!status(m,b))return 1;
 c=lookup(m,0x81a820u,neighbor(m,m.r32(b+0x24u),6));return status(m,b)&&!status(m,c)?1u:0u;
}
std::uint32_t fun_0047bba0(Memory&m,const Inputs&i){const auto mask=1u<<(i.arg[0]&31u);if(!(m.r32(i.cx+0xdcu)&mask))return 0xffffffffu;auto result=0u;for(unsigned d=0;d<8;++d)if(m.r32(lookup(m,0x81a820u,neighbor(m,m.r32(i.cx+0x24u),d))+0xdcu)&mask)result|=1u<<d;return result;}
namespace {
std::uint32_t walk(Memory&m,const Inputs&i,std::uint32_t off,std::uint32_t bit){
 const auto xy=m.r32(i.arg[0]);if(xy==m.r32(0x83a940u))return 0;
 const auto enable=i.arg[1]&255u;auto p=m.r32(i.cx+off);
 while(m.r32(p)!=0x7fff7fffu){const auto out=add_pair(xy,m.r32(p));p+=4;i.arg[1]=out;
 if(inside(m,i.cx,out)){const auto cell=lookup(m,i.cx,out),flags=m.r32(cell+0x12cu);m.w32(cell+0x12cu,enable?flags|bit:flags&~bit);}}
 return 0;
}}
std::uint32_t fun_004996a0(Memory&m,const Inputs&i){return walk(m,i,0x1178u,2u);}
std::uint32_t fun_00499750(Memory&m,const Inputs&i){return walk(m,i,0x1188u,4u);}
std::uint32_t fun_004b4f20(Memory&m,const Inputs&i){const auto r=m.r32(i.cx+0x28u),rs=r*r;for(auto y=0u-r;s32(y)<=s32(r);++y)for(auto x=0u-r;s32(x)<=s32(r);++x){const auto xy=add_pair(m.r32(i.cx+0x24u),pair(x,y)),xx=sx16(xy),yy=sx16(xy>>16);if(s32(xx)<0||s32(xx)>=512||s32(yy)<0||s32(yy)>=512)continue;const auto idx=(yy<<9)+xx;if(!m.r32(m.r32(0x81a958u)+idx*4u))continue;if(s32(x*x+y*y)>s32(rs))continue;const auto cell=lookup(m,0x81a820u,xy);m.w32(cell+0x140u,m.r32(cell+0x140u)&~0x80000u);}return r;}
std::uint32_t fun_004f04f0(Memory&m,const Inputs&i){
 if(s32(i.arg[1])<=0)i.arg[1]=1;
 const auto obj=i.arg[0]+0x88u,rect=i.arg[3];const auto xx=m.r32(obj),yy=m.r32(obj+4u);
 const auto cx=s32(sx16(sar(xx+(s32(xx)<0?255u:0u),8))),cy=s32(sx16(sar(yy+(s32(yy)<0?255u:0u),8)));
 const auto left=s32(m.r32(rect)),top=s32(m.r32(rect+4));const auto w=m.r32(rect+8),h=m.r32(rect+12);
 const auto xmin=cx-6>left?cx-6:left,xmax=cx+6<s32(std::uint32_t(left)+w)?cx+6:s32(std::uint32_t(left)+w);
 const auto ymin=cy-6>top?cy-6:top,ymax=cy+6<s32(std::uint32_t(top)+h)?cy+6:s32(std::uint32_t(top)+h);
 auto&f=i.fp;
 for(auto y=ymin;y<ymax;++y)for(auto x=xmin;x<xmax;++x){const auto dy=std::uint32_t(y-cy),dx=std::uint32_t(x-cx);f.load_integer32(dx*dx+dy*dy);const auto sq=f.pop64();root(m,f,sq);const auto distance=f.store64();f.compare_pop64(floating_b61::read64(m,0x78dfa0u));if(!(f.status()&0x100u))continue;
 f.load64(distance);f.load64(distance);const auto one=floating_b61::read64(m,0x785708u);f.compare_pop64(one);if(f.status()&0x100u){f.pop_st0();f.load64(one);}
 f.load_integer32(i.arg[1]);f.exchange_st1();f.subtract64(one);f.multiply64(floating_b61::read64(m,0x787570u));f.add64(one);f.divide_pop();
 const auto dest=i.arg[2]+(std::uint32_t(y-top)*w+std::uint32_t(x-left))*4u;add_integer(f,m.r32(dest));const auto control=m.r32(0x7c3a04u);if(f.control()!=control)f.load_control(std::uint16_t(control));m.w32(dest,std::uint32_t(f.pop_integer64()));
 }
 return std::uint32_t(ymax);
}
std::uint32_t fun_00564e90(Memory&m,const Inputs&i){const auto xy=m.r32(i.arg[0]),x=sx16(xy),y=sx16(xy>>16),r=i.arg[1];for(auto yy=y-r;s32(yy)<=s32(y+r);++yy)for(auto xx=x-r;s32(xx)<=s32(x+r);++xx){i.arg[0]=pair(xx,yy);const auto k=(sx16(yy)<<9)+sx16(xx);auto p=0u;if(s32(k)>=0&&k<0x40000u)p=m.r32(m.r32(0x81a958u)+k*4u);if(!p){m.w32(0xa57634u,i.arg[0]);p=0xa57610u;}if(m.r32(p+0xe4u))return 1;}return 0;}
std::uint32_t fun_00580430(Memory&m,const Inputs&i){const auto x=m.r32(i.cx),y=m.r32(i.cx+4),w=m.r32(i.cx+8),h=m.r32(i.cx+12);auto count=0u;for(auto yy=0u;s32(yy)<s32(h);++yy)for(auto xx=0u;s32(xx)<s32(w);++xx){const auto a=sx16(x+xx),b=sx16(y+yy);if(!diamond(m,a,b))continue;const auto grid=m.r32(0xa5863cu);const auto val=grid?m.r32(grid+(b*m.r32(0x836b4cu)+a)*80u+0x38u):0xffffffffu;if(val==i.dx&&s32(++count)>=s32(i.arg[1]))return 1;}return 0;}
std::uint32_t fun_00585a20(Memory&m,const Inputs&i){const auto x=m.r32(i.cx),y=m.r32(i.cx+4),w=m.r32(i.cx+8),h=m.r32(i.cx+12);if(!diamond(m,x,y)||!diamond(m,x+w-1u,y)||!diamond(m,x,y+h-1u)||!diamond(m,x+w-1u,y+h-1u))return 0;const auto level=sx8(m.r8(lookup(m,0x81a820u,pair(x,y))+0x11bu));for(auto yy=y;s32(yy)<s32(y+h);++yy)for(auto xx=x;s32(xx)<s32(x+w);++xx){const auto p=lookup(m,0x81a820u,pair(xx,yy));if(sx8(m.r8(p+0x11bu))!=level)return 0;const auto v=m.r32(p+0x38u);if(range(v,m.r32(0xa55944u),15u)||range(v,m.r32(0xa55940u),4u)){if(!(i.dx&255u))return 0;}else if(v!=0&&v!=65535u&&!range(v,m.r32(0xa3ab2cu),14u)&&!range(v,m.r32(0xa55d18u),16u))return 0;}return 1;}
std::uint32_t fun_00673f80(Memory&m,const Inputs&i){m.w32(i.cx+0x34u,i.arg[0]);const auto num=m.r32(0x82196cu)-m.r32(0xaa486cu)-(m.r8(m.r32(0xa255c0u)+0x2239u)?26u:18u)+m.r32(0x821964u)-7u;auto count=sar(imul_high(num,0x51eb851fu),4);count+=count>>31;for(auto n=0u;s32(n)<s32(count);++n)for(auto j=0u;j<2;++j){const auto k=m.r32(i.cx+0x34u),index=n*2u+j,out=0xaa1240u+(k*60u+index)*56u,table=k*921u; m.w32(out+0x24u,202u);m.w32(out+0xcu,m.r32(0x81bd7cu+table*4u)+m.r32(0xaa4870u)*j);m.w32(out+0x10u,m.r32(0x81bd80u+table*4u)+m.r32(0xaa4874u)*n+1u);m.w32(out+0x30u,index);m.w32(out+0x14u,60u);m.w32(out+0x18u,48u);m.w32(out+0x2cu,i.cx);}return s32(count)>0?count:0u;}
std::uint32_t fun_00705620(Memory&m,const Inputs&i){if(s32(m.r32(0xa283c4u))>0)return 1;const auto xy=m.r32(i.cx);const auto x=s32(sx16(xy)),y=s32(sx16(xy>>16));for(auto n=m.r32(0xab81d8u)-1u;s32(n)>=0;--n){const auto p=m.r32(m.r32(0xab81ccu)+n*4u);const auto a=x-s32(sx16(m.r16(p+0xe0u))),b=y-s32(sx16(m.r16(p+0xe2u)));if(a>-3&&a<3&&b>-3&&b<3)return 0;}const auto cell=lookup(m,0x81a820u,xy),level=sx8(m.r8(cell+0x11bu));if(s32(level)<1)return 0;for(auto yy=-1;yy<=1;++yy)for(auto xx=-1;xx<=1;++xx){const auto p=lookup(m,0x81a820u,pair(std::uint32_t(x+xx),std::uint32_t(y+yy)));if(m.r8(p+0x11cu)||m.r32(p+0xecu)||sx8(m.r8(p+0x11bu))!=level)return 0;}return 1;}
std::uint32_t fun_0070bd90(Memory&m,const Inputs&){m.w32(0xac8730u,0);m.w32(0xacaa80u,0);if(m.r32(0x7e35e8u)){m.w32(0x7e35e8u,0);for(auto n=0u;n<65536u;++n){m.w8(0xacae88u+n,0);m.w8(0xab84f0u+n,0);}}else{const auto x=m.r32(0xacaa70u),y=m.r32(0xacaa74u),w=m.r32(0xacaa78u),h=m.r32(0xacaa7cu);if(s32(x)<0||s32(y)<0||s32(x+w)>255||s32(y+h)>255){for(auto n=0u;n<65536u;++n)m.w8(0xacae88u+n,0);}else for(auto yy=y;s32(yy)<=s32(y+h);++yy)for(auto xx=0u;xx<=w;++xx)m.w8(0xacae88u+(yy<<8)+x+xx,0);if(m.r32(0xade090u))for(auto yy=y;s32(yy)<=s32(y+h);++yy)for(auto xx=0u;xx<=w;++xx)m.w8(0xab84f0u+(yy<<8)+x+xx,0);}for(unsigned k=0;k<3;++k){m.w32(0xac84f0u+k*4u,0x461c4000u);m.w32(0xac8858u+k*4u,0xc61c4000u);}return 0xc61c4000u;}
}



