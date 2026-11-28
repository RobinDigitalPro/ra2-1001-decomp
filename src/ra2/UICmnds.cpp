// C:\RA2\UICmnds.cpp (level-2 reconstruction of GAME.EXE 1.001)
// User-interface command helpers: the work behind the keyboard commands (CommandClass subclasses
// in another TU) for deploy/guard/stop/scatter/cheer, team create/select/center/add, alliance,
// attack move, combatant/type selection and health/veterancy/type cycling.
// Function names come from the calling CommandClass Get_Name strings where possible; all other
// names (globals, members, helpers) are provisional.
//
// TU boundary: 0x2ea600 (first GAMECONST.H initializer) .. 0x2ed878 (last template instance).
// The next dynamic initializer at 0x2ed880 starts the next TU.
//
// Generated file: edit W/analysis/level2/uicmnds/UICmnds.tmpl.cpp and run build.py there (the
// virtual slot fillers of ObjectClass/TechnoClass are inserted by gen_slots.py).
#include "GAMECONST.H"
#include <string.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include "ABSTRACT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
int Play_Sound(int voc, float volume, int pan, int flags);   // 0x708970 (names provisional)

// Copy of VECTOR.H plus the constructors that VECTOR.H does not have yet (as in Egos.CPP);
// Add returns bool here (0x2ed7e0 returns al).
template<class T> class VectorClass {
public:
    VectorClass(unsigned size = 0, T const * array = 0) :
        Vector(0), VectorMax(size), IsInitialized(true), IsAllocated(false)
    {
        if (size) {
            if (array) {
                Vector = (T *)array;
            } else {
                Vector = new T[size];
                IsAllocated = true;
            }
        }
    }
    virtual ~VectorClass() { VectorClass<T>::Clear(); }
    virtual bool operator == (VectorClass<T> const & vector) const;
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr);
    virtual int ID(T const & object);
    virtual T Fetch(int index) const { return Vector[index]; }

    T & operator[](unsigned index) { return Vector[index]; }
    T const & operator[](unsigned index) const { return Vector[index]; }
    int Length() const { return VectorMax; }

    T * Vector;
    int VectorMax;
    bool IsInitialized;
    bool IsAllocated;
};

