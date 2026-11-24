// C:\RA2\SerialEd.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Serial settings editor: the dialog that edits a SerialSettingsType (port or modem, baud rate,
// call waiting string, modem init strings, dial method and two modem option check boxes).
// The dialog object has no vtable; the class name SerialSettingsDialogClass and all method,
// member and variable names are provisional (Westwood style).
//
// TU boundary: the 12 GAMECONST initializers 0x263490..0x263651, then the code 0x263660..0x264c83
// (15 member functions in source order). The 16-byte zeroing initializer at 0x264c90 directly
// precedes the next TU's GAMECONST block (0x264cb0) and is not claimed here.
// Several small members (Build_Call_Wait_List, Update_Dial_Method, Show_Custom_Edit,
// Call_Wait_Edit_Done) are auto-inlined into Init / Dialog_Proc and also emitted out of line.
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)

// Dialog support (see also NullDlg.CPP / GameDlg.CPP).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Call_Back_5168E0(bool flag);       // 0x5168e0, called while the dialog runs (meaning unknown)

// Returns the index of the first combo box item from 'start' on whose item data equals 'data',
// or -1 (CB_GETCOUNT / CB_GETITEMDATA loop). Name provisional.
int Find_Item_Data(HWND combo, int start, int data);    // 0x72b9d0

// Removes leading and trailing white space in place. Name provisional.
char * strtrim(char * buffer);          // 0x6e41d0

extern char EmptyString[];              // 0x8248a4

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624).
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};

// Serial port settings (Session + 0x282c and the phone book entries), 0x70 bytes.
enum DialMethodType { DIAL_TOUCH_TONE, DIAL_PULSE };
struct SerialSettingsType {
    int Port;                                   // +0x00, 0x3f8/0x2f8/0x3e8/0x2e8, 1 = modem device
    int IRQ;                                    // +0x04
    int Baud;                                   // +0x08
    DialMethodType DialMethod;                  // +0x0c
    int InitStringIndex;                        // +0x10
    int CallWaitStringIndex;                    // +0x14, 3 = custom string
    int Option18;                               // +0x18, check box 0x3eb (meaning unknown)
    int Option1C;                               // +0x1c, check box 0x3ea (meaning unknown)
    char CallWaitString[0x10];                  // +0x20
    char ModemName[0x40];                       // +0x30
};

enum { CALL_WAIT_CUSTOM = 3 };

// RTTI .?AVNullModemClass@@ (vtable 0x7923d4); only the member used here.
class NullModemClass {
public:
    virtual ~NullModemClass();
    int Detect_Port(SerialSettingsType * settings);    // 0x5c8a70, 0 = valid
};
extern NullModemClass NullModem;                // 0xa28668

enum PortDetectType { PORT_VALID, PORT_INVALID, PORT_IRQ_INUSE };

// Windows modem registry entry, 0x1c bytes, no vtable; the first field is the modem name.
// Names provisional.
class ModemRegistryEntryClass {
public:
    ModemRegistryEntryClass(int modem_number);  // 0x599af0
    ~ModemRegistryEntryClass();                 // 0x59a2e0
    char * Get_Modem_Name() { return ModemName; }

    char * ModemName;                           // +0x00
    char * Unknown04[6];
};

// Session members (see NullDlg.CPP for the convention of separate globals).
extern DynamicVectorClass<char *> SessionInitStrings;           // 0xa27e80 (Session + 0x28b8)
extern DynamicVectorClass<wchar_t *> SessionCallWaitStrings;    // 0xa27e98 (Session + 0x28d0)

#define IDD_SERIAL_SETTINGS     0xED
#define IDC_OPTION_3EA          0x3EA
#define IDC_OPTION_3EB          0x3EB
#define IDC_PORT                0x657
#define IDC_BAUD                0x658
#define IDC_CALL_WAIT           0x659
#define IDC_CALL_WAIT_EDIT      0x65A
#define IDC_PULSE               0x65B
#define IDC_TONE                0x65C
#define IDC_INIT_STRING_EDIT    0x65D
#define IDC_INIT_STRINGS        0x65E
#define IDC_PORT_EDIT           0x65F
#define IDC_INIT_STRING_REMOVE  0x660
#define IDC_INIT_STRING_ADD     0x661

