#include "length_extractors.h"
#include "network_headers.h"
#include "parsers.h"
#include "splitter.h"
#include "queue.h"
#include "thread_pool.h"

#include <iostream>
#include <memory>
#include <vector>


class SimbaFileProcessor {
    public:
    SimbaFileProcessor(size_t read_chunk_size, size_t parsers_threads, const std::string output_filename)
        : read_chunk_size_(read_chunk_size)
        , splitter_(Splitter(std::make_unique<MdpLengthExtractor>()))
        , datagram_counter_(0)
        , output_filename_(output_filename)
        , parsers_threads_(parsers_threads) {}

    bool ProcessTraffic(std::ifstream& infile) {
        auto parser_chain = ParserChain(
            SBEParser(
                std::make_shared<ThreadSafeSeqFileWriter>(output_filename_, 1024*1024*64)
            )
        );
        ThreadPool pool(parsers_threads_, [this, &parser_chain]() {
            ConsumeDatagrams<decltype(parser_chain)>(queue_, parser_chain);
        });
        while (infile) {
            ReadChunkFromFile(infile);
            SplitPacketsFromBuffer();
            DispatchPacketsForParsing();
        }
        std::cout << "waiting" << std::endl;
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
};


struct Args {
    std::string input_file;
    std::string output_file;
};

Args ParseArgs(int argc, char* argv[]) {
    Args args;

    if (argc < 3) {
        std::cerr << "Usage: parse_simba <input_file> <output_file>" << std::endl;
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

    // TODO: tweak chunk size, threads
    auto processor = SimbaFileProcessor(
        /*read_chunk_size=*/1024*1024*1, // 1 MB
        /*parsers_threads=*/1,
        args.output_file);
    return static_cast<int>(!processor.ProcessTraffic(infile));
}
