// C:\RA2\Event.CPP (level-2 reconstruction of GAME.EXE 1.001)
// EventClass: the network/queue event record. One constructor per data layout, the event
// name table (0x7c16fc) and Execute. The event names come from that table; all other names
// are provisional.
//
// TU boundary: 0xb59a0 (first GAMECONST.H initializer) .. 0xb7664 (end of the Execute jump
// table). The zeroing initializer 0xb7670 (.bss 0x84ded8) belongs to the next TU, whose
// GAMECONST block starts at 0xb7690.
#include "GAMECONST.H"
#include "RECT.H"

// Zero rectangle with its own dynamic initializer (0x4b5b70, .bss 0x83de60 directly before
// EmptyCell 0x83de70). Name provisional.
static RectangleStruct const ZeroRect(0, 0, 0, 0);

#include <string.h>
#include <wchar.h>
#include <stdio.h>
#include "POINT.H"
#include "ABSTRACT.H"
#include "VECTOR.H"
#include "SURFACE.H"

// ---- local declarations (to be moved to headers by the integrator) ----

void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
bool Save_Game(char const * file_name, wchar_t const * description, bool flag);   // 0x64c540 (provisional)
void Call_Back();                             // 0x4821e0 (provisional; see CampScor.cpp)

extern int Frame;                               // 0xa2896c, current game frame (NetDlg/Conquer: NetworkEventMode)

typedef unsigned char EventType;                // stored as one byte; passed as a byte argument
enum {
    EVENT_EMPTY, EVENT_POWERON, EVENT_POWEROFF, EVENT_ALLY, EVENT_MEGAMISSION, EVENT_MEGAMISSION_F,
    EVENT_IDLE, EVENT_SCATTER, EVENT_DESTRUCT, EVENT_DEPLOY, EVENT_DETONATE, EVENT_PLACE,
    EVENT_OPTIONS, EVENT_GAMESPEED, EVENT_PRODUCE, EVENT_SUSPEND, EVENT_ABANDON, EVENT_PRIMARY,
    EVENT_SPECIAL_PLACE, EVENT_EXIT, EVENT_ANIMATION, EVENT_REPAIR, EVENT_SELL, EVENT_SELLCELL,
    EVENT_SPECIAL, EVENT_FRAMESYNC, EVENT_MESSAGE, EVENT_RESPONSE_TIME, EVENT_FRAMEINFO,
    EVENT_SAVEGAME, EVENT_ARCHIVE, EVENT_ADDPLAYER, EVENT_TIMING, EVENT_PROCESS_TIME,
    EVENT_PAGEUSER, EVENT_REMOVEPLAYER, EVENT_LATENCYFUDGE, EVENT_MEGAFRAMEINFO,
    EVENT_PACKETTIMING, EVENT_ABOUTTOEXIT, EVENT_FALLBACKHOST, EVENT_ADDRESSCHANGE,
    EVENT_PLANCONNECT, EVENT_PLANCOMMIT, EVENT_PLANNODEDELETE, EVENT_ALLCHEER,
    EVENT_COUNT
};

// RTTI ids (values from Kind_Of comparisons; see Conquer.CPP).
enum RTTIType { RTTI_NONE = 0, RTTI_UNIT = 1, RTTI_AIRCRAFT = 2, RTTI_BUILDING = 6 };
enum MissionType { MISSION_NONE = -1 };         // mission (values below from usage, names unknown)
enum {
    MISSION_5 = 5, MISSION_7 = 7, MISSION_10 = 10, MISSION_11 = 11, MISSION_12 = 12,
    MISSION_16 = 16, MISSION_18 = 18, MISSION_19 = 19
};
enum { RADIO_OVER_OUT = 3 };                    // radio message 3 (name provisional)

typedef unsigned char NetNumType[4];
typedef unsigned char NetNodeType[6];

#pragma pack(push, 1)
class IPXAddressClass {
public:
    IPXAddressClass(NetNumType net, NetNodeType node);     // 0x522980
    void Set_Address(NetNumType net, NetNodeType node);    // 0x5229e0
    void Get_Address(NetNumType net, NetNodeType node);    // 0x522a60
    char * As_String();                                    // 0x522ca0 (name provisional)
private:
    NetNumType NetworkNumber;
    NetNodeType NodeAddress;
};

