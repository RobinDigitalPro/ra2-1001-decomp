// C:\RA2\NullDlg.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Serial (null modem) and modem game support: the serial selection dialog, port checks,
// modem dial/answer, connection test and teardown. Class names come from RTTI where a vtable
// exists (NullModemClass, WinModemClass, HouseClass); all other class, method and variable
// names are provisional (Westwood style).
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include "SURFACE.H"
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
void Wide_To_Narrow(char * dest, wchar_t const * src, int length);  // 0x6eed90 (name provisional)

// Dialog support (see also Restate.cpp / GameDlg.CPP).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Move_Window(HWND dialog, int x, int y);    // 0x5f7dc0, defined in ownrdraw.cpp (x = -1: centre)
HWND Create_Cancel_Dialog(wchar_t const * text, wchar_t const * button, bool * cancelled);  // 0x5f7e80 (provisional)
void Call_Back_5168E0(bool flag);       // 0x5168e0, called while the dialog runs (meaning unknown)

// Main window and surface used to position the dialog.
extern HWND MainWindow;                         // 0xb0de50 (name provisional)
extern Surface * HiddenSurface;                // 0x821c94

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624).
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
    operator long() const { return Value(); }

    long Started;
    T Timer;
    long Accumulated;
};
extern TTimerClass<SystemTimerClass> TickCount;     // 0x821cc0 (name provisional)

// Count-down timer (only used as a local here).
template<class T>
class CDTimerClass {
public:
    CDTimerClass(long set = 0) : Started(Timer()), DelayTime(set) {}
    long Value() const
    {
        long remain = DelayTime;
        if (Started != -1) {
            long value = Timer() - Started;
            if (value < remain) {
                return remain - value;
            }
            return 0;
        }
        return remain;
    }
    operator long() const { return Value(); }

    long Started;
    T Timer;
    long DelayTime;
};

// Serial port settings (Session + 0x282c and the phone book entries); only the fields used here.
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
    char ModemName[1];                          // +0x30
};

class PhoneEntryClass {
public:
    SerialSettingsType Settings;                // +0x00
    char Unknown31[0x9A - sizeof(SerialSettingsType)];
    char Number[1];                             // +0x9a
};

enum { CALL_WAIT_CUSTOM = 3 };

// Serial game packet, 0xfa bytes; only the fields used here.
#pragma pack(push, 1)
struct SerialPacketType {
    int Command;                                // +0x00, 100 = connect request
    char Unknown04[0x18 - 0x04];
    unsigned char ID;                           // +0x18
    char Unknown19[0x92 - 0x19];
    int Time;                                   // +0x92
    char Unknown96[0xFA - 0x96];
};

// Event record, 0x6f bytes; only the type byte is used here.
class EventClass {
public:
    EventClass() : Type(0) {}
    unsigned char Type;
    unsigned char Data[0x6F - 1];
};
#pragma pack(pop)

enum { SERIAL_CONNECT = 100 };
enum { EVENT_EXIT = 0x13 };
enum { CTS_SET = 0x10, DSR_SET = 0x20, RI_SET = 0x40, CD_SET = 0x80 };
enum DialStatusType { DIAL_CONNECTED, DIAL_NO_CARRIER, DIAL_BUSY, DIAL_ERROR, DIAL_NO_DIAL_TONE, DIAL_TIMEOUT, DIAL_CANCELLED };

// RTTI .?AVNullModemClass@@ (vtable 0x7923d4, 16 slots). The global object is always called
// directly, so only the members used here are declared, without the virtual slots.
class NullModemClass {
public:
    virtual ~NullModemClass();
    int Init(int port, int irq, char * dev_name, int baud, char parity, int wordlength, int stopbits);  // 0x5c8770
    void Delete_Connection();                   // 0x5c89f0
    int Detect_Port(SerialSettingsType * settings);    // 0x5c8a70, 0 = valid
    void Shutdown();                            // 0x5c8c00
    int Send_Message(void * buf, int buflen, int ack_req);  // 0x5c8c80
    int Get_Message(void * buf, int * buflen);  // 0x5c8cc0
    int Service();                              // 0x5c8cf0
    int Num_Send();                             // 0x5c8f30 (name provisional)
    bool Detect_Modem(SerialSettingsType * settings, bool reconnect);   // 0x5c9030
    int Dial_Modem(char * string, DialMethodType method, bool reconnect);   // 0x5c99e0
    int Answer_Modem(bool reconnect);           // 0x5c9d70
    void Hangup_Modem();                        // 0x5ca200
    void Setup_Modem_Echo(void (*func)(char c));    // 0x5ca3b0
    void Remove_Modem_Echo();                   // 0x5ca3d0
    void Print_EchoBuf();                       // 0x5ca3e0
    void Reset_EchoBuf();                       // 0x5ca430
    void Change_IRQ_Priority(int irq);          // 0x5ca4d0 (name provisional)
    int Get_Modem_Status();                     // 0x5ca4e0

