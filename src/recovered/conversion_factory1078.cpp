#include "recovered/conversion_factory1078.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::factory1078 {
static void need(bool v){if(!v)throw std::domain_error("1063 outside positive complete descriptor construction");}
static void word16(Heap&h,unsigned p,unsigned v){h.w8(p,v);h.w8(p+1u,v>>8u);}
// Actual41E3E0 cache with genuine41E7F0 first owned backing growth.
static unsigned table(Memory&m,Heap&h,unsigned n){const auto count=m.r32(0x824930u);auto data=m.r32(0x824924u);need(n>=1u&&n<=53u&&count<=1u);if(count)need(m.r32(0x824928u)==10u&&data!=0u);else need(m.r32(0x824928u)==0u&&data==0u);
 for(unsigned j=0;j<count;++j){const auto p=h.r32(data+4u*j);if(h.r32(p+0x20000u)==n){h.w32(p+0x20004u,h.r32(p+0x20004u)+1u);return p;}}
 const auto p=h.allocate(0x20008u);need(p!=0u);h.w32(p+0x20000u,n);h.w32(p+0x20004u,0u);
 for(unsigned y=0;y<256u;++y)for(unsigned x=0;x<256u;++x){const auto product=static_cast<std::int32_t>(x*y*(n-1u));const auto wide=static_cast<std::int64_t>(product)*(-2113531863ll);auto q=static_cast<std::int32_t>(wide>>32u)+product;q>>=14u;q+=static_cast<std::uint32_t>(q)>>31u;if(q>static_cast<std::int32_t>(n-1u))q=static_cast<std::int32_t>(n-1u);word16(h,p+2u*(256u*y+x),static_cast<unsigned>(q)<<8u);}
 // Original786800+8 ->41E7F0: positive new capacity10, no old array/copy/free.
 need(count==0u&&m.r32(0x824934u)==10u);m.w8(0x82492cu,0u);data=h.allocate(40u);need(data!=0u);m.w8(0x82492cu,1u);m.w32(0x824924u,data);m.w32(0x824928u,10u);m.w8(0x82492du,1u);
 m.w32(0x824930u,1u);h.w32(data,p);h.w32(p+0x20004u,1u);return p;
}
unsigned construct_two_byte(Memory&m,const Inputs&i,Heap&h){const auto p=i.cx;need(m.r32(p)==0x7905bcu&&m.r32(p+4u)==2u);
 const auto a0=h.allocate(8u);need(a0!=0u); // original0x483d44
 h.w32(a0+0u,0x78943cu); // original0x483d58
 h.w32(a0+4u,m.r32(p+0x174u)); // original0x483d5e
 m.w32(p+8u,a0); // original0x483d67
 const auto a1=h.allocate(8u);need(a1!=0u); // original0x483d6a
 h.w32(a1+0u,0x78942cu); // original0x483d7c
 h.w32(a1+4u,m.r32(p+0x174u)); // original0x483d82
 m.w32(p+12u,a1); // original0x483d8b
 const auto a2=h.allocate(12u);need(a2!=0u); // original0x483d8e
 h.w32(a2+4u,p+0x17cu); // original0x483da6
 h.w32(a2+8u,m.r32(p+0x174u)); // original0x483da9
 h.w32(a2+0u,0x78941cu); // original0x483dac
 m.w32(p+20u,a2); // original0x483db8
 const auto a3=h.allocate(8u);need(a3!=0u); // original0x483dbb
 h.w32(a3+0u,0x78940cu); // original0x483dce
 word16(h,a3+4u,m.r16(p+0x180u)); // original0x483dd4
 m.w32(p+16u,a3); // original0x483dde
 const auto a4=h.allocate(12u);need(a4!=0u); // original0x483de1
 h.w32(a4+4u,m.r32(p+0x174u)); // original0x483dfa
 word16(h,a4+8u,m.r16(p+0x184u)); // original0x483dfd
 h.w32(a4+0u,0x7893fcu); // original0x483e01
 m.w32(p+24u,a4); // original0x483e0d
 const auto a5=h.allocate(12u);need(a5!=0u); // original0x483e10
 h.w32(a5+4u,m.r32(p+0x174u)); // original0x483e29
 word16(h,a5+8u,m.r16(p+0x180u)); // original0x483e2c
 h.w32(a5+0u,0x7893ecu); // original0x483e30
 m.w32(p+28u,a5); // original0x483e3c
 const auto a6=h.allocate(12u);need(a6!=0u); // original0x483e3f
 h.w32(a6+4u,m.r32(p+0x174u)); // original0x483e58
 word16(h,a6+8u,m.r16(p+0x184u)); // original0x483e5b
 h.w32(a6+0u,0x7893dcu); // original0x483e5f
 m.w32(p+32u,a6); // original0x483e6b
 const auto a7=h.allocate(8u);need(a7!=0u); // original0x483e6e
 h.w32(a7+0u,0x7893ccu); // original0x483e80
 h.w32(a7+4u,m.r32(p+0x174u)); // original0x483e86
 m.w32(p+36u,a7); // original0x483e8f
 const auto a8=h.allocate(8u);need(a8!=0u); // original0x483e92
 h.w32(a8+0u,0x7893bcu); // original0x483ea4
 h.w32(a8+4u,m.r32(p+0x174u)); // original0x483eaa
 m.w32(p+40u,a8); // original0x483eb3
 const auto a9=h.allocate(12u);need(a9!=0u); // original0x483eb6
 h.w32(a9+4u,p+0x17cu); // original0x483ece
 h.w32(a9+8u,m.r32(p+0x174u)); // original0x483ed1
 h.w32(a9+0u,0x7893acu); // original0x483ed4
 m.w32(p+48u,a9); // original0x483ee0
 const auto a10=h.allocate(8u);need(a10!=0u); // original0x483ee3
 h.w32(a10+0u,0x78939cu); // original0x483ef6
 word16(h,a10+4u,m.r16(p+0x180u)); // original0x483efc
 m.w32(p+44u,a10); // original0x483f06
 const auto a11=h.allocate(12u);need(a11!=0u); // original0x483f09
 h.w32(a11+4u,m.r32(p+0x174u)); // original0x483f22
 word16(h,a11+8u,m.r16(p+0x184u)); // original0x483f25
 h.w32(a11+0u,0x78938cu); // original0x483f29
 m.w32(p+52u,a11); // original0x483f35
 const auto a12=h.allocate(12u);need(a12!=0u); // original0x483f38
 h.w32(a12+4u,m.r32(p+0x174u)); // original0x483f51
 word16(h,a12+8u,m.r16(p+0x180u)); // original0x483f54
 h.w32(a12+0u,0x78937cu); // original0x483f58
 m.w32(p+56u,a12); // original0x483f64
 const auto a13=h.allocate(12u);need(a13!=0u); // original0x483f67
 h.w32(a13+4u,m.r32(p+0x174u)); // original0x483f80
 word16(h,a13+8u,m.r16(p+0x184u)); // original0x483f83
 h.w32(a13+0u,0x78936cu); // original0x483f87
 m.w32(p+60u,a13); // original0x483f93
 const auto a14=h.allocate(12u);need(a14!=0u); // original0x483f96
 h.w32(a14+4u,m.r32(p+0x174u)); // original0x483faf
 word16(h,a14+8u,m.r16(p+0x184u)); // original0x483fb2
 h.w32(a14+0u,0x78935cu); // original0x483fb6
 m.w32(p+64u,a14); // original0x483fc2
 const auto a15=h.allocate(12u);need(a15!=0u); // original0x483fc5
 h.w32(a15+4u,m.r32(p+0x174u)); // original0x483fde
 word16(h,a15+8u,m.r16(p+0x180u)); // original0x483fe1
 h.w32(a15+0u,0x78934cu); // original0x483fe5
 m.w32(p+68u,a15); // original0x483ff1
 const auto a16=h.allocate(12u);need(a16!=0u); // original0x483ff4
 h.w32(a16+4u,m.r32(p+0x174u)); // original0x48400d
 word16(h,a16+8u,m.r16(p+0x184u)); // original0x484010
 h.w32(a16+0u,0x78933cu); // original0x484014
 m.w32(p+72u,a16); // original0x484020
 const auto a17=h.allocate(8u);need(a17!=0u); // original0x484023
 h.w32(a17+0u,0x78932cu); // original0x484035
 h.w32(a17+4u,m.r32(p+0x174u)); // original0x48403b
 m.w32(p+76u,a17); // original0x484044
 const auto a18=h.allocate(8u);need(a18!=0u); // original0x484047
 h.w32(a18+0u,0x78931cu); // original0x484059
 h.w32(a18+4u,m.r32(p+0x174u)); // original0x48405f
 m.w32(p+80u,a18); // original0x484068
 const auto a19=h.allocate(12u);need(a19!=0u); // original0x48406b
 h.w32(a19+4u,p+0x17cu); // original0x484083
 h.w32(a19+8u,m.r32(p+0x174u)); // original0x484086
 h.w32(a19+0u,0x78930cu); // original0x484089
 m.w32(p+88u,a19); // original0x484095
 const auto a20=h.allocate(8u);need(a20!=0u); // original0x484098
 h.w32(a20+0u,0x7892fcu); // original0x4840ab
 word16(h,a20+4u,m.r16(p+0x180u)); // original0x4840b1
 m.w32(p+84u,a20); // original0x4840bb
 const auto a21=h.allocate(12u);need(a21!=0u); // original0x4840be
 h.w32(a21+4u,m.r32(p+0x174u)); // original0x4840d7
 word16(h,a21+8u,m.r16(p+0x184u)); // original0x4840da
 h.w32(a21+0u,0x7892ecu); // original0x4840de
 m.w32(p+92u,a21); // original0x4840ea
 const auto a22=h.allocate(12u);need(a22!=0u); // original0x4840ed
 h.w32(a22+4u,m.r32(p+0x174u)); // original0x484106
 word16(h,a22+8u,m.r16(p+0x180u)); // original0x484109
 h.w32(a22+0u,0x7892dcu); // original0x48410d
 m.w32(p+96u,a22); // original0x484119
 const auto a23=h.allocate(12u);need(a23!=0u); // original0x48411c
 h.w32(a23+4u,m.r32(p+0x174u)); // original0x484135
 word16(h,a23+8u,m.r16(p+0x184u)); // original0x484138
 h.w32(a23+0u,0x7892ccu); // original0x48413c
 m.w32(p+100u,a23); // original0x484149
 const auto a24=h.allocate(12u);need(a24!=0u); // original0x48414c
 h.w32(a24+4u,m.r32(p+0x170u)); // original0x484166
 h.w32(a24+8u,0x0u); // original0x48416f
 h.w32(a24+0u,0x7892bcu); // original0x484172
 const auto a25=table(m,h,m.r32(p+0x16cu)); // original0x484178
 h.w32(a24+8u,a25); // original0x48417d
 m.w32(p+104u,a24); // original0x484186
 const auto a27=h.allocate(12u);need(a27!=0u); // original0x484189
 h.w32(a27+4u,m.r32(p+0x170u)); // original0x4841a3
 h.w32(a27+8u,0x0u); // original0x4841ac
 h.w32(a27+0u,0x7892acu); // original0x4841af
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4841b5
 h.w32(a27+8u,a25); // original0x4841ba
 m.w32(p+108u,a27); // original0x4841c3
 const auto a28=h.allocate(16u);need(a28!=0u); // original0x4841c6
 h.w32(a28+8u,m.r32(p+0x170u)); // original0x4841e6
 h.w32(a28+4u,p+0x17cu); // original0x4841ef
 h.w32(a28+12u,0x0u); // original0x4841f2
 h.w32(a28+0u,0x78929cu); // original0x4841f5
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4841fb
 h.w32(a28+12u,a25); // original0x484200
 m.w32(p+112u,a28); // original0x484209
 const auto a29=h.allocate(16u);need(a29!=0u); // original0x48420c
 h.w32(a29+4u,m.r32(p+0x170u)); // original0x484233
 h.w32(a29+8u,0x0u); // original0x484236
 word16(h,a29+12u,m.r16(p+0x184u)); // original0x484239
 h.w32(a29+0u,0x78928cu); // original0x48423d
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484243
 h.w32(a29+8u,a25); // original0x484248
 m.w32(p+116u,a29); // original0x484251
 const auto a30=h.allocate(16u);need(a30!=0u); // original0x484254
 h.w32(a30+4u,m.r32(p+0x170u)); // original0x48427b
 h.w32(a30+8u,0x0u); // original0x48427e
 word16(h,a30+12u,m.r16(p+0x180u)); // original0x484281
 h.w32(a30+0u,0x78927cu); // original0x484285
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x48428b
 h.w32(a30+8u,a25); // original0x484290
 m.w32(p+120u,a30); // original0x484299
 const auto a31=h.allocate(16u);need(a31!=0u); // original0x48429c
 h.w32(a31+4u,m.r32(p+0x170u)); // original0x4842c3
 h.w32(a31+8u,0x0u); // original0x4842c6
 word16(h,a31+12u,m.r16(p+0x184u)); // original0x4842c9
 h.w32(a31+0u,0x78926cu); // original0x4842cd
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4842d3
 h.w32(a31+8u,a25); // original0x4842d8
 m.w32(p+124u,a31); // original0x4842e1
 const auto a32=h.allocate(4u);need(a32!=0u); // original0x4842e4
 h.w32(a32+0u,0x78925cu); // original0x4842f0
 m.w32(p+128u,a32); // original0x4842fc
 const auto a33=h.allocate(4u);need(a33!=0u); // original0x484302
 h.w32(a33+0u,0x78924cu); // original0x48430e
 m.w32(p+132u,a33); // original0x48431a
 const auto a34=h.allocate(8u);need(a34!=0u); // original0x484320
 h.w32(a34+0u,0x78923cu); // original0x484332
 h.w32(a34+4u,m.r32(p+0x170u)); // original0x484338
 m.w32(p+136u,a34); // original0x484341
 const auto a35=h.allocate(12u);need(a35!=0u); // original0x484347
 h.w32(a35+4u,m.r32(p+0x174u)); // original0x484360
 word16(h,a35+8u,m.r16(p+0x180u)); // original0x484363
 h.w32(a35+0u,0x78922cu); // original0x484367
 m.w32(p+140u,a35); // original0x484373
 const auto a36=h.allocate(12u);need(a36!=0u); // original0x484379
 h.w32(a36+4u,m.r32(p+0x174u)); // original0x484392
 word16(h,a36+8u,m.r16(p+0x180u)); // original0x484395
 h.w32(a36+0u,0x78921cu); // original0x484399
 m.w32(p+144u,a36); // original0x4843a5
 const auto a37=h.allocate(12u);need(a37!=0u); // original0x4843ab
 h.w32(a37+4u,m.r32(p+0x170u)); // original0x4843c5
 h.w32(a37+8u,0x0u); // original0x4843ce
 h.w32(a37+0u,0x7892bcu); // original0x4843d1
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4843d7
 h.w32(a37+8u,a25); // original0x4843dc
 m.w32(p+148u,a37); // original0x4843e5
 const auto a38=h.allocate(12u);need(a38!=0u); // original0x4843eb
 h.w32(a38+4u,m.r32(p+0x170u)); // original0x484405
 h.w32(a38+8u,0x0u); // original0x48440e
 h.w32(a38+0u,0x78920cu); // original0x484411
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484417
 h.w32(a38+8u,a25); // original0x48441c
 m.w32(p+152u,a38); // original0x484425
 const auto a39=h.allocate(16u);need(a39!=0u); // original0x48442b
 h.w32(a39+4u,p+0x17cu); // original0x48444c
 h.w32(a39+8u,m.r32(p+0x170u)); // original0x48444f
 h.w32(a39+12u,0x0u); // original0x484452
 h.w32(a39+0u,0x7891fcu); // original0x48445a
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484460
 h.w32(a39+12u,a25); // original0x484465
 m.w32(p+156u,a39); // original0x48446e
 const auto a40=h.allocate(16u);need(a40!=0u); // original0x484474
 h.w32(a40+4u,m.r32(p+0x170u)); // original0x484495
 h.w32(a40+8u,0x0u); // original0x484498
 word16(h,a40+12u,m.r16(p+0x184u)); // original0x48449c
 h.w32(a40+0u,0x7891ecu); // original0x4844a5
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4844ab
 h.w32(a40+8u,a25); // original0x4844b0
 m.w32(p+160u,a40); // original0x4844b9
 const auto a41=h.allocate(16u);need(a41!=0u); // original0x4844bf
 h.w32(a41+4u,m.r32(p+0x170u)); // original0x4844e0
 h.w32(a41+8u,0x0u); // original0x4844e3
 word16(h,a41+12u,m.r16(p+0x180u)); // original0x4844e7
 h.w32(a41+0u,0x7891dcu); // original0x4844f0
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4844f6
 h.w32(a41+8u,a25); // original0x4844fb
 m.w32(p+164u,a41); // original0x484504
 const auto a42=h.allocate(16u);need(a42!=0u); // original0x48450a
 h.w32(a42+4u,m.r32(p+0x170u)); // original0x48452b
 h.w32(a42+8u,0x0u); // original0x48452e
 word16(h,a42+12u,m.r16(p+0x184u)); // original0x484532
 h.w32(a42+0u,0x7891ccu); // original0x48453b
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484541
 h.w32(a42+8u,a25); // original0x484546
 m.w32(p+168u,a42); // original0x48454f
 const auto a43=h.allocate(16u);need(a43!=0u); // original0x484555
 h.w32(a43+4u,m.r32(p+0x170u)); // original0x484576
 h.w32(a43+8u,0x0u); // original0x484579
 word16(h,a43+12u,m.r16(p+0x184u)); // original0x48457d
 h.w32(a43+0u,0x7891bcu); // original0x484586
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x48458c
 h.w32(a43+8u,a25); // original0x484591
 m.w32(p+172u,a43); // original0x48459a
 const auto a44=h.allocate(16u);need(a44!=0u); // original0x4845a0
 h.w32(a44+4u,m.r32(p+0x170u)); // original0x4845c1
 h.w32(a44+8u,0x0u); // original0x4845c4
 word16(h,a44+12u,m.r16(p+0x180u)); // original0x4845c8
 h.w32(a44+0u,0x7891acu); // original0x4845d1
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4845d7
 h.w32(a44+8u,a25); // original0x4845dc
 m.w32(p+176u,a44); // original0x4845e5
 const auto a45=h.allocate(16u);need(a45!=0u); // original0x4845eb
 h.w32(a45+4u,m.r32(p+0x170u)); // original0x48460c
 h.w32(a45+8u,0x0u); // original0x48460f
 word16(h,a45+12u,m.r16(p+0x184u)); // original0x484613
 h.w32(a45+0u,0x78919cu); // original0x48461c
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484622
 h.w32(a45+8u,a25); // original0x484627
 m.w32(p+180u,a45); // original0x484630
 const auto a46=h.allocate(12u);need(a46!=0u); // original0x484636
 h.w32(a46+4u,m.r32(p+0x170u)); // original0x484650
 h.w32(a46+8u,0x0u); // original0x484653
 h.w32(a46+0u,0x7892bcu); // original0x48465c
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484662
 h.w32(a46+8u,a25); // original0x484667
 m.w32(p+184u,a46); // original0x484670
 const auto a47=h.allocate(12u);need(a47!=0u); // original0x484676
 h.w32(a47+4u,m.r32(p+0x170u)); // original0x484690
 h.w32(a47+8u,0x0u); // original0x484693
 h.w32(a47+0u,0x78918cu); // original0x48469c
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4846a2
 h.w32(a47+8u,a25); // original0x4846a7
 m.w32(p+188u,a47); // original0x4846b0
 const auto a48=h.allocate(16u);need(a48!=0u); // original0x4846b6
 h.w32(a48+4u,p+0x17cu); // original0x4846d7
 h.w32(a48+8u,m.r32(p+0x170u)); // original0x4846da
 h.w32(a48+12u,0x0u); // original0x4846dd
 h.w32(a48+0u,0x78917cu); // original0x4846e5
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4846eb
 h.w32(a48+12u,a25); // original0x4846f0
 m.w32(p+192u,a48); // original0x4846f9
 const auto a49=h.allocate(16u);need(a49!=0u); // original0x4846ff
 h.w32(a49+4u,m.r32(p+0x170u)); // original0x484720
 h.w32(a49+8u,0x0u); // original0x484723
 word16(h,a49+12u,m.r16(p+0x184u)); // original0x484727
 h.w32(a49+0u,0x78916cu); // original0x484730
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484736
 h.w32(a49+8u,a25); // original0x48473b
 m.w32(p+196u,a49); // original0x484744
 const auto a50=h.allocate(16u);need(a50!=0u); // original0x48474a
 h.w32(a50+4u,m.r32(p+0x170u)); // original0x48476b
 h.w32(a50+8u,0x0u); // original0x48476e
 word16(h,a50+12u,m.r16(p+0x180u)); // original0x484772
 h.w32(a50+0u,0x78915cu); // original0x48477b
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484781
 h.w32(a50+8u,a25); // original0x484786
 m.w32(p+200u,a50); // original0x48478f
 const auto a51=h.allocate(16u);need(a51!=0u); // original0x484795
 h.w32(a51+4u,m.r32(p+0x170u)); // original0x4847b6
 h.w32(a51+8u,0x0u); // original0x4847b9
 word16(h,a51+12u,m.r16(p+0x184u)); // original0x4847bd
 h.w32(a51+0u,0x78914cu); // original0x4847c6
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4847cc
 h.w32(a51+8u,a25); // original0x4847d1
 m.w32(p+204u,a51); // original0x4847da
 const auto a52=h.allocate(8u);need(a52!=0u); // original0x4847e0
 h.w32(a52+4u,m.r32(p+0x174u)); // original0x4847f2
 h.w32(a52+0u,0x789140u); // original0x4847f5
 m.w32(p+208u,a52); // original0x484801
 const auto a53=h.allocate(12u);need(a53!=0u); // original0x484807
 h.w32(a53+4u,p+0x17cu); // original0x48481f
 h.w32(a53+8u,m.r32(p+0x174u)); // original0x484822
 h.w32(a53+0u,0x789134u); // original0x484825
 m.w32(p+216u,a53); // original0x484831
 const auto a54=h.allocate(8u);need(a54!=0u); // original0x484837
 word16(h,a54+4u,m.r16(p+0x180u)); // original0x48484a
 h.w32(a54+0u,0x789128u); // original0x48484e
 m.w32(p+212u,a54); // original0x48485a
 const auto a55=h.allocate(12u);need(a55!=0u); // original0x484860
 h.w32(a55+4u,m.r32(p+0x174u)); // original0x484879
 word16(h,a55+8u,m.r16(p+0x184u)); // original0x48487c
 h.w32(a55+0u,0x78911cu); // original0x484880
 m.w32(p+220u,a55); // original0x48488c
 const auto a56=h.allocate(12u);need(a56!=0u); // original0x484892
 h.w32(a56+4u,m.r32(p+0x174u)); // original0x4848ab
 word16(h,a56+8u,m.r16(p+0x180u)); // original0x4848ae
 h.w32(a56+0u,0x789110u); // original0x4848b2
 m.w32(p+224u,a56); // original0x4848be
 const auto a57=h.allocate(12u);need(a57!=0u); // original0x4848c4
 h.w32(a57+4u,m.r32(p+0x174u)); // original0x4848dd
 word16(h,a57+8u,m.r16(p+0x184u)); // original0x4848e0
 h.w32(a57+0u,0x789104u); // original0x4848e4
 m.w32(p+228u,a57); // original0x4848f0
 const auto a58=h.allocate(8u);need(a58!=0u); // original0x4848f6
 h.w32(a58+4u,m.r32(p+0x174u)); // original0x484908
 h.w32(a58+0u,0x7890f8u); // original0x48490b
 m.w32(p+232u,a58); // original0x484917
 const auto a59=h.allocate(12u);need(a59!=0u); // original0x48491d
 h.w32(a59+4u,p+0x17cu); // original0x484935
 h.w32(a59+8u,m.r32(p+0x174u)); // original0x484938
 h.w32(a59+0u,0x7890ecu); // original0x48493b
 m.w32(p+236u,a59); // original0x484947
 const auto a60=h.allocate(8u);need(a60!=0u); // original0x48494d
 word16(h,a60+4u,m.r16(p+0x180u)); // original0x484960
 h.w32(a60+0u,0x7890e0u); // original0x484964
 m.w32(p+240u,a60); // original0x484970
 const auto a61=h.allocate(12u);need(a61!=0u); // original0x484976
 h.w32(a61+4u,m.r32(p+0x174u)); // original0x48498f
 word16(h,a61+8u,m.r16(p+0x184u)); // original0x484992
 h.w32(a61+0u,0x7890d4u); // original0x484996
 m.w32(p+244u,a61); // original0x4849a2
 const auto a62=h.allocate(12u);need(a62!=0u); // original0x4849a8
 h.w32(a62+4u,m.r32(p+0x174u)); // original0x4849c1
 word16(h,a62+8u,m.r16(p+0x180u)); // original0x4849c4
 h.w32(a62+0u,0x7890c8u); // original0x4849c8
 m.w32(p+248u,a62); // original0x4849d4
 const auto a63=h.allocate(12u);need(a63!=0u); // original0x4849da
 h.w32(a63+4u,m.r32(p+0x174u)); // original0x4849f3
 word16(h,a63+8u,m.r16(p+0x184u)); // original0x4849f6
 h.w32(a63+0u,0x7890bcu); // original0x4849fa
 m.w32(p+252u,a63); // original0x484a06
 const auto a64=h.allocate(12u);need(a64!=0u); // original0x484a0c
 h.w32(a64+4u,m.r32(p+0x174u)); // original0x484a25
 word16(h,a64+8u,m.r16(p+0x184u)); // original0x484a28
 h.w32(a64+0u,0x7890b0u); // original0x484a2c
 m.w32(p+256u,a64); // original0x484a38
 const auto a65=h.allocate(12u);need(a65!=0u); // original0x484a3e
 h.w32(a65+4u,m.r32(p+0x174u)); // original0x484a57
 word16(h,a65+8u,m.r16(p+0x180u)); // original0x484a5a
 h.w32(a65+0u,0x7890a4u); // original0x484a5e
 m.w32(p+260u,a65); // original0x484a6a
 const auto a66=h.allocate(12u);need(a66!=0u); // original0x484a70
 h.w32(a66+4u,m.r32(p+0x174u)); // original0x484a89
 word16(h,a66+8u,m.r16(p+0x184u)); // original0x484a8c
 h.w32(a66+0u,0x789098u); // original0x484a90
 m.w32(p+264u,a66); // original0x484a9c
 const auto a67=h.allocate(8u);need(a67!=0u); // original0x484aa2
 h.w32(a67+4u,m.r32(p+0x174u)); // original0x484ab4
 h.w32(a67+0u,0x78908cu); // original0x484ab7
 m.w32(p+268u,a67); // original0x484ac3
 const auto a68=h.allocate(12u);need(a68!=0u); // original0x484ac9
 h.w32(a68+4u,p+0x17cu); // original0x484ae1
 h.w32(a68+8u,m.r32(p+0x174u)); // original0x484ae4
 h.w32(a68+0u,0x789080u); // original0x484ae7
 m.w32(p+272u,a68); // original0x484af3
 const auto a69=h.allocate(8u);need(a69!=0u); // original0x484af9
 word16(h,a69+4u,m.r16(p+0x180u)); // original0x484b0c
 h.w32(a69+0u,0x789074u); // original0x484b10
 m.w32(p+276u,a69); // original0x484b1c
 const auto a70=h.allocate(12u);need(a70!=0u); // original0x484b22
 h.w32(a70+4u,m.r32(p+0x174u)); // original0x484b3b
 word16(h,a70+8u,m.r16(p+0x184u)); // original0x484b3e
 h.w32(a70+0u,0x789068u); // original0x484b42
 m.w32(p+280u,a70); // original0x484b4e
 const auto a71=h.allocate(12u);need(a71!=0u); // original0x484b54
 h.w32(a71+4u,m.r32(p+0x174u)); // original0x484b6d
 word16(h,a71+8u,m.r16(p+0x180u)); // original0x484b70
 h.w32(a71+0u,0x78905cu); // original0x484b74
 m.w32(p+284u,a71); // original0x484b80
 const auto a72=h.allocate(12u);need(a72!=0u); // original0x484b86
 h.w32(a72+4u,m.r32(p+0x174u)); // original0x484b9f
 word16(h,a72+8u,m.r16(p+0x184u)); // original0x484ba2
 h.w32(a72+0u,0x789050u); // original0x484ba6
 m.w32(p+288u,a72); // original0x484bb2
 const auto a73=h.allocate(12u);need(a73!=0u); // original0x484bb8
 h.w32(a73+4u,m.r32(p+0x170u)); // original0x484bd2
 h.w32(a73+8u,0x0u); // original0x484bd5
 h.w32(a73+0u,0x789044u); // original0x484bde
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484be4
 h.w32(a73+8u,a25); // original0x484be9
 m.w32(p+292u,a73); // original0x484bf2
 const auto a74=h.allocate(16u);need(a74!=0u); // original0x484bf8
 h.w32(a74+4u,p+0x17cu); // original0x484c19
 h.w32(a74+8u,m.r32(p+0x170u)); // original0x484c1c
 h.w32(a74+12u,0x0u); // original0x484c1f
 h.w32(a74+0u,0x789038u); // original0x484c27
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484c2d
 h.w32(a74+12u,a25); // original0x484c32
 m.w32(p+296u,a74); // original0x484c3b
 const auto a75=h.allocate(16u);need(a75!=0u); // original0x484c41
 h.w32(a75+4u,m.r32(p+0x170u)); // original0x484c62
 h.w32(a75+8u,0x0u); // original0x484c65
 word16(h,a75+12u,m.r16(p+0x184u)); // original0x484c69
 h.w32(a75+0u,0x78902cu); // original0x484c72
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484c78
 h.w32(a75+8u,a25); // original0x484c7d
 m.w32(p+300u,a75); // original0x484c86
 const auto a76=h.allocate(16u);need(a76!=0u); // original0x484c8c
 h.w32(a76+4u,m.r32(p+0x170u)); // original0x484cad
 h.w32(a76+8u,0x0u); // original0x484cb0
 word16(h,a76+12u,m.r16(p+0x180u)); // original0x484cb4
 h.w32(a76+0u,0x789020u); // original0x484cbd
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484cc3
 h.w32(a76+8u,a25); // original0x484cc8
 m.w32(p+304u,a76); // original0x484cd1
 const auto a77=h.allocate(16u);need(a77!=0u); // original0x484cd7
 h.w32(a77+4u,m.r32(p+0x170u)); // original0x484cf8
 h.w32(a77+8u,0x0u); // original0x484cfb
 word16(h,a77+12u,m.r16(p+0x184u)); // original0x484cff
 h.w32(a77+0u,0x789014u); // original0x484d08
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484d0e
 h.w32(a77+8u,a25); // original0x484d13
 m.w32(p+308u,a77); // original0x484d1c
 const auto a78=h.allocate(12u);need(a78!=0u); // original0x484d22
 h.w32(a78+4u,m.r32(p+0x170u)); // original0x484d3c
 h.w32(a78+8u,0x0u); // original0x484d3f
 h.w32(a78+0u,0x789008u); // original0x484d48
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484d4e
 h.w32(a78+8u,a25); // original0x484d53
 m.w32(p+312u,a78); // original0x484d5c
 const auto a79=h.allocate(16u);need(a79!=0u); // original0x484d62
 h.w32(a79+4u,p+0x17cu); // original0x484d83
 h.w32(a79+8u,m.r32(p+0x170u)); // original0x484d86
 h.w32(a79+12u,0x0u); // original0x484d89
 h.w32(a79+0u,0x788ffcu); // original0x484d91
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484d97
 h.w32(a79+12u,a25); // original0x484d9c
 m.w32(p+316u,a79); // original0x484da5
 const auto a80=h.allocate(16u);need(a80!=0u); // original0x484dab
 h.w32(a80+4u,m.r32(p+0x170u)); // original0x484dcc
 h.w32(a80+8u,0x0u); // original0x484dcf
 word16(h,a80+12u,m.r16(p+0x184u)); // original0x484dd3
 h.w32(a80+0u,0x788ff0u); // original0x484ddc
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484de2
 h.w32(a80+8u,a25); // original0x484de7
 m.w32(p+320u,a80); // original0x484df0
 const auto a81=h.allocate(16u);need(a81!=0u); // original0x484df6
 h.w32(a81+4u,m.r32(p+0x170u)); // original0x484e17
 h.w32(a81+8u,0x0u); // original0x484e1a
 word16(h,a81+12u,m.r16(p+0x180u)); // original0x484e1e
 h.w32(a81+0u,0x788fe4u); // original0x484e27
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484e2d
 h.w32(a81+8u,a25); // original0x484e32
 m.w32(p+324u,a81); // original0x484e3b
 const auto a82=h.allocate(16u);need(a82!=0u); // original0x484e41
 h.w32(a82+4u,m.r32(p+0x170u)); // original0x484e62
 h.w32(a82+8u,0x0u); // original0x484e65
 word16(h,a82+12u,m.r16(p+0x184u)); // original0x484e69
 h.w32(a82+0u,0x788fd8u); // original0x484e72
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484e78
 h.w32(a82+8u,a25); // original0x484e7d
 m.w32(p+328u,a82); // original0x484e86
 const auto a83=h.allocate(16u);need(a83!=0u); // original0x484e8c
 h.w32(a83+4u,m.r32(p+0x170u)); // original0x484ead
 h.w32(a83+8u,0x0u); // original0x484eb0
 word16(h,a83+12u,m.r16(p+0x184u)); // original0x484eb4
 h.w32(a83+0u,0x788fccu); // original0x484ebd
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484ec3
 h.w32(a83+8u,a25); // original0x484ec8
 m.w32(p+332u,a83); // original0x484ed1
 const auto a84=h.allocate(16u);need(a84!=0u); // original0x484ed7
 h.w32(a84+4u,m.r32(p+0x170u)); // original0x484ef8
 h.w32(a84+8u,0x0u); // original0x484efb
 word16(h,a84+12u,m.r16(p+0x180u)); // original0x484eff
 h.w32(a84+0u,0x788fc0u); // original0x484f08
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484f0e
 h.w32(a84+8u,a25); // original0x484f13
 m.w32(p+336u,a84); // original0x484f1c
 const auto a85=h.allocate(16u);need(a85!=0u); // original0x484f22
 h.w32(a85+4u,m.r32(p+0x170u)); // original0x484f43
 h.w32(a85+8u,0x0u); // original0x484f46
 word16(h,a85+12u,m.r16(p+0x184u)); // original0x484f4a
 h.w32(a85+0u,0x788fb4u); // original0x484f53
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484f59
 h.w32(a85+8u,a25); // original0x484f5e
 m.w32(p+340u,a85); // original0x484f67
 const auto a86=h.allocate(12u);need(a86!=0u); // original0x484f6d
 h.w32(a86+4u,m.r32(p+0x170u)); // original0x484f87
 h.w32(a86+8u,0x0u); // original0x484f8a
 h.w32(a86+0u,0x788fa8u); // original0x484f93
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484f99
 h.w32(a86+8u,a25); // original0x484f9e
 m.w32(p+344u,a86); // original0x484fa7
 const auto a87=h.allocate(16u);need(a87!=0u); // original0x484fad
 h.w32(a87+4u,p+0x17cu); // original0x484fce
 h.w32(a87+8u,m.r32(p+0x170u)); // original0x484fd1
 h.w32(a87+12u,0x0u); // original0x484fd4
 h.w32(a87+0u,0x788f9cu); // original0x484fdc
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x484fe2
 h.w32(a87+12u,a25); // original0x484fe7
 m.w32(p+348u,a87); // original0x484ff0
 const auto a88=h.allocate(16u);need(a88!=0u); // original0x484ff6
 h.w32(a88+4u,m.r32(p+0x170u)); // original0x485017
 h.w32(a88+8u,0x0u); // original0x48501a
 word16(h,a88+12u,m.r16(p+0x184u)); // original0x48501e
 h.w32(a88+0u,0x788f90u); // original0x485027
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x48502d
 h.w32(a88+8u,a25); // original0x485032
 m.w32(p+352u,a88); // original0x48503b
 const auto a89=h.allocate(16u);need(a89!=0u); // original0x485041
 h.w32(a89+4u,m.r32(p+0x170u)); // original0x485062
 h.w32(a89+8u,0x0u); // original0x485065
 word16(h,a89+12u,m.r16(p+0x180u)); // original0x485069
 h.w32(a89+0u,0x788f84u); // original0x485072
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x485078
 h.w32(a89+8u,a25); // original0x48507d
 m.w32(p+356u,a89); // original0x485086
 const auto a90=h.allocate(16u);need(a90!=0u); // original0x48508c
 h.w32(a90+4u,m.r32(p+0x170u)); // original0x4850ad
 h.w32(a90+8u,0x0u); // original0x4850b0
 word16(h,a90+12u,m.r16(p+0x184u)); // original0x4850b4
 h.w32(a90+0u,0x788f78u); // original0x4850bd
 need(table(m,h,m.r32(p+0x16cu))==a25); // original0x4850c3
 h.w32(a90+8u,a25); // original0x4850c8
 m.w32(p+360u,a90); // original0x4850cb
 return a25;
}
}
