#pragma once

#include <optional>

template <typename T>
class Parser {
public:
    using DataType = T;
    virtual ~Parser() = default;
    virtual std::optional<DataType> Parse(const DataType& data) = 0;
};

template <typename FirstParser, typename... RestParsers>
class ParserChain : public Parser<typename FirstParser::DataType> {
    // If Parser return std::nullopt, further processing will not happen
public:
    using DataType = typename FirstParser::DataType;

    explicit ParserChain(FirstParser first_parser, RestParsers... rest_parsers)
        : first_parser_(first_parser), rest_parsers_(rest_parsers...) {}

    std::optional<DataType> Parse(const DataType& data) override {
        auto processed_data = first_parser_.Parse(data);
        if (!processed_data) {
        return std::nullopt;
        }
        return rest_parsers_.Parse(*processed_data);
    }

private:
    FirstParser first_parser_;
    ParserChain<RestParsers...> rest_parsers_;
};

template <typename LastParser>
class ParserChain<LastParser> : public Parser<typename LastParser::DataType> {
public:
    using DataType = typename LastParser::DataType;

    explicit ParserChain(LastParser last_parser)
        : last_parser_(last_parser) {}

    std::optional<DataType> Parse(const DataType& data) override {
        return last_parser_.Parse(data);
    }

private:
    LastParser last_parser_;
};
