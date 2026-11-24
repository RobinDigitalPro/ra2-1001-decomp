#include "global_b60_b.hpp"
#include <cstdint>
#include <algorithm>
namespace ra2::recovered::global_b26 {
namespace {
constexpr std::uint32_t G_A=0x00798c14u,G_B=0x00798c18u,G_C=0x0082197cu,G_D=0x00821974u,G_SWITCH=0x00a255c0u;
inline std::uint32_t rounded_span(std::uint32_t n){auto q=sar(imul_high(0x51eb851fu,n),4);q+=q>>31;return q*50u;}
}
std::uint32_t fun_00671290(Memory&m,const Inputs&){
    const auto a=m.r32(G_A),b=m.r32(G_B),c=m.r32(G_C),d=m.r32(G_D);m.w32(0x00821968u,a);m.w32(0x00821964u,0x9eu);
    const auto base=(b+c)+d-0x9eu;m.w32(0x0082196cu,base);const bool first=m.r8(m.r32(G_SWITCH)+0x2239u)!=0;
    if(first){m.w32(0x00aa4854u,0xa6);m.w32(0x00aa4858u,0x40);m.w32(0x00aa4860u,0xc5);m.w32(0x00aa4864u,0x1d);m.w32(0x00aa486cu,0xe3);m.w32(0x00aa4870u,0x3f);}
    else{m.w32(0x00aa4854u,0xa5);m.w32(0x00aa4858u,0x34);m.w32(0x00aa4860u,0xc5);m.w32(0x00aa4864u,0x20);m.w32(0x00aa486cu,0xe3);m.w32(0x00aa4870u,0x40);}
    m.w32(0x00aa4874u,0x32);const bool second=m.r8(m.r32(G_SWITCH)+0x2239u)!=0;const auto e=rounded_span(base-(second?0x1au:0x12u)-0x4cu);m.w32(0x00aa4878u,e);
    const auto out=e+0xeau;m.w32(0x00aa4884u,second?0x2eu:0x2du);m.w32(0x00aa4880u,out);m.w32(0x00aa4888u,0x32);return out;
}
// The pushed ECX slot supplies the upper word on the direct branch. The
// active interpolation path overwrites that slot with the coordinate dword.
std::uint32_t fun_004b89b0(Memory&m,const Inputs&i){
    const auto p=i.cx;auto scratch=p;std::uint32_t si=0,result=0;
    const auto bp=s32(sx16(m.r16(p+0x14)));bool active=false;std::uint32_t start=0,remaining=0,time=0;
    if(bp>0){start=m.r32(p+8);remaining=m.r32(p+0x10);time=m.r32(0xa2896c);
        if(start==0xffffffffu)active=remaining!=0;
        else {const auto elapsed=time-start;if(s32(elapsed)<s32(remaining)){remaining-=elapsed;active=remaining!=0;}}
    }
    if(active){const auto delta=s32(sx16(m.r16(p)-m.r16(p+4)));const auto magnitude=delta<0?0u-std::uint32_t(delta):std::uint32_t(delta);
        const auto q=idiv_quotient(magnitude,std::uint32_t(bp));si=m.r32(p);scratch=si;
        if(s32(sx16(q))>0){auto rem=m.r32(p+0x10);const auto started=m.r32(p+8);
            if(started!=0xffffffffu){const auto elapsed=time-started;rem=s32(elapsed)>=s32(rem)?0u:rem-elapsed;}
            const auto step=idiv_quotient(std::uint32_t(delta),std::uint32_t(sx16(q)))*rem;
            scratch=(scratch&0xffff0000u)|((scratch-step)&65535u);
        }result=scratch;
    }else{si=m.r32(p);result=si;}
    scratch=(scratch&0xffff0000u)|((si-result)&65535u);m.w32(i.arg[0],scratch);return i.arg[0];
}
std::uint32_t fun_00755fa0(Memory&m,const Inputs&i){
    auto src=i.dx;auto dst=i.arg[0];auto n=i.cx;std::uint32_t out=0;std::uint32_t run=1;std::uint8_t prev=static_cast<std::uint8_t>(m.r8(src));
    if(s32(n)<=1){if((prev&0xc0u)==0xc0u){m.w8(dst++,0xc1);++out;}m.w8(dst,prev);return out+1u;}
    for(std::uint32_t k=1;k<n;++k){const auto cur=static_cast<std::uint8_t>(m.r8(src+k));if(cur==prev){++run;if(run==0x2fu){m.w8(dst+out,static_cast<std::uint8_t>(m.r8(0x0079a828u)));++out;m.w8(dst+out,cur);++out;run=0;}}
        else{if(run){if(run==1u&&(prev&0xc0u)==0xc0u){m.w8(dst+out,0xc1);++out;m.w8(dst+out,prev);++out;}else if(run==1u){m.w8(dst+out,prev);++out;}else{m.w8(dst+out,static_cast<std::uint8_t>(0xc0u|run));++out;m.w8(dst+out,prev);++out;}}
            prev=cur;run=1;}}
    if(run){if(run>1u){m.w8(dst+out,static_cast<std::uint8_t>(0xc0u|run));++out;}else if((prev&0xc0u)==0xc0u){m.w8(dst+out,0xc1);++out;}m.w8(dst+out,prev);++out;}return out;
}
namespace {
std::uint32_t palette_step(Memory&m,const Inputs&i,unsigned variant){
    const auto obj=i.cx;auto src=i.arg[4],secondary=i.arg[5];const auto row_input=i.arg[6];
    auto row=s32(row_input)>0?row_input:0u;row=sar(row*261u,11);if(s32(row)>254)row=254;
    const auto row_table=m.r32(obj+8)+(row<<9);i.arg[4]=secondary;i.arg[6]=row_table;
    auto count=i.arg[2];if(s32(count)<=0)return count;
    auto dst=i.arg[0];const auto threshold=i.arg[3];i.arg[5]=count;
    do{
        const auto source_value=m.r16(src);
        if(s32(threshold)<static_cast<std::int32_t>(source_value)){
            const auto flag=m.r8(i.arg[1]);i.arg[2]=(i.arg[2]&0xffffff00u)|flag;
            if(flag){const auto slot=m.r16(secondary),mask=m.r16(obj+0xc);
                const auto mapped=m.r16(row_table+slot*2u)|flag;
                const auto color=m.r16(m.r32(obj+4)+mapped*2u);
                const auto old=m.r16(variant==2?dst:dst+i.arg[7]*2u);
                const auto ca=(color>>2)&mask,cb=(old>>2)&mask;
                m.w16(dst,variant==1?ca*3u+cb:ca+cb*3u);
                if(variant==2)m.w16(src,threshold);
            }
        }
        dst+=2u;++i.arg[1];src+=2u;
        const auto source_ring=m.r32(0x821fac);if(src>=m.r32(source_ring+0x1c))src-=m.r32(source_ring+0x20);
        secondary+=2u;const auto second_ring=m.r32(0x8198f4);
        if(secondary>=m.r32(second_ring+0x1c))secondary-=m.r32(second_ring+0x20);
        i.arg[4]=secondary;--count;i.arg[5]=count;
    }while(count!=0);
    return count;
}
}
std::uint32_t fun_00488c40(Memory&m,const Inputs&i){return palette_step(m,i,0);}
std::uint32_t fun_00488ec0(Memory&m,const Inputs&i){return palette_step(m,i,1);}
std::uint32_t fun_00489230(Memory&m,const Inputs&i){return palette_step(m,i,2);}
std::uint32_t fun_0042d520(Memory&m,const Inputs&i){
    if(!i.cx||!i.dx||!i.arg[0]||!i.arg[1])return 0;
    auto src=i.cx,dst=i.arg[0],remain=i.dx,cap=i.arg[1];std::uint32_t used=0;
    while(s32(remain)>0 && s32(cap)>=4){
        const auto first=m.r8(src++);--remain;std::uint32_t value=first<<16,missing=0;
        if(remain==0)missing=2;
        else{value|=m.r8(src++)<<8;--remain;if(remain==0)missing=1;else{value|=m.r8(src++);--remain;}}
        i.arg[0]=value;
        m.w8(dst++,m.r8(m.r32(0x787620)+((value>>18)&63)));
        m.w8(dst++,m.r8(m.r32(0x787620)+((value>>12)&63)));
        m.w8(dst++,missing>=2?m.r8(m.r32(0x78761c)):m.r8(m.r32(0x787620)+((value>>6)&63)));
        m.w8(dst++,missing>=1?m.r8(m.r32(0x78761c)):m.r8(m.r32(0x787620)+(value&63)));
        cap-=4;i.arg[1]=cap;used+=4;
    }
    if(s32(cap)>0)m.w8(dst,0);return used;
}
}