    char Unknown04[0x0C - 0x04];
    char * EchoBuf;                             // +0x0c
    int EchoSize;                               // +0x10
    int EchoCount;                              // +0x14
};
extern NullModemClass NullModem;                // 0xa28668

// RTTI .?AVWinModemClass@@ (vtable 0x79a370, 10 slots), object size 0x2088.
class WinModemClass {
public:
    WinModemClass();                            // 0x728ce0
    virtual ~WinModemClass();                   // deleting destructor is slot 0
    void Write_To_Serial_Port(char const * buffer, int length);   // 0x729830
    HANDLE Get_Port_Handle();                   // 0x72a080
private:
    char Data[0x2088 - 4];
};
extern WinModemClass * SerialPort;              // 0xb0d628

// Dialog objects of other files, used as locals without constructors (names provisional).
class ModemHostDialogClass {                    // ModemHst.cpp
public:
    bool Process();                             // 0x595c10
    char Data[0x60];
};
class ModemGuestDialogClass {                   // ModemGst.cpp
public:
    bool Process();                             // 0x592e10
    char Data[0x5C];
};
class PhoneBookDialogClass {                    // PhoneEd.cpp
public:
    bool Process();                             // 0x605550
    char Data[0x8C];
};
class SerialSettingsDialogClass {               // SerialEd.cpp
public:
    bool Process(SerialSettingsType * settings);    // 0x663660
    char Data[0x374];
};

// RTTI .?AVHouseClass@@; only the fields and the method used here.
class HouseTypeClass {
public:
    char Unknown00[0xC0];
    int ColorScheme;                            // +0xc0 (meaning provisional)
};
class HouseClass {
public:
    void Func_4F3570();                         // 0x4f3570 (meaning unknown, called on a departing house)

    char Unknown00[0x34];
    HouseTypeClass * Class;                     // +0x34
    char Unknown38[0x134 - 0x38];
    bool IsHuman;                               // +0x134
    char Unknown135[0x15F16 - 0x135];
    wchar_t UIName[1];                          // +0x15f16
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8

struct NodeNameType {
    wchar_t Name[20];                           // +0x00 (assumed)
};

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};

class RulesClass {
public:
    char Unknown00[0x1128];
    double MessageDelay;                        // +0x1128, minutes
};
extern RulesClass * Rule;                       // 0x821b88

class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);  // 0x4e0030
    virtual void Virtual_15();                  // 0x4e01c0 (slot 15; called directly here)
};
class MouseClass : public GScreenClass {
};
extern MouseClass Map;                          // 0x81a820

// Session object at 0xa255c8; members used here are separate globals (offsets in comments).
enum GameType { GAME_NORMAL, GAME_MODEM, GAME_NULL_MODEM };
enum ModemGameType { MODEM_NULL_HOST, MODEM_NULL_JOIN, MODEM_DIALER, MODEM_ANSWERER };
class SessionClass {
public:
    void Write_MultiPlayer_Settings();          // 0x666d70 (name provisional)

    GameType Type;                              // +0x0000
};
extern SessionClass Session;                    // 0xa255c8
extern int SessionUniqueID;                     // 0xa256e4  (Session + 0x11c, meaning provisional)
extern int SessionNumPlayers;                   // 0xa2588c  (Session + 0x2c4)
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)
extern unsigned char SessionRecordFlags;        // 0xa27928  (Session + 0x2360, bit 1 = playback, provisional)
extern DynamicVectorClass<NodeNameType *> SessionPlayers;  // 0xa27da8 (Session + 0x27e0)
struct SessionModemFlagsType {
    unsigned ModemService : 1;
};
extern SessionModemFlagsType SessionModemFlags; // 0xa27dec  (Session + 0x2824)
extern int SessionCurPhoneIdx;                  // 0xa27df0  (Session + 0x2828)
extern SerialSettingsType SessionSerialSettings;    // 0xa27df4 (Session + 0x282c)
extern ModemGameType SessionModemGameToPlay;    // 0xa27e64  (Session + 0x289c)
extern DynamicVectorClass<PhoneEntryClass *> SessionPhoneBook;  // 0xa27e68 (Session + 0x28a0)
extern DynamicVectorClass<wchar_t *> SessionCallWaitStrings;    // 0xa27e98 (Session + 0x28d0)

enum { RECORD_PLAYBACK = 2 };

// Globals of this file (probably defined here; kept extern until the data layout is bound).
extern char DialString[];                       // 0xa5a8e0
extern SerialSettingsType * DialSettings;       // 0xa5a92c
extern bool ConnectCancelled;                   // 0xa5aa2c (set by the cancel dialog)

