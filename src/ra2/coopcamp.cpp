// C:\RA2\coopcamp.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Cooperative campaign: the campaign definitions read from COOPCAMP.INI (CoopCampaignListClass)
// and the state of the running cooperative campaign (CoopCampaignClass, RTTI name, no vtable),
// saved per player pair in COOPSAVE.INI and sent to the partner as a "C0,..." option string.
// CoopCampaignClass comes from RTTI; all other names are provisional.
#include "GAMECONST.H"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>

// ---- local declarations (to be moved to headers by the integrator) ----

// VECTOR.H plus the two constructors this TU needs (GAME.EXE VectorClass<char *>::VectorClass
// 0x4911c0, out of line; DynamicVectorClass constructor inlined). The integrator should add the
// constructors to VECTOR.H and drop this copy; everything else is identical to VECTOR.H.
template<class T> class VectorClass {
public:
    VectorClass(unsigned size = 0, T const * array = 0);
    virtual ~VectorClass() { VectorClass<T>::Clear(); }
    virtual bool operator == (VectorClass<T> const & vector) const;
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr);
    virtual int ID(T const & object);
    virtual T Fetch(int index) const { return Vector[index]; }

    T & operator[](unsigned index) { return Vector[index]; }
    int Length() const { return VectorMax; }

    T * Vector;
    int VectorMax;
    bool IsInitialized;
    bool IsAllocated;
};

template<class T> VectorClass<T>::VectorClass(unsigned size, T const * array) :
    Vector(0),
    VectorMax(size),
    IsInitialized(true),
    IsAllocated(false)
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

// File class hierarchy (as in Restate.cpp; CCFileClass gets both constructors).
class FileClass {
public:
    virtual ~FileClass();
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
    char RawFileData[0x1C];             // +0x04, layout not reconstructed
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];            // +0x20, layout not reconstructed
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);
    ~Buffer();                          // 0x438290
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename); // 0x468b70
    CCFileClass();                      // 0x468bf0
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual void Close();               // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

#define WRITE 2

// Doubly linked list (RTTI: GenericNode vtable 0x785afc, GenericList vtable 0x785af4, List<T>).
// The GenericList constructor (0x490c60) is emitted out of line in this TU.
class GenericNode {
public:
    GenericNode() : NextNode(0), PrevNode(0) {}
    virtual ~GenericNode();

    void Link(GenericNode * node)
    {
        node->Unlink();
        node->NextNode = NextNode;
        node->PrevNode = this;
        if (NextNode) NextNode->PrevNode = node;
        NextNode = node;
    }
    void Unlink()
    {
        if (Is_Valid()) {
            PrevNode->NextNode = NextNode;
            NextNode->PrevNode = PrevNode;
            PrevNode = 0;
            NextNode = 0;
        }
    }
    bool Is_Valid() const { return this != NULL && NextNode != NULL && PrevNode != NULL; }

protected:
    GenericNode * NextNode;
    GenericNode * PrevNode;
};

class GenericList {
public:
    GenericList() { FirstNode.Link(&LastNode); }
    virtual ~GenericList();
protected:
    GenericNode FirstNode;
    GenericNode LastNode;
};

template<class T>
class List : public GenericList {
};

// Sorted index; only the constructor is used here (0x490ea0, out of line in this TU).
template<class T, class U>
class IndexClass {
public:
    IndexClass() : IndexTable(0), IndexCount(0), IndexSize(0), IsSorted(false), Archive(0) {}
    ~IndexClass();
private:
    struct NodeElement {
        T ID;
        U Data;
    };
    NodeElement * IndexTable;
    int IndexCount;
    int IndexSize;
    bool IsSorted;
    NodeElement const * Archive;
};

// INI database (see Restate.cpp, Options.CPP). Names provisional.
class INIClass {
public:
    struct INISection;
    struct INIEntry;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                // 0x50ad20
private:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

class CCINIClass : public INIClass {
public:
    CCINIClass() : IsDigestPresent(false) {}