// Custom messages of the game's owner-drawn controls (meanings provisional).
#define WM_SERIAL_INIT          (WM_USER + 0x97)
#define WM_SET_TEXT_NARROW      (WM_USER + 0xB4)
#define WM_GET_TEXT_NARROW      (WM_USER + 0xB5)
#define LB_GETTEXT_NARROW       (WM_USER + 0xB7)
#define CB_FINDSTRING_NARROW    (WM_USER + 0xB8)
#define CB_ADDSTRING_NARROW     (WM_USER + 0xBC)
#define CB_GETLBTEXT_NARROW     (WM_USER + 0xBD)
#define CB_ADDSTRING_WIDE       (WM_USER + 0xC2)
#define LB_FINDSTRING_NARROW    (WM_USER + 0xC4)
#define LB_ADDSTRING_NARROW     (WM_USER + 0xC8)
#define EN_ENTER                0x501       // notification of the game's edit controls (provisional)

#define PORT_CUSTOM             4
#define PORT_MODEM_FIRST        5
#define MAX_MODEMS              10
#define MAX_MODEM_NAME          63
#define MAX_INIT_STRING         40

enum { RESULT_NONE = -1, RESULT_OK = 1, RESULT_CANCEL = 2 };

// Serial settings dialog object (no vtable; used as a 0x374-byte local by Select_Serial_Dialog).
class SerialSettingsDialogClass {
public:
    bool Process(SerialSettingsType * settings);

private:
    static BOOL CALLBACK Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);
    bool Read_Settings();
    void Init(SerialSettingsType * settings);
    void Build_Port_List();
    void Build_Baud_List();
    void Build_Call_Wait_List();
    void Build_Init_String_List();
    void Update_Dial_Method();
    void Show_Custom_Edit(int id);
    void Port_Edit_Done();
    void Call_Wait_Edit_Done();
    void Set_Custom_Item(int id, int data, char * text);
    void Add_Init_String();
    void Remove_Init_String();

    HWND Dialog;                                // +0x00
    int Result;                                 // +0x04
    char Buffer[0x80];                          // +0x08
    SerialSettingsType Settings;                // +0x88
    int ModemCount;                             // +0xf8
    char ModemNames[MAX_MODEMS][MAX_MODEM_NAME];    // +0xfc, object size 0x374
};

// ---- end of local declarations ----

// Port names (.data 0x7dcb40); only the first four are added in the loop, "TXT_CUSTOM" is the
// shared literal also used directly.
static char const * PortNames[5] = {
    "TXT_COM1", "TXT_COM2", "TXT_COM3", "TXT_COM4", "TXT_CUSTOM"
};

// Baud rate names (.data 0x7dcb54); the combo box item data is the table index.
static wchar_t const * BaudNames[6] = {
    L"14400", L"19200", L"28800", L"38400", L"57600", L"115200"
};

bool SerialSettingsDialogClass::Process(SerialSettingsType * settings)
{
    Result = RESULT_NONE;
    Dialog = Create_Dialog(IDD_SERIAL_SETTINGS, Dialog_Proc, 0);
    if (Dialog) {
        SetWindowLongA(Dialog, DWL_USER, (LONG)this);
        Init(settings);
        Show_Dialog(Dialog);
        while (Result < 0) {
            if (Dialog_Abort_Check() == true) {
                break;
            }
            Call_Back_5168E0(false);
        }
        End_Dialog(Dialog);
        if (Result == RESULT_OK) {
            *settings = Settings;
        }
    }
    return (Result == RESULT_OK) ? true : false;
}