template<class T> bool VectorClass<T>::operator == (VectorClass<T> const & vector) const
{
    if (VectorMax == vector.VectorMax) {
        for (int index = 0; index < VectorMax; index++) {
            if (Vector[index] != vector.Vector[index]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class T> bool VectorClass<T>::Resize(int newsize, T const * array)
{
    if (newsize) {
        T * newptr;
        IsInitialized = false;
        if (!array) {
            newptr = new T[newsize];
        } else {
            newptr = (T *)array;
        }
        IsInitialized = true;
        if (!newptr) {
            return false;
        }
        if (Vector != NULL) {
            int copycount = (newsize < VectorMax) ? newsize : VectorMax;
            for (int index = 0; index < copycount; index++) {
                newptr[index] = Vector[index];
            }
            if (IsAllocated) {
                delete [] Vector;
                Vector = 0;
            }
        }
        Vector = newptr;
        VectorMax = newsize;
        IsAllocated = (Vector && !array);
    } else {
        Clear();
    }
    return true;
}

template<class T> void VectorClass<T>::Clear(void)
{
    if (Vector && IsAllocated) {
        delete [] Vector;
        Vector = 0;
    }
    IsAllocated = false;
    VectorMax = 0;
}

template<class T> int VectorClass<T>::ID(T const * ptr)
{
    if (!IsInitialized) {
        return 0;
    }
    return ((unsigned long)ptr - (unsigned long)Vector) / sizeof(T);
}

template<class T> int VectorClass<T>::ID(T const & object)
{
    if (!IsInitialized) {
        return 0;
    }
    for (int index = 0; index < VectorMax; index++) {
        if (Vector[index] == object) {
            return index;
        }
    }
    return -1;
}

template<class T> class DynamicVectorClass : public VectorClass<T> {
public:
    DynamicVectorClass(unsigned size = 0, T const * array = 0) : VectorClass<T>(size, array)
    {
        GrowthStep = 10;
        ActiveCount = 0;
    }
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr) { return VectorClass<T>::ID(ptr); }
    virtual int ID(T const & object);

    int Count() const { return ActiveCount; }
    bool Add(T const & object);
    bool Delete(T const & object);
    bool Delete(int index);

    int ActiveCount;
    int GrowthStep;
};

template<class T> bool DynamicVectorClass<T>::Resize(int newsize, T const * array)
{
    if (VectorClass<T>::Resize(newsize, array)) {
        if (Length() < ActiveCount) {
            ActiveCount = Length();
        }
        return true;
    }
    return false;
}

template<class T> void DynamicVectorClass<T>::Clear(void)
{
    ActiveCount = 0;
    VectorClass<T>::Clear();
}

template<class T> int DynamicVectorClass<T>::ID(T const & object)
{
    for (int index = 0; index < ActiveCount; index++) {
        if ((*this)[index] == object) {
            return index;
        }
    }
    return -1;
}

template<class T> inline bool DynamicVectorClass<T>::Add(T const & object)
{
    if (ActiveCount >= Length()) {
        if ((IsAllocated || !VectorMax) && GrowthStep > 0) {
            if (!Resize(Length() + GrowthStep)) {
                return false;
            }
        } else {
            return false;
        }
    }
    (*this)[ActiveCount++] = object;
    return true;
}

template<class T> inline bool DynamicVectorClass<T>::Delete(T const & object)
{
    int index = ID(object);
    if (index != -1) {
        return Delete(index);
    }
    return false;
}

template<class T> inline bool DynamicVectorClass<T>::Delete(int index)
{
    if (index < ActiveCount) {
        ActiveCount--;
        for (int i = index; i < ActiveCount; i++) {
            (*this)[i] = (*this)[i+1];
        }
        return true;
    }
    return false;
}

class CCINIClass;
class HouseClass;
class TechnoClass;
class TechnoTypeClass;
class ObjectTypeClass;

// Session object at 0xa255c8 (see Event.CPP); only the game type is used here.
class SessionClass {
public:
    int Type;                                   // +0x0000, 0 = single player
};
extern SessionClass Session;                    // 0xa255c8

class ScenarioClass {
public:
    int SpecialFlags;                           // +0x00 (bit 10: no alliances; meaning provisional)
};
extern ScenarioClass * Scen;                    // 0xa255c0

class HouseClass : public AbstractClass {
public:
    bool Is_Player_Control() const;             // 0x4f47b0 (name provisional)
    bool Is_Human_Control() const
    {
        if (Session.Type == 0) {
            return IsHuman;
        }
        return Is_Player_Control();
    }

    char Unknown24[0x30 - 0x24];
    int ArrayIndex;                             // +0x30
    char Unknown34[0x134 - 0x34];
    bool IsPlayerControl;                       // +0x134 (name provisional)
    bool IsHuman;                               // +0x135 (name provisional)
    char Unknown136[0x13D - 0x136];
    bool IsDefeated;                            // +0x13d (name provisional)
    char Unknown13E[0x15F40 - 0x13E];
    int ColorScheme;                            // +0x15f40 (meaning provisional)
};
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

// Type class hierarchy; only the slots and fields used here are declared.
class ObjectTypeClass : public AbstractClass {
public:
    virtual void Load_Theater_Art(int theater);
    virtual bool Read_INI(CCINIClass & ini);
    virtual bool Write_INI(CCINIClass & ini) const;
    virtual void Slot_027(); virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030();
    virtual void Slot_031(); virtual void Slot_032();
    virtual int Cost_Of(HouseClass * house) const;  // slot 33 (+0x84), name provisional

    char ID[0x19];                              // +0x24
    char UINameLabel[0x20];                     // +0x3d
    wchar_t const * UIName;                     // +0x60
    char Unknown64[0xA0 - 0x64];
    int MaxStrength;                            // +0xa0
};

class TechnoTypeClass : public ObjectTypeClass {
public:
    char UnknownA4[0xB58 - 0xA4];
    bool IsCombatant;                           // +0xb58 (name provisional)
};

// Veterancy value (double) embedded in TechnoClass at +0x118.
class VeterancyClass {
public:
    int Level() const;                          // 0x708000: 0, 1 or 2 (name provisional)
    double Value;
};

// Object hierarchy. Only the virtual slots and fields used here are named; RTTI gives the slot
// counts (ObjectClass 116, TechnoClass 280). MissionClass and RadioClass are folded into TechnoClass.
class ObjectClass : public AbstractClass {
public:
    virtual void Slot_024(); virtual void Slot_025(); virtual void Slot_026(); virtual void Slot_027();
    virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030(); virtual void Slot_031();
    virtual TechnoTypeClass * Techno_Type_Class() const;    // slot 32 (+0x80)
    virtual ObjectTypeClass * Class_Of() const;             // slot 33 (+0x84)
    virtual void Slot_034(); virtual void Slot_035(); virtual void Slot_036(); virtual void Slot_037();
    virtual bool Slot_038_Query() const;                    // slot 38 (+0x98), meaning unknown
    virtual bool Slot_039_Query() const;                    // slot 39 (+0x9c), meaning unknown
    virtual void Slot_040(); virtual void Slot_041(); virtual void Slot_042(); virtual void Slot_043();
    virtual void Slot_044(); virtual void Slot_045(); virtual void Slot_046(); virtual void Slot_047();
    virtual void Slot_048(); virtual void Slot_049(); virtual void Slot_050(); virtual void Slot_051();
    virtual void Slot_052(); virtual void Slot_053(); virtual void Slot_054(); virtual void Slot_055();
    virtual void Slot_056(); virtual void Slot_057(); virtual void Slot_058(); virtual void Slot_059();
    virtual void Slot_060(); virtual void Slot_061(); virtual void Slot_062(); virtual void Slot_063();
    virtual void Slot_064(); virtual void Slot_065(); virtual void Slot_066(); virtual void Slot_067();
    virtual void Slot_068(); virtual void Slot_069(); virtual void Slot_070(); virtual void Slot_071();
    virtual void Slot_072(); virtual void Slot_073(); virtual void Slot_074(); virtual void Slot_075();
    virtual void Slot_076(); virtual void Slot_077(); virtual void Slot_078(); virtual void Slot_079();
    virtual bool Select();                                  // slot 80 (+0x140)
    virtual void Unselect();                                // slot 81 (+0x144)
    virtual void Slot_082(); virtual void Slot_083(); virtual void Slot_084(); virtual void Slot_085();
    virtual void Slot_086(); virtual void Slot_087(); virtual void Slot_088(); virtual void Slot_089();
    virtual void Slot_090(); virtual void Slot_091(); virtual void Slot_092(); virtual void Slot_093();
    virtual void Slot_094(); virtual void Slot_095(); virtual void Slot_096(); virtual void Slot_097();
    virtual void Slot_098(); virtual void Slot_099(); virtual void Slot_100(); virtual void Slot_101();
    virtual void Slot_102(); virtual void Slot_103(); virtual void Slot_104(); virtual void Slot_105();
    virtual void Slot_106();
    virtual int Slot_107(int a, int b);                    // slot 107 (+0x1ac), meaning unknown
    virtual void Slot_108(); virtual void Slot_109(); virtual void Slot_110(); virtual void Slot_111();
    virtual void Slot_112(); virtual void Slot_113(); virtual void Slot_114(); virtual void Slot_115();

    int Health_Status() const;                  // 0x5ccd40 (name provisional)
    bool Is_Type(char const * name) const;      // 0x5cae60, Class_Of() == name (name provisional)

    char Unknown24[0x6C - 0x24];
    int Strength;                               // +0x6c
    char Unknown70[0x76 - 0x70];
    bool IsInLimbo;                             // +0x76 (name provisional)
    bool IsSelected;                            // +0x77 (name provisional)
    char Unknown78[0x7D - 0x78];
    bool IsActive;                              // +0x7d (name provisional)
    char Unknown7E[0xAC - 0x7E];
};

// Kind tests on a possibly null object (0x2ed710 is the out-of-line copy of Is_Techno).
inline bool Is_Techno(ObjectClass const * object)
{
    if (!object) {
        return false;
    }
    bool flag = object->Flag1;
    return flag;
}

inline bool Is_Foot(ObjectClass const * object)
{
    if (!object) {
        return false;
    }
    return object->Flag3;
}

class TechnoClass : public ObjectClass {
public:
    virtual void Slot_116(); virtual void Slot_117(); virtual void Slot_118(); virtual void Slot_119();
    virtual void Slot_120(); virtual void Slot_121(); virtual void Slot_122(); virtual void Slot_123();
    virtual void Slot_124(); virtual void Slot_125(); virtual void Slot_126(); virtual void Slot_127();
    virtual void Slot_128(); virtual void Slot_129(); virtual void Slot_130(); virtual void Slot_131();
    virtual void Slot_132(); virtual void Slot_133(); virtual void Slot_134(); virtual void Slot_135();
    virtual void Slot_136(); virtual void Slot_137(); virtual void Slot_138(); virtual void Slot_139();
    virtual void Slot_140(); virtual void Slot_141(); virtual void Slot_142(); virtual void Slot_143();
    virtual void Slot_144(); virtual void Slot_145(); virtual void Slot_146(); virtual void Slot_147();
    virtual void Slot_148(); virtual void Slot_149(); virtual void Slot_150(); virtual void Slot_151();
    virtual void Slot_152(); virtual void Slot_153(); virtual void Slot_154(); virtual void Slot_155();
    virtual void Slot_156(); virtual void Slot_157(); virtual void Slot_158(); virtual void Slot_159();
    virtual void Slot_160(); virtual void Slot_161(); virtual void Slot_162(); virtual void Slot_163();
    virtual void Slot_164(); virtual void Slot_165(); virtual void Slot_166(); virtual void Slot_167();
    virtual void Slot_168(); virtual void Slot_169(); virtual void Slot_170(); virtual void Slot_171();
    virtual void Slot_172(); virtual void Slot_173(); virtual void Slot_174(); virtual void Slot_175();
    virtual void Slot_176(); virtual void Slot_177(); virtual void Slot_178(); virtual void Slot_179();
    virtual void Slot_180(); virtual void Slot_181(); virtual void Slot_182(); virtual void Slot_183();
    virtual void Slot_184();
    virtual bool Slot_185_Query() const;                   // slot 185 (+0x2e4), meaning unknown
    virtual bool Slot_186_Query() const;                   // slot 186 (+0x2e8), meaning unknown
    virtual void Slot_187(); virtual void Slot_188(); virtual void Slot_189(); virtual void Slot_190();
    virtual void Slot_191(); virtual void Slot_192(); virtual void Slot_193(); virtual void Slot_194();
    virtual void Slot_195(); virtual void Slot_196(); virtual void Slot_197(); virtual void Slot_198();
    virtual bool Can_Do_Command(int command);              // slot 199 (+0x31c), name provisional
    virtual bool Can_Do_Command_At(int command, int arg);  // slot 200 (+0x320), name provisional
    virtual void Slot_201(); virtual void Slot_202(); virtual void Slot_203(); virtual void Slot_204();
    virtual void Slot_205(); virtual void Slot_206(); virtual void Slot_207(); virtual void Slot_208();
    virtual void Slot_209(); virtual void Slot_210(); virtual void Slot_211(); virtual void Slot_212();
    virtual void Slot_213(); virtual void Slot_214(); virtual void Slot_215(); virtual void Slot_216();
    virtual void Slot_217(); virtual void Slot_218(); virtual void Slot_219(); virtual void Slot_220();
    virtual void Slot_221(); virtual void Slot_222(); virtual void Slot_223(); virtual void Slot_224();
    virtual void Slot_225(); virtual void Slot_226(); virtual void Slot_227(); virtual void Slot_228();
    virtual void Slot_229(); virtual void Slot_230(); virtual void Slot_231(); virtual void Slot_232();
    virtual void Slot_233(); virtual void Slot_234(); virtual void Slot_235(); virtual void Slot_236();
    virtual void Slot_237(); virtual void Slot_238(); virtual void Slot_239(); virtual void Slot_240();
    virtual void Slot_241(); virtual void Slot_242(); virtual void Slot_243(); virtual void Slot_244();
    virtual void Slot_245(); virtual void Slot_246(); virtual void Slot_247(); virtual void Slot_248();
    virtual void Slot_249(); virtual void Slot_250(); virtual void Slot_251(); virtual void Slot_252();
    virtual void Slot_253(); virtual void Slot_254(); virtual void Slot_255(); virtual void Slot_256();
    virtual void Slot_257(); virtual void Slot_258(); virtual void Slot_259(); virtual void Slot_260();
    virtual void Slot_261(); virtual void Slot_262(); virtual void Slot_263(); virtual void Slot_264();
    virtual void Slot_265(); virtual void Slot_266(); virtual void Slot_267(); virtual void Slot_268();
    virtual void Slot_269(); virtual void Slot_270(); virtual void Slot_271(); virtual void Slot_272();
    virtual void Slot_273(); virtual void Slot_274();
    virtual bool Slot_275_Query() const;                   // slot 275 (+0x44c), meaning unknown
    virtual void Slot_276(); virtual void Slot_277(); virtual void Slot_278(); virtual void Slot_279();

    char UnknownAC[0x118 - 0xAC];
    VeterancyClass Veterancy;                   // +0x118
    char Unknown120[0x1AC - 0x120];
    int Group;                                  // +0x1ac, team number - 1 or -1 (name provisional)
    char Unknown1B0[0x1B4 - 0x1B0];
    HouseClass * House;                         // +0x1b4

    bool Is_Owned_By_Human() const { return Session.Type == 0 ? House->IsHuman : House->Is_Player_Control(); }
};

class BuildingClass : public TechnoClass {
public:
    int Func_452F60() const;                    // 0x452f60 (meaning unknown)
};

class InfantryClass : public TechnoClass {
public:
    bool Func_5084F0() const;                   // 0x5084f0 (meaning unknown)
    bool Func_508520() const;                   // 0x508520 (meaning unknown)
};

enum { RTTI_BUILDING = 6, RTTI_INFANTRY = 15 };

extern DynamicVectorClass<TechnoClass *> Technos;           // 0xa28860 (name provisional)
extern DynamicVectorClass<ObjectClass *> CurrentObjects;    // 0xa288a0 (name provisional)

typedef unsigned char EventType;
enum { EVENT_ALLY = 3, EVENT_ALLCHEER = 45 };

// Event record, 0x6f bytes (see Event.CPP).
#pragma pack(push, 1)
class EventClass {
public:
    EventClass(int house, EventType type);              // 0x4b5ce0
    EventClass(int house, EventType type, int id);      // 0x4b5d40
    unsigned char Data[0x6F];
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

extern int Frame;                               // 0xa2896c

class RulesClass {
public:
    char Unknown0[0x4A0];
    int CheerDelay;                             // +0x4a0 (name provisional)
    char Unknown4A4[0x640 - 0x4A4];
    int StopSound;                              // +0x640 (name provisional)
    int GuardSound;                             // +0x644 (name provisional)
    int ScatterSound;                           // +0x648 (name provisional)
    int DeploySound;                            // +0x64c (name provisional)
    char Unknown650[0x111D - 0x650];
    bool AllowAlliances;                        // +0x111d (name provisional)
};
extern RulesClass * Rule;                       // 0x821b88

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)

class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);  // 0x4e0030
};
class MouseClass : public GScreenClass {
public:
    void Func_49C560(int a);                    // 0x49c560 (meaning unknown)
    void Func_49C600(int a, int b);             // 0x49c600 (meaning unknown)
    void Func_49C720(int a);                    // 0x49c720 (meaning unknown)
    void Func_49C7C0(int a);                    // 0x49c7c0 (meaning unknown)
    void Func_49C860(int a);                    // 0x49c860 (meaning unknown)
    void Func_49E0E0();                         // 0x49e0e0 (meaning unknown)
    void Func_59BF60(int shape, bool flag);     // 0x59bf60 (mouse shape; name provisional)
};
extern MouseClass Map;                          // 0x81a820

// Tactical view (pointer at 0x821cac); keeps a list of the objects on the screen.
class TacticalClass {
public:
    void Unselect_All();                        // 0x6a0380 (name provisional)
    void Func_6A03B0();                         // 0x6a03b0 (meaning unknown)
    int Visible_Count() const;                  // 0x6a1e00 (name provisional)
    ObjectClass * Visible_Object(int index) const;  // 0x6a1e10 (name provisional)
};
extern TacticalClass * TacticalMap;             // 0x821cac

class WWKeyboardClass {
public:
    bool Down(int key);                         // 0x530af0
};
extern WWKeyboardClass * Keyboard;              // 0x81a7a8
inline bool Key_Down(int key) { return Keyboard->Down(key); }
extern int KeyForceMove1;                       // 0xa287ec (name provisional)
extern int KeyForceMove2;                       // 0xa287f0 (name provisional)
extern int KeyForceAttack1;                     // 0xa287f4 (name provisional)
extern int KeyForceAttack2;                     // 0xa287f8 (name provisional)

extern bool AllowVoice;                         // 0x7c3976 (name provisional)
void Func_6CCF00();                             // 0x6ccf00 (meaning unknown)

// Planning mode (names provisional).
class PlanningNodeClass {
public:
    void Delete();                              // 0x60c680
};
bool Is_Planning_Active();                      // 0x60c420
void Func_60C340();                             // 0x60c340
void Func_60C390();                             // 0x60c390
void Func_60EA50();                             // 0x60ea50
void Func_60EAA0(bool a, bool b);               // 0x60eaa0
PlanningNodeClass * Selected_Planning_Node();   // 0x60f5e0

class Object_836C18 {
public:
    void Func_42E940(int a, int b);             // 0x42e940
};
extern Object_836C18 Object836C18;              // 0x836c18

extern wchar_t NullWString[];                   // 0x82208c

// ---- end of local declarations ----

typedef bool (*TechnoFilterFunc)(TechnoClass * techno, void const * data);
typedef void (*TechnoActionFunc)(TechnoClass * techno, void const * data);

// .data
int LastHealthState = -1;                       // 0x7e2424
int LastVeteranState = -1;                      // 0x7e2428

// .bss
static char LastTypeName[0xDC];                 // 0xaa8cd8 (size provisional)
static int LastCommand;                         // 0xaa8db4
static bool AttackMoveArmed;                    // 0xaa8db8
static bool SelectAcrossMap;                    // 0xaa8db9
static bool TypeSelectDown;                     // 0xaa8dba
static unsigned long TypeSelectTime;            // 0xaa8dbc
DynamicVectorClass<TechnoClass *> * CycleList;          // 0xaa8dc0
static int LastTypeCost;                        // 0xaa8dc4
static int NextCheerFrame;                      // 0xaa8dc8

// 0x2ea7d0
void Clear_Cycle_List()
{
    if (CycleList) {
        delete CycleList;
        CycleList = 0;
    }
}

// 0x2ea7f0: true when no unselected member of the team is left.
bool Is_Team_Selected(int team)
{
    int count = Technos.Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = Technos[index];
        if (techno && !techno->IsInLimbo && (Session.Type == 0 ? techno->House->IsHuman : techno->House->Is_Player_Control()) && !techno->IsSelected && techno->Group == team - 1) {
            return false;
        }
    }
    return true;
}

