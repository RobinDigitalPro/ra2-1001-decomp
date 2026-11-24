// unidentified translation unit starting at 0x47fcc0, probably the original COMBUF.CPP (not proven)
// level-2 reconstruction of GAME.EXE 1.001
// CommBufferClass: the send and receive queues below ConnectionClass (Connect.CPP).
// Class name from RTTI (.?AVCommBufferClass@@, vtable 0x788db4, one slot); object size 0x58.
// All method, field and variable names are provisional.
//
// TU span 0x47fcc0..0x480d9b: 0x47fcc0 is the 16-byte zeroing static initializer (shared shape,
// already matched elsewhere; the header that produces it is not reproduced here), 0x47fce0..0x480d77
// the methods, 0x480d80 the compiler-generated scalar deleting destructor. The next TU starts with
// the initializer at 0x480da0.
//
// Mono_Debug_Print 0x480650 matches with TS COMBUF.CPP's header local and its two self-assignments
// in the send loop (w53_TU_47FCC0.claims.json); all methods of this unit are now claimed.
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0); // level-2 1.001: zeroing initializer 0x7fcc0 of this unit
#include <string.h>
#include <stdio.h>

// ---- local declarations (to be moved to headers by the integrator) ----

void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)

// Monochrome debug screen. Not polymorphic; layout not reconstructed.
class MonoClass {
public:
    static MonoClass * Get_Page(int page);      // 0x59a840, returns Pages[page] (0xa58a58)
    void Set_Cursor(int x, int y);              // 0x59b030
    void Clear();                               // 0x59b080
    void Printf(char const * text, ...);        // 0x59b5e0
};

// Declared in Connect.CPP; only the static member used here.
class ConnectionClass {
public:
    static char * Command_Name(int command);    // 0x481830
};

// Packet header in front of every packet, 8 bytes.
struct CommHeaderType {
    unsigned short MagicNumber;                 // +0
    unsigned char Code;                         // +2, PacketType
    unsigned char Flags;                        // +3
    unsigned long PacketID;                     // +4
};

// Send queue entry, 0x20 bytes.
struct SendQueueType {
    unsigned IsActive : 1;
    unsigned IsACK : 1;
    unsigned IsBad : 1;                         // retry or timeout limit exceeded
    unsigned long FirstTime;                    // +0x04
    unsigned long LastTime;                     // +0x08
    unsigned long SendCount;                    // +0x0c
    int BufLen;                                 // +0x10
    char * Buffer;                              // +0x14
    int ExtraLen;                               // +0x18
    void * ExtraBuffer;                         // +0x1c
};

// Receive queue entry, 0x14 bytes.
struct ReceiveQueueType {
    unsigned IsActive : 1;
    unsigned IsRead : 1;
    unsigned IsACK : 1;                         // printed by the mono debug screens
    int BufLen;                                 // +0x04
    char * Buffer;                              // +0x08
    int ExtraLen;                               // +0x0c
    void * ExtraBuffer;                         // +0x10
};

class CommBufferClass {
public:
    CommBufferClass(int numsend, int numreceive, int maxlen, int extralen);    // 0x47fce0
    virtual ~CommBufferClass();                                                 // 0x47fdf0
    void Init();                                                                // 0x47fea0
    void Init_Send_Queue();                                                     // 0x47ff80
    int Queue_Send(void * buf, int buflen, void * extrabuf, int extralen);      // 0x47fff0
    int UnQueue_Send(void * buf, int * buflen, int index, void * extrabuf, int * extralen);   // 0x480140
    SendQueueType * Get_Send(int index);                                        // 0x4802c0
    int Queue_Receive(void * buf, int buflen, void * extrabuf, int extralen);   // 0x4802e0
    int UnQueue_Receive(void * buf, int * buflen, int index, void * extrabuf, int * extralen); // 0x4803e0
    ReceiveQueueType * Get_Receive(int index);                                  // 0x480530
    void Add_Delay(unsigned long delay);                                        // 0x480560
    unsigned long Avg_Response_Time();                                          // 0x4805d0
    unsigned long Max_Response_Time();                                          // 0x4805e0
    void Reset_Response_Time(bool clear);                                       // 0x4805f0
    void Configure_Debug(int offset, int size, char ** names, int namestart, int namecount); // 0x480620
    void Mono_Debug_Print(int refresh);                                         // 0x480650
    void Mono_Debug_Print2(int refresh);                                        // 0x4808e0

