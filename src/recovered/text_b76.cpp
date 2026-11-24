#include "recovered/text_b76.hpp"
#include "recovered/text_b68.hpp"
#include "recovered/text_bytes.hpp"
#include <algorithm>
#include <vector>
namespace ra2::recovered::text_b76 {
using namespace global_b26;
using U=std::uint32_t;
std::uint32_t fun_004090e0(Memory&m,const Inputs&i){
 const U o=i.cx;U left=m.r32(o+0x34)-m.r32(o+0x38)-m.r32(o+0x2c);
 if(!left){m.w32(o+8,0);return 0;}
 const U amount=std::min(left,i.dx),index=m.r32(o+0x14)*8+0x20,segment=m.r32(o+0xc);
 auto available=[&](){U a=left;if(!(m.r8(o+0x10)&1))a=std::min(a,m.r32(segment+index+4)-m.r32(o+4)+m.r32(segment+index));return a;};
 if(amount>=available())throw std::domain_error("90e0 segment transition excluded");
 m.w32(o+4,m.r32(o+4)+amount);left-=amount;m.w32(o+8,available());
 const U total=m.r32(o+0x2c)+amount,cursor=m.r32(o+0x30)+amount,cycle=m.r32(m.r32(o)+0x14);
 m.w32(o+0x2c,total);m.w32(o+0x30,cursor>=cycle?cursor%cycle:cursor);
 if(total&&!m.r32(o+0x18))throw std::domain_error("90e0 refill excluded");return amount;
}
std::uint32_t fun_004315d0(Memory&m,const Inputs&i){
 const U object=i.cx,font=m.r32(object+4);U p=i.arg[0],width=0,count=0;
 if(!font||!p)return 0;
 while(const U ch=m.r16(p)){
  if(ch==9){const U tab=m.r32(object+0x28);width+=tab;width-=idiv_remainder(width,tab);}
  else if(ch!=10&&ch!=13){const U glyph=m.r16(m.r32(font+0x18)+ch*2);U data=glyph?m.r32(font+0x1c)+(glyph-1)*m.r32(font+0x14):0;if(!data)data=m.r32(object+8);if(data)width+=m.r8(data)+m.r32(object+0x2c);}
  ++count;
  if(s32(width)>s32(i.arg[1])){--count;if(i.arg[3]&&ch>32){U q=p-2,c=count;while(c&&m.r16(q)>32){--c;q-=2;}if(c)count=c;}return count;}
  if((i.arg[2]&&count==i.arg[2])||(i.arg[3]&&(ch==10||ch==13)))return count;
  p+=2;i.arg[0]=p;
 }
 return count;
}
std::uint32_t fun_005b27c0(Memory&m,const Inputs&i){
 const U lower=i.arg[2],src=i.arg[1],dst=i.arg[0];if(s32(lower)<=0)return 0;
 std::vector<std::uint16_t> units;for(U p=src;;p+=2){auto x=std::uint16_t(m.r16(p));units.push_back(x);if(!x)break;}
 const U length=ra2::recovered::fun_0076ef45(units.data());const U maximum=std::min(i.arg[3],length);i.arg[2]=length;U boundary=lower;
 if(!i.arg[4]){for(U b=lower;b<=maximum;++b){U ch=m.r16(src+2*b-2);if(ch&&ch<=32){boundary=b;break;}}}
 else {for(U b=maximum;b>=lower;--b){U ch=m.r16(src+2*b-2);if(ch&&ch<=32){boundary=b;break;}}}
 if(dst){for(U k=0;k<2*boundary;++k)m.w8(dst+k,m.r8(src+k));m.w16(dst+2*boundary,0);}
 Inputs a;a.arg={src,src+2*boundary,2*(length-boundary+1)};global_b26::fun_0076ebd0(m,a);return boundary;
}
std::uint32_t fun_00761e20(Memory&m,const Inputs&i){
 const U o=i.cx,dst=m.r32(o+0x78c),pending=m.r32(o+0x7b0);
 if(!(m.r8(o+0x84)&1)||!dst||!pending)return 0xffffffffu;
 const U offset=m.r32(o+0x7ac),src=m.r32(o+0x7a8)+offset,n=pending-offset,pos=m.r32(o+0x790),unit=m.r32(o+0x9c),blocks=m.r32(o+0x79c),flags=m.r32(o+0x794);
 U end=(pos+n)/unit;const U start=pos/unit;if(end>=blocks)end-=blocks;
 if(m.r8(flags+end)==1){m.w32(o+0x18c,m.r32(o+0x18c)+1);return 0xfffffff5u;}
 if(start<=end){for(U k=0;k<n;++k)m.w8(dst+pos+k,m.r8(src+k));m.w32(o+0x790,pos+n);for(U k=start;k<end;++k)m.w8(flags+k,1);}
 else {const U tail=m.r32(o+0x98)-pos;for(U k=0;k<tail;++k)m.w8(dst+pos+k,m.r8(src+k));for(U k=tail;k<n;++k)m.w8(dst+k-tail,m.r8(src+k));m.w32(o+0x790,n-tail);for(U k=start;k<blocks;++k)m.w8(flags+k,1);for(U k=0;k<end;++k)m.w8(flags+k,1);}
 m.w32(o+0x7b0,0);m.w32(o+0x7ac,0);return 0xffffffffu;
}
std::uint32_t fun_00779c50(Memory&m,const Inputs&i){
 U p=i.arg[0],list=i.arg[1],out=i.arg[2];const U argc=i.arg[3],chars=i.arg[4];m.w32(chars,0);m.w32(argc,1);
 auto emit=[&](U ch){if(out)m.w8(out++,ch);m.w32(chars,m.r32(chars)+1);};
 auto pointer=[&](){if(list){m.w32(list,out);list+=4;i.arg[1]=list;}};
 auto lead=[&](U ch){return (m.r8(0xb10be1+ch)&4)!=0;};pointer();
 if(m.r8(p)==34){++p;while(m.r8(p)&&m.r8(p)!=34){if(lead(m.r8(p))){m.w32(chars,m.r32(chars)+1);if(out)m.w8(out++,m.r8(p++));}emit(m.r8(p++));}emit(0);if(m.r8(p)==34)++p;}
 else {U ch;do{ch=m.r8(p++);emit(ch);if(lead(ch)){emit(m.r8(p++));}}while(ch&&ch!=32&&ch!=9);if(!ch)--p;else if(out)m.w8(out-1,0);}
 i.arg[4]=0;
 for(;;){while(m.r8(p)==32||m.r8(p)==9)++p;if(!m.r8(p))break;pointer();m.w32(argc,m.r32(argc)+1);
  for(;;){i.arg[0]=1;U slashes=0;while(m.r8(p)==92){++slashes;++p;}
   if(m.r8(p)==34){if(!(slashes&1)){if(i.arg[4]&&m.r8(p+1)==34)++p;else i.arg[0]=0;i.arg[4]=!i.arg[4];}slashes>>=1;}
   for(U k=0;k<slashes;++k)emit(92);const U ch=m.r8(p);if(!ch||(!i.arg[4]&&(ch==32||ch==9)))break;
   if(i.arg[0]){if(lead(ch))emit(m.r8(p++));emit(m.r8(p));}++p;
  }emit(0);
 }
 if(list)m.w32(list,0);m.w32(argc,m.r32(argc)+1);return argc;
}
}
