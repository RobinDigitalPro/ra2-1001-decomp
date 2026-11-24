// C:\RA2\MPCoop.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Contents: the cooperative multiplayer game mode (RTTI .?AVMPCooperative@@ : MultiplayerGameMode)
// with its campaign selection and dialog support, plus the vector template instances it uses.
// Class names come from RTTI (MPCooperative, MultiplayerGameMode, CoopCampaignClass, INIClass,
// CCFileClass, DynamicVectorClass/VectorClass instances); all other names are provisional.
//
// TU boundary: 0x19f3d0 (GAMECONST block, 12 initializers; 0x19f5a0 zeroes 16 bytes at 0xa58cd8,
// directly before this TU's GAMECONST .bss, and is not reconstructed) to 0x1a3a70. The template
// tail (0x1a2ed0..0x1a3a67) is this TU's COMDAT output. 0x1a3a70 (zeroes 0xa58d70) belongs to the
// next TU (FreeForAll, first initializer block at 0x1a3a90). 0x1a1070 in the function map is a
// fragment inside Slot22 (0x1a0f80..0x1a10e8), not a function.
// Not reconstructed yet: slot 37 (0x1a23c0, 2152 bytes).
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "GAMECONST.H"
#include <windows.h>

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x6eeb60
void Debug_Printf(char const * format, ...);        // 0x4068f0 (empty in this build)

// Copy of VECTOR.H plus the constructors, copy constructor and assignment that VECTOR.H does not
// have yet (as in Egos.CPP/ToolTip.cpp).
template<class T> class VectorClass {
public:
    VectorClass(unsigned size = 0, T const * array = 0);
    VectorClass(VectorClass<T> const & vector) :
        Vector(0), VectorMax(0), IsInitialized(true), IsAllocated(false)
    {
        *this = vector;
    }
    VectorClass<T> & operator = (VectorClass<T> const & vector)
    {
        if (this != &vector) {
            Clear();
            VectorMax = vector.Length();
            if (VectorMax) {
                Vector = new T[VectorMax];
                if (Vector) {
                    IsAllocated = true;
                    for (int index = 0; index < VectorMax; index++) {
                        Vector[index] = vector.Vector[index];
                    }
                }
            } else {
                Vector = 0;
                IsAllocated = false;
            }
        }
        return *this;
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
    int Add(T const & object);
    int Delete(T const & object);
    int Delete(int index);

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

template<class T> inline int DynamicVectorClass<T>::Add(T const & object)
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

template<class T> inline int DynamicVectorClass<T>::Delete(T const & object)
{
    int index = ID(object);
    if (index != -1) {
        return Delete(index);
    }
    return false;
}

template<class T> inline int DynamicVectorClass<T>::Delete(int index)
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

// One-pointer string classes (provisional names, as in MPObserver.cpp).
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);
    WideStringClass(WideStringClass const & string);
    ~WideStringClass();
private:
    wchar_t * Buffer;
};

class CharStringClass {
public:
    CharStringClass(CharStringClass const & string);
    ~CharStringClass();
private:
    char * Buffer;
};

// File and INI classes (as in WDTSel.cpp).
class FileClass {
public:
    virtual ~FileClass() {}
    virtual char const * File_Name() const = 0;
    virtual char const * Set_Name(char const * filename) = 0;
    virtual int Create() = 0;
    virtual int Delete() = 0;
    virtual bool Is_Available(int forced = false) = 0;
    virtual bool Is_Open() const = 0;
    virtual int Open(char const * filename, int rights = 1) = 0;
    virtual int Open(int rights = 1) = 0;
    virtual long Read(void * buffer, long size) = 0;
    virtual long Seek(long pos, int dir = 1) = 0;
    virtual long Size() = 0;
    virtual long Write(void const * buffer, long size) = 0;
    virtual void Close() = 0;
    virtual unsigned long Get_Date_Time() = 0;
    virtual bool Set_Date_Time(unsigned long datetime) = 0;
    virtual void Error(int error, int canretry = false, char const * filename = NULL) = 0;
};

class RawFileClass : public FileClass {
public:
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();
    virtual int Delete();
    virtual bool Is_Available(int forced = false);
    virtual bool Is_Open() const;
    virtual int Open(char const * filename, int rights = 1);
    virtual int Open(int rights = 1);
    virtual long Read(void * buffer, long size);
    virtual long Seek(long pos, int dir = 1);
    virtual long Size();
    virtual long Write(void const * buffer, long size);
    virtual void Close();
    virtual unsigned long Get_Date_Time();
    virtual bool Set_Date_Time(unsigned long datetime);
    virtual void Error(int error, int canretry = false, char const * filename = NULL);
private:
    char RawFileData[0x1C];
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);   // 0x438140
    ~Buffer();                                     // 0x438290
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename);                     // 0x468b70
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual void Close();                                   // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Doubly linked list. Here the GenericList constructor is inlined; the node constructor and Link
// are out of line.
class GenericNode {
public:
    GenericNode();                      // 0x40e160
    virtual ~GenericNode();
    void Link(GenericNode * node);      // 0x40e180
private:
    GenericNode * NextNode;
    GenericNode * PrevNode;
};

class GenericList {
public:
    GenericList() { FirstNode.Link(&LastNode); }
    virtual ~GenericList();
private:
    GenericNode FirstNode;
    GenericNode LastNode;
};

template<class T>
class List : public GenericList {
};

template<class INDEX, class DATA>
class IndexClass {
public:
    IndexClass() : IndexTable(0), IndexCount(0), IndexSize(0), IsSorted(false), Archive(0) {}
    ~IndexClass();
private:
    void * IndexTable;
    int IndexCount;
    int IndexSize;
    bool IsSorted;
    void const * Archive;
};

// RTTI .?AVINIClass@@ (vtable 0x78db34).
class INIClass {
public:
    struct INISection;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                                                        // 0x50ad20
    int Load(FileClass & file, bool withdigest);                                // 0x50b030
    int Get_Int(char const * section, char const * entry, int defvalue) const;  // 0x50cc40
private:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

// Entry of the session player list (0x71 bytes; layout as in ModemHst.cpp, MPSiegeTeam.cpp).
#pragma pack(push, 1)
class IPXAddressClass {
public:
    IPXAddressClass();                          // 0x522950
    void Set_Address(unsigned char * net, unsigned char * node);   // 0x5229e0
    void Get_Address(unsigned char * net, unsigned char * node);   // 0x522a60
    bool operator == (IPXAddressClass const & address) const;      // 0x522ae0
private:
    unsigned char NetworkNumber[4];
    unsigned char NodeAddress[6];
};

struct NodeNameType {
    int Side() const;                           // 0x664e80
    int Get_Color() const;                      // 0x664ea0
    void Set_Side(int side);                    // 0x664ec0

