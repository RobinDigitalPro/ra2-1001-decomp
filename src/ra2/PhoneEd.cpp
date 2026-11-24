// C:\RA2\PhoneEd.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Modem phone book: the phone book list dialog (resource 0xee) and the phone entry editor dialog
// (resource 0xef). Code range 0x605550..0x606631; PIPE.CPP follows at 0x606640.
// No vtables exist for these classes; all class, method and variable names are provisional
// (Westwood style).
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
void Strtrim(char * buffer);                    // 0x6e41d0 (removes leading/trailing blanks, provisional)
void Wcstrim(wchar_t * buffer);                 // 0x6e4240 (wide version, provisional)

// Dialog support (see also NullDlg.CPP / GameDlg.CPP).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Call_Back_5168E0(bool flag);       // 0x5168e0, called while the dialog runs (meaning unknown)

extern HWND MainWindow;                         // 0xb0de50 (name provisional)
extern char NullString[];                       // 0x8248a4 (.bss), shared empty string (name provisional)

// One-pointer wide string (provisional name, as in WDTTerr.cpp). 0x75b2f0 default ctor,
// 0x75b390 dtor. 0x75c230 replaces the text like operator= (0x75b4b0) but returns 1 in ax.
class WideStringClass {
public:
    WideStringClass();
    ~WideStringClass();
    unsigned short Set(wchar_t const * string);
private:
    wchar_t * Buffer;
};

// Owner-draw list column item (ownrdraw.cpp, constructor 0x5d6f90; name and fields provisional).
// Sent with the list message 0x4a8 to set the text of one column of a row.
class ColumnItemClass {
public:
    ColumnItemClass();
    int Flags;                                  // +0x00, 1 = text valid
    WideStringClass Text;                       // +0x04
    WideStringClass Text2;                      // +0x08
    int Unknown0C;                              // +0x0c
    int Unknown10;                              // +0x10
    int Unknown14;                              // +0x14
};

// Serial port settings (Session + 0x282c and the phone book entries), 0x70 bytes.
enum DialMethodType { DIAL_TOUCH_TONE, DIAL_PULSE };
struct SerialSettingsType {
    int Port;                                   // +0x00
    int IRQ;                                    // +0x04
    int Baud;                                   // +0x08
    DialMethodType DialMethod;                  // +0x0c
    int InitStringIndex;                        // +0x10
    int CallWaitStringIndex;                    // +0x14, 3 = custom string
    char Unknown18[0x20 - 0x18];
    char CallWaitString[0x10];                  // +0x20
    char ModemName[0x70 - 0x30];                // +0x30
};

enum { CALL_WAIT_CUSTOM = 3 };

// Phone book entry, 0xb0 bytes.
class PhoneEntryClass {
public:
    enum { PHONE_MAX_NAME = 21, PHONE_MAX_NUM = 21 };
    SerialSettingsType Settings;                // +0x00, Port == 0: use the default settings
    wchar_t Name[PHONE_MAX_NAME];               // +0x70
    char Number[PHONE_MAX_NUM];                 // +0x9a
};

// Session object at 0xa255c8 (class name provisional); only the members used here, at their
// offsets. The phone book members must be accessed through the object: as separate globals the
// compiler loads them in a different order.
class SessionClass {
public:
    void Write_MultiPlayer_Settings();          // 0x666d70 (name provisional)

    char Unknown0000[0x2828];
    int CurPhoneIdx;                            // +0x2828 (0xa27df0), selected phone book entry
    SerialSettingsType SerialSettings;          // +0x282c (0xa27df4), default settings
    char Unknown289C[0x28A0 - 0x289C];          // +0x289c ModemGameToPlay (NullDlg.CPP)
    DynamicVectorClass<PhoneEntryClass *> PhoneBook;    // +0x28a0 (0xa27e68)
};
extern SessionClass Session;                    // 0xa255c8

class SerialSettingsDialogClass {               // SerialEd.cpp
public:
    bool Process(SerialSettingsType * settings);    // 0x663660
    char Data[0x374];
};

