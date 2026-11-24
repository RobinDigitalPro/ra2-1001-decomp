// C:\RA2\SendFile.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Multiplayer scenario file transfer: a client that lacks the host's custom map requests it
// (Get_Scenario), receives it in 192-byte chunks (Receive_Remote_File); the host sends the file
// info and the chunks to every client (Send_Remote_File). Find_Local_Scenario looks the map up in
// the local scenario list first. IPX/internet games use the global channel of Ipx, serial games
// (modem / null modem) the NullModem connection.
// All function, field and variable names are provisional (Westwood style).
//
// TU span 0x261c80..0x263466: the 12 GAMECONST.H initializers 0x261c80..0x261e41, then the four
// functions 0x261e50..0x263466 in source order. The 16-byte zeroing initializer 0x263470
// (.bss 0xa9ec58) precedes SerialEd.cpp's GAMECONST block (0x263490) and is not claimed here.
//
// Status: Find_Local_Scenario matches byte for byte. Get_Scenario, Receive_Remote_File and
// Send_Remote_File have the original size, control flow and calls, but differ in register and
// stack-slot allocation (see W/analysis/level2/agents/SendFile.claims.json).
#include "GAMECONST.H"
#include <string.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Windows_Message_Handler();                               // 0x5b29f0 (provisional)
void Call_Back();                             // 0x4821e0 (provisional; see CampScor.cpp)
void Func_514F50(int a, bool b);                // 0x514f50 (provisional, see CampScor.cpp)

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

// File class hierarchy (see Options.CPP / Restate.cpp; RTTI FileClass, RawFileClass,
// BufferIOFileClass, CDFileClass, CCFileClass).
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

enum { READ = 1, WRITE = 2 };

