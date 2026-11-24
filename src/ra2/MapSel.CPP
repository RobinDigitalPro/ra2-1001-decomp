// C:\RA2\MapSel.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Campaign map selection between missions. In this build the selection runs without user
// interaction: it looks up the current stage of the player's side and picks a follow-up scenario.
// Class names come from RTTI (.?AVMapSelect@@ vtable 0x791074 : .?AVMSEngine@@ vtable 0x791ffc;
// MapStage, MapSelection, MSSfxEntry, MSFont from vector/RTTI type names); all other names
// (methods, members, the string classes and globals) are provisional.
#include "GAMECONST.H"
#include <string.h>
#include "VECTOR.H"
#include "SURFACE.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x6eeb60
void Debug_Printf(char const * format, ...);        // 0x4068f0 (empty in this build)

// Simple owned narrow string, one pointer (library code near 0x759250; RTTI of its vectors calls it
// Wstring; provisional name as in WDTTerr.cpp).
class CharStringClass {
public:
    CharStringClass();                                          // 0x759250
    CharStringClass(char const * string);                       // 0x759260
    CharStringClass(CharStringClass const & string);            // 0x7592c0
    ~CharStringClass();                                         // 0x759320
    bool operator == (char const * string) const;               // 0x759340
    bool operator == (CharStringClass const & string) const;    // 0x7593b0
    bool operator != (char const * string) const;               // 0x759420
    CharStringClass & operator = (char const * string);         // 0x759500
    CharStringClass & operator = (CharStringClass const & string);   // 0x759570
    char const * Peek_Buffer() const;                           // 0x75a030 (Buffer or NullString)
    operator char const * () const;                             // 0x75a070 (same code as 0x75a030)
    unsigned Get_Length() const;                                // 0x75a0e0
    void To_Lower();                                            // 0x75a760
    char * Buffer;
};

// Simple owned wide string, one pointer (library code near 0x75b2f0; provisional name).
class WideStringClass {
public:
    WideStringClass(WideStringClass const & string);            // 0x75b350
    ~WideStringClass();                                         // 0x75b390
    wchar_t * Buffer;
};

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624); see NullDlg.CPP.
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};

class SystemTimerClass {
public:
    long operator()() const;                    // 0x68fad0
};

// Count-down timer (start, timer source, delay); same as Power.CPP.
template<class T>
class CDTimerClass {
public:
    CDTimerClass(long set = 0) : Started(Timer()), DelayTime(set) {}
    operator long() const
    {
        long remain = DelayTime;
        if (Started != -1) {
            long elapsed = Timer() - Started;
            if (elapsed < remain) {
                remain -= elapsed;
            } else {
                remain = 0;
            }
        }
        return remain;
    }

    long Started;
    T Timer;
    long DelayTime;
};

// Music.
class ThemeClass {
public:
    int From_Name(char const * name);       // 0x6dd7d0
    void Play_Song(int theme);              // 0x6dd170
};
extern ThemeClass Theme;                    // 0xa1e0a8

extern Surface * HiddenSurface;            // 0x821c94

// RTTI .?AV?$TRect@H@@ (see WDTTerr.cpp).
template<class T>
class TRect {
public:
    TRect() {}
    T X;
    T Y;
    T Width;
    T Height;
};

// RTTI .?AVHouseTypeClass@@. Only the field used here.
class HouseTypeClass {
public:
    char Unknown00[0xbc];
    int Side;                               // +0xbc, index into Sides
};
extern DynamicVectorClass<HouseTypeClass *> HouseTypes;     // 0xa1e038

// RTTI .?AVSideClass@@ (AbstractTypeClass). Only the ID used here.
class SideClass {
public:
    char Unknown00[0x24];
    char ID[0x18];                          // +0x24 (AbstractTypeClass::ID)
};
extern DynamicVectorClass<SideClass *> Sides;               // 0x84e4e0

// Only the fields used here; layout not reconstructed (see Restate.cpp).
class ScenarioClass {
public:
    void Set_Scenario_Name(char const * name);  // 0x655760, copies at most 0x104 chars to ScenarioName
    char Unknown0[0x83c];
    char ScenarioName[0x104];               // +0x83c
    char Unknown940[0x11fc - 0x940];
    int HouseType;                          // +0x11fc, player's house type index (provisional)
    char Unknown1200[0x2304 - 0x1200];
    unsigned short Stage;                   // +0x2304, campaign stage index (provisional)
};

extern char NullString[];                   // 0x8248a4 (.bss), shared empty string
extern bool MapSelectFlag;                  // 0xa567f8 (.bss), cleared by MapSelect::Run; meaning unknown

// Fastcall helper that prepares a stage text for the given font and width (0x5ab580; provisional).
class MSFont;
void Format_Stage_Text(WideStringClass & text, MSFont * font, int width);

// RTTI .?AVMSFont@@, vtable 0x79208c (5 slots), size 0x20.
class MSFont {
public:
    MSFont(int style);                      // 0x5b0b20
    virtual ~MSFont();                      // slot 0: 0x5b1250
    char Unknown04[0x20 - 0x04];
};