// Entry of the session player list (DynamicVectorClass<NodeNameType *> at 0xa27da8).
struct NodeNameType {
    wchar_t Name[20];               // +0x00 (assumed)
    IPXAddressClass Address;        // +0x28
    char Unknown32[0x5D - 0x32];
    int ID;                         // +0x5d, house index of the player
    int ProcessTime;                // +0x61 (name provisional)
};
#pragma pack(pop)

class EventClass;
class HouseClass;
class AbstractClass;
class ObjectClass;
class TechnoClass;
class BuildingClass;
class FootClass;

// Special (game option) flags, one dword (bit layout not reconstructed; name provisional).
struct SpecialClass {
    int Flags;
};

#pragma pack(push, 1)
// Packed object reference: ID and kind (5 bytes, passed by value in two stack words).
class TargetClass {
public:
    AbstractClass * As_Abstract() const;        // 0x6aae60
    TechnoClass * As_Techno() const;            // 0x6aaf60
    ObjectClass * As_Object() const;            // 0x6ab030
    BuildingClass * As_Building() const;        // 0x6abac0

    int ID;
    unsigned char RTTI;
};

// Event record, 0x6f bytes.
class EventClass {
public:
    EventClass(int house, SpecialClass data);                               // 0x4b5bc0 (SPECIAL)
    EventClass(int house, EventType type, TargetClass whom);                // 0x4b5c00
    EventClass(int house, EventType type, CellStruct const & cell);         // 0x4b5c70
    EventClass(int house, EventType type);                                  // 0x4b5ce0
    EventClass(int house, EventType type, int id);                          // 0x4b5d40
    EventClass(int house, EventType type, TargetClass src, TargetClass dest);   // 0x4b5da0
    EventClass(int house, int anim, int owner, Point2D const & where);      // 0x4b5e20 (ANIMATION)
    EventClass(int house, TargetClass whom, MissionType mission, TargetClass target, TargetClass destination, TargetClass follow);  // 0x4b5e80 (MEGAMISSION)
    EventClass(int house, TargetClass whom, MissionType mission, TargetClass target, TargetClass destination, int speed, int maxspeed);  // 0x4b5f00 (MEGAMISSION_F)
    EventClass(int house, EventType type, int rtti, int id, int flag);      // 0x4b5f90 (production)
    EventClass(int house, EventType type, RTTIType rtti, CellStruct const & cell);  // 0x4b6000
    EventClass(int house, EventType type, RTTIType rtti, int id, CellStruct const & cell);  // 0x4b6080
    EventClass(int house, EventType type, RTTIType rtti, int id, int flag, CellStruct const & cell);  // 0x4b6100
    EventClass(int house, EventType type, int id, CellStruct const & cell); // 0x4b6180
    EventClass(int house, EventType type, int a, int b);                    // 0x4b6200
    EventClass(int house, IPXAddressClass & address, unsigned char id);     // 0x4b6270 (ADDRESSCHANGE)

    void Execute();                                                         // 0x4b62d0

    static char const * EventNames[EVENT_COUNT];

    EventType Type;                     // +0x00
    bool IsExecuted;                    // +0x01
    signed char HouseID;                // +0x02
    int Frame;                          // +0x03
    union {                             // +0x07
        struct { TargetClass Whom; } Target;
        struct { short X; short Y; } Cell;
        struct { int ID; } Value;
        struct { SpecialClass Data; } Options;
        struct { void * Pointer; } Variable;
        struct { TargetClass Source; TargetClass Dest; } NavCom;
        struct { int ID; int Owner; int X; int Y; } Anim;
        struct {
            TargetClass Whom;           // +0x07
            unsigned char Mission;      // +0x0c
            unsigned char Unknown0D;    // +0x0d
            TargetClass Target;         // +0x0e
            TargetClass Destination;    // +0x13
            TargetClass Follow;         // +0x18
            bool IsPlanning;            // +0x1d
        } MegaMission;
        struct {
            TargetClass Whom;           // +0x07
            unsigned char Mission;      // +0x0c
            TargetClass Target;         // +0x0d
            TargetClass Destination;    // +0x12
            int Speed;                  // +0x17
            int MaxSpeed;               // +0x1b
        } MegaMission_F;
        struct { int RTTI; int ID; int Flag; } Production;
        struct { int RTTI; int ID; int Flag; short X; short Y; } Place;
        struct { int ID; short X; short Y; } CellID;
        struct { int A; int B; } Pair;
        struct { int CRC; unsigned short CommandCount; unsigned char Delay; } FrameInfo;
        struct { unsigned short DesiredFrameRate; unsigned short MaxAhead; unsigned char FrameSendRate; } Timing;
        struct { unsigned short AverageTicks; } ProcessTime;
        struct { signed char ID; unsigned char IP[4]; } Address;
        unsigned char Raw[0x68];
    } Data;
};
#pragma pack(pop)

