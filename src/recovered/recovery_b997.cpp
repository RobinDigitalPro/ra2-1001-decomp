//Internal helper derivation provenance is recorded separately; same accepted
//ordinary979 allocator/real file API and exact parsed graph lifetime.
#include "recovery_b997_writer.inc"
std::uint32_t run(Memory&m,const Inputs&in,Heap&h,FileApi&api,EntryState entry,Observation*obs){
 need(entry.entry_esp>0x10000u,"997 explicit raw x86 entry ESP");
 need(in.cx!=0u&&in.arg[0]<=9u&&m.r32(in.cx+0x44u)!=in.arg[0],"997 useful changed nonnegative decimal faction0..9");
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u&&m.r32(0x838be0u)==0u,"997 genuine ordinary/directfilename route");
 need(m.r32(0x7889ccu)==0x75f130u&&m.r32(0x7889c4u)==0x75f100u&&m.r32(0x7889c0u)==0x6066f0u&&m.r32(0x785670u)==0x42f600u&&m.r32(0x785674u)==0x46fa10u&&m.r32(0x785688u)==0x42f730u&&m.r32(0x78568cu)==0x42fca0u&&m.r32(0x78eb9cu)==0x50fe00u&&m.r32(0x78eba4u)==0x50feb0u,"997 authentic original vtables");
 const auto section_text=read_z(m,m.r32(in.cx+0x48u)),key_text=read_z(m,0x7e4f5cu),filename_text=read_z(m,0x7e4fb0u);
 need(section_text=="Profile001"&&key_text=="PlayerFaction"&&filename_text=="WDTHist.ini"&&m.r8(0x7b994cu)=='%'&&m.r8(0x7b994du)=='d'&&m.r8(0x7b994eu)==0u,"997 pinned decimal/section/filename domain");
 //71B39B updates the persistent receiver before opening/reading the real file.
 m.w32(in.cx+0x44u,in.arg[0]);
 const auto filename=h.allocate(12u);write_z(h,filename,filename_text);
 const auto input=api.create_file_a(reinterpret_cast<const char*>(std::uintptr_t(filename)),GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(input!=INVALID_HANDLE_VALUE,"997 explicit actualmode1 open");
 //42F5E0/630240 and75F1E0 see the already-open real handle: no probe calls.
 const auto buffer=h.allocate_reader();DWORD got=0,eof=0;need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(buffer)),4096u,&got,nullptr)!=FALSE&&got>0u&&got<128u,"997 actualread");need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(buffer+got)),4096u-got,&eof,nullptr)!=FALSE&&eof==0u,"997 EOF1");need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(buffer)),4096u,&eof,nullptr)!=FALSE&&eof==0u,"997 EOF2");
 const std::string text(reinterpret_cast<const char*>(std::uintptr_t(buffer)),got),prefix="["+section_text+"]\r\n"+key_text+"=";need(text.size()==prefix.size()+3u&&text.compare(0,prefix.size(),prefix)==0u&&text.substr(text.size()-2u)=="\r\n","997 exact singleton syntax");const auto old=text.substr(prefix.size(),1u);need(old[0]>='0'&&old[0]<='9'&&unsigned(old[0]-'0')!=in.arg[0],"997 file value actually changes");
 const auto section=h.allocate(68u),name=h.allocate(11u),oldnode=h.allocate(40u),oldcopy=h.allocate(2u),keycopy=h.allocate(14u),keytable=h.allocate(80u),sectiontable=h.allocate(80u);write_z(h,name,section_text);write_z(h,oldcopy,old);write_z(h,keycopy,key_text);build_single_section(h,h,section,name,oldnode,keycopy,oldcopy,keytable,sectiontable,section_text,key_text);
 h.free_reader(buffer);need(api.close_handle(input)!=FALSE,"997 root explicit readclose");const auto input_free=h.release(filename);need(input_free!=0u,"997 inputownedfilenamefree");
 //759260 owns a key temporary only. Borrowed section holder at receiver+48h
 //is passed through75A070. Mode0 falls to exact %d. For integer0..9 the
 //771E65 signed/base10 path emits one remainder+'0' and a terminating NUL.
 const auto keytemp=h.allocate(14u);write_z(h,keytemp,key_text);const std::string value(1u,char('0'+in.arg[0]));const auto node=replace_existing(h,section,oldnode,keytable,key_text,value);h.release(keytemp);
 const auto output_filename=h.allocate(12u);write_z(h,output_filename,filename_text);const auto output=api.create_file_a(reinterpret_cast<const char*>(std::uintptr_t(output_filename)),GENERIC_WRITE,0u,nullptr,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);need(output!=INVALID_HANDLE_VALUE,"997 explicit actualmode2 open");save_singleton(h,api,output,section,node);
 //Already-open pipe flag remains0: root42F250 closes and frees filename.
 need(api.close_handle(output)!=FALSE,"997 destructor actualwriteclose");const auto output_free=h.release(output_filename);need(output_free!=0u,"997 outputownedfilenamefree");destroy_single_section(h,section,node,sectiontable,0u);
 if(obs){obs->input_filename_free_bool=input_free;obs->output_filename_free_bool=output_free;}
 //Root localINI=entryESP-E0; final50AD20 LEA EAX,[localINI+8].
 //No subsequent instruction changes EAX. Full stack address, no bit mask.
 return entry.entry_esp-0xd8u;
}
std::uint32_t fun_0071b380(Memory&m,const Inputs&i,Heap&h,FileApi&a,EntryState e){return ra2::recovered::b997::run(m,i,h,a,e);}
}
