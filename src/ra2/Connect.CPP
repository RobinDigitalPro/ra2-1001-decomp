// C:\RA2\Connect.CPP (level-2 reconstruction of GAME.EXE 1.001)
// ConnectionClass: one logical network connection on top of a CommBufferClass send/receive
// queue. Packets carry an 8-byte header (magic number, code, flags, packet id); ACK-required
// packets are resent until acknowledged, NOACK packets are sent once.
// Class names come from RTTI (ConnectionClass vtable 0x788dcc, CommBufferClass vtable 0x788db4);
// all method, field and variable names are provisional.
#include "GAMECONST.H"
#include <string.h>

// ---- local declarations (to be moved to headers by the integrator) ----

void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)

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
extern TTimerClass<SystemTimerClass> TickCount;     // 0x821cc0 (name provisional)

enum { GAME_INTERNET = 4 };
class SessionClass {
public:
    int Type;                                   // +0x0000
};
extern SessionClass Session;                    // 0xa255c8
extern bool SessionHostMigration;               // 0xa27ed4  (Session + 0x290c, meaning provisional)

// Packet header in front of every packet, 8 bytes.
struct CommHeaderType {
    unsigned short MagicNumber;                 // +0
    unsigned char Code;                         // +2, PacketType
    unsigned char Flags;                        // +3, set by Send_Packet in internet games (meaning unknown)
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
    int BufLen;                                 // +0x04
    char * Buffer;                              // +0x08
    int ExtraLen;                               // +0x0c
    void * ExtraBuffer;                         // +0x10
};

// RTTI .?AVCommBufferClass@@ (vtable 0x788db4, one slot), object size 0x58.
// Only the members used here; the rest of the layout is not reconstructed.
class CommBufferClass {
public:
    CommBufferClass(int numsend, int numreceive, int maxlen, int extralen);    // 0x47fce0
    virtual ~CommBufferClass();                                                 // deleting 0x480d80
    void Init();                                                                // 0x47fea0
    int Queue_Send(void * buf, int buflen, void * extrabuf, int extralen);      // 0x47fff0
    int UnQueue_Send(void * buf, int * buflen, int index, void * extrabuf, int * extralen);   // 0x480140
    SendQueueType * Get_Send(int index);                                        // 0x4802c0
    int Queue_Receive(void * buf, int buflen, void * extrabuf, int extralen);   // 0x4802e0
    int UnQueue_Receive(void * buf, int * buflen, int index, void * extrabuf, int * extralen); // 0x4803e0
    ReceiveQueueType * Get_Receive(int index);                                  // 0x480530
    void Add_Delay(unsigned long delay);                                        // 0x480560

    int Max_Receive() { return MaxReceive; }
    int Num_Send() { return SendCount; }
    int Num_Receive() { return ReceiveCount; }

private:
    int MaxSend;                                // +0x04
    int MaxReceive;                             // +0x08
    char Unknown0C[0x28 - 0x0C];
    int SendCount;                              // +0x28
    char Unknown2C[0x38 - 0x2C];
    int ReceiveCount;                           // +0x38
    char Unknown3C[0x58 - 0x3C];
};

// RTTI .?AVConnectionClass@@ (vtable 0x788dcc, 10 slots), object size 0x4c.
class ConnectionClass {
public:
    enum PacketType {
        PACKET_DATA_ACK,
        PACKET_DATA_NOACK,
        PACKET_ACK,
        PACKET_COUNT
    };

    ConnectionClass(int numsend, int numreceive, int maxlen, unsigned short magicnum,
        unsigned long retry_delta, unsigned long max_retries, unsigned long timeout, int extralen);
    virtual ~ConnectionClass();
    virtual void Init();
    virtual int Send_Packet(void * buf, int buflen, int ack_req, unsigned char flags);
    virtual int Receive_Packet(void * buf, int buflen);
    virtual int Get_Packet(void * buf, int * buflen);
    virtual int Service();
    virtual int Virtual_06();                   // returns 0 (meaning unknown)
protected:
    virtual int Service_Send_Queue();
    virtual int Service_Receive_Queue();
    virtual int Send(char * buf, int buflen, void * extrabuf, int extralen, bool global) = 0;
public:
    static unsigned long Time();
    static char * Command_Name(int command);