// Fixed-size ring buffer with time stamps (OutList at 0xa1a668: Count, Head, Tail, Array, Timings).
template<class T, int size> class QueueClass {
public:
    int Add(T const & q)
    {
        if (Count < size) {
            Array[Tail] = q;
            Timings[Tail] = timeGetTime();
            Tail = (Tail + 1) & (size - 1);
            Count = Count + 1;
            return 1;
        }
        return 0;
    }

    int Count;
    int Head;
    int Tail;
    T Array[size];
    int Timings[size];
};
extern QueueClass<EventClass, 128> OutList;     // 0xa1a668

// Object hierarchy. Only the virtual slots and fields used here are named; RTTI gives the
// slot counts (ObjectClass 116, MissionClass 149, RadioClass 153, TechnoClass 280,
// BuildingClass 293, FootClass 310). MissionClass and RadioClass are folded into TechnoClass.
class BombClass {
public:
    void Detonate();                            // 0x435bf0 (name provisional)
};

class ObjectClass : public AbstractClass {
public:
    virtual void Slot_024(); virtual void Slot_025(); virtual void Slot_026(); virtual void Slot_027();
    virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030(); virtual void Slot_031();
    virtual void Slot_032(); virtual void Slot_033(); virtual void Slot_034(); virtual void Slot_035();
    virtual void Slot_036(); virtual void Slot_037(); virtual void Slot_038(); virtual void Slot_039();
    virtual void Slot_040(); virtual void Slot_041(); virtual void Slot_042(); virtual void Slot_043();
    virtual void Slot_044(); virtual void Slot_045(); virtual void Slot_046(); virtual void Slot_047();
    virtual void Slot_048(); virtual void Slot_049(); virtual void Slot_050(); virtual void Slot_051();
    virtual void Slot_052(); virtual void Slot_053(); virtual void Slot_054(); virtual void Slot_055();
    virtual void Slot_056(); virtual void Slot_057(); virtual void Slot_058(); virtual void Slot_059();
    virtual void Slot_060(); virtual void Slot_061(); virtual void Slot_062(); virtual void Slot_063();
    virtual void Slot_064(); virtual void Slot_065(); virtual void Slot_066(); virtual void Slot_067();
    virtual void Slot_068(); virtual void Slot_069(); virtual void Slot_070(); virtual void Slot_071();
    virtual void Slot_072(); virtual void Slot_073(); virtual void Slot_074(); virtual void Slot_075();
    virtual void Slot_076(); virtual void Slot_077(); virtual void Slot_078();
    virtual void Clicked_As_Target(int frames);        // slot 79 (+0x13c), name provisional
    virtual void Slot_080(); virtual void Slot_081(); virtual void Slot_082(); virtual void Slot_083();
    virtual void Slot_084(); virtual void Slot_085(); virtual void Slot_086();
    virtual void Scatter(CoordStruct const & source, bool forced, bool nokidding);   // slot 87 (+0x15c)
    virtual void Slot_088(); virtual void Slot_089(); virtual void Slot_090(); virtual void Slot_091();
    virtual void Slot_092(); virtual void Slot_093(); virtual void Slot_094(); virtual void Slot_095();
    virtual void Slot_096();
    virtual void Repair(int control);                  // slot 97 (+0x184)
    virtual void Sell_Back(int control);               // slot 98 (+0x188)
    virtual void Slot_099(); virtual void Slot_100(); virtual void Slot_101(); virtual void Slot_102();
    virtual void Slot_103();
    virtual CellStruct Deploy_Cell() const;           // slot 104 (+0x1a0), name provisional
    virtual void Slot_105(); virtual void Slot_106(); virtual void Slot_107(); virtual void Slot_108();
    virtual void Slot_109(); virtual void Slot_110(); virtual void Slot_111(); virtual void Slot_112();
    virtual void Slot_113(); virtual void Slot_114(); virtual void Slot_115();

    CoordStruct Get_Coord() const { return Coord; }

