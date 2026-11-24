#include "recovered/recovery_b937.hpp"
#include <array>
#include <stdexcept>
#include <string>
#include <string_view>

namespace ra2::recovered::recovery_b937 {
namespace {
constexpr std::uint32_t g_locale_info = 0x00b10710u;
constexpr std::uint32_t g_name = 0x00b10700u;
constexpr std::uint32_t g_region = 0x00b10704u;
constexpr std::uint32_t g_flags = 0x00b10708u;
constexpr std::uint32_t g_lcid = 0x00b1070cu;
constexpr std::uint32_t g_name_is_short = 0x00b106fcu;
constexpr std::uint32_t g_region_is_short = 0x00b106f4u;
constexpr std::uint32_t g_region_lcid = 0x00b106f0u;
constexpr std::uint32_t g_name_alpha_prefix = 0x00b106f8u;

struct Alias { const char* key; const char* value; std::uint32_t value_address; };
constexpr std::array<Alias,64> names{{
    {"american","ENU",0x008181d4u},{"american english","ENU",0x008181dcu},
    {"american-english","ENU",0x008181e4u},{"australian","ENA",0x008181ecu},
    {"belgian","NLB",0x008181f4u},{"canadian","ENC",0x008181fcu},
    {"chh","ZHH",0x00818204u},{"chi","ZHI",0x0081820cu},
    {"chinese","CHS",0x00818214u},{"chinese-hongkong","ZHH",0x0081821cu},
    {"chinese-simplified","CHS",0x00818224u},{"chinese-singapore","ZHI",0x0081822cu},
    {"chinese-traditional","CHT",0x00818234u},{"dutch-belgian","NLB",0x0081823cu},
    {"english-american","ENU",0x00818244u},{"english-aus","ENA",0x0081824cu},
    {"english-belize","ENL",0x00818254u},{"english-can","ENC",0x0081825cu},
    {"english-caribbean","ENB",0x00818264u},{"english-ire","ENI",0x0081826cu},
    {"english-jamaica","ENJ",0x00818274u},{"english-nz","ENZ",0x0081827cu},
    {"english-south africa","ENS",0x00818284u},{"english-trinidad y tobago","ENT",0x0081828cu},
    {"english-uk","ENG",0x00818294u},{"english-us","ENU",0x0081829cu},
    {"english-usa","ENU",0x008182a4u},{"french-belgian","FRB",0x008182acu},
    {"french-canadian","FRC",0x008182b4u},{"french-luxembourg","FRL",0x008182bcu},
    {"french-swiss","FRS",0x008182c4u},{"german-austrian","DEA",0x008182ccu},
    {"german-lichtenstein","DEC",0x008182d4u},{"german-luxembourg","DEL",0x008182dcu},
    {"german-swiss","DES",0x008182e4u},{"irish-english","ENI",0x008182ecu},
    {"italian-swiss","ITS",0x008182f4u},{"norwegian","NOR",0x008182fcu},
    {"norwegian-bokmal","NOR",0x00818304u},{"norwegian-nynorsk","NON",0x0081830cu},
    {"portuguese-brazilian","PTB",0x00818314u},{"spanish-argentina","ESS",0x0081831cu},
    {"spanish-bolivia","ESB",0x00818324u},{"spanish-chile","ESL",0x0081832cu},
    {"spanish-colombia","ESO",0x00818334u},{"spanish-costa rica","ESC",0x0081833cu},
    {"spanish-dominican republic","ESD",0x00818344u},{"spanish-ecuador","ESF",0x0081834cu},
    {"spanish-el salvador","ESE",0x00818354u},{"spanish-guatemala","ESG",0x0081835cu},
    {"spanish-honduras","ESH",0x00818364u},{"spanish-mexican","ESM",0x0081836cu},
    {"spanish-modern","ESN",0x00818374u},{"spanish-nicaragua","ESI",0x0081837cu},
    {"spanish-panama","ESA",0x00818384u},{"spanish-paraguay","ESZ",0x0081838cu},
    {"spanish-peru","ESR",0x00818394u},{"spanish-puerto rico","ESU",0x0081839cu},
    {"spanish-uruguay","ESY",0x008183a4u},{"spanish-venezuela","ESV",0x008183acu},
    {"swedish-finland","SVF",0x008183b4u},{"swiss","DES",0x008183bcu},
    {"uk","ENG",0x008183c4u},{"us","ENU",0x008183ccu}
}};
constexpr std::array<Alias,22> regions{{
    {"america","USA",0x0081811cu},{"britain","GBR",0x00818124u},
    {"china","CHN",0x0081812cu},{"czech","CZE",0x00818134u},
    {"england","GBR",0x0081813cu},{"great britain","GBR",0x00818144u},
    {"holland","NLD",0x0081814cu},{"hong-kong","HKG",0x00818154u},
    {"new-zealand","NZL",0x0081815cu},{"nz","NZL",0x00818164u},
    {"pr china","CHN",0x0081816cu},{"pr-china","CHN",0x00818174u},
    {"puerto-rico","PRI",0x0081817cu},{"slovak","SVK",0x00818184u},
    {"south africa","ZAF",0x0081818cu},{"south korea","KOR",0x00818194u},
    {"south-africa","ZAF",0x0081819cu},{"south-korea","KOR",0x008181a4u},
    {"trinidad & tobago","TTO",0x008181acu},{"uk","GBR",0x008181b4u},
    {"united-kingdom","GBR",0x008181bcu},{"united-states","USA",0x008181c4u}
}};

void need(bool ok,const char* text){if(!ok)throw std::domain_error(text);}
char lower_ascii(char c){return c>='A'&&c<='Z'?char(c+('a'-'A')):c;}
bool equal_ascii(std::string_view a,std::string_view b){
    if(a.size()!=b.size())return false;
    for(std::size_t i=0;i<a.size();++i)if(lower_ascii(a[i])!=lower_ascii(b[i]))return false;
    return true;
}
std::string guest_string(const Memory& m,std::uint32_t p,std::uint32_t limit=256){
    need(p!=0,"B937 string pointer is null");std::string out;out.reserve(32);
    for(std::uint32_t i=0;i<limit;++i){const auto c=static_cast<char>(m.r8(p+i));if(!c)return out;out.push_back(c);}
    throw std::domain_error("B937 finite route requires a NUL within the bounded string extent");
}
std::string global_string(const Memory& m,std::uint32_t p){
    for(const auto& a:names)if(p==a.value_address)return a.value;
    for(const auto& a:regions)if(p==a.value_address)return a.value;
    return guest_string(m,p);
}
template<std::size_t N> std::uint32_t alias_lookup(const Memory& m,std::uint32_t source,const std::array<Alias,N>& aliases){
    const auto value=guest_string(m,source);
    for(const auto& a:aliases)if(equal_ascii(value,a.key))return a.value_address;
    return source;
}
std::uint32_t leading_ascii_letters(std::string_view s){
    std::uint32_t n=0;for(char c:s){if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))++n;else break;}return n;
}
std::uint32_t parse_hex_id(std::string_view s){
    need(!s.empty()&&s.size()<=8,"B937 callback LCID text must be 1..8 hexadecimal bytes");
    std::uint32_t n=0;
    for(char c:s){std::uint32_t d{};if(c>='0'&&c<='9')d=std::uint32_t(c-'0');else if(c>='a'&&c<='f')d=std::uint32_t(c-'a'+10);else if(c>='A'&&c<='F')d=std::uint32_t(c-'A'+10);else throw std::domain_error("B937 callback LCID contains non-hex text");n=(n<<4)|d;}
    return n;
}
std::uint32_t parse_decimal(std::string_view s){
    need(!s.empty()&&s.size()<=10,"B937 code page text is outside finite decimal domain");
    std::uint32_t n=0;for(char c:s){need(c>='0'&&c<='9',"B937 code page must be decimal, not ACP/OCP");const auto d=std::uint32_t(c-'0');need(n<=(0xffffffffu-d)/10u,"B937 code page decimal overflows");n=n*10u+d;}return n;
}
int call_locale_info(const Ops& o,std::uint32_t id,std::uint32_t type,char* out,int capacity){
    need(o.get_locale_info_a,"B937 requires a captured real GetLocaleInfoA boundary");
    return o.get_locale_info_a(o.context,id,type,out,capacity);
}
std::string query_locale_info(const Ops& o,std::uint32_t id,std::uint32_t type,int capacity){
    need(capacity>0&&capacity<=120,"B937 locale output capacity outside finite route");
    std::array<char,120> out{};const int n=call_locale_info(o,id,type,out.data(),capacity);
    need(n>0&&n<=capacity,"B937 finite positive route requires successful GetLocaleInfoA");
    need(out[static_cast<std::size_t>(n-1)]=='\0',"B937 GetLocaleInfoA result must include its NUL terminator");
    return std::string(out.data(),static_cast<std::size_t>(n-1));
}
void write_guest_text(Memory& m,std::uint32_t dst,const std::string& s){
    for(std::size_t i=0;i<=s.size();++i)m.w8(dst+static_cast<std::uint32_t>(i),i==s.size()?0u:static_cast<std::uint8_t>(s[i]));
}
std::uint32_t callback_text(Memory& m,std::string_view callback,const Ops& o){
    const auto id=parse_hex_id(callback);
    const auto region_ptr=m.r32(g_region);
    const auto expected_region=global_string(m,region_ptr);
    const auto query_type=m.r32(g_region_is_short)?0x0007u:0x1002u;
    const auto actual_region=query_locale_info(o,id,query_type,0x78);
    const auto name_ptr=m.r32(g_name);
    const auto configured_name=global_string(m,name_ptr);
    const auto name_type=m.r32(g_name_is_short)?0x0003u:0x00001001u;
    const auto actual_name=query_locale_info(o,id,name_type,0x78);
    need(equal_ascii(actual_region,expected_region),
         "B937 positive callback requires the actual country comparison to match");
    need(equal_ascii(actual_name,configured_name),
         "B937 positive callback requires the actual full language-name comparison to match");
    m.w16(g_flags,m.r16(g_flags)|0x0304u);
    m.w32(g_lcid,id);
    m.w32(g_region_lcid,id);
    return ((~m.r32(g_flags))>>2)&1u;
}
}