    CommBufferClass * Queue;                    // +0x04
    int NumRetries;                             // +0x08, resends of ACK packets
    unsigned long PacketsLost;                  // +0x0c, NOACK packets missing
    int PercentLost;                            // +0x10
    int ReceiveErrors;                          // +0x14
    int BadMagicCount;                          // +0x18
    int MaxPacketLen;                           // +0x1c, including the header
    char * PacketBuf;                           // +0x20
    unsigned short MagicNum;                    // +0x24
    unsigned long RetryDelta;                   // +0x28
    unsigned long MaxRetries;                   // +0x2c, -1 = unlimited
    unsigned long Timeout;                      // +0x30, -1 = unlimited
    unsigned long NumRecNoAck;                  // +0x34
    unsigned long NumRecAck;                    // +0x38
    unsigned long NumSendNoAck;                 // +0x3c
    unsigned long NumSendAck;                   // +0x40
    unsigned long LastSeqID;                    // +0x44
    unsigned long LastReadID;                   // +0x48
};

// Connection used for global (broadcast) packets; Ipx + 0x4c (0xa28614). Name provisional.
extern ConnectionClass * GlobalChannel;

// ---- ConnectionClass ----

ConnectionClass::ConnectionClass(int numsend, int numreceive, int maxlen, unsigned short magicnum,
    unsigned long retry_delta, unsigned long max_retries, unsigned long timeout, int extralen)
{
    MaxPacketLen = maxlen + sizeof(CommHeaderType);
    MagicNum = magicnum;
    RetryDelta = retry_delta;
    MaxRetries = max_retries;
    Timeout = timeout;
    PacketBuf = new char[MaxPacketLen];
    Queue = new CommBufferClass(numsend, numreceive, MaxPacketLen, extralen);
}

ConnectionClass::~ConnectionClass()
{
    delete [] PacketBuf;
    delete Queue;
}

void ConnectionClass::Init()
{
    NumRecNoAck = 0;
    NumRecAck = 0;
    NumSendNoAck = 0;
    NumSendAck = 0;
    NumRetries = 0;
    PacketsLost = 0;
    PercentLost = 0;
    ReceiveErrors = 0;
    BadMagicCount = 0;
    LastSeqID = 0xFFFFFFFF;
    LastReadID = 0xFFFFFFFF;
    Queue->Init();
}

int ConnectionClass::Send_Packet(void * buf, int buflen, int ack_req, unsigned char flags)
{
    ((CommHeaderType *)PacketBuf)->MagicNumber = MagicNum;
    if (ack_req) {
        ((CommHeaderType *)PacketBuf)->Code = PACKET_DATA_ACK;
        ((CommHeaderType *)PacketBuf)->PacketID = NumSendAck;
        Debug_Printf("NumSendAck = %d\n", NumSendAck);
    } else {
        ((CommHeaderType *)PacketBuf)->Code = PACKET_DATA_NOACK;
        ((CommHeaderType *)PacketBuf)->PacketID = NumSendNoAck;
    }

    if (Session.Type == GAME_INTERNET && SessionHostMigration) {
        ((CommHeaderType *)PacketBuf)->Flags = flags;
    }

    if (MaxPacketLen < buflen) {
        Debug_Printf("MaxPacketLen = %d\n", MaxPacketLen);
        Debug_Printf("buflen = %d\n", buflen);
    } else {
        memcpy(PacketBuf + sizeof(CommHeaderType), buf, buflen);
        if (Queue->Queue_Send(PacketBuf, buflen + sizeof(CommHeaderType), NULL, 0)) {
            if (ack_req) {
                NumSendAck++;
            } else {
                NumSendNoAck++;
            }
            return 1;
        }
    }
    return 0;
}

