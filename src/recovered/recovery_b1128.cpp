#include "recovery_b1128.hpp"
#include "platform/ole_storage973.hpp"
#include <array>
#include <string>
namespace ra2::recovered::b1128{
static void need(bool x){if(!x)throw std::domain_error("1128 finite actual-storage metadata fallback");}
static IStream*stream(IStorage*storage,unsigned selector,Observation&o){IStream*s=nullptr;need(storage->OpenStream(platform::ole_storage973::item(selector).name,nullptr,0x10u,0u,&s)==S_OK&&s);++o.streams;return s;}
static std::wstring wide(IStorage*storage,unsigned selector,Observation&o){auto*s=stream(storage,selector,o);std::wstring v;for(unsigned k=0;;++k){wchar_t c=0;need(k<64u&&s->Read(&c,2u,nullptr)==S_OK);++o.units;if(!c)break;v.push_back(c);}need(s->Release()==0u);return v;}
static void wide_store(Memory&m,unsigned output,const std::wstring&v){for(unsigned k=0;k<=v.size();++k)m.w16(output+2u*k,k<v.size()?unsigned(v[k]):0u);}
static void fixed(IStorage*storage,unsigned selector,Memory&m,unsigned output,unsigned n,Observation&o){for(unsigned k=0;k<n;++k)m.w8(output+k,0u);auto*s=stream(storage,selector,o);std::array<unsigned char,8>v{};need(n<=v.size()&&s->Read(v.data(),n,nullptr)==S_OK);for(unsigned k=0;k<n;++k)m.w8(output+k,v[k]);need(s->Release()==0u);}
static void narrow(IStorage*storage,unsigned selector,Memory&m,unsigned output,Api&api,Observation&o){m.w8(output,0u);auto*s=stream(storage,selector,o);std::wstring v;for(unsigned k=0;;++k){wchar_t c=0;need(k<64u&&s->Read(&c,2u,nullptr)==S_OK);++o.units;if(!c)break;v.push_back(c);}char text[127]{};const auto n=api.widetomb(CP_ACP,0u,v.c_str(),-1,text,127,nullptr,nullptr);need(n==int(v.size()+1u)&&n<=127);for(int k=0;k<n;++k)m.w8(output+unsigned(k),unsigned(static_cast<unsigned char>(text[k])));need(s->Release()==0u);++o.converted;}
static unsigned aggregate(Memory&m,unsigned record,IStorage*storage,Api&api,Observation&o){need(storage);IPropertySetStorage*sets=nullptr;need(storage->QueryInterface(iid_sets,reinterpret_cast<void**>(&sets))==S_OK&&sets);IPropertyStorage*property=nullptr;o.missing_open=sets->Open(summary,0x12u,&property);need(o.missing_open==STG_E_FILENOTFOUND&&property==nullptr);
 // The initial SummaryInformation Open fails genuinely. Original6516B0
 // returns before ReadMultiple; the aggregate restores every fallback field.
 wide_store(m,record+8u,wide(storage,2u,o));wide_store(m,record+0x108u,wide(storage,3u,o));
 fixed(storage,9u,m,record+4u,4u,o);fixed(storage,0x10u,m,record,4u,o);
 fixed(storage,0xcu,m,record+0x3d8u,8u,o);fixed(storage,0xdu,m,record+0x3e8u,8u,o);fixed(storage,0xau,m,record+0x3e0u,8u,o);
 narrow(storage,0x12u,m,record+0x2d4u,api,o);narrow(storage,4u,m,record+0x294u,api,o);
 fixed(storage,0x64u,m,record+0x18cu,4u,o);fixed(storage,0x65u,m,record+0x188u,4u,o);fixed(storage,0x66u,m,record+0x3f0u,4u,o);
 o.released_sets=sets->Release();need(o.streams==12u&&o.converted==2u);return 0u;
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Api&api,Observation&o){o={};if(root==0x250b20u)return aggregate(m,i.cx,reinterpret_cast<IStorage*>(std::uintptr_t(i.arg[0])),api,o);need(root==0x24f030u);wchar_t path[64]{};need(api.mbtowide(CP_ACP,0u,reinterpret_cast<const char*>(std::uintptr_t(i.cx)),-1,path,64)==10);IStorage*storage=nullptr;need(api.open(path,nullptr,0x12u,nullptr,0u,&storage)==S_OK&&storage);need(aggregate(m,i.dx,storage,api,o)==0u);o.released_storage=storage->Release();need(o.released_storage==0u);return(o.released_storage&0xffffff00u)|1u;}
}