    INISection * Find_Section(char const * section);                                        // 0x50be00
    bool Is_Present(char const * section) { return Find_Section(section) != NULL; }
    int Entry_Count(char const * section);                                                  // 0x50bf50
    char const * Get_Entry(char const * section, int index);                                // 0x50c250
    int Load(FileClass & file, bool withdigest, bool merge);                                // 0x4692d0
    int Save(FileClass & file, bool withdigest);                                            // 0x469510
    bool Clear(char const * section = NULL, char const * entry = NULL);                     // 0x50adf0
    int Get_Int(char const * section, char const * entry, int defvalue = 0);                // 0x50cc40
    bool Put_Int(char const * section, char const * entry, int number, int format = 0);     // 0x50cb30
    int Get_String(char const * section, char const * entry, char const * defvalue, char * buffer, int size);   // 0x50ddf0
    int Put_String(char const * section, char const * entry, char const * string);          // 0x50da40
    int Get_HousesType(char const * section, char const * entry, int defvalue);             // 0x46a620
    bool Put_HousesType(char const * section, char const * entry, int value);               // 0x46a6d0
private:
    bool IsDigestPresent;               // +0x38
    unsigned char Digest[20];           // +0x39
};

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
char * To_Narrow(wchar_t const * string);       // 0x6eedc0
void Debug_Printf(char const * format, ...);    // 0x4068f0 (empty in this build)
void Send_Campaign_Settings(char const * text); // 0x5be7a0 (see MPCoop.cpp)

// House build counters (see CampScor.cpp).
class UnitTrackerClass : public VectorClass<int> {
public:
    int Total() const;                  // 0x491b70
};

// RTTI .?AVHouseTypeClass@@; only the fields used here.
class HouseTypeClass {
public:
    char Unknown00[0x24];
    char ID[0x18];                      // +0x24 (AbstractTypeClass::ID)
    char Unknown3C[0x64 - 0x3C];
    char Name[0x30];                    // +0x64 (AbstractTypeClass::Name)
    char Unknown94[0x1A6 - 0x94];
    bool IsMultiplayPassive;            // +0x1a6
};
extern DynamicVectorClass<HouseTypeClass *> HouseTypes;    // 0xa1e038

// RTTI .?AVHouseClass@@; only the fields used here (see CampScor.cpp).
class HouseClass {
public:
    char Unknown0[0x34];
    HouseTypeClass * Class;             // +0x34
    char Unknown38[0x134 - 0x38];
    bool IsHuman;                       // +0x134 (provisional)
    char Unknown135[0x13d - 0x135];
    bool IsDefeated;                    // +0x13d
    char Unknown13E[0x5310 - 0x13e];
    int UnitsKilled[20];                // +0x5310
    int UnitsLost;                      // +0x5360
    int BuildingsKilled[20];            // +0x5364
    int BuildingsLost;                  // +0x53b4
    char Unknown53B8[0x5418 - 0x53b8];
    int Points;                         // +0x5418
    char Unknown541C[0x5460 - 0x541c];
    UnitTrackerClass Trackers5460[4];   // +0x5460..+0x5490
    char Unknown54A0[0x15f16 - 0x54a0];
    wchar_t IniName[21];                // +0x15f16
    int ColorSchemeIndex;               // +0x15f40
};
extern DynamicVectorClass<HouseClass *> Houses;   // 0xa1a5c8

// One score line, 0x70 bytes (same record as MPScore.cpp).
struct MPScoreRecord {
    wchar_t Name[20];                   // +0x00
    int Scheme;                         // +0x28
    int Wins;                           // +0x2c
    int Lost;                           // +0x30
    int Unknown34[3];
    int Kills;                          // +0x40
    int Unknown44[3];
    int Built;                          // +0x50
    int Unknown54[3];
    int Score;                          // +0x60
    int Unknown64[3];
};

// Scenario (see MPScore.cpp).
// level-2 1.001: Random2Class (operator() 0x62FE40, the scenario generator), not RandomClass (0x62FCC0); shown by the P9 link check.
class Random2Class {
public:
    int operator()(int minval, int maxval);     // 0x62fe40
};
class SystemTimerClass {
public:
    long operator()() const;                    // 0x68fad0
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
class ScenarioClass {
public:
    char Unknown0[0x218];
    Random2Class RandomNumber;                       // +0x218
    char Unknown219[0x614 - 0x219];
    TTimerClass<SystemTimerClass> ElapsedTimer;     // +0x614
};
extern ScenarioClass * Scen;                        // 0xa255c0

// Session player entry (see MPCoop.cpp, netdlg2.cpp).
struct NodeNameType {
    int Side() const;                   // 0x664e80
    int Color() const;                  // 0x664e90
};

// Session object (see MPCoop.cpp, Skirmish.cpp); only the members used here.
class SessionClass {
public:
    char Unknown0000[0x64];
    int AIHouses[8];                            // +0x0064 (0xa2562c), -1 = not an AI slot
    char Unknown0084[0x27E0 - 0x84];
    DynamicVectorClass<NodeNameType *> Players; // +0x27e0 (0xa27da8)
};
extern SessionClass Session;                    // 0xa255c8

// One campaign definition from COOPCAMP.INI, 0x44 bytes (MPCoop.cpp: CoopCampaignTypeClass).
struct CoopCampaignType {
    int ID;                                     // +0x00
    wchar_t * Name;                             // +0x04
    char MapCount;                              // +0x08
    char (* Maps)[0x104];                       // +0x0c, three alternatives per map
    DynamicVectorClass<char *> Players;         // +0x10, "CampaignPlayer" houses
    DynamicVectorClass<char *> Enemies;         // +0x28, "CampaignEnemy" houses
    char * AI;                                  // +0x40, "CampaignAI"
};

// The campaign definitions read from COOPCAMP.INI, 0x5c bytes.
class CoopCampaignListClass {
public:
    CoopCampaignListClass();
    ~CoopCampaignListClass();
    bool Get_Campaign(int index, CoopCampaignType ** campaign);
    bool Get_Count(int * count);
    bool Get_Names(VectorClass<wchar_t *> & names);