    wchar_t Name[20];                           // +0x00
    IPXAddressClass Address;                    // +0x28
    char Handle[0x49 - 0x32];                   // +0x32 (provisional)
    int House;                                  // +0x49
    int Field4D;                                // +0x4d
    int Color;                                  // +0x51
    int Field55;                                // +0x55
    int Team;                                   // +0x59
    int HouseIndex;                             // +0x5d
    int Field61;                                // +0x61
    int Field65;                                // +0x65
    int Field69;                                // +0x69
    char Unknown6D[0x71 - 0x6D];
};
#pragma pack(pop)

void Delete_All(DynamicVectorClass<NodeNameType *> & vector);  // 0x5a4070 (MPLayer.CPP)

// Scenario description of the session list (as in ModemHst.cpp).
class MultiMission {
public:
    wchar_t Description[0x2C];                  // +0x00
    char FileName[0x104];                       // +0x58
};

// Session object at 0xa255c8 (class name provisional); only the members used here, at their
// binary offsets (names as in ModemHst.cpp where known).
class SessionClass {
public:
    int Type;                                   // +0x0000 (0xa255c8)
    char Unknown0004[0x001C - 0x0004];
    int ScenarioIdx;                            // +0x001c (0xa255e4)
    bool Bases;                                 // +0x0020 (0xa255e8)
    char Unknown0021[0x0024 - 0x0021];
    int Credits;                                // +0x0024 (0xa255ec)
    bool BridgeDestruction;                     // +0x0028 (0xa255f0)
    bool Crates;                                // +0x0029 (0xa255f1)
    bool ShortGame;                             // +0x002a (0xa255f2)
    bool SuperWeapons;                          // +0x002b (0xa255f3)
    bool BuildOffAlly;                          // +0x002c (0xa255f4)
    char Unknown002D[0x0030 - 0x002D];
    int GameSpeed;                              // +0x0030 (0xa255f8)
    bool CrapEngineers;                         // +0x0034 (0xa255fc)
    char Unknown0035[0x0038 - 0x0035];
    int UnitCount;                              // +0x0038 (0xa25600)
    int AIPlayers;                              // +0x003c (0xa25604)
    int AIDifficulty;                           // +0x0040 (0xa25608)
    int AIDifficulties[8];                      // +0x0044 (0xa2560c), per player slot
    int AIHouses[8];                            // +0x0064 (0xa2562c)
    int AIColors[8];                            // +0x0084 (0xa2564c)
    bool Flag0A4;                               // +0x00a4 (0xa2566c)
    bool HarvesterTruce;                        // +0x00a5 (0xa2566d)
    bool Flag0A6;                               // +0x00a6 (0xa2566e)
    bool FogOfWar;                              // +0x00a7 (0xa2566f)
    bool MCVRedeploy;                           // +0x00a8 (0xa25670)
    char Unknown00A9[0x0124 - 0x00A9];
    int House;                                  // +0x0124 (0xa256ec)
    char Unknown0128[0x02B0 - 0x0128];
    int Field2B0;                               // +0x02b0 (0xa25878)
    char Unknown02B4[0x02C4 - 0x02B4];
    int NumPlayers;                             // +0x02c4 (0xa2588c)
    char Unknown02C8[0x0640 - 0x02C8];
    DynamicVectorClass<MultiMission *> Scenarios;// +0x0640 (0xa25c08)
    char Unknown0658[0x0884 - 0x0658];
    int Field884;                               // +0x0884 (0xa25e4c, number of player slots?)
    char Unknown0888[0x0894 - 0x0888];
    IPXAddressClass MyAddress;                  // +0x0894 (0xa25e5c, provisional)
    char Unknown089E[0x2376 - 0x089E];
    wchar_t Handle[20];                         // +0x2376 (0xa2793e), the local player name
    char Unknown239E[0x27E0 - 0x239E];
    DynamicVectorClass<NodeNameType *> Players; // +0x27e0 (0xa27da8)
    char Unknown27F8[0x27FC - 0x27F8];
    NodeNameType * Slots[8];                    // +0x27fc (0xa27dc4, meaning provisional)
    char Unknown281C[0x33B4 - 0x281C];
    int Field33B4;                              // +0x33b4 (0xa2897c)
};
extern SessionClass Session;                    // 0xa255c8

bool Set_Scenario(int index);                   // 0x5c1bd0
extern wchar_t NullWString[];                   // 0x82208c

// RTTI .?AVHouseTypeClass@@; only the field used here.
class HouseTypeClass {
public:
    wchar_t const * Full_Name() const { return UIName; }

    char Unknown00[0x24];
    char ID[0x3C];                              // +0x24 (AbstractTypeClass::ID)
    wchar_t const * UIName;                     // +0x60
    char Unknown64[0xB8 - 0x64];
    int FieldB8;                                // +0xb8 (printed with the alliances)
    int FieldBC;                                // +0xbc
    int FieldC0;                                // +0xc0
    char UnknownC4[0x1A6 - 0xC4];
    bool IsMultiplayPassive;                    // +0x1a6
};
extern DynamicVectorClass<HouseTypeClass *> HouseTypes;    // 0xa1e038

// Cell coordinates (RTTI .?AV?$VectorClass@VCell@@@@; same layout as CellStruct in COORD.H).
class Cell {
public:
    Cell() {}
    Cell(short x, short y) : X(x), Y(y) {}
    bool operator == (Cell const & cell) const { return X == cell.X && Y == cell.Y; }
    bool operator != (Cell const & cell) const { return X != cell.X || Y != cell.Y; }
    Cell operator - (Cell const & cell) const { return Cell((short)(X - cell.X), (short)(Y - cell.Y)); }
    short X;
    short Y;
};

double __cdecl Square_Root(double value);       // 0x4ba080 (provisional)
DynamicVectorClass<Cell> Get_Start_Cells(bool flag);    // 0x656fd0 (provisional)
int Scenario_Max_Players(int index);            // 0x5c0690

// RTTI .?AVHouseTypeClass@@ / .?AVHouseClass@@; only the fields used here.
class HouseTypeClass2;
class HouseClass {
public:
    char Unknown0000[0x34];
    void Make_Ally(HouseClass * house, bool announce);  // 0x4e4d00
    bool Is_Human() const;                      // 0x4f47f0 (provisional)

    HouseTypeClass * Class;                     // +0x34
    char Unknown0038[0x134 - 0x38];
    bool IsHuman;                               // +0x134 (provisional)
    char Unknown0135[0x13D - 0x135];
    bool IsDefeated;                            // +0x13d
    char Unknown013E[0x53BC - 0x13E];
    CoordStruct StartCoord;                     // +0x53bc (provisional)
    char Unknown53C8[0x15F16 - 0x53C8];
    wchar_t IniName[21];                        // +0x15f16
};
char const * Wide_To_Ascii(wchar_t const * string);    // 0x6eedc0 (provisional)
extern DynamicVectorClass<HouseClass *> Houses;     // 0xa1a5c8

// GDlgSupp.cpp and others.
int Player_Side_ID(int slot);                           // 0x4d0d70
void Select_Side(HWND dialog, int id, int side);        // 0x4d1310
void Fill_All_Side_Lists(HWND dialog);                  // 0x4d1030
void Update_Player_Slots(HWND dialog, int count);       // 0x5c44c0 (provisional)
int Coop_Selected_Campaign();                           // 0x5c0830 (provisional)

// Timers (as in MPScore.cpp).
class SystemTimerClass {
public:
    long operator()() const;                // 0x68fad0
};

template<class T>
class TTimerClass {
public:
    long Value() const
    {
        long value = Accumulated;
        if (Started != -1) {
            value += Timer() - Started;
        }
        return value;
    }
    long Started;
    T Timer;
    long Accumulated;
};

// Random number generator inside the scenario (as in MPScore.cpp).
// level-2 1.001: Random2Class (operator() 0x62FE40, the scenario generator), not RandomClass (0x62FCC0); shown by the P9 link check.
class Random2Class {
public:
    int operator()(int minval, int maxval); // 0x62fe40
};
class ScenarioClass {
public:
    char Unknown0[0x218];
    Random2Class RandomNumber;               // +0x218
    char Unknown219[0x614 - 0x219];
    TTimerClass<SystemTimerClass> ElapsedTimer;     // +0x614
    char Unknown620[0x834 - 0x620];
    int ScenarioIndex;                      // +0x834 (provisional)
    char Unknown838[0x2230 - 0x838];
    bool Field2230;                         // +0x2230
    char Unknown2231[1];
    bool Field2232;                         // +0x2232
    bool Field2233;                         // +0x2233
    bool Field2234;                         // +0x2234
};
extern ScenarioClass * Scen;                // 0xa255c0

void Send_Campaign_Settings(char const * text);         // 0x5be7a0 (provisional)

extern int TechLevel;                           // 0x7c3978 (.data, initial 10; name provisional)

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)

class RulesClass {
public:
    char Unknown00[0x1128];
    double MessageDelay;                        // +0x1128, minutes
};
extern RulesClass * Rule;                       // 0x821b88

int Message_Color();                            // 0x4ceba0 (provisional)

// Global map object at 0x81a820 (its exact class is not yet bound).
class MapClass {
public:
    void Func_498CF0(int value);                // 0x498cf0 (meaning unknown)
    char Unknown0000[0x11A0];
    int Field11A0;                              // +0x11a0 (0x81b9c0)
    int Field11A4;                              // +0x11a4
    int Field11A8;                              // +0x11a8
};
extern MapClass Map;

// Score records of MPScore.cpp (0xa27534); only the field used here.
struct MPScoreRecord {
    wchar_t Name[20];                       // +0x00
    int Scheme;                             // +0x28
    int Wins;                               // +0x2c
    int Lost[4];                            // +0x30
    int Kills[4];                           // +0x40
    int Built[4];                           // +0x50
    int Score[4];                           // +0x60
};
struct MPScoreData {
    MPScoreRecord Records[8];               // 0xa27534
    int GameNumber;                         // 0xa278b4
    int PlayerCount;                        // 0xa278b8
    int WinnerIndex;                        // 0xa278bc
    int Game;                               // 0xa278c0: reloaded after each store below, so it is
                                            // part of this aggregate (MPScore.cpp ends it at 0xa278bc)
};
extern MPScoreData ScoreData;