BOOL CALLBACK Serial_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);
void Update_Serial_Buttons(HWND dialog);
bool Init_Null_Modem(SerialSettingsType * settings);
bool Test_Null_Modem();
void Modem_Echo(char c);
bool Dial_Modem(SerialSettingsType * settings, bool reconnect);
bool Answer_Modem(SerialSettingsType * settings, bool reconnect);

// ---- end of local declarations ----

#define IDD_SELECT_SERIAL   0xEC
#define IDC_SERIAL_651      0x651
#define IDC_SERIAL_652      0x652
#define IDC_SERIAL_653      0x653
#define IDC_SERIAL_654      0x654
#define IDC_SERIAL_655      0x655
#define WM_SERIAL_INIT      (WM_USER + 0x97)

// level-2 1.001: INFERRED local name; the reference names this handshake Test_Null_Modem.
static int Test_Serial_Cable()
{
    int result = 0;
    bool process = true;
    unsigned long starttime;
    int packetlen;
    char buffer[80 * 3];
    SerialPacketType sendpacket;
    SerialPacketType receivepacket;

    SetCommBreak(SerialPort->Get_Port_Handle());
    SerialPort->Write_To_Serial_Port("ATH\r", strlen("ATH\r"));
    CDTimerClass<SystemTimerClass> timer;
    timer = 120;
    while (timer.Value()) {
    }
    ClearCommBreak(SerialPort->Get_Port_Handle());
    EscapeCommFunction(SerialPort->Get_Port_Handle(), CLRDTR);

    starttime = TickCount.Value();
    while ((unsigned long)TickCount.Value() - starttime < 80) {
        NullModem.Service();
        if (NullModem.Get_Message(&receivepacket, &packetlen) > 0 && receivepacket.Command == SERIAL_CONNECT) {
            starttime = TickCount.Value();
            while ((unsigned long)TickCount.Value() - starttime < 30) {
                NullModem.Service();
            }
            process = false;
            result = 2;
            break;
        }
    }

    memset(&sendpacket, 0, sizeof(SerialPacketType));
    if (process == true) {
        sendpacket.Command = SERIAL_CONNECT;
        sendpacket.Time = TickCount;
        sendpacket.ID = (unsigned char)(int)buffer;
        NullModem.Send_Message(&sendpacket, sizeof(SerialPacketType), 1);

        starttime = TickCount;
        while ((unsigned long)TickCount - starttime < 80) {
            NullModem.Service();
            if (NullModem.Get_Message(&receivepacket, &packetlen) > 0 && receivepacket.Command == SERIAL_CONNECT) {
                starttime = TickCount;
                while ((unsigned long)TickCount - starttime < 30) {
                    NullModem.Service();
                }
                if (receivepacket.Time > sendpacket.Time) {
                    process = false;
                    result = 2;
                } else if (receivepacket.Time == sendpacket.Time) {
                    if (receivepacket.ID > sendpacket.ID) {
                        process = false;
                        result = 2;
                    } else if (receivepacket.ID == sendpacket.ID) {
                        process = false;
                        result = 3;
                    }
                }
                break;
            }
        }

        if (process) {
            ConnectCancelled = false;
#line 6293 "C:\\RA2\\NullDlg.CPP"
            HWND waitdialog = Create_Cancel_Dialog(Fetch_String("TXT_WAITING_CONNECT", NULL, __FILE__, __LINE__), Fetch_String("TXT_CANCEL", NULL, __FILE__, __LINE__), &ConnectCancelled);
            if (waitdialog) {
                Show_Dialog(waitdialog);
                starttime = TickCount;
                while (true) {
                    if (Dialog_Abort_Check() == true || ConnectCancelled) {
                        result = 0;
                        break;
                    }
                    Call_Back_5168E0(false);
                    NullModem.Service();
                    if (NullModem.Num_Send() == 0) {
                        if (NullModem.Get_Message(&receivepacket, &packetlen) > 0) {
                            if (receivepacket.Command == SERIAL_CONNECT) {
                                starttime = TickCount;
                                while ((unsigned long)TickCount - starttime < 30) {
                                    NullModem.Service();
                                }
                                if (receivepacket.Time > sendpacket.Time) {
                                    process = false;
                                    result = 2;
                                } else if (receivepacket.Time == sendpacket.Time) {
                                    if (receivepacket.ID > sendpacket.ID) {
                                        process = false;
                                        result = 2;
                                    } else if (receivepacket.ID == sendpacket.ID) {
                                        process = false;
                                        result = 3;
                                    }
                                }
                            } else {
                                result = 0;
                                process = false;
                            }
                        } else {
                            result = 1;
                            process = false;
                        }
                    }
                    if ((unsigned long)TickCount - starttime > 3600) {
                        result = 0;
                        break;
                    }
                    if (process != true) {
                        break;
                    }
                }
                End_Dialog(waitdialog);
            }
        }
    }
    return result;
}

