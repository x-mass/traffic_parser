#pragma once

#include "indexed_datagram.h"
#include "abstract_parser.h"
#include "file_writer.h"
#include "network_headers.h"

#include "moex_spectra_simba/MessageHeader.h"
#include "moex_spectra_simba/OrderBookSnapshot.h"
#include "moex_spectra_simba/OrderExecution.h"
#include "moex_spectra_simba/OrderUpdate.h"
#include <optional>



class SBEParser : public Parser<IndexedDatagram> {
public:
    // SBE could have multiple messages inside. Maybe make Parser class use separate templates
    // for input and output, so we could change processing data types. Then we could have
    // vector returned here.
    SBEParser(std::shared_ptr<ThreadSafeSeqFileWriter> file_writer)
        : file_writer_(std::move(file_writer)) {}

    std::optional<DataType> Parse(const DataType& datagram) override {
        if (!datagram.data) {
            return std::make_optional<DataType>(datagram);
        }

        const MdpHdr* mdp_hdr = reinterpret_cast<const MdpHdr*>(&(*datagram.data->begin()));

        if (mdp_hdr->msg_flags & static_cast<uint16_t>(MdpHdrFlags::kIncremental)) {
        } else {
        }
        if (mdp_hdr->msg_size >= sizeof(mdp_hdr)) {
            std::string to_write;
            if (mdp_hdr->msg_flags & static_cast<uint16_t>(MdpHdrFlags::kIncremental)) {
                to_write = ParseSbeMessages(datagram.data->subspan(sizeof(MdpHdr) + sizeof(IncPktHdr)), true);
            } else {
                to_write = ParseSbeMessages(datagram.data->subspan(sizeof(MdpHdr)), false);
            }
            file_writer_->Write(datagram.index, std::span<char>(to_write.data(), to_write.size()));
        } else {
            throw;
        }
        return MakeCutIndexedDatagram(datagram, sizeof(UdpHdr));
    }
private:
    std::shared_ptr<ThreadSafeSeqFileWriter> file_writer_;

private:

    std::string ParseSbeMessages(std::span<char> data_span, const bool is_incremental) {
        std::ostringstream oss;
        const auto length = data_span.size();
        size_t current_pos = 0;

        while (current_pos < length) {
            std::span<char> header_span = data_span.subspan(current_pos, moex_spectra_simba::MessageHeader::encodedLength());
            moex_spectra_simba::MessageHeader message_header;
            message_header.wrap(header_span.data(), 0, moex_spectra_simba::MessageHeader::sbeSchemaVersion(), header_span.size());
            current_pos += moex_spectra_simba::MessageHeader::encodedLength();

            const auto bytes_left = length - current_pos;
            switch (message_header.templateId()) {
            case moex_spectra_simba::OrderUpdate::sbeTemplateId(): {
                std::span<char> message_body_span = data_span.subspan(current_pos, moex_spectra_simba::OrderUpdate::sbeBlockLength());
                moex_spectra_simba::OrderUpdate order_update;
                order_update.wrapForEncode(message_body_span.data(), 0, message_body_span.size());
                oss << order_update << '\n';
                current_pos += moex_spectra_simba::OrderUpdate::sbeBlockLength();
                break;
            }
            case moex_spectra_simba::OrderExecution::sbeTemplateId(): {
                std::span<char> message_body_span = data_span.subspan(current_pos, moex_spectra_simba::OrderExecution::sbeBlockLength());
                moex_spectra_simba::OrderExecution order_execution;
                order_execution.wrapForEncode(message_body_span.data(), 0, message_body_span.size());
                oss << order_execution << '\n';
                current_pos += moex_spectra_simba::OrderExecution::sbeBlockLength();
                break;
            }
            case moex_spectra_simba::OrderBookSnapshot::sbeTemplateId(): {
                std::span<char> message_body_span = data_span.subspan(current_pos, bytes_left);
                moex_spectra_simba::OrderBookSnapshot order_book_snapshot;
                order_book_snapshot.wrapForEncode(message_body_span.data(), 0, message_body_span.size());
                oss << order_book_snapshot;
                auto& group = order_book_snapshot.noMDEntries();
                while (group.hasNext()) {
                    group.next();
                    oss << group << '\n';
                }
                current_pos += bytes_left;
                break;
            }
            default: {
                current_pos += is_incremental ? message_header.blockLength() : bytes_left;
            }
            }
        }
        return oss.str();
    }
};