// Phone book dialog, used as a local by Select_Serial_Dialog (NullDlg.CPP); 0x8c bytes.
class PhoneBookDialogClass {
public:
    bool Process();                             // 0x605550
    static BOOL CALLBACK Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x6055d0
    bool Accept_Number();                       // 0x605860
    void Fill_List();                           // 0x605a20
    void Selection_Changed();                   // 0x605cc0
    void New_Entry();                           // 0x605d40
    void Edit_Entry();                          // 0x605ec0
    void Delete_Entry();                        // 0x606000

    HWND Dialog;                                // +0x00
    int Result;                                 // +0x04, 1 = OK, 2 = cancel
    bool Changed;                               // +0x08, phone book must be saved
    char Number[PhoneEntryClass::PHONE_MAX_NUM];    // +0x09
    char Unknown1E[0x8C - 0x1E];
};

// Phone entry editor dialog, used as a local; 0x7c bytes.
class PhoneEntryDialogClass {
public:
    bool Process(PhoneEntryClass * entry);      // 0x6060a0
    static BOOL CALLBACK Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x606120
    void Save_Controls();                       // 0x606380
    void Init_Controls();                       // 0x6064e0

    HWND Dialog;                                // +0x00
    int Result;                                 // +0x04, 1 = OK, 2 = cancel
    PhoneEntryClass * Entry;                    // +0x08
    SerialSettingsType Settings;                // +0x0c, custom settings being edited
};

int __cdecl Phone_Compare(void const * a, void const * b);  // 0x6065d0, qsort callback

// ---- end of local declarations ----

#define IDD_PHONE_BOOK          0xEE
#define IDD_PHONE_ENTRY         0xEF
#define IDC_PHONE_DELETE        0x53B
#define IDC_PHONE_ENTRY_NUMBER  0x5DF
#define IDC_PHONE_LIST          0x5E0
#define IDC_PHONE_EDIT          0x5E4
#define IDC_PHONE_NUMBER        0x5E5       // number edit (book) / name edit (entry dialog)
#define IDC_PHONE_ADD           0x661
#define IDC_PHONE_DEFAULT       0x663
#define IDC_PHONE_CUSTOM        0x664
#define WM_DIALOG_INIT          (WM_USER + 0x97)

// Westwood control messages (names provisional).
#define WWM_SET_TEXT_WIDE       (WM_USER + 0xB2)
#define WWM_GET_TEXT_WIDE       (WM_USER + 0xB3)
#define WWM_SET_TEXT            (WM_USER + 0xB4)
#define WWM_GET_TEXT            (WM_USER + 0xB5)
#define WWM_SET_COLUMN          (WM_USER + 0xA6)
#define WWM_SET_ITEM            (WM_USER + 0xA8)
#define WWM_ADD_STRING_WIDE     (WM_USER + 0xCD)
#define WWN_CHANGED             0x501

bool PhoneBookDialogClass::Process()
{
    Dialog = Create_Dialog(IDD_PHONE_BOOK, Dialog_Proc, 0);
    if (Dialog) {
        Changed = false;
        Result = -1;
        SetWindowLongA(Dialog, DWL_USER, (LONG)this);
        Fill_List();
        Show_Dialog(Dialog);
        while (Result < 0) {
            if (Dialog_Abort_Check() == true) {
                break;
            }
            Call_Back_5168E0(false);
        }
        End_Dialog(Dialog);
        if (Changed == true) {
            Session.Write_MultiPlayer_Settings();
        }
    }
    return (Result == 1) ? true : false;
}

