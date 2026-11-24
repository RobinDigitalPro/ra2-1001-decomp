// C:\RA2\NullMgr.CPP (level-2 reconstruction of GAME.EXE 1.001)
// NullModemClass: the serial (null modem / modem) connection manager on top of WinModemClass
// (the Windows serial port) and one NullModemConnClass connection. Besides the packet service
// it detects, dials, answers and hangs up modems.
// Class names come from RTTI (NullModemClass vtable 0x7923d4 derived from ConnManClass vtable
// 0x78f730, NullModemConnClass vtable 0x792388, WinModemClass vtable 0x79a370, CommBufferClass);
// all method, field and variable names are provisional (Westwood style).
//
// TU span 0x1c8460..0x1ca77d: the 16-byte zeroing initializer 0x1c8460, the 12 GAMECONST
// initializers 0x1c8480..0x1c8641, the methods 0x1c8650..0x1ca6d2 in source order (the in-class
// inline virtual overrides 0x1ca5b0..0x1ca6c0 are emitted at the end) and the scalar deleting
// destructor 0x1ca6e0. The next TU starts with the GAMECONST initializer at 0x1ca780.
// Six functions have no function_map entry (out-of-line copies that are also inlined):
// Num_Receive 0x1c8f50, Abort_Modem 0x1ca440, Setup_Abort_Modem 0x1ca490,
// Remove_Abort_Modem 0x1ca4b0, Send_Modem_Command 0x1ca530, Verify_And_Convert_To_Int 0x1ca560.
//
// Open (see W/analysis/level2/agents/NullMgr.claims.json):
// - Constructor 0x1c8650: store order matches; register allocation differs (original loads the
//   constants -1/0 into edx/ecx first and moves the arguments through esi).
// - Detect_Modem 0x1c9030: all code matches except the placement of the shared
//   "End_Dialog; Leave_Failsafe_Mode; return false" tail (original keeps it after the 'AT'
//   failure, our compile merges into the copy after TXT_ERROR_TOO_MANY).

// Dynamic initializer 0x1c8460: zeroes 16 bytes at 0xa5a968 (this TU's .bss, next to
// ModemConnectString 0xa5a978); nothing else references them. Meaning unknown.
struct NullMgrUnknownStruct {
    NullMgrUnknownStruct() : A(0), B(0), C(0), D(0) {}
    int A;
    int B;
    int C;
    int D;
};
static NullMgrUnknownStruct NullMgrUnknown;

#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
void Delay(int duration);                       // 0x496800 (name provisional)
void Call_Back();                             // 0x4821e0 (provisional; see CampScor.cpp)
void Windows_Message_Handler();                               // 0x5b29f0 (provisional)

// Dialog support (see NullDlg.CPP).
void Show_Dialog(HWND dialog);                  // 0x5f7480
void End_Dialog(HWND dialog);                   // 0x5f73a0
bool Dialog_Abort_Check();                      // 0x5f7d70, pumps messages, true when the dialog must close
HWND Create_Cancel_Dialog(wchar_t const * text, wchar_t const * button, bool * cancelled);  // 0x5f7e80 (provisional)
void Set_Cancel_Dialog_Text(HWND dialog, wchar_t const * text);     // 0x5f7f60 (name provisional)
void Call_Back_5168E0(bool flag);               // 0x5168e0, called while the dialog runs (meaning unknown)

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624).
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};

class WWKeyboardClass {
public:
    unsigned short Check();                     // 0x530530
    void Clear();                               // 0x530c50
};
extern WWKeyboardClass * Keyboard;              // 0x81a7a8

extern char EmptyString[];                      // 0x8248a4 (BSS), shared default string

// Serial port settings (Session + 0x282c and the phone book entries), see SerialEd.cpp.
enum DialMethodType { DIAL_TOUCH_TONE, DIAL_PULSE };
struct SerialSettingsType {
    int Port;                                   // +0x00, 0x3f8/0x2f8/0x3e8/0x2e8, 1 = modem device
    int IRQ;                                    // +0x04
    int Baud;                                   // +0x08
    DialMethodType DialMethod;                  // +0x0c
    int InitStringIndex;                        // +0x10, -1 = none
    int CallWaitStringIndex;                    // +0x14
    int Compression;                            // +0x18, check box 0x3eb (data compression)
    int ErrorCorrection;                        // +0x1c, check box 0x3ea (error correction)
    char CallWaitString[0x10];                  // +0x20
    char ModemName[0x40];                       // +0x30
};

enum PortDetectType { PORT_VALID, PORT_INVALID, PORT_IRQ_INUSE };
enum DialStatusType { DIAL_CONNECTED, DIAL_NO_CARRIER, DIAL_BUSY, DIAL_ERROR, DIAL_NO_DIAL_TONE, DIAL_TIMEOUT, DIAL_CANCELLED };
enum { CTS_SET = 0x10, DSR_SET = 0x20, RI_SET = 0x40, CD_SET = 0x80 };

