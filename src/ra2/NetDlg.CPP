// C:\RA2\NetDlg.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Network dialog support: IPX/bridge start-up, network shutdown, connection teardown,
// name CRCs and list box clearing. Class names come from RTTI where a vtable exists
// (IPXManagerClass, WinsockInterfaceClass, ListClass, HouseClass, MultiplayerGameMode);
// all other class, method and variable names are provisional.
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
void Add_CRC(unsigned long * crc, unsigned long val);  // 0x621b70, crc = rol(crc,1) + val

typedef unsigned char NetNumType[4];
typedef unsigned char NetNodeType[6];

// IPX network/node address, 10 bytes (packed: one instance lives at the odd address 0xa27ed5).
#pragma pack(push, 1)
class IPXAddressClass {
public:
    void Set_Address(NetNumType net, NetNodeType node);    // 0x5229e0
    void Get_Address(NetNumType net, NetNodeType node);    // 0x522a60
private:
    NetNumType NetworkNumber;
    NetNodeType NodeAddress;
};

// Entry of the session player list (element of DynamicVectorClass<NodeNameType *> at 0xa27da8).
// Only the fields used here; the rest of the layout is not reconstructed.
struct NodeNameType {
    wchar_t Name[20];               // +0x00 (assumed)
    IPXAddressClass Address;        // +0x28
    char Unknown32[0x5D - 0x32];
    int ID;                         // +0x5d, house index of the player
};

// Event record, 0x6f bytes (constructor 0x4b5d40). Layout not reconstructed.
class EventClass {
public:
    EventClass(int house, int type, int id);
private:
    unsigned char Data[0x6F];
};
#pragma pack(pop)

enum { EVENT_DESTRUCT_CONNECTION = 0x23 };      // provisional name for event type 0x23

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

// RTTI .?AVIPXManagerClass@@ (vtable 0x78f6d4); only the non-virtual methods used here.
class IPXManagerClass {
public:
    int Init();                                 // 0x523fb0
    void Delete_Connection(int id);             // 0x5243c0
    void Set_Bridge(NetNumType bridge);         // 0x5259d0
    void Set_Host_Address(IPXAddressClass * address);  // 0x525a60
};
extern IPXManagerClass Ipx;                     // 0xa285c8

// RTTI .?AVWinsockInterfaceClass@@ (vtable 0x79a8b4); slot 0 is the deleting destructor.
class WinsockInterfaceClass {
public:
    virtual ~WinsockInterfaceClass();
};
extern WinsockInterfaceClass * PacketTransport; // 0x821f90

// RTTI .?AVHouseClass@@; only the fields and the method used here.
class HouseTypeClass {
public:
    char Unknown00[0xC0];
    int ColorScheme;                            // +0xc0 (meaning provisional)
};
class HouseClass {
public:
    void Connection_Lost();                     // 0x4e73d0 (meaning provisional)

    char Unknown00[0x30];
    int ArrayIndex;                             // +0x30
    HouseTypeClass * Class;                     // +0x34
    char Unknown38[0x134 - 0x38];
    bool IsHuman;                               // +0x134
    char Unknown135[0x15F16 - 0x135];
    wchar_t UIName[1];                          // +0x15f16
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

// RTTI .?AVMultiplayerGameMode@@ (vtable 0x792188, 44 slots); only up to slot 12 here.
class MultiplayerGameMode {
public:
    virtual ~MultiplayerGameMode();
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
    virtual bool Announce_Last_Player();        // slot 12 (meaning provisional)
};

// Message list at 0xa25fa0 (Session + 0x9d8).
class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};

// Session object at 0xa255c8. Members used here are kept as separate globals below; their
// addresses suggest they are Session members (offsets given in the comments).
enum { GAME_INTERNET = 4 };
class SessionClass {
public:
    bool Is_Host_Change_Allowed(HouseClass * house);   // 0x665c40 (meaning provisional)