BOOL CALLBACK PhoneBookDialogClass::Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) {
        return result;
    }

    PhoneBookDialogClass * self = (PhoneBookDialogClass *)GetWindowLongA(dialog, DWL_USER);

    switch (message) {
        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case IDOK:
                    if (HIWORD(wparam) == 0 && self->Accept_Number() == true) {
                        self->Result = 1;
                        return FALSE;
                    }
                    break;

                case IDCANCEL:
                    if (HIWORD(wparam) == 0) {
                        self->Result = 2;
                        return FALSE;
                    }
                    break;

                case IDC_PHONE_DELETE:
                    if (HIWORD(wparam) == 0) {
                        self->Delete_Entry();
                    }
                    break;

                case IDC_PHONE_LIST:
                    if (HIWORD(wparam) == 1) {
                        self->Selection_Changed();
                        return FALSE;
                    }
                    break;

                case IDC_PHONE_EDIT:
                    if (HIWORD(wparam) == 0) {
                        self->Edit_Entry();
                    }
                    break;

                case IDC_PHONE_ADD:
                    if (HIWORD(wparam) == 0) {
                        self->New_Entry();
                        return FALSE;
                    }
                    break;
            }
            break;

        case WM_DIALOG_INIT:
            SendDlgItemMessageA(dialog, IDC_PHONE_NUMBER, EM_LIMITTEXT, 20, 0);
            SendDlgItemMessageA(dialog, IDC_PHONE_LIST, WWM_SET_COLUMN, 0x90, 2);
            SendDlgItemMessageA(dialog, IDC_PHONE_LIST, WWM_SET_COLUMN, 0x79, 0x96);
            SendDlgItemMessageA(dialog, IDC_PHONE_LIST, WWM_SET_COLUMN, 0, 0x113);
            return FALSE;
    }
    return FALSE;
}

bool PhoneBookDialogClass::Accept_Number()
{
    HWND edit = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
    SendMessageA(edit, WWM_GET_TEXT, PhoneEntryClass::PHONE_MAX_NUM, (LPARAM)Number);
    HWND list = GetDlgItem(Dialog, IDC_PHONE_LIST);
    Session.CurPhoneIdx = SendMessageA(list, LB_GETCURSEL, 0, 0);
    if (Session.CurPhoneIdx == -1 || strcmp(Session.PhoneBook[Session.CurPhoneIdx]->Number, Number) != 0) {
        if (strlen(Number) == 0) {
            return false;
        }

        PhoneEntryClass * entry = new PhoneEntryClass;
        if (!entry) {
            return false;
        }

#line 231 "C:\\RA2\\PhoneEd.cpp"
        wcscpy(entry->Name, Fetch_String("TXT_NONAME", NULL, __FILE__, __LINE__));
        strcpy(entry->Number, Number);
        entry->Settings.Port = 0;
        entry->Settings.IRQ = -1;
        entry->Settings.Baud = -1;
        entry->Settings.DialMethod = DIAL_TOUCH_TONE;
        entry->Settings.InitStringIndex = -1;
        entry->Settings.CallWaitStringIndex = CALL_WAIT_CUSTOM;
        entry->Settings.CallWaitString[0] = 0;

        Session.PhoneBook.Add(entry);
        Fill_List();
        Changed = true;
        Session.CurPhoneIdx = Session.PhoneBook.ID(entry);
    }
    return true;
}

void PhoneBookDialogClass::Fill_List()
{
    ColumnItemClass item;
    wchar_t buffer[80];
    char number[80];

    HWND list = GetDlgItem(Dialog, IDC_PHONE_LIST);
    if (list) {
        SendMessageA(list, LB_RESETCONTENT, 0, 0);

        if (Session.PhoneBook.ActiveCount > 1) {
            qsort(&Session.PhoneBook[0], Session.PhoneBook.ActiveCount, sizeof(PhoneEntryClass *), Phone_Compare);
        }

        for (int index = 0; index < Session.PhoneBook.ActiveCount; index++) {
            if (wcslen(Session.PhoneBook[index]->Name) == 0) {
                wcscpy(buffer, L" ");
            } else {
                wcsncpy(buffer, Session.PhoneBook[index]->Name, 20);
                buffer[20] = 0;
            }
            int row = SendMessageA(list, WWM_ADD_STRING_WIDE, 0, (LPARAM)buffer);

            if (strlen(Session.PhoneBook[index]->Number) == 0) {
                wcscpy(buffer, L" ");
            } else {
                strncpy(number, Session.PhoneBook[index]->Number, 20);
                number[20] = 0;
                swprintf(buffer, L"%hs", number);
            }
            item.Flags = 1;
            item.Text.Set(buffer);
            SendMessageA(list, WWM_SET_ITEM, MAKEWPARAM(0x96, row), (LPARAM)&item);

            if (Session.PhoneBook[index]->Settings.Baud != -1) {
                swprintf(buffer, L"%d", Session.PhoneBook[index]->Settings.Baud);
            } else {
#line 321
                swprintf(buffer, L"[%s]", Fetch_String("TXT_DEFAULT", NULL, __FILE__, __LINE__));
            }
            item.Flags = 1;
            item.Text.Set(buffer);
            SendMessageA(list, WWM_SET_ITEM, MAKEWPARAM(0x113, row), (LPARAM)&item);
        }

        if (SendMessageA(list, LB_GETCOUNT, 0, 0) == 0 || Session.CurPhoneIdx < -1) {
            Session.CurPhoneIdx = -1;
        } else if (Session.CurPhoneIdx >= SendMessageA(list, LB_GETCOUNT, 0, 0)) {
            Session.CurPhoneIdx = 0;
        }
        if (Session.CurPhoneIdx > -1) {
            SendMessageA(list, LB_SETCURSEL, Session.CurPhoneIdx, 0);
            HWND edit = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
            if (edit) {
                SendMessageA(edit, WWM_SET_TEXT, 0, (LPARAM)Session.PhoneBook[Session.CurPhoneIdx]->Number);
            }
        }
    }
}