    char Unknown24[0x38 - 0x24];
    BombClass * AttachedBomb;                   // +0x38 (name provisional)
    char Unknown3C[0x6C - 0x3C];
    int Strength;                               // +0x6c
    char Unknown70[0x76 - 0x70];
    bool IsInLimbo;                             // +0x76 (name provisional)
    char Unknown77[0x79 - 0x77];
    bool Field79;                               // +0x79 (meaning unknown)
    char Unknown7A[0x7D - 0x7A];
    bool IsActive;                              // +0x7d (name provisional)
    char Unknown7E[0x88 - 0x7E];
    CoordStruct Coord;                          // +0x88
};

class Object238Class {
public:
    void Func_67FBB0();                         // 0x67fbb0 (meaning unknown)
};

class TechnoClass : public ObjectClass {
public:
    virtual void Assign_Mission(int mission, int arg); // slot 116 (+0x1d0)
    virtual void Commence();                          // slot 117 (+0x1d4)
    virtual void Slot_118(); virtual void Slot_119(); virtual void Slot_120(); virtual void Slot_121();
    virtual void Slot_122(); virtual void Slot_123(); virtual void Slot_124(); virtual void Slot_125();
    virtual void Slot_126(); virtual void Slot_127(); virtual void Slot_128(); virtual void Slot_129();
    virtual void Slot_130(); virtual void Slot_131(); virtual void Slot_132(); virtual void Slot_133();
    virtual void Slot_134(); virtual void Slot_135(); virtual void Slot_136(); virtual void Slot_137();
    virtual void Slot_138(); virtual void Slot_139(); virtual void Slot_140(); virtual void Slot_141();
    virtual void Slot_142(); virtual void Slot_143(); virtual void Slot_144(); virtual void Slot_145();
    virtual void Slot_146(); virtual void Slot_147(); virtual void Slot_148();
    virtual void Transmit_Message(int message);       // slot 149 (+0x254), name provisional
    virtual void Slot_150(); virtual void Slot_151();
    virtual void Transmit_To_All(int message);        // slot 152 (+0x260), name provisional
    virtual void Slot_153(); virtual void Slot_154(); virtual void Slot_155(); virtual void Slot_156();
    virtual void Slot_157(); virtual void Slot_158(); virtual void Slot_159(); virtual void Slot_160();
    virtual void Slot_161(); virtual void Slot_162(); virtual void Slot_163();
    virtual bool Is_Busy() const;                     // slot 164 (+0x290), name provisional
    virtual void Slot_165(); virtual void Slot_166(); virtual void Slot_167(); virtual void Slot_168();
    virtual void Slot_169(); virtual void Slot_170(); virtual void Slot_171(); virtual void Slot_172();
    virtual void Slot_173(); virtual void Slot_174(); virtual void Slot_175(); virtual void Slot_176();
    virtual void Slot_177(); virtual void Slot_178(); virtual void Slot_179(); virtual void Slot_180();
    virtual void Slot_181(); virtual void Slot_182(); virtual void Slot_183(); virtual void Slot_184();
    virtual void Slot_185(); virtual void Slot_186(); virtual void Slot_187(); virtual void Slot_188();
    virtual void Slot_189(); virtual void Slot_190(); virtual void Slot_191(); virtual void Slot_192();
    virtual void Slot_193(); virtual void Slot_194(); virtual void Slot_195(); virtual void Slot_196();
    virtual void Slot_197(); virtual void Slot_198(); virtual void Slot_199(); virtual void Slot_200();
    virtual void Slot_201(); virtual void Slot_202(); virtual void Slot_203(); virtual void Slot_204();
    virtual void Slot_205(); virtual void Slot_206(); virtual void Slot_207(); virtual void Slot_208();
    virtual void Slot_209(); virtual void Slot_210(); virtual void Slot_211(); virtual void Slot_212();
    virtual void Slot_213(); virtual void Slot_214(); virtual void Slot_215(); virtual void Slot_216();
    virtual void Slot_217(); virtual void Slot_218(); virtual void Slot_219();
    virtual void Assign_Target(AbstractClass * target);   // slot 220 (+0x370)
    virtual void Slot_221(); virtual void Slot_222(); virtual void Slot_223(); virtual void Slot_224();
    virtual void Slot_225(); virtual void Slot_226(); virtual void Slot_227(); virtual void Slot_228();
    virtual void Slot_229(); virtual void Slot_230(); virtual void Slot_231(); virtual void Slot_232();
    virtual void Slot_233(); virtual void Slot_234(); virtual void Slot_235(); virtual void Slot_236();
    virtual void Slot_237(); virtual void Slot_238(); virtual void Slot_239(); virtual void Slot_240();
    virtual void Slot_241(); virtual void Slot_242(); virtual void Slot_243(); virtual void Slot_244();
    virtual void Slot_245(); virtual void Slot_246(); virtual void Slot_247(); virtual void Slot_248();
    virtual void Slot_249(); virtual void Slot_250(); virtual void Slot_251(); virtual void Slot_252();
    virtual void Slot_253(); virtual void Slot_254(); virtual void Slot_255(); virtual void Slot_256();
    virtual void Slot_257(); virtual void Slot_258();
    virtual void Assign_Follow(AbstractClass * target);   // slot 259 (+0x40c), name provisional
    virtual void Assign_Destination(AbstractClass * target, bool flag);  // slot 260 (+0x410)
    virtual void Slot_261(); virtual void Slot_262(); virtual void Slot_263(); virtual void Slot_264();
    virtual void Slot_265(); virtual void Slot_266(); virtual void Slot_267();
    virtual int Event_Mission(EventClass * event);    // slot 268 (+0x430), name provisional
    virtual void Slot_269(); virtual void Slot_270(); virtual void Slot_271(); virtual void Slot_272();
    virtual void Slot_273(); virtual void Slot_274(); virtual void Slot_275(); virtual void Slot_276();
    virtual void Slot_277(); virtual void Slot_278(); virtual void Slot_279();