int ConnectionClass::Receive_Packet(void * buf, int buflen)
{
    CommHeaderType * packet = (CommHeaderType *)buf;
    CommHeaderType ackpacket;
    SendQueueType * send_entry;
    ReceiveQueueType * rec_entry;
    CommHeaderType * entry_header;
    int i;

    if (packet->MagicNumber != MagicNum) {
        BadMagicCount++;
        return 0;
    }

    if (packet->Code == PACKET_ACK) {
        for (i = 0; i < Queue->Num_Send(); i++) {
            send_entry = Queue->Get_Send(i);
            if (send_entry) {
                entry_header = (CommHeaderType *)send_entry->Buffer;
                if (packet->PacketID == entry_header->PacketID && entry_header->Code == PACKET_DATA_ACK) {
                    send_entry->IsACK = 1;
                    break;
                }
            }
        }
        return 1;
    }

    if (packet->Code == PACKET_DATA_NOACK) {
        if (Queue->Max_Receive() - Queue->Num_Receive() <= 1) {
            ReceiveErrors++;
            Debug_Printf("Error - ConnectClass::Receive_Packet Queue full on PACKET_DATA_NOACK\n");
            return 0;
        }
        if (!Queue->Queue_Receive(buf, buflen, NULL, 0)) {
#line 330 "C:\\RA2\\Connect.CPP"
            Debug_Printf("Error - unable to queue incoming packet. %s %s\n", __FILE__, __LINE__);
            ReceiveErrors++;
            return 0;
        }
        NumRecNoAck++;
        PacketsLost = packet->PacketID - NumRecNoAck + 1;
        if (packet->PacketID) {
            PercentLost = 100 - (NumRecNoAck * 100) / (packet->PacketID + 1);
        }
        return 1;
    }

    if (packet->Code == PACKET_DATA_ACK) {
        if (packet->PacketID > LastSeqID || LastSeqID == 0xFFFFFFFF) {
            // A packet that is already queued is only acknowledged again.
            for (i = 0; i < Queue->Num_Receive(); i++) {
                rec_entry = Queue->Get_Receive(i);
                if (rec_entry) {
                    entry_header = (CommHeaderType *)rec_entry->Buffer;
                    if (entry_header->Code == PACKET_DATA_ACK && entry_header->PacketID == packet->PacketID) {
                        goto send_ack;
                    }
                }
            }
            if (Queue->Max_Receive() - Queue->Num_Receive() <= 1 && packet->PacketID != LastSeqID + 1) {
                Debug_Printf("Error - ConnectClass::Receive_Packet Queue full on PACKET_DATA_ACK\n");
                return 0;
            }
            if (!Queue->Queue_Receive(buf, buflen, NULL, 0)) {
                Debug_Printf("Error - ConnectClass::Receive_Packet Queue->Queue_Receive error\n");
                return 0;
            }
            NumRecAck++;
            if (packet->PacketID == LastSeqID + 1) {
                // Advance LastSeqID over the queued packets that directly follow it.
                bool found;
                LastSeqID = packet->PacketID;
                do {
                    found = false;
                    for (i = 0; i < Queue->Num_Receive(); i++) {
                        rec_entry = Queue->Get_Receive(i);
                        if (rec_entry) {
                            entry_header = (CommHeaderType *)rec_entry->Buffer;
                            if (entry_header->Code == PACKET_DATA_ACK && entry_header->PacketID == LastSeqID + 1) {
                                LastSeqID = entry_header->PacketID;
                                found = true;
                                break;
                            }
                        }
                    }
                } while (found);
            }
        }

send_ack:
        ackpacket.MagicNumber = MagicNum;
        ackpacket.Code = PACKET_ACK;
        ackpacket.Flags = 0;
        ackpacket.PacketID = packet->PacketID;
        Send((char *)&ackpacket, sizeof(CommHeaderType), NULL, 0, this == GlobalChannel);
        return 1;
    }

    Debug_Printf("Error - ConnectClass::Receive_Packet did not understand packet->Code\n");
    return 0;
}