void PhoneBookDialogClass::Selection_Changed()
{
    HWND list = GetDlgItem(Dialog, IDC_PHONE_LIST);
    if (list && SendMessageA(list, LB_GETCOUNT, 0, 0) > 0) {
        Session.CurPhoneIdx = SendMessageA(list, LB_GETCURSEL, 0, 0);
        if (Session.CurPhoneIdx > -1) {
            HWND edit = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
            SendMessageA(edit, WWM_SET_TEXT, 0, (LPARAM)Session.PhoneBook[Session.CurPhoneIdx]->Number);
            SetFocus(edit);
        }
    }
}

void PhoneBookDialogClass::New_Entry()
{
    PhoneEntryDialogClass dialog;

    PhoneEntryClass * entry = new PhoneEntryClass;
    if (entry) {
        entry->Name[0] = 0;
        entry->Number[0] = 0;
        entry->Settings.Port = 0;
        entry->Settings.IRQ = -1;
        entry->Settings.Baud = -1;
        entry->Settings.DialMethod = DIAL_TOUCH_TONE;
        entry->Settings.InitStringIndex = -1;
        entry->Settings.CallWaitStringIndex = CALL_WAIT_CUSTOM;
        entry->Settings.CallWaitString[0] = 0;

        ShowWindow(Dialog, SW_HIDE);
        UpdateWindow(MainWindow);

        if (dialog.Process(entry) == true) {
            Session.PhoneBook.Add(entry);
            Changed = true;
            Fill_List();
            Session.CurPhoneIdx = Session.PhoneBook.ID(entry);
            if (Session.CurPhoneIdx > -1) {
                HWND list = GetDlgItem(Dialog, IDC_PHONE_LIST);
                if (list) {
                    SendMessageA(list, LB_SETCURSEL, Session.CurPhoneIdx, 0);
                }
                HWND edit = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
                if (edit) {
                    SendMessageA(edit, WWM_SET_TEXT, 0, (LPARAM)Session.PhoneBook[Session.CurPhoneIdx]->Number);
                }
            }
        } else {
            delete entry;
        }
        ShowWindow(Dialog, SW_SHOW);
    }
}

void PhoneBookDialogClass::Edit_Entry()
{
    PhoneEntryDialogClass dialog;

    HWND list = GetDlgItem(Dialog, IDC_PHONE_LIST);
    if (list) {
        Session.CurPhoneIdx = SendMessageA(list, LB_GETCURSEL, 0, 0);
    }

    if (Session.CurPhoneIdx > -1) {
        PhoneEntryClass * copy = new PhoneEntryClass;
        if (copy) {
            PhoneEntryClass * entry = Session.PhoneBook[Session.CurPhoneIdx];
            *copy = *entry;

            ShowWindow(Dialog, SW_HIDE);
            UpdateWindow(MainWindow);

            if (dialog.Process(copy) == true) {
                Changed = true;
                *entry = *copy;
                Fill_List();
                Session.CurPhoneIdx = Session.PhoneBook.ID(entry);
                if (Session.CurPhoneIdx > -1) {
                    SendMessageA(list, LB_SETCURSEL, Session.CurPhoneIdx, 0);
                    HWND edit = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
                    if (edit) {
                        SendMessageA(edit, WWM_SET_TEXT, 0, (LPARAM)entry->Number);
                    }
                }
            }
            ShowWindow(Dialog, SW_SHOW);
            delete copy;
        }
    }
}