// Session members (see NullDlg.CPP for the convention of separate globals).
struct SessionModemFlagsType {
    unsigned ModemService : 1;
};
extern SessionModemFlagsType SessionModemFlags; // 0xa27dec  (Session + 0x2824)
extern DynamicVectorClass<char *> SessionInitStrings;   // 0xa27e80 (Session + 0x28b8)

// Windows modem registry entry, 0x1c bytes, no vtable (see SerialEd.cpp).
class ModemRegistryEntryClass {
public:
    ModemRegistryEntryClass(int modem_number);  // 0x599af0
    ~ModemRegistryEntryClass();                 // 0x59a2e0

    char * ModemName;                           // +0x00
    char * ModemDeviceName;                     // +0x04
    char * ErrorCorrectionEnable;               // +0x08
    char * ErrorCorrectionDisable;              // +0x0c
    char * CompressionEnable;                   // +0x10
    char * CompressionDisable;                  // +0x14
    char * HardwareFlowControl;                 // +0x18
};

// Results of WinModemClass::Send_Command_To_Modem.
enum ModemCommandType { MODEM_CMD_TIMEOUT, MODEM_CMD_ERROR, MODEM_CMD_OK, MODEM_CMD_0 };
#define ASYNC_ABORT (-1000)     // returned by Get_Modem_Result and the abort function

// RTTI .?AVWinModemClass@@ (vtable 0x79a370, 10 slots), object size 0x2088.
class WinModemClass {
public:
    WinModemClass();                            // 0x728ce0
    virtual ~WinModemClass();                   // slot 0 (deleting 0x72a1d0)
    virtual HANDLE Serial_Port_Open(char * port_name, int baud, int parity, int wordlen, int stopbits);     // 0x728fd0
    virtual void Set_Modem_Dial_Type(DialMethodType method);            // 0x729460
    virtual int Get_Modem_Status();                                     // 0x729470
    virtual void Set_Serial_DTR(BOOL state);                            // 0x7294c0
    virtual int Get_Modem_Result(int delay, char * buffer, int buffer_len, int terminate);    // 0x729890
    virtual void Dial_Modem(char * dial_number);                        // 0x729b10
    virtual int Send_Command_To_Modem(char * command, char terminator, char * buffer, int buflen,
        int delay, int retries, int terminate);                         // 0x729cd0
    virtual void Set_Echo_Function(void (*func)(char c));               // 0x72a060
    virtual void Set_Abort_Function(int (*func)());                     // 0x72a070

    bool Enter_Failsafe_Mode();                 // 0x729230 ("WinModemClass - Entering failsafe ...")
    void Leave_Failsafe_Mode();                 // 0x729380
    void Serial_Port_Close();                   // 0x729510
    int Read_From_Serial_Port(char * buffer, int length);   // 0x7296f0
    void Write_To_Serial_Port(char const * buffer, int length);   // 0x729830
    HANDLE Get_Port_Handle();                   // 0x72a080
private:
    char Data[0x2088 - 4];
};
extern WinModemClass * SerialPort;              // 0xb0d628

// Send queue entry, 0x20 bytes (see Connect.CPP).
struct SendQueueType {
    unsigned IsActive : 1;
    unsigned IsACK : 1;
    unsigned IsBad : 1;
    unsigned long FirstTime;                    // +0x04
    unsigned long LastTime;                     // +0x08
    unsigned long SendCount;                    // +0x0c
    int BufLen;                                 // +0x10
    char * Buffer;                              // +0x14
    int ExtraLen;                               // +0x18
    void * ExtraBuffer;                         // +0x1c
};

// Packet header in front of every connection packet, 8 bytes (see Connect.CPP).
struct CommHeaderType {
    unsigned short MagicNumber;                 // +0
    unsigned char Code;                         // +2, PacketType
    unsigned char Flags;                        // +3
    unsigned long PacketID;                     // +4
};

// RTTI .?AVCommBufferClass@@ (see unnamed/TU_47FCC0.cpp); only the members used here.
class CommBufferClass {
public:
    virtual ~CommBufferClass();
    void Init_Send_Queue();                     // 0x47ff80
    SendQueueType * Get_Send(int index);        // 0x4802c0
    unsigned long Avg_Response_Time();          // 0x4805d0
    void Reset_Response_Time(bool clear);       // 0x4805f0
    void Configure_Debug(int offset, int size, char ** names, int namestart, int namecount); // 0x480620

    int Num_Send() { return SendCount; }
    int Num_Receive() { return ReceiveCount; }

private:
    char Unknown04[0x28 - 0x04];
    int SendCount;                              // +0x28
    char Unknown2C[0x38 - 0x2C];
    int ReceiveCount;                           // +0x38
    char Unknown3C[0x58 - 0x3C];
};

// RTTI .?AVConnectionClass@@ (vtable 0x788dcc, see Connect.CPP); only the members used here.
class ConnectionClass {
public:
    enum PacketType {
        PACKET_DATA_ACK,
        PACKET_DATA_NOACK,
        PACKET_ACK,
        PACKET_COUNT
    };