    int Type;                                   // +0x0000
};
extern SessionClass Session;                    // 0xa255c8
extern MultiplayerGameMode * SessionGameMode;   // 0xa255cc  (Session + 0x4)
extern int SessionNumPlayers;                   // 0xa2588c  (Session + 0x2c4)
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)
extern int SessionIsBridge;                     // 0xa2792c  (Session + 0x2364)
extern IPXAddressClass SessionBridgeNet;        // 0xa27930  (Session + 0x2368)
extern unsigned short SessionWord2376;          // 0xa2793e  (Session + 0x2376, meaning unknown)
extern DynamicVectorClass<NodeNameType *> SessionPlayers;  // 0xa27da8 (Session + 0x27e0)
extern bool SessionHostMigration;               // 0xa27ed4  (Session + 0x290c, meaning provisional)
extern IPXAddressClass SessionHostAddress;      // 0xa27ed5  (Session + 0x290d)
extern wchar_t SessionHostName[];               // 0xa27eea  (Session + 0x2922)
extern int SessionHostID;                       // 0xa27f14  (Session + 0x294c)
extern bool SessionHostChanged;                 // 0xa27f24  (Session + 0x295c)

extern bool DebugNetwork;                       // 0xa2895c
extern int NetworkEventMode;                    // 0xa2896c (meaning unknown)
extern int Flag_B0FCC0;                         // 0xb0fcc0 (meaning unknown)

// Object at 0xa9e820 (class not bound).
class HostManagerClass {
public:
    void Func_636520();
    int Choose_New_Host();                      // 0x636cf0, -1 when none
    void Player_Left(int id);                   // 0x636f30
};
extern HostManagerClass HostManager;            // 0xa9e820

// Rules object pointer at 0x821b88; only MessageDelay.
class RulesClass {
public:
    char Unknown00[0x1128];
    double MessageDelay;                        // +0x1128, minutes
};
extern RulesClass * Rule;                       // 0x821b88

// The display object at 0x81a820 (MouseClass vtable); Flag_To_Redraw is 0x4e0030.
class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);
};
class MouseClass : public GScreenClass {
};
extern MouseClass Map;                          // 0x81a820

// RTTI .?AVListClass@@ (vtable 0x790624, 51 slots); placeholders up to slot 43.
class ListClass {
public:
    virtual ~ListClass();
    virtual void Slot_01(); virtual void Slot_02(); virtual void Slot_03(); virtual void Slot_04();
    virtual void Slot_05(); virtual void Slot_06(); virtual void Slot_07(); virtual void Slot_08();
    virtual void Slot_09(); virtual void Slot_10(); virtual void Slot_11(); virtual void Slot_12();
    virtual void Slot_13(); virtual void Slot_14(); virtual void Slot_15(); virtual void Slot_16();
    virtual void Slot_17();
    virtual void Flag_To_Redraw();                          // slot 18
    virtual void Slot_19(); virtual void Slot_20(); virtual void Slot_21(); virtual void Slot_22();
    virtual void Slot_23(); virtual void Slot_24(); virtual void Slot_25(); virtual void Slot_26();
    virtual void Slot_27(); virtual void Slot_28(); virtual void Slot_29(); virtual void Slot_30();
    virtual void Slot_31(); virtual void Slot_32(); virtual void Slot_33(); virtual void Slot_34();
    virtual void Slot_35(); virtual void Slot_36();
    virtual int Count() const;                              // slot 37
    virtual void Slot_38(); virtual void Slot_39();
    virtual char const * Get_Item(int index) const;         // slot 40
    virtual void Slot_41(); virtual void Slot_42();
    virtual void Remove_Item(char const * text);            // slot 43
};

// ---- end of local declarations ----

bool Init_Network()
{
    NetNumType net;
    NetNodeType node;

    if (!Ipx.Init()) {
        return false;
    }

    if (Session.Type != GAME_INTERNET) {
        if (SessionIsBridge) {
            SessionBridgeNet.Get_Address(net, node);
            Ipx.Set_Bridge(net);
        }
    }

    return true;
}

void Shutdown_Network()
{
    SessionWord2376 = 0;
    if (PacketTransport != NULL) {
        delete PacketTransport;
    }
    PacketTransport = NULL;
}