// Dialog support.
HWND Current_Dialog();                          // 0x72a6d0
void Coop_Dialog_Func_5BDF90(HWND dialog, class MPCooperative * mode);   // 0x5bdf90 (meaning unknown)
void Coop_Dialog_Func_5BDFF0(HWND dialog);      // 0x5bdff0 (meaning unknown)
void Coop_Dialog_Func_5C15D0(HWND dialog);      // 0x5c15d0 (meaning unknown)
void Coop_Func_5BE350(bool a, bool b);          // 0x5be350 (meaning unknown)
void __cdecl Coop_Message(int id, wchar_t const * text);    // 0x5bd810 (provisional)
HWND Find_Dialog(int id);                       // 0x72a500, NULL when not open
int Current_Dialog_ID();                        // 0x72a6e0
HWND Get_Coop_Dialog();                         // 0x5bd7d0 (provisional)

// House type index of a campaign house name, -2 for "<random>", -1 when unknown (coopcamp.cpp).
int Coop_House_From_Name(char const * name);    // 0x490280

// One campaign definition from COOPCAMP.INI, 0x44 bytes (as in coopcamp.cpp).
struct CoopCampaignType {
    int ID;                                     // +0x00
    wchar_t * Name;                             // +0x04
    char MapCount;                              // +0x08
    char (* Maps)[0x104];                       // +0x0c, three alternatives per map
    DynamicVectorClass<char *> Players;         // +0x10, "CampaignPlayer" houses
    DynamicVectorClass<char *> Enemies;         // +0x28, "CampaignEnemy" houses
    char * AI;                                  // +0x40, "CampaignAI"
};

// The campaign definitions read from COOPCAMP.INI, 0x5c bytes (as in coopcamp.cpp).
class CoopCampaignListClass {
public:
    CoopCampaignListClass();                    // 0x4902f0
    ~CoopCampaignListClass();                   // 0x490a80
    bool Get_Campaign(int index, CoopCampaignType ** campaign);     // 0x490a30
    bool Get_Count(int * count);                // 0x490a70
    bool Get_Names(VectorClass<wchar_t *> & names);                 // 0x490be0

    char INI[0x50];                             // +0x00 CCINIClass
    CoopCampaignType * Campaigns;               // +0x50
    int Count;                                  // +0x54
    bool IsLoaded;                              // +0x58
};

// Score line of one player (RTTI .?AV?$DynamicVectorClass@PAUMPlayerScoreType@@@@); 0x70 bytes,
// passed by value to Set_Progress. coopcamp.cpp calls it MPScoreRecord (MPScore.cpp layout).
// The deletes here test the pointer before operator delete, as for a type with a destructor.
struct MPlayerScoreType {
    ~MPlayerScoreType() {}
    char Data[0x70];
};

// Cooperative score screen (provisional name; 8 bytes, constructor 0x465820).
class CoopScoreClass {
public:
    CoopScoreClass();                           // 0x465820
    virtual ~CoopScoreClass();
    virtual void Presentation(DynamicVectorClass<MPlayerScoreType *> scores, long time, bool unfinished, int level, wchar_t const * name);
    int Field04;
};

// Final campaign screen (provisional name; 4 bytes, constructor 0x466e30).
class CoopFinalClass {
public:
    CoopFinalClass();                           // 0x466e30
    virtual ~CoopFinalClass();
    virtual void Presentation(DynamicVectorClass<MPlayerScoreType *> scores, int count, int level, int campaign, wchar_t const * name);
};

extern bool CoopScoreFlag;                      // 0x83884c (provisional)


// RTTI .?AVCoopCampaignClass@@ (no vtable), 0x70 bytes: the state of one cooperative campaign
// (method names as in coopcamp.cpp).
class CoopCampaignClass {
public:
    CoopCampaignClass();                        // 0x48de20
    CoopCampaignClass(wchar_t const * name1, wchar_t const * name2);   // 0x48de70
    ~CoopCampaignClass();                       // 0x48df30
    void Set_Players(wchar_t const * name1, wchar_t const * name2);    // 0x48df70
    bool Next_Map();                            // 0x48e140
    bool Get_Campaign_Type(int * type);         // 0x48e490
    bool Get_Map_Count(int * count);            // 0x48e4b0
    bool Get_Current_Map(int * map);            // 0x48e4d0
    bool Get_Scores(DynamicVectorClass<MPlayerScoreType *> & list, int * time);   // 0x48e4f0
    bool Load();                                // 0x48e910
    bool Save();                                // 0x48ee20
    bool Start(int campaign);                   // 0x48f370
    bool Set_Progress(int map, int time, MPlayerScoreType score1, MPlayerScoreType score2);   // 0x48f510
    bool Setup(CoopCampaignListClass * list, int campaign, DynamicVectorClass<int> picks, char const * name2, char const * name1);   // 0x48f5b0
    bool Get_Map(char ** map, int index);       // 0x48f920
    bool Is_Saved();                            // 0x48f9d0
    bool Is_Finished(char * buffer);            // 0x48fc50
    bool Send(CoopCampaignListClass * list);    // 0x48ff30
    char Data[0x70];
};

// RTTI .?AVMultiplayerTeam@@.
class MultiplayerTeam;

// RTTI .?AVMultiplayerGameMode@@, vtable 0x792188 (44 slots). Slot names provisional.
class MultiplayerGameMode {
public:
    MultiplayerGameMode(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value);  // 0x5b37e0
    virtual ~MultiplayerGameMode();                     // 0x5b3930
    virtual bool Slot01();                              // 0x59f150
    virtual bool Slot02();                              // 0x59f160
    virtual bool Slot03(int);                           // 0x59f170
    virtual bool Init();                                // 0x5b3e40
    virtual bool Slot05(int value);                     // 0x5b3e70
    virtual bool Slot06();                              // 0x5b3ea0
    virtual bool Is_Valid_House(int house);             // 0x5b42d0
    virtual void Slot08();                              // 0x59f180
    virtual void Request_Refresh();                     // 0x59f190
    virtual int Slot10();                               // 0x5b39c0
    virtual bool Slot11();                              // 0x5b3eb0
    virtual void Slot12();                              // 0x5b3ec0
    virtual int Slot13();                               // 0x5b3ed0
    virtual void Slot14();                              // 0x5b3f80
    virtual void Fill_Scenario_List(HWND list, DynamicVectorClass<MultiMission *> & scenarios, int unused);   // 0x5b3ff0
    virtual void Slot16(int a, int b);                  // 0x5b4070
    virtual bool Slot17(int a, DynamicVectorClass<int> b);  // 0x59f1c0
    virtual bool Slot18(int campaign, DynamicVectorClass<int> picks, char const * name2, char const * name1);   // 0x59f1a0
    virtual bool Slot19(int map, int time, MPlayerScoreType * scores);   // 0x59f1e0
    virtual bool Slot20();                              // 0x5b3e80
    virtual bool Slot21();                              // 0x5b3e90
    virtual bool Slot22();                              // 0x59f1f0
    virtual int Slot23();                               // 0x5b3f60
    virtual int Slot24();                               // 0x5b3f70
    virtual void Slot25(int type, char * text);         // 0x59f200
    virtual bool Slot26();                              // 0x5b42c0
    virtual bool Slot27(bool flag);                     // 0x5b44f0
    virtual bool Slot28();                              // 0x5b4cb0
    virtual bool Reveal_Map();                          // 0x5b4d00 returns true
    virtual void Slot30();                              // 0x59f210
    virtual void Slot31();                              // 0x59f220
    virtual int Slot32();                               // 0x59f230
    virtual void Slot33();                              // 0x59f240
    virtual void Slot34(bool won);                      // 0x59f250
    virtual void Slot35(bool flag);                     // 0x59f260
    virtual bool Slot36();                              // 0x59f270
    virtual void Slot37();                              // 0x59f280
    virtual void Slot38();                              // 0x59f290
    virtual bool Slot39(DynamicVectorClass<struct MPlayerScoreType *> scores, int * result);   // 0x59f2a0
    virtual void Slot40();                              // 0x5b41c0
    virtual Cell Pick_Start_Cell(int house, DynamicVectorClass<Cell> & cells, bool * used);   // 0x5b43c0
    virtual void Slot42();                              // 0x5b4820
    virtual void Slot43();                              // 0x5b48f0

    bool Field04;                                       // +0x04
    char Teams[0x18];                                   // +0x08 DynamicVectorClass<MultiplayerTeam *>
    char Name[4];                                       // +0x20 WideStringClass
    char Description[4];                                // +0x24 WideStringClass
    int Value;                                          // +0x28
    char IniName[4];                                    // +0x2c CharStringClass
    char IniFile[4];                                    // +0x30 CharStringClass
    bool Flag;                                          // +0x34
    void * INI;                                         // +0x38 CCINIClass *
    int Field3C;                                        // +0x3c
};