    CCINIClass INI;                             // +0x00
    CoopCampaignType * Campaigns;               // +0x50
    int Count;                                  // +0x54
    bool IsLoaded;                              // +0x58
};

// One of the two players of a cooperative campaign, 0x1c bytes.
struct CoopPlayerType {
    char Name[20];                              // +0x00, narrow player name
    int House;                                  // +0x14
    int Color;                                  // +0x18
};

// RTTI .?AVCoopCampaignClass@@ (no vtable), 0x70 bytes.
class CoopCampaignClass {
public:
    CoopCampaignClass();
    CoopCampaignClass(wchar_t const * name1, wchar_t const * name2);
    ~CoopCampaignClass();
    void Set_Players(wchar_t const * name1, wchar_t const * name2);
    bool Next_Map();
    bool Get_Campaign_Type(int * type);
    bool Get_Map_Count(int * count);
    bool Get_Current_Map(int * map);
    bool Get_Scores(DynamicVectorClass<MPScoreRecord *> & list, int * time);
    bool Clear_Saved();
    bool Load();
    bool Save();
    bool Start(int campaign);
    bool Set_Progress(int map, int time, MPScoreRecord score1, MPScoreRecord score2);
    bool Setup(CoopCampaignListClass * list, int campaign, DynamicVectorClass<int> picks, char const * name2, char const * name1);
    bool Get_Map(char ** map, int index);
    bool Get_Player1(int * house, int * color);
    bool Get_Player2(int * house, int * color);
    bool Is_Saved();
    bool Is_Finished(char * buffer);
    bool Send(CoopCampaignListClass * list);