std::uint32_t fun_0077afc6(Memory& m,const Inputs& in,const Ops& o){
    const auto text=guest_string(m,in.arg[0],9);
    return callback_text(m,text,o);
}

std::uint32_t fun_0077af3f(Memory& m,const Ops& o){
    need(m.r32(g_name)&&m.r32(g_region),"B937 enumeration root needs initialized name/region globals");
    need(o.get_locale_info_iat_value!=0&&m.r32(g_locale_info)==o.get_locale_info_iat_value,
         "B937 enumeration root requires initializer-bound GetLocaleInfoA IAT value");
    need(m.r32(g_flags)==0,"B937 enumeration root precondition is cleared result flags");
    const auto name=global_string(m,m.r32(g_name));
    const auto region=global_string(m,m.r32(g_region));
    const auto name_len=static_cast<std::uint32_t>(name.size());
    const auto region_len=static_cast<std::uint32_t>(region.size());
    m.w32(g_name_is_short,name_len==3u?1u:0u);
    m.w32(g_region_is_short,region_len==3u?1u:0u);
    m.w32(g_region_lcid,0u);
    m.w32(g_name_alpha_prefix,name_len==3u?2u:leading_ascii_letters(name));

    need(o.enum_callback_count&&o.enum_callback_text,"B937 requires captured EnumSystemLocalesA callback inputs");
    const auto count=o.enum_callback_count(o.context);
    need(count>0&&count<=4096,"B937 finite positive route needs a bounded nonempty locale enumeration");
    bool stopped=false;
    for(std::uint32_t i=0;i<count;++i){
        std::array<char,16> text{};
        need(o.enum_callback_text(o.context,i,text.data(),static_cast<std::uint32_t>(text.size())),
             "B937 callback text is unavailable from actual EnumSystemLocalesA observation");
        const auto keep_going=callback_text(m,text.data(),o);
        if(!keep_going){stopped=true;break;}
    }
    need(stopped,"B937 captured enumeration did not stop at a positive callback");
    auto flags=m.r32(g_flags);
    if((flags&0x00000300u)!=0x00000300u||(flags&0x7u)==0u)m.w32(g_flags,0u);
    return flags;
}

