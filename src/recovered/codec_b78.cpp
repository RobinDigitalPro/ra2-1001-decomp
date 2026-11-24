#include "recovered/codec_b78.hpp"
#include "recovered/pixels_b72.hpp"
#include <algorithm>
#include <cstdint>

namespace ra2::recovered::codec_b78 {
namespace {
using U=std::uint32_t;
inline U arg(const Inputs&i,unsigned n){return i.arg[n];}

// The 0x76ca70 body is byte-for-byte instruction-identical to accepted RVA
// 0x36a710 after relocating its two embedded tables by 0x2360.
constexpr U audio_four_table[4]={0xfeu,0xffu,0x00u,0x01u};
constexpr U audio_sixteen_table[16]={0xf7u,0xf8u,0xfau,0xfbu,0xfcu,0xfdu,0xfeu,0xffu,0x00u,0x01u,0x02u,0x03u,0x04u,0x05u,0x06u,0x08u};
inline U audio_sat(const U* table,unsigned index,U value){
    const U v=table[index],sum=(value&255u)+v;
    if(v>=0x80u){if(sum<=255u)return 0;}
    else if(sum>255u)return 255u;
    return sum&255u;
}
U audio_clone(Memory&m,const Inputs&i){
    U src=arg(i,0),dst=arg(i,1),left=arg(i,2),consumed=0;
    if(!src||!dst||!left||global_b26::s32(left)<=0)return 0;
    U edx=(i.dx&0xffffff00u)|0x80u;
    while(global_b26::s32(left)>0){
        const U ctl=m.r8(src++);++consumed;const U mode=ctl>>6,value=ctl&0x3fu;U dl=edx&255u;
        if(mode==2u){
            if(value&0x20u){const int signed_delta=(value&0x10u)?int(value&0x1fu)-32:int(value&0x1fu);dl=(dl+static_cast<U>(signed_delta))&255u;m.w8(dst++,dl);edx=(edx&0xffffff00u)|dl;--left;}
            else {const U n=value+1u;for(U k=0;k<n;++k)m.w8(dst++,m.r8(src++));consumed+=n;left-=n;--dst;dl=m.r8(dst);++dst;edx=(edx&0xffffff00u)|dl;}
            continue;
        }
        if(mode==1u){const U pairs=value+1u;for(U k=0;k<pairs;++k){const U packed=m.r8(src++);++consumed;
            dl=audio_sat(audio_sixteen_table,packed&15u,dl);edx=(edx&0xffffff00u)|dl;const U dh=dl;
            dl=audio_sat(audio_sixteen_table,packed>>4u,dl);edx=(edx&0xffff00ffu)|(dl<<8u);m.w16(dst,dh|(dl<<8u));edx=(edx&0xffffff00u)|dl;dst+=2u;left-=2u;}continue;}
        if(mode==0u){for(U k=0;k<value+1u;++k){const U packed=m.r8(src++);++consumed;
            for(U j=0;j<4u;++j){const U code=(packed>>(j*2u))&3u;dl=audio_sat(audio_four_table,code,dl);edx=(edx&0xffffff00u)|dl;if(j!=3u)edx=(edx&0xffff00ffu)|(dl<<8u);edx=(edx>>8u)|(edx<<24u);}
            m.w32(dst,edx);left-=4u;dst+=4u;edx=(edx<<8u)|(edx>>24u);}continue;}
        const U n=value+1u,fill=dl;left-=n;for(U k=0;k<n;++k)m.w8(dst++,fill);
    }
    return consumed;
}

U lcw_without_selector(Memory&m,const Inputs&i){
    const_cast<Inputs&>(i).arithmetic_flags&=~0x400u;
    U src=arg(i,0),dst=arg(i,1),cap=arg(i,2),produced=0;
    const U start=dst;
    while(produced<cap){
        const U ctl=m.r8(src++);U n=0,from=0;const U remain=cap-produced;
        if((ctl&0x80u)==0){n=((ctl>>4u)&7u)+3u;const U low=m.r8(src++);from=dst-(((ctl&15u)<<8u)|low);n=std::min(n,remain);while(n--){m.w8(dst++,m.r8(from++));++produced;}continue;}
        if((ctl&0x40u)==0){if(ctl==0x80u)break;n=std::min(ctl&0x3fu,remain);while(n--){m.w8(dst++,m.r8(src++));++produced;}continue;}
        n=(ctl&0x3fu)+3u;
        if(ctl==0xfeu){n=m.r16(src);src+=2u;const U value=m.r8(src++);n=std::min(n,remain);while(n--){m.w8(dst++,value);++produced;}continue;}
        if(ctl==0xffu){n=m.r16(src);src+=2u;}
        const U offset=m.r16(src);src+=2u;from=start+offset;n=std::min(n,remain);
        while(n--){m.w8(dst++,m.r8(from++));++produced;}
    }
    (void)start;return dst-arg(i,1);
}

U receiver_lcw(Memory&m,const Inputs&i){
    // Receiver and linked descriptors are caller-prepared finite records. The
    // three call sites and ordered flag/length writes follow 0x763b30 bytes.
    const U receiver=i.cx,object=m.r32(receiver+0x1a0u),descriptor=m.r32(object+4u),flags=m.r8(receiver+0x1a4u);
    if(flags&2u)return (i.ax&0xffffff00u)|flags;
    U eax=0;
    {
        U f=m.r32(descriptor+0xcu);
        U selected_output=0;
        if(f&2u){if(m.r8(receiver+0x154u)&1u){selected_output=m.r32(receiver+0x6f0u);f|=4u;m.w32(descriptor+0xcu,f);}else selected_output=m.r32(descriptor);}
        if(f&2u){const U input_base=m.r32(descriptor),cap=m.r32(receiver+0x774u),src=input_base+m.r32(descriptor+0x10u);const_cast<Inputs&>(i).arithmetic_flags&=~0x400u;eax=pixels_b72::fun_0076cd2b(m,Inputs{.arg={src,selected_output,cap}});m.w32(descriptor+0x14u,eax);f&=~2u;m.w32(descriptor+0xcu,f);eax=f;}
    }
    U f=m.r32(object+0x14u);if(f&8u){const U dst=m.r32(object+8u),cap=m.r32(receiver+0x770u),input=dst+m.r32(object+0x24u);const_cast<Inputs&>(i).arithmetic_flags&=~0x400u;eax=pixels_b72::fun_0076cd2b(m,Inputs{.arg={input,dst,cap}});m.w32(object+0x28u,eax);f&=~8u;m.w32(object+0x14u,f);eax=f;}else eax=f;
    f=m.r32(object+0x14u);if(f&0x10u){U dst=m.r32(object);if(m.r8(receiver+0x154u)&2u){dst=m.r32(receiver+0x6e8u);f|=0x40u;m.w32(object+0x14u,f);}const U cap=m.r32(receiver+0x778u),input=m.r32(object)+m.r32(object+0x20u);const_cast<Inputs&>(i).arithmetic_flags&=~0x400u;eax=pixels_b72::fun_0076cd2b(m,Inputs{.arg={input,dst,cap}});f=m.r32(object+0x14u)&~0x10u;m.w32(object+0x14u,f);eax=f;}else eax=f;
    return eax;
}

U adpcm_pair(Memory&m,const Inputs&i){
    const U state=arg(i,0),count=arg(i,1),input=m.r32(state),output=m.r32(state+4u);
    if(count!=2u||m.r16(state+0x38u)==0x10u||m.r16(state+0x3au)==2u)return count;
    m.w32(state+0x10u,0);m.w32(state+0x24u,0);
    U cursor=input,p=output,odd=0,packed=0;
    for(U n=0;n<2u;++n){
        U token;
        if((m.r32(state+0x10u)&1u)!=0u){token=(m.r16(state+0x1cu)>>4u)&15u;m.w16(state+0x1eu,token);}
        else {packed=m.r8(cursor++);m.w16(state+0x1cu,packed);token=packed&15u;m.w16(state+0x1eu,token);}
        m.w32(state+0x18u,0);const U step=m.r16(state+0x20u);
        U delta=step>>3u;if(token&4u)delta+=step;if(token&2u)delta+=step>>1u;if(token&1u)delta+=step>>2u;if(token&8u)delta=0u-delta;
        m.w32(state+0x18u,delta);
        auto sample=m.r32(state+0x14u)+delta;if(global_b26::s32(sample)>32767)sample=32767u;else if(global_b26::s32(sample)<-32768)sample=0xffff8000u;
        m.w32(state+0x14u,sample);m.w8(p++,((sample>>8u)^0x80u)&255u);
        const U index=m.r16(state+0x1eu);const U amount=m.r16(0x810944u+index*2u);U next=(m.r16(state+0x22u)+amount)&0xffffu;
        if(next>=0x8000u)next=0;else if(next>0x58u)next=0x58u;
        m.w16(state+0x22u,next);m.w32(state+0x10u,m.r32(state+0x10u)+1u);m.w16(state+0x20u,m.r16(0x810964u+next*2u));odd^=1u;
    }
    (void)odd;return count;
}

U token_expand(Memory&m,const Inputs&i){
    U src=i.cx,dst=i.dx;const U start=dst;
    for(;;){
        const U ctl=m.r8(src++);U count=0,from=0;
        if((ctl&0x80u)==0){count=(ctl>>4u)+3u;const U back=((ctl&15u)<<8u)|m.r8(src++);from=dst-back;while(count--){m.w8(dst++,m.r8(from++));}continue;}
        if((ctl&0x40u)==0){if(ctl==0x80u)break;count=ctl&0x3fu;while(count--){m.w8(dst++,m.r8(src++));}continue;}
        if(ctl==0xfeu){
            count=(m.r8(src+1u)<<8u)|m.r8(src);src+=2u;const U fill=m.r8(src++);
            U cursor=dst,left=count;const U prefix=std::min(left,4u-(cursor&3u));
            for(U k=0;k<prefix;++k)m.w8(cursor++,fill);
            left-=prefix;const U bulk=left&~3u,bulk_end=cursor+bulk;
            while(cursor<bulk_end){m.w32(cursor,fill*0x01010101u);m.w32(cursor+4u,fill*0x01010101u);cursor+=8u;}
            const U tail=left&3u;for(U k=0;k<tail;++k)m.w8(bulk_end+k,fill);
            dst+=count;continue;
        }
        if(ctl==0xffu){count=(m.r8(src+1u)<<8u)|m.r8(src);src+=2u;const U offset=(m.r8(src+1u)<<8u)|m.r8(src);src+=2u;from=start+offset;while(count--){m.w8(dst++,m.r8(from++));}continue;}
        count=(ctl&0x3fu)+3u;const U offset=(m.r8(src+1u)<<8u)|m.r8(src);src+=2u;from=start+offset;while(count--){m.w8(dst++,m.r8(from++));}
    }
    return dst-start;
}

U plane_decode(Memory&m,const Inputs&i,bool reverse){
    const U d=arg(i,0),table=reverse?m.r32(d+4u):m.r32(d);
    const U init=m.r8(d+0x32u);U x=0,y=0;
    for(U n=0;n<init;++n){m.w16(0xae0490u+n*4u,x);x+=global_b26::sx16(m.r16(d+0x2au));m.w16(0xae0492u+n*4u,y);y+=global_b26::sx16(m.r16(d+0x2cu));}
    U input=m.r32(d+0x0cu),row_input=input;
    U output=m.r32(d+0x18u),row_output=output;
    U rows=m.r8(d+0x31u),width=m.r8(d+0x30u);const U row_width=width;
    while(rows){
        if(width==0u){input=row_input+m.r32(d+0x14u);row_input=input;m.w32(d+0x0cu,input);output=row_output+m.r32(d+0x24u);row_output=output;--rows;width=row_width;continue;}
        m.w32(d+0x18u,output);
        const U signed_value=m.r32(table+input*4u);
        if(global_b26::s32(signed_value)>=0){
            m.w32(d+0x18u,output);
            U cursor=signed_value+m.r32(d+8u),remaining=m.r8(d+0x32u);
            U coord=(m.r16(d+0x1au)<<16u)|m.r16(d+0x18u);
            const U stride=m.r32(d+0x2au);
            while(remaining){
                if(reverse){
                    const U run=m.r8(cursor--);
                    if(run==0u)--cursor;
                    else {for(U k=0;k<run;++k){remaining=(remaining-1u)&255u;--cursor;const U pixel=m.r8(cursor);--cursor;const U index=((coord>>16u)&0xffffff00u)|((coord>>8u)&255u);m.w8(0xacae88u+index,pixel);coord+=stride;}--cursor;}
                    const U delta=m.r8(cursor--);remaining=(remaining-delta)&255u;coord+=m.r32(0xae0490u+delta*4u);
                } else {
                    const U delta=m.r8(cursor++);remaining=(remaining-delta)&255u;coord+=m.r32(0xae0490u+delta*4u);
                    const U run=m.r8(cursor++);if(run==0u){++cursor;continue;}
                    for(U k=0;k<run;++k){remaining=(remaining-1u)&255u;const U index=((coord>>16u)&0xffffff00u)|((coord>>8u)&255u);const U pixel=m.r8(cursor);cursor+=2u;m.w8(0xacae88u+index,pixel);coord+=stride;}
                    ++cursor;
                }
            }
        }
        input+=m.r32(d+0x10u);m.w32(d+0x0cu,input);output+=m.r32(d+0x1eu);--width;
        if(width==0u){input=row_input+m.r32(d+0x14u);row_input=input;m.w32(d+0x0cu,input);output=row_output+m.r32(d+0x24u);row_output=output;--rows;width=row_width;}
    }
    return input;
}

U signed_stream(Memory&m,const Inputs&i){
    U eax=(i.ax&0xffffff00u),source=arg(i,0),in_size=arg(i,1),out=arg(i,2),out_size=arg(i,3);
    if(in_size==0)return eax|1u;
    if(in_size<2u)return eax;
    const U mode=m.r16(source);source+=2u;U remaining=in_size-2u;
    if(remaining==0u)return eax|1u;
    if(!mode){if(remaining!=out_size)return eax;for(U n=0;n<remaining;++n)m.w8(out+n,m.r8(source+n));return eax|1u;}
    if(mode!=1u)return eax;
    while(remaining){
        const U ctl=m.r8(source++);--remaining;
    if((ctl&0x80u)==0){
            if(ctl){if(remaining<ctl)return eax;for(U n=0;n<ctl;++n)m.w8(out++,m.r8(source++));remaining-=ctl;continue;}
            if(remaining<2u)return eax;const U count=m.r8(source++),fill=m.r8(source++);remaining-=2u;
            for(U n=0;n<count;++n)m.w8(out++,fill);continue;
        }
        if(ctl!=0x80u){const auto delta=global_b26::sx8(ctl);out+=delta;continue;}
        if(remaining<2u)return eax;const U count=m.r16(source);source+=2u;remaining-=2u;
        if(count==0u)return eax|1u;
        // The original tests the loaded word as a signed 16-bit value.  A
        // 0x8003 word is a negative literal command, not a large positive skip.
        if((count&0x8000u)==0u){out+=count;continue;}
        const U expanded=count-0x8000u;
        if(count>=0xc000u){if(!remaining)return eax;const U fill=m.r8(source++);--remaining;const U n=expanded-0x4000u;for(U k=0;k<n;++k)m.w8(out++,fill);}
        else {const U n=expanded;if(remaining<n)return eax;for(U k=0;k<n;++k)m.w8(out++,m.r8(source++));remaining-=n;}
    }
    return eax;
}

U token_compress(Memory&m,const Inputs&i){
    const U start=i.cx,end=start+arg(i,0),output_start=i.dx;U p=start+1u,out=output_start;
    U literal_header=out;m.w8(out++,0x81u);m.w8(out++,m.r8(start));bool literals=true;
    while(p<end){
        U run=1u;const U value=m.r8(p);
        if(p+0x40u<end+0x40u&&m.r8(p+0x40u)==value){run=0;while(p+run<end&&m.r8(p+run)==value)++run;if(run) --run;}
        if(run>=65u){m.w8(out++,0xfeu);m.w16(out,run);out+=2u;m.w8(out++,value);p+=run;literals=false;continue;}
        U best=1u,best_at=0;
        for(U candidate=start;candidate<p;++candidate){if(m.r8(candidate)!=value)continue;U n=0;while(p+n<end&&m.r8(candidate+n)==m.r8(p+n))++n;if(n>=best){best=n;best_at=candidate;}}
        if(best<=2u){
            if(!literals||m.r8(literal_header)==0xbfu){literal_header=out;m.w8(out++,0x80u);literals=true;}
            m.w8(literal_header,m.r8(literal_header)+1u);
            m.w8(out++,value);++p;continue;
        }
        const U distance=p-best_at;
        if(best<=10u&&distance<=0xfffu){const U packed=((best-3u)<<4u)|((distance>>8u)&15u);m.w8(out++,packed);m.w8(out++,distance);}
        else if(best<=64u){m.w8(out++,0xc0u|(best-3u));m.w16(out,best_at-start);out+=2u;}
        else {m.w8(out++,0xffu);m.w16(out,best);out+=2u;m.w16(out,best_at-start);out+=2u;}
        p+=best;literals=false;
    }
    m.w8(out++,0x80u);return out-output_start;
}
}

U fun_0076ca70(Memory&m,const Inputs&i){return audio_clone(m,i);}
U fun_0076cc60(Memory&m,const Inputs&i){return lcw_without_selector(m,i);}
U fun_00763b30(Memory&m,const Inputs&i){return receiver_lcw(m,i);}
U fun_0076adfc(Memory&m,const Inputs&i){return adpcm_pair(m,i);}
U fun_00532db0(Memory&m,const Inputs&i){return token_expand(m,i);}
U fun_00784300(Memory&m,const Inputs&i){return plane_decode(m,i,false);}
U fun_00784400(Memory&m,const Inputs&i){return plane_decode(m,i,true);}
U fun_004249f0(Memory&m,const Inputs&i){return signed_stream(m,i);}
U fun_00532fa0(Memory&m,const Inputs&i){return token_compress(m,i);}
}
