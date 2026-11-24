#include "numeric_b88.hpp"
#include "numeric_b88_detail.hpp"
#include "leaf_b15_d.hpp"
#include <algorithm>
#include <array>
#include <cstring>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::numeric_b88 {
namespace {
void fimul32(ra2::platform::x87::State&f,std::uint32_t value){
    f.require_masked();ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[value]\n\tfnsave %[guest]\n\tfrstor %[host]"
        :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[value]"m"(value)
        :"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
void fdivr_st0_st1(ra2::platform::x87::State&f){
    f.require_masked();ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte 0xd8,0xf9\n\tfnsave %[guest]\n\tfrstor %[host]"
        :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes)::"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
std::uint32_t float_bits(float v){std::uint32_t b;std::memcpy(&b,&v,sizeof b);return b;}
std::array<std::uint32_t,3> transform_point(Memory&m,ra2::platform::x87::State&f,std::uint32_t matrix,
                     std::uint32_t x,std::uint32_t y,std::uint32_t z){
    std::array<std::uint32_t,3> result{};
    for(unsigned row=0;row<3;++row){
        if(row==0){
            f.load32(m.r32(matrix+8u));f.multiply32(z);
            f.load32(m.r32(matrix+4u));f.multiply32(y);f.add_pop();
            f.load32(m.r32(matrix));f.multiply32(x);f.add_pop();
        }else{
            f.load32(m.r32(matrix+row*16u));f.multiply32(x);
            f.load32(m.r32(matrix+row*16u+8u));f.multiply32(z);f.add_pop();
            f.load32(m.r32(matrix+row*16u+4u));f.multiply32(y);f.add_pop();
        }
        f.add32(m.r32(matrix+row*16u+12u));result[row]=f.pop32();
    }
    return result;
}
std::uint32_t call_leaf_30e420(Memory&m,std::uint32_t receiver,std::uint32_t arg0,std::uint32_t arg1){
    const auto array=m.r32(receiver+0x10u),base_value=m.r32(receiver+0x14u);
    const auto indexed=array+arg0*12u;
    const auto low=std::min({receiver+0x10u,receiver+0x14u,indexed});
    const auto high=std::max({receiver+0x14u,indexed+4u,receiver+0x14u+4u});
    std::vector<std::uint8_t> bytes(high-low,0);
    auto put=[&](std::uint32_t address,std::uint32_t value){for(unsigned b=0;b<4;++b)bytes[address-low+b]=std::uint8_t(value>>(b*8));};
    put(receiver+0x10u,array);put(receiver+0x14u,base_value);put(indexed,m.r32(indexed));
    ra2::recovered::leaf::Memory leaf_memory(bytes.data(),low,static_cast<std::uint32_t>(bytes.size()));
    ra2::recovered::leaf::Inputs leaf_inputs;leaf_inputs.cx=receiver;leaf_inputs.arg[0]=arg1;leaf_inputs.arg[1]=arg0;
    return ra2::recovered::leaf::fun_0070e420(leaf_memory,leaf_inputs);
}
}

std::uint32_t fun_004ba810(Memory& m,const Inputs& i) {
    using namespace detail;
    auto& f=i.fp;
    const auto a=i.arg[0],b=i.arg[1],eps=m.r32(0x785738u);
    std::uint32_t eax=i.ax;
    auto fnstsw_ax=[&](){eax=(eax&0xffff0000u)|f.status();};

    // The two equality/sentinel returns retain the incoming high EAX word;
    // each original FNSTSW AX replaces only its low word.
    f.load32(b);f.compare_pop32(eps);f.load32(a);fnstsw_ax();
    if(eax&0x4000u) {
        f.compare_pop32(eps);fnstsw_ax();
        if(eax&0x4000u) {f.load32(eps);return eax;}
        f.load32(m.r32((eax&0x4100u)?0x78bf90u:0x78bf8cu));
        return eax;
    }

    ext::divide32(f,b);
    ext::divide32(f,m.r32(0x800138u));
    const auto rounded=integer(m,f);
    const auto index=s32(rounded)<0?0u-rounded:rounded;
    eax=index;
    if(index<0x1001u)f.load32(m.r32(0x7fc134u+index*4u));
    else f.load32(m.r32(0x78bf8cu));

    f.load32(b);f.compare_pop32(eps);fnstsw_ax();
    if(eax&0x0100u)f.reverse_subtract64(read64(m,0x788158u));
    f.load32(a);f.compare_pop32(eps);fnstsw_ax();
    if(eax&0x0100u)f.change_sign();
    return eax;
}

std::uint32_t fun_0047ddc0(Memory&m,const Inputs&i){
    using namespace detail;
    const auto scalar=i.cx,record=i.dx;std::uint32_t esi=scalar;
    auto&f=i.fp;
    auto& raw_stack=const_cast<Inputs&>(i).stack_minus8;
    raw_stack=scalar;
    const auto flag_ptr=m.r32(0xa255c0u);
    if(scalar==0||(m.r8(flag_ptr)&0x20u)||record==0)return 0;
    if(s32(scalar)<0)return s32(i.arg[1])>=8?0u:scalar;

    f.load_integer32(scalar);
    const auto scalar_float=f.store32();
    f.multiply32(m.r32(record+0x12cu));
    const auto product=f.pop32();
    raw_stack=product;
    f.load32(m.r32(record+0x124u));f.multiply32(m.r32(0x7860acu));
    auto denominator=integer(m,f);
    f.load32(product);f.compare_pop32(scalar_float);
    if(!(f.status()&0x4000u)&&denominator!=0){
        f.load32(scalar_float);f.subtract32(product);
        i.arg[1]=denominator-i.arg[1];
        fimul32(f,i.arg[1]);
        f.divide_integer32(denominator);
        f.add32(product);
        esi=integer(m,f);
    }
    const auto signed_value=s32(esi);
    const auto table_index=i.arg[0];
    i.arg[1]=(signed_value>0)?esi:0u;
    f.load_integer32(i.arg[1]);
    f.multiply64(read64(m,record+0xa0u+table_index*8u));
    const auto result=integer(m,f);
    const auto max=m.r32(m.r32(0x821b88u)+0x1330u);
    return s32(result)<s32(max)?result:max;
}

std::uint32_t fun_006aff30(Memory&m,const Inputs&i){
    using namespace detail;
    const auto count=m.r32(0x84e4b8u);
    if(s32(count)<=0)return count;
    const auto array=m.r32(0x84e4acu);
    std::uint32_t matched=0;
    for(std::uint32_t n=0;n<count;++n){
        const auto object=m.r32(array+n*4u);
        if(!object||m.r32(object+0x2cu)!=i.dx)continue;
        const auto time_record=m.r32(object+0x24u);
        if(s32(m.r32(time_record+0xb4u))>=s32(i.cx))continue;
        // The observed child-empty route jumps over the missing 0x2ae600 call.
        if(m.r32(object+0x54u)!=0)continue;
        m.w8(object+0x7eu,1);m.w8(object+0x7du,1);
        const auto clock=m.r32(0x821b88u);
        i.fp.load64(read64(m,clock+0x1150u));
        i.fp.multiply64(read64(m,0x786608u));
        const auto timestamp=integer(m,i.fp);
        m.w32(object+0x64u,m.r32(0xa2896cu));
        m.w32(object+0x68u,i.stack_minus8);
        m.w32(object+0x6cu,timestamp);
        m.w8(object+0x82u,1);
        ++matched;
    }
    return count;
}

std::uint32_t fun_0062d5c0(Memory&m,const Inputs&i){
    using namespace detail;
    const auto o=i.cx;
    const auto base=m.r32(o+0x34u),phase=m.r32(o+0x6cu);
    const auto half=half_toward_zero(base);
    std::uint32_t numerator;
    if(s32(phase)<s32(half)){
        numerator=phase+phase;i.fp.load_integer32(numerator);
    }else{
        const auto twice=phase+phase;
        const auto rem=static_cast<std::uint32_t>(s32(twice)%s32(base));
        numerator=base-rem;i.fp.load_integer32(numerator);
    }
    i.fp.load_integer32(base);fdivr_st0_st1(i.fp);
    const auto step=m.r32(o+0x48u)*phase;
    i.fp.multiply64(read64(m,o+0x38u));
    write64(m,o+0x70u,i.fp.pop64());i.fp.pop_st0();
    i.fp.load_integer32(step);i.fp.multiply64(read64(m,o+0x40u));
    const auto increment=integer(m,i.fp);
    const auto vx=m.r32(o+0x60u)*increment,vy=m.r32(o+0x64u)*increment,vz=m.r32(o+0x68u)*increment;
    const auto x=m.r32(o+0x4cu)+vx,y=m.r32(o+0x50u)+vy,z=m.r32(o+0x54u)+vz;
    m.w32(o+0x4cu,x);m.w32(o+0x50u,y);m.w32(o+0x54u,z);
    const auto norm=x*x+y*y+z*z;
    i.fp.load_integer32(norm);const auto norm64=i.fp.pop64();
    root(m,i.fp,norm64);write64(m,o+0x58u,i.fp.store64());
    i.fp.divide64(read64(m,o+0x10u));const auto divisor=integer(m,i.fp);
    m.w32(o+0x7cu,divisor);
    std::uint32_t ox=x,oy=y,oz=z;
    if(s32(divisor)!=0){ox=std::uint32_t(s32(x)/s32(divisor));oy=std::uint32_t(s32(y)/s32(divisor));oz=std::uint32_t(s32(z)/s32(divisor));}
    m.w32(o+0x80u,ox);m.w32(o+0x84u,oy);m.w32(o+0x88u,oz);return divisor?oz:0;
}

std::uint32_t fun_00698230(Memory&m,const Inputs&i){
    using namespace detail;
    const auto out=i.arg[0],pair=i.arg[1];
    const auto x=m.r32(pair),y=m.r32(pair+4u);
    i.arg[1]=x;
    if(s32(x)>=s32(m.r32(0xaa6070u))||s32(y)>=s32(m.r32(0xaa6074u))){
        m.w32(out,m.r32(0xaa6048u));m.w32(out+4u,m.r32(0xaa604cu));m.w32(out+8u,m.r32(0xaa6050u));return out;
    }
    const auto tx=i.cx+0xde4u;
    i.fp.load_integer32(x);const auto xf=i.fp.pop32();
    i.fp.load_integer32(y);const auto yf=i.fp.pop32();
    const auto transformed=transform_point(m,i.fp,tx,xf,yf,0);
    i.fp.load32(transformed[0]);const auto rx=integer(m,i.fp);
    i.fp.load32(transformed[1]);const auto ry=integer(m,i.fp);
    m.w32(out,rx);m.w32(out+4u,ry);m.w32(out+8u,0);return out;
}

std::uint32_t fun_005cd720(Memory&m,const Inputs&i){
    using namespace detail;
    const auto count=m.r32(i.cx+0x10u),list=m.r32(i.cx+4u),point=i.dx;
    std::uint32_t best_distance=0x05f5e0ffu,best_record=0;
    for(std::uint32_t remaining=count;remaining;--remaining){
        const auto record=m.r32(list+(remaining-1u)*4u);
        const auto coords=record+0x88u;
        const auto dx=m.r32(point)-m.r32(coords),dy=m.r32(point+4u)-m.r32(coords+4u),dz=m.r32(point+8u)-m.r32(coords+8u);
        i.fp.load_integer32(dy);i.fp.load_integer32(dz);i.fp.load_integer32(dx);
        if(remaining==count){
            reg<0xd9c1>(i.fp);reg<0xd8ca>(i.fp);
            reg<0xd9c3>(i.fp);reg<0xd8cc>(i.fp);i.fp.add_pop();
            reg<0xd9c1>(i.fp);reg<0xd8ca>(i.fp);i.fp.add_pop();
        }else{
            i.fp.load_st0();reg<0xd8c9>(i.fp);
            i.fp.load_st2();reg<0xd8cb>(i.fp);i.fp.add_pop();
            reg<0xd9c3>(i.fp);reg<0xd8cc>(i.fp);i.fp.add_pop();
        }
        const auto square_sum=i.fp.pop64();
        i.fp.pop_st0();i.fp.pop_st0();i.fp.pop_st0();
        root(m,i.fp,square_sum);
        const auto distance=integer(m,i.fp);
        if(remaining==count){best_distance=distance;best_record=record;continue;}
        if(s32(distance)<s32(best_distance)){best_distance=distance;best_record=record;}
    }
    return best_record;
}

std::uint32_t fun_006d4c30(Memory&m,const Inputs&i){
    using namespace detail;
    const auto o=i.cx,out=i.arg[0];
    if(m.r8(o+0x6d0u)==0){
        m.w32(out,m.r32(o+0x6c4u));m.w32(out+4u,m.r32(o+0x6c8u));m.w32(out+8u,m.r32(o+0x6ccu));return out;
    }
    const auto x=m.r32(o+0x6c4u),y=m.r32(o+0x6c8u),scalar=m.r32(o+0x6ccu);
    const auto matrix=m.r32(0x821cacu)+0xde4u;
    // The helper inputs are signed integers converted to single-precision;
    // zero in the third coordinate leaves only x/y contributions.
    i.fp.load_integer32(x);const auto xf=i.fp.pop32();
    i.fp.load_integer32(y);const auto yf=i.fp.pop32();
    const auto transformed=transform_point(m,i.fp,matrix,xf,yf,float_bits(0.0f));
    i.fp.load32(transformed[0]);const auto tx=integer(m,i.fp);
    i.fp.load32(transformed[1]);const auto ty=integer(m,i.fp);
    const auto tenth=scalar*10u;
    std::uint32_t tx2=tx-tenth,ty2=ty-tenth;
    i.fp.load_integer32(tenth);i.fp.load_st0();reg<0xd8c9>(i.fp);reg<0xd8c0>(i.fp);
    const auto radicand=i.fp.pop64();i.fp.pop_st0();root(m,i.fp,radicand);
    i.fp.multiply64(read64(m,0x798010u));
    const auto magnitude=integer(m,i.fp);
    const auto z=s32(scalar)<0?magnitude:0u-magnitude;
    m.w32(out,tx2);m.w32(out+4u,ty2);m.w32(out+8u,z);return out;
}

std::uint32_t fun_0070bf20(Memory&m,const Inputs&i){
    using namespace detail;
    const auto source=call_leaf_30e420(m,i.cx,i.arg[0],i.dx);
    const auto index=m.r32(0xacaa80u),record=0xadae88u+index*72u;
    m.w32(record,i.cx);m.w32(record+4u,i.dx);m.w32(record+8u,i.arg[0]);
    m.w32(record+0x3cu,i.arg[4]);m.w32(record+0x40u,i.arg[5]);m.w32(record+0x44u,i.arg[6]);
    const auto addition=i.arg[3];
    for(std::uint32_t k=0;k<4;++k){
        const auto dst=record+0x0cu+k*12u;
        const auto first=transform_point(m,i.fp,i.arg[2],
            m.r32(source+0x40u+k*12u),m.r32(source+0x44u+k*12u),m.r32(source+0x48u+k*12u));
        m.w32(dst,first[0]);m.w32(dst+4u,first[1]);m.w32(dst+8u,0);
        const auto second=transform_point(m,i.fp,i.arg[1],
            m.r32(dst),m.r32(dst+4u),m.r32(dst+8u));
        m.w32(dst,second[0]);m.w32(dst+4u,second[1]);m.w32(dst+8u,second[2]);
        for(unsigned c=0;c<3;++c){
            i.fp.load32(m.r32(addition+c*4u));i.fp.add32(m.r32(dst+c*4u));m.w32(dst+c*4u,i.fp.pop32());
        }
        i.fp.load32(m.r32(dst+4u));i.fp.change_sign();m.w32(dst+4u,i.fp.pop32());
        const auto x=m.r32(dst),y=m.r32(dst+4u);
        i.fp.load32(x);i.fp.compare_pop32(m.r32(0xac84f0u));if(i.fp.status()&0x0100u)m.w32(0xac84f0u,x);
        i.fp.load32(y);i.fp.compare_pop32(m.r32(0xac84f4u));if(i.fp.status()&0x0100u)m.w32(0xac84f4u,y);
        i.fp.load32(x);i.fp.compare_pop32(m.r32(0xac8858u));if((i.fp.status()&0x4100u)==0)m.w32(0xac8858u,x);
        i.fp.load32(y);i.fp.compare_pop32(m.r32(0xac885cu));if((i.fp.status()&0x4100u)==0)m.w32(0xac885cu,y);
    }
    const auto updated=index+1u;m.w32(0xacaa80u,updated);return updated;
}

std::uint32_t fun_0070c080(Memory&m,const Inputs&i){
    using namespace detail;
    const auto source=call_leaf_30e420(m,i.cx,i.arg[0],i.dx);
    const auto index=m.r32(0xac8730u),record=0xac8868u+index*136u;
    m.w32(record,i.cx);m.w32(record+4u,i.dx);m.w32(record+8u,i.arg[0]);
    const auto large=0x461c4000u,negative=0xc61c4000u;
    for(unsigned c=0;c<3;++c){m.w32(record+0x10u+c*4u,large);m.w32(record+0x1cu+c*4u,negative);}
    for(std::uint32_t k=0;k<8;++k){
        const auto dst=record+0x28u+k*12u;
        const auto result=transform_point(m,i.fp,i.arg[1],
            m.r32(source+0x40u+k*12u),m.r32(source+0x44u+k*12u),m.r32(source+0x48u+k*12u));
        m.w32(dst,result[0]);m.w32(dst+4u,result[1]);m.w32(dst+8u,result[2]);
        i.fp.load32(m.r32(dst+4u));i.fp.change_sign();m.w32(dst+4u,i.fp.pop32());
        const auto x=m.r32(dst),y=m.r32(dst+4u),z=m.r32(dst+8u);
        if(i.fp.load32(x),i.fp.compare_pop32(m.r32(record+0x10u)),i.fp.status()&0x0100u)m.w32(record+0x10u,x);
        if(i.fp.load32(x),i.fp.compare_pop32(m.r32(record+0x1cu)),(i.fp.status()&0x4100u)==0)m.w32(record+0x1cu,x);
        if(i.fp.load32(y),i.fp.compare_pop32(m.r32(record+0x14u)),i.fp.status()&0x0100u)m.w32(record+0x14u,y);
        if(i.fp.load32(y),i.fp.compare_pop32(m.r32(record+0x20u)),(i.fp.status()&0x4100u)==0)m.w32(record+0x20u,y);
        if(i.fp.load32(z),i.fp.compare_pop32(m.r32(record+0x18u)),i.fp.status()&0x0100u){m.w32(record+0x0cu,k);m.w32(record+0x18u,z);}
        if(i.fp.load32(z),i.fp.compare_pop32(m.r32(record+0x24u)),(i.fp.status()&0x4100u)==0)m.w32(record+0x24u,z);
    }
    for(unsigned c=0;c<3;++c){
        const auto global=0xac84f0u+c*4u,mn=m.r32(record+0x10u+c*4u);
        i.fp.load32(mn);i.fp.compare_pop32(m.r32(global));if(i.fp.status()&0x0100u)m.w32(global,mn);
    }
    for(unsigned c=0;c<3;++c){
        const auto global=0xac8858u+c*4u,mx=m.r32(record+0x1cu+c*4u);
        i.fp.load32(mx);i.fp.compare_pop32(m.r32(global));if((i.fp.status()&0x4100u)==0)m.w32(global,mx);
    }
    const auto updated=index+1u;m.w32(0xac8730u,updated);return updated;
}

std::uint32_t fun_005b43c0(Memory&m,const Inputs&i){
    using namespace detail;
    const auto desc=i.arg[2],flags=i.arg[3],count=m.r32(desc+0x10u),items=m.r32(desc+4u);
    bool has_set=false,has_clear=false;
    for(std::uint32_t k=0;k<count;++k){if(m.r8(flags+k))has_set=true;else has_clear=true;}
    if(!has_set||!has_clear)return 0;
    std::int32_t best_score=-1;std::uint32_t best_index=0xffffffffu;
    for(std::uint32_t candidate=0;candidate<count;++candidate){
        if(m.r8(flags+candidate))continue;
        std::int32_t score=0;
        for(std::uint32_t target=0;target<count;++target){
            if(!m.r8(flags+target))continue;
            const auto a=items+candidate*4u,b=items+target*4u;
            const auto dx=static_cast<std::int16_t>(std::uint16_t(m.r16(a))-std::uint16_t(m.r16(b)));
            const auto dy=static_cast<std::int16_t>(std::uint16_t(m.r16(a+2u))-std::uint16_t(m.r16(b+2u)));
            const auto ux=static_cast<std::uint32_t>(static_cast<std::int32_t>(dx));
            const auto uy=static_cast<std::uint32_t>(static_cast<std::int32_t>(dy));
            i.fp.load_integer32(ux);i.fp.load_integer32(uy);
            i.fp.load_st0();reg<0xd8c9>(i.fp);i.fp.load_st2();reg<0xd8cb>(i.fp);i.fp.add_pop();
            const auto square_sum=i.fp.pop64();i.fp.pop_st0();i.fp.pop_st0();root(m,i.fp,square_sum);
            score+=static_cast<std::int16_t>(integer(m,i.fp));
        }
        if(score>best_score){best_score=score;best_index=candidate;}
    }
    if(best_index==0xffffffffu)return 0;
    m.w8(flags+best_index,1);const auto winner=m.r32(items+best_index*4u);
    m.w32(i.arg[0],winner);return i.arg[0];
}

std::uint32_t fun_00428370(Memory&m,const Inputs&i){
    using namespace detail;
    if((m.r8(0x836b20u)&1u)==0)throw std::domain_error("0x28370 initialization callback route excluded");
    const auto desc=i.arg[0],out=i.arg[1],count=m.r32(desc+0x0cu),header=m.r32(desc);
    i.fp.load32(m.r32(desc+8u));const auto conversion=integer(m,i.fp);
    m.w32(0x834b54u,conversion);m.w32(0x834b58u,count);m.w32(0x834b60u,0);
    m.w16(0x834b68u,0);m.w16(0x834b6au,0);m.w32(0x834b5cu,out);m.w32(0x834b64u,0x834b98u);
    auto ebp=header,ebx=m.r32(header+8u);
    if(count<2u||count>4u)throw std::domain_error("0x28370 descriptor count outside frozen scope");
    for(std::uint32_t remaining=count-1u;remaining;--remaining){
        const auto dest=out+(remaining-1u)*4u;
        m.w32(0x834b98u+(remaining-1u)*4u,m.r32(ebx+4u));
        const auto next=m.r32(ebx+8u);
        const auto curr_obj=m.r32(ebx),prev_obj=m.r32(ebp);
        const auto curr=m.r32(curr_obj),prev=m.r32(prev_obj);
        const auto curr_y=s32(sx16(m.r16(curr+0x26u))),prev_y=s32(sx16(m.r16(prev+0x26u)));
        const auto dy=curr_y-prev_y;
        std::uint32_t direction=8;
        if(dy>=-1&&dy<=1){
            const auto curr_x=s32(sx16(m.r16(curr+0x24u))),prev_x=s32(sx16(m.r16(prev+0x24u)));
            const auto dx=curr_x-prev_x;
            if(dx>=-1&&dx<=1){
                const auto index=3*dy+curr_x-prev_x;
                direction=m.r32(0x7ba0a0u+static_cast<std::uint32_t>(index)*4u);
            }
        }
        m.w32(dest,direction);
        ebp=m.r32(ebp+8u);ebx=next;
    }
    m.w32(out+(count-1u)*4u,0xffffffffu);
    const auto last_obj=m.r32(ebp),last_coords=m.r32(last_obj);
    m.w32(0x834b50u,m.r32(last_coords+0x24u));
    if(m.r32(0x834b54u)==0)m.w32(0x834b54u,1);
    return 0x834b50u;
}

} // namespace ra2::recovered::numeric_b88