int ConnectionClass::Get_Packet(void * buf, int * buflen)
{
    ReceiveQueueType * rec_entry;
    CommHeaderType * entry_header;
    int packetlen;
    int i;

    for (i = 0; i < Queue->Num_Receive(); i++) {
        rec_entry = Queue->Get_Receive(i);
        if (rec_entry && !rec_entry->IsRead) {
            entry_header = (CommHeaderType *)rec_entry->Buffer;
            if (entry_header->Code == PACKET_DATA_ACK && entry_header->PacketID == LastReadID + 1) {
                LastReadID = entry_header->PacketID;
            } else if (entry_header->Code != PACKET_DATA_NOACK) {
                continue;
            }
            rec_entry->IsRead = 1;
            packetlen = rec_entry->BufLen - sizeof(CommHeaderType);
            if (packetlen > 0) {
                memcpy(buf, rec_entry->Buffer + sizeof(CommHeaderType), packetlen);
            }
            *buflen = packetlen;
            return 1;
        }
    }
    return 0;
}

int ConnectionClass::Service()
{
    if (Service_Send_Queue() && Service_Receive_Queue()) {
        return 1;
    }
    return 0;
}

int ConnectionClass::Virtual_06()
{
    return 0;
}

int ConnectionClass::Service_Send_Queue()
{
    SendQueueType * send_entry;
    unsigned long curtime;
    int num_entries;
    int bad_conn = 0;
    int i;

    // Remove the entries that have been acknowledged.
    for (i = 0; i < Queue->Num_Send(); i++) {
        send_entry = Queue->Get_Send(i);
        if (send_entry->IsACK) {
            if (((CommHeaderType *)send_entry->Buffer)->Code == PACKET_DATA_ACK) {
                Queue->Add_Delay(Time() - send_entry->FirstTime);
            }
            Queue->UnQueue_Send(NULL, NULL, i, NULL, NULL);
            i--;
        }
    }

    // Send or resend the remaining entries.
    num_entries = Queue->Num_Send();
    for (i = 0; i < num_entries; i++) {
        send_entry = Queue->Get_Send(i);
        if (send_entry->IsACK) {
            continue;
        }
        curtime = Time();
        if (curtime - send_entry->LastTime > RetryDelta) {
            Send(send_entry->Buffer, send_entry->BufLen, send_entry->ExtraBuffer, send_entry->ExtraLen,
                this == GlobalChannel);
            send_entry->LastTime = curtime;
            if (send_entry->SendCount == 0) {
                send_entry->FirstTime = curtime;
                if (((CommHeaderType *)send_entry->Buffer)->Code == PACKET_DATA_NOACK) {
                    send_entry->IsACK = 1;
                }
            } else {
                NumRetries++;
            }
            send_entry->SendCount++;
            if (MaxRetries != 0xFFFFFFFF && send_entry->SendCount > MaxRetries) {
                bad_conn = 1;
                send_entry->IsBad = 1;
            }
            if (Timeout != 0xFFFFFFFF && send_entry->LastTime - send_entry->FirstTime > Timeout) {
                bad_conn = 1;
                send_entry->IsBad = 1;
            }
        }
    }

    if (bad_conn) {
        Debug_Printf("ConnectionClass::Service_Send_Queue bad connection\n");
        return 0;
    }
    return 1;
}

int ConnectionClass::Service_Receive_Queue()
{
    ReceiveQueueType * rec_entry;
    CommHeaderType * packet_hdr;
    int i;

    for (i = 0; i < Queue->Num_Receive(); i++) {
        rec_entry = Queue->Get_Receive(i);
        if (rec_entry->IsRead) {
            packet_hdr = (CommHeaderType *)rec_entry->Buffer;
            if (packet_hdr->Code == PACKET_DATA_NOACK || packet_hdr->PacketID < LastSeqID) {
                Queue->UnQueue_Receive(NULL, NULL, i, NULL, NULL);
                i--;
            }
        }
    }
    return 1;
}

unsigned long ConnectionClass::Time()
{
    return TickCount.Value();
}

char * ConnectionClass::Command_Name(int command)
{
    static char * _names[PACKET_COUNT] = {
        "ADATA",
        "NDATA",
        "ACK",
    };

    if (command >= PACKET_DATA_ACK && command < PACKET_COUNT) {
        return _names[command];
    }
    return NULL;
}
