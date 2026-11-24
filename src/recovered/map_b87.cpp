#include "recovered/map_b87.hpp"
#include "recovered/map_b79.hpp"
#include "recovered/global_b58_c.hpp"
#include "recovered/global_b27_memory.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <algorithm>
#include <cstdint>
#include <string>
#include <utility>

namespace ra2::recovered::global_b26 { std::uint32_t fun_00545500(Memory&,const Inputs&); std::uint32_t fun_0056a990(Memory&,const Inputs&); }
namespace ra2::recovered::global_b26 { std::uint32_t fun_0047b480(Memory&,const Inputs&); }
namespace ra2::recovered::global_b27 { void fun_004585b0(Memory&,State&); void fun_004585c0(Memory&,State&); }
namespace ra2::recovered::map_b87 {
using namespace global_b26;
namespace {
std::uint32_t pair(std::uint32_t x,std::uint32_t y){return (x&0xffffu)|((y&0xffffu)<<16);}
std::uint32_t lookup(Memory&m,std::uint32_t context,std::uint32_t xy){global_b26::Inputs c{};c.cx=context;c.arg[0]=0x180ff000u;m.w16(c.arg[0],xy);m.w16(c.arg[0]+2,xy>>16);return fun_00545500(m,c);}
std::uint32_t lookup_global(Memory&m,std::uint32_t xy,std::uint32_t scratch=0){if(!scratch)scratch=m.r32(0x81a958u)-0x100u;try{const auto saved=m.r32(scratch);global_b26::Inputs c{};c.cx=0x81a820u;c.arg[0]=scratch;m.w16(c.arg[0],xy);m.w16(c.arg[0]+2,xy>>16);const auto idx=(sx16(xy>>16)<<9)+sx16(xy),table=m.r32(0x81a958u);const auto expected=(s32(idx)>=0&&idx<0x40000u)?m.r32(table+idx*4u):0u;if(!expected)throw std::out_of_range("lookup entry missing table="+std::to_string(table)+" index="+std::to_string(idx));const auto out=fun_00545500(m,c);m.w32(scratch,saved);return out;}catch(const std::out_of_range&e){const auto idx=(sx16(xy>>16)<<9)+sx16(xy);throw std::out_of_range("lookup_global xy="+std::to_string(xy)+" scratch="+std::to_string(scratch)+" index="+std::to_string(idx)+" table="+std::to_string(m.r32(0x81a958u))+" cause="+e.what());}}
bool diamond(Memory&m,std::uint32_t x,std::uint32_t y){auto xx=sx16(x),yy=sx16(y),sum=xx+yy,lo=m.r32(0xa58634),hi=m.r32(0xa58638);return s32(sum)>s32(lo)&&s32(xx-yy)<s32(lo)&&s32(yy-xx)<s32(lo)&&s32(sum)<=s32(hi);}
std::uint32_t self_rec(Memory&m,std::uint32_t x,std::uint32_t y,std::uint32_t mode,std::uint32_t extra,unsigned depth){
    if(depth>32)throw std::out_of_range("36b170 finite recursion bound");
    const auto base=m.r32(0xaa49b4),width=m.r32(0x810a24),target=m.r32(base+(y*width+x)*8u);
    for(int dy=-1;dy<=1;++dy)for(int dx=-1;dx<=1;++dx){
        if(!dx&&!dy)continue;
        const auto nx=x+dx,ny=y+dy,p=base+(ny*width+nx)*8u,flags=m.r32(p+4);
        const auto v=m.r32(p),delta=v-target,sign=0u-(delta>>31),distance=(delta^sign)-sign;
        if(flags&1){if(extra||distance<=12)continue;return 0;}
        if(distance<=12)continue;
        if(mode==1){if(v<target){m.w32(p,target-12u);m.w32(p+4,flags|2u);}}
        else if(v>target){m.w32(p,target+12u);m.w32(p+4,flags|2u);}
        if(!self_rec(m,nx,ny,mode,extra,depth+1)&&!extra)return 0;
    }
    return 1;
}
}
std::uint32_t fun_00423b90(Memory&m,const floating_b61::Inputs&i){unsigned st=0;std::uint32_t c=0,owner=0,ot=0;try{global_b26::Inputs q{};q.cx=0x81a820u;q.arg[0]=i.arg[0];st=1;c=fun_00545500(m,q);st=2;auto stride=m.r32(0x834a48);st=3;const auto rz=m.r32(i.cx+0x90);st=4;if((m.r32(c+0x140)&0x100u)!=0){const auto h=sx8(m.r8(c+0x11b))*stride;if(s32(rz-h)>s32(2u*stride)){if(m.r8(c+0x128)&0xe0u)return 0;return 1;}}st=5;auto t=m.r32(c+0xec);if(t==3||t==10||t==4)return 0;st=6;owner=m.r32(c+0x44);st=61;if(owner!=0xffffffffu){ot=m.r32(0xa1e11c);st=62;auto op=m.r32(ot+owner*4);st=63;if(m.r8(op+0x278))return 0;}st=7;if(m.r8(c+0x124)&0xe0)return 0;auto z=sx8(m.r8(c+0x11b))*stride;return s32(z-rz)<=s32(2u*stride)?1u:0u;}catch(const std::out_of_range&){throw std::out_of_range("23b90 stage="+std::to_string(st)+" c="+std::to_string(c)+" owner="+std::to_string(owner)+" ot="+std::to_string(ot));}}
std::uint32_t fun_0047a1a0(Memory&m,const floating_b61::Inputs&i){auto base=m.r32(0xa1e11c),xy=m.r32(i.cx+0x24);std::uint32_t mask=0;for(unsigned n=0;n<4;++n){const auto k=n*2u,d=m.r32(0x839da0+k*4u),at=pair(sx16(xy)+sx16(d),sx16(xy>>16)+sx16(d>>16));auto p=lookup_global(m,at,i.cx+0x24u),o=m.r32(p+0x44);if(o==0xffffffffu)continue;auto marker=m.r8(m.r32(base+o*4)+0x27e);if((m.r8(p+0x11c)==0||marker)&&(o==0x7e?m.r8(p+0x11e)>=0x30:marker))mask|=1u<<n;}return mask;}
std::uint32_t fun_0047a270(Memory&m,const floating_b61::Inputs&i){auto c=i.cx,t=m.r32(c+0xec),o=m.r32(c+0x44),owners=m.r32(0xa1e11c);if(m.r8(c+0x11c)>4||t==2||t==3||t==8||t==6)return 0;if(o!=0xffffffffu&&!m.r8(m.r32(owners+o*4)+0x27e))return 0;const auto xy=m.r32(c+0x24);for(unsigned n=0;n<4;++n){const auto k=n*2u,d=m.r32(0x839da0+k*4u),at=pair(sx16(xy)+sx16(d),sx16(xy>>16)+sx16(d>>16));auto p=lookup_global(m,at,i.cx+0x24u),owner=m.r32(p+0x44),type=m.r32(p+0xec);if(m.r8(p+0x11c)>4||m.r8(c+0x11c)||owner==0xffffffffu||!m.r8(m.r32(owners+owner*4)+0x27e)||type==2||type==3||type==8||type==6)return 0;}return 1;}
std::uint32_t fun_004f4820(Memory&m,const floating_b61::Inputs&i){int stage=0,xx=0,yy=0;try{if(!m.r32(0xa255c8))return floating_b61::with_al(i.ax,1);stage=1;const auto obj=i.arg[0],coord=i.arg[1];global_b27::State a{};a.cx=obj;global_b27::fun_004585b0(m,a);const auto left=a.ax;stage=2;global_b27::State b{};b.cx=obj;b.arg[0]=0;global_b27::fun_004585c0(m,b);const auto right=b.ax;stage=3;const auto index=m.r32(m.r32(0x821b88)+0x10c8),half=index*2u;const auto x=sx16(m.r16(coord)),y=sx16(m.r16(coord+2));const auto x0=x-s32(index)-1,x1=x+s32(left)+s32(half)+1,y0=y-s32(index)-1,y1=y+s32(right)+s32(half)+1,bit=1u<<(m.r32(i.cx+0x30)&31);stage=4;for(yy=y0;yy<y1;++yy)for(xx=x0;xx<x1;++xx){i.arg[0]=pair(xx,yy);auto p=lookup_global(m,i.arg[0]);if(m.r32(p+0xdc)&bit)return 1;}return 0;}catch(const std::out_of_range&e){throw std::out_of_range("f4820 stage="+std::to_string(stage)+" x="+std::to_string(xx)+" y="+std::to_string(yy)+" cause="+e.what());}}
std::uint32_t fun_0054cfb0(Memory&m,const floating_b61::Inputs&i){
    const auto xy=i.arg[0];const auto x=sx16(m.r16(xy)),y=sx16(m.r16(xy+2));
    const auto width=m.r32(i.cx+0xf0),height=m.r32(i.cx+0xf4);
    const auto raw=(width+height+1u)*y+x;
    const auto index=s32(raw)<0?0u:(s32(raw)>=s32(m.r32(i.cx+0x68))?m.r32(i.cx+0x68)-1u:raw);
    const auto center=m.r32(i.cx+0x64)+index*4u;
    const auto stride=m.r32(0x81a910)+m.r32(0x81a914)+1u;
    const std::uint32_t offsets[8]={0u-stride,1u-stride,1u,stride+1u,stride,stride-1u,0xffffffffu,0u-stride-1u};
    i.arg[0]=0xffffffffu;
    if(m.r8(center)==7)return 7;
    bool found_zero=false;std::uint32_t chosen=0;for(auto o:offsets)if(!m.r8(center+o*4u)){found_zero=true;chosen=center+o*4u;break;}
    if(!found_zero)throw std::out_of_range("14cfb0 excluded 54c060 fallback");
    const auto palette=m.r32(i.cx+0x18);std::uint32_t previous=0,count=0;
    for(auto o:offsets){const auto p=center+o*4u,selector=m.r16(p+2);
        if(m.r16(palette+selector*2u)!=m.r16(palette+previous*2u)&&m.r8(p)!=7){previous=selector;chosen=p;++count;}}
    i.arg[0]=count;
    if(count<=3&&m.r8(center)==0)m.w16(center+2,m.r16(chosen+2));
    return count;
}
std::uint32_t fun_0054d0f0(Memory&m,const floating_b61::Inputs&i){
    const auto xy=i.arg[0];const auto x=sx16(m.r16(xy)),y=sx16(m.r16(xy+2));
    const auto width=m.r32(i.cx+0xf0),height=m.r32(i.cx+0xf4);
    const auto raw=(width+height+1u)*y+x;
    const auto index=s32(raw)<0?0u:(s32(raw)>=s32(m.r32(i.cx+0x68))?m.r32(i.cx+0x68)-1u:raw);
    const auto center=m.r32(i.cx+0x64)+index*4u,stride=m.r32(0x81a910)+m.r32(0x81a914)+1u;
    const std::uint32_t offsets[8]={0u-stride,1u-stride,1u,stride+1u,stride,stride-1u,0xffffffffu,0u-stride-1u};
    i.arg[0]=0xffffffffu;const auto kind=m.r8(center);if(kind==7)return 7;
    bool matched=false;std::uint32_t chosen=0;for(auto o:offsets)if(m.r8(center+o*4u)==kind){matched=true;chosen=center+o*4u;break;}
    if(!matched)throw std::out_of_range("14d0f0 excluded 54c060 fallback");
    const auto palette=m.r32(i.cx+0x18);std::uint32_t previous=0,count=0;
    for(auto o:offsets){const auto p=center+o*4u,selector=m.r16(p+2);
        if(m.r16(palette+selector*2u)!=m.r16(palette+previous*2u)&&m.r8(p)!=7){previous=selector;chosen=p;++count;}}
    i.arg[0]=count;
    if(count>3)throw std::out_of_range("14d0f0 excluded 54c060 fallback");
    const auto result=m.r16(chosen+2);m.w16(center+2,result);return result;
}
std::uint32_t fun_0056f6c0(Memory&m,const floating_b61::Inputs&i){
    const auto coord=i.arg[0],out=i.arg[1],x=sx16(m.r16(coord)),y=sx16(m.r16(coord+2));
    auto& f=i.fp;f.load64(floating_b61::read64(m,0x790bf8));f.subtract64(floating_b61::read64(m,0x790bf0));
    f.load32(m.r32(0x7867f8));f.subtract32(i.arg[3]);ra2::platform::x87_scalar_b46::multiply_pop(f);
    f.add64(floating_b61::read64(m,0x790bf0));const auto control=m.r32(0x7c3a04);if(f.control()!=control)f.load_control(std::uint16_t(control));
    const auto threshold=std::uint32_t(f.pop_integer64());
    const auto scratch=coord+0x100u;std::uint32_t saved[4];for(unsigned k=0;k<4;++k)saved[k]=m.r32(scratch+4*k);
    auto check=[&](std::uint32_t xx,std::uint32_t yy){m.w32(scratch,xx);m.w32(scratch+4,yy);m.w32(scratch+8,5);m.w32(scratch+12,5);
        map_b79::Inputs h{};h.cx=scratch;h.dx=m.r32(i.cx+8);h.arg[1]=threshold;return map_b79::fun_00580430(m,h)&255u;};
    const auto center_x=x-2u,center_y=y-2u;i.arg[0]=center_x;
    if(!check(center_x,center_y)){for(unsigned k=0;k<4;++k)m.w32(scratch+4*k,saved[k]);m.w8(out,0);return 0;}
    std::uint32_t mask=0;
    for(unsigned row=0;row<3;++row)for(unsigned col=0;col<3;++col){if(row==1&&col==1)continue;
        if(check(x-7u+col*5u,y-7u+row*5u))mask|=m.r32(0x7cb4a0+(row*3u+col)*4u);}
    for(unsigned k=0;k<4;++k)m.w32(scratch+4*k,saved[k]);i.arg[3]=mask;return mask;
}
std::uint32_t fun_00572700(Memory&m,const floating_b61::Inputs&i){
    const auto r=i.arg[0],x=m.r32(r),y=m.r32(r+4),w=m.r32(r+8),h=m.r32(r+12),scratch=r-0x100u;
    for(auto [xx,yy]:{std::pair{x,y},std::pair{x+w-1u,y},std::pair{x,y+h-1u},std::pair{x+w-1u,y+h-1u}}){
        i.arg[0]=pair(xx,yy);
        const auto saved=m.r32(scratch);global_b26::Inputs q{};q.cx=0x81a820;q.arg[0]=scratch;q.arg[1]=1;
        m.w32(scratch,pair(xx,yy));const auto result=fun_00557450(m,q);m.w32(scratch,saved);
        if(!(result&255u))return result&0xffffff00u;
    }
    const auto grid=m.r32(0xa5863c),stride=m.r32(0x836b4c);
    for(auto yy=y;s32(yy)<s32(y+h);++yy)for(auto xx=x;s32(xx)<s32(x+w);++xx){
        i.arg[0]=pair(xx,yy);
        const auto grid_value=grid?m.r32(grid+(sx16(yy)*stride+sx16(xx))*80u+0x38u):0xffffffffu;
        if(grid_value!=m.r32(i.cx+8)&&grid_value!=i.arg[1])return grid_value&0xffffff00u;
        const auto p=lookup_global(m,pair(xx,yy));if(m.r32(p+0x38)!=0&&m.r32(p+0x38)!=65535u)return m.r32(p+0x38)&0xffffff00u;
    }
    return (x&0xffffff00u)|1u;
}
std::uint32_t fun_00585650(Memory&m,const floating_b61::Inputs&i){
    const auto out=i.arg[0],coord=i.arg[1],rect=i.arg[2];
    const auto source=m.r32(coord),x=sx16(source),y=sx16(source>>16);
    const auto width=m.r32(rect+8),height=m.r32(rect+12);
    const auto right=m.r32(rect)+width+1u,bottom=m.r32(rect+4)+height+1u;
    if(s32(x)<s32(right)&&s32(y)<s32(bottom))throw std::out_of_range("185650 excluded 185830 route");
    const auto direction=(i.arg[3]-4u)&7u,step=m.r32(0x839da0+direction*4u);
    const auto selected=pair(x+sx16(step),y+sx16(step>>16));
    i.arg[3]=selected;
    const auto target_x=sx16(m.r16(coord)),target_y=sx16(m.r16(coord+2));
    if(std::max(s32(selected&0xffffu)-s32(target_x),s32(selected>>16)-s32(target_y))>6)
        throw std::out_of_range("185650 excluded random-step route");
    m.w32(out,selected);return out;
}
std::uint32_t fun_00585830(Memory&m,const floating_b61::Inputs&i){
    const auto r=i.cx,x=m.r32(r),y=m.r32(r+4),w=m.r32(r+8),h=m.r32(r+12);
    if(!diamond(m,x,y)||!diamond(m,x+w-1u,y)||!diamond(m,x,y+h-1u)||!diamond(m,x+w-1u,y+h-1u))return x&0xffffff00u;
    const auto in=[&](std::uint32_t v,std::uint32_t first,std::uint32_t size){return s32(v)>=s32(first)&&s32(v)<s32(first+size);};
    for(auto yy=y;s32(yy)<s32(y+h);++yy)for(auto xx=x;s32(xx)<s32(x+w);++xx){
        const auto p=lookup_global(m,pair(xx,yy)),v=m.r32(p+0x38);
        if(in(v,m.r32(0xa55944),15)){if(!(i.dx&255u))return v&0xffffff00u;continue;}
        if(in(v,m.r32(0xa55940),4)){if(!(i.arg[0]&255u))return v&0xffffff00u;continue;}
        if(v==0||v==65535u||in(v,m.r32(0xa3ab2c),14)||in(v,m.r32(0xa55d18),16))continue;
        return v&0xffffff00u;
    }
    return (x&0xffffff00u)|1u;
}
std::uint32_t fun_00586120(Memory&m,const floating_b61::Inputs&i){
    const auto r=i.cx,x=m.r32(r),y=m.r32(r+4),w=m.r32(r+8),h=m.r32(r+12);
    if(!diamond(m,x,y)||!diamond(m,x+w-1u,y)||!diamond(m,x,y+h-1u)||!diamond(m,x+w-1u,y+h-1u))return x&0xffffff00u;
    for(auto yy=y;s32(yy)<s32(y+h);++yy)for(auto xx=x;s32(xx)<s32(x+w);++xx){
        const auto p=lookup_global(m,pair(xx,yy)),v=m.r32(p+0x38);Inputs z{};z.cx=p;
        if(!(fun_0047b480(m,z)&255u)){
            const auto low=m.r32(0xa3ab2c);
            if(s32(v)<s32(low))return low&0xffffff00u;
            if(s32(v)>s32(low+7u))return (low+7u)&0xffffff00u;
        }
        const auto marker=m.r32(p+0xe4);if(marker)return marker&0xffffff00u;
    }
    return (x&0xffffff00u)|1u;
}
std::uint32_t fun_0067a7e0(Memory&m,const floating_b61::Inputs&i){auto obj=i.cx,xy=m.r32(obj+0x24),x=sx16(xy),y=sx16(xy>>16),sum=x+y,lo=m.r32(0xa58634);if(s32(sum)<=s32(lo)||s32(x-y)>=s32(lo)||s32(y-x)>=s32(lo)||s32(sum)>s32(m.r32(0xa58638))||m.r32(obj+0x44)!=0xffffffff||m.r32(obj+0xe4))return 1;const auto scratch=obj+0x20u,prior=m.r32(scratch);m.w32(scratch,xy);global_b26::Inputs q{};q.cx=scratch;auto c=fun_0056a990(m,q);m.w32(scratch,prior);if(m.r8(c+0x45))return 1;auto n=m.r32(obj+0x38),count=m.r32(0xa28920);if(s32(n)>=s32(count)||n==0xffff)return 1;auto table=m.r32(0xa28914),target=m.r32(table+n*4);return (table&0xffffff00u)|(m.r8(target+0x2b0));}
std::uint32_t fun_0067c3c0(Memory&m,const floating_b61::Inputs&i){
    const auto o=i.cx,xy=m.r32(o+0x24),x=sx16(xy),y=sx16(xy>>16),base=m.r32(0xaa49b4);
    const auto width=m.r32(0x810a24),x_origin=m.r32(0x810a28),y_origin=m.r32(0x810a2c);
    const auto index=(y-y_origin)*width+x-x_origin;
    auto minimum=1000u;
    for(auto yy=0u;yy<2;++yy)for(auto xx=0u;xx<2;++xx){const auto v=m.r32(base+(index+yy*width+xx)*8u);if(s32(v)<s32(minimum))minimum=v;}
    if(!diamond(m,x,y)||m.r32(o+0x44)!=0xffffffffu||m.r32(o+0xe4))return sx8(m.r8(o+0x11b));
    const auto saved=m.r32(o+0x20);m.w32(o+0x20,xy);global_b26::Inputs q{};q.cx=o+0x20;
    const auto cell=fun_0056a990(m,q);m.w32(o+0x20,saved);
    const auto idx=m.r32(o+0x38),count=m.r32(0xa28920);
    if(m.r8(cell+0x45)||s32(idx)>=s32(count)||idx==0xffffu||!m.r8(m.r32(m.r32(0xa28914)+idx*4u)+0x2b0))return sx8(m.r8(o+0x11b));
    const auto high=imul_high(minimum,0x88888889u),qv=sar(high+minimum,3);return qv+(qv>>31);
}
std::uint32_t fun_0076b170(Memory&m,const floating_b61::Inputs&i){return self_rec(m,i.arg[0],i.arg[1],i.arg[2],i.arg[3],0);}
}