    int Max_Receive() { return MaxReceive; }
    int Num_Send() { return SendCount; }
    int Num_Receive() { return ReceiveCount; }

private:
    int MaxSend;                                // +0x04
    int MaxReceive;                             // +0x08
    int MaxPacketSize;                          // +0x0c
    int MaxExtraSize;                           // +0x10
    unsigned long DelaySum;                     // +0x14
    unsigned long NumDelay;                     // +0x18, saturates at 256
    unsigned long MeanDelay;                    // +0x1c
    unsigned long MaxDelay;                     // +0x20
    SendQueueType * SendQueue;                  // +0x24
    int SendCount;                              // +0x28
    unsigned long SendTotal;                    // +0x2c
    int * SendIndex;                            // +0x30
    ReceiveQueueType * ReceiveQueue;            // +0x34
    int ReceiveCount;                           // +0x38
    unsigned long ReceiveTotal;                 // +0x3c
    int * ReceiveIndex;                         // +0x40
    int DebugOffset;                            // +0x44, offset of the shown data word in a packet
    int DebugSize;                              // +0x48, 0 = off, 1, 2 or 4 bytes
    char ** DebugNames;                         // +0x4c
    int DebugNameStart;                         // +0x50
    int DebugNameCount;                         // +0x54
};

// ---- CommBufferClass ----

CommBufferClass::CommBufferClass(int numsend, int numreceive, int maxlen, int extralen)
{
    int i;

    MaxSend = numsend;
    MaxReceive = numreceive;
    MaxPacketSize = maxlen;
    MaxExtraSize = extralen;

    SendQueue = new SendQueueType[numsend];
    ReceiveQueue = new ReceiveQueueType[numreceive];
    SendIndex = new int[numsend];
    ReceiveIndex = new int[numreceive];

    for (i = 0; i < MaxSend; i++) {
        SendQueue[i].Buffer = new char[maxlen];
        if (MaxExtraSize > 0) {
            SendQueue[i].ExtraBuffer = new char[MaxExtraSize];
        } else {
            SendQueue[i].ExtraBuffer = NULL;
        }
    }

    for (i = 0; i < MaxReceive; i++) {
        ReceiveQueue[i].Buffer = new char[maxlen];
        if (MaxExtraSize > 0) {
            ReceiveQueue[i].ExtraBuffer = new char[MaxExtraSize];
        } else {
            ReceiveQueue[i].ExtraBuffer = NULL;
        }
    }

    Init();
}

CommBufferClass::~CommBufferClass()
{
    int i;

    for (i = 0; i < MaxSend; i++) {
        delete [] SendQueue[i].Buffer;
        if (SendQueue[i].ExtraBuffer) {
            delete [] SendQueue[i].ExtraBuffer;
        }
    }

    for (i = 0; i < MaxReceive; i++) {
        delete [] ReceiveQueue[i].Buffer;
        if (ReceiveQueue[i].ExtraBuffer) {
            delete [] ReceiveQueue[i].ExtraBuffer;
        }
    }

    delete [] SendQueue;
    delete [] ReceiveQueue;
    delete [] SendIndex;
    delete [] ReceiveIndex;
}