    virtual ~ConnectionClass();
    virtual void Init();
    virtual int Send_Packet(void * buf, int buflen, int ack_req, unsigned char flags);
    virtual int Receive_Packet(void * buf, int buflen);
    virtual int Get_Packet(void * buf, int * buflen);
    virtual int Service();

    CommBufferClass * Queue;                    // +0x04
    char Unknown08[0x1C - 0x08];
    int MaxPacketLen;                           // +0x1c, including the header
    char Unknown20[0x28 - 0x20];
    unsigned long RetryDelta;                   // +0x28
    unsigned long MaxRetries;                   // +0x2c
    unsigned long Timeout;                      // +0x30
    char Unknown34[0x4C - 0x34];
};

// RTTI .?AVNullModemConnClass@@ (vtable 0x792388), object size 0x54.
class NullModemConnClass : public ConnectionClass {
public:
    NullModemConnClass(int numsend, int numreceive, int maxlen, unsigned short magicnum);   // 0x5c61d0
    void Init(HANDLE port_handle);              // 0x5c6240
    static int Compute_CRC(char * buf, int buflen); // 0x5c6310

    HANDLE PortHandle;                          // +0x4c
    char * SendBuf;                             // +0x50
};

// RTTI .?AVConnManClass@@ (vtable 0x78f730, 16 slots, all but the destructor pure).
class ConnManClass {
public:
    virtual ~ConnManClass() {}
    virtual int Service() = 0;
    virtual int Send_Private_Message(void * buf, int buflen, int ack_req, int conn_id) = 0;
    virtual int Get_Private_Message(void * buf, int * buflen, int * conn_id) = 0;
    virtual int Num_Connections() = 0;
    virtual int Connection_ID(int index) = 0;
    virtual int Connection_Index(int id) = 0;
    virtual int Global_Num_Send() = 0;
    virtual int Global_Num_Receive() = 0;
    virtual int Private_Num_Send(int id) = 0;
    virtual int Private_Num_Receive(int id) = 0;
    virtual void Reset_Response_Time(int unused) = 0;
    virtual unsigned long Response_Time() = 0;
    virtual void Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout, int unused) = 0;
    virtual void Set_Default_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout) = 0;
    virtual void Configure_Debug(int index, int type_offset, int type_size, char ** names, int namestart, int namecount) = 0;
};

// RTTI .?AVNullModemClass@@ (vtable 0x7923d4, 16 slots), object size 0x74.
class NullModemClass : public ConnManClass {
public:
    NullModemClass(int numsend, int numreceive, int maxlen, unsigned short magicnum);
    virtual ~NullModemClass();

    int Init(int port, int irq, char * dev_name, int baud, char parity, int wordlength, int stopbits);
    virtual int Num_Connections();
    int Delete_Connection();
    int Init_Send_Queue();
    int Detect_Port(SerialSettingsType * settings);
    void Shutdown();
    virtual void Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout, int unused);
    int Send_Message(void * buf, int buflen, int ack_req);
    int Get_Message(void * buf, int * buflen);
    virtual int Service();
    int Num_Send();
    int Num_Receive();
    virtual unsigned long Response_Time();
    virtual void Reset_Response_Time(int unused);
    void * Oldest_Send();
    virtual void Configure_Debug(int index, int type_offset, int type_size, char ** names, int namestart, int namecount);

    bool Detect_Modem(SerialSettingsType * settings, bool reconnect);
    int Dial_Modem(char * string, DialMethodType method, bool reconnect);
    int Answer_Modem(bool reconnect);
    bool Hangup_Modem();
    void Setup_Modem_Echo(void (*func)(char c));
    void Remove_Modem_Echo();
    void Print_EchoBuf();
    void Reset_EchoBuf();
    static int Abort_Modem();
    void Setup_Abort_Modem();
    void Remove_Abort_Modem();
    int Change_IRQ_Priority(int irq);
    int Get_Modem_Status();
    int Send_Modem_Command(char * command, char terminator, char * buffer, int buflen, int delay, int retries);
    int Verify_And_Convert_To_Int(char * buffer);

    virtual int Connection_ID(int index) { return 0; }
    virtual int Connection_Index(int id) { return 0; }
    virtual void Set_Default_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout)
    {
        Set_Timing(retrydelta, maxretries, timeout, 1);
    }
    virtual int Send_Private_Message(void * buf, int buflen, int ack_req, int conn_id)
    {
        return Send_Message(buf, buflen, ack_req);
    }
    virtual int Get_Private_Message(void * buf, int * buflen, int * conn_id)
    {
        return Get_Message(buf, buflen);
    }
    virtual int Global_Num_Send() { return Num_Send(); }
    virtual int Global_Num_Receive() { return Num_Receive(); }
    virtual int Private_Num_Send(int id) { return Num_Send(); }
    virtual int Private_Num_Receive(int id) { return Num_Receive(); }

    char * SendBuf;                             // +0x04
    int MaxLen;                                 // +0x08, largest packet
    char * EchoBuf;                             // +0x0c
    int EchoSize;                               // +0x10
    int EchoCount;                              // +0x14
    int OldIRQPri;                              // +0x18
    int ModemVerboseOn;                         // +0x1c
    int ModemEchoOn;                            // +0x20
    int ModemWaitCarrier;                       // +0x24, dial/answer carrier wait
    int ModemHangupDelay;                       // +0x28, ATH response delay
    int ModemGuardTime;                         // +0x2c, escape guard time
    char ModemEscapeCode;                       // +0x30
    ModemRegistryEntryClass * ModemRegistry;    // +0x34
    NullModemConnClass * Connection;            // +0x38
    int NumConnections;                         // +0x3c
    HANDLE PortHandle;                          // +0x40
    int NumSend;                                // +0x44
    int NumReceive;                             // +0x48
    unsigned short MagicNum;                    // +0x4c
    char * RecvBuf;                             // +0x50
    int RecvBufSize;                            // +0x54
    int RecvBufPos;                             // +0x58
    unsigned long RetryDelta;                   // +0x5c
    unsigned long MaxRetries;                   // +0x60
    unsigned long Timeout;                      // +0x64
    int SendOverflows;                          // +0x68
    int ReceiveOverflows;                       // +0x6c
    int CRCErrors;                              // +0x70
};
extern NullModemClass NullModem;                // 0xa28668