// Objects owned by MapSelect at +0xac/+0xb0; only the virtual destructor is used here.
class MSAnim {
public:
    virtual ~MSAnim();
};

// Sound entry of a stage list (RTTI name from DynamicVectorClass<MSSfxEntry *>).
class MSSfxEntry {
public:
    void Play();                            // 0x5ae2b0
};

// One follow-up choice of a stage (RTTI name from DynamicVectorClass<MapSelection *>).
class MapSelection {
public:
    CharStringClass Stage;                  // +0x00, name of the target stage
};

// One campaign stage (RTTI name from DynamicVectorClass<MapStage *>). Layout partial.
class MapStage {
public:
    CharStringClass Name;                   // +0x00
    CharStringClass Scenario;               // +0x04
    CharStringClass Field08;                // +0x08, non-empty: select automatically (meaning provisional)
    int Unknown0C;
    WideStringClass Description;            // +0x10
    char Unknown14[0x54 - 0x14];
    DynamicVectorClass<MapSelection *> Selections;   // +0x54
};

// Stage list of one side, 0x5c bytes; code in MSChoice.cpp (class name not in RTTI, provisional).
class MapChoiceClass {
public:
    MapChoiceClass();                                           // 0x5acaf0
    ~MapChoiceClass();                                          // 0x5acb80
    bool Init(CharStringClass const & side);                    // 0x5acc10
    void Clear();                                               // 0x5ad310
    MapStage * Find_Stage(CharStringClass const & name);        // 0x5ad3d0, by MapStage::Name
    MapStage * Find_Scenario(CharStringClass const & scenario); // 0x5ad480, by MapStage::Scenario
    MapStage * Get_Stage(unsigned short index);                 // 0x5ad530
    int Stage_Index(MapStage * stage);                          // 0x5ad550
    MSSfxEntry * Find_Sfx(CharStringClass const & name);        // 0x5ad560
    TRect<int> Get_Rect() const { return Rect; }

    DynamicVectorClass<MapStage *> Stages;  // +0x00
    TRect<int> Rect;                        // +0x18
    char Unknown28[0x5c - 0x28];
};

// RTTI .?AVMSEngine@@, vtable 0x791ffc (3 slots). Code in MSChoice.cpp.
class MSEngine {
public:
    MSEngine();                                     // 0x5af7c0
    virtual ~MSEngine();                            // 0x5af850 (deleting 0x5b0420)
    virtual void Virtual_01(int value) {}           // slot 1: 0x58cb90 (emitted here)
    virtual void Virtual_02();                      // slot 2: 0x5b0410
    char Unknown04[0x48 - 0x04];
    int XOffset;                                    // +0x48
    int YOffset;                                    // +0x4c
};

// RTTI .?AVMapSelect@@, vtable 0x791074 (3 slots), size 0xdc.
class MapSelect : public MSEngine {
public:
    MapSelect() {}
    virtual void Virtual_02();                      // slot 2: 0x58cac0

    bool Select_Scenario(ScenarioClass * scen, CharStringClass const & scenario);
    bool Run(ScenarioClass * scen);
    bool Init(ScenarioClass * scen);
    void Cleanup();
    int Unknown_58CAF0(int value);
    void Play_Sound(CharStringClass const & name);
    void Queue_Sound(CharStringClass const & name, long delay);
    void Unknown_58CB70(int value);
    void Unknown_58CB80(int value);

    MapChoiceClass Choices;                         // +0x50
    MSAnim * Anim1;                                 // +0xac
    MSAnim * Anim2;                                 // +0xb0
    MSFont * Font;                                  // +0xb4
    TRect<int> Rect;                                // +0xb8
    CharStringClass SoundName;                      // +0xc8
    CDTimerClass<SystemTimerClass> SoundTimer;      // +0xcc
    int FieldD8;                                    // +0xd8
};

// ---- end of local declarations ----

