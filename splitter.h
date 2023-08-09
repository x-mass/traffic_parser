#pragma once

#include <optional>
#include <vector>
#include <span>
#include <iostream>

class LengthExtractor {
public:
    virtual ~LengthExtractor() = default;
    virtual std::optional<size_t> GetDatagramLength(const std::span<char>& buffer) = 0;
};

class Splitter {
public:
    Splitter(std::shared_ptr<LengthExtractor> datagram_length_extractor)
        : datagram_length_extractor_(std::move(datagram_length_extractor)) {}

    std::vector<std::vector<char>> SplitDatagrams(std::vector<char>& buffer) {
        std::vector<std::vector<char>> datagrams;
        size_t offset = 0;

        while (offset < buffer.size()) {
            std::span<char> buffer_span(buffer.data() + offset, buffer.size() - offset);
            const auto datagram_length = datagram_length_extractor_->GetDatagramLength(buffer_span);

            if (!datagram_length.has_value() || offset + datagram_length.value() > buffer.size()) {
                break;
            }

            datagrams.emplace_back(std::make_move_iterator(buffer.begin() + offset),
                                std::make_move_iterator(buffer.begin() + offset + datagram_length.value()));
            offset += datagram_length.value();
        }

        buffer.erase(buffer.begin(), buffer.begin() + offset);

        return datagrams;
    }

private:
    std::shared_ptr<LengthExtractor> datagram_length_extractor_;
};