// Serial packet header in the receive buffer (followed by the data and a 32-bit CRC).
struct SerialHeaderType {
    unsigned short MagicNumber;                 // +0, 0xdabd
    unsigned short Length;                      // +2, data bytes
    unsigned short MagicNumber2;                // +4, 0xdeaf
};
#define SERIAL_MAGIC        0xDABD
#define SERIAL_MAGIC2       0xDEAF

bool ConnectCancelled;                          // 0xa5aa2c (set by the cancel dialog and Abort_Modem)

// ---- end of local declarations ----

static char ModemResponseNames[4][20] = {       // 0x7d1a54
    "MODEM_CMD_TIMEOUT",
    "MODEM_CMD_ERROR",
    "MODEM_CMD_OK",
    "MODEM_CMD_0",
};

char ModemConnectString[80];                    // 0xa5a978, the modem's connect message



NullModemClass::~NullModemClass()
{
    delete ModemRegistry;
    Delete_Connection();
    Shutdown();
    if (SerialPort) {
        delete SerialPort;
        SerialPort = NULL;
    }
}

int NullModemClass::Init(int port, int irq, char * dev_name, int baud, char parity, int wordlength, int stopbits)
{
    static char _portnames[9][5] = {"COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9"};
    char * portname;

    Debug_Printf("NullModemClass::Init\n");

    if (SerialPort) {
        PortHandle = SerialPort->Get_Port_Handle();
    } else {
        PortHandle = INVALID_HANDLE_VALUE;
    }

    if (!Connection) {
        Debug_Printf("Creating connection class\n");
        Connection = new NullModemConnClass(NumSend, NumReceive, MaxLen, MagicNum);
        Connection->RetryDelta = RetryDelta;
        Connection->MaxRetries = MaxRetries;
        Connection->Timeout = Timeout;
        RecvBufSize = (Connection->MaxPacketLen + sizeof(SerialHeaderType) + sizeof(int) + 1) * NumReceive;
        RecvBuf = new char[RecvBufSize];
        SendBuf = new char[MaxLen];
        EchoBuf = new char[EchoSize];
    } else {
        Debug_Printf("Connection already exists\n");
    }

    RecvBufPos = 0;
    EchoCount = 0;

    if (!SerialPort) {
        SerialPort = new WinModemClass;
    }

    switch (port) {
        case 0x3f8:
            portname = _portnames[0];
            break;

        case 0x2f8:
            portname = _portnames[1];
            break;

        case 0x3e8:
            portname = _portnames[2];
            break;

        case 0x2e8:
            portname = _portnames[3];
            break;

        case 1: {
            portname = dev_name;
            if (ModemRegistry) {
                delete ModemRegistry;
                ModemRegistry = NULL;
            }
            for (int i = 0; i < 10; i++) {
                ModemRegistry = new ModemRegistryEntryClass(i);
                if (ModemRegistry->ModemName && !strcmp(dev_name, ModemRegistry->ModemName)) {
                    portname = ModemRegistry->ModemDeviceName;
                    break;
                }
                delete ModemRegistry;
                ModemRegistry = NULL;
            }
            break;
        }

        default:
            portname = NULL;
            break;
    }

    PortHandle = SerialPort->Serial_Port_Open(portname, baud, parity, wordlength, stopbits);
    if (PortHandle == INVALID_HANDLE_VALUE) {
        return false;
    }

    Debug_Printf("Ready to initialise connection\n");
    Connection->Init(PortHandle);
    NumConnections = 1;
    return true;
}

