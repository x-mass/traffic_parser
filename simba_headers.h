#pragma once

#include <cstdint>

#pragma pack(push, 1)

// Market Data Packet Header
struct MdpHdr {
    uint32_t msg_seq_num;
    uint16_t msg_size;
    uint16_t msg_flags;
    uint64_t sending_time;
};

struct IncPktHdr {
    uint64_t tx_time;
    uint32_t exchg_tr_sid;
};

#pragma pack(pop)

enum class MdpHdrFlags : uint16_t {
    kLastFragment     = 0x1,
    kFirstSnapshotMsg = 0x2,
    kLastSnapshotMsg  = 0x4,
    kIncremental      = 0x8,
    kPossDupFlag      = 0x10,
};
