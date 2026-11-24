// unidentified translation unit (GAMECONST.H initializers at 0x3250f0) (level-2 reconstruction of GAME.EXE 1.001)
// Inferred content: WorldDominationTour::State (RTTI .?AVState@WorldDominationTour@@, vtable 0x79a25c,
// size 0x14), the owner of every territory at one stage of a World Domination Tour campaign, taken
// from the shared WDTState. The original file name is unknown; class names come from RTTI, all
// other names are provisional.
//
// TU boundary: the 16-byte zeroing initializer 0x3250d0 (.bss 0xb0d440, directly before this file's
// GAMECONST data 0xb0d450..0xb0d47c) starts the file, followed by the GAMECONST initializers
// 0x3250f0..0x3252a0; the code runs from 0x3252c0 to 0x325544. The zeroing initializer 0x325550
// (.bss 0xb0d4b8, directly before WDTTerr.cpp's GAMECONST data 0xb0d4c8..) starts WDTTerr.cpp.
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----
#include <stddef.h>

// RTTI .?AVReferenceCounted@@, vtable 0x793cd4.
class ReferenceCounted {
public:
    ReferenceCounted() : ReferenceCount(0) {}
    virtual ~ReferenceCounted();                 // 0x230cb0 (deleting 0x230cf0)
    virtual bool Is_Kind(int kind) const;        // 0x230ce0
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
    T * operator -> ();
};

template<class T>
T * rc_ptr<T>::operator -> ()
{
    if (Pointer != NULL) {
        return (T *)Pointer;
    }
    return NULL;
}

// RTTI .?AVWDTState@@, vtable 0x79a198. Only the fields used here are named.
class WDTState : public ReferenceCounted {
public:
    char * ShortDescriptionLabel;    // +08
    char * LongDescriptionLabel;     // +0C
    char * CampaignName;             // +10
    bool IsEnabled;                  // +14
    int CampaignID;                  // +18
    int Unknown1C;                   // +1C
    unsigned TerritoryCount;         // +20
    unsigned StageCount;             // +24
    char Unknown28[0x44 - 0x28];     // +28
    unsigned char ** StageOwners;    // +44 (per stage: one owner code per territory)
};

namespace WorldDominationTour {

// RTTI .?AVState@WorldDominationTour@@, vtable 0x79a25c, size 0x14.
class State : public ReferenceCounted {
public:
    State();                                                                   // 0x3253b0
    State(rc_ptr<WDTState> const & state, unsigned stage);                     // 0x3253f0
    virtual ~State();                                                          // 0x3254a0 (deleting 0x325510)

    static rc_ptr<State> Create(rc_ptr<WDTState> const & state, unsigned stage);   // 0x3252c0
    static rc_ptr<State> Create();                                             // 0x325350

    int Get_Owner(unsigned territory);        // 0x325450 (non-const: the original reloads Campaign through the non-const operator->)
    int Get_Score(int side);                                             // 0x3254c0
    bool Is_Valid() const { return Campaign.Get() != NULL && Owners != NULL; }

    rc_ptr<WDTState> Campaign;       // +08
    unsigned char * Owners;          // +10 (owner code per territory: 0, 1 or 2)
};

}
// ---- end of local declarations ----

using namespace WorldDominationTour;

// 0x3252c0
rc_ptr<State> State::Create(rc_ptr<WDTState> const & state, unsigned stage)
{
    return rc_ptr<State>(new State(state, stage));
}

// 0x325350
rc_ptr<State> State::Create()
{
    return rc_ptr<State>(new State());
}

// 0x3253b0
State::State() :
    Owners(NULL)
{
}

// 0x3253f0
State::State(rc_ptr<WDTState> const & state, unsigned stage) :
    Campaign(state),
    Owners(NULL)
{
    if (Campaign.Get() != NULL && stage < Campaign.Get()->StageCount) {
        Owners = Campaign.Get()->StageOwners[stage];
    }
}

// 0x325450
int State::Get_Owner(unsigned territory)
{
    if (Is_Valid() && territory < Campaign->TerritoryCount) {
        switch (Owners[territory]) {
            case 0:
                return 1;
            case 1:
                return 2;
            case 2:
                return 3;
        }
    }
    return 0;
}

// 0x3254a0
State::~State()
{
}

// 0x3254c0
int State::Get_Score(int side)
{
    if (Is_Valid()) {
        int score = 0;
        unsigned char const * owner = Owners;
        unsigned count = Campaign->TerritoryCount;
        while (count--) {
            switch (*owner++) {
                case 1:
                    if (side == 2) {
                        ++score;
                    }
                    break;
                case 2:
                    if (side == 3) {
                        ++score;
                    }
                    break;
            }
        }
        return score;
    }
    return 0;
}