void PhoneBookDialogClass::Delete_Entry()
{
    HWND list = GetDlgItem(Dialog, IDC_PHONE_LIST);
    if (list) {
        Session.CurPhoneIdx = SendMessageA(list, LB_GETCURSEL, 0, 0);
        if (Session.CurPhoneIdx > -1) {
            Session.PhoneBook.Delete(Session.CurPhoneIdx);
            Changed = true;
            Fill_List();
            if (Session.CurPhoneIdx == -1) {
                HWND edit = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
                if (edit) {
                    SendMessageA(edit, WWM_SET_TEXT, 0, (LPARAM)NullString);
                }
            }
        }
    }
}

// The original does not inline this function into New_Entry/Edit_Entry, although -Ob2 would
// (it does inline Selection_Changed and Delete_Entry of similar size). The cause is unknown;
// auto_inline(off) reproduces the original code.
#pragma auto_inline(off)
bool PhoneEntryDialogClass::Process(PhoneEntryClass * entry)
{
    if (!entry) {
        return false;
    }

    Dialog = Create_Dialog(IDD_PHONE_ENTRY, Dialog_Proc, 0);
    if (Dialog) {
        Entry = entry;
        Result = -1;
        SetWindowLongA(Dialog, DWL_USER, (LONG)this);
        Init_Controls();
        Show_Dialog(Dialog);
        while (Result < 0) {
            if (Dialog_Abort_Check() == true) {
                break;
            }
            Call_Back_5168E0(false);
        }
        End_Dialog(Dialog);
    }
    return (Result == 1) ? true : false;
}
#pragma auto_inline(on)

BOOL CALLBACK PhoneEntryDialogClass::Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) {
        return result;
    }

    PhoneEntryDialogClass * self = (PhoneEntryDialogClass *)GetWindowLongA(dialog, DWL_USER);

    switch (message) {
        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case IDOK:
                    if (HIWORD(wparam) == 0) {
                        self->Save_Controls();
                        self->Result = 1;
                        return FALSE;
                    }
                    break;

                case IDCANCEL:
                    if (HIWORD(wparam) == 0) {
                        self->Result = 2;
                        return FALSE;
                    }
                    break;

                case IDC_PHONE_ENTRY_NUMBER:
                    if (HIWORD(wparam) == WWN_CHANGED || HIWORD(wparam) == EN_KILLFOCUS) {
                        char buffer[64];
                        SendMessageA((HWND)lparam, WWM_GET_TEXT, sizeof(buffer), (LPARAM)buffer);
                        Strtrim(buffer);
                        SendMessageA((HWND)lparam, WWM_SET_TEXT, 0, (LPARAM)buffer);
                        return FALSE;
                    }
                    break;

                case IDC_PHONE_NUMBER:
                    if (HIWORD(wparam) == WWN_CHANGED || HIWORD(wparam) == EN_KILLFOCUS) {
                        wchar_t buffer[64];
                        SendMessageA((HWND)lparam, WWM_GET_TEXT_WIDE, 64, (LPARAM)buffer);
                        Wcstrim(buffer);
                        SendMessageA((HWND)lparam, WWM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
                        return FALSE;
                    }
                    break;

                case IDC_PHONE_DEFAULT:
                    if (HIWORD(wparam)) {
                        SendMessageA((HWND)lparam, BM_SETCHECK, BST_CHECKED, 0);
                        SendDlgItemMessageA(dialog, IDC_PHONE_CUSTOM, BM_SETCHECK, BST_UNCHECKED, 0);
                    }
                    break;

                case IDC_PHONE_CUSTOM:
                    if (HIWORD(wparam)) {
                        SendMessageA((HWND)lparam, BM_SETCHECK, BST_CHECKED, 0);
                        SendDlgItemMessageA(dialog, IDC_PHONE_DEFAULT, BM_SETCHECK, BST_UNCHECKED, 0);
                        UpdateWindow(dialog);
                        ShowWindow(dialog, SW_HIDE);
                        UpdateWindow(MainWindow);
                        SerialSettingsDialogClass settingsdialog;
                        settingsdialog.Process(&self->Settings);
                        ShowWindow(dialog, SW_SHOW);
                        return FALSE;
                    }
                    break;
            }
            break;

        case WM_DIALOG_INIT:
            SendDlgItemMessageA(dialog, IDC_PHONE_NUMBER, EM_LIMITTEXT, 20, 0);
            SendDlgItemMessageA(dialog, IDC_PHONE_ENTRY_NUMBER, EM_LIMITTEXT, 20, 0);
            return FALSE;
    }
    return FALSE;
}