// Chooses the scenario that follows the current campaign stage. Returns its name or NULL.
char const * Map_Selection(ScenarioClass * scen)
{
    if (!MapSelect().Run(scen)) {
#line 134 "C:\\RA2\\MapSel.CPP"
        WWMessageBox().Process(Fetch_String("MSG:UnableMapSelect", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
        return NULL;
    }
    Debug_Printf("MapSelect: Scenario - %s, Stage - %ld\n", scen->ScenarioName, scen->Stage);
    return strlen(scen->ScenarioName) ? scen->ScenarioName : NULL;
}

// Selects the given follow-up scenario of the current stage. Returns the name or NULL.
char const * Map_Selection(ScenarioClass * scen, char const * scenario)
{
    bool failed;
    {
        CharStringClass name(scenario);
        failed = !MapSelect().Select_Scenario(scen, name);
    }
    if (failed) {
#line 152 "C:\\RA2\\MapSel.CPP"
        WWMessageBox().Process(Fetch_String("MSG:UnableMapSelect", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
        return NULL;
    }
    return scenario;
}

bool MapSelect::Select_Scenario(ScenarioClass * scen, CharStringClass const & scenario)
{
    if (scen == NULL || scenario == NULL) {
        return false;
    }

    SideClass * side = Sides[HouseTypes[scen->HouseType]->Side];
    if (side == NULL) {
        Debug_Printf("MapSelect: Invalid side!\n");
        return false;
    }
    Debug_Printf("MapSelect: Side %s\n", side->ID);

    if (!Choices.Init(side->ID)) {
        Choices.Clear();
        Debug_Printf("MapSelect: Unable to initialize choices!\n");
        return false;
    }

    MapStage * stage = Choices.Get_Stage(scen->Stage);
    if (stage == NULL) {
        Choices.Clear();
        Debug_Printf("MapSelect: Invalid stage!\n");
        return false;
    }

    scen->Set_Scenario_Name(NullString);
    for (int index = 0; index < stage->Selections.ActiveCount; index++) {
        MapSelection * selection = stage->Selections[index];
        if (selection != NULL) {
            MapStage * next = Choices.Find_Stage(selection->Stage);
            CharStringClass name = next->Scenario;
            name.To_Lower();
            CharStringClass wanted = scenario;
            wanted.To_Lower();
            if (next != NULL && name == wanted) {
                scen->Set_Scenario_Name(next->Scenario);
                scen->Stage = Choices.Stage_Index(next);
                break;
            }
        }
    }
    Choices.Clear();
    return strlen(scen->ScenarioName) > 0;
}

bool MapSelect::Run(ScenarioClass * scen)
{
    if (!Init(scen)) {
        return false;
    }

    MapSelectFlag = false;
    MapStage * stage = Choices.Find_Scenario(scen->ScenarioName);
    Debug_Printf("MapSelect: Stage: %s\n", stage->Name);
    if (stage->Field08 != NULL) {
        Theme.Play_Song(Theme.From_Name("LOADING"));
        char const * selected = stage->Selections[0]->Stage;
        if (selected != NULL) {
            Debug_Printf("Selected %s\n", selected);
            MapStage * next = Choices.Find_Stage(selected);
            CharStringClass name = next->Scenario;
            if (name.Get_Length()) {
                scen->Set_Scenario_Name(name.Peek_Buffer());
                scen->Stage = Choices.Stage_Index(next);
            }
        }
    }
    Cleanup();
    return true;
}

bool MapSelect::Init(ScenarioClass * scen)
{
    Anim1 = NULL;
    Anim2 = NULL;
    Font = NULL;

    if (scen == NULL) {
        Debug_Printf("MapSelect: Invalid Scenario pointer!\n");
        return false;
    }

    SideClass * side = Sides[HouseTypes[scen->HouseType]->Side];
    if (side == NULL) {
        Debug_Printf("MapSelect: Invalid side!\n");
        return false;
    }
    Debug_Printf("MapSelect: Side %s\n", side->ID);

    if (!Choices.Init(side->ID)) {
        Choices.Clear();
        Debug_Printf("MapSelect: Unable to initialize choices!\n");
        return false;
    }

    MapStage * stage = Choices.Find_Scenario(scen->ScenarioName);
    if (stage == NULL) {
        Debug_Printf("MapSelect: Invalid stage!\n");
        Cleanup();
        return false;
    }

    Font = new MSFont(1);
    if (Font == NULL) {
        Debug_Printf("MapSelect: Unable to create font!\n");
        Cleanup();
        return false;
    }

    XOffset = (HiddenSurface->Get_Width() - 640) / 2;
    YOffset = (HiddenSurface->Get_Height() - 400) / 2;
    Rect = Choices.Get_Rect();
    Rect.X += XOffset;
    Rect.Y += YOffset;

    int index = 0;
    do {
        WideStringClass text = stage->Description;
        Format_Stage_Text(text, Font, Rect.Width);
        stage = Choices.Get_Stage(++index);
    } while (stage != NULL);

    SoundName = NULL;
    SoundTimer = 0;
    FieldD8 = -1;
    return true;
}

void MapSelect::Cleanup()
{
    if (Font != NULL) {
        delete Font;
        Font = NULL;
    }
    if (Anim2 != NULL) {
        delete Anim2;
        Anim2 = NULL;
    }
    if (Anim1 != NULL) {
        delete Anim1;
        Anim1 = NULL;
    }
    Choices.Clear();
}

void MapSelect::Virtual_02()
{
    if (SoundName != NULL && !SoundTimer) {
    }
}

int MapSelect::Unknown_58CAF0(int)
{
    return 0;
}

void MapSelect::Play_Sound(CharStringClass const & name)
{
    if (name != NULL) {
        MSSfxEntry * sfx = Choices.Find_Sfx(name);
        if (sfx != NULL) {
            sfx->Play();
        }
    }
}

void MapSelect::Queue_Sound(CharStringClass const & name, long delay)
{
    SoundName = name;
    SoundTimer = delay;
}

void MapSelect::Unknown_58CB70(int)
{
}

void MapSelect::Unknown_58CB80(int)
{
}