// 0x2ea860
int Team_Member_Count(int team)
{
    int members = 0;
    int count = Technos.Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = Technos[index];
        if (techno && !techno->IsInLimbo && (Session.Type == 0 ? techno->House->IsHuman : techno->House->Is_Player_Control()) && techno->Group == team - 1) {
            members++;
        }
    }
    return members;
}

// 0x2ea8d0
void Show_Command_Message(wchar_t const * text, int timeout = -1)
{
    if (timeout == -1) {
        timeout = 0xF0;
    }
    int color = 3;
    if (PlayerPtr) {
        color = PlayerPtr->ColorScheme;
    }
    SessionMessages.Add_Message(NULL, 0, text, color, 0x4046, timeout, true);
}

// 0x2ea910
int Command_Message_Style()
{
    return 0x4046;
}

// 0x2ea920
int Command_Message_Time()
{
    return 0xF0;
}

// 0x2ea930 (DeployObject)
void Deploy_Command()
{
    bool played = false;
    if (CurrentObjects.Count() > 0) {
        if (CurrentObjects[0]) {
            ObjectClass * object = CurrentObjects[0];
            if (object && object->Kind_Of() == RTTI_BUILDING && ((BuildingClass *)object)->Func_452F60() > 0) {
                TechnoClass * techno = (TechnoClass *)CurrentObjects[0];
                if (techno && techno->Flag1 && techno->Can_Do_Command(9)) {
                    Play_Sound(Rule->DeploySound, 1.0f, 0x2000, 0);
                }
                return;
            }
        }

        bool ready = false;
        int count = CurrentObjects.Count();
        bool unready = false;
        for (int index = 0; index < count; index++) {
            ObjectClass * object = CurrentObjects[index];
            if (object && object->Kind_Of() == RTTI_INFANTRY && ((InfantryClass *)object)->Func_5084F0()) {
                if (((InfantryClass *)object)->Func_508520()) {
                    ready = true;
                } else {
                    unready = true;
                }
                if (ready && unready) {
                    break;
                }
            }
        }

        for (index = 0; index < count; index++) {
            TechnoClass * techno = (TechnoClass *)CurrentObjects[index];
            if (techno && (techno->Slot_039_Query() || techno->Slot_038_Query()) && techno->Flag1 && techno->Slot_185_Query() && techno->Slot_186_Query()) {
                if (techno->Kind_Of() == RTTI_INFANTRY && ((InfantryClass *)techno)->Func_5084F0() && ready && unready && ((InfantryClass *)techno)->Func_508520()) {
                    continue;
                }
                if (techno->Can_Do_Command(9)) {
                    played = true;
                }
            }
        }
        if (played) {
            Play_Sound(Rule->DeploySound, 1.0f, 0x2000, 0);
        }
    }
}