int NullModemClass::Num_Connections()
{
    return NumConnections;
}

int NullModemClass::Delete_Connection()
{
    if (Connection) {
        delete Connection;
        Connection = NULL;
    }
    if (RecvBuf) {
        delete [] RecvBuf;
        RecvBuf = NULL;
    }
    if (SendBuf) {
        delete [] SendBuf;
        SendBuf = NULL;
    }
    if (EchoBuf) {
        delete [] EchoBuf;
        EchoBuf = NULL;
    }
    NumConnections = 0;
    return true;
}

int NullModemClass::Init_Send_Queue()
{
    if (Connection) {
        Connection->Queue->Init_Send_Queue();
    }
    return true;
}

int NullModemClass::Detect_Port(SerialSettingsType * settings)
{
    static char _portnames[9][5] = {"COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9"};
    char * portname;

    if (!SerialPort) {
        SerialPort = new WinModemClass;
    } else {
        SerialPort->Serial_Port_Close();
    }

    int baud = settings->Baud;

    switch (settings->Port) {
        case 0x3f8:
            portname = _portnames[0];
            break;

        case 0x2f8:
            portname = _portnames[1];
            break;

        case 0x3e8:
            portname = _portnames[2];
            break;

        case 0x2e8:
            portname = _portnames[3];
            break;

        case 1: {
            portname = settings->ModemName;
            if (ModemRegistry) {
                delete ModemRegistry;
                ModemRegistry = NULL;
            }
            for (int i = 0; i < 10; i++) {
                ModemRegistry = new ModemRegistryEntryClass(i);
                if (ModemRegistry->ModemName && !strcmp(settings->ModemName, ModemRegistry->ModemName)) {
                    portname = ModemRegistry->ModemDeviceName;
                    break;
                }
                delete ModemRegistry;
                ModemRegistry = NULL;
            }
            break;
        }

        default:
            return PORT_INVALID;
    }

    if (SerialPort->Serial_Port_Open(portname, baud, 0, 8, 1) == INVALID_HANDLE_VALUE) {
        return PORT_INVALID;
    }
    SerialPort->Serial_Port_Close();
    return PORT_VALID;
}

void NullModemClass::Shutdown()
{
    if (PortHandle != INVALID_HANDLE_VALUE && SerialPort) {
        SerialPort->Serial_Port_Close();
        delete SerialPort;
        SerialPort = NULL;
        PortHandle = INVALID_HANDLE_VALUE;
        Delete_Connection();
    }
}

void NullModemClass::Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout, int)
{
    RetryDelta = retrydelta;
    MaxRetries = maxretries;
    Timeout = timeout;
    Connection->RetryDelta = RetryDelta;
    Connection->MaxRetries = MaxRetries;
    Connection->Timeout = Timeout;
}

int NullModemClass::Send_Message(void * buf, int buflen, int ack_req)
{
    if (NumConnections == 0) {
        return false;
    }
    int rc = Connection->Send_Packet(buf, buflen, ack_req, 0);
    if (!rc) {
        SendOverflows++;
    }
    return rc;
}

int NullModemClass::Get_Message(void * buf, int * buflen)
{
    if (NumConnections == 0) {
        return false;
    }
    return Connection->Get_Packet(buf, buflen);
}

int NullModemClass::Service()
{
    int pos;
    int i;
    unsigned int bytes_left;
    unsigned int end;
    SerialHeaderType * header;
    unsigned short length;
    int * crc;

    if (NumConnections == 0) {
        return false;
    }

    RecvBufPos += SerialPort->Read_From_Serial_Port(RecvBuf + RecvBufPos, RecvBufSize - RecvBufPos);

    if (RecvBufPos < sizeof(SerialHeaderType) + sizeof(int) + 1) {
        return Connection->Service();
    }

    pos = -1;
    for (i = 0; i <= RecvBufPos - 2; i++) {
        if (*(unsigned short *)(RecvBuf + i) == SERIAL_MAGIC) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        memmove(RecvBuf, RecvBuf + i, 1);
        RecvBufPos = 1;
        return Connection->Service();
    }

    bytes_left = RecvBufPos - pos;
    if (bytes_left < sizeof(SerialHeaderType)) {
        memmove(RecvBuf, RecvBuf + pos, bytes_left);
        RecvBufPos -= pos;
        return Connection->Service();
    }

    header = (SerialHeaderType *)(RecvBuf + pos);
    if (header->MagicNumber2 != SERIAL_MAGIC2) {
        pos += 2;
        memmove(RecvBuf, RecvBuf + pos, RecvBufPos - pos);
        RecvBufPos -= pos;
        return Connection->Service();
    }

    length = header->Length;
    if (length > MaxLen) {
        Debug_Printf("Serial packet length too long by %d bytes\n", length - MaxLen);
        pos += 2;
        memmove(RecvBuf, RecvBuf + pos, RecvBufPos - pos);
        RecvBufPos -= pos;
        return Connection->Service();
    }

    end = pos + length + sizeof(SerialHeaderType) + sizeof(int);
    if (end > RecvBufPos) {
        if (pos) {
            memmove(RecvBuf, header, bytes_left);
            RecvBufPos -= pos;
        }
        return Connection->Service();
    }

    crc = (int *)(RecvBuf + pos + sizeof(SerialHeaderType) + length);
    if (NullModemConnClass::Compute_CRC((char *)(header + 1), length) != *crc) {
        CRCErrors++;
        Debug_Printf("Serial packet failed CRC check\n");
        pos += 2;
        memmove(RecvBuf, RecvBuf + pos, RecvBufPos - pos);
        RecvBufPos -= pos;
        return Connection->Service();
    }

    if (!Connection->Receive_Packet(RecvBuf + pos + sizeof(SerialHeaderType), length)) {
        ReceiveOverflows++;
    }

    memmove(RecvBuf, RecvBuf + end, RecvBufPos - end);
    RecvBufPos -= end;
    return Connection->Service();
}