void CommBufferClass::Init()
{
    int i;

    SendTotal = 0;
    ReceiveTotal = 0;

    DelaySum = 0;
    NumDelay = 0;
    MeanDelay = 0;
    MaxDelay = 0;

    SendCount = 0;
    ReceiveCount = 0;

    for (i = 0; i < MaxSend; i++) {
        SendQueue[i].IsActive = 0;
        SendQueue[i].IsACK = 0;
        SendQueue[i].IsBad = 0;
        SendQueue[i].FirstTime = 0;
        SendQueue[i].LastTime = 0;
        SendQueue[i].SendCount = 0;
        SendQueue[i].BufLen = 0;
        SendQueue[i].ExtraLen = 0;
        SendIndex[i] = 0;
    }

    for (i = 0; i < MaxReceive; i++) {
        ReceiveQueue[i].IsActive = 0;
        ReceiveQueue[i].IsRead = 0;
        ReceiveQueue[i].IsACK = 0;
        ReceiveQueue[i].BufLen = 0;
        ReceiveQueue[i].ExtraLen = 0;
        ReceiveIndex[i] = 0;
    }

    DebugOffset = 0;
    DebugSize = 0;
    DebugNames = NULL;
    DebugNameCount = 0;
}

void CommBufferClass::Init_Send_Queue()
{
    int i;

    SendCount = 0;

    for (i = 0; i < MaxSend; i++) {
        SendQueue[i].IsActive = 0;
        SendQueue[i].IsACK = 0;
        SendQueue[i].IsBad = 0;
        SendQueue[i].FirstTime = 0;
        SendQueue[i].LastTime = 0;
        SendQueue[i].SendCount = 0;
        SendQueue[i].BufLen = 0;
        SendQueue[i].ExtraLen = 0;
        SendIndex[i] = 0;
    }
}