    bool Is_Foot() const { return Flag3; }
    TechnoClass * Contact_With_Whom(int index) const;   // 0x62e3b0
    void Set_Archive(AbstractClass * target);   // 0x6cc3c0

    char Unknown94[0x98 - 0x94];
    int Mission;                                // +0x98
    char Unknown9C[0x1B4 - 0x9C];
    HouseClass * House;                         // +0x1b4
    char Unknown1B8[0x22C - 0x1B8];
    int Field22C;                               // +0x22c (meaning unknown)
    char Unknown230[0x238 - 0x230];
    Object238Class * Field238;                  // +0x238 (meaning unknown)
    char Unknown23C[0x370 - 0x23C];
    bool Field370;                              // +0x370 (meaning unknown)
    char Unknown371[0x3F8 - 0x371];
    int Field3F8;                               // +0x3f8 (meaning unknown)
    int Field3FC;                               // +0x3fc (meaning unknown)
    char Unknown400[0x418 - 0x400];
};

class BuildingTypeClass {
public:
    char Unknown0[0x134D];
    bool Field134D;                             // +0x134d (meaning unknown)
    char Unknown134E[0x1357 - 0x134E];
    bool Field1357;                             // +0x1357 (meaning unknown)
    char Unknown1358[0x135A - 0x1358];
    bool Field135A;                             // +0x135a (meaning unknown)
};

class BuildingClass : public TechnoClass {
public:
    virtual void Slot_280(); virtual void Slot_281(); virtual void Slot_282(); virtual void Slot_283();
    virtual void Slot_284(); virtual void Slot_285(); virtual void Slot_286();
    virtual void Toggle_Primary();                    // slot 287 (+0x47c)

    void Turn_On();                            // 0x44d0d0 (name provisional)
    void Turn_Off();                           // 0x44d220 (name provisional)

    BuildingTypeClass * Class;                  // +0x418
};

// Object embedded in FootClass at +0x49c (class not bound).
class Foot49CClass {
public:
    virtual void Slot_00(); virtual void Slot_01(); virtual void Slot_02();
    virtual void Stop();                        // slot 3 (+0xc), name provisional
};

class TeamClass {
public:
    void Remove(FootClass * object, int typeindex, bool flag);  // 0x6ae600 (name provisional)
};

class FootClass : public TechnoClass {
public:
    void Func_4C8890();                         // 0x4c8890, calls Field49C.Stop()

    int Field418;                               // +0x418 (meaning unknown)
    CellStruct Field41C;                        // +0x41c (meaning unknown)
    CellStruct Field420;                        // +0x420 (meaning unknown)
    char Unknown424[0x498 - 0x424];
    int Field498;                               // +0x498 (meaning unknown)
    Foot49CClass Field49C;                      // +0x49c
    char Unknown4A0[0x4C4 - 0x4A0];
    TeamClass * Team;                           // +0x4c4
    char Unknown4C8[0x576 - 0x4C8];
    bool Field576;                              // +0x576 (meaning unknown)
    char Unknown577[0x59C - 0x577];
    bool Field59C;                              // +0x59c (meaning unknown)
    char Unknown59D[0x5AC - 0x59D];
};

