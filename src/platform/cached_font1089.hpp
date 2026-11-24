#pragma once
// Independent bitwise key and complete borrowed-memory/state oracle.
#include <algorithm>
#include <stdexcept>
namespace ra2::platform::cached_font1089 {
namespace b=b1089_test;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
inline constexpr const char*names[]{"TEXT1.AUD","TEXT2.AUD","TEXT3.AUD","FULLFNT3.SHP"};
inline constexpr unsigned name_addresses[]{0x7dc6c8u,0x7dc69cu,0x7dc670u,0x7d0844u};
inline unsigned crc(const std::vector<unsigned char>&s){unsigned state=0u;auto update=[&](const unsigned char*p){auto c=~state;for(unsigned k=0;k<4u;++k){c^=p[k];for(unsigned bit=0;bit<8u;++bit)c=(c>>1u)^((c&1u)?0xedb88320u:0u);}state=~c;};unsigned p=0;for(;p+4u<=s.size();p+=4u)update(s.data()+p);if(p<s.size()){unsigned char tail[4]{};const auto n=unsigned(s.size())-p;for(unsigned k=0;k<n;++k)tail[k]=s[p+k];tail[n]=static_cast<unsigned char>(n);for(unsigned k=n+1u;k<4u;++k)tail[k]=tail[0];update(tail);}return state;}
struct World{
 unsigned root,base;b::Case c;static constexpr unsigned arena_size=65536u;
 World(unsigned r,unsigned a,b::Case v):root(r),base(a),c(v){}
 unsigned receiver()const{return base+0x4000u+64u*c.slot;}
 unsigned audio_record()const{return base+0x6000u+512u*c.slot;}
 unsigned backing()const{return base+0x2000u;}
 unsigned payload(unsigned n)const{return backing()+256u*n;}
 unsigned size(unsigned n)const{return 17u+b::mix(c.seed+119u*n)%97u;}
 b::Inputs input()const{b::Inputs i{};i.ax=b::mix(c.seed+1u);i.cx=root==0x25ed70u?receiver():b::mix(c.seed+2u);i.dx=b::mix(c.seed+3u);for(unsigned k=0;k<16u;++k)i.arg[k]=b::mix(c.seed+73u*k+17u);return i;}
 void setup(b::Memory&m,unsigned char*a)const{
  need(root==0x25e8b0u||root==0x25ed70u,"1089 selectedtwo usefulroots");
  for(unsigned j=0;j<4u;++j)for(unsigned k=0;;++k){need(m.r8(name_addresses[j]+k)==static_cast<unsigned char>(names[j][k]),"1089 exactoriginalfixednamebytes");if(!names[j][k])break;}
  for(unsigned k=0;k<arena_size;++k)a[k]=static_cast<unsigned char>(b::mix(c.seed+131u*k));
  m.w32(0xb10530u,0u);m.w32(0x819778u,audio_record());
  // Original402C70 publishes a 0x1E8-byte receiver at406BD8. The selected
  //406F30 only observes nonnull identity. These488 borrowed bytes are opaque;
  // no wholedevice construction or DirectSound behavior is claimed.
  for(unsigned k=0;k<488u;++k)m.w8(audio_record()+k,0u);m.w32(audio_record()+0x10u,1u);
  m.w32(0xa588e0u,base+0x1000u);m.w32(base+0x1004u,base+0x1100u);m.w32(base+0x1104u,base+0x1200u);m.w32(base+0x1204u,0u);
  for(unsigned owner=0;owner<2u;++owner){const auto p=base+0x1000u+256u*owner;m.w32(p+8u,base+0x1400u);m.w32(p+0x14u,owner==c.owner?4u:0u);m.w32(p+0x20u,base+0x1800u);m.w32(p+0x24u,backing());}
  struct Row{unsigned key,id;};std::array<Row,4>rows{};
  for(unsigned j=0;j<4u;++j){std::vector<unsigned char>text;for(unsigned k=0;names[j][k];++k)text.push_back(static_cast<unsigned char>(names[j][k]));rows[j]={crc(text),j};for(unsigned k=0;k<size(j);++k)m.w8(payload(j)+k,b::mix(c.seed+31u*j+73u*k));}
  std::sort(rows.begin(),rows.end(),[](auto a,auto d){return static_cast<std::int32_t>(a.key)<static_cast<std::int32_t>(d.key);});
  for(unsigned j=0;j<4u;++j){need(!j||rows[j-1u].key!=rows[j].key,"1089 distinctactualkeys");m.w32(base+0x1800u+12u*j,rows[j].key);m.w32(base+0x1804u+12u*j,256u*rows[j].id);m.w32(base+0x1808u+12u*j,size(rows[j].id));}
  m.w32(0xa9eaa8u,c.counter);for(unsigned j=0;j<3u;++j){m.w32(0xa9eab0u+8u*j,0xe0890000u+256u*j+c.seed%256u);m.w8(0xa9eab4u+8u*j,(c.seed+71u*j)&255u);}
  m.w8(receiver()+16u,1u+(c.seed%255u));
 }
};
struct Observation{std::vector<unsigned char>image,arena;unsigned scalar;};
inline Observation verify(const World&w,unsigned eax,const ra2::platform::x87::Image&numeric,const std::vector<unsigned char>&bi,const std::vector<unsigned char>&ba,const unsigned char*image,const unsigned char*arena){
 Observation o;o.image=bi;o.arena=ba;
 for(unsigned j=0;j<3u;++j)b::word(o.image,0x69eab0u+8u*j,w.payload(j));
 if(w.root==0x25ed70u){b::word(o.image,0x69eaa8u,w.c.counter+1u);const auto p=w.receiver()-w.base;b::word(o.arena,p,0x794160u);b::word(o.arena,p+4u,11u);b::word(o.arena,p+8u,21u);b::word(o.arena,p+12u,w.payload(3u));o.arena[p+16u]=0u;b::word(o.arena,p+20u,w.input().arg[0]);}
 const auto expected=w.root==0x25ed70u?w.receiver():0u;need(eax==expected,"1089 fullrawEAX0or exactborrowedreceiver");o.scalar=expected;
 need(std::equal(o.image.begin(),o.image.end(),image)&&std::equal(o.arena.begin(),o.arena.end(),arena),"1089 fullindependentimage/arena/cache/all4borrowedpayloads/opaque488record/flags/padding");
 need(ra2::platform::x87::same_numeric(numeric,ra2::platform::x87::Image::empty(static_cast<std::uint16_t>(w.c.control))),"1089 complete unchanged numericx87");return o;
}
inline void compare(const Observation&a,const Observation&d){need(a.image==d.image&&a.arena==d.arena&&a.scalar==d.scalar,"1089 pairedeverybyte/fullrawreturn");}
}
