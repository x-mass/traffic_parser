#pragma once
#pragma pack(push, 1)

struct PcapHdr {
    uint32_t magic_number;
    uint16_t version_major;
    uint16_t version_minor;
    int32_t this_zone;
    uint32_t sigfigs;
    uint32_t snaplen;
    uint32_t network;
};

struct PcapRecHdr {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t incl_len;
    uint32_t orig_len;
};

struct EthernetHdr {
    uint8_t dest_mac[6];
    uint8_t src_mac[6];
    uint16_t ethertype;
};

// TODO: add enums for ethertype (as ETHERTYPE_IP, etc.)

struct IpHdr {
    uint8_t version_and_header_length;
    uint8_t differentiated_services;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags_and_fragment_offset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t source_ip;
    uint32_t dest_ip;
};

struct UdpHdr {
    uint16_t src_port;
    uint16_t dest_port;
    uint16_t length;
    uint16_t checksum;
};

#pragma pack(pop)

enum class Ethertypes : uint16_t {
    kIPv4 = 0x0800,
    kARP = 0x0806,
    kIPv6 = 0x86DD,
    kVLAN = 0x8100,
};

enum class IpProtocols : uint8_t {
    kTCP = 6,
    kUDP = 17,
};