int NullModemClass::Num_Send()
{
    if (Connection) {
        return Connection->Queue->Num_Send();
    }
    return 0;
}

int NullModemClass::Num_Receive()
{
    if (Connection) {
        return Connection->Queue->Num_Receive();
    }
    return 0;
}

unsigned long NullModemClass::Response_Time()
{
    if (Connection) {
        return Connection->Queue->Avg_Response_Time();
    }
    return 0;
}

void NullModemClass::Reset_Response_Time(int)
{
    if (Connection) {
        Connection->Queue->Reset_Response_Time(true);
    }
}

void * NullModemClass::Oldest_Send()
{
    int i;
    SendQueueType * send_entry;
    void * buf = NULL;

    for (i = 0; i < Connection->Queue->Num_Send(); i++) {
        send_entry = Connection->Queue->Get_Send(i);
        if (send_entry) {
            CommHeaderType * packet = (CommHeaderType *)send_entry->Buffer;
            if (packet->Code == ConnectionClass::PACKET_DATA_ACK && send_entry->IsACK == 0) {
                buf = send_entry->Buffer;
                break;
            }
        }
    }
    return buf;
}

void NullModemClass::Configure_Debug(int, int type_offset, int type_size, char ** names, int namestart, int namecount)
{
    if (Connection) {
        Connection->Queue->Configure_Debug(type_offset, type_size, names, namestart, namecount);
    }
}

#line 1120 "C:\\RA2\\NullMgr.CPP"


#line 1400
int NullModemClass::Dial_Modem(char * string, DialMethodType method, bool reconnect)
{
    bool process = true;
    int status = DIAL_ERROR;
    int delay;
    wchar_t const * text;
    char buffer[240];

    Debug_Printf("Dial_Modem\n");

    if (reconnect == true) {
#line 1409
        text = Fetch_String("TXT_MODEM_CONNERR_REDIALING", NULL, __FILE__, __LINE__);
    } else {
#line 1411
        text = Fetch_String("TXT_DIALING", NULL, __FILE__, __LINE__);
    }

    ConnectCancelled = false;
#line 1415
    HWND dialog = Create_Cancel_Dialog(text, Fetch_String("TXT_CANCEL", NULL, __FILE__, __LINE__), &ConnectCancelled);
    if (dialog) {
        Show_Dialog(dialog);

        Debug_Printf("Setting modem dial type\n");
        SerialPort->Set_Modem_Dial_Type(method);

        Debug_Printf("Clearing results buffer\n");
        SerialPort->Get_Modem_Result(60, buffer, 81, -1);

        Debug_Printf("Calling dial function\n");
        SerialPort->Dial_Modem(string);

        Setup_Abort_Modem();

        delay = ModemWaitCarrier;
        Debug_Printf("Waiting for dial result\n");

        while (process == true) {
            if (Dialog_Abort_Check() == true || ConnectCancelled) {
                status = DIAL_CANCELLED;
                if (SerialPort) {
                    char abortbuf[3] = "\r";
                    SerialPort->Write_To_Serial_Port(abortbuf, 2);
                }
                Debug_Printf("Dialling cancelled\n");
                break;
            }

            Call_Back_5168E0(false);

            memset(buffer, 0, sizeof(buffer));
            delay = SerialPort->Get_Modem_Result(delay, buffer, 81, 15);

            if (delay == ASYNC_ABORT) {
                status = DIAL_CANCELLED;
                if (SerialPort) {
                    char abortbuf[3] = "\r";
                    SerialPort->Write_To_Serial_Port(abortbuf, 2);
                }
                Debug_Printf("Dialling cancelled\n");
                break;
            }

            _strupr(buffer);
            if (strlen(buffer)) {
                Debug_Printf("From Modem: %s\n", buffer);
            }

            if (strstr(buffer, "CON")) {
                memset(ModemConnectString, 0, sizeof(ModemConnectString));
                strncpy(ModemConnectString, buffer, sizeof(ModemConnectString) - 1);
                status = DIAL_CONNECTED;
                Debug_Printf("Dial result is %s\n", buffer);
                process = false;
            } else if (!strncmp(buffer, "BUSY", 4)) {
                status = DIAL_BUSY;
                Debug_Printf("Dial result is %s\n", buffer);
                process = false;
            } else if (!strncmp(buffer, "NO C", 4)) {
                status = DIAL_NO_CARRIER;
                Debug_Printf("Dial result is %s\n", buffer);
                process = false;
            } else if (!strncmp(buffer, "NO D", 4)) {
                status = DIAL_NO_DIAL_TONE;
                Debug_Printf("Dial result is %s\n", buffer);
                process = false;
            } else if (!strncmp(buffer, "ERRO", 4)) {
                status = DIAL_ERROR;
                Debug_Printf("Dial result is %s\n", buffer);
                process = false;
            }

            if (delay <= 0) {
                Debug_Printf("NullModemClass::Dial_Modem has timed out\n");
                if (strlen(buffer)) {
                    Debug_Printf("Dial result is %s\n", buffer);
                }
                if (SerialPort) {
                    char abortbuf[3] = "\r";
                    SerialPort->Write_To_Serial_Port(abortbuf, 2);
                }
                status = DIAL_TIMEOUT;
                break;
            }
        }

        Remove_Abort_Modem();
        End_Dialog(dialog);
    }

    return status;
}

