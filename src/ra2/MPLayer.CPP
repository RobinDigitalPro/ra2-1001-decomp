// C:\RA2\MPLayer.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Contents: a small multiplayer dialog procedure, an OK/Cancel question box, a helper that deletes
// every element of a pointer vector, and the "Man Battle" multiplayer game mode.
// Class names come from RTTI (.?AVMultiplayerManBattle@@ : .?AVMultiplayerGameMode@@); all other
// names (functions, the string classes, the vector element type) are provisional.
// TU extent: header initializers 0x1a3e00..0x1a3fc1, functions 0x1a3fd0..0x1a4111. The code from
// 0x1a4120 to 0x1a711a is the multi-precision math module (prime table 0x7ce3ec, DER encoders,
// bignum arithmetic) of a separate translation unit without static initializers.
#include "GAMECONST.H"
#include <windows.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x6eeb60

// Dialog support (see also MPScore.cpp / NullDlg.CPP).
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624); see NullDlg.CPP.
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};

// One-pointer wide string (provisional name). 0x75b350 copy ctor, 0x75b390 dtor.
class WideStringClass {
public:
    WideStringClass(WideStringClass const & string);
    ~WideStringClass();
private:
    wchar_t * Buffer;
};

// One-pointer narrow string (provisional name). 0x7592c0 copy ctor.
class CharStringClass {
public:
    CharStringClass(CharStringClass const & string);
    ~CharStringClass();
private:
    char * Buffer;
};

// RTTI .?AVMultiplayerGameMode@@, vtable 0x792188 (44 slots); same declaration as MPObserver.cpp.
class MultiplayerGameMode {
public:
    MultiplayerGameMode(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value);  // 0x5b37e0
    virtual ~MultiplayerGameMode();      // 0x5b3930
    virtual void Virtual_01();
    virtual void Virtual_02();
    virtual void Virtual_03();
    virtual void Virtual_04();
    virtual void Virtual_05();
    virtual void Virtual_06();
    virtual void Virtual_07();
    virtual void Virtual_08();
    virtual void Virtual_09();
    virtual void Virtual_10();
    virtual void Virtual_11();
    virtual void Virtual_12();
    virtual void Virtual_13();
    virtual void Virtual_14();
    virtual void Virtual_15();
    virtual void Virtual_16();
    virtual void Virtual_17();
    virtual void Virtual_18();
    virtual void Virtual_19();
    virtual void Virtual_20();
    virtual void Virtual_21();
    virtual void Virtual_22();
    virtual void Virtual_23();
    virtual void Virtual_24();
    virtual void Virtual_25();
    virtual void Virtual_26();
    virtual void Virtual_27();
    virtual void Virtual_28();
    virtual bool Reveal_Map();           // slot 29: base 0x5b4d00 returns true
    virtual void Virtual_30();
    virtual void Virtual_31();
    virtual void Virtual_32();
    virtual void Virtual_33();
    virtual void Virtual_34();
    virtual void Virtual_35();
    virtual void Virtual_36();
    virtual void Virtual_37();
    virtual void Virtual_38();
    virtual void Virtual_39();
    virtual void Virtual_40();
    virtual void Virtual_41();
    virtual void Virtual_42();
    virtual void Virtual_43();
};

// RTTI .?AVMultiplayerManBattle@@ : MultiplayerGameMode, vtable 0x7919b4 (only slot 0 overridden).
class MultiplayerManBattle : public MultiplayerGameMode {
public:
    MultiplayerManBattle(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value);
    virtual ~MultiplayerManBattle();
};

// Element type of the global pointer vectors 0xa27d78, 0xa27d90 and 0xa27da8 (0xa27da8 is the
// player list used by MultiplayerTeam::Is_Valid_Index); deleted without a destructor call.
// Provisional name and contents.
struct NodeNameType {
    int Unknown;
};

int OK_Cancel_Box(wchar_t const * message);
void Delete_All(DynamicVectorClass<NodeNameType *> & vector);

// ---- end of local declarations ----

// 0x5a3fd0: stores the id of the pressed control into the int that the dialog's DWL_USER points to.
BOOL CALLBACK MPLayer_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) {
        return result;
    }

    if (message == WM_COMMAND) {
        *(int *)GetWindowLongA(dialog, DWL_USER) = LOWORD(wparam);
    }
    return FALSE;
}

// 0x5a4020: true when the user answers OK.
#line 106 "C:\\RA2\\MPLayer.CPP"
int OK_Cancel_Box(wchar_t const * message)
{
    return WWMessageBox().Process(message, Fetch_String("TXT_OK", NULL, __FILE__, __LINE__), Fetch_String("TXT_CANCEL", NULL, __FILE__, __LINE__)) == 0;
}

// 0x5a4070: deletes every element, then clears the vector (virtual Clear).
void Delete_All(DynamicVectorClass<NodeNameType *> & vector)
{
    for (int index = 0; index < vector.ActiveCount; index++) {
        delete vector[index];
    }
    vector.Clear();
}

MultiplayerManBattle::MultiplayerManBattle(WideStringClass const & name, WideStringClass const & description,
    CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value) :
    MultiplayerGameMode(name, description, ini_name, ini_file, flag, value)
{
}

MultiplayerManBattle::~MultiplayerManBattle()
{
}