int Select_Serial_Dialog()
{
    int selection = -1;
    int retval = -1;

    HWND dialog = Create_Dialog(IDD_SELECT_SERIAL, Serial_Dialog_Proc, 0);
    if (dialog) {
        SetWindowLongA(dialog, DWL_USER, (LONG)&selection);
        Move_Window(dialog, -1, (HiddenSurface->Get_Height() - 400) / 2 + 0x93);
        Show_Dialog(dialog);

        if (SessionSerialSettings.Port == 0 || SessionSerialSettings.IRQ == -1 || SessionSerialSettings.Baud == -1
            || NullModem.Detect_Port(&SessionSerialSettings)) {
            selection = IDC_SERIAL_652;
        }

        while (retval == -1) {
            while (selection < 0) {
                if (Dialog_Abort_Check() == true) {
                    break;
                }
                Call_Back_5168E0(false);
            }

            switch (selection) {
                case IDC_SERIAL_653:
                    ShowWindow(dialog, SW_HIDE);
                    UpdateWindow(MainWindow);
                    if (PhoneBookDialogClass().Process() == true) {
                        SerialSettingsType * settings = &SessionPhoneBook[SessionCurPhoneIdx]->Settings;
                        if (settings->Port == 0) {
                            settings = &SessionSerialSettings;
                        }

                        if (SerialPort) {
                            delete SerialPort;
                        }
                        SerialPort = new WinModemClass;

                        if (Init_Null_Modem(settings)) {
                            if (settings->CallWaitStringIndex == CALL_WAIT_CUSTOM) {
                                strcpy(DialString, settings->CallWaitString);
                            } else {
                                Wide_To_Narrow(DialString, SessionCallWaitStrings[settings->CallWaitStringIndex], -1);
                            }
                            strcat(DialString, SessionPhoneBook[SessionCurPhoneIdx]->Number);

                            if (Dial_Modem(settings, false)) {
                                SessionModemGameToPlay = MODEM_DIALER;
                                Session.Type = GAME_MODEM;
                                if (ModemHostDialogClass().Process()) {
                                    retval = 1;
                                    break;
                                }
                                Session.Type = GAME_NORMAL;
                                retval = 0;
                            }
                            NullModem.Change_IRQ_Priority(0);
                        } else {
#line 5798 "C:\\RA2\\NullDlg.CPP"
                            WWMessageBox().Process(Fetch_String("TXT_SELECT_SETTINGS", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                        }
                    }
                    ShowWindow(dialog, SW_SHOW);
                    break;

                case IDC_SERIAL_654:
                    ShowWindow(dialog, SW_HIDE);
                    UpdateWindow(MainWindow);

                    if (SerialPort) {
                        delete SerialPort;
                    }
                    SerialPort = new WinModemClass;

                    if (Init_Null_Modem(&SessionSerialSettings)) {
                        if (Answer_Modem(&SessionSerialSettings, false)) {
                            SessionModemGameToPlay = MODEM_ANSWERER;
                            Session.Type = GAME_MODEM;
                            if (ModemGuestDialogClass().Process()) {
                                retval = 1;
                                break;
                            }
                            Session.Type = GAME_NORMAL;
                            retval = 0;
                        }
                        NullModem.Change_IRQ_Priority(0);
                    } else {
#line 5833
                        WWMessageBox().Process(Fetch_String("TXT_SELECT_SETTINGS", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    }
                    ShowWindow(dialog, SW_SHOW);
                    break;

                case IDC_SERIAL_655:
                    ShowWindow(dialog, SW_HIDE);
                    UpdateWindow(MainWindow);

                    if (NullModem.Init(SessionSerialSettings.Port, SessionSerialSettings.IRQ, SessionSerialSettings.ModemName, SessionSerialSettings.Baud, 0, 8, 1)) {
                        switch (Test_Serial_Cable()) {
                            case 1:
                                SessionModemGameToPlay = MODEM_NULL_HOST;
                                Session.Type = GAME_NULL_MODEM;
                                if (ModemHostDialogClass().Process() == true) {
                                    retval = 2;
                                    break;
                                }
                                Session.Type = GAME_NORMAL;
                                break;

                            case 2:
                                SessionModemGameToPlay = MODEM_NULL_JOIN;
                                Session.Type = GAME_NULL_MODEM;
                                if (ModemGuestDialogClass().Process() == true) {
                                    retval = 2;
                                    break;
                                }
                                Session.Type = GAME_NORMAL;
                                break;

                            case 3:
#line 5868
                                WWMessageBox().Process(Fetch_String("TXT_MODEM_OR_LOOPBACK", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                                break;
                        }

                        if (retval == -1) {
                            NullModem.Change_IRQ_Priority(0);
                            ShowWindow(dialog, SW_SHOW);
                        }
                        break;
                    }
#line 5877
                    WWMessageBox().Process(Fetch_String("TXT_SELECT_SETTINGS", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    ShowWindow(dialog, SW_SHOW);
                    break;

                case IDC_SERIAL_652:
                    ShowWindow(dialog, SW_HIDE);
                    UpdateWindow(MainWindow);
                    if (SerialSettingsDialogClass().Process(&SessionSerialSettings)) {
                        Session.Write_MultiPlayer_Settings();
                    }
                    Update_Serial_Buttons(dialog);
                    ShowWindow(dialog, SW_SHOW);
                    break;

                default:
                    retval = 0;
                    break;
            }

            selection = -1;
        }

        End_Dialog(dialog);
        return retval;
    }
    return 0;
}

BOOL CALLBACK Serial_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) {
        return result;
    }

    switch (message) {
        case WM_SERIAL_INIT:
            Update_Serial_Buttons(dialog);
            return FALSE;

        case WM_COMMAND:
        {
            int * selection = (int *)GetWindowLongA(dialog, DWL_USER);
            if (wparam == IDCANCEL || (wparam > IDC_SERIAL_651 && wparam <= IDC_SERIAL_655)) {
                *selection = wparam;
            }
            break;
        }
    }
    return FALSE;
}

void Update_Serial_Buttons(HWND dialog)
{
    bool valid = true;
    if (SessionSerialSettings.Port == 0) {
        valid = false;
    } else if (SessionSerialSettings.IRQ == -1) {
        valid = false;
    } else if (SessionSerialSettings.Baud == -1) {
        valid = false;
    } else if (NullModem.Detect_Port(&SessionSerialSettings)) {
        valid = false;
    }

    HWND item = GetDlgItem(dialog, IDC_SERIAL_653);
    if (item) {
        EnableWindow(item, valid);
    }
    item = GetDlgItem(dialog, IDC_SERIAL_654);
    if (item) {
        EnableWindow(item, valid);
    }
    item = GetDlgItem(dialog, IDC_SERIAL_655);
    if (item) {
        EnableWindow(item, valid);
    }
}

bool Init_Null_Modem(SerialSettingsType * settings)
{
    if (NullModem.Init(settings->Port, settings->IRQ, settings->ModemName, settings->Baud, 0, 8, 1)) {
        return true;
    }
    return false;
}

void Shutdown_Modem()
{
    if (!(SessionRecordFlags & RECORD_PLAYBACK)) {
        if (Session.Type == GAME_MODEM) {
            NullModem.Hangup_Modem();
        }
    }
    NullModem.Shutdown();
}

void Modem_Signoff()
{
    unsigned long starttime;
    EventClass event;

    if (!(SessionRecordFlags & RECORD_PLAYBACK)) {
        memset(&event, 0, sizeof(EventClass));
        event.Type = EVENT_EXIT;
        NullModem.Send_Message(&event, sizeof(EventClass), 0);
        NullModem.Send_Message(&event, sizeof(EventClass), 0);

        starttime = TickCount.Value();
        while ((unsigned long)TickCount.Value() - starttime < 30) {
            NullModem.Service();
        }
    }
}

bool Reconnect_Modem()
{
    bool retval = false;

    switch (SessionModemGameToPlay) {
        case MODEM_NULL_HOST:
        case MODEM_NULL_JOIN:
            retval = Test_Null_Modem();
            break;

        case MODEM_DIALER:
            if (NullModem.Get_Modem_Status() & CD_SET) {
                retval = Test_Null_Modem();
            } else {
                retval = Dial_Modem(DialSettings, true);
            }
            break;

        case MODEM_ANSWERER:
            if (NullModem.Get_Modem_Status() & CD_SET) {
                retval = Test_Null_Modem();
            } else {
                retval = Answer_Modem(DialSettings, true);
            }
            break;
    }
    return retval;
}

void Destroy_Null_Connection(int id, int error)
{
    HouseClass * housep;
    wchar_t txt[80];

    if (SessionNumPlayers == 1) {
        return;
    }

    housep = Houses[id];
    if (!housep || !housep->IsHuman) {
        return;
    }

    txt[0] = 0;
    switch (error) {
        case 1:
#line 6412
            swprintf(txt, Fetch_String("TXT_CONNECTION_LOST", NULL, __FILE__, __LINE__), housep->UIName);
            break;

        case 0:
#line 6416
            swprintf(txt, Fetch_String("TXT_LEFT_GAME", NULL, __FILE__, __LINE__), housep->UIName);
            break;

        case -1:
            NullModem.Delete_Connection();
            break;
    }

    if (wcslen(txt)) {
        SessionMessages.Add_Message(NULL, 0, txt, housep->Class->ColorScheme, 0x4046,
            (int)(Rule->MessageDelay * 900), false);
        Map.Flag_To_Redraw(false);
    }

    for (int i = 0; i < SessionPlayers.ActiveCount; i++) {
        if (!_wcsicmp(SessionPlayers[i]->Name, housep->UIName)) {
            delete SessionPlayers[i];
            SessionPlayers.Delete(SessionPlayers[i]);
            break;
        }
    }

    housep->Func_4F3570();

    SessionNumPlayers--;
    if (SessionNumPlayers == 1) {
#line 6453
        swprintf(txt, L"%s", Fetch_String("TXT_JUST_YOU_AND_ME", NULL, __FILE__, __LINE__));
        SessionMessages.Add_Message(NULL, 0, txt, housep->Class->ColorScheme, 0x4046,
            (int)(Rule->MessageDelay * 900), false);
        Map.Flag_To_Redraw(false);
    }
}

bool Test_Null_Modem()
{
    bool process = true;
    bool retval = false;
    unsigned long timer;
    unsigned long starttime;
    int packetlen;
    SerialPacketType sendpacket;
    SerialPacketType receivepacket;

    ConnectCancelled = false;
#line 6489
    HWND dialog = Create_Cancel_Dialog(Fetch_String("TXT_NULL_CONNERR_CHECK_CABLES", NULL, __FILE__, __LINE__), Fetch_String("TXT_CANCEL", NULL, __FILE__, __LINE__), &ConnectCancelled);
    if (dialog) {
        Show_Dialog(dialog);

        timer = TickCount.Value();
        starttime = timer;
        while (process == true) {
            if (Dialog_Abort_Check() == true || ConnectCancelled) {
                retval = false;
                break;
            }

            NullModem.Service();

            if ((unsigned long)TickCount.Value() - starttime > 30) {
                starttime = TickCount.Value();
                memset(&sendpacket, 0, sizeof(SerialPacketType));
                sendpacket.Command = SERIAL_CONNECT;
                sendpacket.ID = SessionUniqueID;
                NullModem.Send_Message(&sendpacket, sizeof(SerialPacketType), 0);
            }

            if (NullModem.Get_Message(&receivepacket, &packetlen) > 0) {
                timer = TickCount.Value();
                if (receivepacket.Command == SERIAL_CONNECT) {
                    if (receivepacket.ID == SessionUniqueID) {
#line 6530
                        WWMessageBox().Process(Fetch_String("TXT_SYSTEM_NOT_RESPONDING", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                        retval = false;
                        break;
                    }
                    memset(&sendpacket, 0, sizeof(SerialPacketType));
                    sendpacket.Command = SERIAL_CONNECT;
                    sendpacket.ID = SessionUniqueID;
                    NullModem.Send_Message(&sendpacket, sizeof(SerialPacketType), 1);

                    starttime = TickCount.Value();
                    while ((unsigned long)TickCount.Value() - starttime < 60) {
                        NullModem.Service();
                    }
                    retval = true;
                    process = false;
                }
            }

            if ((unsigned long)TickCount.Value() - timer > 900) {
                retval = false;
                break;
            }
        }

        End_Dialog(dialog);
    }
    return retval;
}

bool Dial_Modem(SerialSettingsType * settings, bool reconnect)
{
    bool connected = false;
    int status;
    int modemstatus;

    Debug_Printf("Dial Modem\n");

    SessionModemFlags.ModemService = false;
    DialSettings = settings;

    modemstatus = NullModem.Get_Modem_Status();
    Debug_Printf("Get_Modem_Status indicates the following...\n");
    Debug_Printf("CTS: %s\n", (modemstatus & CTS_SET) ? "SET" : "CLEAR");
    Debug_Printf("DSR: %s\n", (modemstatus & DSR_SET) ? "SET" : "CLEAR");
    Debug_Printf(" RI: %s\n", (modemstatus & RI_SET) ? "SET" : "CLEAR");
    Debug_Printf(" CD: %s\n", (modemstatus & CD_SET) ? "SET" : "CLEAR");

    if (reconnect) {
        if (modemstatus & CD_SET) {
            SessionModemFlags.ModemService = true;
            return true;
        }
    } else if (modemstatus & CD_SET) {
        Debug_Printf("Modem already on-line - hanging up\n");
        NullModem.Hangup_Modem();
        SessionModemFlags.ModemService = false;
    }

    NullModem.Setup_Modem_Echo(Modem_Echo);

    status = NullModem.Detect_Modem(settings, reconnect);
    if (!status) {
        Debug_Printf("Detect_Modem failed\n");
        NullModem.Remove_Modem_Echo();
        NullModem.Print_EchoBuf();
        NullModem.Reset_EchoBuf();

        switch (settings->Baud) {
            case 14400:
                Debug_Printf("Upshifting to 19200\n");
                settings->Baud = 19200;
                Shutdown_Modem();
                Init_Null_Modem(settings);
                NullModem.Setup_Modem_Echo(Modem_Echo);
                if (!NullModem.Detect_Modem(settings, reconnect)) {
                    Debug_Printf("Detect_Modem failed at 19200\n");
                    NullModem.Remove_Modem_Echo();
                    NullModem.Print_EchoBuf();
                    NullModem.Reset_EchoBuf();
#line 6664
                    WWMessageBox().Process(Fetch_String("TXT_UNABLE_FIND_MODEM", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    SessionModemFlags.ModemService = true;
                    return false;
                }
                break;

            case 28800:
                Debug_Printf("Upshifting to 38400\n");
                settings->Baud = 38400;
                Shutdown_Modem();
                Init_Null_Modem(settings);
                NullModem.Setup_Modem_Echo(Modem_Echo);
                if (!NullModem.Detect_Modem(settings, reconnect)) {
                    Debug_Printf("Detect_Modem failed at 38400\n");
                    NullModem.Remove_Modem_Echo();
                    NullModem.Print_EchoBuf();
                    NullModem.Reset_EchoBuf();
#line 6685
                    WWMessageBox().Process(Fetch_String("TXT_UNABLE_FIND_MODEM", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    SessionModemFlags.ModemService = true;
                    return false;
                }
                break;

            default:
#line 6692
                WWMessageBox().Process(Fetch_String("TXT_UNABLE_FIND_MODEM", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                SessionModemFlags.ModemService = true;
                return false;
        }
    } else if (status == -1) {
        NullModem.Remove_Modem_Echo();
        NullModem.Print_EchoBuf();
        NullModem.Reset_EchoBuf();
#line 6705
        WWMessageBox().Process(Fetch_String("TXT_ERROR_IN_INITSTRING", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
        SessionModemFlags.ModemService = true;
        return false;
    }

    Debug_Printf("Ready to dial\n");
    status = NullModem.Dial_Modem(DialString, settings->DialMethod, reconnect);

    if (reconnect) {
        Map.Flag_To_Redraw(2);
        Map.Virtual_15();
    }

    switch (status) {
        case DIAL_CONNECTED:
            Debug_Printf("Dial_Modem returned 'DIAL_CONNECTED'\n");
            connected = true;
            break;

        case DIAL_NO_CARRIER:
            Debug_Printf("Dial_Modem returned 'DIAL_NO_CARRIER'\n");
#line 6758
            WWMessageBox().Process(Fetch_String("TXT_NO_CARRIER", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_BUSY:
            Debug_Printf("Dial_Modem returned 'DIAL_BUSY'\n");
#line 6764
            WWMessageBox().Process(Fetch_String("TXT_LINE_BUSY", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_ERROR:
            Debug_Printf("Dial_Modem returned 'DIAL_ERROR'\n");
#line 6770
            WWMessageBox().Process(Fetch_String("TXT_NUMBER_INVALID", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_TIMEOUT:
            Debug_Printf("Dial_Modem returned 'DIAL_TIMEOUT'\n");
#line 6776
            WWMessageBox().Process(Fetch_String("TXT_ERROR_TIMEOUT", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_NO_DIAL_TONE:
            Debug_Printf("Dial_Modem returned 'DIAL_NO_DIAL_TONE'\n");
#line 6782
            WWMessageBox().Process(Fetch_String("TXT_NO_DIAL_TONE", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_CANCELLED:
            Debug_Printf("Dial_Modem returned 'DIAL_CANCELLED'\n");
            NullModem.Hangup_Modem();
            SessionModemFlags.ModemService = false;
#line 6790
            WWMessageBox().Process(Fetch_String("TXT_DIALING_CANCELED", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;
    }

    NullModem.Remove_Modem_Echo();
    NullModem.Print_EchoBuf();
    NullModem.Reset_EchoBuf();

    SessionModemFlags.ModemService = true;
    return connected;
}

bool Answer_Modem(SerialSettingsType * settings, bool reconnect)
{
    bool connected = false;
    int status;
    int modemstatus;

    Debug_Printf("Answer Modem\n");

    SessionModemFlags.ModemService = false;
    DialSettings = settings;

    modemstatus = NullModem.Get_Modem_Status();
    Debug_Printf("Get_Modem_Status indicates the following...\n");
    Debug_Printf("CTS: %s\n", (modemstatus & CTS_SET) ? "SET" : "CLEAR");
    Debug_Printf("DSR: %s\n", (modemstatus & DSR_SET) ? "SET" : "CLEAR");
    Debug_Printf(" RI: %s\n", (modemstatus & RI_SET) ? "SET" : "CLEAR");
    Debug_Printf(" CD: %s\n", (modemstatus & CD_SET) ? "SET" : "CLEAR");

    if (reconnect) {
        if (modemstatus & CD_SET) {
            SessionModemFlags.ModemService = true;
            return true;
        }
    } else if (modemstatus & CD_SET) {
        Debug_Printf("Modem already on-line - hanging up\n");
        NullModem.Hangup_Modem();
        SessionModemFlags.ModemService = false;
    }

    NullModem.Setup_Modem_Echo(Modem_Echo);

    status = NullModem.Detect_Modem(settings, reconnect);
    if (!status) {
        Debug_Printf("Detect_Modem failed\n");
        NullModem.Remove_Modem_Echo();
        NullModem.Print_EchoBuf();
        NullModem.Reset_EchoBuf();

        switch (settings->Baud) {
            case 14400:
                Debug_Printf("Upshifting to 19200\n");
                settings->Baud = 19200;
                Shutdown_Modem();
                Init_Null_Modem(settings);
                NullModem.Setup_Modem_Echo(Modem_Echo);
                if (!NullModem.Detect_Modem(settings, reconnect)) {
                    Debug_Printf("Detect_Modem failed at 19200\n");
                    NullModem.Remove_Modem_Echo();
                    NullModem.Print_EchoBuf();
                    NullModem.Reset_EchoBuf();
#line 6887
                    WWMessageBox().Process(Fetch_String("TXT_UNABLE_FIND_MODEM", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    SessionModemFlags.ModemService = true;
                    return false;
                }
                break;

            case 28800:
                Debug_Printf("Upshifting to 38400\n");
                settings->Baud = 38400;
                Shutdown_Modem();
                Init_Null_Modem(settings);
                NullModem.Setup_Modem_Echo(Modem_Echo);
                if (!NullModem.Detect_Modem(settings, reconnect)) {
                    Debug_Printf("Detect_Modem failed at 38400\n");
                    NullModem.Remove_Modem_Echo();
                    NullModem.Print_EchoBuf();
                    NullModem.Reset_EchoBuf();
#line 6908
                    WWMessageBox().Process(Fetch_String("TXT_UNABLE_FIND_MODEM", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    SessionModemFlags.ModemService = true;
                    return false;
                }
                break;

            default:
#line 6915
                WWMessageBox().Process(Fetch_String("TXT_UNABLE_FIND_MODEM", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                SessionModemFlags.ModemService = true;
                return false;
        }
    } else if (status == -1) {
        NullModem.Remove_Modem_Echo();
        NullModem.Print_EchoBuf();
        NullModem.Reset_EchoBuf();
#line 6925
        WWMessageBox().Process(Fetch_String("TXT_ERROR_IN_INITSTRING", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
        SessionModemFlags.ModemService = true;
        return false;
    }

    Debug_Printf("Ready to answer\n");
    status = NullModem.Answer_Modem(reconnect);

    switch (status) {
        case DIAL_CONNECTED:
            Debug_Printf("Answer_Modem returned 'DIAL_CONNECTED'\n");
            connected = true;
            break;

        case DIAL_NO_CARRIER:
            Debug_Printf("Answer_Modem returned 'DIAL_NO_CARRIER'\n");
#line 6941
            WWMessageBox().Process(Fetch_String("TXT_NO_CARRIER", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_ERROR:
            Debug_Printf("Answer_Modem returned 'DIAL_ERROR'\n");
#line 6947
            WWMessageBox().Process(Fetch_String("TXT_NUMBER_INVALID", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_TIMEOUT:
            Debug_Printf("Answer_Modem returned 'DIAL_TIMEOUT'\n");
#line 6953
            WWMessageBox().Process(Fetch_String("TXT_ERROR_TIMEOUT", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;

        case DIAL_CANCELLED:
            Debug_Printf("Answer_Modem returned 'DIAL_CANCELLED'\n");
#line 6959
            WWMessageBox().Process(Fetch_String("TXT_ANSWERING_CANCELED", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            connected = false;
            break;
    }

    NullModem.Remove_Modem_Echo();
    NullModem.Print_EchoBuf();
    NullModem.Reset_EchoBuf();

    SessionModemFlags.ModemService = true;
    return connected;
}

void Modem_Echo(char c)
{
    if (NullModem.EchoCount < NullModem.EchoSize - 1) {
        *(NullModem.EchoBuf + NullModem.EchoCount) = c;
        *(NullModem.EchoBuf + NullModem.EchoCount + 1) = 0;
        NullModem.EchoCount++;
    }
}
