#include "recovered/recovery_b1204.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1204 {namespace{
void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
void put(b1062::Observation&o,unsigned a,unsigned x){for(unsigned k=0;k<4u;++k)o.file.at(a+k)=static_cast<unsigned char>(x>>(8u*k));}
unsigned word(const unsigned char*p){return unsigned(p[0])|(unsigned(p[1])<<8u)|(unsigned(p[2])<<16u)|(unsigned(p[3])<<24u);}
std::string key(Heap&h,unsigned p){std::string s;for(unsigned k=0;k<32u&&h.r8(p+k);++k)s+=char(h.r8(p+k));return s;}
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,Observation&o){
 need(m.r32(0xab7eccu)==0u&&m.r32(0xa27e9cu)==0u&&m.r32(0xa27ea0u)==0u&&m.r32(0xa27ea8u)==0u&&m.r32(0xa27eacu)==10u&&m.r32(0xa27e98u)==0x7906f4u,"1204 genuine cold localization/Session producer state");
 m.w32(0xab7eccu,1u);m.w32(0xab7ea8u,0u);m.w32(0xab7eb4u,i.cx);
 std::string path;for(unsigned k=0;k<64u&&m.r8(i.cx+k);++k)path+=char(m.r8(i.cx+k));need(path=="whole.mix","1204 finite public filename argument");const auto dot=path.find('.');path.resize(dot);path+=".csf";for(unsigned k=0;k<=path.size();++k)m.w8(0xaace08u+k,k==path.size()?0u:unsigned(path[k]));
 auto&f=o.probe;f.filename=h.allocate(unsigned(path.size()+1u));need(f.filename!=0u,"1204 genuine probe filename clone");for(unsigned k=0;k<=path.size();++k){unsigned ch=k==path.size()?0u:unsigned(path[k]);if(ch>='a'&&ch<='z')ch-=32u;h.w8(f.filename+k,ch);}
 put(f,0u,0x7856a0u);put(f,4u,1u);put(f,0xcu,0xffffffffu);put(f,0x10u,0xffffffffu);put(f,0x14u,f.filename);f.file[0x1cu]=1u;put(f,0x3cu,0xffffffffu);put(f,0x40u,0xffffffffu);
 const auto name=reinterpret_cast<const char*>(std::uintptr_t(f.filename));for(unsigned j=0;j<3u;++j){HANDLE file=a.create_file_a(name,GENERIC_READ,j==2u?3u:1u,nullptr,OPEN_EXISTING,j==2u?FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN:FILE_ATTRIBUTE_NORMAL,nullptr);need(file!=INVALID_HANDLE_VALUE,"1204 genuine positive header probe open");put(f,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(file)));if(j==2u){f.bytes_read=0u;need(a.read_file(file,f.header.data(),24u,&f.bytes_read,nullptr)!=FALSE&&f.bytes_read==24u,"1204 actual complete CSF header probe");m.w8(0xa9e184u,0u);need(word(f.header.data())==0x43534620u&&word(f.header.data()+4u)>=2u&&word(f.header.data()+8u)==5u&&word(f.header.data()+12u)==5u&&word(f.header.data()+20u)<10u,"1204 five positive labels and matched real language");m.w32(0xab7eb8u,5u);m.w32(0xab7ebcu,5u);m.w32(0x7e25f0u,word(f.header.data()+20u));put(f,0u,0x793c84u);}
 need(a.close_handle(file)!=FALSE,"1204 real header probe close");put(f,0x10u,0xffffffffu);}
 f.final_free=h.release(f.filename);need(f.final_free!=0u,"1204 actual probe name release");put(f,0u,0x793c3cu);put(f,0x14u,0u);f.file[0x1cu]=0u;
 for(unsigned j=0;j<3u;++j){const unsigned bytes=j?20u:200u,p=h.allocate(bytes);need(p!=0u,"1204 true positive header array allocation");m.w32(0xab7ec0u+j*4u,p);for(unsigned k=0;k<bytes;++k)h.w8(p+k,0u);}
 Inputs parser=i;parser.cx=0xaace08u;need(b1062::run(m,parser,h,a,o.parser)==1u,"1204 accepted exact physical binary parser contract");
 const unsigned records=m.r32(0xab7ec0u);for(unsigned j=1u;j<5u;++j)for(unsigned k=j;k&&key(h,records+k*40u)<key(h,records+(k-1u)*40u);--k)for(unsigned z=0;z<40u;++z){const unsigned x=h.r8(records+k*40u+z),y=h.r8(records+(k-1u)*40u+z);h.w8(records+k*40u+z,y);h.w8(records+(k-1u)*40u+z,x);}
 const auto lookup=[&](unsigned label){std::string name;for(unsigned k=0;k<32u&&m.r8(label+k);++k)name+=char(m.r8(label+k));unsigned lo=0u,hi=5u;while(lo<hi){const unsigned mid=lo+(hi-lo)/2u;const auto found=key(h,records+mid*40u);if(found==name)return h.r32(m.r32(0xab7ec4u)+4u*h.r32(records+mid*40u+36u));if(found<name)lo=mid+1u;else hi=mid;}throw std::domain_error("1204 positive actual bsearch label must exist");};
 for(unsigned j=0;j<4u;++j){const unsigned src=lookup(m.r32(0x7dccf8u+j*4u));unsigned n=0u;while(h.r8(src+n)||h.r8(src+n+1u))n+=2u;const unsigned duplicate=h.allocate(n+2u);need(duplicate!=0u,"1204 genuine nonempty wide strdup");for(unsigned k=0;k<n+2u;++k)h.w8(duplicate+k,h.r8(src+k));unsigned count=m.r32(0xa27ea8u);if(count>=m.r32(0xa27ea0u)){need(count==0u&&m.r32(0xa27eacu)==10u,"1204 real first reserve10 only");const unsigned backing=h.allocate(40u);need(backing!=0u,"1204 actual vector reserve allocation");m.w8(0xa27ea4u,1u);m.w32(0xa27e9cu,backing);m.w32(0xa27ea0u,10u);m.w8(0xa27ea5u,1u);}h.w32(m.r32(0xa27e9cu)+4u*count,duplicate);m.w32(0xa27ea8u,count+1u);}
 const unsigned description=lookup(0x7cbfb4u);unsigned n=0u;do{const unsigned lo=h.r8(description+n),hi=h.r8(description+n+1u);m.w8(0xa579f8u+n,lo);m.w8(0xa579f9u+n,hi);n+=2u;if(!lo&&!hi)break;}while(n<256u);need(n<=256u,"1204 exact fixed description capacity");return 1u;
}
}
