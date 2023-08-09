#pragma once
#include "simba_parser.h"
#include "abstract_parser.h"
#include "network_headers.h"
#include "simba_headers.h"
#include "file_writer.h"
#include "indexed_datagram.h"

#include <optional>
#include <vector>

class PcapRecParser : public Parser<IndexedDatagram> {
public:
    std::optional<DataType> Parse(const DataType& datagram) override {
        return MakeCutIndexedDatagram(datagram, sizeof(PcapRecHdr));
    }
};

class EthernetParser : public Parser<IndexedDatagram> {
public:
    std::optional<DataType> Parse(const DataType& datagram) override {
        const EthernetHdr* ethernet_hdr = reinterpret_cast<const EthernetHdr*>(&(*datagram.data->begin()));

        if (ntohs(ethernet_hdr->ethertype) != static_cast<uint16_t>(Ethertypes::kIPv4)) {
            return MakeEmptyDatagram(datagram);
        }

        return MakeCutIndexedDatagram(datagram, sizeof(EthernetHdr));
    }
};

class IPParser : public Parser<IndexedDatagram> {
public:
    std::optional<DataType> Parse(const DataType& datagram) override {
        if (!datagram.data) {
            return datagram;
        }
        const IpHdr* ip_hdr = reinterpret_cast<const IpHdr*>(&(*datagram.data->begin()));
        if (!(ip_hdr->protocol & static_cast<uint16_t>(IpProtocols::kUDP))) {
            return MakeEmptyDatagram(datagram);
        }
        return MakeCutIndexedDatagram(datagram, sizeof(IpHdr));
    }
};

class UDPParser : public Parser<IndexedDatagram> {
public:
    std::optional<DataType> Parse(const DataType& datagram) override {
        if (!datagram.data) {
            return datagram;
        }
        return MakeCutIndexedDatagram(datagram, sizeof(UdpHdr));
    }
};

class FileWriterParser : public Parser<IndexedDatagram> {
public:
    FileWriterParser(std::shared_ptr<ThreadSafeSeqFileWriter> file_writer)
    : file_writer_(std::move(file_writer)) {}

    std::optional<DataType> Parse(const DataType& datagram) override {
        file_writer_->Write(
            datagram.index,
            datagram.data
            ? *datagram.data
            : std::span<char>{}
        );
        return std::nullopt;
    }

private:
    std::shared_ptr<ThreadSafeSeqFileWriter> file_writer_;
};
