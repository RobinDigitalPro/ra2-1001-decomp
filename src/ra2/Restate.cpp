// C:\RA2\Restate.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Mission briefing ("restate mission") dialog.
#include "GAMECONST.H"
#include <windows.h>

// ---- local declarations (to be moved to headers by the integrator) ----

// File class hierarchy (RTTI: FileClass, RawFileClass, BufferIOFileClass, CDFileClass, CCFileClass).
// The 17 virtual slots follow the RTTI vtable slot count; signatures are provisional.
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

// Owned or borrowed memory block (0x438140 constructor, 0x438290 destructor).
class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);
    ~Buffer();
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass();                      // 0x468bf0
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual void Close();               // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Doubly linked list (RTTI: GenericNode, GenericList, List<T>).
class GenericNode {
public:
    virtual ~GenericNode();
private:
    GenericNode * NextNode;
    GenericNode * PrevNode;
};

class GenericList {
public:
    GenericList();                      // 0x490c60
    virtual ~GenericList();
private:
    GenericNode FirstNode;
    GenericNode LastNode;
};

template<class T>
class List : public GenericList {
};

// Sorted index (constructor 0x490ea0 is out of line in GAME.EXE).
template<class INDEX, class DATA>
class IndexClass {
public:
    IndexClass();
    ~IndexClass();
private:
    void * IndexTable;
    int IndexCount;
    int IndexSize;
    bool IsSorted;
    void const * Archive;
};

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

    // The existing CCINI.H names 0x50be00 "Is_Present(char const *)". This TU shows that it is
    // the section lookup behind an inline two-argument Is_Present; 0x50c0f0 is the entry lookup.
    INISection * Find_Section(char const * section);                        // 0x50be00
    INIEntry * Find_Entry(char const * section, char const * entry);        // 0x50c0f0
    bool Is_Present(char const * section, char const * entry = NULL)
    {
        if (entry == NULL) return Find_Section(section) != NULL;
        return Find_Entry(section, entry) != NULL;
    }
    int Load(FileClass & file, bool withdigest, bool merge);                // 0x4692d0
    int Get_String(char const * section, char const * entry, char const * defvalue, char * buffer, int size);
private:
    bool IsDigestPresent;               // +0x38
    unsigned char Digest[20];           // +0x39
};

// Only the fields used here; layout not reconstructed.
class ScenarioClass {
public:
    char Unknown0[0x83C];
    char ScenarioName[0x2306 - 0x83C];  // +0x83c, INI section name of the scenario
    bool Field2306;                     // +0x2306, meaning unknown
};
extern ScenarioClass * Scen;            // 0xa255c0

// Keyboard object (0x530c50 discards pending keys); names provisional.
class WWKeyboardClass {
public:
    void Clear();
};
extern WWKeyboardClass * Keyboard;      // 0x81a7a8

// The display object at 0x81a820 has the MouseClass vtable; Flag_To_Redraw is the
// GScreenClass virtual 0x4e0030 (not overridden).
class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);
};
class MouseClass : public GScreenClass {
};
extern MouseClass Map;                  // 0x81a820

extern bool Flag_A28944;                // 0xa28944, saved/cleared/restored here; meaning unknown
extern bool Flag_A28984;                // 0xa28984, set while the briefing is shown; meaning unknown
extern char EmptyString[];              // 0x8248a4 (BSS), shared default string

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0

// ---- end of local declarations ----

#define IDD_BRIEFING        0x10C
#define IDC_BRIEFING_OK     0x423
#define IDC_BRIEFING_TEXT   0x6E7
#define WM_BRIEFING_INIT    (WM_USER + 0x97)
#define WM_SET_TEXT_WIDE    (WM_USER + 0xB2)

char const * BriefingININame = "MISSION.INI";       // 0x7d8310
char const * BriefingEntryName = "Briefing";        // 0x7d8314

static wchar_t const * BriefingText;                // 0xa9e230

static BOOL CALLBACK Restate_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);

void Restate_Mission(ScenarioClass * scenario)
{
    bool oldflag = Flag_A28944;
    Flag_A28944 = false;

    CCFileClass file;
    CCINIClass ini;
    file.Close();
    file.Set_Name(BriefingININame);

    if (file.Is_Available()) {
        ini.Load(file, false, false);

        char const * section = scenario->ScenarioName;
        if (ini.Is_Present(section, BriefingEntryName)) {
            char buffer[256];
            ini.Get_String(section, BriefingEntryName, EmptyString, buffer, sizeof(buffer));
#line 135 "C:\\RA2\\Restate.cpp"
            BriefingText = Fetch_String(buffer, NULL, __FILE__, __LINE__);
        } else {
#line 138
            BriefingText = Fetch_String("Brief:Error", NULL, __FILE__, __LINE__);
        }

        HWND dialog = Create_Dialog(IDD_BRIEFING, Restate_Dialog_Proc, 0);
        Flag_A28984 = true;
        Keyboard->Clear();
        if (dialog != NULL) {
            int result;
            SetWindowLongA(dialog, DWL_USER, (LONG)&result);
            Show_Dialog(dialog);
            result = 0;
            while (result == 0) {
                if (Dialog_Abort_Check()) {
                    result = IDC_BRIEFING_OK;
                }
            }
            End_Dialog(dialog);
        }
        Keyboard->Clear();
        Flag_A28984 = Scen->Field2306;
        Map.Flag_To_Redraw(2);
    }

    Flag_A28944 = oldflag;
}

static BOOL CALLBACK Restate_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    switch (message) {
        case WM_COMMAND:
            if (GetDlgCtrlID((HWND)lparam) == IDC_BRIEFING_OK && HIWORD(wparam) == BN_CLICKED) {
                *(int *)GetWindowLongA(dialog, DWL_USER) = IDC_BRIEFING_OK;
            }
            break;

        case WM_BRIEFING_INIT:
        {
            HWND text = GetDlgItem(dialog, IDC_BRIEFING_TEXT);
            SendMessageA(text, WM_SET_TEXT_WIDE, 0, (LPARAM)BriefingText);
            return FALSE;
        }
    }
    return FALSE;
}