std::uint32_t fun_0077ad6a(Memory& m,const Inputs& in,const Ops& o){
    need(in.arg[0]!=0,"B937 initializer needs a nonnull locale triplet buffer");
    need(m.r32(g_locale_info)==0,"B937 initializer finite route begins with a zero API pointer global");
    std::uint32_t platform{};
    need(o.get_version_platform_id&&o.get_version_platform_id(o.context,platform),
         "B937 requires a successful real GetVersionExA observation");
    need(platform==2u,"B937 finite route includes only the observed Win32 NT version branch");
    need(o.get_locale_info_iat_value!=0,"B937 initializer requires the actual GetLocaleInfoA IAT target value");
    m.w32(g_locale_info,o.get_locale_info_iat_value);

    m.w32(g_name,in.arg[0]);
    const auto name=guest_string(m,in.arg[0],0x40u);
    need(!name.empty(),"B937 positive route requires a nonempty configured language-comparison token");
    m.w32(g_name,alias_lookup(m,in.arg[0],names));

    const auto input_region=in.arg[0]+0x40u;
    const auto region=guest_string(m,input_region,0x40u);
    need(!region.empty(),"B937 positive route requires a nonempty configured country-comparison token");
    m.w32(g_region,input_region);
    m.w32(g_region,alias_lookup(m,input_region,regions));
    const auto codepage_name=guest_string(m,in.arg[0]+0x80u,32);
    need(!codepage_name.empty(),"B937 positive route requires a nonempty third code-page string");
    need(codepage_name.find("ACP")==std::string::npos&&codepage_name.find("OCP")==std::string::npos,
         "B937 finite route excludes special ACP/OCP code-page tokens");

    m.w32(g_flags,0u);
    (void)fun_0077af3f(m,o);
    need(m.r32(g_flags)!=0,"B937 positive route requires a successful callback result");

    const auto selected_lcid=m.r32(g_region_lcid);
    const auto selected_for_validity=m.r32(g_lcid);
    need(selected_lcid==selected_for_validity&&selected_lcid!=0,
         "B937 finite route expects callback-selected LCID in both original globals");
    // For this finite route the caller supplies a decimal code-page token.
    // Original 0x77b3b4 takes the numeric parser path; only the separate ACP
    // and OCP tokens reach its LCTYPE 0x1004 / 0x000b queries.
    const auto codepage=parse_decimal(codepage_name);
    need(o.is_valid_code_page&&o.is_valid_code_page(o.context,codepage),
         "B937 positive route requires actual IsValidCodePage success");
    need(o.is_valid_locale&&o.is_valid_locale(o.context,m.r32(g_region_lcid),1u),
         "B937 positive route requires actual IsValidLocale(LCID_SUPPORTED) success");

    if(in.arg[1]){
        m.w16(in.arg[1],m.r16(g_region_lcid));
        m.w16(in.arg[1]+2u,m.r16(g_lcid));
        m.w16(in.arg[1]+4u,codepage);
    }
    if(in.arg[2]){
        const auto lang=query_locale_info(o,m.r32(g_region_lcid),0x1001u,0x40);
        const auto country=query_locale_info(o,m.r32(g_lcid),0x1002u,0x40);
        write_guest_text(m,in.arg[2],lang);
        write_guest_text(m,in.arg[2]+0x40u,country);
        char reverse[16]{};unsigned n=0;auto value=codepage;
        do{reverse[n++]=char('0'+value%10u);value/=10u;}while(value);
        for(unsigned i=0;i<n;++i)m.w8(in.arg[2]+0x80u+i,static_cast<std::uint8_t>(reverse[n-1u-i]));
        m.w8(in.arg[2]+0x80u+n,0u);
    }
    return 1u;
}
}