// 0x2eab00 (GuardObject)
void Guard_Command()
{
    if (Is_Planning_Active()) {
        Func_60EA50();
        return;
    }
    if (CurrentObjects.Count() > 0) {
        bool ok = true;
        int count = CurrentObjects.Count();
        for (int index = 0; index < count; index++) {
            TechnoClass * techno = (TechnoClass *)CurrentObjects[index];
            if (techno && techno->Flag1 && techno->Slot_039_Query() && techno->Slot_038_Query()) {
                ok = techno->Can_Do_Command_At(11, techno->Slot_107(0, 0));
                if (!ok) {
                    break;
                }
            }
        }
        if (ok) {
            Play_Sound(Rule->GuardSound, 1.0f, 0x2000, 0);
        }
    }
}

// 0x2eabb0 (StopObject)
void Stop_Command()
{
    if (CurrentObjects.Count() > 0) {
        bool ok = true;
        int count = CurrentObjects.Count();
        for (int index = 0; index < count; index++) {
            TechnoClass * techno = (TechnoClass *)CurrentObjects[index];
            if (techno && techno->Flag1 && (techno->Slot_039_Query() || techno->Slot_038_Query())) {
                ok = techno->Can_Do_Command(6);
                if (!ok) {
                    break;
                }
            }
        }
        if (ok) {
            Play_Sound(Rule->StopSound, 1.0f, 0x2000, 0);
        }
    }
}