BOOL CALLBACK SerialSettingsDialogClass::Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) {
        return result;
    }

    SerialSettingsDialogClass * self = (SerialSettingsDialogClass *)GetWindowLongA(dialog, DWL_USER);

    switch (message) {
        case WM_SERIAL_INIT:
        {
            HWND item = GetDlgItem(dialog, IDC_INIT_STRING_EDIT);
            if (item) {
                SendMessageA(item, EM_LIMITTEXT, MAX_INIT_STRING, 0);
            }
            item = GetDlgItem(dialog, IDC_PORT_EDIT);
            if (item) {
                SendMessageA(item, EM_LIMITTEXT, 0x3E, 0);
            }
            item = GetDlgItem(dialog, IDC_CALL_WAIT_EDIT);
            if (item) {
                SendMessageA(item, EM_LIMITTEXT, 0xF, 0);
            }
            break;
        }

        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case IDOK:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        if (self->Read_Settings() == true) {
                            self->Result = RESULT_OK;
                        }
                    }
                    break;

                case IDCANCEL:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        self->Result = RESULT_CANCEL;
                    }
                    break;

                case IDC_OPTION_3EA:
                    if (HIWORD(wparam) != BN_CLICKED) {
                        SendMessageA((HWND)lparam, BM_SETCHECK, BST_CHECKED, 0);
                    }
                    break;

                case IDC_OPTION_3EB:
                    if (HIWORD(wparam) != BN_CLICKED) {
                        SendMessageA((HWND)lparam, BM_SETCHECK, BST_CHECKED, 0);
                    }
                    break;

                case IDC_PORT:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        int index = SendMessageA((HWND)lparam, CB_GETCURSEL, 0, 0);
                        if (SendMessageA((HWND)lparam, CB_GETITEMDATA, index, 0) == PORT_CUSTOM) {
                            SendMessageA((HWND)lparam, CB_GETLBTEXT_NARROW, index, (LPARAM)self->Buffer);
                            self->Show_Custom_Edit(IDC_PORT_EDIT);
                        } else {
                            SetFocus(NULL);
                        }
                    }
                    break;

                case IDC_CALL_WAIT:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        int index = SendMessageA((HWND)lparam, CB_GETCURSEL, 0, 0);
                        if (SendMessageA((HWND)lparam, CB_GETITEMDATA, index, 0) == CALL_WAIT_CUSTOM) {
                            SendMessageA((HWND)lparam, CB_GETLBTEXT_NARROW, index, (LPARAM)self->Buffer);
                            self->Show_Custom_Edit(IDC_CALL_WAIT_EDIT);
                        } else {
                            SetFocus(NULL);
                        }
                    }
                    break;

                case IDC_CALL_WAIT_EDIT:
                    if (HIWORD(wparam) == EN_ENTER || HIWORD(wparam) == EN_KILLFOCUS) {
                        self->Call_Wait_Edit_Done();
                    }
                    break;

                case IDC_PULSE:
                    if (HIWORD(wparam) != BN_CLICKED) {
                        SendMessageA((HWND)lparam, BM_SETCHECK, BST_CHECKED, 0);
                        SendDlgItemMessageA(dialog, IDC_TONE, BM_SETCHECK, BST_UNCHECKED, 0);
                    }
                    break;

                case IDC_PORT_EDIT:
                    if (HIWORD(wparam) == EN_ENTER || HIWORD(wparam) == EN_KILLFOCUS) {
                        self->Port_Edit_Done();
                    }
                    break;

                case IDC_INIT_STRINGS:
                    if (HIWORD(wparam) == LBN_DBLCLK) {
                        if (SendMessageA((HWND)lparam, LB_GETCOUNT, 0, 0) > 0) {
                            int index = SendMessageA((HWND)lparam, LB_GETCURSEL, 0, 0);
                            if (index != LB_ERR) {
                                SendMessageA((HWND)lparam, LB_GETTEXT_NARROW, index, (LPARAM)self->Buffer);
                                HWND item = GetDlgItem(dialog, IDC_INIT_STRING_EDIT);
                                if (item) {
                                    SendMessageA(item, WM_SET_TEXT_NARROW, 0, (LPARAM)self->Buffer);
                                    SetFocus(item);
                                }
                            }
                        }
                    }
                    break;

                case IDC_INIT_STRING_EDIT:
                    if (HIWORD(wparam) == EN_ENTER) {
                        self->Add_Init_String();
                    }
                    break;

                case IDC_INIT_STRING_ADD:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        self->Add_Init_String();
                    }
                    break;

                case IDC_INIT_STRING_REMOVE:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        self->Remove_Init_String();
                    }
                    break;

                case IDC_TONE:
                    if (HIWORD(wparam) != BN_CLICKED) {
                        SendMessageA((HWND)lparam, BM_SETCHECK, BST_CHECKED, 0);
                        SendDlgItemMessageA(dialog, IDC_PULSE, BM_SETCHECK, BST_UNCHECKED, 0);
                    }
                    break;
            }
            break;
    }
    return FALSE;
}

