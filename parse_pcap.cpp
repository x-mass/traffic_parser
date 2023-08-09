#include "length_extractors.h"
#include "network_headers.h"
#include "parsers.h"
#include "splitter.h"
#include "queue.h"
#include "thread_pool.h"

#include <iostream>
#include <memory>


class PcapFileProcessor {
public:
    PcapFileProcessor(size_t read_chunk_size, size_t parsers_threads, const std::string output_filename)
        : read_chunk_size_(read_chunk_size)
        , splitter_(Splitter(std::make_unique<PcapLengthExtractor>()))
        , datagram_counter_(0)
        , output_filename_(output_filename)
        , parsers_threads_(parsers_threads) {}

    bool ProcessTraffic(std::ifstream& infile) {
        PcapHdr pcap_header;
        infile.read(reinterpret_cast<char*>(&pcap_header), sizeof(pcap_header));
        if (!IsValidPcapHdr(pcap_header)) {
            std::cerr << "File will not be parsed" << std::endl;
            return false;
        }
        auto parser_chain = ParserChain(
            PcapRecParser(),
            EthernetParser(),
            IPParser(),
            UDPParser(),
            FileWriterParser(std::make_shared<ThreadSafeSeqFileWriter>(output_filename_, 1024*1024*64))
        );
        ThreadPool pool(parsers_threads_, [this, &parser_chain]() {
            ConsumeDatagrams<decltype(parser_chain)>(queue_, parser_chain);
        });
        while (infile) {
            ReadChunkFromFile(infile);
            SplitPacketsFromBuffer();
            DispatchPacketsForParsing();
        }
        queue_.terminate();
        return true;
    }

private:
    size_t read_chunk_size_;
    Splitter splitter_;
    BlockingMPMCQueue<std::pair<size_t, std::vector<char>>> queue_;
    std::vector<char> buffer_;
    std::vector<std::vector<char>> datagrams_;
    std::string output_filename_;
    size_t parsers_threads_;
    int datagram_counter_;

    void ReadChunkFromFile(std::ifstream& infile) {
        size_t old_size = buffer_.size();
        buffer_.resize(old_size + read_chunk_size_);
        infile.read(reinterpret_cast<char*>(buffer_.data()) + old_size, read_chunk_size_);
        std::streamsize bytes_read = infile.gcount();
        buffer_.resize(old_size + bytes_read);
    }

    void SplitPacketsFromBuffer() {
        datagrams_ = splitter_.SplitDatagrams(buffer_);
    }

    void DispatchPacketsForParsing() {
        for (auto& datagram : datagrams_) {
        queue_.push(std::make_pair(
            datagram_counter_++,
            std::move(datagram)
        ));
        }
    }

    template <typename ParserChainType>
    void ConsumeDatagrams(
        BlockingMPMCQueue<std::pair<size_t, std::vector<char>>>& queue,
        ParserChainType parser_chain
    ) {
        while (true) {
            auto data = queue.pop();
            if (!data) {
                // Is terminated
                break;
            }
            parser_chain.Parse(IndexedDatagram{
                data->first,
                std::span<char>(data->second.data(), data->second.size())
            });
        }
    }

    bool IsValidPcapHdr(const PcapHdr& pcap_hdr) {
        if (
            // First two store time in microseconds, last two — in nanoseconds
            pcap_hdr.magic_number != 0xA1B2C3D4
            && pcap_hdr.magic_number != 0XD4C3B2A1
            && pcap_hdr.magic_number != 0XA1B23C4D
            && pcap_hdr.magic_number != 0X4D3CB2A1
        ) {
            std::cerr << "Invalid PCAP file" << std::endl;
            return false;
        }

        if (pcap_hdr.version_major != 2) {
            std::cerr << "Unsupported PCAP major version: " << pcap_hdr.version_major << std::endl;
            return false;
        }

        if (pcap_hdr.version_minor != 4) {
            std::cerr << "Unsupported PCAP minor version: " << pcap_hdr.version_minor << std::endl;
            return false;
        }

        if (pcap_hdr.snaplen > 65535) {
            std::cerr << "Unusual max length of captured packets: " << pcap_hdr.snaplen << std::endl;
            return false;
        }

        return true;
    }
};


struct Args {
    std::string input_file;
    std::string output_file;
};

Args ParseArgs(int argc, char* argv[]) {
    Args args;

    if (argc < 3) {
        std::cerr << "Usage: pcap_parser <input_file> <output_file>" << std::endl;
        std::exit(1);
    }

    args.input_file = argv[1];
    args.output_file = argv[2];

    return args;
}

int main(int argc, char* argv[]) {
    const auto args = ParseArgs(argc, argv);

    std::ifstream infile(args.input_file, std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Could not open file: " << args.input_file << std::endl;
        return 1;
    }

    auto processor = PcapFileProcessor(
        /*read_chunk_size=*/1024*1024*64,
        2,
        args.output_file); // 32 MB input chunk size, 2 threads
                           // TODO: tweak chunk size, threads
    return static_cast<int>(!processor.ProcessTraffic(infile));
}