// RTTI .?AVMPCooperative@@ : MultiplayerGameMode, vtable 0x791764.
class MPCooperative : public MultiplayerGameMode {
public:
    MPCooperative(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value);
    virtual ~MPCooperative();
    virtual bool Slot01() { return true; }
    virtual bool Slot02() { return true; }
    virtual bool Init();
    virtual bool Slot05(int value);
    virtual bool Slot06();
    virtual bool Is_Valid_House(int house);
    virtual void Slot08();
    virtual void Request_Refresh();
    virtual int Slot10();
    virtual bool Slot11();
    virtual int Slot13();
    virtual void Slot16(int a, int b);
    virtual bool Slot18(int campaign, DynamicVectorClass<int> picks, char const * name2, char const * name1);
    virtual bool Slot19(int map, int time, MPlayerScoreType * scores);
    virtual bool Slot20();
    virtual bool Slot21();
    virtual bool Slot22();
    virtual void Slot25(int type, char * text);
    virtual bool Slot26();
    virtual bool Slot27(bool flag);
    virtual bool Slot28();
    virtual int Slot23();
    virtual int Slot24();
    virtual void Slot33();
    virtual void Slot34(bool won);
    virtual void Fill_Scenario_List(HWND list, DynamicVectorClass<MultiMission *> & scenarios, int unused);
    virtual void Slot30();
    virtual void Slot31();
    virtual bool Slot36();
    virtual void Slot35(bool flag);
    virtual void Slot38();
    virtual bool Reveal_Map();
    virtual int Slot32();
    virtual bool Slot39(DynamicVectorClass<struct MPlayerScoreType *> scores, int * result);
    virtual Cell Pick_Start_Cell(int house, DynamicVectorClass<Cell> & cells, bool * used);

    int Find_Scenario();
    void Fill_Side_List(HWND dialog, int id);
    void Update_Dialog(HWND dialog);
    bool New_Campaign();

    CoopCampaignListClass * CampaignList;               // +0x40
    CoopCampaignClass * Current;                        // +0x44
    int Field48;                                        // +0x48
    bool Field4C;                                       // +0x4c
    bool SaveListed;                                    // +0x4d, saved game entry added to list 0x553
    int Field50;                                        // +0x50
    CoopScoreClass * Score;                             // +0x54
    int LocalPlayer;                                    // +0x58, index of the local player in Names
    DynamicVectorClass<NodeNameType *> Names;           // +0x5c, players of the last mission
    // Game settings remembered at the end of a mission (+0x74..+0xc8).
    int SavedHouse;                                     // +0x74
    wchar_t PlayerName[20];                             // +0x78
    int SavedField33B4;                                 // +0xa0
    int SavedTechLevel;                                 // +0xa4
    int SavedUnitCount;                                 // +0xa8
    int SavedCredits;                                   // +0xac
    bool SavedFogOfWar;                                 // +0xb0
    bool SavedBridgeDestruction;                        // +0xb1
    bool SavedCrates;                                   // +0xb2
    bool SavedMCVRedeploy;                              // +0xb3
    bool SavedFlag0A4;                                  // +0xb4
    bool SavedHarvesterTruce;                           // +0xb5
    bool SavedBases;                                    // +0xb6
    bool SavedFlag0A6;                                  // +0xb7
    int SavedAIPlayers;                                 // +0xb8
    int SavedAIDifficulty;                              // +0xbc
    bool SavedShortGame;                                // +0xc0
    bool SavedSuperWeapons;                             // +0xc1
    bool SavedBuildOffAlly;                             // +0xc2
    bool SavedCrapEngineers;                            // +0xc3
    int SavedGameSpeed;                                 // +0xc4
    DynamicVectorClass<int> Lists1[8];                  // +0xc8
    DynamicVectorClass<int> Lists2[8];                  // +0x188
    DynamicVectorClass<CoopCampaignClass *> Campaigns;  // +0x248
    int CampaignIndex;                                  // +0x260
    bool NeedsRefresh;                                  // +0x264
};

// ---- end of local declarations ----

// 0x19f5c0: counts the start waypoints of a map file.
int Map_Player_Count(char const * filename)
{
    if (filename == NULL) {
        return 0;
    }
    CCFileClass file(filename);
    INIClass ini;
    if (!ini.Load(file, false)) {
        return 0;
    }
    int count = 0;
    for (int index = 0; index < 8; index++) {
        char buffer[32];
        sprintf(buffer, "%d", index);
        if (ini.Get_Int("Waypoints", buffer, -1) != -1) {
            count++;
        }
    }
    if (count == 0) {
        count = ini.Get_Int("RandomMap", "NumPlayers", 0);
    }
    return count;
}

MPCooperative::MPCooperative(WideStringClass const & name, WideStringClass const & description,
    CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value) :
    MultiplayerGameMode(name, description, ini_name, ini_file, false, value)
{
    CampaignList = new CoopCampaignListClass;
    Current = NULL;
    Field48 = 0;
    CampaignIndex = 0;
    Score = NULL;
    Field04 = false;
    Field4C = false;
    SaveListed = false;
    Field50 = 0;
    NeedsRefresh = true;
    Init();
}

MPCooperative::~MPCooperative()
{
    if (CampaignList) {
        delete CampaignList;
        CampaignList = NULL;
    }
    if (Current) {
        delete Current;
        Current = NULL;
    }
    for (int index = Campaigns.Count() - 1; index >= 0; index--) {
        delete Campaigns[index];
    }
    Campaigns.Clear();
    for (index = Names.Count() - 1; index >= 0; index--) {
        delete Names[index];
    }
    int length = Names.Length();
    Names.Clear();
    Names.Resize(length);
    if (Score) {
        delete Score;
        Score = NULL;
    }
    Field04 = false;
}

bool MPCooperative::Is_Valid_House(int house)
{
    if (CampaignList == NULL) {
        return true;
    }
    CoopCampaignType * campaign;
    CampaignList->Get_Campaign(CampaignIndex, &campaign);
    if (campaign == NULL) {
        return true;
    }
    bool valid = false;
    if (house == -2 && campaign->Players.Count() > 1) {
        return true;
    }
    for (int index = 0; index < campaign->Players.Count(); index++) {
        if (Coop_House_From_Name(campaign->Players[index]) == house) {
            valid = true;
            break;
        }
    }
    return valid;
}

bool MPCooperative::Init()
{
    for (int index = Campaigns.Count() - 1; index >= 0; index--) {
        delete Campaigns[index];
    }
    int length = Campaigns.Length();
    Campaigns.Clear();
    Campaigns.Resize(length);
    int count;
    CampaignList->Get_Count(&count);
    for (index = 0; index < count; index++) {
        CoopCampaignClass * campaign = new CoopCampaignClass;
        campaign->Start(index);
        Campaigns.Add(campaign);
    }
    return true;
}

inline bool Is_Same_Map(char const * filename, char const * name)
{
    return _strnicmp(filename, name, strlen(name)) == 0;
}

// 0x19fbe0: the campaign whose map list contains the selected scenario, or -1.
int MPCooperative::Find_Scenario()
{
    if (CampaignList == NULL) {
        return -1;
    }
    int found = -1;
    for (int index = 0; index < CampaignList->Count; index++) {
        CoopCampaignType * campaign;
        CampaignList->Get_Campaign(index, &campaign);
        for (int map = 0; map < 3; map++) {
            if (Session.ScenarioIdx) {
                char const * filename = Session.Scenarios[Session.ScenarioIdx]->FileName;
                if (_strnicmp(filename, campaign->Maps[map], strlen(campaign->Maps[map])) == 0) {
                    found = index;
                }
            }
        }
    }
    return found;
}

