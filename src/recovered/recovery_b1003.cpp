#include <algorithm>
#include <utility>
#include "recovery_b1003_graph.inc"
namespace {
std::string hz(Heap&h,unsigned p){std::string s;need(p!=0u,"1003 ownedstring");for(unsigned k=0;k<64u;++k){const auto c=h.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1003 boundedownedtext");}
void append(Heap&h,unsigned section,unsigned node){const auto last=h.r32(section+0x28u),next=h.r32(last+4u);h.w32(node+4u,next);h.w32(node+8u,last);if(next)h.w32(next+8u,node);h.w32(last+4u,node);}
unsigned new_node(Heap&h,const std::string&key,const std::string&value){const auto n=h.allocate(40u),v=h.allocate(unsigned(value.size()+1u));write_z(h,v,value);const auto k=h.allocate(unsigned(key.size()+1u));write_z(h,k,key);h.w32(n,0x78eb9cu);h.w32(n+4u,0u);h.w32(n+8u,0u);h.w32(n+0xcu,k);h.w32(n+0x10u,v);for(unsigned off=0x14u;off<=0x24u;off+=4u)h.w32(n+off,0u);return n;}
void destroy_node(Heap&h,unsigned node){h.release(h.r32(node+0xcu));h.w32(node+0xcu,0u);h.release(h.r32(node+0x10u));h.w32(node+0x10u,0u);for(unsigned off=0x14u;off<=0x24u;off+=4u)need(h.r32(node+off)==0u,"1003 nocomments/padding/child");h.w32(node+0x18u,0u);const auto next=h.r32(node+4u),prev=h.r32(node+8u);need(next&&prev,"1003 authentic linkednode");h.w32(prev+4u,next);h.w32(next+8u,prev);h.w32(node+4u,0u);h.w32(node+8u,0u);h.w32(node,0x785afcu);h.release(node);}
unsigned replace(Heap&h,unsigned section,unsigned table,const std::string&key,const std::string&value){
 need(h.r32(section+0x30u)==5u&&h.r32(section+0x34u)==10u&&h.r32(section+0x2cu)==table,"1003 actual5existingkeys/capacity10");std::array<std::pair<unsigned,unsigned>,5>rows{};for(unsigned k=0;k<5u;++k)rows[k]={h.r32(table+8u*k),h.r32(table+8u*k+4u)};
 //510220 qsort76D686 comparator510750 compares signedhashes. All5
 //different literalhashes are unique, so final permutation is exact.
 if(!h.r8(section+0x38u)){std::sort(rows.begin(),rows.end(),[](auto a,auto b){return (a.first^0x80000000u)<(b.first^0x80000000u);});for(unsigned k=0;k<5u;++k){h.w32(table+8u*k,rows[k].first);h.w32(table+8u*k+4u,rows[k].second);}h.w32(section+0x3cu,0u);h.w8(section+0x38u,1u);}
 const auto hash=hash_text(key);unsigned pos=5u;for(unsigned k=0;k<5u;++k)if(rows[k].first==hash){pos=k;break;}need(pos<5u,"1003 existinguniquekey");h.w32(section+0x3cu,table+8u*pos);const auto old=rows[pos].second;need(hz(h,h.r32(old+0xcu))==key,"1003 realexistingkeyidentity");
 //50DC64..9B shifts allfollowingrows left, zeros oldlastrow/count/cache.
 for(unsigned k=pos+1u;k<5u;++k){h.w32(table+8u*(k-1u),rows[k].first);h.w32(table+8u*(k-1u)+4u,rows[k].second);}h.w32(table+32u,0u);h.w32(table+36u,0u);h.w32(section+0x30u,4u);h.w32(section+0x3cu,0u);destroy_node(h,old);
 const auto node=new_node(h,key,value);append(h,section,node);h.w32(table+32u,hash);h.w32(table+36u,node);h.w32(section+0x30u,5u);h.w8(section+0x38u,0u);return node;
}
}
Fixture prepare(Memory&m,Heap&h,const std::array<unsigned,5>&oldv,const std::array<unsigned,5>&newv){
 Fixture f{};for(unsigned k=0;k<5u;++k){need(oldv[k]<=9u&&newv[k]<=9u&&oldv[k]!=newv[k],"1003 useful5changed singledigits");m.w32(globals[k],newv[k]);}const auto sectiontext=read_z(m,0x7e6d4cu);need(sectiontext=="WOnline","1003 authenticsectionliteral");f.section=h.allocate(68u);f.section_name=h.allocate(8u);write_z(h,f.section_name,sectiontext);
 //Reverse initial sourcekeyorder exercises nontrivial unlink/indexshift.
 const auto key4=read_z(m,key_literals[4]);f.old_nodes[4]=new_node(h,key4,std::string(1u,char('0'+oldv[4])));f.key_table=h.allocate(80u);f.section_table=h.allocate(80u);build_single_section(h,h,f.section,f.section_name,f.old_nodes[4],h.r32(f.old_nodes[4]+0xcu),h.r32(f.old_nodes[4]+0x10u),f.key_table,f.section_table,sectiontext,key4);
 for(int k=3;k>=0;--k){const auto key=read_z(m,key_literals[unsigned(k)]);const auto node=new_node(h,key,std::string(1u,char('0'+oldv[unsigned(k)])));f.old_nodes[unsigned(k)]=node;append(h,f.section,node);const unsigned row=4u-unsigned(k);h.w32(f.key_table+row*8u,hash_text(key));h.w32(f.key_table+row*8u+4u,node);h.w32(f.section+0x30u,row+1u);}
 m.w32(parser,0x78db34u);m.w32(parser+4u,0x785aecu);m.w32(parser+8u,0x785afcu);m.w32(parser+0xcu,f.section);m.w32(parser+0x10u,0u);m.w32(parser+0x14u,0x785afcu);m.w32(parser+0x18u,0u);m.w32(parser+0x1cu,f.section);m.w32(parser+0x20u,f.section_table);m.w32(parser+0x24u,1u);m.w32(parser+0x28u,10u);m.w8(parser+0x2cu,0u);m.w32(parser+0x30u,0u);m.w32(parser+0x34u,0u);m.w8(parser+0x38u,0u);h.w32(f.section+4u,parser+0x14u);h.w32(f.section+8u,parser+8u);return f;
}
unsigned run(Memory&m,const Inputs&,Heap&h,FileApi&api,const Fixture&f,Observation&o){
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u&&m.r8(0xa9e184u)==0u,"1003 authenticordinaryheap/noIOerror");need(m.r32(parser+0x20u)==f.section_table&&m.r32(parser+0x24u)==1u&&m.r32(parser+0x28u)==10u&&m.r32(parser+0x34u)==0u,"1003 freshsingle-sectionindex");need(m.r32(0x793c9cu)==0x630a70u&&m.r32(0x793ca0u)==0x6301a0u&&m.r32(0x793cb4u)==0x630420u&&m.r32(0x793cb8u)==0x6302f0u&&m.r32(0x7889ccu)==0x75f130u&&m.r32(0x7889c4u)==0x75f100u,"1003 actualRawFile/pipevirtuals");
 for(unsigned k=0;k<5u;++k){const auto value=m.r32(globals[k]);need(value<=9u,"1003 decimalmode0 singledigit");const auto key=read_z(m,key_literals[k]);
  //510440/5104E0 firstsort/cache singletonsection; subsequent4lookuphits.
  if(!k){m.w8(parser+0x2cu,1u);m.w32(parser+0x30u,f.section_table);}else need(m.r8(parser+0x2cu)==1u&&m.r32(parser+0x30u)==f.section_table,"1003 sectioncachehit");replace(h,f.section,f.key_table,key,std::string(1u,char('0'+value)));
 }
 o.chunks={"[",hz(h,h.r32(f.section+0xcu)),"]","\r\n"};for(unsigned node=h.r32(f.section+0x18u);node!=f.section+0x20u;node=h.r32(node+4u)){need(o.chunks.size()<24u,"1003 exactlyfive writerkeys");o.chunks.push_back(hz(h,h.r32(node+0xcu)));o.chunks.push_back("=");o.chunks.push_back(hz(h,h.r32(node+0x10u)));o.chunks.push_back("\r\n");}need(o.chunks.size()==24u,"1003 truefive-key writergraph");need(read_z(m,0x7c69c4u)=="RA2.INI","1003 actualborrowedPEfilename");
 //6300E0 constructs localRawFile793C84 borrowing7C69C4,ownerbyte1Ch0.
 //69510arg1lowbyte0 ordinary save: pipefirstwrite opens/closes actualmode2.
 o.raw_file=RawFileState{};o.raw_file.mode=2u;const auto output=api.create_file_a(reinterpret_cast<const char*>(std::uintptr_t(0x7c69c4u)),GENERIC_WRITE,0u,nullptr,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);need(output!=INVALID_HANDLE_VALUE,"1003 actualRawFileCreateAlways");o.raw_file.handle=unsigned(reinterpret_cast<std::uintptr_t>(output));o.written=0u;for(const auto&chunk:o.chunks){DWORD got=0;need(api.write_file(output,chunk.data(),DWORD(chunk.size()),&got,nullptr)!=FALSE&&got==chunk.size(),"1003 genuinecompleteWriteFile");o.written+=got;}need(api.close_handle(output)!=FALSE,"1003 genuinepipeownedflushclose");
 //630060 afterclosedhandle:630A70 XOREAX/SETNE gives0; MOVAL,[owner1C]
 //writes0,borrowedfilename skipsfree. Tailvptrstore/pops preserve fullEAX0.
 o.raw_file.handle=0xffffffffu;o.raw_file.vptr=0x793c3cu;o.destructor_full_eax=0u;return o.destructor_full_eax;
}
void cleanup(Memory&m,Heap&h,const Fixture&f){
 h.release(f.section_name);while(h.r32(f.section+0x18u)!=f.section+0x20u)destroy_node(h,h.r32(f.section+0x18u));h.release(f.key_table);
 for(unsigned off=0;off<=0x40u;off+=4u)if(off!=0x38u)h.w32(f.section+off,0u);h.w8(f.section+0x38u,0u);h.w32(f.section,0x785afcu);h.w32(f.section+0x10u,0x785af4u);h.w32(f.section+0x14u,0x785afcu);h.w32(f.section+0x18u,f.section+0x20u);h.w32(f.section+0x20u,0x785afcu);h.w32(f.section+0x28u,f.section+0x14u);h.release(f.section);h.release(f.section_table);
 m.w32(parser,0x78db34u);m.w32(parser+4u,0x785af4u);m.w32(parser+8u,0x785afcu);m.w32(parser+0xcu,parser+0x14u);m.w32(parser+0x10u,0u);m.w32(parser+0x14u,0x785afcu);m.w32(parser+0x18u,0u);m.w32(parser+0x1cu,parser+8u);for(auto off:{0x20u,0x24u,0x28u,0x30u,0x34u})m.w32(parser+off,0u);m.w8(parser+0x2cu,0u);
}
unsigned fun_00731930(Memory&m,const Inputs&i,Heap&h,FileApi&a,const Fixture&f,Observation&o){return ra2::recovered::b1003::run(m,i,h,a,f,o);}
}