    CoopPlayerType Players[2];                  // +0x00, +0x1c
    int CurrentMap;                             // +0x38
    char ** Maps;                               // +0x3c
    int MapCount;                               // +0x40
    int CampaignType;                           // +0x44
    int Kills[2];                               // +0x48
    int Built[2];                               // +0x50
    int Lost[2];                                // +0x58
    int Score[2];                               // +0x60
    int Time;                                   // +0x68
    bool IsActive;                              // +0x6c
};

char Hex_Digit(int value);
int Hex_Value(char digit);
char * Encode_Name(char const * string);
char * Decode_Name(char const * string);
void Fill_Coop_Score(MPScoreRecord * record, bool second);
int Coop_House_From_Name(char const * name);

// ---- end of local declarations ----

static char EncodeBuffer[1024];                 // 0x8394a0
static char DecodeBuffer[1024];                 // 0x8398a0
static char CampaignBuffer[128];                // 0x839cf8

static char const SaveFileName[] = "coopsave.ini";

// 0x48dc40
char Hex_Digit(int value)
{
    if (value >= 0 && value <= 15) {
        if (value < 10) {
            return (char)(value + '0');
        }
        return (char)(value + 'A' - 10);
    }
    return 0;
}

// 0x48dc60
int Hex_Value(char digit)
{
    if (digit <= '9' && digit >= '0') {
        return digit - '0';
    }
    if (digit <= 'f' && digit >= 'a') {
        return digit - 'a' + 10;
    }
    if (digit <= 'F' && digit >= 'A') {
        return digit - 'A' + 10;
    }
    return 0;
}

// 0x48dca0: every character that is not alphanumeric becomes "=XX".
char * Encode_Name(char const * string)
{
    int index = 0;
    for (; *string; string++) {
        if (index >= (int)sizeof(EncodeBuffer) - 3) break;
        if (!isalnum(*string)) {
            EncodeBuffer[index++] = '=';
            EncodeBuffer[index++] = Hex_Digit(*string >> 4);
            EncodeBuffer[index] = Hex_Digit(*string & 0x0F);
        } else {
            EncodeBuffer[index] = *string;
        }
        index++;
    }
    EncodeBuffer[index] = 0;
    return EncodeBuffer;
}

// 0x48dd50
char * Decode_Name(char const * string)
{
    char * ptr = DecodeBuffer;
    while (*string != '\0') {
        if (*string == '=') {
            if (string[1] == '\0') break;
            *ptr = (char)Hex_Value(string[1]);
            string++;
            if (string[1] != '\0') {
                *ptr <<= 4;
                *ptr |= (char)Hex_Value(string[1]);
                string++;
            }
        } else {
            *ptr = *string;
        }
        string++;
        ptr++;
    }
    *ptr = '\0';
    return DecodeBuffer;
}

// 0x48de20
CoopCampaignClass::CoopCampaignClass()
{
    Players[0].Name[0] = '\0';
    Players[1].Name[0] = '\0';
    Players[0].House = -2;
    Players[1].House = -2;
    Players[0].Color = -2;
    Players[1].Color = -2;
    Maps = NULL;
    CampaignType = -1;
    IsActive = false;
    MapCount = 0;
    CurrentMap = -1;
    Kills[0] = 0;
    Kills[1] = 0;
    Built[0] = 0;
    Built[1] = 0;
    Lost[0] = 0;
    Lost[1] = 0;
    Time = 0;
    Score[0] = 0;
    Score[1] = 0;
}

// 0x48de70
CoopCampaignClass::CoopCampaignClass(wchar_t const * name1, wchar_t const * name2)
{
    if (name1 != NULL) {
        strcpy(Players[0].Name, To_Narrow(name1));
    } else {
        Players[0].Name[0] = '\0';
    }
    if (name2 != NULL) {
        strcpy(Players[1].Name, To_Narrow(name2));
    } else {
        Players[1].Name[0] = '\0';
    }
    Players[0].House = -2;
    Players[1].House = -2;
    Players[0].Color = -2;
    Players[1].Color = -2;
    Maps = NULL;
    CampaignType = -1;
    CurrentMap = -1;
    IsActive = false;
    MapCount = 0;
    Kills[0] = 0;
    Kills[1] = 0;
    Built[0] = 0;
    Built[1] = 0;
    Lost[0] = 0;
    Lost[1] = 0;
    Time = 0;
    Score[0] = 0;
    Score[1] = 0;
}

// 0x48df30
CoopCampaignClass::~CoopCampaignClass()
{
    if (Maps != NULL) {
        for (int index = 0; index < MapCount; index++) {
            if (Maps[index] != NULL) {
                delete Maps[index];
            }
        }
        delete Maps;
    }
}

// 0x48df70
void CoopCampaignClass::Set_Players(wchar_t const * name1, wchar_t const * name2)
{
    if (name1 != NULL) {
        strcpy(Players[0].Name, To_Narrow(name1));
    } else {
        Players[0].Name[0] = '\0';
    }
    if (name2 != NULL) {
        strcpy(Players[1].Name, To_Narrow(name2));
    } else {
        Players[1].Name[0] = '\0';
    }
}

// 0x48dff0: the score line of the first (second == false) or second human house.
void Fill_Coop_Score(MPScoreRecord * record, bool second)
{
    int count = Houses.ActiveCount;
    for (int index = 0; index < count; index++) {
        HouseClass * house = Houses[index];
        if (house == NULL || house->Class->IsMultiplayPassive == true) continue;
        if (!house->IsHuman) continue;
        if (second) {
            second = false;
            continue;
        }

        record->Wins = 0;
        wcscpy(record->Name, house->IniName);
        record->Lost = 0;
        record->Kills = 0;
        record->Built = 0;
        record->Score = 0;
        record->Scheme = house->ColorSchemeIndex;
        if (!house->IsDefeated) {
            record->Wins += 1;
        }

        int kills = 0;
        int i;
        for (i = 0; i < 20; i++) {
            kills += house->UnitsKilled[i];
        }
        for (i = 0; i < count; i++) {
            kills += house->BuildingsKilled[i];
        }
        record->Kills = kills;
        record->Lost = house->UnitsLost + house->BuildingsLost;
        int total = house->Trackers5460[0].Total();
        total += house->Trackers5460[1].Total();
        total += house->Trackers5460[2].Total();
        total += house->Trackers5460[3].Total();
        record->Built = house->UnitsLost + house->BuildingsLost + total;
        if (house->Points > 0) {
            record->Score += house->Points;
        }
        Debug_Printf("@@@@ %s: %s\n Scheme: %d\n Lost = %d\n Kills = %d\n Built = %d\n Score = %d\n",
            To_Narrow(record->Name), record->Wins > 0 ? "Winner" : "Loser",
            record->Scheme, record->Lost, record->Kills, record->Built, record->Score);
        return;
    }
}

static void Format_Time(char * buffer, int seconds)
{
    if (buffer != NULL) {
        if (seconds / 3600 > 99) {
            seconds = 99 * 3600 + 59 * 60 + 59;
        }
        int hours = seconds / 3600;
        seconds -= hours * 3600;
        int minutes = seconds / 60;
        seconds -= minutes * 60;
        sprintf(buffer, "%02d:%02d:%02d", hours, minutes, seconds);
    }
}

// 0x48e140: add the scores of the finished map.
bool CoopCampaignClass::Next_Map()
{
    if (!IsActive) return false;

    Debug_Printf("@@@@ NextMap\n");
    MPScoreRecord score1;
    MPScoreRecord score2;
    Fill_Coop_Score(&score1, false);
    Fill_Coop_Score(&score2, true);

    if (strcmp(Players[0].Name, To_Narrow(score1.Name)) == 0) {
        Debug_Printf("@@@@ %s is local\n", To_Narrow(score1.Name));
        Kills[0] += score1.Kills;
        Kills[1] += score2.Kills;
        Built[0] += score1.Built;
        Built[1] += score2.Built;
        Lost[0] += score1.Lost;
        Lost[1] += score2.Lost;
        Score[0] += score1.Score;
        Score[1] += score2.Score;
    } else {
        Debug_Printf("@@@@ Assuming %s is local\n", To_Narrow(score2.Name));
        Kills[1] += score1.Kills;
        Kills[0] += score2.Kills;
        Built[1] += score1.Built;
        Built[0] += score2.Built;
        Lost[1] += score1.Lost;
        Lost[0] += score2.Lost;
        Score[1] += score1.Score;
        Score[0] += score2.Score;
    }

    char gametime[256];
    char totaltime[256];
    Format_Time(gametime, Scen->ElapsedTimer.Value() / 60);
    Time += Scen->ElapsedTimer.Value();
    Format_Time(totaltime, Time);
    Debug_Printf("@@@@ Game Time: %s, Total Time: %s\n", gametime, totaltime);
    CurrentMap++;
    return true;
}

// 0x48e490
bool CoopCampaignClass::Get_Campaign_Type(int * type)
{
    if (!IsActive) return false;
    *type = CampaignType;
    return true;
}

// 0x48e4b0
bool CoopCampaignClass::Get_Map_Count(int * count)
{
    if (!IsActive) return false;
    *count = MapCount;
    return true;
}

// 0x48e4d0
bool CoopCampaignClass::Get_Current_Map(int * map)
{
    if (!IsActive) return false;
    *map = CurrentMap;
    return true;
}

// 0x48e4f0: two new score lines with the campaign totals (local player first).
bool CoopCampaignClass::Get_Scores(DynamicVectorClass<MPScoreRecord *> & list, int * time)
{
    if (!IsActive) return false;

    while (list.Count() != 0) {
        delete list[0];
        list.Delete(0);
    }

    MPScoreRecord * score1 = new MPScoreRecord;
    Fill_Coop_Score(score1, false);
    MPScoreRecord * score2 = new MPScoreRecord;
    Fill_Coop_Score(score2, true);

    if (strcmp(Players[0].Name, To_Narrow(score1->Name)) != 0) {
        MPScoreRecord * temp = score1;
        score1 = score2;
        score2 = temp;
    }

    for (int index = 0; index < 2; index++) {
        MPScoreRecord * score = (index == 0) ? score1 : score2;
        score->Kills = Kills[index];
        score->Built = Built[index];
        score->Lost = Lost[index];
        score->Wins = CurrentMap;
        score->Score = Score[index];
        list.Add(score);
    }
    *time = Time;
    return true;
}

// 0x48e650: remove the saved state of this player pair.
bool CoopCampaignClass::Clear_Saved()
{
    if (Players[0].Name[0] != '\0' && Players[1].Name[0] != '\0') {
        char section[100];
        CCFileClass file(SaveFileName);
        CCINIClass ini;
        ini.Load(file, false, false);
        file.Close();

        strcpy(section, Encode_Name(Players[0].Name));
        strcat(section, Encode_Name(Players[1].Name));

        {
            CCFileClass wfile;
            wfile.Set_Name(SaveFileName);
            wfile.Open(WRITE);
            ini.Clear(section);
            ini.Save(wfile, false);
            wfile.Close();
        }
    }
    return true;
}

// 0x48e910: restore the saved state of this player pair.
bool CoopCampaignClass::Load()
{
    if (Players[0].Name[0] == '\0' || Players[1].Name[0] == '\0') return false;

    char section[100];
    strcpy(section, Encode_Name(Players[0].Name));
    strcat(section, Encode_Name(Players[1].Name));

    CCFileClass file(SaveFileName);
    CCINIClass ini;
    if (!ini.Load(file, false, false)) return false;

    CurrentMap = ini.Get_Int(section, "CurrentMap", 0);
    ini.Get_Int(section, "Score", 0);
    CampaignType = ini.Get_Int(section, "CampaignType", -1);
    Players[0].House = ini.Get_HousesType(section, "House1", -2);
    Players[0].Color = ini.Get_Int(section, "Color1", -2);
    Players[1].House = ini.Get_HousesType(section, "House2", -2);
    Players[1].Color = ini.Get_Int(section, "Color2", -2);
    Kills[0] = ini.Get_Int(section, "Kills1", 0);
    Kills[1] = ini.Get_Int(section, "Kills2", 0);
    Built[0] = ini.Get_Int(section, "Built1", 0);
    Built[1] = ini.Get_Int(section, "Built2", 0);
    Lost[0] = ini.Get_Int(section, "Lost1", 0);
    Lost[1] = ini.Get_Int(section, "Lost2", 0);
    Score[0] = ini.Get_Int(section, "Score1", 0);
    Score[1] = ini.Get_Int(section, "Score2", 0);
    Time = ini.Get_Int(section, "Time", 0);

    CoopCampaignListClass * list = new CoopCampaignListClass;
    if (CampaignType >= 0 && CampaignType < list->Count) {
        CoopCampaignType * campaign = &list->Campaigns[CampaignType];
        MapCount = campaign->MapCount;
        Maps = new char * [campaign->MapCount];
        for (int index = 0; index < MapCount; index++) {
            char entry[32];
            sprintf(entry, "Map%d", index + 1);
            Maps[index] = new char[0x104];
            ini.Get_String(section, entry, "undefined", Maps[index], 0x104);
        }
        delete list;
        IsActive = true;
        return true;
    }
    MapCount = 0;
    delete list;
    return false;
}

// 0x48ee20: save the state of this player pair.
bool CoopCampaignClass::Save()
{
    if (!IsActive || Players[0].Name[0] == '\0' || Players[1].Name[0] == '\0') return false;

    CoopCampaignListClass * list = new CoopCampaignListClass;
    if (CampaignType >= 0 && CampaignType < list->Count) {
    CoopCampaignType * campaign = &list->Campaigns[CampaignType];
    {
    CCFileClass file(SaveFileName);
    CCINIClass ini;
    ini.Load(file, false, false);
    file.Close();

    char section[100];
    strcpy(section, Encode_Name(Players[0].Name));
    strcat(section, Encode_Name(Players[1].Name));

    CCFileClass outfile;
    outfile.Set_Name(SaveFileName);
    outfile.Open(WRITE);
    ini.Clear(section);
    ini.Put_Int(section, "CurrentMap", CurrentMap);
    ini.Put_Int(section, "CampaignType", CampaignType);
    int index;
    for (index = 0; index < campaign->MapCount; index++) {
        char entry[32];
        sprintf(entry, "Map%d", index + 1);
        ini.Put_String(section, entry, Maps[index]);
    }

    if (Session.Players.ActiveCount != 0) {
        ini.Put_HousesType(section, "House1", Session.Players[0]->Side());
        ini.Put_Int(section, "Color1", Session.Players[0]->Color());
    }
    for (index = 1; index < Session.Players.ActiveCount; index++) {
        if (Session.AIHouses[index] == -1) {
            ini.Put_HousesType(section, "House2", Session.Players[index]->Side());
            ini.Put_Int(section, "Color2", Session.Players[index]->Color());
            break;
        }
    }
    ini.Put_Int(section, "Time", Time);
    ini.Put_Int(section, "Kills1", Kills[0]);
    ini.Put_Int(section, "Kills2", Kills[1]);
    ini.Put_Int(section, "Built1", Built[0]);
    ini.Put_Int(section, "Built2", Built[1]);
    ini.Put_Int(section, "Lost1", Lost[0]);
    ini.Put_Int(section, "Lost2", Lost[1]);
    ini.Put_Int(section, "Score1", Score[0]);
    ini.Put_Int(section, "Score2", Score[1]);
    ini.Save(outfile, false);
    outfile.Close();
    }
    delete list;
    IsActive = true;
    return true;
    }
    delete list;
    return false;
}

// 0x48f370: start a new campaign; picks one of the three alternatives of every map.
bool CoopCampaignClass::Start(int campaign)
{
    CoopCampaignListClass * list = new CoopCampaignListClass;
    if (campaign >= 0 && campaign < list->Count) {
        CoopCampaignType * type = &list->Campaigns[campaign];
        IsActive = true;
        CurrentMap = -1;
        Kills[0] = 0;
        Kills[1] = 0;
        Built[0] = 0;
        Built[1] = 0;
        Score[0] = 0;
        Score[1] = 0;
        Lost[0] = 0;
        Lost[1] = 0;
        Time = 0;
        if (CampaignType != campaign) {
            if (Maps != NULL) {
                for (int index = 0; index < MapCount; index++) {
                    if (Maps[index] != NULL) {
                        delete Maps[index];
                    }
                }
                delete Maps;
            }
            Maps = NULL;
            MapCount = 0;
            Maps = new char * [type->MapCount];
            for (int index = 0; index < type->MapCount; index++) {
                int pick = Scen->RandomNumber(0, 2);
                Maps[index] = new char[0x104];
                strncpy(Maps[index], type->Maps[index * 3 + pick], 0x103);
            }
            MapCount = type->MapCount;
            CurrentMap = 0;
        }
        CampaignType = campaign;
        delete list;
        return true;
    }
    delete list;
    return false;
}

// 0x48f510
bool CoopCampaignClass::Set_Progress(int map, int time, MPScoreRecord score1, MPScoreRecord score2)
{
    if (map >= 0 && map < MapCount) {
        CurrentMap = map;
        Kills[0] = score1.Kills + Kills[0];
        Kills[1] = score2.Kills + Kills[1];
        Built[0] = score1.Built + Built[0];
        Built[1] = score2.Built + Built[1];
        Lost[0] = score1.Lost + Lost[0];
        Lost[1] = score2.Lost + Lost[1];
        Score[0] = score1.Score + Score[0];
        Score[1] = score2.Score + Score[1];
        Time = time;
        return true;
    }
    return false;
}

// 0x48f5b0: set up the campaign received from the partner.
bool CoopCampaignClass::Setup(CoopCampaignListClass * list, int campaign, DynamicVectorClass<int> picks, char const * name2, char const * name1)
{
    if (campaign >= 0 && campaign < list->Count) {
        CoopCampaignType * type = &list->Campaigns[campaign];
        CurrentMap = -1;
        Kills[0] = 0;
        Kills[1] = 0;
        Built[0] = 0;
        Built[1] = 0;
        Lost[0] = 0;
        Lost[1] = 0;
        Score[0] = 0;
        Score[1] = 0;
        Time = 0;
        if (type->MapCount != picks.ActiveCount) return false;

        CampaignType = campaign;
        IsActive = true;
        if (Maps != NULL) {
            for (int index = 0; index < MapCount; index++) {
                if (Maps[index] != NULL) {
                    delete Maps[index];
                }
            }
            delete Maps;
        }
        Maps = NULL;
        MapCount = 0;
        Maps = new char * [picks.ActiveCount];
        for (int index = 0; index < picks.ActiveCount; index++) {
            Maps[index] = new char[0x104];
            strncpy(Maps[index], type->Maps[picks[index] + index * 3], 0x103);
        }
        MapCount = picks.ActiveCount;
        CurrentMap = 0;

        if (name1 != NULL) {
            strcpy(Players[0].Name, Decode_Name(name1));
        } else {
            Players[0].Name[0] = '\0';
        }
        if (name2 != NULL) {
            strcpy(Players[1].Name, Decode_Name(name2));
        } else {
            Players[1].Name[0] = '\0';
        }
        Debug_Printf("@@@@ SetCampaignInfo saw campaign_type %d\n", CampaignType);
    }
    return IsActive;
}

// 0x48f920
bool CoopCampaignClass::Get_Map(char ** map, int index)
{
    bool result = false;
    *map = NULL;
    if (index == -1) {
        index = CurrentMap;
    }
    if (index < 0 || index >= MapCount) {
        index = -1;
    }
    if (IsActive) {
        if (index != -1) {
            *map = Maps[index];
        }
        if (*map != NULL) {
            result = true;
        }
    }
    return result;
}

// 0x48f970
bool CoopCampaignClass::Get_Player1(int * house, int * color)
{
    if (IsActive) {
        *house = Players[0].House;
        *color = Players[0].Color;
        return true;
    }
    return false;
}

// 0x48f9a0
bool CoopCampaignClass::Get_Player2(int * house, int * color)
{
    if (IsActive) {
        *house = Players[1].House;
        *color = Players[1].Color;
        return true;
    }
    return false;
}

// 0x48f9d0: is there a saved state for this player pair?
bool CoopCampaignClass::Is_Saved()
{
    if (Players[0].Name[0] != '\0' && Players[1].Name[0] != '\0') {
        CCFileClass file(SaveFileName);
        CCINIClass ini;
        if (!ini.Load(file, false, false)) {
            file.Close();
            return false;
        }
        file.Close();

        char section[100];
        strcpy(section, Encode_Name(Players[0].Name));
        strcat(section, Encode_Name(Players[1].Name));
        return ini.Is_Present(section);
    }
    return false;
}

// 0x48fc50: true when the saved state has no next map (the campaign is complete).
bool CoopCampaignClass::Is_Finished(char * buffer)
{
    if (Players[0].Name[0] != '\0' && Players[1].Name[0] != '\0') {
        CCFileClass file(SaveFileName);
        CCINIClass ini;
        if (!ini.Load(file, false, false)) {
            file.Close();
            return false;
        }
        file.Close();

        char section[100];
        strcpy(section, Encode_Name(Players[0].Name));
        strcat(section, Encode_Name(Players[1].Name));

        char entry[32];
        sprintf(entry, "Map%d", ini.Get_Int(section, "CurrentMap", 0) + 1);
        ini.Get_String(section, entry, "undefined", buffer, 0x104);
        if (strcmp(buffer, "undefined") == 0) {
            return true;
        }
    }
    return false;
}

// 0x48ff30: send the campaign state as game option string to the partner.
bool CoopCampaignClass::Send(CoopCampaignListClass * list)
{
    if (!IsActive) return false;
    if (CampaignType >= 0 && CampaignType < list->Count) {

    CoopCampaignType * type = &list->Campaigns[CampaignType];
    char buffer[400];
    sprintf(buffer, "C0,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", CampaignType, CurrentMap, Time,
        Kills[0], Built[0], Lost[0], Score[0], Kills[1], Built[1], Lost[1], Score[1]);

    for (int index = 0; index < MapCount; index++) {
        int pick = 0;
        for (int alt = 0; alt < 3; alt++) {
            if (_stricmp(type->Maps[index * 3 + alt], Maps[index]) == 0) {
                pick = alt;
                break;
            }
        }
        char temp[16];
        sprintf(temp, ",%d", pick);
        strcat(buffer, temp);
    }
    strcat(buffer, ",-1,");
    strcat(buffer, Encode_Name(Players[0].Name));
    strcat(buffer, ",");
    strcat(buffer, Encode_Name(Players[1].Name));
    Debug_Printf("@@@@ Sending campaign game option string: %s\n", buffer);
    Send_Campaign_Settings(buffer);
    Debug_Printf("@@@@ Sent\n");
    return true;
    }
    return false;
}

// 0x490280: house type index of a campaign house name, -2 for "<random>", -1 when unknown.
int Coop_House_From_Name(char const * name)
{
    if (_stricmp(name, "<random>") == 0) {
        return -2;
    }
    if (name != NULL) {
        for (int index = 0; index < HouseTypes.Count(); index++) {
            HouseTypeClass * house = HouseTypes[index];
            if (_stricmp(house->Name, name) == 0 || _stricmp(house->ID, name) == 0) {
                return index;
            }
        }
    }
    return -1;
}

// 0x4902f0: read the campaign definitions from COOPCAMP.INI.
CoopCampaignListClass::CoopCampaignListClass()
{
    CCFileClass file("CoopCamp.ini");
    if (!INI.Load(file, false, false)) {
        Count = 0;
        Campaigns = NULL;
        IsLoaded = false;
        return;
    }

    Count = INI.Entry_Count("Campaigns");
    if (Count <= 0) {
        Count = 0;
        Campaigns = NULL;
    } else {
        Campaigns = new CoopCampaignType[Count];
        if (Campaigns != NULL) {
            for (int index = 0; index < Count; index++) {
                char const * entry = INI.Get_Entry("Campaigns", index);
                if (entry == NULL) continue;

                char section[128];
                INI.Get_String("Campaigns", entry, NULL, section, sizeof(section));
                int mapcount = INI.Get_Int(section, "NumberOfCampaignMaps", 0);
                if (INI.Get_String(section, "CampaignName", NULL, CampaignBuffer, sizeof(CampaignBuffer))) {
#line 1032 "C:\\RA2\\coopcamp.cpp"
                    wchar_t const * name = Fetch_String(CampaignBuffer, NULL, __FILE__, __LINE__);
                    Campaigns[index].Name = new wchar_t[129];
                    if (Campaigns[index].Name != NULL) {
                        wcscpy(Campaigns[index].Name, name);
                    }
                }
                INI.Get_String(section, "CampaignAI", "Easy", CampaignBuffer, sizeof(CampaignBuffer));
                Campaigns[index].AI = new char[strlen(CampaignBuffer) + 1];
                strcpy(Campaigns[index].AI, CampaignBuffer);
                Campaigns[index].ID = index;
                Campaigns[index].MapCount = (char)mapcount;
                Campaigns[index].Maps = new char[mapcount * 3][0x104];

                char * token;
                if (INI.Get_String(section, "CampaignPlayer", NULL, CampaignBuffer, sizeof(CampaignBuffer))) {
                    token = strtok(CampaignBuffer, ",");
                    if (token != NULL) {
                        char * house = new char[strlen(token) + 1];
                        strcpy(house, token);
                        Campaigns[index].Players.Add(house);
                    }
                    while ((token = strtok(NULL, ",")) != NULL) {
                        char * house = new char[strlen(token) + 1];
                        strcpy(house, token);
                        Campaigns[index].Players.Add(house);
                    }
                }
                if (INI.Get_String(section, "CampaignEnemy", NULL, CampaignBuffer, sizeof(CampaignBuffer))) {
                    token = strtok(CampaignBuffer, ",");
                    if (token != NULL) {
                        char * house = new char[strlen(token) + 1];
                        strcpy(house, token);
                        Campaigns[index].Enemies.Add(house);
                    }
                    while ((token = strtok(NULL, ",")) != NULL) {
                        char * house = new char[strlen(token) + 1];
                        strcpy(house, token);
                        Campaigns[index].Enemies.Add(house);
                    }
                }

                for (int map = 1; map < mapcount + 1; map++) {
                    char mapentry[32];
                    sprintf(mapentry, "Map%d", map);
                    if (INI.Get_String(section, mapentry, NULL, CampaignBuffer, sizeof(CampaignBuffer))) {
                        token = strtok(CampaignBuffer, ",");
                        if (token != NULL) {
                            strcpy(Campaigns[index].Maps[(map - 1) * 3], token);
                        }
                        token = strtok(NULL, ",");
                        if (token != NULL) {
                            strcpy(Campaigns[index].Maps[(map - 1) * 3 + 1], token);
                        }
                        token = strtok(NULL, ",");
                        if (token != NULL) {
                            strcpy(Campaigns[index].Maps[(map - 1) * 3 + 2], token);
                        }
                    }
                }
            }
        }
    }
    IsLoaded = true;
}

// 0x490a30
bool CoopCampaignListClass::Get_Campaign(int index, CoopCampaignType ** campaign)
{
    if (index >= 0 && index < Count) {
        *campaign = &Campaigns[index];
        return true;
    }
    *campaign = NULL;
    return false;
}

// 0x490a70
bool CoopCampaignListClass::Get_Count(int * count)
{
    *count = Count;
    return IsLoaded;
}

// 0x490a80
CoopCampaignListClass::~CoopCampaignListClass()
{
    if (Campaigns != NULL) {
        for (int index = 0; index < Count; index++) {
            if (Campaigns[index].Maps != NULL) {
                delete Campaigns[index].Name;
                delete Campaigns[index].AI;
                delete Campaigns[index].Maps;
            }
            int i;
            for (i = 0; i < Campaigns[index].Enemies.Count(); i++) {
                delete Campaigns[index].Enemies[i];
            }
            Campaigns[index].Enemies.Clear();
            for (i = 0; i < Campaigns[index].Players.Count(); i++) {
                delete Campaigns[index].Players[i];
            }
            Campaigns[index].Players.Clear();
        }
        delete [] Campaigns;
        Campaigns = NULL;
        IsLoaded = false;
    }
}

// 0x490be0
bool CoopCampaignListClass::Get_Names(VectorClass<wchar_t *> & names)
{
    if (IsLoaded) {
        names.Resize(Count);
        for (int index = 0; index < Count; index++) {
            names[index] = new wchar_t[129];
            if (names[index] != NULL) {
                wcscpy(names[index], Campaigns[index].Name);
            }
        }
        return true;
    }
    return false;
}
