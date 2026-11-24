#include "recovered/leaf_b21_c.hpp"

namespace ra2::recovered::leaf {

uint32_t fun_004052f0(Memory& m,const Inputs& i){const auto v=m.r32(i.cx+0x18);const auto out=(v&0xffffff00u)|((v|8u)&0xffu);m.w32(i.cx+0x18,out);return out;}
uint32_t fun_004071e0(Memory& m,const Inputs& i){return m.r32(i.cx+8)>>16;}
uint32_t fun_00407a70(Memory& m,const Inputs& i){const auto p=m.r32(i.cx+0x14);m.w32(p+0x94,i.dx);return p;}
uint32_t fun_00407a80(Memory& m,const Inputs& i){const auto p=m.r32(i.cx+0x14);m.w32(p+0x9c,i.dx);return p;}

uint32_t fun_0040ff10(Memory& m,const Inputs& i){
 const auto receiver=i.cx;std::uint32_t cl=0;
 m.w32(receiver+8,0x785e44);m.w32(receiver+0xc,0x785e3c);
 m.w32(receiver+0x18,0);m.w32(receiver+0x1c,0);m.w8(receiver+0x20,cl);
 cl=m.r8(receiver+0x14)&0xf8u;
 m.w32(receiver+0x10,0xffffffffu);m.w32(receiver,0x785dd8);m.w32(receiver+4,0x785dbc);
 m.w32(receiver+8,0x785db4);m.w32(receiver+0xc,0x785dac);m.w8(receiver+0x14,cl);
 return receiver;
}
uint32_t fun_0040ffc0(Memory& m,const Inputs& i){const auto p=i.arg[0];return m.r32(p+0xc);}
uint32_t fun_004112f0(Memory& m,const Inputs& i){const auto value=m.r32(i.cx+0xc)-1u;m.w32(i.cx+0xc,value);return (value&0xffffff00u)|1u;}

uint32_t fun_00432030(Memory& m,const Inputs& i){
 const auto object=m.r32(i.cx+4);if(!object)return 0;
 const auto index=i.arg[0]&0xffffu;const auto table=m.r32(object+0x18);
 const auto entry=m.r16(table+index*2u);if(!entry)return 0;
 const auto row=m.r32(object+0x14)*(entry-1u)+m.r32(object+0x1c);
 return row?m.r8(row):0u;
}

uint32_t fun_0044d070(Memory& m,const Inputs& i){
 const auto receiver=i.cx;std::uint32_t eax=0,edx=0,esi=receiver+0x454;
 m.w8(receiver+0x530,1);
 while(s32(edx)<0x4c8){
  eax=m.r32(receiver+0x418);
  if(m.r8(eax+edx+0xd14)!=0){
   eax=m.r32(esi);
   if(eax){m.w8(eax+0x102,0);m.w8(eax+0x103,1);m.w8(eax+0x101,0);}
  }
  edx+=0x44u;esi+=4u;
 }
 return eax;
}

uint32_t fun_004513f0(Memory& m,const Inputs& i){
 const auto receiver=i.cx;auto eax=m.r32(m.r32(receiver+0x418)+0x11d8);
 if(s32(eax)>0)return eax;
 for(std::uint32_t n=0;n<3;++n){const auto p=m.r32(receiver+0x4c0+n*4u);if(p){const auto v=m.r32(p+0x11d8);if(s32(v)>0)return v;}}
 return 0;
}
uint32_t fun_00451440(Memory& m,const Inputs& i){
 const auto receiver=i.cx;auto eax=m.r32(m.r32(receiver+0x418)+0x11dc);
 if(s32(eax)>0)return eax;
 for(std::uint32_t n=0;n<3;++n){const auto p=m.r32(receiver+0x4c0+n*4u);if(p){const auto v=m.r32(p+0x11dc);if(s32(v)>0)return v;}}
 return 0;
}
uint32_t fun_00451490(Memory& m,const Inputs& i){
 const auto receiver=i.cx;auto eax=m.r32(m.r32(receiver+0x418)+0x11e0);
 if(s32(eax)>0)return eax;
 for(std::uint32_t n=0;n<3;++n){const auto p=m.r32(receiver+0x4c0+n*4u);if(p){const auto v=m.r32(p+0x11e0);if(s32(v)>0)return v;}}
 return 0;
}

uint32_t fun_0045e900(Memory& m,const Inputs& i){
 const auto c=i.cx;const auto a=m.r8(c+0x1362);
 if(a){if(m.r8(c+0x1364)!=0)return 0;return 0x40;}
 if(m.r8(c+0x135e)!=0||m.r8(c+0x1363)!=0){if(m.r8(c+0x1364)!=0)return 0;return 0x40;}
 return m.r8(c+0x1364)==0?0x80u:0u;
}

uint32_t fun_00468690(Memory& m,const Inputs& i){
 const auto target=i.arg[0];if(!target)return 0;
 auto node=m.r32(i.cx+4);if(!node)return 0;
 if(node==target){const auto next=m.r32(node+0x30);m.w32(i.cx+4,next);return 0;}
 while(true){const auto next=m.r32(node+0x30);if(!next)return 0;if(next==target){m.w32(node+0x30,m.r32(next+0x30));return 0;}node=next;}
}
uint32_t fun_00476060(Memory& m,const Inputs& i){
 const auto bit=i.arg[0];if(bit==0||bit==1)return 0;
 const auto flags=m.r8(i.cx+(i.arg[1]?0x128u:0x124u));const auto mask=std::uint32_t{1}<<(bit&31u);
 return ((flags&mask)!=0)?0u:1u;
}
uint32_t fun_0047c440(Memory& m,const Inputs& i){
 const auto c=i.cx;if(m.r32(c+0x130)==1)m.w32(c+0x130,0);
 const auto counter=m.r32(c+0x130)-1u;m.w32(c+0x130,counter);
 auto flags=m.r32(c+0x12c);
 if((flags&8u)==0 || (flags&0x10u)==0){if(s32(counter)>0)return flags;flags|=0x18u;m.w32(c+0x12c,flags);return flags;}
 if(s32(counter)>0)return flags;
 flags=m.r32(c+0x140);if((flags&0x20u)!=0){flags&=~0x20u;m.w32(c+0x140,flags);}return flags;
}
uint32_t fun_0047c4a0(Memory& m,const Inputs& i){
 const auto c=i.cx;const auto old=m.r32(c+0x130);if(old==0xffffffffu)m.w32(c+0x130,0);
 auto value=m.r32(c+0x130)+1u;m.w32(c+0x130,value);const auto limit=m.r32(c+0x134);
 if(s32(value)>s32(limit)){m.w32(c+0x130,limit);value=limit;}
 if(s32(old)>0)return limit;
 value=m.r32(c+0x130);if(s32(value)<=0)return value;
 auto flags=m.r32(c+0x140)|0x20u;m.w32(c+0x140,flags);return flags;
}
uint32_t fun_004d1530(Memory&,const Inputs& i){const auto x=i.cx;if(x==0)return 0x6a2;if(x<=6)return 0x521u+x;return x==7?0x528u:0xffffffffu;}
uint32_t fun_004e0840(Memory& m,const Inputs& i){return m.r8(i.cx)==0?1u:0u;}
uint32_t fun_004e0880(Memory& m,const Inputs& i){
 auto a=i.cx,b=i.arg[0];while(true){auto x=m.r8(a),y=m.r8(b);if(x!=y)return x<y?0xffffff00u:0u;if(x==0)return 1;x=m.r8(a+1);y=m.r8(b+1);if(x!=y)return x<y?0xffffff00u:0u;if(x==0)return 1;a+=2;b+=2;}
}
uint32_t fun_004fe7b0(Memory& m,const Inputs& i){const auto x=(~m.r8(i.cx))&1u;return (m.r32(i.cx)&0xffffff00u)|x;}
uint32_t fun_004fe7c0(Memory& m,const Inputs& i){const auto x=((~m.r8(i.cx))>>1)&1u;return (m.r32(i.cx)&0xffffff00u)|x;}
uint32_t fun_004fe7d0(Memory& m,const Inputs& i){const auto x=((~m.r8(i.cx))>>2)&1u;return (m.r32(i.cx)&0xffffff00u)|x;}
uint32_t fun_005084f0(Memory& m,const Inputs& i){const auto p=m.r32(i.cx+0x5a8);return (p&0xffffff00u)|m.r8(p+0xc16);}
uint32_t fun_00521580(Memory& m,const Inputs& i){
 auto d=i.dx-1u;std::uint32_t e=1,threshold=8;while(s32(d)>=s32(threshold)){d-=threshold;threshold+=8u;e++;}
 std::uint32_t a,b;auto t=2*e+1;if(s32(d)<s32(t)){a=e;b=d-e;}
 else if(s32(d)<s32(4*e+1)){a=3*e-d;b=e;}
 else if(s32(d)<s32(6*e+1)){a=0u-e;b=5*e-d;}
 else {a=d-7*e;b=0u-e;}m.w32(i.cx,a);m.w32(i.cx+4,b);return i.cx;
}
uint32_t fun_0053b410(Memory& m,const Inputs& i){const auto p=i.arg[0];return (p&0xffffff00u)|m.r8(p+0xc);}
uint32_t fun_00547f90(Memory& m,const Inputs& i){
 const auto p=i.arg[0];auto x=m.r32(p),y=m.r32(p+4);x+=((x&0x80000000u)?0xffu:0u);y+=((y&0x80000000u)?0xffu:0u);x=sx16(sar(x,8));y=sx16(sar(y,8));
 const auto sum=x+y, lim=m.r32(i.cx+0xf0);if(s32(sum)<=s32(lim))return y&0xffffff00u;
 if(s32(x-y)>=s32(lim))return y&0xffffff00u;
 const auto diff=y-x;if(s32(diff)>=s32(lim))return diff&0xffffff00u;
 const auto factor=m.r32(i.cx+0xf4);const auto upper=lim+factor*2u;if(s32(sum)>s32(upper))return factor&0xffffff00u;
 return (factor&0xffffff00u)|1u;
}
uint32_t fun_00567690(Memory& m,const Inputs& i){
 auto value=m.r32(i.cx+0x144);if(s32(value)<13)return value;const auto count=m.r32(i.cx+0x13c);if(s32(count)<=0)return value;
 for(std::uint32_t n=0;n<count;++n){const auto p=m.r32(m.r32(i.cx+0x138)+n*4u);if(!p)continue;const auto v=sx8(m.r8(p+0x11b));const auto chosen=s32(value)<s32(v)?value:v;m.w32(i.cx+0x144,chosen);value=chosen&(s32(chosen)<=0?0u:0xffffffffu);m.w32(i.cx+0x144,value);}return m.r32(i.cx+0x144);
}
uint32_t fun_00591bd0(Memory& m,const Inputs& i){auto c=i.cx;m.w8(c+4,0);m.w8(c+5,0);m.w8(c+7,0);m.w8(c+6,1);m.w8(c+8,1);m.w8(c+9,1);m.w32(c+0x10,0xd2f1a9fc);m.w32(c+0x18,0xd2f1a9fc);m.w32(c,0xffffffff);m.w32(c+0x14,0x3f90624d);m.w32(c+0x1c,0x3f90624d);return c;}
uint32_t fun_005a42c0(Memory& m,const Inputs& i){
 auto pos=i.dx;auto eax=m.r8(pos++);if(eax!=2)return eax;
 auto b=m.r8(pos++);std::uint32_t run;if(!(b&0x80u)){run=b;eax=run;}else{run=b&0x7fu;eax=run;if(run>2)return eax;auto lo=m.r8(pos++);run=lo;if((b&0x7fu)>1){auto hi=m.r8(pos++);run=(run<<8)|hi;eax=(eax&0xffffff00u)|hi;}}
 const auto cap=i.arg[0]*4u;if(run>cap)return eax;const auto color=m.r8(pos);const auto fill=(color&0x80u)?0xffu:0u;auto out=i.cx+cap;std::uint32_t remain=cap-run;while(remain){m.w8(--out,fill);--remain;}
 eax=(eax&0xffffff00u)|fill;if(run==0)return eax;auto p=pos;while(run){m.w8(--out,m.r8(p++));--run;}return eax;
}
uint32_t fun_005aa400(Memory& m,const Inputs& i){m.w32(i.cx+0x40,0);m.w32(i.cx+0x28,i.arg[0]);return i.arg[0];}
uint32_t fun_005c30c0(Memory&,const Inputs& i){const auto x=i.cx;if(x==0)return 0x411;if(x<=6)return 0x411u+x;return x==7?0x418u:0xffffffffu;}
uint32_t fun_00608eb0(Memory& m,const Inputs& i){const auto s=i.dx;const auto adjusted=s+((s&0x80000000u)?1u:0u);const auto delta=0u-sar(adjusted,1);m.w32(i.cx,i.arg[0]+delta);m.w32(i.cx+4,i.arg[1]+delta);m.w32(i.cx+8,s);m.w32(i.cx+0xc,s);return i.cx;}
uint32_t fun_00609050(Memory& m,const Inputs& i){const auto count=m.r32(i.cx+0x10);if(s32(count)<=0)return 0;const auto a=m.r32(i.cx+4);for(std::uint32_t n=0;n<count;++n){const auto p=m.r32(a+n*4u);if(m.r32(p)==i.arg[0])return p;}return 0;}
uint32_t fun_00609150(Memory& m,const Inputs& i){const auto count=m.r32(i.cx+0x10);std::uint32_t found=0;if(s32(count)>0){const auto arr=m.r32(i.cx+4);for(std::uint32_t n=0;n<count;++n){const auto p=m.r32(arr+n*4u);if(m.r32(p)==i.arg[0]){found=p;break;}}}const auto ix=m.r32(found+8);return ix==0xffffffffu?0:m.r32(m.r32(i.cx+0x24)+ix*4u);}
uint32_t fun_00617f70(Memory& m,const Inputs& i){return m.r32(i.cx+0x64)!=0?1u:0u;}
uint32_t fun_00619dc0(Memory&,const Inputs& i){return i.cx+i.arg[0]*4u;}
uint32_t fun_0062cc50(Memory& m,const Inputs& i){const auto c=i.cx;m.w32(c+0x10,0);m.w8(c,0);m.w8(c+1,1);m.w32(c+4,0);m.w32(c+8,i.arg[0]);m.w32(c+0x14,0);for(auto o:{0x18u,0x19u,0x1au})m.w8(c+o,0);for(auto o:{0x1cu,0x20u,0x24u,0x28u,0x2cu,0x30u,0x38u,0x40u,0x34u,0x3cu,0x44u,0x48u,0x6cu})m.w32(c+o,0);for(auto o:{0xb0u,0xb1u,0xb2u})m.w8(c+o,0);return c;}
uint32_t fun_006502d0(Memory& m,const Inputs& i){const auto c=i.cx;m.w32(c,0);m.w32(c+4,0);m.w32(c+0x188,0xffffffff);m.w32(c+0x18c,0);m.w32(c+0x3f0,0);m.w16(c+8,0);m.w16(c+0x108,0);for(auto o:{0x190u,0x294u,0x2d4u})m.w8(c+o,0);for(auto o:{0x3d8u,0x3dcu,0x3e0u,0x3e4u,0x3e8u,0x3ecu})m.w32(c+o,0);return c;}
uint32_t fun_00692e00(Memory& m,const Inputs& i){const auto p=m.r32(i.cx+0x24);return (p&0xffffff00u)|m.r8(p+0xde);}
uint32_t fun_00697d80(Memory& m,const Inputs& i){
 const auto x=i.arg[0],y=i.arg[1];
 const auto half=[](std::uint32_t v){return sar(v+((v&0x80000000u)?1u:0u),1);};
 const auto outx=half(x*60u)+half(0u-y*60u),outy=half(x*30u)+half(y*30u);
 m.w32(i.cx,outx);m.w32(i.cx+4,outy);return i.cx;
}
uint32_t fun_006a2350(Memory& m,const Inputs& i){const auto count=m.r32(i.cx+0x10);if(s32(count)<=0)return 0xffffffff;const auto arr=m.r32(i.cx+4),p=i.arg[0];for(std::uint32_t n=0;n<count;++n){const auto q=arr+n*0x14u;if(m.r8(q+0x10)==m.r8(p+0x10)&&m.r32(q)==m.r32(p)&&m.r32(q+4)==m.r32(p+4)&&m.r32(q+8)==m.r32(p+8)&&m.r32(q+0xc)==m.r32(p+0xc))return n;}return 0xffffffff;}
uint32_t fun_006d4c20(Memory& m,const Inputs& i){return m.r32(i.cx+0x710+i.arg[0]*4u);}
uint32_t fun_006e11a0(Memory& m,const Inputs& i){return m.r32(i.cx+4)!=0?1u:0u;}
uint32_t fun_006e1610(Memory& m,const Inputs& i){const auto count=i.dx;if(s32(count)<=0)return 0;const auto key=m.r32(i.arg[0]);std::uint32_t lo=0,hi=count;while(lo<hi){const auto mid=lo+(hi-lo)/2u;const auto p=i.cx+mid*8u;const auto v=m.r32(p);if(v==key)return p;if(v<key)lo=mid+1u;else hi=mid;}return 0;}
uint32_t fun_006ebaf0(Memory& m,const Inputs& i){const auto count=m.r32(i.cx+0x10);if(s32(count)<=0)return 0xffffffff;const auto arr=m.r32(i.cx+4);for(std::uint32_t n=0;n<count;++n){auto a=i.dx,b=m.r32(arr+n*4u);while(true){const auto x=m.r8(a),y=m.r8(b);if(x!=y)break;if(x==0)return n;++a;++b;}}return 0xffffffff;}
uint32_t fun_00720f50(Memory& m,const Inputs& i){const auto x=m.r32(i.cx+0x44);return (x&0xffffff00u)|(x!=0?1u:0u);}
uint32_t fun_007254c0(Memory& m,const Inputs& i){const auto holder=m.r32(i.cx+0xc),src=m.r32(i.cx+0x10);if(!holder||!src)return 0;auto left=m.r32(holder+0x20);auto p=src;auto wanted=i.arg[0];std::uint32_t hits=0;while(left){const auto b=m.r8(p++);if(b==1&&wanted==2)++hits;else if(b==2&&wanted==3)++hits;--left;}return hits;}
uint32_t fun_0072e510(Memory& m,const Inputs& i){const auto c=i.cx;const auto count=m.r32(c+0x10),newcount=i.arg[0],idx=i.arg[1];if(newcount==count){if(idx!=2)return count;const auto flag=m.r8(c+0x14);if(flag==0){m.w8(c+0x14,1);m.w8(c+8,1);}return (count&0xffffff00u)|flag;}const auto oldidx=m.r32(c+0x18);const bool ok=(count==0)||(s32(idx)>=s32(oldidx));if(ok&&newcount!=0){if(idx==3)m.w8(c+0x14,0);m.w32(c+0x10,newcount);m.w32(c+0x18,idx);m.w8(c+8,1);}return count;}
uint32_t fun_00759340(Memory& m,const Inputs& i){auto a=m.r32(i.cx),b=i.arg[0];if(!a&&!b)return 1;if(!a)return 0;if(!b)return a&0xffffff00u;while(true){auto x=m.r8(a),y=m.r8(b);if(x!=y)return x<y?0xffffff00u:0u;if(!x)return 1;x=m.r8(a+1);y=m.r8(b+1);if(x!=y)return x<y?0xffffff00u:0u;if(!x)return 1;a+=2;b+=2;}}
uint32_t fun_007593b0(Memory& m,const Inputs& i){auto a=m.r32(i.cx),bp=i.arg[0];auto b=m.r32(bp);if(!a&&!b)return 1;if(!a)return 0;if(!b)return a&0xffffff00u;while(true){auto x=m.r8(a),y=m.r8(b);if(x!=y)return x<y?0xffffff00u:0u;if(!x)return 1;x=m.r8(a+1);y=m.r8(b+1);if(x!=y)return x<y?0xffffff00u:0u;if(!x)return 1;a+=2;b+=2;}}
uint32_t fun_00767d80(Memory& m,const Inputs& i){const auto d=i.dx?i.dx:0x763d70u, p=i.arg[0]?i.arg[0]:0x763d70u;m.w32(i.cx+0x784,d);m.w32(i.cx+0x788,p);return 0xffffffffu;}
uint32_t fun_00777239(Memory&,const Inputs& i){switch(i.arg[0]){case 0x3a4:return 0x411;case 0x3a8:return 0x804;case 0x3b5:return 0x412;case 0x3b6:return 0x404;default:return 0;}}
uint32_t fun_0077e917(Memory& m,const Inputs& i){auto p=i.arg[0];const auto count=i.arg[1];if(count==0){(void)m.r16(p);return 0;}std::uint32_t n=0;while(n<count&&m.r16(p+n*2u)!=0)++n;if(n<count)return n;(void)m.r16(p+count*2u);return count;}

} // namespace ra2::recovered::leaf