class UnitTypeClass {
public:
    char Unknown0[0xBA6];
    bool FieldBA6;                              // +0xba6 (meaning unknown)
};

class UnitClass : public FootClass {
public:
    UnitTypeClass * Class;                      // +0x5ac
};

class AnimTypeClass;
class AnimClass : public AbstractClass {
public:
    AnimClass(AnimTypeClass * type, CoordStruct const & coord, int timedelay = 0, int loop = 1,
        int flags = 0x600, int arg6 = 0);       // 0x420110
    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    char Unknown24[0x17d - 0x24];
    bool Flag17D;                               // +0x17d
    char Unknown17E[0x1A8 - 0x17E];
};
extern DynamicVectorClass<AnimTypeClass *> AnimTypes;      // 0x84e508

// Interface at HouseClass+0x24 (slot 4 returns the house name; name provisional).
struct IHouse : IUnknown {
    virtual long __stdcall ID_Number() const = 0;
    virtual wchar_t const * __stdcall Name() const = 0;
};

class HouseClass : public AbstractClass, public IHouse {
public:
    bool Is_Ally(HouseClass const * house) const;   // 0x4e4be0
    bool Is_Ally(TechnoClass const * object) const; // 0x4e4c20
    void Make_Ally(int house, bool announce);   // 0x4e4ce0 (name provisional)
    void Make_Enemy(int house, bool announce);  // 0x4e50f0 (name provisional)
    void Begin_Production(int rtti, int id, bool flag, int arg);    // 0x4e54d0 (name provisional)
    void Suspend_Production(int rtti, int id, bool flag);   // 0x4e5a90 (name provisional)
    void Abandon_Production(int rtti, int id, bool flag);   // 0x4e5b90 (name provisional)
    void Place_Special_Blast(int special, CellStruct const & cell); // 0x4e5f70 (name provisional)
    void Place_Object(int rtti, int id, bool flag, CellStruct const & cell);   // 0x4e5ff0 (name provisional)
    void Connection_Lost();                     // 0x4e73d0 (meaning provisional)
    void Sell_Wall(CellStruct const & cell, bool flag);    // 0x4e78c0 (name provisional)
    bool Is_Player_Control() const;             // 0x4f47b0 (name provisional)
    bool Func_4F47F0() const;                   // 0x4f47f0 (meaning unknown, see Super.CPP)
    void All_To_Cheer();                        // 0x4f57b0 (name provisional)

    char Unknown28[0x30 - 0x28];
    int ArrayIndex;                             // +0x30
    char Unknown34[0x15F16 - 0x34];
    wchar_t UIName[0x15];                       // +0x15f16 (length assumed)
    int ColorScheme;                            // +0x15f40 (meaning provisional)
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

class CellClass {
public:
    BuildingClass * Cell_Building() const;      // 0x4713b0
    char Unknown0[0x11C];
    bool Field11C;                              // +0x11c (meaning unknown)
    char Unknown11D[0x140 - 0x11D];
    int Flags;                                  // +0x140 (bit 8 tested; meaning unknown)
};

class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);  // 0x4e0030
    virtual void Virtual_15();                  // 0x4e01c0 (slot 15; called directly here)
};
class MapClass : public GScreenClass {
public:
    CellClass & operator [] (CoordStruct const & coord);    // 0x545490
    CellClass & operator [] (CellStruct const & cell);      // 0x545500
    int Get_Cell_Height(CoordStruct const & coord) const;   // 0x557070 (name provisional)
};
class MouseClass : public MapClass {
};
extern MouseClass Map;                          // 0x81a820

class RulesClass {
public:
    char Unknown00[0xA74];
    AnimTypeClass * DefaultAnim;                // +0xa74 (name provisional)
    char UnknownA78[0x1128 - 0xA78];
    double MessageDelay;                        // +0x1128, minutes
};
extern RulesClass * Rule;                       // 0x821b88

