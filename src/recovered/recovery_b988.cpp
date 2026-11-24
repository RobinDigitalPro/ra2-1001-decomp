#include "recovered/recovery_b988.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b988 {
namespace {using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::domain_error(s);}void w16(Format&f,U o,U v){f[o]=std::uint8_t(v);f[o+1u]=std::uint8_t(v>>8);}void w32(Format&f,U o,U v){for(U j=0;j<4u;++j)f[o+j]=std::uint8_t(v>>(8u*j));}}
U run(Memory&m,const Inputs&i,Boundary&h,U root,FormatObservation&o){
 need(root==0xa6e0u||root==0xa770u,"988 selected root");const auto buffer=m.r32(0x8198f0u);need(buffer!=0,"988 actual primary buffer");U rate=0,channels=0,bits=0,align=0;
 if(root==0xa6e0u){rate=i.cx;channels=i.arg[0]&0xffffu;bits=i.dx;need(bits==8u||bits==16u,"988 PCM8/16");align=((bits/8u)*i.arg[0])&0xffffu;}else{need(m.r32(0x819778u)!=0,"988 existing source receiver");need(h.stop(buffer)==0u,"988 actual Stop success");const auto owner=m.r32(0x819778u);rate=m.r32(owner+0x4cu);channels=m.r16(owner+0x50u);const auto sample_bytes=m.r16(owner+0x54u);need(sample_bytes==1u||sample_bytes==2u,"988 PCM byte width");bits=(sample_bytes<<3u)&0xffffu;align=(sample_bytes*channels)&0xffffu;}
 need((channels==1u||channels==2u)&&(rate==11025u||rate==22050u||rate==44100u||rate==48000u),"988 finite useful PCM format");
 o={};w16(o.bytes,0u,1u);w16(o.bytes,2u,channels);w32(o.bytes,4u,rate);w32(o.bytes,8u,align*rate);w16(o.bytes,12u,align);w16(o.bytes,14u,bits);w16(o.bytes,16u,0u);o.pointer=reinterpret_cast<std::uintptr_t>(o.bytes.data());
 if(root==0xa6e0u)need(h.stop(buffer)==0u,"988 actual Stop success");need(h.set_format(buffer,o.bytes)==0u,"988 actual SetFormat success");const auto result=h.play(buffer,0u,0u,1u);need(result==0u,"988 actual looping Play success");return result;
}
U fun_0040a6e0(Memory&m,const Inputs&i,Boundary&h,FormatObservation&o){return run(m,i,h,0xa6e0u,o);}
U fun_0040a770(Memory&m,const Inputs&i,Boundary&h,FormatObservation&o){return run(m,i,h,0xa770u,o);}
}
