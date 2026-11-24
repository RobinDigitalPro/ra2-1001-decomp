#include "recovery_b1202.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
namespace ra2::recovered::b1202{
static void need(bool x){if(!x)throw std::domain_error("1202 exact populated Tag/Trigger contract");}
static std::string owned(Heap&h,unsigned p){std::string s;for(unsigned k=0;k<128u;++k){const auto c=h.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1202 bounded parser string");}
static std::string name(Memory&m,unsigned p){std::string s;for(unsigned k=0;k<25u;++k){const auto c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1202 original410580 name");}
static bool equal(std::string a,std::string z){const auto fold=[](char c){return c>='A'&&c<='Z'?char(c+32):c;};return a.size()==z.size()&&std::equal(a.begin(),a.end(),z.begin(),[&](char x,char y){return fold(x)==fold(y);});}
static unsigned hash(const std::string&s){return ini_name_hash(reinterpret_cast<const unsigned char*>(s.data()),s.size(),nullptr);}
static unsigned lookup(Memory&m,Heap&h,unsigned header,const std::string&s){const auto n=m.r32(header+16u),a=m.r32(header+4u);need(n==2u&&m.r32(header+8u)==10u);for(unsigned k=0;k<n;++k){const auto p=h.r32(a+4u*k);if(equal(name(m,p+36u),s))return p;}throw std::domain_error("1202 genuine existing name hit required");}
static unsigned decimal(const std::string&s){need(!s.empty());unsigned v=0u;for(char c:s){need(c>='0'&&c<='9');v=v*10u+unsigned(c-'0');}need(v<1000u);return v;}
static void display(Memory&m,unsigned receiver,const std::string&s){need(!s.empty()&&s.size()<48u);for(unsigned k=0;k<49u;++k)m.w8(receiver+100u+k,k<s.size()?static_cast<unsigned char>(s[k]):0u);}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&s){
 const bool tag=root==0x2a9f30u;need(tag||root==0x2e3ab0u);const auto ini=i.cx,row=m.r32(ini+48u);need(m.r32(ini)==0x78db34u&&m.r32(ini+36u)==1u&&m.r8(ini+44u)==1u&&row==m.r32(ini+32u));const auto section=h.r32(row+4u);need(h.r32(section)==0x78eba4u&&h.r32(section+48u)==1u&&h.r8(section+56u)==1u);const auto sectionname=owned(h,h.r32(section+12u));need(sectionname==(tag?"Tags":"Triggers")&&h.r32(row)==hash(sectionname));const auto kr=h.r32(section+60u);need(kr==h.r32(section+44u));const auto node=h.r32(kr+4u);need(h.r32(node)==0x78eb9cu);const auto key=owned(h,h.r32(node+12u)),payload=owned(h,h.r32(node+16u));need(h.r32(kr)==hash(key)&&!payload.empty()&&payload.size()<128u);
 const auto object=lookup(m,h,tag?0xaa79a8u:0x84e538u,key);need(m.r32(object)==(tag?0x79768cu:0x798934u));
 if(tag){need(m.r32(0x7976f0u)==0x6aa0e0u&&key.size()==8u);unsigned id=0u;for(char c:key){const unsigned digit=c>='0'&&c<='9'?unsigned(c-'0'):c>='A'&&c<='F'?unsigned(c-'A'+10):c>='a'&&c<='f'?unsigned(c-'a'+10):99u;need(digit<16u);id=(id<<4u)+digit;}need(m.r32(0xaa538cu)==0x797204u&&m.r32(0xaa5394u)==1000u&&m.r32(0xaa539cu)==1u);const auto a=m.r32(0xaa5390u);h.w32(a+8u,id);h.w32(a+12u,object);m.w32(0xaa539cu,2u);
 }else need(m.r32(0x798998u)==0x6e3730u);
 //The real helper writes the complete128/512-byte strncpy-padded buffer, delimiter NULs,
 //and, for the two absent Event/Action lookups, full512-byte empty-string padding. No private tail
 //is invented or compared. The real CRT TLS context is fetched through the
 //unchanged current-thread OS provider and its cursor is a produced output.
 s.produced=tag?128u:512u;std::fill(s.scratch.begin(),s.scratch.begin()+s.produced,0u);std::copy(payload.begin(),payload.end(),s.scratch.begin());std::vector<std::string>tokens;unsigned start=0u;for(unsigned k=0;k<=payload.size();++k)if(k==payload.size()||payload[k]==','){need(k>start);tokens.emplace_back(payload.substr(start,k-start));s.scratch[k]=0u;need(s.api!=nullptr);const auto context=s.api->current_thread(m.r32(0x817778u));need(context==i.cx+0x5000u);m.w32(context+24u,unsigned(reinterpret_cast<std::uintptr_t>(s.scratch.data()+(k<payload.size()?k+1u:k))));start=k+1u;}
 if(tag){need(tokens.size()==3u);m.w32(object+156u,decimal(tokens[0]));display(m,object,tokens[1]);const auto linked=lookup(m,h,0x84e538u,tokens[2]);m.w32(object+160u,linked);return(linked&0xffffff00u)|1u;}
 need(tokens.size()==8u&&equal(tokens[0],"<none>"));const auto descriptor=h.r32(m.r32(0xa1e03cu));need(descriptor!=0u);m.w32(object+164u,descriptor);m.w32(object+168u,lookup(m,h,0x84e538u,tokens[1]));display(m,object,tokens[2]);m.w8(object+159u,decimal(tokens[3])==0u);m.w8(object+156u,decimal(tokens[4])!=0u);m.w8(object+157u,decimal(tokens[5])!=0u);m.w8(object+158u,decimal(tokens[6])!=0u);need(m.r8(object+160u)==0u);if(decimal(tokens[7])!=0u)m.w8(object+160u,1u);need(hash("Events")!=h.r32(row)&&hash("Actions")!=h.r32(row));std::fill(s.scratch.begin(),s.scratch.end(),0u);return 1u;
}
unsigned cleanup(unsigned root,Memory&m,Heap&h,unsigned ini){need(root==0x2a9f30u||root==0x2e3ab0u);const auto index=m.r32(ini+32u),section=h.r32(index+4u),keyindex=h.r32(section+44u),node=h.r32(keyindex+4u);unsigned result=0u;for(auto p:{h.r32(section+12u),h.r32(node+12u),h.r32(node+16u),node,keyindex,section,index,m.r32(0xaa79acu),m.r32(0x84e53cu),m.r32(0xa1e03cu),m.r32(0xaa5390u)}){result=h.release(p);need(result!=0u);}return result;}
}