// 0x2eac40 (AllToCheer)
void All_To_Cheer_Command()
{
    if (Frame >= NextCheerFrame) {
        OutList.Add(EventClass(PlayerPtr->ArrayIndex, EVENT_ALLCHEER));
        NextCheerFrame = Rule->CheerDelay + Frame;
    }
}

// 0x2eacf0 (ScatterObject)
void Scatter_Command()
{
    if (CurrentObjects.Count() > 0) {
        bool ok = true;
        int count = CurrentObjects.Count();
        for (int index = 0; index < count; index++) {
            TechnoClass * techno = (TechnoClass *)CurrentObjects[index];
            if (techno && techno->Flag1 && techno->Slot_039_Query()) {
                ok = techno->Can_Do_Command(7);
                if (!ok) {
                    break;
                }
            }
        }
        if (ok) {
            Play_Sound(Rule->ScatterSound, 1.0f, 0x2000, 0);
        }
    }
}

// 0x2ead70 (CreateTeam)
void Create_Team_Command(int team)
{
    int count = Technos.Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = Technos[index];
        if (techno && !techno->IsInLimbo && techno->House->Is_Human_Control()) {
            if (techno->Group == team - 1) {
                techno->Group = -1;
            }
            if (techno->IsSelected) {
                techno->Group = team - 1;
            }
        }
    }
}

// 0x2eadf0
void Clear_Team(int team)
{
    int count = Technos.Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = Technos[index];
        if (techno && !techno->IsInLimbo && (Session.Type == 0 ? techno->House->IsHuman : techno->House->Is_Player_Control()) && techno->Group == team - 1) {
            techno->Group = -1;
        }
    }
}

static inline void Reset_Mouse_Modes()
{
    Map.Func_49C720(0);
    Map.Func_49C600(0, 0);
    Map.Func_49C7C0(0);
    Map.Func_49C560(0);
    Map.Func_49C860(0);
}

// 0x2eae60 (SelectTeam)
void Select_Team_Command(int team)
{
    Reset_Mouse_Modes();
    TacticalMap->Unselect_All();
    AllowVoice = true;
    for (int index = 0; index < Technos.Count(); index++) {
        TechnoClass * techno = Technos[index];
        if (techno && !techno->IsInLimbo && techno->Group == team - 1 && techno->Is_Owned_By_Human() && !techno->IsSelected) {
            techno->Select();
            AllowVoice = false;
        }
    }
    AllowVoice = true;
    Func_6CCF00();
}

// 0x2eaf40 (CenterTeam)
void Center_Team_Command(int team)
{
    Reset_Mouse_Modes();
    if (CurrentObjects.Count()) {
        ObjectClass * object = CurrentObjects[0];
        if (!Is_Foot(object) || ((TechnoClass *)CurrentObjects[0])->Group != team - 1) {
            TacticalMap->Unselect_All();
        }
    }
    for (int index = 0; index < Technos.Count(); index++) {
        TechnoClass * techno = Technos[index];
        if (techno && !techno->IsInLimbo && techno->Group == team - 1 && techno->Is_Owned_By_Human() && !techno->IsSelected) {
            techno->Select();
            AllowVoice = false;
        }
    }
    Map.Func_49E0E0();
    Map.Flag_To_Redraw(true);
    AllowVoice = true;
}

// 0x2eb060 (AddTeam)
void Add_Team_Command(int team)
{
    Reset_Mouse_Modes();
    AllowVoice = true;
    for (int index = 0; index < Technos.Count(); index++) {
        TechnoClass * techno = Technos[index];
        if (techno && !techno->IsInLimbo && techno->Group == team - 1 && techno->Is_Owned_By_Human() && !techno->IsSelected) {
            techno->Select();
            AllowVoice = false;
        }
    }
    AllowVoice = true;
}

// 0x2eb140
void Request_Alliance(int house)
{
    if (Session.Type != 0 && !(Scen->SpecialFlags & 0x400) && Rule->AllowAlliances) {
        OutList.Add(EventClass(PlayerPtr->ArrayIndex, EVENT_ALLY, house));
    }
}

// 0x2eb1f0 (ToggleAlliance)
void Alliance_Command()
{
    if (CurrentObjects.Count() && !PlayerPtr->IsDefeated && CurrentObjects[0]->Owner_House() != PlayerPtr && CurrentObjects[0]->Owner_House()->IsPlayerControl) {
        Request_Alliance(CurrentObjects[0]->Owner_House_Index());
    }
}

// 0x2eb300 (Delete)
void Delete_Command()
{
    PlanningNodeClass * node = Selected_Planning_Node();
    if (node) {
        node->Delete();
    } else {
        Object836C18.Func_42E940(-1, -1);
    }
}

// 0x2eb320 (PlaceBeacon)
void Place_Beacon_Command()
{
    Map.Func_49C860(-1);
}

// 0x2eb330
void Planning_Mode_Begin(bool flag)
{
    Func_60C340();
    Func_60EAA0(flag, true);
}

// 0x2eb350
void Planning_Mode_End(bool flag)
{
    Func_60C390();
    Func_60EAA0(flag, false);
}

// 0x2eb370
bool Planning_Mode_Active()
{
    return Is_Planning_Active();
}

// 0x2eb380
bool All_Can_Attack_Move()
{
    int count = CurrentObjects.Count();
    for (int index = 0; index < count; index++) {
        ObjectClass * object = CurrentObjects[index];
        if (Is_Techno(object) && !((TechnoClass *)object)->Slot_275_Query()) {
            return false;
        }
    }
    return true;
}