bool SerialSettingsDialogClass::Read_Settings()
{
    Debug_Printf("Reading serial settings dialog\n");

    HWND item = GetDlgItem(Dialog, IDC_PORT);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        int data = SendMessageA(item, CB_GETITEMDATA, index, 0);
        Settings.Port = 1;
        Settings.ModemName[0] = '\0';
        switch (data) {
            case 0:
                Settings.Port = 0x3F8;
                break;

            case 1:
                Settings.Port = 0x2F8;
                break;

            case 2:
                Settings.Port = 0x3E8;
                break;

            case 3:
                Settings.Port = 0x2E8;
                break;

            case PORT_CUSTOM:
            {
                SendMessageA(item, CB_GETLBTEXT_NARROW, index, (LPARAM)Buffer);
                Buffer[0x3E] = '\0';
                char * text = strchr(Buffer, '-');
                if (text) {
                    strcpy(Settings.ModemName, text + 1);
                }
                break;
            }

            default:
                SendMessageA(item, CB_GETLBTEXT_NARROW, index, (LPARAM)Buffer);
                Buffer[0x3E] = '\0';
                strcpy(Settings.ModemName, Buffer);
                break;
        }
    }

    Debug_Printf("Port: %lx\n", Settings.Port);
    Debug_Printf("Modem: %s\n", Settings.ModemName);

    item = GetDlgItem(Dialog, IDC_BAUD);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        int data = SendMessageA(item, CB_GETITEMDATA, index, 0);
        swscanf(BaudNames[data], L"%d", &Settings.Baud);
    }
    Debug_Printf("Baud: %ld\n", Settings.Baud);

    item = GetDlgItem(Dialog, IDC_INIT_STRINGS);
    if (item) {
        int index = SendMessageA(item, LB_GETCURSEL, 0, 0);
        if (index != LB_ERR && SessionInitStrings.ActiveCount) {
            Settings.InitStringIndex = index;
        } else {
            Settings.InitStringIndex = -1;
        }
    }

    item = GetDlgItem(Dialog, IDC_CALL_WAIT);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        Settings.CallWaitStringIndex = SendMessageA(item, CB_GETITEMDATA, index, 0);
        Settings.CallWaitString[0] = '\0';
        if (Settings.CallWaitStringIndex == CALL_WAIT_CUSTOM) {
            SendMessageA(item, CB_GETLBTEXT_NARROW, index, (LPARAM)Buffer);
            Buffer[0xF] = '\0';
            char * text = strchr(Buffer, '-');
            if (text) {
                strcpy(Settings.CallWaitString, text + 1);
            }
        }
    }

    Settings.DialMethod = DIAL_TOUCH_TONE;
    item = GetDlgItem(Dialog, IDC_PULSE);
    if (item) {
        if (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) {
            Settings.DialMethod = DIAL_PULSE;
        }
    }
    Debug_Printf("DialMethod: %s\n", (Settings.DialMethod == DIAL_TOUCH_TONE) ? "Tone" : "Pulse");

    item = GetDlgItem(Dialog, IDC_OPTION_3EA);
    if (item) {
        if (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) {
            Settings.Option1C = 1;
        } else {
            Settings.Option1C = 0;
        }
    }

    item = GetDlgItem(Dialog, IDC_OPTION_3EB);
    if (item) {
        if (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) {
            Settings.Option18 = 1;
        } else {
            Settings.Option18 = 0;
        }
    }

    switch (NullModem.Detect_Port(&Settings)) {
        case PORT_VALID:
            return true;

        case PORT_INVALID:
#line 531 "C:\\RA2\\SerialEd.cpp"
            WWMessageBox().Process(Fetch_String("TXT_UNABLE_TO_OPEN_PORT", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            break;

        case PORT_IRQ_INUSE:
#line 535
            WWMessageBox().Process(Fetch_String("TXT_IRQ_ALREADY_IN_USE", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            break;
    }
    return false;
}

void SerialSettingsDialogClass::Init(SerialSettingsType * settings)
{
    Settings = *settings;

    if (Settings.Port == 0) {
        Settings.Port = 0x2F8;
    }
    if (Settings.IRQ == -1) {
        Settings.IRQ = 3;
    }
    if (Settings.Baud == -1) {
        Settings.Baud = 57600;
    }

    Build_Port_List();
    Build_Baud_List();
    Build_Call_Wait_List();
    Update_Dial_Method();

    if (!SessionInitStrings.ActiveCount) {
        char * temp = new char[8];
        strcpy(temp, "ATZ");
        SessionInitStrings.Add(temp);
        Settings.InitStringIndex = 0;
    }
    Build_Init_String_List();

    HWND item = GetDlgItem(Dialog, IDC_OPTION_3EB);
    if (item) {
        SendMessageA(item, BM_SETCHECK, settings->Option18 != 0, 0);
    }
    item = GetDlgItem(Dialog, IDC_OPTION_3EA);
    if (item) {
        SendMessageA(item, BM_SETCHECK, settings->Option1C != 0, 0);
    }
}

void SerialSettingsDialogClass::Build_Port_List()
{
    wchar_t buffer[128];

    HWND item = GetDlgItem(Dialog, IDC_PORT);
    if (item) {
        SendMessageA(item, CB_RESETCONTENT, 0, 0);
        for (int i = 0; i < 4; i++) {
#line 647
            int index = SendMessageA(item, CB_ADDSTRING_WIDE, 0, (LPARAM)Fetch_String(PortNames[i], NULL, __FILE__, __LINE__));
            SendMessageA(item, CB_SETITEMDATA, index, i);
        }

        ModemCount = 0;
        for (int modem = 0; modem < MAX_MODEMS; modem++) {
            ModemRegistryEntryClass * entry = new ModemRegistryEntryClass(modem);
            if (entry) {
                if (entry->Get_Modem_Name()) {
                    strncpy(ModemNames[ModemCount], entry->Get_Modem_Name(), MAX_MODEM_NAME);
                    int index = SendMessageA(item, CB_ADDSTRING_NARROW, 0, (LPARAM)ModemNames[ModemCount]);
                    SendMessageA(item, CB_SETITEMDATA, index, ModemCount + PORT_MODEM_FIRST);
                    ModemCount++;
                }
                delete entry;
            }
        }

#line 674
        wcscpy(buffer, Fetch_String("TXT_CUSTOM", NULL, __FILE__, __LINE__));
        int index = SendMessageA(item, CB_ADDSTRING_WIDE, 0, (LPARAM)buffer);
        SendMessageA(item, CB_SETITEMDATA, index, PORT_CUSTOM);
        SendMessageA(item, CB_SETCURSEL, 0, 0);

        if (strlen(Settings.ModemName)) {
            index = SendMessageA(item, CB_FINDSTRING_NARROW, -1, (LPARAM)Settings.ModemName);
            if (index == CB_ERR) {
                index = Find_Item_Data(item, -1, PORT_CUSTOM);
                if (index != -1) {
#line 692
                    swprintf(buffer, L"%s %hs", Fetch_String("TXT_CUSTOM", NULL, __FILE__, __LINE__), Settings.ModemName);
                    SendMessageA(item, CB_DELETESTRING, index, 0);
                    index = SendMessageA(item, CB_ADDSTRING_WIDE, 0, (LPARAM)buffer);
                    SendMessageA(item, CB_SETITEMDATA, index, PORT_CUSTOM);
                }
            }
            SendMessageA(item, CB_SETCURSEL, index, 0);
            return;
        } else {
            switch (Settings.Port) {
                case 0x3F8:
                    index = Find_Item_Data(item, -1, 0);
                    break;

                case 0x2F8:
                    index = Find_Item_Data(item, -1, 1);
                    break;

                case 0x3E8:
                    index = Find_Item_Data(item, -1, 2);
                    break;

                case 0x2E8:
                    index = Find_Item_Data(item, -1, 3);
                    break;

                default:
                {
                    wchar_t custom[128];
                    index = Find_Item_Data(item, -1, PORT_CUSTOM);
                    if (index != -1) {
#line 730
                        swprintf(custom, L"%s %x", Fetch_String("TXT_CUSTOM", NULL, __FILE__, __LINE__), Settings.Port);
                        SendMessageA(item, CB_DELETESTRING, index, 0);
                        index = SendMessageA(item, CB_ADDSTRING_WIDE, 0, (LPARAM)custom);
                        SendMessageA(item, CB_SETITEMDATA, index, PORT_CUSTOM);
                    }
                    break;
                }
            }
        }
        SendMessageA(item, CB_SETCURSEL, index, 0);
    }
}

void SerialSettingsDialogClass::Build_Baud_List()
{
    HWND item = GetDlgItem(Dialog, IDC_BAUD);
    if (item) {
        SendMessageA(item, CB_RESETCONTENT, 0, 0);
        for (int i = 0; i < 6; i++) {
            wchar_t const * name = BaudNames[i];
            int index = SendMessageA(item, CB_ADDSTRING_WIDE, 0, (LPARAM)name);
            SendMessageA(item, CB_SETITEMDATA, index, i);
        }

        int baud;
        switch (Settings.Baud) {
            case 14400:
                baud = 0;
                break;

            case 19200:
                baud = 1;
                break;

            case 28800:
                baud = 2;
                break;

            default:
                baud = 3;
                break;

            case 57600:
                baud = 4;
                break;

            case 115200:
                baud = 5;
                break;
        }
        int index = Find_Item_Data(item, -1, baud);
        SendMessageA(item, CB_SETCURSEL, index, 0);
    }
}

void SerialSettingsDialogClass::Build_Call_Wait_List()
{
    HWND item = GetDlgItem(Dialog, IDC_CALL_WAIT);
    if (item) {
        SendMessageA(item, CB_RESETCONTENT, 0, 0);
        for (int i = 0; i < 4; i++) {
            wchar_t const * name = SessionCallWaitStrings[i];
            int index = SendMessageA(item, CB_ADDSTRING_WIDE, 0, (LPARAM)name);
            SendMessageA(item, CB_SETITEMDATA, index, i);
        }
        int index = Find_Item_Data(item, -1, Settings.CallWaitStringIndex);
        SendMessageA(item, CB_SETCURSEL, index, 0);
    }
}

void SerialSettingsDialogClass::Build_Init_String_List()
{
    HWND item = GetDlgItem(Dialog, IDC_INIT_STRINGS);
    if (item) {
        SendMessageA(item, LB_RESETCONTENT, 0, 0);
        for (int i = 0; i < SessionInitStrings.ActiveCount; i++) {
            SendMessageA(item, LB_ADDSTRING_NARROW, 0, (LPARAM)SessionInitStrings[i]);
        }

        if (SendMessageA(item, LB_GETCOUNT, 0, 0) && Settings.InitStringIndex >= -1) {
            if (Settings.InitStringIndex >= SendMessageA(item, LB_GETCOUNT, 0, 0)) {
                Settings.InitStringIndex = 0;
            }
        } else {
            Settings.InitStringIndex = -1;
        }

        if (Settings.InitStringIndex != -1) {
            SendMessageA(item, LB_SETCURSEL, Settings.InitStringIndex, 0);
        }
    }
}

void SerialSettingsDialogClass::Update_Dial_Method()
{
    bool tone = (Settings.DialMethod == DIAL_TOUCH_TONE);

    HWND item = GetDlgItem(Dialog, IDC_TONE);
    if (item) {
        SendMessageA(item, BM_SETCHECK, tone == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_PULSE);
    if (item) {
        SendMessageA(item, BM_SETCHECK, tone == false, 0);
    }
}

void SerialSettingsDialogClass::Show_Custom_Edit(int id)
{
    HWND item = GetDlgItem(Dialog, id);
    if (item) {
        ShowWindow(item, SW_SHOW);
        EnableWindow(item, TRUE);
        char * text = strchr(Buffer, '-');
        if (text) {
            text++;
            strtrim(text);
        } else {
            text = EmptyString;
        }
        SendMessageA(item, WM_SET_TEXT_NARROW, 0, (LPARAM)text);
        SetFocus(item);
    }
}

void SerialSettingsDialogClass::Port_Edit_Done()
{
    HWND combo = GetDlgItem(Dialog, IDC_PORT);
    HWND edit = GetDlgItem(Dialog, IDC_PORT_EDIT);
    if (combo && edit) {
        ShowWindow(edit, SW_HIDE);
        EnableWindow(edit, FALSE);
        SendMessageA(edit, WM_GET_TEXT_NARROW, 0x40, (LPARAM)Buffer);
        Buffer[0x3F] = '\0';
        strtrim(Buffer);
        _strupr(Buffer);

        int port;
        if (stricmp(Buffer, "3F8")) {
            if (!stricmp(Buffer, "2F8")) {
                port = 1;
            } else if (!stricmp(Buffer, "3E8")) {
                port = 2;
            } else if (!stricmp(Buffer, "2E8")) {
                port = 3;
            } else {
                if (!strncmp(Buffer, "COM", 3)) {
                    switch (Buffer[3]) {
                        case '1':
                            port = 0;
                            goto found;

                        case '2':
                            port = 1;
                            goto found;

                        case '3':
                            port = 2;
                            goto found;

                        case '4':
                            port = 3;
                            goto found;

                        default:
                            if (Buffer[3] <= '9' && Buffer[3] > '0') {
                                Buffer[4] = '\0';
                            } else {
#line 1088
                    WWMessageBox().Process(Fetch_String("TXT_INVALID_PORT_ADDRESS", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                                return;
                            }
                            break;
                    }
                }
                Set_Custom_Item(IDC_PORT, PORT_CUSTOM, Buffer);
                return;
            }
        } else {
            port = 0;
        }
found:
        int index = Find_Item_Data(combo, -1, port);
        SendMessageA(combo, CB_SETCURSEL, index, 0);
    }
}

void SerialSettingsDialogClass::Call_Wait_Edit_Done()
{
    HWND edit = GetDlgItem(Dialog, IDC_CALL_WAIT_EDIT);
    if (edit) {
        ShowWindow(edit, SW_HIDE);
        EnableWindow(edit, FALSE);
        SendMessageA(edit, WM_GET_TEXT_NARROW, 0x10, (LPARAM)Buffer);
        Buffer[0xF] = '\0';
        strtrim(Buffer);
        _strupr(Buffer);
        Set_Custom_Item(IDC_CALL_WAIT, CALL_WAIT_CUSTOM, Buffer);
    }
}

void SerialSettingsDialogClass::Set_Custom_Item(int id, int data, char * text)
{
    char buffer[0x80];

    HWND item = GetDlgItem(Dialog, id);
    if (item) {
        int index = Find_Item_Data(item, -1, data);
        SendMessageA(item, CB_GETLBTEXT_NARROW, index, (LPARAM)buffer);
        char * old = strchr(buffer, '-');
        if (old) {
            if (stricmp(text, old + 1)) {
#line 1187
                sprintf(buffer, "%ls ", Fetch_String("TXT_CUSTOM", NULL, __FILE__, __LINE__));
                strcat(buffer, text);
                SendMessageA(item, CB_DELETESTRING, index, 0);
                index = SendMessageA(item, CB_ADDSTRING_NARROW, 0, (LPARAM)buffer);
                SendMessageA(item, CB_SETITEMDATA, index, data);
                SendMessageA(item, CB_SETCURSEL, index, 0);
            }
        }
    }
}

void SerialSettingsDialogClass::Add_Init_String()
{
    HWND edit = GetDlgItem(Dialog, IDC_INIT_STRING_EDIT);
    HWND list = GetDlgItem(Dialog, IDC_INIT_STRINGS);
    if (edit && list) {
        SendMessageA(edit, WM_GET_TEXT_NARROW, sizeof(Buffer), (LPARAM)Buffer);
        SendMessageA(edit, WM_SET_TEXT_NARROW, 0, (LPARAM)EmptyString);
        strtrim(Buffer);
        if (strlen(Buffer)) {
            _strupr(Buffer);
            int index = SendMessageA(list, LB_FINDSTRING_NARROW, -1, (LPARAM)Buffer);
            if (index == LB_ERR) {
                char * temp = new char[MAX_INIT_STRING + 1];
                strcpy(temp, Buffer);
                index = SendMessageA(list, LB_ADDSTRING_NARROW, 0, (LPARAM)temp);
                if (index == LB_ERR) {
                    return;
                }
                SessionInitStrings.Add(temp);
            }
            SendMessageA(list, LB_SETCURSEL, index, 0);
            SendMessageA(list, LB_SETTOPINDEX, index, 0);
            Settings.InitStringIndex = index;
        }
    }
}

void SerialSettingsDialogClass::Remove_Init_String()
{
    HWND list = GetDlgItem(Dialog, IDC_INIT_STRINGS);
    if (list) {
        if (SendMessageA(list, LB_GETCOUNT, 0, 0) > 0) {
            int index = SendMessageA(list, LB_GETCURSEL, 0, 0);
            if (index != LB_ERR) {
                SendMessageA(list, LB_DELETESTRING, index, 0);
                SessionInitStrings.Delete(index);
                if (index >= SendMessageA(list, LB_GETCOUNT, 0, 0)) {
                    index--;
                }
                SendMessageA(list, LB_SETCURSEL, index, 0);
                SendMessageA(list, LB_SETTOPINDEX, index, 0);
                Settings.InitStringIndex = index;
            }
        }
    }
}