void Destroy_Connection(int id, int error)
{
    HouseClass * housep = Houses[id];
    wchar_t txt[80];

    if (DebugNetwork) {
        Debug_Printf("Destroying connection for house %d (%ls)\n", id, housep->UIName);
    }

    if (!housep || !housep->IsHuman) {
        return;
    }

    txt[0] = 0;
    if (error == 1) {
#line 463 "C:\\RA2\\NetDlg.CPP"
        swprintf(txt, Fetch_String("TXT_CONNECTION_LOST", NULL, __FILE__, __LINE__), housep->UIName);
    } else if (error == 0) {
#line 465
        swprintf(txt, Fetch_String("TXT_LEFT_GAME", NULL, __FILE__, __LINE__), housep->UIName);
    }

    if (wcslen(txt)) {
        SessionMessages.Add_Message(NULL, 0, txt, housep->Class->ColorScheme, 0x4046,
            (int)(Rule->MessageDelay * 900), false);
        Map.Flag_To_Redraw(false);
    }

    Ipx.Delete_Connection(id);

    if (error) {
        if (!NetworkEventMode) {
            housep->Connection_Lost();
        } else {
            OutList.Add(EventClass(PlayerPtr->ArrayIndex, EVENT_DESTRUCT_CONNECTION, id));
        }
    } else if (Session.Type == GAME_INTERNET) {
        if (Flag_B0FCC0) {
            housep->Connection_Lost();
        }
        if (Session.Type == GAME_INTERNET && SessionHostMigration) {
            HostManager.Player_Left(id);
        }
    }

    if (Session.Type == GAME_INTERNET && SessionHostMigration && Session.Is_Host_Change_Allowed(housep)) {
        SessionHostChanged = true;
        int newhost = HostManager.Choose_New_Host();
        if (newhost != -1) {
            HouseClass * hostp = Houses[newhost];
            if (hostp) {
                if (SessionPlayers.ActiveCount > 2) {
                    IPXAddressClass * address = NULL;
                    for (int i = 0; i < SessionPlayers.ActiveCount; i++) {
                        if (SessionPlayers[i]->ID == newhost) {
                            address = &SessionPlayers[i]->Address;
                            break;
                        }
                    }
                    NetNumType net;
                    NetNodeType node;
                    address->Get_Address(net, node);
                    SessionHostAddress.Set_Address(net, node);
                    Ipx.Set_Host_Address(&SessionHostAddress);
                }
                wcscpy(SessionHostName, hostp->UIName);
                Debug_Printf("New game host is %ls\n", SessionHostName);
                SessionHostID = newhost;
                if (Session.Is_Host_Change_Allowed(NULL)) {
                    HostManager.Func_636520();
                }
            }
        }
    }

    for (int i = 0; i < SessionPlayers.ActiveCount; i++) {
        if (SessionPlayers[i]->ID == id) {
            delete SessionPlayers[i];
            SessionPlayers.Delete(SessionPlayers[i]);
            if (Session.Type == GAME_INTERNET && SessionHostMigration) {
                HostManager.Player_Left(id);
            }
            break;
        }
    }

    SessionNumPlayers--;
    if (SessionNumPlayers == 1) {
        if (!SessionGameMode || SessionGameMode->Announce_Last_Player()) {
#line 630
            swprintf(txt, L"%s", Fetch_String("TXT_JUST_YOU_AND_ME", NULL, __FILE__, __LINE__));
            SessionMessages.Add_Message(NULL, 0, txt, housep->Class->ColorScheme, 0x4046,
                (int)(Rule->MessageDelay * 900), false);
            Map.Flag_To_Redraw(false);
        }
    }
}

unsigned long Compute_Name_CRC(char * name)
{
    char buf[80];
    unsigned long crc = 0;

    strcpy(buf, name);
    _strupr(buf);

    for (unsigned i = 0; i < strlen(buf); i++) {
        Add_CRC(&crc, (unsigned long)buf[i]);
    }

    return crc;
}

unsigned long Compute_Name_CRC(wchar_t * name)
{
    wchar_t buf[80];
    unsigned long crc = 0;

    wcscpy(buf, name);
    _wcsupr(buf);

    for (unsigned i = 0; i < wcslen(buf); i++) {
        Add_CRC(&crc, (unsigned long)buf[i]);
    }

    return crc;
}

void Clear_Listbox(ListClass * list)
{
    while (list->Count()) {
        char * ptr = (char *)list->Get_Item(0);
        list->Remove_Item(ptr);
        delete [] ptr;
    }

    list->Flag_To_Redraw();
}