class RawFileClass : public FileClass {
public:
    RawFileClass(char const * filename);    // 0x6300e0
    virtual ~RawFileClass();                // 0x630060
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();
    virtual int Delete();                   // 0x6307e0
    virtual bool Is_Available(int forced = false);  // 0x630240
    virtual bool Is_Open() const;
    virtual int Open(char const * filename, int rights = 1);
    virtual int Open(int rights = 1);       // 0x6301a0
    virtual long Read(void * buffer, long size);
    virtual long Seek(long pos, int dir = 1);
    virtual long Size();
    virtual long Write(void const * buffer, long size);     // 0x630420
    virtual void Close();                   // 0x6302f0
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
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual int Open(int rights = 1);                       // 0x468e40
    virtual long Read(void * buffer, long size);            // 0x468c80
    virtual long Size();                                    // 0x468d70
    virtual void Close();               // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Doubly linked list (RTTI: GenericNode, GenericList, List<T>), see Restate.cpp.
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

// INI database (see Restate.cpp / Options.CPP). Load and Get_String are used here on a plain
// INIClass object; elsewhere Get_String (0x50ddf0) is bound as CCINIClass::Get_String.
class INIClass {
public:
    struct INISection;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                // 0x50ad20
    int Load(FileClass & file, bool withdigest = false);    // 0x50b030 (name provisional)
    int Get_String(char const * section, char const * entry, char const * defvalue, char * buffer, int size);   // 0x50ddf0
private:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

// CD check object (RTTI .?AVCD@@, vtable 0x788868, three slots). Names provisional.
class CD {
public:
    CD() {}
    virtual bool Force_Available(int cd);       // 0x46e0f0
    virtual bool Virtual_01();                  // 0x46e120
    virtual bool Virtual_02();                  // 0x46e350
    int Unknown04;
};
extern int RequiredCD;                          // 0x7bd078 (.data, initial -1)
void Set_Required_CD(int cd);                   // 0x46e0d0, stores -2 when byte 0x838b70 is 1
int Func_46E0C0(int value);                     // 0x46e0c0 (meaning unknown)

#pragma pack(push, 1)
class IPXAddressClass {
public:
    IPXAddressClass();                          // 0x522950
    bool operator == (IPXAddressClass & address);          // 0x522ae0
private:
    unsigned char Address[10];
};

struct NodeNameType {
    wchar_t Name[20];                           // +0x00
    IPXAddressClass Address;                    // +0x28
};

// Global (session) packet, 0x1c7 bytes; only the scenario file info fields.
struct GlobalPacketType {
    int Command;                                // +0x00
    char Unknown04[0xAF - 0x04];
    unsigned FileLength;                        // +0xaf
    char ShortFileName[0x1C7 - 0xB3];           // +0xb3
};

// Serial packet, 0xfa bytes; only the scenario file info fields.
struct SerialPacketType {
    int Command;                                // +0x00
    char Unknown04[0x9E - 0x04];
    unsigned FileLength;                        // +0x9e
    char Unknown_A2;
    char ShortFileName[0xFA - 0xA3];            // +0xa3
};
#pragma pack(pop)

// One chunk of the file, sent on either channel (0xc8 bytes).
enum { FILE_CHUNK_SIZE = 0xC0 };
struct FileChunkType {
    int Command;                                // +0x00
    unsigned short BlockNumber;                 // +0x04
    unsigned short BlockLength;                 // +0x06
    unsigned char Data[FILE_CHUNK_SIZE];        // +0x08
};
enum { RECEIVE_BUFFER_SIZE = 0x1E7 };

enum NetCommandType {
    NET_REQ_SCENARIO = 0x10,
    NET_FILE_INFO = 0x11,
    NET_FILE_CHUNK = 0x12,
    NET_FILE_INFO_ACK = 0x15,
};
enum SerialCommandType {
    SERIAL_REQ_SCENARIO = 0x6E,
    SERIAL_FILE_INFO = 0x6F,
    SERIAL_FILE_CHUNK = 0x70,
    SERIAL_FILE_INFO_ACK = 0x71,
};
enum { GAME_MODEM = 1, GAME_NULL_MODEM = 2 };

// RTTI .?AVIPXManagerClass@@; only the non-virtual methods used here.
class IPXManagerClass {
public:
    int Send_Global_Message(void * buf, int buflen, int ack_req, IPXAddressClass * address);   // 0x524560
    int Get_Global_Message(void * buf, int * buflen, IPXAddressClass * address, unsigned short * product_id);  // 0x5245e0
    int Global_Num_Send();                      // 0x524ce0 (name provisional)
};
extern IPXManagerClass Ipx;                     // 0xa285c8

class NullModemClass {
public:
    int Send_Message(void * buf, int buflen, int ack_req);  // 0x5c8c80
    int Get_Message(void * buf, int * buflen);  // 0x5c8cc0
    int Num_Send();                             // 0x5c8f30 (name provisional)
};
extern NullModemClass NullModem;                // 0xa28668

// Multiplayer scenario list entry; only the members used here.
class MultiMission {
public:
    bool Func_6681B0(int value);                // 0x6681b0 (meaning unknown, checks a file)
    int Func_668240();                          // 0x668240, returns *(this + 0x18c)
    char Unknown00[0x58];
    char Filename[1];                           // +0x58 (size unknown)
};

extern DynamicVectorClass<MultiMission *> SessionScenarios;    // 0xa25c08 (Session + 0x640)
extern signed char SessionRecipients[];         // 0xa25e50 (Session + 0x888), player indices (provisional)
extern int SessionRecipientCount;               // 0xa25e58 (Session + 0x890) (provisional)
extern IPXAddressClass SessionHostAddress;      // 0xa25e5c (Session + 0x894) (provisional)
extern DynamicVectorClass<NodeNameType *> SessionPlayers;  // 0xa27da8 (Session + 0x27e0)
extern int SessionCounter2820;                  // 0xa27de8 (Session + 0x2820), counted around the CD check

// Two ints passed by value (meaning provisional).
struct Point2DStruct {
    int X;
    int Y;
    Point2DStruct(int x, int y) : X(x), Y(y) {}
};

// Object at 0xa5e540 (class not bound); progress bar methods used here.
class Object_A5E540 {
public:
    void Func_616960(double max, int a, int b);                                 // 0x616960
    void Func_616AE0(char const * shape, int a, int b);                         // 0x616ae0
    void Func_616B40(Point2DStruct point, wchar_t const * text, int a, int b);  // 0x616b40
    void Func_617BE0(Point2DStruct point = Point2DStruct(-1, -1));              // 0x617be0
    void Func_617D70(int index, double value, Point2DStruct point = Point2DStruct(-1, -1));  // 0x617d70
};
extern Object_A5E540 ObjectA5E540;              // 0xa5e540

// ---- end of local declarations ----

bool Receive_Remote_File(char * name, unsigned file_length, int commtype, bool show);
bool Send_Remote_File(char * name, int commtype, bool toall, bool show);


/***********************************************************************************************
 * Get_Scenario -- requests the scenario file from the host and receives it.                   *
 *=============================================================================================*/
bool Get_Scenario(char * name, int commtype, bool show)
{
    unsigned file_length = 0;
    IPXAddressClass sender;
    bool found = false;
    int packetlen;
    int seriallen;
    unsigned short product_id;
    GlobalPacketType sendpacket;
    GlobalPacketType receivepacket;
    SerialPacketType sendserial;
    SerialPacketType receiveserial;

    Debug_Printf("Getting file from host\n");
    CDTimerClass<SystemTimerClass> timer;
    Debug_Printf("Requesting file download\n");

    timer = 60 * 60;
    if (commtype == GAME_MODEM || commtype == GAME_NULL_MODEM) {
        memset(&sendserial, 0, sizeof(sendserial));
        sendserial.Command = SERIAL_REQ_SCENARIO;
        NullModem.Send_Message(&sendserial, sizeof(sendserial), 1);
        while (NullModem.Num_Send() > 0 && timer) {
            Call_Back();
        }
    } else {
        memset(&sendpacket, 0, sizeof(sendpacket));
        sendpacket.Command = NET_REQ_SCENARIO;
        Ipx.Send_Global_Message(&sendpacket, sizeof(sendpacket), 1, &SessionHostAddress);
        while (Ipx.Global_Num_Send() > 0 && timer) {
            Call_Back();
        }
    }
    if (!timer) {
        Debug_Printf("Timeout waiting for REQ_SCENARIO packet send\n");
        return false;
    }

    timer = 60 * 60;
    if (commtype == GAME_MODEM || commtype == GAME_NULL_MODEM) {
        do {
            Call_Back();
            if (NullModem.Get_Message(&receiveserial, &seriallen) > 0 && receiveserial.Command == SERIAL_FILE_INFO) {
                strcpy(name, receiveserial.ShortFileName);
                file_length = receiveserial.FileLength;
                found = true;
                break;
            }
        } while (timer);
    } else {
        do {
            Call_Back();
            packetlen = sizeof(receivepacket);
            if (Ipx.Get_Global_Message(&receivepacket, &packetlen, &sender, &product_id)
                && receivepacket.Command == NET_FILE_INFO && sender == SessionHostAddress) {
                strcpy(name, receivepacket.ShortFileName);
                file_length = receivepacket.FileLength;
                found = true;
                break;
            }
        } while (timer);
    }
    if (found) {
        Debug_Printf("Host responded with file info\n");
        Debug_Printf("File name is %s\n", name);
    }
    if (!timer) {
        Debug_Printf("Timeout waiting for host to respond to file info request\n");
        return false;
    }

    Debug_Printf("Sending file info received ack\n");
    timer = 60 * 60;
    if (commtype == GAME_MODEM || commtype == GAME_NULL_MODEM) {
        memset(&sendserial, 0, sizeof(sendserial));
        sendserial.Command = SERIAL_FILE_INFO_ACK;
        NullModem.Send_Message(&sendserial, sizeof(sendserial), 1);
        while (NullModem.Num_Send() > 0 && timer) {
            Call_Back();
        }
    } else {
        memset(&sendpacket, 0, sizeof(sendpacket));
        sendpacket.Command = NET_FILE_INFO_ACK;
        Ipx.Send_Global_Message(&sendpacket, sizeof(sendpacket), 1, &SessionHostAddress);
        while (Ipx.Global_Num_Send() > 0 && timer) {
            Call_Back();
        }
    }
    if (!timer) {
        Debug_Printf("Timeout waiting for FILE_INFO_ACK send\n");
        return false;
    }

    bool result = Receive_Remote_File(name, file_length, commtype, show);
    Debug_Printf("Receive_Remote_File returned %s\n", result ? "true" : "false");
    return result;
}


/***********************************************************************************************
 * Receive_Remote_File -- receives the chunks of a file and writes it to disk.                 *
 *=============================================================================================*/
// level-2 1.001: defined in src/m85/src/sendfile.cpp (one definition per function)
bool Receive_Remote_File(char * name, unsigned file_length, int commtype, bool show);


/***********************************************************************************************
 * Send_Remote_File -- sends a file to the clients.                                            *
 *=============================================================================================*/
bool Send_Remote_File(char * name, int commtype, bool toall, bool show)
{
    CDTimerClass<SystemTimerClass> timer;
    bool result = false;
    int length;                 // IPX packet length, later the number of blocks (one frame slot)
    int seriallen;
    unsigned short product_id;
    GlobalPacketType sendpacket;
    GlobalPacketType receivepacket;
    SerialPacketType sendserial;
    SerialPacketType receiveserial;
    FileChunkType chunk;

    Debug_Printf("Send file %s to clients\n", name);
    CCFileClass file(name);
    if (!file.Is_Available()) {
        return false;
    }
    int remaining = file.Size();

    timer = 60 * 60;
    Debug_Printf("Sending file info to clients\n");
    if (commtype == GAME_MODEM || commtype == GAME_NULL_MODEM) {
        sendserial.Command = SERIAL_FILE_INFO;
        strcpy(sendserial.ShortFileName, name);
        sendserial.FileLength = remaining;
        NullModem.Send_Message(&sendserial, sizeof(sendserial), 1);
        while (NullModem.Num_Send() > 0 && timer) {
            Call_Back();
        }
    } else {
        sendpacket.Command = NET_FILE_INFO;
        strcpy(sendpacket.ShortFileName, name);
        sendpacket.FileLength = remaining;
        if (toall) {
            for (int i = 1; i < SessionPlayers.ActiveCount; i++) {
                do {
                    Call_Back();
                } while (!Ipx.Send_Global_Message(&sendpacket, sizeof(sendpacket), 1, &SessionPlayers[i]->Address) && timer);
            }
        } else {
            for (int i = 0; i < SessionRecipientCount; i++) {
                do {
                    Call_Back();
                    Debug_Printf("Sending file info packet to player %d\n", SessionPlayers[SessionRecipients[i]]->Name);
                } while (!Ipx.Send_Global_Message(&sendpacket, sizeof(sendpacket), 1, &SessionPlayers[SessionRecipients[i]]->Address) && timer);
            }
        }
        while (Ipx.Global_Num_Send() > 0 && timer) {
            Call_Back();
        }
    }
    if (!timer) {
        Debug_Printf("File info send timed out\n");
        return false;
    }

    IPXAddressClass sender;
    int responses = 0;
    int expected;
    if (toall) {
        expected = SessionPlayers.ActiveCount - 1;
    } else {
        expected = SessionRecipientCount;
    }
    timer = 60 * 60;
    if (commtype == GAME_MODEM || commtype == GAME_NULL_MODEM) {
        do {
            Call_Back();
            if (NullModem.Get_Message(&receiveserial, &seriallen) > 0 && receiveserial.Command == SERIAL_FILE_INFO_ACK) {
                Debug_Printf("Client responded with file info ack\n");
                break;
            }
        } while (timer && responses < expected);
    } else {
        do {
            Call_Back();
            length = sizeof(receivepacket);
            if (Ipx.Get_Global_Message(&receivepacket, &length, &sender, &product_id)
                && receivepacket.Command == NET_FILE_INFO_ACK) {
                responses++;
            }
        } while (timer && responses < expected);
    }

    length = (remaining + FILE_CHUNK_SIZE - 1) / FILE_CHUNK_SIZE;
    file.Open(READ);
    int block = 0;

    if (show) {
        ObjectA5E540.Func_616960(100.0, 1, 0);
        ObjectA5E540.Func_616AE0("PROGBARM.SHP", 0, 0);
#line 559
        ObjectA5E540.Func_616B40(Point2DStruct(-1, -1), Fetch_String("GUI:Generating", NULL, __FILE__, __LINE__), 0, 1);
        Func_514F50(0, true);
        ObjectA5E540.Func_617BE0();
        ObjectA5E540.Func_617D70(0, 0.0);
    }

    timer = 60 * 60;
    int percent = 0;
    while (timer) {
        if (commtype == GAME_MODEM || commtype == GAME_NULL_MODEM) {
            Windows_Message_Handler();
            Call_Back();
            if (block < length) {
                if (NullModem.Num_Send() < 2) {
                    chunk.Command = SERIAL_FILE_CHUNK;
                    chunk.BlockNumber = block;
                    chunk.BlockLength = remaining;
                    if (remaining >= FILE_CHUNK_SIZE) {
                        chunk.BlockLength = FILE_CHUNK_SIZE;
                    }
                    remaining -= chunk.BlockLength;
                    if (file.Read(chunk.Data, chunk.BlockLength) == chunk.BlockLength) {
                        Debug_Printf("Sending file chunk %d\n", block);
                        NullModem.Send_Message(&chunk, sizeof(chunk), 1);
                    }
                    block++;
                    percent += 100;
                    if (show) {
                        ObjectA5E540.Func_617D70(0, percent / length);
                    }
                }
            } else if (NullModem.Num_Send() == 0) {
                result = true;
                if (show) {
                    ObjectA5E540.Func_617D70(0, 100.0);
                }
                break;
            }
        } else {
            Windows_Message_Handler();
            Call_Back();
            if (block < length) {
                if (Ipx.Global_Num_Send() < 10) {
                    chunk.Command = NET_FILE_CHUNK;
                    chunk.BlockNumber = block;
                    chunk.BlockLength = remaining;
                    if (remaining >= FILE_CHUNK_SIZE) {
                        chunk.BlockLength = FILE_CHUNK_SIZE;
                    }
                    remaining -= chunk.BlockLength;
                    if (file.Read(chunk.Data, chunk.BlockLength) == chunk.BlockLength) {
                        Debug_Printf("Sending file chunk %d\n", block);
                        if (toall) {
                            for (int i = 1; i < SessionPlayers.ActiveCount; i++) {
                                int sent;
                                do {
                                    sent = Ipx.Send_Global_Message(&chunk, sizeof(chunk), 1, &SessionPlayers[i]->Address);
                                    Call_Back();
                                } while (!sent);
                            }
                        } else {
                            for (int i = 0; i < SessionRecipientCount; i++) {
                                int sent;
                                do {
                                    sent = Ipx.Send_Global_Message(&chunk, sizeof(chunk), 1, &SessionPlayers[SessionRecipients[i]]->Address);
                                    Call_Back();
                                } while (!sent);
                            }
                        }
                    }
                    block++;
                    percent += 100;
                    if (show) {
                        ObjectA5E540.Func_617D70(0, percent / length);
                    }
                }
            } else if (Ipx.Global_Num_Send() == 0) {
                timer = 60;
                while (timer) {
                    Windows_Message_Handler();
                    Call_Back();
                }
                if (Ipx.Global_Num_Send() == 0) {
                    result = true;
                    if (show) {
                        ObjectA5E540.Func_617D70(0, 100.0);
                    }
                    break;
                }
            }
        }
    }

    Debug_Printf("File upload completed\n");
    return result;
}


/***********************************************************************************************
 * Find_Local_Scenario -- looks for the scenario file in the local scenario list.              *
 *=============================================================================================*/
bool Find_Local_Scenario(char * filename, unsigned length, char * digest, char * description, bool official)
{
    if (stricmp(filename, "RandMap.Sed") == 0) {
        return false;
    }
    for (int i = 0; i < SessionScenarios.ActiveCount; i++) {
        if (strcmp(SessionScenarios[i]->Filename, filename) == 0) {
            CCFileClass file(SessionScenarios[i]->Filename);
            if (!file.Is_Available() && official == true) {
                MultiMission * scenario = SessionScenarios[i];
                if (!scenario->Func_6681B0(Func_46E0C0(60))) {
                    Set_Required_CD(scenario->Func_668240());
                }
                SessionCounter2820++;
                if (!CD().Force_Available(RequiredCD)) {
                    SessionCounter2820--;
                    return false;
                }
                SessionCounter2820--;
            }
            if (file.Is_Available() && file.Size() == length) {
                INIClass ini;
                char buffer[32];
                ini.Load(file);
                ini.Get_String("Digest", "1", "No digest here mate. Nope.", buffer, sizeof(buffer));
                if (digest == NULL || *digest == '\0' || strcmp(digest, buffer) == 0) {
                    strcpy(filename, SessionScenarios[i]->Filename);
                    return true;
                }
            }
        }
    }
    return false;
}