void PhoneEntryDialogClass::Save_Controls()
{
    HWND name = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
    if (name) {
        SendMessageA(name, WWM_GET_TEXT_WIDE, PhoneEntryClass::PHONE_MAX_NAME, (LPARAM)Entry->Name);
        if (wcslen(Entry->Name) > 0) {
            _wcsupr(Entry->Name);
        } else {
#line 757
            wcscpy(Entry->Name, Fetch_String("TXT_NONAME", NULL, __FILE__, __LINE__));
        }
    }
    Debug_Printf("Name: %ls\n", Entry->Name);

    HWND number = GetDlgItem(Dialog, IDC_PHONE_ENTRY_NUMBER);
    if (number) {
        SendMessageA(number, WWM_GET_TEXT, PhoneEntryClass::PHONE_MAX_NUM, (LPARAM)Entry->Number);
    }
    Debug_Printf("Number: %s\n", Entry->Number);

    bool custom = false;
    HWND button = GetDlgItem(Dialog, IDC_PHONE_CUSTOM);
    if (button) {
        custom = (SendMessageA(button, BM_GETCHECK, 0, 0) == BST_CHECKED);
    }
    if (custom == true) {
        Entry->Settings = Settings;
    } else {
        Entry->Settings.Port = 0;
        Entry->Settings.IRQ = -1;
        Entry->Settings.Baud = -1;
        Entry->Settings.DialMethod = DIAL_TOUCH_TONE;
        Entry->Settings.InitStringIndex = -1;
        Entry->Settings.CallWaitStringIndex = CALL_WAIT_CUSTOM;
        Entry->Settings.CallWaitString[0] = 0;
    }
    Debug_Printf("Settings: Port %d, Baud %d\n", Entry->Settings.Port, Entry->Settings.Baud);
}

void PhoneEntryDialogClass::Init_Controls()
{
    bool custom;

    HWND item = GetDlgItem(Dialog, IDC_PHONE_NUMBER);
    SendMessageA(item, WWM_SET_TEXT_WIDE, 0, (LPARAM)Entry->Name);
    item = GetDlgItem(Dialog, IDC_PHONE_ENTRY_NUMBER);
    SendMessageA(item, WWM_SET_TEXT, 0, (LPARAM)Entry->Number);

    if (Entry->Settings.Port != 0 && Entry->Settings.IRQ != -1 && Entry->Settings.Baud != -1) {
        Settings = Entry->Settings;
        custom = true;
    } else {
        Settings = Session.SerialSettings;
        custom = false;
    }

    item = GetDlgItem(Dialog, IDC_PHONE_CUSTOM);
    if (item) {
        SendMessageA(item, BM_SETCHECK, custom == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_PHONE_DEFAULT);
    if (item) {
        SendMessageA(item, BM_SETCHECK, !custom, 0);
    }
}

int __cdecl Phone_Compare(void const * a, void const * b)
{
    PhoneEntryClass const * entry1 = *(PhoneEntryClass * const *)a;
    PhoneEntryClass const * entry2 = *(PhoneEntryClass * const *)b;

    int result = wcscmp(entry1->Name, entry2->Name);
    if (result == 0) {
        result = strcmp(entry1->Number, entry2->Number);
    }
    return result;
}
