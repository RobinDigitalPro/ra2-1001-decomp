#include "recovered/recovery_b1624.hpp"
// Unchanged accepted algorithm helpers, visible only in this translation unit.
// Their old run()/fixture guards are not called or relaxed.
#include "recovered/recovery_b999_parser.inc"
} // namespace ra2::recovered::b999 opened by the helper include
namespace ra2::recovered::b1624 {
namespace {
void need(bool x,const char*why){if(!x)throw std::domain_error(why);}
U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
std::string literal(Memory&m,U a,U count){std::string s;for(U k=0;k<count;++k){const U c=m.r8(a+k);need(c!=0,"1624 premature literal NUL");s.push_back(char(c));}need(m.r8(a+count)==0,"1624 literal extent");return s;}
void empty_lists(Memory&m,U self,U vptr){m.w32(self,vptr);m.w32(self+4,0x785aec);m.w32(self+8,0x785afc);m.w32(self+0xc,self+0x14);m.w32(self+0x10,0);m.w32(self+0x14,0x785afc);m.w32(self+0x18,0);m.w32(self+0x1c,self+8);for(U off:{0x20u,0x24u,0x28u,0x30u,0x34u})m.w32(self+off,0);m.w8(self+0x2c,0);}
}
U run(U root,Memory&m,const Inputs&i,Heap&h,FileApi&api){
 need(root==0x902f0&&i.cx!=0,"1624 selected receiver/root");const U self=i.cx;(void)m.r8(self+0x58);
 need(api.create_file_a&&api.read_file&&api.close_handle,"1624 real provider bindings required");
 need(m.r32(0x817554)==0&&m.r32(0xb10e14)==0&&m.r8(0xa9e184)==0,"1624 ordinary CRT/noIOerror");
 need(m.r32(0xb10530)==0&&m.r32(0xa588e0)==0&&m.r32(0x838be0)==0,"1624 ASCII/noarchives/nopathlist");
 const auto path_literal=literal(m,0x7c027c,12),section_query=literal(m,0x7c0270,9);
 need(path_literal=="CoopCamp.ini"&&section_query=="Campaigns","1624 actual PE literals");
 need(m.r32(0x7856a0+4)==0x401940&&m.r32(0x7856a0+8)==0x46fd50&&m.r32(0x7856a0+0x14)==0x468dc0&&m.r32(0x7856a0+0x18)==0x468e00&&m.r32(0x7856a0+0x1c)==0x468e40&&m.r32(0x7856a0+0x24)==0x468c80&&m.r32(0x7856a0+0x34)==0x468e10,"1624 normal derived file slots");
 need(m.r32(0x7889b4)==0x75f1e0&&m.r32(0x78eb9c)==0x50fe00&&m.r32(0x78eba4)==0x50feb0,"1624 actual reader/node/section slots");
 // 490C60 and Root490305..32B: only constructor-authored public bytes.
 empty_lists(m,self,0x785ae4);m.w8(self+0x38,0);
 // 468B70 ->630110 ->779146 actual owned name clone: nominal13, rounded16.
 const U name=h.allocate(U(path_literal.size()+1));b999::write_z(h,name,path_literal);
 const U reader=h.allocate_reader();
 // 468DC0 ->5928A0 uppercases the owned name before checking empty archive.
 for(U k=0;k<12;++k){const U c=h.r8(name+k);if(c>='a'&&c<='z')h.w8(name+k,c-32);}
 std::string upper;for(U k=0;k<12;++k)upper.push_back(char(h.r8(name+k)));
 const U archive_hash=b999::hash_text(upper);(void)archive_hash;
 const char*path=reinterpret_cast<const char*>(std::uintptr_t(name));
 // Derived availability probe, then derived Open1's own raw availability.
 for(U n=0;n<2;++n){const HANDLE probe=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(probe!=INVALID_HANDLE_VALUE,"1624 genuine physical availability");need(api.close_handle(probe)!=FALSE,"1624 actual probe close BOOL");}
 const HANDLE input=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(input!=INVALID_HANDLE_VALUE,"1624 actual Open1");
 DWORD got=0,eof=0;need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(reader)),4096,&got,nullptr)!=FALSE&&got==40,"1624 actual40-byte positive input");
 need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(reader+got)),4096-got,&eof,nullptr)!=FALSE&&eof==0,"1624 first real EOF");
 need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(reader)),4096,&eof,nullptr)!=FALSE&&eof==0,"1624 second real EOF");
 const std::string text(reinterpret_cast<const char*>(std::uintptr_t(reader)),got),prefix="[Profile001]\r\nPlayerFaction=";
 need(text.size()==40&&text.compare(0,prefix.size(),prefix)==0&&text.substr(38)=="\r\n","1624 real parsed syntax");const auto value=text.substr(prefix.size(),10);need(value.substr(0,9)=="Profile00"&&value[9]>='0'&&value[9]<='9',"1624 positive value domain");
 const U section=h.allocate(68),section_name=h.allocate(11),node=h.allocate(40),value_copy=h.allocate(11),key=h.allocate(14),keytable=h.allocate(80),sectiontable=h.allocate(80);
 b999::write_z(h,section_name,"Profile001");b999::write_z(h,value_copy,value);b999::write_z(h,key,"PlayerFaction");
 b999::build_single_section(h,h,section,section_name,node,key,value_copy,keytable,sectiontable,"Profile001","PlayerFaction");
 h.w32(section+4,self+0x14);h.w32(section+8,self+8);m.w32(self+0xc,section);m.w32(self+0x1c,section);m.w32(self+0x20,sectiontable);m.w32(self+0x24,1);m.w32(self+0x28,10);m.w8(self+0x2c,0);m.w32(self+0x30,0);m.w32(self+0x34,0);
 h.free_reader(reader);m.w8(self+0x38,0);need(api.close_handle(input)!=FALSE,"1624 reader75F240 real close");
 // 50BF50 ->5106D0: fresh one-row table is sorted (qsort count1 is empty),
 // then the actual signed binary search misses Campaigns without caching it.
 const U query=b999::hash_text(section_query);need(m.r32(self+0x24)==1&&m.r8(self+0x2c)==0&&m.r32(self+0x30)==0,"1624 cold exactindex");m.w32(self+0x30,0);m.w8(self+0x2c,1);
 std::int32_t count=1;U at=sectiontable,found=0;while(count>0){const auto mid=count/2;const U p=at+U(mid)*8;const auto stored=std::int32_t(h.r32(p));if(stored>std::int32_t(query))count=mid;else if(stored==std::int32_t(query)){found=p;break;}else{at=p+8;count-=mid+1;}}
 need(found==0,"1624 actual Campaigns miss, no creation loop");m.w32(self+0x54,0);m.w32(self+0x50,0);m.w8(self+0x58,1);
 // 438290 sees null holder, then42F250/630060 sees alreadyclosed handle.
 need(h.release(name)!=0,"1624 real owned filename final free BOOL");return self;
}
void cleanup(Memory&m,U self,Heap&h){
 need(m.r32(self+0x50)==0&&m.r32(self+0x54)==0&&m.r8(self+0x58)==1,"1624 empty campaign cleanup");
 const U table=m.r32(self+0x20),section=h.r32(table+4),node=h.r32(h.r32(section+0x2c)+4);
 b999::destroy_single_section(h,section,node,table,0);
 empty_lists(m,self,0x78db34);m.w32(self+4,0x785af4);
 // 90A80 skips array-loop clear58 when+50 isNULL: successbyte remains1.
}
}