// 0x2eb3d0
void Attack_Move_Command()
{
    if (CurrentObjects.Count() == 0) {
#line 664 "C:\\RA2\\UICmnds.cpp"
        Show_Command_Message(Fetch_String("MSG:NothingSelected", NULL, __FILE__, __LINE__));
    } else if (!All_Can_Attack_Move()) {
#line 670
        Show_Command_Message(Fetch_String("MSG:AttackMoveUnsupported", NULL, __FILE__, __LINE__));
        return;
    }
    AttackMoveArmed = true;
}

// 0x2eb4c0
void Attack_Move_Disarm()
{
    AttackMoveArmed = false;
}

// 0x2eb4d0
bool Is_Attack_Move()
{
    if (AttackMoveArmed) {
        return true;
    }
    bool move = Key_Down(KeyForceMove1) || Key_Down(KeyForceMove2);
    bool attack = Key_Down(KeyForceAttack1) || Key_Down(KeyForceAttack2);
    if (move && attack && All_Can_Attack_Move()) {
        return true;
    }
    return false;
}

// 0x2eb590
int Attack_Move_Action()
{
    return 0x47;
}

// 0x2eb5a0
int Attack_Move_Shape()
{
    return 0x16;
}

// 0x2eb5b0
void Attack_Move_Mouse()
{
    Map.Func_59BF60(0x4D, false);
}

// 0x2eb5c0
void Attack_Move_Mouse_Small()
{
    Map.Func_59BF60(0x4C, false);
}

// 0x2eb5d0
void Attack_Move_Cancel()
{
    AttackMoveArmed = false;
}

// 0x2eb5e0
void Set_Last_Command(int command)
{
    LastCommand = command;
    AttackMoveArmed = false;
}

// 0x2eb5f0
void Selection_Scope_Message(wchar_t * buffer)
{
    if (CurrentObjects.Count() == 0) {
#line 817
        wcscpy(buffer, Fetch_String("MSG:NothingSelected", NULL, __FILE__, __LINE__));
    } else if (SelectAcrossMap) {
#line 819
        wcscpy(buffer, Fetch_String("MSG:SelAcrossMap", NULL, __FILE__, __LINE__));
    } else {
#line 821
        wcscpy(buffer, Fetch_String("MSG:SelAcrossScreen", NULL, __FILE__, __LINE__));
    }
}

// 0x2eb670
void Cycle_Message(wchar_t * buffer, wchar_t const * text)
{
    wchar_t name[100];
    if (CycleList->Count() && text) {
        wcscpy(name, text);
        _wcsupr(name);
        int count = CurrentObjects.Count();
        if (count == 0) {
#line 840
            swprintf(buffer, Fetch_String("MSG:NoUnitsSel", NULL, __FILE__, __LINE__), name);
            return;
        }
        int worth = 0;
        for (int index = 0; index < count; index++) {
            ObjectClass * object = CurrentObjects[index];
            if (Is_Techno(object)) {
                HouseClass * house = ((TechnoClass *)object)->House;
                worth += object->Class_Of()->Cost_Of(house);
            }
        }
#line 860
        swprintf(buffer, Fetch_String("MSG:UnitsWorth", NULL, __FILE__, __LINE__), count, name, worth);
    } else {
#line 830
        wcscpy(buffer, Fetch_String("MSG:NavEmpty", NULL, __FILE__, __LINE__));
    }
}

// 0x2eb790
DynamicVectorClass<TechnoClass *> * Collect_Technos(TechnoFilterFunc filter, void const * data)
{
    DynamicVectorClass<TechnoClass *> * list = new DynamicVectorClass<TechnoClass *>;
    int count = Technos.Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = Technos[index];
        if (filter(techno, data)) {
            list->Add(techno);
        }
    }
    return list;
}

// 0x2eb850
DynamicVectorClass<TechnoClass *> * Collect_Visible(TechnoFilterFunc filter, void const * data)
{
    DynamicVectorClass<TechnoClass *> * list = new DynamicVectorClass<TechnoClass *>;
    int count = TacticalMap->Visible_Count();
    for (int index = 0; index < count; index++) {
        ObjectClass * object = TacticalMap->Visible_Object(index);
        if (Is_Techno(object)) {
            TechnoClass * techno = (TechnoClass *)object;
            if (filter(techno, data)) {
                list->Add(techno);
            }
        }
    }
    return list;
}

// 0x2eb930
DynamicVectorClass<TechnoClass *> * Collect_Selected()
{
    DynamicVectorClass<TechnoClass *> * list = new DynamicVectorClass<TechnoClass *>;
    int count = CurrentObjects.Count();
    for (int index = 0; index < count; index++) {
        ObjectClass * object = CurrentObjects[index];
        if (Is_Techno(object)) {
            list->Add((TechnoClass *)object);
        }
    }
    return list;
}

// 0x2eb9f0
void For_Each(DynamicVectorClass<TechnoClass *> & list, TechnoActionFunc action, void const * data)
{
    int count = list.Count();
    for (int index = 0; index < count; index++) {
        action(list[index], data);
    }
}

// 0x2eba20
void For_Each_If(DynamicVectorClass<TechnoClass *> & list, TechnoFilterFunc filter, TechnoActionFunc action, void const * filter_data, void const * action_data)
{
    int count = list.Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = list[index];
        if (filter(techno, filter_data)) {
            action(techno, action_data);
        }
    }
}

// 0x2eba70
bool All_Of(DynamicVectorClass<TechnoClass *> & list, TechnoFilterFunc filter, void const * data)
{
    int count = list.Count();
    for (int index = 0; index < count; index++) {
        if (!filter(list[index], data)) {
            return false;
        }
    }
    return true;
}

// 0x2ebab0
bool Any_Of(DynamicVectorClass<TechnoClass *> & list, TechnoFilterFunc filter, void const * data)
{
    int count = list.Count();
    for (int index = 0; index < count; index++) {
        if (filter(list[index], data)) {
            return true;
        }
    }
    return false;
}

// 0x2ebaf0
int Find_Name(DynamicVectorClass<char const *> & list, char const * name)
{
    for (int index = 0; index < list.Count(); index++) {
        if (strcmp(name, list[index]) == 0) {
            return index;
        }
    }
    return -1;
}

bool Is_Own_Active(TechnoClass * techno, void const * data);
bool Is_Type_Match(TechnoClass * techno, void const * name);

// Selection tests and action expanded through the pointer-taking helpers (no copies of their own in the image).
// Adapted from meastes/redalert2-decomp (7c68e23b61) src/uicmnds.cpp, GPL-3.0-or-later.
static inline bool Is_Selectable_Combatant(TechnoClass * techno, void const *)
{
    if (techno->Kind_Of() != RTTI_BUILDING && techno->Techno_Type_Class()->IsCombatant) {
        return true;
    }
    return false;
}