#line 300 "C:\\RA2\\MPCoop.cpp"
void MPCooperative::Slot08()
{
    int description;
    if (CampaignList == NULL) {
        return;
    }
    if (Find_Dialog(0xc2) || Find_Dialog(0xbc)) {
        if (Current) {
            int campaign;
            Current->Get_Campaign_Type(&campaign);
            if (Find_Scenario() != campaign) {
                delete Current;
                Current = NULL;
            }
        }
        if (Current) {
            if (Session.Players.Count() == 2) {
                Current->Set_Players(Session.Players[0]->Name, Session.Players[1]->Name);
            } else {
                Current->Set_Players(NullWString, NullWString);
            }
        }
    }
    if (Current == NULL) {
        Current = new CoopCampaignClass;
        if (Current == NULL) {
            return;
        }
        Current->Start(0);
        int index = Find_Scenario();
        if (index < 0) {
            char * name;
            CampaignIndex = 0;
            name = NULL;
            Current->Get_Map(&name, 0);
            for (int scenario = 0; scenario < Session.Scenarios.Count(); scenario++) {
                char const * filename = Session.Scenarios[scenario]->FileName;
                if (_strnicmp(filename, name, strlen(name)) == 0) {
                    Session.ScenarioIdx = scenario;
                    Set_Scenario(scenario);
                    break;
                }
            }
            if (scenario == Session.Scenarios.Count()) {
                Session.ScenarioIdx = 0;
                Set_Scenario(0);
            }
        } else {
            CoopCampaignType * campaign;
            char * name;
            CampaignIndex = index;
            CampaignList->Get_Campaign(index, &campaign);
            name = NULL;
            Current->Get_Map(&name, 0);
            Debug_Printf("@@@ Looking for %s", Session.Scenarios[Session.ScenarioIdx]->FileName);
            while (!Is_Same_Map(Session.Scenarios[Session.ScenarioIdx]->FileName, name)) {
                Current->Start(index == 0);
                Current->Start(index);
                Current->Get_Map(&name, 0);
            }
        }
    }
    NeedsRefresh = true;
    HWND dialog = Get_Coop_Dialog();
    if (dialog) {
        HWND item = GetDlgItem(dialog, 0x72f);
        if (item && Current) {
            if (Current->Get_Campaign_Type(&description)) {
                char buffer[64];
                sprintf(buffer, "NAME:COOPDESC%d", description + 1);
#line 329
                SendMessageA(item, 0x4b2, 0, (LPARAM)Fetch_String(buffer, NULL, __FILE__, __LINE__));
                ShowWindow(item, SW_SHOW);
            }
        }
    }
}

void MPCooperative::Request_Refresh()
{
    NeedsRefresh = true;
}

int MPCooperative::Slot13()
{
    int count = 0;
    char * name = NULL;
    if (CampaignList == NULL) {
        CampaignList = new CoopCampaignListClass;
    }
    CampaignList->Get_Count(&count);
    if (count) {
        if (Current == NULL) {
            Current = new CoopCampaignClass;
        }
        Current->Start(0);
        Current->Get_Map(&name, 0);
        for (int index = 0; index < Session.Scenarios.Count(); index++) {
            char const * filename = Session.Scenarios[index]->FileName;
            if (_strnicmp(filename, name, strlen(name)) == 0) {
                return index;
            }
        }
        Init();
    }
    return -1;
}

bool MPCooperative::Slot05(int value)
{
    if (Session.Players.Count() == 2 && Current) {
        Current->Set_Players(Session.Players[0]->Name, Session.Players[1]->Name);
    }
    return MultiplayerGameMode::Slot05(value);
}

bool MPCooperative::Slot06()
{
    if (CampaignList == NULL || Current == NULL) {
        return false;
    }
    int count;
    CampaignList->Get_Count(&count);
    int index = Coop_Selected_Campaign();
    if (index >= count) {
        if (Session.Players.Count() == 2) {
            Current->Set_Players(Session.Players[0]->Name, Session.Players[1]->Name);
        }
        if (!Current->Load()) {
            return false;
        }
        Field4C = true;
    } else if (Current_Dialog_ID() == 0x6b) {
        delete Current;
        Current = Campaigns[index];
        Campaigns[index] = new CoopCampaignClass;
        Campaigns[index]->Start(index);
        Field50 = index;
        if (Session.Players.Count() == 2) {
            Current->Set_Players(Session.Players[0]->Name, Session.Players[1]->Name);
        }
    }
    CoopCampaignType * campaign;
    CampaignList->Get_Campaign(CampaignIndex, &campaign);
    if (campaign == NULL) {
        return false;
    }
    int sides = campaign->Players.Count();
    if (sides == 0) {
        return false;
    }
    Update_Dialog(Get_Coop_Dialog());
    for (int player = 0; player < Session.Players.Count(); player++) {
        if (!Is_Valid_House(Session.Players[player]->Side())) {
            Session.Players[player]->Set_Side(sides > 1 ? -2 : Coop_House_From_Name(campaign->Players[0]));
        }
    }
    return true;
}

int MPCooperative::Slot10()
{
    CoopCampaignType * campaign;
    CampaignList->Get_Campaign(CampaignIndex, &campaign);
    if (campaign == NULL) {
        return -2;
    }
    int count = campaign->Players.Count();
    if (count == 0) {
        return -2;
    }
    if (count > 1) {
        return -2;
    }
    return Coop_House_From_Name(campaign->Players[0]);
}

bool MPCooperative::Slot18(int campaign, DynamicVectorClass<int> picks, char const * name2, char const * name1)
{
    if (Current == NULL) {
        New_Campaign();
        NeedsRefresh = true;
    }
    if (Current && CampaignList) {
        int current;
        Current->Get_Campaign_Type(&current);
        if (current != campaign) {
            NeedsRefresh = true;
        }
        Current->Setup(CampaignList, campaign, picks, name2, name1);
        CampaignIndex = campaign;
        return true;
    }
    return false;
}

bool MPCooperative::Slot19(int map, int time, MPlayerScoreType * scores)
{
    if (Current == NULL) {
        return false;
    }
    HWND dialog = Get_Coop_Dialog();
    if (dialog && NeedsRefresh) {
        Update_Dialog(dialog);
        NeedsRefresh = false;
    }
    return Current->Set_Progress(map, time, scores[0], scores[1]);
}