#line 1570
int NullModemClass::Answer_Modem(bool reconnect)
{
    bool ring = false;
    int status = DIAL_ERROR;
    bool process;
    int delay;
    wchar_t const * text;
    char buffer[240];

    if (reconnect == true) {
#line 1580
        text = Fetch_String("TXT_MODEM_CONNERR_WAITING", NULL, __FILE__, __LINE__);
    } else {
#line 1582
        text = Fetch_String("TXT_WAITING_FOR_CALL", NULL, __FILE__, __LINE__);
    }

    Debug_Printf("Waiting for ring\n");

    process = true;
    ConnectCancelled = false;
#line 1589
    HWND dialog = Create_Cancel_Dialog(text, Fetch_String("TXT_CANCEL", NULL, __FILE__, __LINE__), &ConnectCancelled);
    if (dialog) {
        Show_Dialog(dialog);

        Setup_Abort_Modem();

        delay = 3600;

        while (process == true) {
            if (Dialog_Abort_Check() == true || ConnectCancelled) {
                status = DIAL_CANCELLED;
                Debug_Printf("Answering cancelled\n");
                if (SerialPort) {
                    char abortbuf[3] = "\r";
                    SerialPort->Write_To_Serial_Port(abortbuf, 2);
                }
                break;
            }

            Call_Back_5168E0(false);

            memset(buffer, 0, sizeof(buffer));
            delay = SerialPort->Get_Modem_Result(delay, buffer, 81, ring ? 15 : -1);
            Debug_Printf("Get_Modem_Result returned %d\n", delay);

            if (delay == ASYNC_ABORT) {
                status = DIAL_CANCELLED;
                Debug_Printf("Answering cancelled\n");
                if (SerialPort) {
                    char abortbuf[3] = "\r";
                    SerialPort->Write_To_Serial_Port(abortbuf, 2);
                }
                break;
            }

            _strupr(buffer);
            if (strlen(buffer)) {
                Debug_Printf("Get_Modem_Result returned string:%s\n", buffer);
            }

            if (!strncmp(buffer, "RING", 4)) {
                Debug_Printf("RING\n");
#line 1647
                Set_Cancel_Dialog_Text(dialog, Fetch_String("TXT_ANSWERING", NULL, __FILE__, __LINE__));
                Debug_Printf("Answering with ATA\n");
                SerialPort->Write_To_Serial_Port("ATA\r", strlen("ATA\r"));
                ring = true;
                delay = ModemWaitCarrier;
            } else if (strstr(buffer, "CONNECT")) {
                memset(ModemConnectString, 0, sizeof(ModemConnectString));
                strncpy(ModemConnectString, buffer, sizeof(ModemConnectString) - 1);
                status = DIAL_CONNECTED;
                Debug_Printf("Result is %s\n", buffer);
                process = false;
            } else if (!strncmp(buffer, "BUSY", 4)) {
                status = DIAL_BUSY;
                Debug_Printf("Result is %s\n", buffer);
                process = false;
            } else if (!strncmp(buffer, "NO C", 4)) {
                status = DIAL_NO_CARRIER;
                Debug_Printf("Result is %s\n", buffer);
                process = false;
            } else if (!strncmp(buffer, "ERRO", 4)) {
                status = DIAL_ERROR;
                Debug_Printf("Result is %s\n", buffer);
#line 1671
                WWMessageBox().Process(Fetch_String("TXT_ERROR_ERROR", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                process = false;
            }

            if (delay <= 0) {
                if (!ring) {
                    delay = 3600;
                } else {
                    if (SerialPort->Get_Modem_Status() & CD_SET) {
                        sprintf(ModemConnectString, "%s", "Connected");
                        status = DIAL_CONNECTED;
                        Debug_Printf("Connected\n");
                    } else {
                        Debug_Printf("NullModemClass::Answer_Modem has timed out\n");
                        if (strlen(buffer)) {
                            Debug_Printf("Answer result is %s\n", buffer);
                        }
#line 1687
                        WWMessageBox().Process(Fetch_String("TXT_ERROR_TIMEOUT", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                        Debug_Printf("Not connected\n");
                        status = DIAL_TIMEOUT;
                    }
                    process = false;
                }
            }
        }

        Remove_Abort_Modem();
        End_Dialog(dialog);
    }

    return status;
}

bool NullModemClass::Hangup_Modem()
{
    int status;
    int delay;
    char buffer[81];
    char escape[4];

    if (PortHandle == INVALID_HANDLE_VALUE || !SerialPort) {
        return false;
    }

    SessionModemFlags.ModemService = false;

    if (SerialPort->Send_Command_To_Modem("AT", '\r', buffer, 81, 90, 1, -1) == MODEM_CMD_OK) {
        SessionModemFlags.ModemService = true;
        return true;
    }

    SerialPort->Set_Serial_DTR(FALSE);
    Delay(53);
    SerialPort->Set_Serial_DTR(TRUE);

    if (SerialPort->Send_Command_To_Modem("AT", '\r', buffer, 81, 90, 1, -1) == MODEM_CMD_OK) {
        SessionModemFlags.ModemService = true;
        return true;
    }

    delay = ModemGuardTime;
    while (delay > 0) {
        delay = SerialPort->Get_Modem_Result(delay, buffer, 81, -1);
    }

    escape[0] = ModemEscapeCode;
    escape[1] = ModemEscapeCode;
    escape[2] = ModemEscapeCode;
    escape[3] = 0;
    SerialPort->Write_To_Serial_Port(escape, 3);

    delay = ModemGuardTime;
    while (delay > 0) {
        delay = SerialPort->Get_Modem_Result(delay, buffer, 81, -1);
        if (!strncmp(buffer, "OK", 2)) {
            break;
        }
    }

    if (SerialPort->Send_Command_To_Modem("ATH", '\r', buffer, 81, ModemHangupDelay, 1, -1) == MODEM_CMD_OK) {
        if (SerialPort->Send_Command_To_Modem("ATZ", '\r', buffer, 81, 60, 1, -1) != MODEM_CMD_OK) {
            SessionModemFlags.ModemService = true;
            return false;
        }
        SessionModemFlags.ModemService = true;
        return true;
    }

    SessionModemFlags.ModemService = true;
    return false;
}

void NullModemClass::Setup_Modem_Echo(void (*func)(char c))
{
    SerialPort->Set_Echo_Function(func);
}

void NullModemClass::Remove_Modem_Echo()
{
}

void NullModemClass::Print_EchoBuf()
{
    for (int i = 0; i < strlen(NullModem.EchoBuf); i++) {
        if (NullModem.EchoBuf[i] == '\r') {
            NullModem.EchoBuf[i] = 1;
        } else if (NullModem.EchoBuf[i] == '\n') {
            NullModem.EchoBuf[i] = 2;
        }
    }
}

void NullModemClass::Reset_EchoBuf()
{
    *EchoBuf = 0;
    EchoCount = 0;
}

int NullModemClass::Abort_Modem()
{
    Call_Back();
    Windows_Message_Handler();

    int key = Keyboard->Check();
    if (key) {
        Keyboard->Clear();
        if (key == VK_ESCAPE) {
            ConnectCancelled = true;
            return ASYNC_ABORT;
        }
    }

    return ConnectCancelled ? ASYNC_ABORT : 0;
}

void NullModemClass::Setup_Abort_Modem()
{
    SerialPort->Set_Abort_Function(Abort_Modem);
    ConnectCancelled = false;
}

void NullModemClass::Remove_Abort_Modem()
{
    SerialPort->Set_Abort_Function(NULL);
    ConnectCancelled = false;
}

int NullModemClass::Change_IRQ_Priority(int)
{
    return 0;
}

int NullModemClass::Get_Modem_Status()
{
    char buffer[81];

    int modemstatus = SerialPort->Get_Modem_Status();
    if (SerialPort->Send_Command_To_Modem("AT", '\r', buffer, 81, 90, 1, -1) == MODEM_CMD_OK) {
        modemstatus &= ~CD_SET;
    }
    return modemstatus;
}

int NullModemClass::Send_Modem_Command(char * command, char terminator, char * buffer, int buflen, int delay, int retries)
{
    return SerialPort->Send_Command_To_Modem(command, terminator, buffer, buflen, delay, retries, -1);
}

int NullModemClass::Verify_And_Convert_To_Int(char * buffer)
{
    int i;
    int len = strlen(buffer);

    for (i = 0; i < len; i++) {
        if (!isdigit(buffer[i])) {
            return -1;
        }
    }
    return atoi(buffer);
}