static inline bool Is_Unselected_Combatant(TechnoClass * techno, void const *)
{
    if (techno->Kind_Of() != RTTI_BUILDING && techno->Techno_Type_Class()->IsCombatant && !techno->IsSelected) {
        return true;
    }
    return false;
}

static inline void Select_Techno(TechnoClass * techno, void const *)
{
    techno->Select();
}

// 0x2ebb60 (CombatantSelect)
// Adapted from meastes/redalert2-decomp (7c68e23b61), 1.006 Select_All_Combatants 0x6F6D00, GPL-3.0-or-later.
void Combatant_Select_Command(bool clear)
{
    TacticalMap->Func_6A03B0();
    if (LastCommand != 1) {
        SelectAcrossMap = false;
    }
    TechnoFilterFunc test = Is_Own_Active;
    DynamicVectorClass<TechnoClass *> * list;
    if (SelectAcrossMap) {
        list = Collect_Technos(test, NULL);
    } else {
        list = Collect_Visible(test, NULL);
        if (!Any_Of(*list, Is_Unselected_Combatant, NULL)) {
            SelectAcrossMap = true;
        }
        if (SelectAcrossMap) {
            delete list;
            list = Collect_Technos(test, NULL);
        }
    }
    if (clear) {
        TacticalMap->Unselect_All();
    }
    For_Each_If(*list, Is_Selectable_Combatant, Select_Techno, NULL, NULL);
    wchar_t buffer[256];
    Selection_Scope_Message(buffer);
    Show_Command_Message(buffer, -1);
    delete list;
    LastCommand = 1;
    AttackMoveArmed = false;
}

#line 990
// 0x2ebe30
bool Is_Own_Active(TechnoClass * techno, void const *)
{
    return techno && techno->IsActive && techno->Is_Owned_By_Human();
}



// 0x2ebfe0
bool Is_Type_Match(TechnoClass * techno, void const * name)
{
    return techno && techno->IsActive && techno->Is_Owned_By_Human() && techno->Is_Type((char const *)name);
}



bool Has_Type_Name(TechnoClass * techno, DynamicVectorClass<char const *> * names);
DynamicVectorClass<char const *> * Collect_Selected_Names();

// Pointer wrapper operations used by the 1.006 selection commands.
// Adapted from meastes/redalert2-decomp rebuild/include/smartptr.h.
template<class T> class SmartPtr {
public:
    SmartPtr(T * value = 0) : Pointer(value) {}
    ~SmartPtr() { Pointer = 0; }
    operator T *() const { return Pointer; }
    T *operator->() const { return Pointer; }
    T &operator*() const { return *Pointer; }
private:
    T *Pointer;
};

// Predicate adapted from meastes Named_Selection_Test (expanded through Any_Of; no copy of its own in the image).
static inline bool Pending_Named(TechnoClass * object, void const * data)
{
    bool named = Has_Type_Name(object, (DynamicVectorClass<char const *> *)data);
    bool selected = object->IsSelected;
    return named && !selected;
}

// Filter for the final selection (expanded through For_Each_If; no copy of its own in the image).
static inline bool Accept_Named(TechnoClass * object, void const * data)
{
    return Has_Type_Name(object, (DynamicVectorClass<char const *> *)data);
}

// 0x2ec1b0 (TypeSelect)
// Adapted from meastes/redalert2-decomp (7c68e23b61), 1.006 Command_Type_Select, GPL-3.0-or-later.
void Type_Select_Command()
{
    wchar_t buffer[256];

    TacticalMap->Func_6A03B0();
    if (LastCommand != 2) {
        SelectAcrossMap = false;
    }
    DynamicVectorClass<char const *> * names = Collect_Selected_Names();
    // level-2 1.001: STEERING the test goes through a local (as in Combatant_Select_Command and the 1.006 twins) so the
    // inlined collectors keep Is_Own_Active a call; replaces the former #pragma auto_inline(off) on Is_Own_Active.
    TechnoFilterFunc test = Is_Own_Active;
    DynamicVectorClass<TechnoClass *> * list;
    if (SelectAcrossMap) {
        list = Collect_Technos(test, NULL);
    } else {
        list = Collect_Visible(test, NULL);
        if (!Any_Of(*list, Pending_Named, names)) {
            SelectAcrossMap = true;
        }
        if (SelectAcrossMap) {
            delete list;
            list = Collect_Technos(test, NULL);
        }
    }
    For_Each_If(*list, Accept_Named, Select_Techno, names, NULL);
    Selection_Scope_Message(buffer);
    Show_Command_Message(buffer, -1);
    LastCommand = 2;
    AttackMoveArmed = false;
    delete names;
    delete list;
}

// 0x2ec450
bool Has_Type_Name(TechnoClass * techno, DynamicVectorClass<char const *> * names)
{
    int count = names->Count();
    for (int index = 0; index < count; index++) {
        char const * name = (*names)[index];
        if (techno->Is_Type(name)) {
            return true;
        }
    }
    return false;
}

// 0x2ec490
void Type_Select_Key_Down()
{
    if (!TypeSelectDown) {
        TypeSelectDown = true;
        TypeSelectTime = timeGetTime();
    }
}

// 0x2ec4b0
void Type_Select_Key_Up()
{
    if (TypeSelectDown) {
        TypeSelectDown = false;
        if (abs((int)(timeGetTime() - TypeSelectTime)) <= 500) {
            Type_Select_Command();
            Map.Flag_To_Redraw(true);
        }
    }
}

// 0x2ec4f0
bool Is_Type_Select_Down()
{
    return TypeSelectDown;
}

// 0x2ec500
DynamicVectorClass<char const *> * Collect_Selected_Names()
{
    DynamicVectorClass<char const *> * names = new DynamicVectorClass<char const *>;
    int count = CurrentObjects.Count();
    for (int index = 0; index < count; index++) {
        char const * name = CurrentObjects[index]->Class_Of()->ID;
        if (Find_Name(*names, name) == -1) {
            names->Add(name);
        }
    }
    return names;
}

// 0x2ec640
void For_Each_Of_Type(char const * name, TechnoActionFunc action, void const * data)
{
    TechnoFilterFunc test = Is_Type_Match;
    DynamicVectorClass<TechnoClass *> * list;
    if (SelectAcrossMap) {
        list = Collect_Technos(test, name);
    } else {
        list = Collect_Visible(test, name);
    }
    For_Each(*list, action, data);
    delete list;
}

// 0x2ec7b0
void Remove_From_Cycle(TechnoClass * techno)
{
    if (CycleList) {
        for (int index = CycleList->Count() - 1; index >= 0; index--) {
            if ((*CycleList)[index] == techno) {
                CycleList->Delete(index);
                break;
            }
        }
    }
}

