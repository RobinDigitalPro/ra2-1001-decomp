#pragma once
#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <ole2.h>
#include <propidl.h>
#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
namespace ra2::platform::ole_property990 {
inline void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
inline constexpr GUID fmtid{0xf29f85e0u,0x4ff9u,0x1068u,{0xabu,0x91u,8u,0u,0x2bu,0x27u,0xb3u,0xd9u}};
inline constexpr GUID control_fmtid{0xb990a201u,0x4a01u,0x4bb0u,{0x91u,3u,7u,6u,5u,4u,3u,2u}};
inline constexpr GUID iid_sets{0x0000013au,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}};
inline constexpr GUID iid_unknown{0u,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}};
inline bool guid_equal(const GUID&a,const GUID&b){return std::memcmp(&a,&b,16)==0;}
struct Value{ULONG id;VARTYPE type;std::int32_t integer=0;std::wstring text,name;bool operator==(const Value&o)const{return id==o.id&&type==o.type&&integer==o.integer&&text==o.text&&name==o.name;}bool operator!=(const Value&o)const{return !(*this==o);}};
struct Set{std::array<std::uint8_t,16>id{},class_id{};DWORD flags;std::vector<Value>values;bool operator==(const Set&o)const{return id==o.id&&class_id==o.class_id&&flags==o.flags&&values==o.values;}bool operator!=(const Set&o)const{return !(*this==o);}};
using Snapshot=std::vector<Set>;
struct Lifetime{std::uint32_t sets,storage,identity;ULONG refs;bool operator==(const Lifetime&o)const{return sets==o.sets&&storage==o.storage&&identity==o.identity&&refs==o.refs;}bool operator!=(const Lifetime&o)const{return !(*this==o);}};
inline std::uint32_t pointer(const void*p){static_assert(sizeof(void*)==4);return std::uint32_t(reinterpret_cast<std::uintptr_t>(p));}
inline Value read_value(IPropertyStorage*p,ULONG id){PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=id;PROPVARIANT v{};need(p->ReadMultiple(1,&spec,&v)==S_OK,"990 real complete ReadMultiple");Value out{id,v.vt,0,{},{}};if(v.vt==VT_LPWSTR){need(v.pwszVal!=nullptr,"990 nonnull readback string");out.text=v.pwszVal;}else if(v.vt==VT_I2)out.integer=v.iVal;else if(v.vt==VT_I4)out.integer=v.lVal;else{PropVariantClear(&v);throw std::runtime_error("990 bounded property types");}need(PropVariantClear(&v)==S_OK,"990 actual readback PropVariantClear");return out;}
class Storage{
 ILockBytes*lock_=nullptr;IStorage*storage_=nullptr;IPropertySetStorage*sets_=nullptr;Snapshot initial_;static inline Storage*active_=nullptr;
 static void write_string(IPropertyStorage*p,ULONG id,const std::wstring&s){PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=id;PROPVARIANT v{};v.vt=VT_LPWSTR;v.pwszVal=const_cast<wchar_t*>(s.c_str());need(p->WriteMultiple(1,&spec,&v,2u)==S_OK,"990 genuine fixture string write");}
 IPropertyStorage*create(const GUID&id){IPropertyStorage*p=nullptr;need(sets_->Create(id,nullptr,0u,0x1012u,&p)==S_OK&&p,"990 actual fixture property Create");PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=PID_CODEPAGE;PROPVARIANT v{};v.vt=VT_I2;v.iVal=1200;need(p->WriteMultiple(1,&spec,&v,2u)==S_OK,"990 explicit Unicode property codepage");return p;}
 public:
 Storage(){need(!active_,"990 exclusive provider");need(CreateILockBytesOnHGlobal(nullptr,TRUE,&lock_)==S_OK&&lock_,"990 actual lockbytes");need(StgCreateDocfileOnILockBytes(lock_,STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,&storage_)==S_OK&&storage_,"990 actual compound storage");need(storage_->QueryInterface(iid_sets,reinterpret_cast<void**>(&sets_))==S_OK&&sets_,"990 genuine IPropertySetStorage QueryInterface");active_=this;}
 ~Storage(){active_=nullptr;if(sets_)sets_->Release();if(storage_)storage_->Release();if(lock_)lock_->Release();}
 Storage(const Storage&)=delete;Storage&operator=(const Storage&)=delete;
 static Storage&current(){need(active_,"990 active provider");return *active_;}
 IPropertySetStorage*get()const{return sets_;}
 std::uint32_t address()const{return pointer(sets_);}
 Lifetime lifetime()const{IUnknown*q=nullptr;need(sets_->QueryInterface(iid_unknown,reinterpret_cast<void**>(&q))==S_OK&&q,"990 actual IUnknown identity");const auto id=pointer(q);q->Release();const auto add=sets_->AddRef(),release=sets_->Release();need(add==release+1u,"990 actual reference balance");return {address(),pointer(storage_),id,release};}
 void seed(const std::array<std::wstring,7>&strings){auto*p=create(fmtid);for(unsigned j=0;j<strings.size();++j)write_string(p,2u+j,strings[j]);need(p->Commit(STGC_DEFAULT)==S_OK,"990 fixture target property commit");p->Release();p=create(control_fmtid);write_string(p,2u,L"B990 control property set");PROPSPEC spec{};spec.ulKind=PRSPEC_PROPID;spec.propid=3u;PROPVARIANT number{};number.vt=VT_I4;number.lVal=0x19901022;need(p->WriteMultiple(1,&spec,&number,2u)==S_OK&&p->Commit(STGC_DEFAULT)==S_OK,"990 fixture unrelated integer property");p->Release();need(storage_->Commit(STGC_DEFAULT)==S_OK,"990 initial compound commit");initial_=snapshot();need(initial_.size()==2u,"990 exact two property sets");}
 const Snapshot&initial()const{return initial_;}
 void verify_seed(const std::array<std::wstring,7>&strings)const{unsigned targets=0,controls=0;for(const auto&set:initial_){GUID id{};std::memcpy(&id,set.id.data(),16u);if(guid_equal(id,fmtid)){++targets;need(set.values.size()==8u,"990 all seven seeded metadata properties plus codepage");for(const auto&v:set.values){if(v.id==PID_CODEPAGE)need(v.type==VT_I2&&v.integer==1200,"990 target Unicode codepage readback");else need(v.id>=2u&&v.id<=8u&&v.type==VT_LPWSTR&&v.text==strings[v.id-2u],"990 complete initial typed string oracle");}}else if(guid_equal(id,control_fmtid)){++controls;need(set.values.size()==3u,"990 control complete property count");for(const auto&v:set.values){if(v.id==PID_CODEPAGE)need(v.type==VT_I2&&v.integer==1200,"990 control codepage");else if(v.id==2u)need(v.type==VT_LPWSTR&&v.text==L"B990 control property set","990 control wide string");else need(v.id==3u&&v.type==VT_I4&&v.integer==0x19901022,"990 control integer");}}else throw std::runtime_error("990 unexpected extra property set");}need(targets==1u&&controls==1u,"990 exact target/control FMTIDs");}
 void reset_property(ULONG id,const std::wstring&s){IPropertyStorage*p=nullptr;need(sets_->Open(fmtid,0x12u,&p)==S_OK&&p,"990 reset actual property Open");write_string(p,id,s);need(p->Commit(STGC_DEFAULT)==S_OK,"990 reset actual Commit");p->Release();}
 Snapshot snapshot()const{
  IEnumSTATPROPSETSTG*enumerator=nullptr;need(sets_->Enum(&enumerator)==S_OK&&enumerator,"990 actual property-set enumeration");Snapshot out;
  for(;;){STATPROPSETSTG set{};ULONG got=0;const auto hr=enumerator->Next(1,&set,&got);if(!got){need(hr==S_FALSE,"990 property-set enumeration end");break;}need(hr==S_OK&&got==1u,"990 property-set enumeration item");Set image{};std::memcpy(image.id.data(),&set.fmtid,16);std::memcpy(image.class_id.data(),&set.clsid,16);image.flags=set.grfFlags;IPropertyStorage*p=nullptr;need(sets_->Open(set.fmtid,0x10u,&p)==S_OK&&p,"990 actual snapshot property Open");image.values.push_back(read_value(p,PID_CODEPAGE));IEnumSTATPROPSTG*rows=nullptr;need(p->Enum(&rows)==S_OK&&rows,"990 actual property enumeration");for(;;){STATPROPSTG row{};ULONG count=0;const auto status=rows->Next(1,&row,&count);if(!count){need(status==S_FALSE,"990 property enumeration end");break;}need(status==S_OK&&count==1u,"990 property enumeration row");const std::wstring name=row.lpwstrName?row.lpwstrName:L"";if(row.lpwstrName)CoTaskMemFree(row.lpwstrName);if(row.propid!=PID_CODEPAGE){auto value=read_value(p,row.propid);value.name=name;image.values.push_back(std::move(value));}else image.values[0].name=name;}rows->Release();p->Release();std::sort(image.values.begin(),image.values.end(),[](const Value&a,const Value&b){return a.id<b.id;});out.push_back(std::move(image));}
  enumerator->Release();std::sort(out.begin(),out.end(),[](const Set&a,const Set&b){return a.id<b.id;});return out;
 }
};
inline Snapshot project(Snapshot before,ULONG id,const std::wstring&text){std::array<std::uint8_t,16>bytes{};std::memcpy(bytes.data(),&fmtid,16);unsigned changed=0;for(auto&set:before)if(set.id==bytes)for(auto&value:set.values)if(value.id==id){need(value.type==VT_LPWSTR,"990 projection target wide string");value.text=text;++changed;}need(changed==1u,"990 exactly one projected property");return before;}
}

