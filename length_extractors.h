#pragma once

#include "splitter.h"
#include "network_headers.h"
#include "simba_headers.h"

class EthernetIpLengthExtractor : public LengthExtractor {
public:
    std::optional<size_t> GetDatagramLength(const std::span<char>& buffer) override {
        throw;
        return 0;
    }
};
#include <iostream>
class PcapLengthExtractor : public LengthExtractor {
public:
    std::optional<size_t> GetDatagramLength(const std::span<char>& buffer) override {
        if (buffer.size() < sizeof(PcapRecHdr)) return std::nullopt;
        const auto* pcap_rec_hdr = reinterpret_cast<const PcapRecHdr*>(buffer.data());
        return pcap_rec_hdr->incl_len + sizeof(PcapRecHdr);
    }
};

class MdpLengthExtractor : public LengthExtractor {
public:
    std::optional<size_t> GetDatagramLength(const std::span<char>& buffer) override {
        if (buffer.size() < sizeof(MdpHdr)) {
            return std::nullopt;
        }
        const auto* mdp_hdr = reinterpret_cast<const MdpHdr*>(buffer.data());
        return mdp_hdr->msg_size;
    }
    int ctr = 0;
};
