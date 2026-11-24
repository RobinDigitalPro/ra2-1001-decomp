// C:\RA2\WDTProps.cpp (level-2 reconstruction of GAME.EXE 1.001)
// WorldDominationTour::CampaignProperties: the descriptive properties of a World Domination
// Tour campaign, read from the shared WDTState (class names from RTTI, all others provisional).
#include "GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----
#include <stddef.h>

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x2eeb60 (also in ABSTYPE.H)

// Simple owned narrow string, one pointer (library code near 0x359260; name provisional).
class CharStringClass {
public:
    CharStringClass(char const * string);           // 0x359260
    CharStringClass(CharStringClass const & string);
    ~CharStringClass();
    char * Buffer;
};

// Simple owned wide string, one pointer (library code near 0x35b300; name provisional).
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);           // 0x35b300
    WideStringClass(WideStringClass const & string);   // 0x35b350
    ~WideStringClass();                                 // 0x35b390
    wchar_t * Buffer;
};

extern char NullString[];   // 0x8248a4 (.bss); name provisional

// RTTI .?AVReferenceCounted@@, vtable 0x793cd4.
class ReferenceCounted {
public:
    ReferenceCounted() : ReferenceCount(0) {}
    virtual ~ReferenceCounted();                 // 0x230cb0 (deleting 0x230cf0)
    virtual bool Is_Kind(int kind) const;        // 0x230ce0 (returns false; name provisional)
    virtual void Release();                      // 0x230cc0
    void Add_Ref() { ++ReferenceCount; }
    int ReferenceCount;
};

// RTTI .?AVrc_ptr_base@@, vtable 0x793ccc.
class rc_ptr_base {
public:
    rc_ptr_base();                               // 0x230a80
    rc_ptr_base(ReferenceCounted * pointer);     // 0x230a90
    rc_ptr_base(rc_ptr_base const & other);      // 0x230b00
    virtual ~rc_ptr_base();                      // 0x230ab0 (deleting 0x230b20)
    void Set(ReferenceCounted * pointer);        // 0x230ad0
protected:
    ReferenceCounted * Pointer;
};

template<class T>
class rc_ptr : public rc_ptr_base {
public:
    rc_ptr() {}
    rc_ptr(T * pointer) { Set(pointer); }
    rc_ptr(rc_ptr<T> const & other) { Set(other.Pointer); }
    virtual ~rc_ptr() {}
    T * Get() const { return (T *)Pointer; }
    T * operator -> () const { return (T *)Pointer; }
};

// RTTI .?AVWDTState@@, vtable 0x79a198. Only the fields used here are named.
class WDTState : public ReferenceCounted {
public:
    char * ShortDescriptionLabel;    // +08
    char * LongDescriptionLabel;     // +0C
    char * CampaignName;             // +10
    bool IsEnabled;                  // +14
    int CampaignID;                  // +18
    int Unknown1C;                   // +1C
    int Unknown20;                   // +20
    int StageCount;                  // +24
};

namespace WorldDominationTour {

// RTTI .?AVCampaignProperties@WorldDominationTour@@, vtable 0x79a1dc, size 0x18.
class CampaignProperties : public ReferenceCounted {
public:
    CampaignProperties(rc_ptr<WDTState> const & state);
    virtual ~CampaignProperties();

    static rc_ptr<CampaignProperties> Create(rc_ptr<WDTState> const & state);

    int Campaign_ID() const;
    int Is_Available() const;
    int Is_Enabled() const;
    int Last_Stage() const;
    CharStringClass Campaign_Name() const;

    rc_ptr<WDTState> State;              // +08
    WideStringClass ShortDescription;    // +10
    WideStringClass LongDescription;     // +14
};

}
// ---- end of local declarations ----

using namespace WorldDominationTour;

// 0x321d40
rc_ptr<CampaignProperties> CampaignProperties::Create(rc_ptr<WDTState> const & state)
{
    return rc_ptr<CampaignProperties>(new CampaignProperties(state));
}

// 0x321d80 (scalar deleting destructor 0x321ee0)
CampaignProperties::~CampaignProperties()
{
}

// 0x321db0; the original __LINE__ values of the two Fetch_String calls are 20 and 21.
#line 18 "C:\\RA2\\WDTProps.cpp"
CampaignProperties::CampaignProperties(rc_ptr<WDTState> const & state) :
    State(state),
    ShortDescription(state.Get() ? Fetch_String(state->ShortDescriptionLabel, NULL, __FILE__, __LINE__) : Fetch_String("\"WDT:DefaultShortDescription\"", NULL, __FILE__, __LINE__)),
    LongDescription(state.Get() ? Fetch_String(state->LongDescriptionLabel, NULL, __FILE__, __LINE__) : Fetch_String("\"WDT:DefaultLongDescription\"", NULL, __FILE__, __LINE__))
{
}

// 0x321e50
int CampaignProperties::Campaign_ID() const
{
    if (State.Get() != NULL) {
        return State->CampaignID;
    }
    return 0;
}

// 0x321e60
int CampaignProperties::Is_Available() const
{
    return true;
}

// 0x321e70
int CampaignProperties::Is_Enabled() const
{
    if (State.Get() != NULL) {
        return State->IsEnabled;
    }
    return true;
}

// 0x321e90
int CampaignProperties::Last_Stage() const
{
    if (State.Get() != NULL) {
        return State->StageCount - 1;
    }
    return 0;
}

// 0x321ea0 (no direct callers found)
CharStringClass CampaignProperties::Campaign_Name() const
{
    return CharStringClass(State.Get() ? State->CampaignName : NullString);
}

// (integrator 2026-11-18: the 0x321f30 initializer belongs to WDTSel.cpp; .bss ownership proof in its claims)