class ScenarioClass {
public:
    SpecialClass Special;                       // +0x00 (bit 12 lowers the timing MaxAhead by 10)
};
extern ScenarioClass * Scen;                    // 0xa255c0
extern SpecialClass Special;                    // 0xa28570 (name provisional)

class OptionsClass {
public:
    int GameSpeed;                              // +0x00
};
extern OptionsClass Options;                    // 0xa28758

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};

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

extern Surface * HiddenSurface;                // 0x821c94

class IPXManagerClass {
public:
    void Set_Connection_Address(int id, IPXAddressClass * address);    // 0x524c90 (name provisional)
    void Set_Host_Address(IPXAddressClass * address);  // 0x525a60
};
extern IPXManagerClass Ipx;                     // 0xa285c8

class HostManagerClass {
public:
    void Func_636520();
    void Set_Player_Address(int id, IPXAddressClass * address);   // 0x636c90 (name provisional)
    int Choose_New_Host();                      // 0x636cf0, -1 when none
    void Player_Left(int id);                   // 0x636f30
};
extern HostManagerClass HostManager;            // 0xa9e820

// Session object at 0xa255c8. Members used here are kept as separate globals below; their
// addresses suggest they are Session members (offsets given in the comments).
enum { GAME_INTERNET = 4 };
class SessionClass {
public:
    bool Is_Host_Change_Allowed(HouseClass * house);   // 0x665c40 (meaning provisional)

    int Type;                                   // +0x0000
};
extern SessionClass Session;                    // 0xa255c8
extern unsigned SessionMaxAhead;                // 0xa25890  (Session + 0x2c8)
extern unsigned SessionFrameSendRate;           // 0xa25894  (Session + 0x2cc)
extern unsigned SessionDesiredFrameRate;        // 0xa25898  (Session + 0x2d0)
extern int SessionMaxMaxAhead;                  // 0xa258a8  (Session + 0x2e0)
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)
extern unsigned char SessionRecordFlags;        // 0xa27928  (Session + 0x2360, bit 1 = playback, provisional)
extern DynamicVectorClass<NodeNameType *> SessionPlayers;  // 0xa27da8 (Session + 0x27e0)
extern int SessionLatency;                      // 0xa27ed0  (Session + 0x2908)
extern bool SessionHostMigration;               // 0xa27ed4  (Session + 0x290c, meaning provisional)
extern IPXAddressClass SessionHostAddress;      // 0xa27ed5  (Session + 0x290d)
extern wchar_t SessionHostName[];               // 0xa27eea  (Session + 0x2922)
extern int SessionHostID;                       // 0xa27f14  (Session + 0x294c)
extern int SessionFallbackHost;                 // 0xa27f20  (Session + 0x2958, name provisional)
extern bool SessionHostChanged;                 // 0xa27f24  (Session + 0x295c)
extern int SessionHostChangeFrame;              // 0xa27f2c  (Session + 0x2964, name provisional)
extern unsigned SessionHostResumeFrame;         // 0xa27f30  (Session + 0x2968, name provisional)
extern int SessionNewHost;                      // 0xa27f34  (Session + 0x296c, name provisional)
enum { RECORD_PLAYBACK = 2 };

extern int MaxAheadChangeFrame;                 // 0xa25588 (name provisional)
extern int MaxAheadSettleFrame;                 // 0xa2556c (name provisional)
extern int Flag_B0FCC0;                         // 0xb0fcc0 (meaning unknown)
extern bool GameOver_A1E0E0;                    // 0xa1e0e0, set by the EXIT event (name provisional)

// Mode for Special_Dialog (see Conquer.CPP).
enum { SDLG_NONE = 0, SDLG_1 = 1, SDLG_7 = 7 };
extern int ExitMode_A28988;                     // 0xa28988, the Special_Dialog mode

// Planning-mode helpers (names provisional).
void Planning_Execute(EventClass * event);      // 0x60c780
void Planning_Unlink(TechnoClass * techno, EventClass * event); // 0x60d060

// ---- end of local declarations ----


// level-2 1.001: defined in src/m85/src/event.cpp (one definition per function)

// 0x7c17b4: frame of the last numbered event; never written in GAME.EXE.
int EventNumberFrame = -1;
static unsigned char EventNumber;                // 0x83decc

// 0x4b5b90: running event number within the current frame (no caller in GAME.EXE).
unsigned char Next_Event_Number()
{
    if (Frame != EventNumberFrame) {
        EventNumber = 0;
    }
    return EventNumber++;
}