// 0x2ec800
void Build_Cycle_List()
{
    Clear_Cycle_List();
    CycleList = Collect_Selected();
    if (CycleList->Count() == 0) {
        Clear_Cycle_List();
        DynamicVectorClass<TechnoClass *> * list = new DynamicVectorClass<TechnoClass *>;
        int count = TacticalMap->Visible_Count();
        for (int index = 0; index < count; index++) {
            ObjectClass * object = TacticalMap->Visible_Object(index);
            if (Is_Techno(object) && object->IsActive && ((TechnoClass *)object)->Is_Owned_By_Human() && object->Kind_Of() != RTTI_BUILDING) {
                list->Add((TechnoClass *)object);
            }
        }
        CycleList = list;
    }
}

bool Is_Own_Active_Unit(TechnoClass * techno, void const * data);
wchar_t const * Health_Name(int state);
int Next_Health_State(int state);

// Adapted from the 1.006 Refresh_Type_Select_List shared by health and rank.
static void Refresh_Cycle_List()
{
    Clear_Cycle_List();
    CycleList = Collect_Selected();
    if (CycleList->Count() == 0) {
        delete CycleList;
        CycleList = 0;
        CycleList = Collect_Visible(Is_Own_Active_Unit, NULL);
    }
}

// 0x2ec9c0 (HealthNav)
void Health_Nav_Command(bool clear)
{
    wchar_t buffer[256];
    int state;

    if (LastCommand != 3) {
        Refresh_Cycle_List();
        TacticalMap->Unselect_All();
        state = 0;
    } else {
        state = Next_Health_State(LastHealthState);
        if (clear) {
            TacticalMap->Unselect_All();
        }
    }

    DynamicVectorClass<TechnoClass *> * cycle = CycleList;
    int count = cycle->Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = (*cycle)[index];
        if (techno->Health_Status() == state) {
            techno->Select();
        }
    }

    wchar_t const * text = Health_Name(state);
    SmartPtr<DynamicVectorClass<TechnoClass *> > selected(Collect_Selected());
    count = selected->Count();
    for (index = 0; index < count; index++) {
        if ((*selected)[index]->Health_Status() != state) {
#line 1343
            text = Fetch_String("MSG:Mixed", NULL, __FILE__, __LINE__);
            break;
        }
    }
    delete selected;

    Cycle_Message(buffer, text);
    Show_Command_Message(buffer);
    LastHealthState = state;
    int commands = CycleList->Count();
    LastCommand = 0;
    if (commands) {
        LastCommand = 3;
    }
    AttackMoveArmed = false;
}

// 0x2ecc20
bool Is_Own_Active_Unit(TechnoClass * techno, void const *)
{
    return techno && techno->IsActive && techno->Is_Owned_By_Human() && techno->Kind_Of() != RTTI_BUILDING;
}

// 0x2ecc70
wchar_t const * Health_Name(int state)
{
    if (state == 0) {
#line 1364
        return Fetch_String("MSG:Critical", NULL, __FILE__, __LINE__);
    } else if (state == 1) {
        return Fetch_String("MSG:HeavilyDamaged", NULL, __FILE__, __LINE__);
    } else if (state == 2) {
        return Fetch_String("MSG:Healthy", NULL, __FILE__, __LINE__);
    }
    return NullWString;
}

// 0x2eccd0
int Next_Health_State(int state)
{
    if (state == -1) {
        return 0;
    }
    if (state == 0) {
        return 1;
    }
    return state == 1 ? 2 : 0;
}

wchar_t const * Veterancy_Name(int state);
int Next_Veterancy_State(int state);


// 0x2eccf0 (VeterancyNav)
// Adapted from meastes/redalert2-decomp (7c68e23b61), 1.006 Unknown_006F7EC0, GPL-3.0-or-later.

void Veterancy_Nav_Command(bool clear)
{
    wchar_t buffer[256];
    int state;

    if (LastCommand != 4) {
        Refresh_Cycle_List();
        TacticalMap->Unselect_All();
        state = 0;
    } else {
        state = Next_Veterancy_State(LastVeteranState);
        if (clear) {
            TacticalMap->Unselect_All();
        }
    }

    DynamicVectorClass<TechnoClass *> * cycle = CycleList;
    int count = cycle->Count();
    for (int index = 0; index < count; index++) {
        TechnoClass * techno = (*cycle)[index];
        if (techno->Veterancy.Level() == state) {
            techno->Select();
        }
    }

    wchar_t const * text = Veterancy_Name(state);
    SmartPtr<DynamicVectorClass<TechnoClass *> > selected(Collect_Selected());
    count = selected->Count();
    for (index = 0; index < count; index++) {
        TechnoClass * item = (*selected)[index];
        if (item->Veterancy.Level() != state) {
#line 1415
            text = Fetch_String("MSG:Mixed", NULL, __FILE__, __LINE__);
            break;
        }
    }
    delete selected;

    Cycle_Message(buffer, text);
    Show_Command_Message(buffer);
    LastVeteranState = state;
    int commands = CycleList->Count();
    LastCommand = 0;
    if (commands) {
        LastCommand = 4;
    }
    AttackMoveArmed = false;
}

#line 1431
// 0x2ecf60
wchar_t const * Veterancy_Name(int state)
{
    if (state == 0) {
#line 1435
        return Fetch_String("MSG:Elite", NULL, __FILE__, __LINE__);
    } else if (state == 1) {
        return Fetch_String("MSG:Veteran", NULL, __FILE__, __LINE__);
    } else if (state == 2) {
        return Fetch_String("MSG:LittleExperience", NULL, __FILE__, __LINE__);
    }
    return NullWString;
}

// 0x2ecfc0
int Next_Veterancy_State(int state)
{
    if (state == -1) {
        return 0;
    }
    if (state == 0) {
        return 1;
    }
    return state == 1 ? 2 : 0;
}

// 0x2ecfe0 (type cycling command, uses 0x2ed400, LastTypeName and LastTypeCost): not reconstructed yet.

// 0x2ed2c0
DynamicVectorClass<char const *> * Collect_Type_Names(DynamicVectorClass<TechnoClass *> * list)
{
    DynamicVectorClass<char const *> * names = new DynamicVectorClass<char const *>;
    int count = list->Count();
    for (int index = 0; index < count; index++) {
        char const * name = (*list)[index]->Class_Of()->ID;
        if (Find_Name(*names, name) == -1) {
            names->Add(name);
        }
    }
    return names;
}

// 0x2ed400 (next type name by cost; builds a DynamicVectorClass<int> of costs, vtable 0x788a94):
// not reconstructed yet.