int CommBufferClass::Queue_Send(void * buf, int buflen, void * extrabuf, int extralen)
{
    int i;
    int index;

    if (SendCount == MaxSend || buflen > MaxPacketSize) {
        if (SendCount == MaxSend) {
            Debug_Printf("Queue_Send - No room in send queue\n");
            return 0;
        }
        Debug_Printf("buflen > MaxPacketSize by %d bytes\n", MaxPacketSize - buflen);
        return 0;
    }

    index = -1;
    for (i = 0; i < MaxSend; i++) {
        if (SendQueue[i].IsActive == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return 0;
    }

    SendQueue[index].IsActive = 1;
    SendQueue[index].IsACK = 0;
    SendQueue[index].IsBad = 0;
    SendQueue[index].FirstTime = 0;
    SendQueue[index].LastTime = 0;
    SendQueue[index].SendCount = 0;
    SendQueue[index].BufLen = buflen;
    memcpy(SendQueue[index].Buffer, buf, buflen);

    if (extrabuf != NULL && extralen > 0 && extralen <= MaxExtraSize) {
        memcpy(SendQueue[index].ExtraBuffer, extrabuf, extralen);
        SendQueue[index].ExtraLen = extralen;
    } else {
        SendQueue[index].ExtraLen = 0;
    }

    SendIndex[SendCount] = index;
    SendCount++;
    SendTotal++;

    return 1;
}

int CommBufferClass::UnQueue_Send(void * buf, int * buflen, int index, void * extrabuf, int * extralen)
{
    int i;

    if (SendCount == 0 || SendQueue[SendIndex[index]].IsActive == 0) {
        return 0;
    }

    if (buf != NULL) {
        memcpy(buf, SendQueue[SendIndex[index]].Buffer, SendQueue[SendIndex[index]].BufLen);
        *buflen = SendQueue[SendIndex[index]].BufLen;
    }

    if (extrabuf != NULL && extralen != NULL) {
        memcpy(extrabuf, SendQueue[SendIndex[index]].ExtraBuffer, SendQueue[SendIndex[index]].ExtraLen);
        *extralen = SendQueue[SendIndex[index]].ExtraLen;
    }

    SendQueue[SendIndex[index]].IsActive = 0;
    SendQueue[SendIndex[index]].IsACK = 0;
    SendQueue[SendIndex[index]].IsBad = 0;
    SendQueue[SendIndex[index]].FirstTime = 0;
    SendQueue[SendIndex[index]].LastTime = 0;
    SendQueue[SendIndex[index]].SendCount = 0;
    SendQueue[SendIndex[index]].BufLen = 0;
    SendQueue[SendIndex[index]].ExtraLen = 0;

    for (i = index; i < SendCount - 1; i++) {
        SendIndex[i] = SendIndex[i + 1];
    }
    SendIndex[SendCount - 1] = 0;
    SendCount--;

    return 1;
}

SendQueueType * CommBufferClass::Get_Send(int index)
{
    if (SendQueue[SendIndex[index]].IsActive == 0) {
        return NULL;
    }
    return &SendQueue[SendIndex[index]];
}

int CommBufferClass::Queue_Receive(void * buf, int buflen, void * extrabuf, int extralen)
{
    int i;
    int index;

    if (ReceiveCount == MaxReceive || buflen > MaxPacketSize) {
        return 0;
    }

    index = -1;
    for (i = 0; i < MaxReceive; i++) {
        if (ReceiveQueue[i].IsActive == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        Debug_Printf("Can't queue incoming packet - Unable to find free slot in array.\n");
        return 0;
    }

    ReceiveQueue[index].IsActive = 1;
    ReceiveQueue[index].IsRead = 0;
    ReceiveQueue[index].IsACK = 0;
    ReceiveQueue[index].BufLen = buflen;
    memcpy(ReceiveQueue[index].Buffer, buf, buflen);

    if (extrabuf != NULL && extralen > 0 && extralen <= MaxExtraSize) {
        memcpy(ReceiveQueue[index].ExtraBuffer, extrabuf, extralen);
        ReceiveQueue[index].ExtraLen = extralen;
    } else {
        ReceiveQueue[index].ExtraLen = 0;
    }

    ReceiveIndex[ReceiveCount] = index;
    ReceiveCount++;
    ReceiveTotal++;

    return 1;
}

int CommBufferClass::UnQueue_Receive(void * buf, int * buflen, int index, void * extrabuf, int * extralen)
{
    int i;

    if (ReceiveCount == 0 || ReceiveQueue[ReceiveIndex[index]].IsActive == 0) {
        return 0;
    }

    if (buf != NULL) {
        memcpy(buf, ReceiveQueue[ReceiveIndex[index]].Buffer, ReceiveQueue[ReceiveIndex[index]].BufLen);
        *buflen = ReceiveQueue[ReceiveIndex[index]].BufLen;
    }

    if (extrabuf != NULL && extralen != NULL) {
        memcpy(extrabuf, ReceiveQueue[ReceiveIndex[index]].ExtraBuffer, ReceiveQueue[ReceiveIndex[index]].ExtraLen);
        *extralen = ReceiveQueue[ReceiveIndex[index]].ExtraLen;
    }

    ReceiveQueue[ReceiveIndex[index]].IsActive = 0;
    ReceiveQueue[ReceiveIndex[index]].IsRead = 0;
    ReceiveQueue[ReceiveIndex[index]].IsACK = 0;
    ReceiveQueue[ReceiveIndex[index]].BufLen = 0;
    ReceiveQueue[ReceiveIndex[index]].ExtraLen = 0;

    for (i = index; i < ReceiveCount - 1; i++) {
        ReceiveIndex[i] = ReceiveIndex[i + 1];
    }
    ReceiveIndex[ReceiveCount - 1] = 0;
    ReceiveCount--;

    return 1;
}

ReceiveQueueType * CommBufferClass::Get_Receive(int index)
{
    if (ReceiveQueue[ReceiveIndex[index]].IsActive == 0) {
        return NULL;
    }
    return &ReceiveQueue[ReceiveIndex[index]];
}

// Running mean of the response times over the last 256 samples, plus the maximum.
void CommBufferClass::Add_Delay(unsigned long delay)
{
    int roundoff = 0;

    if (NumDelay == 256) {
        DelaySum -= MeanDelay;
        DelaySum += delay;
        if ((DelaySum & 0x00ff) > 127) {
            roundoff = 1;
        }
        MeanDelay = (DelaySum >> 8) + roundoff;
    } else {
        NumDelay++;
        DelaySum += delay;
        MeanDelay = DelaySum / NumDelay;
    }

    if (delay > MaxDelay) {
        MaxDelay = delay;
    }
}

unsigned long CommBufferClass::Avg_Response_Time()
{
    return MeanDelay;
}

unsigned long CommBufferClass::Max_Response_Time()
{
    return MaxDelay;
}

void CommBufferClass::Reset_Response_Time(bool clear)
{
    if (clear) {
        DelaySum = 0;
        NumDelay = 0;
        MeanDelay = 0;
        MaxDelay = 0;
    } else {
        DelaySum = MeanDelay;
        NumDelay = 1;
        MaxDelay = MeanDelay;
    }
}

void CommBufferClass::Configure_Debug(int offset, int size, char ** names, int namestart, int namecount)
{
    DebugOffset = offset;
    DebugSize = size;
    DebugNames = names;
    DebugNameStart = namestart;
    DebugNameCount = namecount;
}

// Compact display: three columns of 16 entries per queue.
void CommBufferClass::Mono_Debug_Print(int refresh)
{
    static int send_col[] = {1, 14, 28};
    static int receive_col[] = {40, 54, 68};
    int i;
    int row;
    int col;
    MonoClass * mono;
    CommHeaderType * hdr;

    if (MaxSend <= 16) {
        Mono_Debug_Print2(refresh);
        return;
    }

    mono = MonoClass::Get_Page(4);

    if (refresh) {
        mono->Clear();
        mono->Printf("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
        mono->Printf("\xb3                                                                             \xb3\n");
        mono->Printf("\xb3                                                                             \xb3\n");
        mono->Printf("\xb3                                                                             \xb3\n");
        mono->Printf("\xc3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb4\n");
        mono->Printf("\xb3              Send Queue              \xb3             Receive Queue            \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3 ID  Ct ACK   ID  Ct ACK    ID  Ct ACK\xb3 ID  Rd ACK    ID  Rd ACK   ID  Rd ACK\xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    }

    row = 0;
    col = 0;
    for (i = 0; i < MaxSend; i++) {
        mono->Set_Cursor(send_col[col], row + 8);
        if (SendQueue[i].IsActive) {
            hdr = (CommHeaderType *)SendQueue[i].Buffer; // level-2 1.001: header through a local (as TS COMBUF.CPP)
            hdr->MagicNumber = hdr->MagicNumber;
            hdr->Code = hdr->Code;
            mono->Printf("%4d %2d  %d", hdr->PacketID,
                SendQueue[i].SendCount, SendQueue[i].IsACK);
        } else {
            mono->Printf("____ __  _ ");
        }
        row++;
        if (row > 15) {
            row = 0;
            col++;
        }
    }

    row = 0;
    col = 0;
    for (i = 0; i < MaxReceive; i++) {
        mono->Set_Cursor(receive_col[col], row + 8);
        if (ReceiveQueue[i].IsActive) {
            hdr = (CommHeaderType *)ReceiveQueue[i].Buffer; // level-2 1.001: as TS COMBUF.CPP
            mono->Printf("%4d  %d  %d", hdr->PacketID,
                ReceiveQueue[i].IsRead, ReceiveQueue[i].IsACK);
        } else {
            mono->Printf("____  _  _ ");
        }
        row++;
        if (row > 15) {
            row = 0;
            col++;
        }
    }
}

// Detailed display: one line per entry with the packet type and an optional data word.
void CommBufferClass::Mono_Debug_Print2(int refresh)
{
    int i;
    char txt[80];
    int val;
    MonoClass * mono;
    CommHeaderType * hdr;

    mono = MonoClass::Get_Page(4);

    if (refresh) {
        mono->Clear();
        mono->Printf("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
        mono->Printf("\xb3                                                                             \xb3\n");
        mono->Printf("\xb3                                                                             \xb3\n");
        mono->Printf("\xb3                                                                             \xb3\n");
        mono->Printf("\xc3\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb4\n");
        mono->Printf("\xb3              Send Queue              \xb3             Receive Queue            \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3 ID  Ct Type   Data  Name         ACK \xb3 ID  Rd Type   Data  Name         ACK \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xb3                                      \xb3                                      \xb3\n");
        mono->Printf("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    }

    for (i = 0; i < MaxSend; i++) {
        mono->Set_Cursor(1, i + 8);
        if (SendQueue[i].IsActive) {
            hdr = (CommHeaderType *)SendQueue[i].Buffer;
            sprintf(txt, "%4d %2d %-5s  ", hdr->PacketID, SendQueue[i].SendCount,
                ConnectionClass::Command_Name(hdr->Code));
            if (DebugSize && (DebugOffset + DebugSize) <= SendQueue[i].BufLen) {
                switch (DebugSize) {
                case 1:
                    val = *((char *)SendQueue[i].Buffer + DebugOffset);
                    break;
                case 2:
                    val = *((short *)(SendQueue[i].Buffer + DebugOffset));
                    break;
                default:
                    val = *((int *)(SendQueue[i].Buffer + DebugOffset));
                    break;
                }
                sprintf(txt + strlen(txt), "%4d  ", val);
                if (DebugNameCount > 0 && val >= 0 && val < DebugNameCount) {
                    sprintf(txt + strlen(txt), "%-12s  %x", DebugNames[val - DebugNameStart], SendQueue[i].IsACK);
                } else {
                    sprintf(txt + strlen(txt), "              %x", SendQueue[i].IsACK);
                }
            } else {
                sprintf(txt + strlen(txt), "                    %x", SendQueue[i].IsACK);
            }
            mono->Printf("%s", txt);
        } else {
            mono->Printf("____ __                            _");
        }
    }

    for (i = 0; i < MaxReceive; i++) {
        mono->Set_Cursor(40, i + 8);
        if (ReceiveQueue[i].IsActive) {
            hdr = (CommHeaderType *)ReceiveQueue[i].Buffer;
            sprintf(txt, "%4d %2d %-5s  ", hdr->PacketID, ReceiveQueue[i].IsRead,
                ConnectionClass::Command_Name(hdr->Code));
            if (DebugSize && (DebugOffset + DebugSize) <= ReceiveQueue[i].BufLen) {
                switch (DebugSize) {
                case 1:
                    val = *((char *)ReceiveQueue[i].Buffer + DebugOffset);
                    break;
                case 2:
                    val = *((short *)(ReceiveQueue[i].Buffer + DebugOffset));
                    break;
                default:
                    val = *((int *)(ReceiveQueue[i].Buffer + DebugOffset));
                    break;
                }
                sprintf(txt + strlen(txt), "%4d  ", val);
                if (DebugNameCount > 0 && val >= 0 && val < DebugNameCount) {
                    sprintf(txt + strlen(txt), "%-12s  %x", DebugNames[val - DebugNameStart], ReceiveQueue[i].IsACK);
                } else {
                    sprintf(txt + strlen(txt), "              %x", ReceiveQueue[i].IsACK);
                }
            } else {
                sprintf(txt + strlen(txt), "                    %x", ReceiveQueue[i].IsACK);
            }
            mono->Printf("%s", txt);
        } else {
            mono->Printf("____ __                            _");
        }
    }
}