// 0x1a03a0: fills one side combo box with the sides the campaign allows.
#line 520
void MPCooperative::Fill_Side_List(HWND dialog, int id)
{
    HWND item = GetDlgItem(dialog, id);
    ShowWindow(item, SW_HIDE);
    SendMessageA(item, CB_RESETCONTENT, 0, 0);
    CoopCampaignType * campaign;
    CampaignList->Get_Campaign(CampaignIndex, &campaign);
    if (campaign == NULL) {
        return;
    }
    int count = campaign->Players.Count();
    if (count == 0) {
        return;
    }
    if (count > 1) {
#line 527
        LRESULT index = SendMessageA(item, 0x4c2, 0, (LPARAM)Fetch_String("GUI:Random", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_SETITEMDATA, index, -2);
    }
    for (int side = 0; side < count; side++) {
        int house = Coop_House_From_Name(campaign->Players[side]);
        LRESULT index = SendMessageA(item, 0x4c2, 0, (LPARAM)HouseTypes[house]->Full_Name());
        SendMessageA(item, CB_SETITEMDATA, index, house);
    }
    SendMessageA(item, CB_SETCURSEL, 0, 0);
    ShowWindow(item, SW_SHOW);
}

// 0x1a0490
void MPCooperative::Update_Dialog(HWND dialog)
{
    if (dialog == NULL) {
        return;
    }
    int slots = Session.Field884;
    CoopCampaignType * campaign;
    CampaignList->Get_Campaign(CampaignIndex, &campaign);
    if (campaign == NULL) {
        return;
    }
    int count = campaign->Players.Count();
    if (count == 0) {
        return;
    }
    for (int slot = 0; slot < slots; slot++) {
        int id = Player_Side_ID(slot);
        Fill_Side_List(dialog, id);
        if (count > 1) {
            Select_Side(dialog, id, -2);
            Session.Slots[slot]->Set_Side(-2);
        } else {
            int house = Coop_House_From_Name(campaign->Players[0]);
            Select_Side(dialog, id, house);
            Session.Slots[slot]->Set_Side(house);
        }
    }
    Update_Player_Slots(dialog, slots);
    HWND coop = Get_Coop_Dialog();
    int index;
    if (coop && Current) {
        if (Current->Get_Campaign_Type(&index)) {
            char buffer[64];
            sprintf(buffer, "NAME:COOPDESC%d", index + 1);
            HWND item = GetDlgItem(coop, 0x72f);
            if (item) {
#line 605
                SendMessageA(item, 0x4b2, 0, (LPARAM)Fetch_String(buffer, NULL, __FILE__, __LINE__));
                ShowWindow(item, SW_SHOW);
                InvalidateRect(item, NULL, FALSE);
            }
        }
    }
}

bool MPCooperative::Slot20()
{
    if (Current == NULL) {
        return false;
    }
    Current->Get_Campaign_Type(&CampaignIndex);
    HWND dialog = Get_Coop_Dialog();
    if (dialog && NeedsRefresh) {
        Update_Dialog(dialog);
        NeedsRefresh = false;
    }
    return Current->Send(CampaignList);
}

static int PlayerColors[8];         // 0xa58d30

// 0x1a0650
void Init_Coop_Player_Colors()
{
    for (int index = 0; index < 8; index++) {
        PlayerColors[index] = -2;
    }
    int count = Session.Players.Count();
    for (index = 0; index < count; index++) {
        PlayerColors[index] = Session.Players[index]->Get_Color();
    }
}

// 0x1a0690: sends the AI houses and colours of every campaign mission.
bool MPCooperative::Slot21()
{
    CoopCampaignType * campaign;
    char buffer[400];
    CampaignList->Get_Campaign(CampaignIndex, &campaign);
    sprintf(buffer, "C1,%d", campaign->MapCount);
    for (int slot = 0; slot < 8; slot++) {
        int length = Lists1[slot].Length();
        Lists1[slot].Clear();
        Lists1[slot].Resize(length);
        length = Lists2[slot].Length();
        Lists2[slot].Clear();
        Lists2[slot].Resize(length);
    }
    int players = Session.Players.Count();
    for (int mission = 0; mission < campaign->MapCount; mission++) {
        Init_Coop_Player_Colors();
        for (slot = 0; slot < 8; slot++) {
            if (slot < players) {
                Lists1[slot].Add(Slot23());
                Lists2[slot].Add(PlayerColors[slot]);
            } else {
                Lists1[slot].Add(Slot24());
                int color;
                bool used;
                do {
                    color = Scen->RandomNumber(0, 7);
                    used = false;
                    if (color != -2) {
                        for (int index = 0; index < 8; index++) {
                            if (PlayerColors[index] == color) {
                                used = true;
                                break;
                            }
                        }
                    }
                } while (used);
                PlayerColors[slot] = color;
                Lists2[slot].Add(color);
            }
            char text[16];
            sprintf(text, ",%d,%d", Lists1[slot][mission], Lists2[slot][mission]);
            strcat(buffer, text);
        }
    }
    Debug_Printf("@@@@ Sending campaign game AI settings: %s\n", buffer);
    Send_Campaign_Settings(buffer);
    Debug_Printf("@@@@ Sent\n");
    return true;
}

// 0x1a09d0: receives the AI houses and colours sent by Slot21.
void MPCooperative::Slot25(int type, char * text)
{
    if (type == 1) {
        int count = (int)atol(strtok(text, ","));
        for (int slot = 0; slot < 8; slot++) {
            int length = Lists1[slot].Length();
            Lists1[slot].Clear();
            Lists1[slot].Resize(length);
            length = Lists2[slot].Length();
            Lists2[slot].Clear();
            Lists2[slot].Resize(length);
        }
        for (int mission = 0; mission < count; mission++) {
            for (slot = 0; slot < 8; slot++) {
                char * token = strtok(NULL, ",");
                if (token) {
                    Lists1[slot].Add((int)atol(token));
                } else {
                    Lists1[slot].Add(-1);
                }
                token = strtok(NULL, ",");
                if (token) {
                    Lists2[slot].Add((int)atol(token));
                } else {
                    Lists2[slot].Add(-1);
                }
            }
        }
    }
}

#line 770
bool MPCooperative::Slot26()
{
    HWND dialog = Get_Coop_Dialog();
    if (dialog && Current) {
        int index;
        if (Current->Get_Campaign_Type(&index)) {
            char buffer[64];
            sprintf(buffer, "NAME:COOPDESC%d", index + 1);
            HWND item = GetDlgItem(dialog, 0x72f);
            if (item) {
#line 776
                SendMessageA(item, 0x4b2, 0, (LPARAM)Fetch_String(buffer, NULL, __FILE__, __LINE__));
                ShowWindow(item, SW_SHOW);
            }
        }
    }
    return true;
}

void MPCooperative::Slot16(int a, int b)
{
    MultiplayerGameMode::Slot16(a, b);
}

inline double Distance(double x, double y)
{
    return Square_Root(x * x + y * y);
}

// 0x1a0cc0: picks a free start waypoint; the first one at random, then the ones farthest
// from the waypoints already taken.
Cell MPCooperative::Pick_Start_Cell(int house, DynamicVectorClass<Cell> & cells, bool * used)
{
    int taken = 0;
    for (int index = 0; index < cells.Count(); index++) {
        if (used[index]) {
            taken++;
        }
    }
    int bestindex;
    if (taken == 0) {
        bestindex = Scen->RandomNumber(0, cells.Count() - 1);
    } else {
        int nearest = -1;
        int nearestindex = -1;
        if (taken == 1) {
            for (int cell = 0; cell < cells.Count(); cell++) {
                if (!used[cell]) {
                    int total = 0;
                    for (int other = 0; other < cells.Count(); other++) {
                        if (used[other]) {
                            Cell diff = cells[cell] - cells[other];
                            total += (short)Distance(diff.X, diff.Y);
                        }
                    }
                    if (total < nearest || nearest < 0) {
                        nearest = total;
                        nearestindex = cell;
                    }
                }
            }
            used[nearestindex] = true;
            return cells[nearestindex];
        }
        int best = -1;
        bestindex = -1;
        for (int cell = 0; cell < cells.Count(); cell++) {
            if (!used[cell]) {
                int total = 0;
                for (int other = 0; other < cells.Count(); other++) {
                    if (used[other]) {
                        Cell diff = cells[cell] - cells[other];
                        total += (short)Distance(diff.X, diff.Y);
                    }
                }
                if (total > best) {
                    best = total;
                    bestindex = cell;
                }
            }
        }
    }
    used[bestindex] = true;
    return cells[bestindex];
}

bool MPCooperative::Slot27(bool flag)
{
    DynamicVectorClass<Cell> cells = Get_Start_Cells(flag);
    bool used[16];
    memset(used, 0, sizeof(used));
    for (int index = 0; index < Houses.Count(); index++) {
        HouseClass * house = Houses[index];
        if (!house->Class->IsMultiplayPassive) {
            Debug_Printf("Assigning Starting Points for house %d (%s)\n", index, house->Class->ID);
            Cell cell = Pick_Start_Cell(index, cells, used);
            house->StartCoord = CoordStruct(cell.X * 256 + 128, cell.Y * 256 + 128, 0);
        }
    }
    return true;
}

bool MPCooperative::Slot22()
{
    int ai = Scenario_Max_Players(Session.ScenarioIdx) - 2;
    Debug_Printf("@@@@ Adding %d AI players\n", ai);
    if (ai <= 0) {
        return false;
    }
    Session.AIPlayers = ai;
    int added = 0;
    CoopCampaignType * campaign;
    CampaignList->Get_Campaign(CampaignIndex, &campaign);
    if (campaign == NULL) {
        return false;
    }
    if (campaign->Enemies.Count() == 0) {
        return false;
    }
    for (int slot = 2; slot < 8; slot++) {
        if (added < ai) {
            Debug_Printf("@@@@ Setting slot %d for AI\n", slot);
            if (strcmp(campaign->AI, "Normal") == 0) {
                Session.AIDifficulties[slot] = 1;
            } else if (strcmp(campaign->AI, "Hard") == 0) {
                Session.AIDifficulties[slot] = 0;
            } else {
                Session.AIDifficulties[slot] = 2;
            }
            Debug_Printf("@@@@     AI difficulty: %d\n", Session.AIDifficulties[slot]);
            Session.AIHouses[slot] = -2;
            Session.AIColors[slot] = -2;
            added++;
        } else {
            Session.AIDifficulties[slot] = -1;
            Session.AIHouses[slot] = -1;
            Session.AIColors[slot] = -1;
        }
    }
    return true;
}

// 0x1a10f0: makes all human houses allies of each other.
bool MPCooperative::Slot28()
{
    Debug_Printf("@@@@ Making Alliances\n");
    for (int index = 0; index < Houses.Count(); index++) {
        HouseClass * house1 = Houses[index];
        Debug_Printf("@@@@     House1 = %s\n", Wide_To_Ascii(house1->IniName));
        if (!house1->Class->IsMultiplayPassive && house1->IsHuman) {
            for (int other = index + 1; other < Houses.Count(); other++) {
                HouseClass * house2 = Houses[other];
                Debug_Printf("@@@@         House2 = %s\n", Wide_To_Ascii(house2->IniName));
                if (!house2->Class->IsMultiplayPassive && house2->IsHuman) {
                    Debug_Printf("@@@@ Making Allies of %s(%d/%d/%d) and %s(%d/%d/%d)\n",
                        Wide_To_Ascii(house1->IniName), house1->Class->FieldB8, house1->Class->FieldBC, house1->Class->FieldC0,
                        Wide_To_Ascii(house2->IniName), house2->Class->FieldB8, house2->Class->FieldBC, house2->Class->FieldC0);
                    house1->Make_Ally(house2, false);
                    house2->Make_Ally(house1, false);
                }
            }
        }
    }
    return true;
}

// 0x1a1260: a random house among the campaign's player sides.
int MPCooperative::Slot23()
{
    int count = HouseTypes.Count();
    bool found = false;
    int index = 0;
    CoopCampaignType * campaign;
    Current->Get_Campaign_Type(&index);
    CampaignList->Get_Campaign(index, &campaign);
    int house;
    do {
        house = Scen->RandomNumber(0, count - 1);
        for (int side = 0; side < campaign->Players.Count(); side++) {
            if (house == Coop_House_From_Name(campaign->Players[side])) {
                found = true;
            }
        }
    } while (!found);
    Debug_Printf("@@@@ Choosing a random player house: %d(%s)\n", house, Wide_To_Ascii(HouseTypes[house]->UIName));
    return house;
}

// 0x1a1310: a random house among the campaign's AI sides.
int MPCooperative::Slot24()
{
    int count = HouseTypes.Count();
    bool found = false;
    int index = 0;
    CoopCampaignType * campaign;
    Current->Get_Campaign_Type(&index);
    CampaignList->Get_Campaign(index, &campaign);
    int house;
    do {
        house = Scen->RandomNumber(0, count - 1);
        for (int side = 0; side < campaign->Enemies.Count(); side++) {
            if (house == Coop_House_From_Name(campaign->Enemies[side])) {
                found = true;
            }
        }
    } while (!found);
    Debug_Printf("@@@@ Choosing a random AI house: %d(%s)\n", house, Wide_To_Ascii(HouseTypes[house]->UIName));
    return house;
}

bool MPCooperative::Reveal_Map()
{
    return MultiplayerGameMode::Reveal_Map();
}

bool MPCooperative::Slot11()
{
    return false;
}

// 0x1a13e0: end of a campaign mission: saves the campaign and remembers the game settings.
#line 1040
void MPCooperative::Slot34(bool won)
{
    bool alive = false;
    for (int index = 0; index < Houses.Count(); index++) {
        if (Houses[index] && Houses[index]->Is_Human() && !Houses[index]->IsDefeated) {
            alive = true;
        }
    }
    Debug_Printf("@@@@ End-of-Game: PlayerWins:%d, win:%d\n", won, alive);
    if (alive) {
        int color = Message_Color();
        if (Current) {
            Current->Next_Map();
            if (Current->Save()) {
#line 1048
                SessionMessages.Add_Message(NULL, 0, Fetch_String("TXT_COOP_SAVE_SUCCESS", NULL, __FILE__, __LINE__), color, 0x16, Rule->MessageDelay * 900.0, false);
            } else {
#line 1050
                SessionMessages.Add_Message(NULL, 0, Fetch_String("TXT_COOP_SAVE_FAILED", NULL, __FILE__, __LINE__), color, 0x16, Rule->MessageDelay * 900.0, false);
            }
        }
    }
    wcscpy(PlayerName, Session.Handle);
    Scen->Field2232 = true;
    Scen->Field2230 = false;
    Scen->Field2234 = true;
    Scen->Field2233 = false;
    Delete_All(Names);
    LocalPlayer = 0;
    for (index = 0; index < Session.Players.Count(); index++) {
        NodeNameType * node = new NodeNameType;
        wcscpy(node->Name, Session.Players[index]->Name);
        node->Field69 = Session.Players[index]->Field69;
        node->House = Session.Players[index]->House;
        node->Color = Session.Players[index]->Color;
        node->HouseIndex = Session.Players[index]->HouseIndex;
        strcpy(node->Handle, Session.Players[index]->Handle);
        node->Field4D = Session.Players[index]->Field4D;
        node->Field55 = Session.Players[index]->Field55;
        node->Team = Session.Players[index]->Team;
        node->Field61 = Session.Players[index]->Field61;
        node->Field65 = Session.Players[index]->Field65;
        node->Field69 = Session.Players[index]->Field69;
        node->Address = Session.Players[index]->Address;
        Names.Add(node);
        if (Session.MyAddress == Session.Players[index]->Address) {
            LocalPlayer = index;
        }
    }
    SavedHouse = Session.House;
    SavedField33B4 = Session.Field33B4;
    SavedTechLevel = TechLevel;
    SavedUnitCount = Session.UnitCount;
    SavedCredits = Session.Credits;
    SavedFogOfWar = Session.FogOfWar;
    SavedBridgeDestruction = Session.BridgeDestruction;
    SavedCrates = Session.Crates;
    SavedMCVRedeploy = Session.MCVRedeploy;
    SavedFlag0A4 = Session.Flag0A4;
    SavedHarvesterTruce = Session.HarvesterTruce;
    SavedBases = Session.Bases;
    SavedFlag0A6 = Session.Flag0A6;
    SavedAIPlayers = Session.AIPlayers;
    SavedAIDifficulty = Session.AIDifficulty;
    SavedShortGame = Session.ShortGame;
    SavedSuperWeapons = Session.SuperWeapons;
    SavedBuildOffAlly = Session.BuildOffAlly;
    SavedCrapEngineers = Session.CrapEngineers;
    SavedGameSpeed = Session.GameSpeed;
    Session.Field2B0 = 0;
    Map.Func_498CF0(0);
    Map.Field11A0 = 0;
    Map.Field11A4 = 0;
    Map.Field11A8 = -1;
    for (int record = 0; record < 4; record++) {
        ScoreData.Records[record].Kills[ScoreData.Game] = -1;
    }
}

// 0x1a1bc0
// 0x1a1810: fills the scenario list box with the first map of every campaign and a saved game.
#line 1230
void MPCooperative::Fill_Scenario_List(HWND list, DynamicVectorClass<MultiMission *> & scenarios, int unused)
{
    Field04 = true;
    if (Score == NULL) {
        Score = new CoopScoreClass;
    }
    SendMessageA(list, LB_RESETCONTENT, 0, 0);
    SaveListed = false;
    if (Current == NULL) {
        if (Session.Players.Count() == 2) {
            Current = new CoopCampaignClass(Session.Players[0]->Name, Session.Players[1]->Name);
        }
    } else if (Session.Players.Count() != 2) {
        Current->Set_Players(NullWString, NullWString);
    }
    if (Campaigns.Count() == 0) {
        int count;
        CampaignList->Get_Count(&count);
        for (int index = 0; index < count; index++) {
            CoopCampaignClass * campaign = new CoopCampaignClass;
            campaign->Start(index);
            Campaigns.Add(campaign);
        }
    }
    DynamicVectorClass<wchar_t *> names;
    CampaignList->Get_Names(names);
    int count = names.Count();
    for (int index = 0; index < count; index++) {
        if (names[index]) {
            char * mapname;
            Campaigns[index]->Get_Map(&mapname, -1);
            char filename[260];
            int scenariocount = scenarios.Count();
            MultiMission * found = NULL;
            sprintf(filename, "%s.MAP", mapname);
            for (int scenario = 0; scenario < scenariocount; scenario++) {
                if (found) {
                    break;
                }
                MultiMission * mission = scenarios[scenario];
                if (_stricmp(mission->FileName, filename) == 0) {
                    found = scenarios[scenario];
                }
            }
            if (found) {
                wchar_t text[252];
                swprintf(text, L"%d. %s", index + 1, names[index]);
                SendMessageA(list, 0x4cd, 0, (LPARAM)text);
                SendMessageA(list, LB_SETITEMDATA, index, (LPARAM)found);
            } else {
                Debug_Printf("@@@@ Could not find %s for %s\n", filename, names[index]);
            }
            delete names[index];
        }
    }
    if (Current && Current->Is_Saved() && !SaveListed) {
        char filename[260];
        Current->Is_Finished(filename);
        strcat(filename, ".MAP");
        int scenariocount = scenarios.Count();
        MultiMission * found = NULL;
        for (int scenario = 0; scenario < scenariocount; scenario++) {
            if (found) {
                break;
            }
            MultiMission * mission = scenarios[scenario];
            if (_stricmp(mission->FileName, filename) == 0) {
                found = scenarios[scenario];
            }
        }
        if (found) {
#line 1281
            SendMessageA(list, 0x4cd, 0, (LPARAM)Fetch_String("TXT_COOP_USE_SAVE", NULL, __FILE__, __LINE__));
            SendMessageA(list, LB_SETITEMDATA, index, (LPARAM)found);
            SaveListed = true;
        }
    }
    SendMessageA(list, LB_SETCURSEL, 0, 0);
}

// Not inlined into Slot18 in the original although VC6 would auto-inline it here; the pragma
// reproduces that decision (cause unknown, see the claims file).
#pragma auto_inline(off)
bool MPCooperative::New_Campaign()
{
    delete Current;
    Current = NULL;
    Current = new CoopCampaignClass;
    Current->Start(0);
    if (Session.Players.Count() == 2) {
        Current->Set_Players(Session.Players[0]->Name, Session.Players[1]->Name);
    }
    return Current ? true : false;
}
#pragma auto_inline(on)

void MPCooperative::Slot33()
{
    HWND dialog = Get_Coop_Dialog();
    if (dialog) {
        HWND item = GetDlgItem(dialog, 0x72f);
        if (item) {
            SendMessageA(item, 0x4b2, 0, (LPARAM)NullWString);
            ShowWindow(item, SW_HIDE);
        }
        Fill_All_Side_Lists(dialog);
    }
    for (int index = 0; index < Session.Players.Count(); index++) {
        Session.Players[index]->Team = index;
    }
}

// 0x1a1ca0
void MPCooperative::Slot30()
{
    if (Current_Dialog_ID() == 0x6b) {
        if (SaveListed) {
            HWND list = GetDlgItem(Current_Dialog(), 0x553);
            int count = SendMessageA(list, LB_GETCOUNT, 0, 0);
            if (count == -1) {
                if (Current) {
                    Current->Set_Players(NullWString, NullWString);
                }
                return;
            }
            if (SendMessageA(list, LB_GETCURSEL, 0, 0) == count - 1) {
                SendMessageA(list, LB_SETCURSEL, count - 2, 0);
            }
            SendMessageA(list, LB_DELETESTRING, count - 1, 0);
            SaveListed = false;
        }
    } else {
        if (Current && Field4C) {
            if (Field50) {
                Current->Start(0);
                Current->Start(Field50);
            } else {
                Current->Start(1);
                Current->Start(Field50);
            }
            char * name;
            Current->Get_Map(&name, -1);
            char filename[260];
            int count = Session.Scenarios.Count();
            sprintf(filename, "%s.MAP", name);
            for (int index = 0; index < count; index++) {
                MultiMission * scenario = Session.Scenarios[index];
                if (_stricmp(scenario->FileName, filename) == 0) {
                    break;
                }
            }
            Session.ScenarioIdx = index;
            Scen->ScenarioIndex = index;
            Set_Scenario(index);
        }
        HWND dialog = Get_Coop_Dialog();
        if (dialog) {
            Coop_Dialog_Func_5BDF90(dialog, this);
            Coop_Dialog_Func_5BDFF0(dialog);
            Coop_Dialog_Func_5C15D0(dialog);
        }
        Coop_Func_5BE350(true, true);
    }
    if (Current) {
        Current->Set_Players(NullWString, NullWString);
    }
}

// 0x1a1e30: offers a saved campaign game in the scenario list.
#line 1440
void MPCooperative::Slot31()
{
    if (Current == NULL) {
        Current = new CoopCampaignClass;
        Current->Start(0);
    }
    if (Current == NULL) {
        return;
    }
    if (Session.Players.Count() == 2) {
        Current->Set_Players(Session.Players[0]->Name, Session.Players[1]->Name);
    }
    Slot20();
    if (!Current->Is_Saved()) {
        return;
    }
    if (Current_Dialog_ID() == 0x6b) {
        if (SaveListed) {
            return;
        }
        char filename[260];
        Current->Is_Finished(filename);
        strcat(filename, ".MAP");
        MultiMission * found = NULL;
        int count = Session.Scenarios.Count();
        for (int index = 0; index < count; index++) {
            if (found) {
                break;
            }
            MultiMission * scenario = Session.Scenarios[index];
            if (_stricmp(scenario->FileName, filename) == 0) {
                found = Session.Scenarios[index];
            }
        }
        if (found) {
            HWND list = GetDlgItem(Current_Dialog(), 0x553);
            int item = SendMessageA(list, LB_GETCOUNT, 0, 0);
            if (item != -1) {
#line 1466
                SendMessageA(list, 0x4cd, 0, (LPARAM)Fetch_String("TXT_COOP_USE_SAVE", NULL, __FILE__, __LINE__));
                SendMessageA(list, LB_SETITEMDATA, item, (LPARAM)found);
                SaveListed = true;
            }
        }
    } else {
#line 1472
        Coop_Message(-1, Fetch_String("TXT_SAVE_CAMP_AVAILABLE", NULL, __FILE__, __LINE__));
    }
}

int MPCooperative::Slot32()
{
    return 2;
}

// 0x1a1ff0: shows the score screen after a campaign mission.
bool MPCooperative::Slot36()
{
    if (Score == NULL) {
        Score = new CoopScoreClass;
    }
    if (Current == NULL) {
        return false;
    }
    if (CampaignList == NULL) {
        return false;
    }
    DynamicVectorClass<MPlayerScoreType *> scores;
    int count;
    Current->Get_Scores(scores, &count);
    int index;
    CoopCampaignType * campaign = NULL;
    if (!Current->Get_Campaign_Type(&index)) {
        index = -1;
    } else {
        CampaignList->Get_Campaign(index, &campaign);
    }
    int level = -1;
    if (index == 0 || index == 1) {
        level = 0;
    } else if (index == 2 || index == 3) {
        level = 1;
    } else if (index == 4) {
        level = 2;
    }
    int total;
    Current->Get_Map_Count(&total);
    int done;
    Current->Get_Current_Map(&done);
    if (campaign) {
        Score->Presentation(scores, Scen->ElapsedTimer.Value(), done < total, level, campaign->Name);
    } else {
        Score->Presentation(scores, Scen->ElapsedTimer.Value(), done < total, level, NullWString);
    }
    while (scores.Count()) {
        delete scores[0];
        scores[0] = NULL;
        scores.Delete(0);
    }
    bool result = CoopScoreFlag;
    CoopScoreFlag = false;
    return result;
}

// 0x1a2210: shows the final campaign screen.
void MPCooperative::Slot35(bool flag)
{
    if (Current == NULL) {
        return;
    }
    int total;
    Current->Get_Map_Count(&total);
    int done;
    Current->Get_Current_Map(&done);
    if (!flag) {
        return;
    }
    if (done < total) {
        return;
    }
    CoopFinalClass * final = new CoopFinalClass;
    if (final == NULL) {
        return;
    }
    DynamicVectorClass<MPlayerScoreType *> scores;
    int index;
    int count;
    Current->Get_Scores(scores, &count);
    CoopCampaignType * campaign = NULL;
    if (!Current->Get_Campaign_Type(&index)) {
        index = -1;
    } else {
        CampaignList->Get_Campaign(index, &campaign);
    }
    int level = -1;
    if (index == 0 || index == 1) {
        level = 0;
    } else if (index == 2 || index == 3) {
        level = 1;
    } else if (index == 4) {
        level = 2;
    }
    final->Presentation(scores, count, level, index + 1, campaign->Name);
    delete final;
    while (scores.Count()) {
        delete scores[0];
        scores[0] = NULL;
        scores.Delete(0);
    }
}

// 0x1a2c50: rebuilds the session player list from the saved player names.
void MPCooperative::Slot38()
{
    Delete_All(Session.Players);
    Session.NumPlayers = 0;
    for (int index = 0; index < Names.Count(); index++) {
        for (int house = 0; house < Houses.Count(); house++) {
            if (_wcsicmp(Houses[house]->IniName, Names[index]->Name) == 0) {
                Names[index]->HouseIndex = house;
                NodeNameType * node = new NodeNameType;
                wcscpy(node->Name, Names[index]->Name);
                node->Field69 = Names[index]->Field69;
                node->House = Names[index]->House;
                node->Color = Names[index]->Color;
                strcpy(node->Handle, Names[index]->Handle);
                node->Field4D = Names[index]->Field4D;
                node->Field55 = Names[index]->Field55;
                node->Team = Names[index]->Team;
                node->Field61 = Names[index]->Field61;
                node->Field65 = Names[index]->Field65;
                node->Field69 = Names[index]->Field69;
                unsigned char * buffer = new unsigned char[30];
                unsigned char network[4];
                unsigned char address[8];
                Names[index]->Address.Get_Address(network, address);
                node->Address.Set_Address(network, address);
                delete buffer;
                Session.Players.Add(node);
                Session.NumPlayers++;
                break;
            }
        }
    }
}

bool MPCooperative::Slot39(DynamicVectorClass<struct MPlayerScoreType *> scores, int * result)
{
    *result = 0;
    if (Current) {
        return true;
    }
    return false;
}

// Out of line in this TU (0x1a3980, 0x1a39d0, 0x1a3a20 are called by the constructors).
template<class T> VectorClass<T>::VectorClass(unsigned size, T const * array) :
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