EventClass::EventClass(int house, SpecialClass data)
{
    if (house >= 0) {
        HouseID = house;
        Type = EVENT_SPECIAL;
        Data.Options.Data = data;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, TargetClass whom)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Target.Whom = whom;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, CellStruct const & cell)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Cell.X = cell.X;
        Data.Cell.Y = cell.Y;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, int id)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Value.ID = id;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, TargetClass src, TargetClass dest)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.NavCom.Source = src;
        Data.NavCom.Dest = dest;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, int anim, int owner, Point2D const & where)
{
    Debug_Printf("Adding event ANIMATION\n");
    if (house >= 0) {
        HouseID = house;
        Type = EVENT_ANIMATION;
        Data.Anim.ID = anim;
        Data.Anim.Owner = owner;
        Data.Anim.X = where.X;
        Data.Anim.Y = where.Y;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, TargetClass whom, MissionType mission, TargetClass target, TargetClass destination, TargetClass follow)
{
    if (house >= 0) {
        HouseID = house;
        Type = EVENT_MEGAMISSION;
        Data.MegaMission.IsPlanning = false;
        Data.MegaMission.Whom = whom;
        Data.MegaMission.Mission = mission;
        Data.MegaMission.Target = target;
        Data.MegaMission.Destination = destination;
        Data.MegaMission.Follow = follow;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, TargetClass whom, MissionType mission, TargetClass target, TargetClass destination, int speed, int maxspeed)
{
    Debug_Printf("Adding event MEGAMISSION_F\n");
    if (house >= 0) {
        HouseID = house;
        Type = EVENT_MEGAMISSION_F;
        Data.MegaMission_F.Whom = whom;
        Data.MegaMission_F.Mission = mission;
        Data.MegaMission_F.Target = target;
        Data.MegaMission_F.Destination = destination;
        Data.MegaMission_F.Speed = speed;
        Data.MegaMission_F.MaxSpeed = maxspeed;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, int rtti, int id, int flag)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Production.RTTI = rtti;
        Data.Production.ID = id;
        Data.Production.Flag = flag;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, RTTIType rtti, CellStruct const & cell)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Place.RTTI = rtti;
        Data.Place.ID = -1;
        Data.Place.Flag = 0;
        Data.Place.X = cell.X;
        Data.Place.Y = cell.Y;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, RTTIType rtti, int id, CellStruct const & cell)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Place.RTTI = rtti;
        Data.Place.ID = id;
        Data.Place.Flag = 0;
        Data.Place.X = cell.X;
        Data.Place.Y = cell.Y;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, RTTIType rtti, int id, int flag, CellStruct const & cell)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Place.RTTI = rtti;
        Data.Place.ID = id;
        Data.Place.Flag = flag;
        Data.Place.X = cell.X;
        Data.Place.Y = cell.Y;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, int id, CellStruct const & cell)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.CellID.ID = id;
        Data.CellID.X = cell.X;
        Data.CellID.Y = cell.Y;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, EventType type, int a, int b)
{
    Debug_Printf("Adding event %s\n", EventNames[type]);
    if (house >= 0) {
        HouseID = house;
        Type = type;
        Data.Pair.A = a;
        Data.Pair.B = b;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

EventClass::EventClass(int house, IPXAddressClass & address, unsigned char id)
{
    if (house >= 0) {
        HouseID = house;
        Type = EVENT_ADDRESSCHANGE;
        NetNumType net;
        NetNodeType node;
        address.Get_Address(net, node);
        *(int *)Data.Address.IP = *(int *)node;
        Data.Address.ID = id;
    } else {
        HouseID = -1;
        Type = EVENT_EMPTY;
    }
    Frame = ::Frame;
}

// 0x4b62d0: carries out the event for the house that sent it.
// Open (logic reconstructed, not byte-identical): same size (4976 bytes incl. the 45-entry jump
// table) and the same block order and code, except that GAME.EXE materialises the foot bit
// (Is_Foot, AbstractClass+0x14 bit 2) into a byte stack local at [esp+0x13] at five sites
// (shr/and/store, never read), while this source gives `test byte ptr [reg+0x14], 4`; the extra
// 4-byte slot shifts every small local by 4 (frame 0x36c instead of 0x370) and the register
// allocation differs. The `foot` ternary in MEGAMISSION is branch-free here but a test/branch
// with an out-of-line `xor ebx,ebx` in GAME.EXE.

