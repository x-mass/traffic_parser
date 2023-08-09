/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MOEX_SPECTRA_SIMBA_SECURITYDEFINITION_H_
#define _MOEX_SPECTRA_SIMBA_SECURITYDEFINITION_H_

#if defined(SBE_HAVE_CMATH)
/* cmath needed for std::numeric_limits<double>::quiet_NaN() */
#  include <cmath>
#  define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#  define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#else
/* math.h needed for NAN */
#  include <math.h>
#  define SBE_FLOAT_NAN NAN
#  define SBE_DOUBLE_NAN NAN
#endif

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#  define SBE_NOEXCEPT noexcept
#else
#  define SBE_CONSTEXPR
#  define SBE_NOEXCEPT
#endif

#if __cplusplus >= 201703L
#  include <string_view>
#  define SBE_NODISCARD [[nodiscard]]
#else
#  define SBE_NODISCARD
#endif

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <cstring>
#include <iomanip>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

#if defined(WIN32) || defined(_WIN32)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#  error "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if defined(SBE_NO_BOUNDS_CHECK)
#  define SBE_BOUNDS_CHECK_EXPECT(exp,c) (false)
#elif defined(_MSC_VER)
#  define SBE_BOUNDS_CHECK_EXPECT(exp,c) (exp)
#else
#  define SBE_BOUNDS_CHECK_EXPECT(exp,c) (__builtin_expect(exp,c))
#endif

#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()


#include "SecurityTradingStatus.h"
#include "FlagsSet.h"
#include "MessageHeader.h"
#include "TradSesStatus.h"
#include "NegativePrices.h"
#include "Decimal5.h"
#include "MDUpdateAction.h"
#include "MDFlagsSet.h"
#include "MDFlags2Set.h"
#include "Decimal5NULL.h"
#include "Utf8String.h"
#include "TradSesEvent.h"
#include "SecurityAltIDSource.h"
#include "TradingSessionID.h"
#include "VarString.h"
#include "Decimal2NULL.h"
#include "GroupSize.h"
#include "MarketSegmentID.h"
#include "MDEntryType.h"

namespace moex_spectra_simba {

class SecurityDefinition
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_position = 0;
    std::uint64_t m_actingVersion = 0;

    inline std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
    {
        return &m_position;
    }

public:
    static const std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(250);
    static const std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(12);
    static const std::uint16_t SBE_SCHEMA_ID = static_cast<std::uint16_t>(19780);
    static const std::uint16_t SBE_SCHEMA_VERSION = static_cast<std::uint16_t>(3);

    enum MetaAttribute
    {
        EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE
    };

    union sbe_float_as_uint_u
    {
        float fp_value;
        std::uint32_t uint_value;
    };

    union sbe_double_as_uint_u
    {
        double fp_value;
        std::uint64_t uint_value;
    };

    using messageHeader = MessageHeader;

    SecurityDefinition() = default;

    SecurityDefinition(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_position(sbeCheckPosition(offset + actingBlockLength)),
        m_actingVersion(actingVersion)
    {
    }

    SecurityDefinition(char *buffer, const std::uint64_t bufferLength) :
        SecurityDefinition(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    SecurityDefinition(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        SecurityDefinition(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(250);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(12);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(19780);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(3);
    }

    SBE_NODISCARD static SBE_CONSTEXPR const char *sbeSemanticType() SBE_NOEXCEPT
    {
        return "d";
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
    }

    SecurityDefinition &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        return *this = SecurityDefinition(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    SecurityDefinition &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        messageHeader hdr(buffer, offset, bufferLength, sbeSchemaVersion());

        hdr
            .blockLength(sbeBlockLength())
            .templateId(sbeTemplateId())
            .schemaId(sbeSchemaId())
            .version(sbeSchemaVersion());

        return *this = SecurityDefinition(
            buffer,
            offset + messageHeader::encodedLength(),
            bufferLength,
            sbeBlockLength(),
            sbeSchemaVersion());
    }

    SecurityDefinition &wrapForDecode(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        return *this = SecurityDefinition(buffer, offset, bufferLength, actingBlockLength, actingVersion);
    }

    SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
    {
        return m_position;
    }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    std::uint64_t sbeCheckPosition(const std::uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        return position;
    }

    void sbePosition(const std::uint64_t position)
    {
        m_position = sbeCheckPosition(position);
    }

    SBE_NODISCARD std::uint64_t encodedLength() const SBE_NOEXCEPT
    {
        return sbePosition() - m_offset;
    }

    SBE_NODISCARD std::uint64_t decodeLength() const
    {
        SecurityDefinition skipper(m_buffer, m_offset, m_bufferLength, sbeBlockLength(), m_actingVersion);
        skipper.skip();
        return skipper.encodedLength();
    }

    SBE_NODISCARD const char *buffer() const SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD char *buffer() SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD std::uint64_t bufferLength() const SBE_NOEXCEPT
    {
        return m_bufferLength;
    }

    SBE_NODISCARD std::uint64_t actingVersion() const SBE_NOEXCEPT
    {
        return m_actingVersion;
    }

    SBE_NODISCARD static const char *TotNumReportsMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t totNumReportsId() SBE_NOEXCEPT
    {
        return 911;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t totNumReportsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool totNumReportsInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= totNumReportsSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t totNumReportsEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint32_t totNumReportsNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR std::uint32_t totNumReportsMinValue() SBE_NOEXCEPT
    {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t totNumReportsMaxValue() SBE_NOEXCEPT
    {
        return UINT32_C(0xfffffffe);
    }

    static SBE_CONSTEXPR std::size_t totNumReportsEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::uint32_t totNumReports() const SBE_NOEXCEPT
    {
        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition &totNumReports(const std::uint32_t value) SBE_NOEXCEPT
    {
        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint32_t));
        return *this;
    }

    SBE_NODISCARD static const char *SymbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t symbolId() SBE_NOEXCEPT
    {
        return 55;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t symbolSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool symbolInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= symbolSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t symbolEncodingOffset() SBE_NOEXCEPT
    {
        return 4;
    }

    static SBE_CONSTEXPR char symbolNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char symbolMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char symbolMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t symbolEncodingLength() SBE_NOEXCEPT
    {
        return 25;
    }

    static SBE_CONSTEXPR std::uint64_t symbolLength() SBE_NOEXCEPT
    {
        return 25;
    }

    SBE_NODISCARD const char *symbol() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 4;
    }

    SBE_NODISCARD char *symbol() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 4;
    }

    SBE_NODISCARD char symbol(const std::uint64_t index) const
    {
        if (index >= 25)
        {
            throw std::runtime_error("index out of range for symbol [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 4 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &symbol(const std::uint64_t index, const char value)
    {
        if (index >= 25)
        {
            throw std::runtime_error("index out of range for symbol [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 4 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSymbol(char *const dst, const std::uint64_t length) const
    {
        if (length > 25)
        {
            throw std::runtime_error("length too large for getSymbol [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 4, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putSymbol(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 4, src, sizeof(char) * 25);
        return *this;
    }

    SBE_NODISCARD std::string getSymbolAsString() const
    {
        const char *buffer = m_buffer + m_offset + 4;
        size_t length = 0;

        for (; length < 25 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSymbolAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSymbolAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getSymbolAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 4;
        size_t length = 0;

        for (; length < 25 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putSymbol(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 25)
        {
            throw std::runtime_error("string too large for putSymbol [E106]");
        }

        std::memcpy(m_buffer + m_offset + 4, str.data(), srcLength);
        for (size_t start = srcLength; start < 25; ++start)
        {
            m_buffer[m_offset + 4 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putSymbol(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 25)
        {
            throw std::runtime_error("string too large for putSymbol [E106]");
        }

        std::memcpy(m_buffer + m_offset + 4, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 25; ++start)
        {
            m_buffer[m_offset + 4 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *SecurityIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityIDId() SBE_NOEXCEPT
    {
        return 48;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityIDInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= securityIDSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityIDEncodingOffset() SBE_NOEXCEPT
    {
        return 29;
    }

    static SBE_CONSTEXPR std::int32_t securityIDNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR std::int32_t securityIDMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t securityIDMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t securityIDEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t securityID() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 29, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition &securityID(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 29, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *SecurityIDSourceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "constant";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityIDSourceId() SBE_NOEXCEPT
    {
        return 22;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityIDSourceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityIDSourceInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= securityIDSourceSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityIDSourceEncodingOffset() SBE_NOEXCEPT
    {
        return 33;
    }

    static SBE_CONSTEXPR char securityIDSourceNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char securityIDSourceMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char securityIDSourceMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t securityIDSourceEncodingLength() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint64_t securityIDSourceLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD const char *securityIDSource() const
    {
        static const std::uint8_t securityIDSourceValues[] = { 56 };

        return (const char *)securityIDSourceValues;
    }

    SBE_NODISCARD char securityIDSource(const std::uint64_t index) const
    {
        static const std::uint8_t securityIDSourceValues[] = { 56 };

        return (char)securityIDSourceValues[index];
    }

    std::uint64_t getSecurityIDSource(char *dst, const std::uint64_t length) const
    {
        static std::uint8_t securityIDSourceValues[] = { 56 };
        std::uint64_t bytesToCopy = length < sizeof(securityIDSourceValues) ? length : sizeof(securityIDSourceValues);

        std::memcpy(dst, securityIDSourceValues, static_cast<size_t>(bytesToCopy));
        return bytesToCopy;
    }

    std::string getSecurityIDSourceAsString() const
    {
        static const std::uint8_t SecurityIDSourceValues[] = { 56 };

        return std::string((const char *)SecurityIDSourceValues, 1);
    }

    std::string getSecurityIDSourceAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityIDSourceAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    SBE_NODISCARD static const char *SecurityAltIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityAltIDId() SBE_NOEXCEPT
    {
        return 455;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityAltIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityAltIDInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= securityAltIDSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityAltIDEncodingOffset() SBE_NOEXCEPT
    {
        return 33;
    }

    static SBE_CONSTEXPR char securityAltIDNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char securityAltIDMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char securityAltIDMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t securityAltIDEncodingLength() SBE_NOEXCEPT
    {
        return 25;
    }

    static SBE_CONSTEXPR std::uint64_t securityAltIDLength() SBE_NOEXCEPT
    {
        return 25;
    }

    SBE_NODISCARD const char *securityAltID() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 33;
    }

    SBE_NODISCARD char *securityAltID() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 33;
    }

    SBE_NODISCARD char securityAltID(const std::uint64_t index) const
    {
        if (index >= 25)
        {
            throw std::runtime_error("index out of range for securityAltID [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 33 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &securityAltID(const std::uint64_t index, const char value)
    {
        if (index >= 25)
        {
            throw std::runtime_error("index out of range for securityAltID [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 33 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSecurityAltID(char *const dst, const std::uint64_t length) const
    {
        if (length > 25)
        {
            throw std::runtime_error("length too large for getSecurityAltID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 33, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putSecurityAltID(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 33, src, sizeof(char) * 25);
        return *this;
    }

    SBE_NODISCARD std::string getSecurityAltIDAsString() const
    {
        const char *buffer = m_buffer + m_offset + 33;
        size_t length = 0;

        for (; length < 25 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSecurityAltIDAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityAltIDAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getSecurityAltIDAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 33;
        size_t length = 0;

        for (; length < 25 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putSecurityAltID(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 25)
        {
            throw std::runtime_error("string too large for putSecurityAltID [E106]");
        }

        std::memcpy(m_buffer + m_offset + 33, str.data(), srcLength);
        for (size_t start = srcLength; start < 25; ++start)
        {
            m_buffer[m_offset + 33 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putSecurityAltID(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 25)
        {
            throw std::runtime_error("string too large for putSecurityAltID [E106]");
        }

        std::memcpy(m_buffer + m_offset + 33, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 25; ++start)
        {
            m_buffer[m_offset + 33 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *SecurityAltIDSourceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityAltIDSourceId() SBE_NOEXCEPT
    {
        return 456;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityAltIDSourceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityAltIDSourceInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= securityAltIDSourceSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityAltIDSourceEncodingOffset() SBE_NOEXCEPT
    {
        return 58;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityAltIDSourceEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD SecurityAltIDSource::Value securityAltIDSource() const
    {
        char val;
        std::memcpy(&val, m_buffer + m_offset + 58, sizeof(char));
        return SecurityAltIDSource::get((val));
    }

    SecurityDefinition &securityAltIDSource(const SecurityAltIDSource::Value value) SBE_NOEXCEPT
    {
        char val = (value);
        std::memcpy(m_buffer + m_offset + 58, &val, sizeof(char));
        return *this;
    }

    SBE_NODISCARD static const char *SecurityTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityTypeId() SBE_NOEXCEPT
    {
        return 167;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityTypeInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= securityTypeSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 59;
    }

    static SBE_CONSTEXPR char securityTypeNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char securityTypeMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char securityTypeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t securityTypeEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    static SBE_CONSTEXPR std::uint64_t securityTypeLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD const char *securityType() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 59;
    }

    SBE_NODISCARD char *securityType() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 59;
    }

    SBE_NODISCARD char securityType(const std::uint64_t index) const
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for securityType [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 59 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &securityType(const std::uint64_t index, const char value)
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for securityType [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 59 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSecurityType(char *const dst, const std::uint64_t length) const
    {
        if (length > 4)
        {
            throw std::runtime_error("length too large for getSecurityType [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 59, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putSecurityType(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 59, src, sizeof(char) * 4);
        return *this;
    }

    SecurityDefinition &putSecurityType(
        const char value0,
        const char value1,
        const char value2,
        const char value3) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 59, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 60, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 61, &val2, sizeof(char));
        char val3 = (value3);
        std::memcpy(m_buffer + m_offset + 62, &val3, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getSecurityTypeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 59;
        size_t length = 0;

        for (; length < 4 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSecurityTypeAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityTypeAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getSecurityTypeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 59;
        size_t length = 0;

        for (; length < 4 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putSecurityType(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 4)
        {
            throw std::runtime_error("string too large for putSecurityType [E106]");
        }

        std::memcpy(m_buffer + m_offset + 59, str.data(), srcLength);
        for (size_t start = srcLength; start < 4; ++start)
        {
            m_buffer[m_offset + 59 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putSecurityType(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 4)
        {
            throw std::runtime_error("string too large for putSecurityType [E106]");
        }

        std::memcpy(m_buffer + m_offset + 59, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 4; ++start)
        {
            m_buffer[m_offset + 59 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *CFICodeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t cFICodeId() SBE_NOEXCEPT
    {
        return 461;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t cFICodeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool cFICodeInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= cFICodeSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t cFICodeEncodingOffset() SBE_NOEXCEPT
    {
        return 63;
    }

    static SBE_CONSTEXPR char cFICodeNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char cFICodeMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char cFICodeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t cFICodeEncodingLength() SBE_NOEXCEPT
    {
        return 6;
    }

    static SBE_CONSTEXPR std::uint64_t cFICodeLength() SBE_NOEXCEPT
    {
        return 6;
    }

    SBE_NODISCARD const char *cFICode() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 63;
    }

    SBE_NODISCARD char *cFICode() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 63;
    }

    SBE_NODISCARD char cFICode(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for cFICode [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 63 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &cFICode(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for cFICode [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 63 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getCFICode(char *const dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
            throw std::runtime_error("length too large for getCFICode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 63, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putCFICode(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 63, src, sizeof(char) * 6);
        return *this;
    }

    SBE_NODISCARD std::string getCFICodeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 63;
        size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getCFICodeAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getCFICodeAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getCFICodeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 63;
        size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putCFICode(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putCFICode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 63, str.data(), srcLength);
        for (size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 63 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putCFICode(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putCFICode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 63, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 63 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *StrikePriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t strikePriceId() SBE_NOEXCEPT
    {
        return 202;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t strikePriceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool strikePriceInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= strikePriceSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t strikePriceEncodingOffset() SBE_NOEXCEPT
    {
        return 69;
    }

private:
    Decimal5NULL m_strikePrice;

public:
    SBE_NODISCARD Decimal5NULL &strikePrice()
    {
        m_strikePrice.wrap(m_buffer, m_offset + 69, m_actingVersion, m_bufferLength);
        return m_strikePrice;
    }

    SBE_NODISCARD static const char *ContractMultiplierMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t contractMultiplierId() SBE_NOEXCEPT
    {
        return 231;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t contractMultiplierSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool contractMultiplierInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= contractMultiplierSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t contractMultiplierEncodingOffset() SBE_NOEXCEPT
    {
        return 77;
    }

    static SBE_CONSTEXPR std::int32_t contractMultiplierNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR std::int32_t contractMultiplierMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t contractMultiplierMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t contractMultiplierEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t contractMultiplier() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 77, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition &contractMultiplier(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 77, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *SecurityTradingStatusMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t securityTradingStatusId() SBE_NOEXCEPT
    {
        return 326;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t securityTradingStatusSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool securityTradingStatusInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= securityTradingStatusSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityTradingStatusEncodingOffset() SBE_NOEXCEPT
    {
        return 81;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t securityTradingStatusEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD SecurityTradingStatus::Value securityTradingStatus() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 81, sizeof(std::uint8_t));
        return SecurityTradingStatus::get((val));
    }

    SecurityDefinition &securityTradingStatus(const SecurityTradingStatus::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 81, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *CurrencyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t currencyId() SBE_NOEXCEPT
    {
        return 15;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t currencySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool currencyInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= currencySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t currencyEncodingOffset() SBE_NOEXCEPT
    {
        return 82;
    }

    static SBE_CONSTEXPR char currencyNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char currencyMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char currencyMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t currencyEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t currencyLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *currency() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 82;
    }

    SBE_NODISCARD char *currency() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 82;
    }

    SBE_NODISCARD char currency(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for currency [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 82 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &currency(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for currency [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 82 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getCurrency(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getCurrency [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 82, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putCurrency(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 82, src, sizeof(char) * 3);
        return *this;
    }

    SecurityDefinition &putCurrency(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 82, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 83, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 84, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getCurrencyAsString() const
    {
        const char *buffer = m_buffer + m_offset + 82;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getCurrencyAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getCurrencyAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getCurrencyAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 82;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putCurrency(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 82, str.data(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 82 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putCurrency(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 82, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 82 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *MarketIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "constant";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t marketIDId() SBE_NOEXCEPT
    {
        return 1301;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t marketIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool marketIDInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= marketIDSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t marketIDEncodingOffset() SBE_NOEXCEPT
    {
        return 85;
    }

    static SBE_CONSTEXPR char marketIDNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char marketIDMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char marketIDMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t marketIDEncodingLength() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint64_t marketIDLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD const char *marketID() const
    {
        static const std::uint8_t marketIDValues[] = { 77, 79, 69, 88 };

        return (const char *)marketIDValues;
    }

    SBE_NODISCARD char marketID(const std::uint64_t index) const
    {
        static const std::uint8_t marketIDValues[] = { 77, 79, 69, 88 };

        return (char)marketIDValues[index];
    }

    std::uint64_t getMarketID(char *dst, const std::uint64_t length) const
    {
        static std::uint8_t marketIDValues[] = { 77, 79, 69, 88 };
        std::uint64_t bytesToCopy = length < sizeof(marketIDValues) ? length : sizeof(marketIDValues);

        std::memcpy(dst, marketIDValues, static_cast<size_t>(bytesToCopy));
        return bytesToCopy;
    }

    std::string getMarketIDAsString() const
    {
        static const std::uint8_t MarketIDValues[] = { 77, 79, 69, 88 };

        return std::string((const char *)MarketIDValues, 4);
    }

    std::string getMarketIDAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getMarketIDAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    SBE_NODISCARD static const char *MarketSegmentIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t marketSegmentIDId() SBE_NOEXCEPT
    {
        return 1300;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t marketSegmentIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool marketSegmentIDInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= marketSegmentIDSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t marketSegmentIDEncodingOffset() SBE_NOEXCEPT
    {
        return 85;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t marketSegmentIDEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD MarketSegmentID::Value marketSegmentID() const
    {
        char val;
        std::memcpy(&val, m_buffer + m_offset + 85, sizeof(char));
        return MarketSegmentID::get((val));
    }

    SecurityDefinition &marketSegmentID(const MarketSegmentID::Value value) SBE_NOEXCEPT
    {
        char val = (value);
        std::memcpy(m_buffer + m_offset + 85, &val, sizeof(char));
        return *this;
    }

    SBE_NODISCARD static const char *TradingSessionIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t tradingSessionIDId() SBE_NOEXCEPT
    {
        return 336;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tradingSessionIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool tradingSessionIDInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= tradingSessionIDSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t tradingSessionIDEncodingOffset() SBE_NOEXCEPT
    {
        return 86;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t tradingSessionIDEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD TradingSessionID::Value tradingSessionID() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 86, sizeof(std::uint8_t));
        return TradingSessionID::get((val));
    }

    SecurityDefinition &tradingSessionID(const TradingSessionID::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 86, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *ExchangeTradingSessionIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t exchangeTradingSessionIDId() SBE_NOEXCEPT
    {
        return 5842;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t exchangeTradingSessionIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool exchangeTradingSessionIDInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= exchangeTradingSessionIDSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t exchangeTradingSessionIDEncodingOffset() SBE_NOEXCEPT
    {
        return 87;
    }

    static SBE_CONSTEXPR std::int32_t exchangeTradingSessionIDNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR std::int32_t exchangeTradingSessionIDMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t exchangeTradingSessionIDMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t exchangeTradingSessionIDEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t exchangeTradingSessionID() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 87, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition &exchangeTradingSessionID(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 87, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *VolatilityMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t volatilityId() SBE_NOEXCEPT
    {
        return 5678;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t volatilitySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool volatilityInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= volatilitySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t volatilityEncodingOffset() SBE_NOEXCEPT
    {
        return 91;
    }

private:
    Decimal5NULL m_volatility;

public:
    SBE_NODISCARD Decimal5NULL &volatility()
    {
        m_volatility.wrap(m_buffer, m_offset + 91, m_actingVersion, m_bufferLength);
        return m_volatility;
    }

    SBE_NODISCARD static const char *HighLimitPxMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t highLimitPxId() SBE_NOEXCEPT
    {
        return 1149;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t highLimitPxSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool highLimitPxInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= highLimitPxSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t highLimitPxEncodingOffset() SBE_NOEXCEPT
    {
        return 99;
    }

private:
    Decimal5NULL m_highLimitPx;

public:
    SBE_NODISCARD Decimal5NULL &highLimitPx()
    {
        m_highLimitPx.wrap(m_buffer, m_offset + 99, m_actingVersion, m_bufferLength);
        return m_highLimitPx;
    }

    SBE_NODISCARD static const char *LowLimitPxMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t lowLimitPxId() SBE_NOEXCEPT
    {
        return 1148;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t lowLimitPxSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool lowLimitPxInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= lowLimitPxSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t lowLimitPxEncodingOffset() SBE_NOEXCEPT
    {
        return 107;
    }

private:
    Decimal5NULL m_lowLimitPx;

public:
    SBE_NODISCARD Decimal5NULL &lowLimitPx()
    {
        m_lowLimitPx.wrap(m_buffer, m_offset + 107, m_actingVersion, m_bufferLength);
        return m_lowLimitPx;
    }

    SBE_NODISCARD static const char *MinPriceIncrementMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minPriceIncrementId() SBE_NOEXCEPT
    {
        return 969;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minPriceIncrementSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minPriceIncrementInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= minPriceIncrementSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minPriceIncrementEncodingOffset() SBE_NOEXCEPT
    {
        return 115;
    }

private:
    Decimal5NULL m_minPriceIncrement;

public:
    SBE_NODISCARD Decimal5NULL &minPriceIncrement()
    {
        m_minPriceIncrement.wrap(m_buffer, m_offset + 115, m_actingVersion, m_bufferLength);
        return m_minPriceIncrement;
    }

    SBE_NODISCARD static const char *MinPriceIncrementAmountMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minPriceIncrementAmountId() SBE_NOEXCEPT
    {
        return 1146;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minPriceIncrementAmountSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minPriceIncrementAmountInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= minPriceIncrementAmountSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minPriceIncrementAmountEncodingOffset() SBE_NOEXCEPT
    {
        return 123;
    }

private:
    Decimal5NULL m_minPriceIncrementAmount;

public:
    SBE_NODISCARD Decimal5NULL &minPriceIncrementAmount()
    {
        m_minPriceIncrementAmount.wrap(m_buffer, m_offset + 123, m_actingVersion, m_bufferLength);
        return m_minPriceIncrementAmount;
    }

    SBE_NODISCARD static const char *InitialMarginOnBuyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t initialMarginOnBuyId() SBE_NOEXCEPT
    {
        return 20002;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t initialMarginOnBuySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool initialMarginOnBuyInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= initialMarginOnBuySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t initialMarginOnBuyEncodingOffset() SBE_NOEXCEPT
    {
        return 131;
    }

private:
    Decimal2NULL m_initialMarginOnBuy;

public:
    SBE_NODISCARD Decimal2NULL &initialMarginOnBuy()
    {
        m_initialMarginOnBuy.wrap(m_buffer, m_offset + 131, m_actingVersion, m_bufferLength);
        return m_initialMarginOnBuy;
    }

    SBE_NODISCARD static const char *InitialMarginOnSellMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t initialMarginOnSellId() SBE_NOEXCEPT
    {
        return 20000;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t initialMarginOnSellSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool initialMarginOnSellInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= initialMarginOnSellSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t initialMarginOnSellEncodingOffset() SBE_NOEXCEPT
    {
        return 139;
    }

private:
    Decimal2NULL m_initialMarginOnSell;

public:
    SBE_NODISCARD Decimal2NULL &initialMarginOnSell()
    {
        m_initialMarginOnSell.wrap(m_buffer, m_offset + 139, m_actingVersion, m_bufferLength);
        return m_initialMarginOnSell;
    }

    SBE_NODISCARD static const char *InitialMarginSynteticMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t initialMarginSynteticId() SBE_NOEXCEPT
    {
        return 20001;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t initialMarginSynteticSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool initialMarginSynteticInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= initialMarginSynteticSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t initialMarginSynteticEncodingOffset() SBE_NOEXCEPT
    {
        return 147;
    }

private:
    Decimal2NULL m_initialMarginSyntetic;

public:
    SBE_NODISCARD Decimal2NULL &initialMarginSyntetic()
    {
        m_initialMarginSyntetic.wrap(m_buffer, m_offset + 147, m_actingVersion, m_bufferLength);
        return m_initialMarginSyntetic;
    }

    SBE_NODISCARD static const char *TheorPriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t theorPriceId() SBE_NOEXCEPT
    {
        return 20006;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t theorPriceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool theorPriceInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= theorPriceSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t theorPriceEncodingOffset() SBE_NOEXCEPT
    {
        return 155;
    }

private:
    Decimal5NULL m_theorPrice;

public:
    SBE_NODISCARD Decimal5NULL &theorPrice()
    {
        m_theorPrice.wrap(m_buffer, m_offset + 155, m_actingVersion, m_bufferLength);
        return m_theorPrice;
    }

    SBE_NODISCARD static const char *TheorPriceLimitMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t theorPriceLimitId() SBE_NOEXCEPT
    {
        return 20007;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t theorPriceLimitSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool theorPriceLimitInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= theorPriceLimitSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t theorPriceLimitEncodingOffset() SBE_NOEXCEPT
    {
        return 163;
    }

private:
    Decimal5NULL m_theorPriceLimit;

public:
    SBE_NODISCARD Decimal5NULL &theorPriceLimit()
    {
        m_theorPriceLimit.wrap(m_buffer, m_offset + 163, m_actingVersion, m_bufferLength);
        return m_theorPriceLimit;
    }

    SBE_NODISCARD static const char *UnderlyingQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t underlyingQtyId() SBE_NOEXCEPT
    {
        return 879;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool underlyingQtyInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= underlyingQtySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 171;
    }

private:
    Decimal5NULL m_underlyingQty;

public:
    SBE_NODISCARD Decimal5NULL &underlyingQty()
    {
        m_underlyingQty.wrap(m_buffer, m_offset + 171, m_actingVersion, m_bufferLength);
        return m_underlyingQty;
    }

    SBE_NODISCARD static const char *UnderlyingCurrencyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t underlyingCurrencyId() SBE_NOEXCEPT
    {
        return 318;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingCurrencySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool underlyingCurrencyInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= underlyingCurrencySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingCurrencyEncodingOffset() SBE_NOEXCEPT
    {
        return 179;
    }

    static SBE_CONSTEXPR char underlyingCurrencyNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char underlyingCurrencyMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char underlyingCurrencyMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t underlyingCurrencyEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t underlyingCurrencyLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *underlyingCurrency() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 179;
    }

    SBE_NODISCARD char *underlyingCurrency() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 179;
    }

    SBE_NODISCARD char underlyingCurrency(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for underlyingCurrency [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 179 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &underlyingCurrency(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for underlyingCurrency [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 179 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getUnderlyingCurrency(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getUnderlyingCurrency [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 179, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putUnderlyingCurrency(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 179, src, sizeof(char) * 3);
        return *this;
    }

    SecurityDefinition &putUnderlyingCurrency(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 179, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 180, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 181, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getUnderlyingCurrencyAsString() const
    {
        const char *buffer = m_buffer + m_offset + 179;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getUnderlyingCurrencyAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getUnderlyingCurrencyAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getUnderlyingCurrencyAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 179;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putUnderlyingCurrency(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putUnderlyingCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 179, str.data(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 179 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putUnderlyingCurrency(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putUnderlyingCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 179, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 179 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *MaturityDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t maturityDateId() SBE_NOEXCEPT
    {
        return 541;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t maturityDateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool maturityDateInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= maturityDateSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t maturityDateEncodingOffset() SBE_NOEXCEPT
    {
        return 182;
    }

    static SBE_CONSTEXPR std::uint32_t maturityDateNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR std::uint32_t maturityDateMinValue() SBE_NOEXCEPT
    {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t maturityDateMaxValue() SBE_NOEXCEPT
    {
        return UINT32_C(0xfffffffe);
    }

    static SBE_CONSTEXPR std::size_t maturityDateEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::uint32_t maturityDate() const SBE_NOEXCEPT
    {
        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 182, sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition &maturityDate(const std::uint32_t value) SBE_NOEXCEPT
    {
        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 182, &val, sizeof(std::uint32_t));
        return *this;
    }

    SBE_NODISCARD static const char *MaturityTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t maturityTimeId() SBE_NOEXCEPT
    {
        return 1079;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t maturityTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool maturityTimeInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= maturityTimeSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t maturityTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 186;
    }

    static SBE_CONSTEXPR std::uint32_t maturityTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR std::uint32_t maturityTimeMinValue() SBE_NOEXCEPT
    {
        return UINT32_C(0x0);
    }

    static SBE_CONSTEXPR std::uint32_t maturityTimeMaxValue() SBE_NOEXCEPT
    {
        return UINT32_C(0xfffffffe);
    }

    static SBE_CONSTEXPR std::size_t maturityTimeEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::uint32_t maturityTime() const SBE_NOEXCEPT
    {
        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 186, sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition &maturityTime(const std::uint32_t value) SBE_NOEXCEPT
    {
        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 186, &val, sizeof(std::uint32_t));
        return *this;
    }

    SBE_NODISCARD static const char *FlagsMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t flagsId() SBE_NOEXCEPT
    {
        return 20008;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t flagsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool flagsInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= flagsSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t flagsEncodingOffset() SBE_NOEXCEPT
    {
        return 190;
    }

private:
    FlagsSet m_flags;

public:
    SBE_NODISCARD FlagsSet &flags()
    {
        m_flags.wrap(m_buffer, m_offset + 190, m_actingVersion, m_bufferLength);
        return m_flags;
    }

    static SBE_CONSTEXPR std::size_t flagsEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD static const char *MinPriceIncrementAmountCurrMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t minPriceIncrementAmountCurrId() SBE_NOEXCEPT
    {
        return 20040;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t minPriceIncrementAmountCurrSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool minPriceIncrementAmountCurrInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= minPriceIncrementAmountCurrSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t minPriceIncrementAmountCurrEncodingOffset() SBE_NOEXCEPT
    {
        return 198;
    }

private:
    Decimal5NULL m_minPriceIncrementAmountCurr;

public:
    SBE_NODISCARD Decimal5NULL &minPriceIncrementAmountCurr()
    {
        m_minPriceIncrementAmountCurr.wrap(m_buffer, m_offset + 198, m_actingVersion, m_bufferLength);
        return m_minPriceIncrementAmountCurr;
    }

    SBE_NODISCARD static const char *SettlPriceOpenMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t settlPriceOpenId() SBE_NOEXCEPT
    {
        return 20041;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t settlPriceOpenSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool settlPriceOpenInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= settlPriceOpenSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t settlPriceOpenEncodingOffset() SBE_NOEXCEPT
    {
        return 206;
    }

private:
    Decimal5NULL m_settlPriceOpen;

public:
    SBE_NODISCARD Decimal5NULL &settlPriceOpen()
    {
        m_settlPriceOpen.wrap(m_buffer, m_offset + 206, m_actingVersion, m_bufferLength);
        return m_settlPriceOpen;
    }

    SBE_NODISCARD static const char *ValuationMethodMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t valuationMethodId() SBE_NOEXCEPT
    {
        return 1197;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t valuationMethodSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool valuationMethodInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= valuationMethodSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t valuationMethodEncodingOffset() SBE_NOEXCEPT
    {
        return 214;
    }

    static SBE_CONSTEXPR char valuationMethodNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char valuationMethodMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char valuationMethodMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t valuationMethodEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    static SBE_CONSTEXPR std::uint64_t valuationMethodLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD const char *valuationMethod() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 214;
    }

    SBE_NODISCARD char *valuationMethod() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 214;
    }

    SBE_NODISCARD char valuationMethod(const std::uint64_t index) const
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for valuationMethod [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 214 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &valuationMethod(const std::uint64_t index, const char value)
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for valuationMethod [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 214 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getValuationMethod(char *const dst, const std::uint64_t length) const
    {
        if (length > 4)
        {
            throw std::runtime_error("length too large for getValuationMethod [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 214, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putValuationMethod(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 214, src, sizeof(char) * 4);
        return *this;
    }

    SecurityDefinition &putValuationMethod(
        const char value0,
        const char value1,
        const char value2,
        const char value3) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 214, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 215, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 216, &val2, sizeof(char));
        char val3 = (value3);
        std::memcpy(m_buffer + m_offset + 217, &val3, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getValuationMethodAsString() const
    {
        const char *buffer = m_buffer + m_offset + 214;
        size_t length = 0;

        for (; length < 4 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getValuationMethodAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getValuationMethodAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getValuationMethodAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 214;
        size_t length = 0;

        for (; length < 4 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putValuationMethod(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 4)
        {
            throw std::runtime_error("string too large for putValuationMethod [E106]");
        }

        std::memcpy(m_buffer + m_offset + 214, str.data(), srcLength);
        for (size_t start = srcLength; start < 4; ++start)
        {
            m_buffer[m_offset + 214 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putValuationMethod(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 4)
        {
            throw std::runtime_error("string too large for putValuationMethod [E106]");
        }

        std::memcpy(m_buffer + m_offset + 214, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 4; ++start)
        {
            m_buffer[m_offset + 214 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *RiskFreeRateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t riskFreeRateId() SBE_NOEXCEPT
    {
        return 1190;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t riskFreeRateSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool riskFreeRateInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= riskFreeRateSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t riskFreeRateEncodingOffset() SBE_NOEXCEPT
    {
        return 218;
    }

    static SBE_CONSTEXPR double riskFreeRateNullValue() SBE_NOEXCEPT
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR double riskFreeRateMinValue() SBE_NOEXCEPT
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR double riskFreeRateMaxValue() SBE_NOEXCEPT
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR std::size_t riskFreeRateEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD double riskFreeRate() const SBE_NOEXCEPT
    {
        union sbe_double_as_uint_u val;
        std::memcpy(&val, m_buffer + m_offset + 218, sizeof(double));
        val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
        return val.fp_value;
    }

    SecurityDefinition &riskFreeRate(const double value) SBE_NOEXCEPT
    {
        union sbe_double_as_uint_u val;
        val.fp_value = value;
        val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
        std::memcpy(m_buffer + m_offset + 218, &val, sizeof(double));
        return *this;
    }

    SBE_NODISCARD static const char *FixedSpotDiscountMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t fixedSpotDiscountId() SBE_NOEXCEPT
    {
        return 20042;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t fixedSpotDiscountSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool fixedSpotDiscountInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= fixedSpotDiscountSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t fixedSpotDiscountEncodingOffset() SBE_NOEXCEPT
    {
        return 226;
    }

    static SBE_CONSTEXPR double fixedSpotDiscountNullValue() SBE_NOEXCEPT
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR double fixedSpotDiscountMinValue() SBE_NOEXCEPT
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR double fixedSpotDiscountMaxValue() SBE_NOEXCEPT
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR std::size_t fixedSpotDiscountEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD double fixedSpotDiscount() const SBE_NOEXCEPT
    {
        union sbe_double_as_uint_u val;
        std::memcpy(&val, m_buffer + m_offset + 226, sizeof(double));
        val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
        return val.fp_value;
    }

    SecurityDefinition &fixedSpotDiscount(const double value) SBE_NOEXCEPT
    {
        union sbe_double_as_uint_u val;
        val.fp_value = value;
        val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
        std::memcpy(m_buffer + m_offset + 226, &val, sizeof(double));
        return *this;
    }

    SBE_NODISCARD static const char *ProjectedSpotDiscountMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t projectedSpotDiscountId() SBE_NOEXCEPT
    {
        return 20043;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t projectedSpotDiscountSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool projectedSpotDiscountInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= projectedSpotDiscountSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t projectedSpotDiscountEncodingOffset() SBE_NOEXCEPT
    {
        return 234;
    }

    static SBE_CONSTEXPR double projectedSpotDiscountNullValue() SBE_NOEXCEPT
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR double projectedSpotDiscountMinValue() SBE_NOEXCEPT
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR double projectedSpotDiscountMaxValue() SBE_NOEXCEPT
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR std::size_t projectedSpotDiscountEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD double projectedSpotDiscount() const SBE_NOEXCEPT
    {
        union sbe_double_as_uint_u val;
        std::memcpy(&val, m_buffer + m_offset + 234, sizeof(double));
        val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
        return val.fp_value;
    }

    SecurityDefinition &projectedSpotDiscount(const double value) SBE_NOEXCEPT
    {
        union sbe_double_as_uint_u val;
        val.fp_value = value;
        val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
        std::memcpy(m_buffer + m_offset + 234, &val, sizeof(double));
        return *this;
    }

    SBE_NODISCARD static const char *SettlCurrencyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t settlCurrencyId() SBE_NOEXCEPT
    {
        return 120;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t settlCurrencySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool settlCurrencyInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= settlCurrencySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t settlCurrencyEncodingOffset() SBE_NOEXCEPT
    {
        return 242;
    }

    static SBE_CONSTEXPR char settlCurrencyNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char settlCurrencyMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char settlCurrencyMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t settlCurrencyEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t settlCurrencyLength() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD const char *settlCurrency() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 242;
    }

    SBE_NODISCARD char *settlCurrency() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 242;
    }

    SBE_NODISCARD char settlCurrency(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for settlCurrency [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 242 + (index * 1), sizeof(char));
        return (val);
    }

    SecurityDefinition &settlCurrency(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for settlCurrency [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 242 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSettlCurrency(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getSettlCurrency [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 242, sizeof(char) * static_cast<size_t>(length));
        return length;
    }

    SecurityDefinition &putSettlCurrency(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 242, src, sizeof(char) * 3);
        return *this;
    }

    SecurityDefinition &putSettlCurrency(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 242, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 243, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 244, &val2, sizeof(char));

        return *this;
    }

    SBE_NODISCARD std::string getSettlCurrencyAsString() const
    {
        const char *buffer = m_buffer + m_offset + 242;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSettlCurrencyAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSettlCurrencyAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getSettlCurrencyAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 242;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    SecurityDefinition &putSettlCurrency(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSettlCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 242, str.data(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 242 + start] = 0;
        }

        return *this;
    }
    #else
    SecurityDefinition &putSettlCurrency(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putSettlCurrency [E106]");
        }

        std::memcpy(m_buffer + m_offset + 242, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 242 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *NegativePricesMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t negativePricesId() SBE_NOEXCEPT
    {
        return 20044;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t negativePricesSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool negativePricesInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= negativePricesSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t negativePricesEncodingOffset() SBE_NOEXCEPT
    {
        return 245;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t negativePricesEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD NegativePrices::Value negativePrices() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 245, sizeof(std::uint8_t));
        return NegativePrices::get((val));
    }

    SecurityDefinition &negativePrices(const NegativePrices::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 245, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *DerivativeContractMultiplierMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t derivativeContractMultiplierId() SBE_NOEXCEPT
    {
        return 1266;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t derivativeContractMultiplierSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool derivativeContractMultiplierInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= derivativeContractMultiplierSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t derivativeContractMultiplierEncodingOffset() SBE_NOEXCEPT
    {
        return 246;
    }

    static SBE_CONSTEXPR std::int32_t derivativeContractMultiplierNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR std::int32_t derivativeContractMultiplierMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t derivativeContractMultiplierMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t derivativeContractMultiplierEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t derivativeContractMultiplier() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 246, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    SecurityDefinition &derivativeContractMultiplier(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 246, &val, sizeof(std::int32_t));
        return *this;
    }

    class NoMDFeedTypes
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(29));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 29;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 29;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoMDFeedTypes &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex() SBE_NOEXCEPT
        {
            m_count = m_index;
            GroupSize dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #endif

        SBE_NODISCARD static const char *MDFeedTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t mDFeedTypeId() SBE_NOEXCEPT
        {
            return 1022;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t mDFeedTypeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool mDFeedTypeInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= mDFeedTypeSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t mDFeedTypeEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR char mDFeedTypeNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char mDFeedTypeMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char mDFeedTypeMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t mDFeedTypeEncodingLength() SBE_NOEXCEPT
        {
            return 25;
        }

        static SBE_CONSTEXPR std::uint64_t mDFeedTypeLength() SBE_NOEXCEPT
        {
            return 25;
        }

        SBE_NODISCARD const char *mDFeedType() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 0;
        }

        SBE_NODISCARD char *mDFeedType() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 0;
        }

        SBE_NODISCARD char mDFeedType(const std::uint64_t index) const
        {
            if (index >= 25)
            {
                throw std::runtime_error("index out of range for mDFeedType [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 0 + (index * 1), sizeof(char));
            return (val);
        }

        NoMDFeedTypes &mDFeedType(const std::uint64_t index, const char value)
        {
            if (index >= 25)
            {
                throw std::runtime_error("index out of range for mDFeedType [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 0 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getMDFeedType(char *const dst, const std::uint64_t length) const
        {
            if (length > 25)
            {
                throw std::runtime_error("length too large for getMDFeedType [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 0, sizeof(char) * static_cast<size_t>(length));
            return length;
        }

        NoMDFeedTypes &putMDFeedType(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 0, src, sizeof(char) * 25);
            return *this;
        }

        SBE_NODISCARD std::string getMDFeedTypeAsString() const
        {
            const char *buffer = m_buffer + m_offset + 0;
            size_t length = 0;

            for (; length < 25 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getMDFeedTypeAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getMDFeedTypeAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getMDFeedTypeAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 0;
            size_t length = 0;

            for (; length < 25 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        NoMDFeedTypes &putMDFeedType(const std::string_view str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 25)
            {
                throw std::runtime_error("string too large for putMDFeedType [E106]");
            }

            std::memcpy(m_buffer + m_offset + 0, str.data(), srcLength);
            for (size_t start = srcLength; start < 25; ++start)
            {
                m_buffer[m_offset + 0 + start] = 0;
            }

            return *this;
        }
        #else
        NoMDFeedTypes &putMDFeedType(const std::string& str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 25)
            {
                throw std::runtime_error("string too large for putMDFeedType [E106]");
            }

            std::memcpy(m_buffer + m_offset + 0, str.c_str(), srcLength);
            for (size_t start = srcLength; start < 25; ++start)
            {
                m_buffer[m_offset + 0 + start] = 0;
            }

            return *this;
        }
        #endif

        SBE_NODISCARD static const char *MarketDepthMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t marketDepthId() SBE_NOEXCEPT
        {
            return 264;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t marketDepthSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool marketDepthInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= marketDepthSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t marketDepthEncodingOffset() SBE_NOEXCEPT
        {
            return 25;
        }

        static SBE_CONSTEXPR std::uint32_t marketDepthNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT32;
        }

        static SBE_CONSTEXPR std::uint32_t marketDepthMinValue() SBE_NOEXCEPT
        {
            return UINT32_C(0x0);
        }

        static SBE_CONSTEXPR std::uint32_t marketDepthMaxValue() SBE_NOEXCEPT
        {
            return UINT32_C(0xfffffffe);
        }

        static SBE_CONSTEXPR std::size_t marketDepthEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::uint32_t marketDepth() const SBE_NOEXCEPT
        {
            std::uint32_t val;
            std::memcpy(&val, m_buffer + m_offset + 25, sizeof(std::uint32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoMDFeedTypes &marketDepth(const std::uint32_t value) SBE_NOEXCEPT
        {
            std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 25, &val, sizeof(std::uint32_t));
            return *this;
        }

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits>& operator << (
            std::basic_ostream<CharT, Traits>& builder, NoMDFeedTypes writer)
        {
            builder << '{';
            builder << R"("MDFeedType": )";
            builder << '"' <<
                writer.getMDFeedTypeAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("MarketDepth": )";
            builder << +writer.marketDepth();

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoMDFeedTypes m_noMDFeedTypes;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t NoMDFeedTypesId() SBE_NOEXCEPT
    {
        return 1141;
    }

    SBE_NODISCARD inline NoMDFeedTypes &noMDFeedTypes()
    {
        m_noMDFeedTypes.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noMDFeedTypes;
    }

    NoMDFeedTypes &noMDFeedTypesCount(const std::uint8_t count)
    {
        m_noMDFeedTypes.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noMDFeedTypes;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noMDFeedTypesSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noMDFeedTypesInActingVersion() const SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= noMDFeedTypesSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    class NoUnderlyings
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(37));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 37;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 37;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoUnderlyings &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex() SBE_NOEXCEPT
        {
            m_count = m_index;
            GroupSize dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #endif

        SBE_NODISCARD static const char *UnderlyingSymbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingSymbolId() SBE_NOEXCEPT
        {
            return 311;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingSymbolSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingSymbolInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= underlyingSymbolSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingSymbolEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR char underlyingSymbolNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char underlyingSymbolMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char underlyingSymbolMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t underlyingSymbolEncodingLength() SBE_NOEXCEPT
        {
            return 25;
        }

        static SBE_CONSTEXPR std::uint64_t underlyingSymbolLength() SBE_NOEXCEPT
        {
            return 25;
        }

        SBE_NODISCARD const char *underlyingSymbol() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 0;
        }

        SBE_NODISCARD char *underlyingSymbol() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 0;
        }

        SBE_NODISCARD char underlyingSymbol(const std::uint64_t index) const
        {
            if (index >= 25)
            {
                throw std::runtime_error("index out of range for underlyingSymbol [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 0 + (index * 1), sizeof(char));
            return (val);
        }

        NoUnderlyings &underlyingSymbol(const std::uint64_t index, const char value)
        {
            if (index >= 25)
            {
                throw std::runtime_error("index out of range for underlyingSymbol [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 0 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getUnderlyingSymbol(char *const dst, const std::uint64_t length) const
        {
            if (length > 25)
            {
                throw std::runtime_error("length too large for getUnderlyingSymbol [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 0, sizeof(char) * static_cast<size_t>(length));
            return length;
        }

        NoUnderlyings &putUnderlyingSymbol(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 0, src, sizeof(char) * 25);
            return *this;
        }

        SBE_NODISCARD std::string getUnderlyingSymbolAsString() const
        {
            const char *buffer = m_buffer + m_offset + 0;
            size_t length = 0;

            for (; length < 25 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getUnderlyingSymbolAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getUnderlyingSymbolAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getUnderlyingSymbolAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 0;
            size_t length = 0;

            for (; length < 25 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        NoUnderlyings &putUnderlyingSymbol(const std::string_view str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 25)
            {
                throw std::runtime_error("string too large for putUnderlyingSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 0, str.data(), srcLength);
            for (size_t start = srcLength; start < 25; ++start)
            {
                m_buffer[m_offset + 0 + start] = 0;
            }

            return *this;
        }
        #else
        NoUnderlyings &putUnderlyingSymbol(const std::string& str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 25)
            {
                throw std::runtime_error("string too large for putUnderlyingSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 0, str.c_str(), srcLength);
            for (size_t start = srcLength; start < 25; ++start)
            {
                m_buffer[m_offset + 0 + start] = 0;
            }

            return *this;
        }
        #endif

        SBE_NODISCARD static const char *UnderlyingBoardMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingBoardId() SBE_NOEXCEPT
        {
            return 20045;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingBoardSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingBoardInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= underlyingBoardSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingBoardEncodingOffset() SBE_NOEXCEPT
        {
            return 25;
        }

        static SBE_CONSTEXPR char underlyingBoardNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char underlyingBoardMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char underlyingBoardMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t underlyingBoardEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint64_t underlyingBoardLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD const char *underlyingBoard() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 25;
        }

        SBE_NODISCARD char *underlyingBoard() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 25;
        }

        SBE_NODISCARD char underlyingBoard(const std::uint64_t index) const
        {
            if (index >= 4)
            {
                throw std::runtime_error("index out of range for underlyingBoard [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 25 + (index * 1), sizeof(char));
            return (val);
        }

        NoUnderlyings &underlyingBoard(const std::uint64_t index, const char value)
        {
            if (index >= 4)
            {
                throw std::runtime_error("index out of range for underlyingBoard [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 25 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getUnderlyingBoard(char *const dst, const std::uint64_t length) const
        {
            if (length > 4)
            {
                throw std::runtime_error("length too large for getUnderlyingBoard [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 25, sizeof(char) * static_cast<size_t>(length));
            return length;
        }

        NoUnderlyings &putUnderlyingBoard(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 25, src, sizeof(char) * 4);
            return *this;
        }

        NoUnderlyings &putUnderlyingBoard(
            const char value0,
            const char value1,
            const char value2,
            const char value3) SBE_NOEXCEPT
        {
            char val0 = (value0);
            std::memcpy(m_buffer + m_offset + 25, &val0, sizeof(char));
            char val1 = (value1);
            std::memcpy(m_buffer + m_offset + 26, &val1, sizeof(char));
            char val2 = (value2);
            std::memcpy(m_buffer + m_offset + 27, &val2, sizeof(char));
            char val3 = (value3);
            std::memcpy(m_buffer + m_offset + 28, &val3, sizeof(char));

            return *this;
        }

        SBE_NODISCARD std::string getUnderlyingBoardAsString() const
        {
            const char *buffer = m_buffer + m_offset + 25;
            size_t length = 0;

            for (; length < 4 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getUnderlyingBoardAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getUnderlyingBoardAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getUnderlyingBoardAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 25;
            size_t length = 0;

            for (; length < 4 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        NoUnderlyings &putUnderlyingBoard(const std::string_view str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 4)
            {
                throw std::runtime_error("string too large for putUnderlyingBoard [E106]");
            }

            std::memcpy(m_buffer + m_offset + 25, str.data(), srcLength);
            for (size_t start = srcLength; start < 4; ++start)
            {
                m_buffer[m_offset + 25 + start] = 0;
            }

            return *this;
        }
        #else
        NoUnderlyings &putUnderlyingBoard(const std::string& str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 4)
            {
                throw std::runtime_error("string too large for putUnderlyingBoard [E106]");
            }

            std::memcpy(m_buffer + m_offset + 25, str.c_str(), srcLength);
            for (size_t start = srcLength; start < 4; ++start)
            {
                m_buffer[m_offset + 25 + start] = 0;
            }

            return *this;
        }
        #endif

        SBE_NODISCARD static const char *UnderlyingSecurityIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingSecurityIDId() SBE_NOEXCEPT
        {
            return 309;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingSecurityIDSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingSecurityIDInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= underlyingSecurityIDSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingSecurityIDEncodingOffset() SBE_NOEXCEPT
        {
            return 29;
        }

        static SBE_CONSTEXPR std::int32_t underlyingSecurityIDNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT32;
        }

        static SBE_CONSTEXPR std::int32_t underlyingSecurityIDMinValue() SBE_NOEXCEPT
        {
            return INT32_C(-2147483647);
        }

        static SBE_CONSTEXPR std::int32_t underlyingSecurityIDMaxValue() SBE_NOEXCEPT
        {
            return INT32_C(2147483647);
        }

        static SBE_CONSTEXPR std::size_t underlyingSecurityIDEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::int32_t underlyingSecurityID() const SBE_NOEXCEPT
        {
            std::int32_t val;
            std::memcpy(&val, m_buffer + m_offset + 29, sizeof(std::int32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoUnderlyings &underlyingSecurityID(const std::int32_t value) SBE_NOEXCEPT
        {
            std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 29, &val, sizeof(std::int32_t));
            return *this;
        }

        SBE_NODISCARD static const char *UnderlyingFutureIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t underlyingFutureIDId() SBE_NOEXCEPT
        {
            return 2620;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t underlyingFutureIDSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool underlyingFutureIDInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= underlyingFutureIDSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t underlyingFutureIDEncodingOffset() SBE_NOEXCEPT
        {
            return 33;
        }

        static SBE_CONSTEXPR std::int32_t underlyingFutureIDNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT32;
        }

        static SBE_CONSTEXPR std::int32_t underlyingFutureIDMinValue() SBE_NOEXCEPT
        {
            return INT32_C(-2147483647);
        }

        static SBE_CONSTEXPR std::int32_t underlyingFutureIDMaxValue() SBE_NOEXCEPT
        {
            return INT32_C(2147483647);
        }

        static SBE_CONSTEXPR std::size_t underlyingFutureIDEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::int32_t underlyingFutureID() const SBE_NOEXCEPT
        {
            std::int32_t val;
            std::memcpy(&val, m_buffer + m_offset + 33, sizeof(std::int32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoUnderlyings &underlyingFutureID(const std::int32_t value) SBE_NOEXCEPT
        {
            std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 33, &val, sizeof(std::int32_t));
            return *this;
        }

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits>& operator << (
            std::basic_ostream<CharT, Traits>& builder, NoUnderlyings writer)
        {
            builder << '{';
            builder << R"("UnderlyingSymbol": )";
            builder << '"' <<
                writer.getUnderlyingSymbolAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("UnderlyingBoard": )";
            builder << '"' <<
                writer.getUnderlyingBoardAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("UnderlyingSecurityID": )";
            builder << +writer.underlyingSecurityID();

            builder << ", ";
            builder << R"("UnderlyingFutureID": )";
            builder << +writer.underlyingFutureID();

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoUnderlyings m_noUnderlyings;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t NoUnderlyingsId() SBE_NOEXCEPT
    {
        return 711;
    }

    SBE_NODISCARD inline NoUnderlyings &noUnderlyings()
    {
        m_noUnderlyings.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noUnderlyings;
    }

    NoUnderlyings &noUnderlyingsCount(const std::uint8_t count)
    {
        m_noUnderlyings.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noUnderlyings;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noUnderlyingsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noUnderlyingsInActingVersion() const SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= noUnderlyingsSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    class NoLegs
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(33));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 33;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 33;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoLegs &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex() SBE_NOEXCEPT
        {
            m_count = m_index;
            GroupSize dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #endif

        SBE_NODISCARD static const char *LegSymbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSymbolId() SBE_NOEXCEPT
        {
            return 600;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSymbolSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSymbolInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= legSymbolSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSymbolEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR char legSymbolNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char legSymbolMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char legSymbolMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t legSymbolEncodingLength() SBE_NOEXCEPT
        {
            return 25;
        }

        static SBE_CONSTEXPR std::uint64_t legSymbolLength() SBE_NOEXCEPT
        {
            return 25;
        }

        SBE_NODISCARD const char *legSymbol() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 0;
        }

        SBE_NODISCARD char *legSymbol() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 0;
        }

        SBE_NODISCARD char legSymbol(const std::uint64_t index) const
        {
            if (index >= 25)
            {
                throw std::runtime_error("index out of range for legSymbol [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 0 + (index * 1), sizeof(char));
            return (val);
        }

        NoLegs &legSymbol(const std::uint64_t index, const char value)
        {
            if (index >= 25)
            {
                throw std::runtime_error("index out of range for legSymbol [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 0 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getLegSymbol(char *const dst, const std::uint64_t length) const
        {
            if (length > 25)
            {
                throw std::runtime_error("length too large for getLegSymbol [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 0, sizeof(char) * static_cast<size_t>(length));
            return length;
        }

        NoLegs &putLegSymbol(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 0, src, sizeof(char) * 25);
            return *this;
        }

        SBE_NODISCARD std::string getLegSymbolAsString() const
        {
            const char *buffer = m_buffer + m_offset + 0;
            size_t length = 0;

            for (; length < 25 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getLegSymbolAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getLegSymbolAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getLegSymbolAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 0;
            size_t length = 0;

            for (; length < 25 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        NoLegs &putLegSymbol(const std::string_view str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 25)
            {
                throw std::runtime_error("string too large for putLegSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 0, str.data(), srcLength);
            for (size_t start = srcLength; start < 25; ++start)
            {
                m_buffer[m_offset + 0 + start] = 0;
            }

            return *this;
        }
        #else
        NoLegs &putLegSymbol(const std::string& str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 25)
            {
                throw std::runtime_error("string too large for putLegSymbol [E106]");
            }

            std::memcpy(m_buffer + m_offset + 0, str.c_str(), srcLength);
            for (size_t start = srcLength; start < 25; ++start)
            {
                m_buffer[m_offset + 0 + start] = 0;
            }

            return *this;
        }
        #endif

        SBE_NODISCARD static const char *LegSecurityIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legSecurityIDId() SBE_NOEXCEPT
        {
            return 602;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legSecurityIDSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legSecurityIDInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= legSecurityIDSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legSecurityIDEncodingOffset() SBE_NOEXCEPT
        {
            return 25;
        }

        static SBE_CONSTEXPR std::int32_t legSecurityIDNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT32;
        }

        static SBE_CONSTEXPR std::int32_t legSecurityIDMinValue() SBE_NOEXCEPT
        {
            return INT32_C(-2147483647);
        }

        static SBE_CONSTEXPR std::int32_t legSecurityIDMaxValue() SBE_NOEXCEPT
        {
            return INT32_C(2147483647);
        }

        static SBE_CONSTEXPR std::size_t legSecurityIDEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::int32_t legSecurityID() const SBE_NOEXCEPT
        {
            std::int32_t val;
            std::memcpy(&val, m_buffer + m_offset + 25, sizeof(std::int32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoLegs &legSecurityID(const std::int32_t value) SBE_NOEXCEPT
        {
            std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 25, &val, sizeof(std::int32_t));
            return *this;
        }

        SBE_NODISCARD static const char *LegRatioQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t legRatioQtyId() SBE_NOEXCEPT
        {
            return 623;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t legRatioQtySinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool legRatioQtyInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= legRatioQtySinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t legRatioQtyEncodingOffset() SBE_NOEXCEPT
        {
            return 29;
        }

        static SBE_CONSTEXPR std::int32_t legRatioQtyNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT32;
        }

        static SBE_CONSTEXPR std::int32_t legRatioQtyMinValue() SBE_NOEXCEPT
        {
            return INT32_C(-2147483647);
        }

        static SBE_CONSTEXPR std::int32_t legRatioQtyMaxValue() SBE_NOEXCEPT
        {
            return INT32_C(2147483647);
        }

        static SBE_CONSTEXPR std::size_t legRatioQtyEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::int32_t legRatioQty() const SBE_NOEXCEPT
        {
            std::int32_t val;
            std::memcpy(&val, m_buffer + m_offset + 29, sizeof(std::int32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoLegs &legRatioQty(const std::int32_t value) SBE_NOEXCEPT
        {
            std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 29, &val, sizeof(std::int32_t));
            return *this;
        }

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits>& operator << (
            std::basic_ostream<CharT, Traits>& builder, NoLegs writer)
        {
            builder << '{';
            builder << R"("LegSymbol": )";
            builder << '"' <<
                writer.getLegSymbolAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("LegSecurityID": )";
            builder << +writer.legSecurityID();

            builder << ", ";
            builder << R"("LegRatioQty": )";
            builder << +writer.legRatioQty();

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoLegs m_noLegs;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t NoLegsId() SBE_NOEXCEPT
    {
        return 555;
    }

    SBE_NODISCARD inline NoLegs &noLegs()
    {
        m_noLegs.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noLegs;
    }

    NoLegs &noLegsCount(const std::uint8_t count)
    {
        m_noLegs.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noLegs;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noLegsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noLegsInActingVersion() const SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= noLegsSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    class NoInstrAttrib
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(35));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 35;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 35;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoInstrAttrib &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex() SBE_NOEXCEPT
        {
            m_count = m_index;
            GroupSize dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #endif

        SBE_NODISCARD static const char *InstrAttribTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t instrAttribTypeId() SBE_NOEXCEPT
        {
            return 871;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t instrAttribTypeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool instrAttribTypeInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= instrAttribTypeSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t instrAttribTypeEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::int32_t instrAttribTypeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT32;
        }

        static SBE_CONSTEXPR std::int32_t instrAttribTypeMinValue() SBE_NOEXCEPT
        {
            return INT32_C(-2147483647);
        }

        static SBE_CONSTEXPR std::int32_t instrAttribTypeMaxValue() SBE_NOEXCEPT
        {
            return INT32_C(2147483647);
        }

        static SBE_CONSTEXPR std::size_t instrAttribTypeEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::int32_t instrAttribType() const SBE_NOEXCEPT
        {
            std::int32_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoInstrAttrib &instrAttribType(const std::int32_t value) SBE_NOEXCEPT
        {
            std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int32_t));
            return *this;
        }

        SBE_NODISCARD static const char *InstrAttribValueMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t instrAttribValueId() SBE_NOEXCEPT
        {
            return 872;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t instrAttribValueSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool instrAttribValueInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= instrAttribValueSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t instrAttribValueEncodingOffset() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR char instrAttribValueNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char instrAttribValueMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char instrAttribValueMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t instrAttribValueEncodingLength() SBE_NOEXCEPT
        {
            return 31;
        }

        static SBE_CONSTEXPR std::uint64_t instrAttribValueLength() SBE_NOEXCEPT
        {
            return 31;
        }

        SBE_NODISCARD const char *instrAttribValue() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 4;
        }

        SBE_NODISCARD char *instrAttribValue() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 4;
        }

        SBE_NODISCARD char instrAttribValue(const std::uint64_t index) const
        {
            if (index >= 31)
            {
                throw std::runtime_error("index out of range for instrAttribValue [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 4 + (index * 1), sizeof(char));
            return (val);
        }

        NoInstrAttrib &instrAttribValue(const std::uint64_t index, const char value)
        {
            if (index >= 31)
            {
                throw std::runtime_error("index out of range for instrAttribValue [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 4 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getInstrAttribValue(char *const dst, const std::uint64_t length) const
        {
            if (length > 31)
            {
                throw std::runtime_error("length too large for getInstrAttribValue [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 4, sizeof(char) * static_cast<size_t>(length));
            return length;
        }

        NoInstrAttrib &putInstrAttribValue(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 4, src, sizeof(char) * 31);
            return *this;
        }

        SBE_NODISCARD std::string getInstrAttribValueAsString() const
        {
            const char *buffer = m_buffer + m_offset + 4;
            size_t length = 0;

            for (; length < 31 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getInstrAttribValueAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getInstrAttribValueAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getInstrAttribValueAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 4;
            size_t length = 0;

            for (; length < 31 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        NoInstrAttrib &putInstrAttribValue(const std::string_view str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 31)
            {
                throw std::runtime_error("string too large for putInstrAttribValue [E106]");
            }

            std::memcpy(m_buffer + m_offset + 4, str.data(), srcLength);
            for (size_t start = srcLength; start < 31; ++start)
            {
                m_buffer[m_offset + 4 + start] = 0;
            }

            return *this;
        }
        #else
        NoInstrAttrib &putInstrAttribValue(const std::string& str)
        {
            const size_t srcLength = str.length();
            if (srcLength > 31)
            {
                throw std::runtime_error("string too large for putInstrAttribValue [E106]");
            }

            std::memcpy(m_buffer + m_offset + 4, str.c_str(), srcLength);
            for (size_t start = srcLength; start < 31; ++start)
            {
                m_buffer[m_offset + 4 + start] = 0;
            }

            return *this;
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits>& operator << (
            std::basic_ostream<CharT, Traits>& builder, NoInstrAttrib writer)
        {
            builder << '{';
            builder << R"("InstrAttribType": )";
            builder << +writer.instrAttribType();

            builder << ", ";
            builder << R"("InstrAttribValue": )";
            builder << '"' <<
                writer.getInstrAttribValueAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoInstrAttrib m_noInstrAttrib;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t NoInstrAttribId() SBE_NOEXCEPT
    {
        return 870;
    }

    SBE_NODISCARD inline NoInstrAttrib &noInstrAttrib()
    {
        m_noInstrAttrib.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noInstrAttrib;
    }

    NoInstrAttrib &noInstrAttribCount(const std::uint8_t count)
    {
        m_noInstrAttrib.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noInstrAttrib;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noInstrAttribSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noInstrAttribInActingVersion() const SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= noInstrAttribSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    class NoEvents
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint8_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(16));
            dimensions.numInGroup(static_cast<std::uint8_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 16;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 16;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline NoEvents &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex() SBE_NOEXCEPT
        {
            m_count = m_index;
            GroupSize dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint8_t>(m_count));
            return m_count;
        }

    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #endif

        SBE_NODISCARD static const char *EventTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t eventTypeId() SBE_NOEXCEPT
        {
            return 865;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t eventTypeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool eventTypeInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= eventTypeSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t eventTypeEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::int32_t eventTypeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT32;
        }

        static SBE_CONSTEXPR std::int32_t eventTypeMinValue() SBE_NOEXCEPT
        {
            return INT32_C(-2147483647);
        }

        static SBE_CONSTEXPR std::int32_t eventTypeMaxValue() SBE_NOEXCEPT
        {
            return INT32_C(2147483647);
        }

        static SBE_CONSTEXPR std::size_t eventTypeEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::int32_t eventType() const SBE_NOEXCEPT
        {
            std::int32_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoEvents &eventType(const std::int32_t value) SBE_NOEXCEPT
        {
            std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int32_t));
            return *this;
        }

        SBE_NODISCARD static const char *EventDateMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t eventDateId() SBE_NOEXCEPT
        {
            return 866;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t eventDateSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool eventDateInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= eventDateSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t eventDateEncodingOffset() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint32_t eventDateNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT32;
        }

        static SBE_CONSTEXPR std::uint32_t eventDateMinValue() SBE_NOEXCEPT
        {
            return UINT32_C(0x0);
        }

        static SBE_CONSTEXPR std::uint32_t eventDateMaxValue() SBE_NOEXCEPT
        {
            return UINT32_C(0xfffffffe);
        }

        static SBE_CONSTEXPR std::size_t eventDateEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD std::uint32_t eventDate() const SBE_NOEXCEPT
        {
            std::uint32_t val;
            std::memcpy(&val, m_buffer + m_offset + 4, sizeof(std::uint32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(val);
        }

        NoEvents &eventDate(const std::uint32_t value) SBE_NOEXCEPT
        {
            std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            std::memcpy(m_buffer + m_offset + 4, &val, sizeof(std::uint32_t));
            return *this;
        }

        SBE_NODISCARD static const char *EventTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t eventTimeId() SBE_NOEXCEPT
        {
            return 1145;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t eventTimeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool eventTimeInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= eventTimeSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t eventTimeEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        static SBE_CONSTEXPR std::uint64_t eventTimeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT64;
        }

        static SBE_CONSTEXPR std::uint64_t eventTimeMinValue() SBE_NOEXCEPT
        {
            return UINT64_C(0x0);
        }

        static SBE_CONSTEXPR std::uint64_t eventTimeMaxValue() SBE_NOEXCEPT
        {
            return UINT64_C(0xfffffffffffffffe);
        }

        static SBE_CONSTEXPR std::size_t eventTimeEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::uint64_t eventTime() const SBE_NOEXCEPT
        {
            std::uint64_t val;
            std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::uint64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        NoEvents &eventTime(const std::uint64_t value) SBE_NOEXCEPT
        {
            std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::uint64_t));
            return *this;
        }

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits>& operator << (
            std::basic_ostream<CharT, Traits>& builder, NoEvents writer)
        {
            builder << '{';
            builder << R"("EventType": )";
            builder << +writer.eventType();

            builder << ", ";
            builder << R"("EventDate": )";
            builder << +writer.eventDate();

            builder << ", ";
            builder << R"("EventTime": )";
            builder << +writer.eventTime();

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    NoEvents m_noEvents;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t NoEventsId() SBE_NOEXCEPT
    {
        return 864;
    }

    SBE_NODISCARD inline NoEvents &noEvents()
    {
        m_noEvents.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noEvents;
    }

    NoEvents &noEventsCount(const std::uint8_t count)
    {
        m_noEvents.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_noEvents;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t noEventsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool noEventsInActingVersion() const SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= noEventsSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    SBE_NODISCARD static const char *SecurityDescMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static const char *securityDescCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t securityDescSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool securityDescInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= securityDescSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::uint16_t securityDescId() SBE_NOEXCEPT
    {
        return 107;
    }

    static SBE_CONSTEXPR std::uint64_t securityDescHeaderLength() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD std::uint16_t securityDescLength() const
    {
        std::uint16_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(length);
    }

    std::uint64_t skipSecurityDesc()
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        sbePosition(lengthPosition + lengthOfLengthField + dataLength);
        return dataLength;
    }

    SBE_NODISCARD const char *securityDesc()
    {
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint16_t));
        const char *fieldPtr = m_buffer + sbePosition() + 2;
        sbePosition(sbePosition() + 2 + SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getSecurityDesc(char *dst, const std::uint64_t length)
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
        std::uint64_t pos = sbePosition();
        sbePosition(pos + dataLength);
        std::memcpy(dst, m_buffer + pos, static_cast<size_t>(bytesToCopy));
        return bytesToCopy;
    }

    SecurityDefinition &putSecurityDesc(const char *src, const std::uint16_t length)
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        std::uint16_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_16(length);
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint16_t));
        if (length != std::uint16_t(0))
        {
            std::uint64_t pos = sbePosition();
            sbePosition(pos + length);
            std::memcpy(m_buffer + pos, src, length);
        }
        return *this;
    }

    std::string getSecurityDescAsString()
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }

    std::string getSecurityDescAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSecurityDescAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    std::string_view getSecurityDescAsStringView()
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string_view result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }
    #endif

    SecurityDefinition &putSecurityDesc(const std::string& str)
    {
        if (str.length() > 65534)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSecurityDesc(str.data(), static_cast<std::uint16_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    SecurityDefinition &putSecurityDesc(const std::string_view str)
    {
        if (str.length() > 65534)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSecurityDesc(str.data(), static_cast<std::uint16_t>(str.length()));
    }
    #endif

    SBE_NODISCARD static const char *QuotationListMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static const char *quotationListCharacterEncoding() SBE_NOEXCEPT
    {
        return "US-ASCII";
    }

    static SBE_CONSTEXPR std::uint64_t quotationListSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool quotationListInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= quotationListSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::uint16_t quotationListId() SBE_NOEXCEPT
    {
        return 20005;
    }

    static SBE_CONSTEXPR std::uint64_t quotationListHeaderLength() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD std::uint16_t quotationListLength() const
    {
        std::uint16_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(length);
    }

    std::uint64_t skipQuotationList()
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        sbePosition(lengthPosition + lengthOfLengthField + dataLength);
        return dataLength;
    }

    SBE_NODISCARD const char *quotationList()
    {
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint16_t));
        const char *fieldPtr = m_buffer + sbePosition() + 2;
        sbePosition(sbePosition() + 2 + SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getQuotationList(char *dst, const std::uint64_t length)
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
        std::uint64_t pos = sbePosition();
        sbePosition(pos + dataLength);
        std::memcpy(dst, m_buffer + pos, static_cast<size_t>(bytesToCopy));
        return bytesToCopy;
    }

    SecurityDefinition &putQuotationList(const char *src, const std::uint16_t length)
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        std::uint16_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_16(length);
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint16_t));
        if (length != std::uint16_t(0))
        {
            std::uint64_t pos = sbePosition();
            sbePosition(pos + length);
            std::memcpy(m_buffer + pos, src, length);
        }
        return *this;
    }

    std::string getQuotationListAsString()
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }

    std::string getQuotationListAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getQuotationListAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    std::string_view getQuotationListAsStringView()
    {
        std::uint64_t lengthOfLengthField = 2;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint16_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint16_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_16(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string_view result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }
    #endif

    SecurityDefinition &putQuotationList(const std::string& str)
    {
        if (str.length() > 65534)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putQuotationList(str.data(), static_cast<std::uint16_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    SecurityDefinition &putQuotationList(const std::string_view str)
    {
        if (str.length() > 65534)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putQuotationList(str.data(), static_cast<std::uint16_t>(str.length()));
    }
    #endif

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits>& operator << (
    std::basic_ostream<CharT, Traits>& builder, SecurityDefinition _writer)
{
    SecurityDefinition writer(_writer.m_buffer, _writer.m_offset,
        _writer.m_bufferLength, _writer.sbeBlockLength(), _writer.m_actingVersion);
    builder << '{';
    builder << R"("Name": "SecurityDefinition", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("TotNumReports": )";
    builder << +writer.totNumReports();

    builder << ", ";
    builder << R"("Symbol": )";
    builder << '"' <<
        writer.getSymbolAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("SecurityID": )";
    builder << +writer.securityID();

    builder << ", ";
    builder << R"("SecurityAltID": )";
    builder << '"' <<
        writer.getSecurityAltIDAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("SecurityAltIDSource": )";
    builder << '"' << writer.securityAltIDSource() << '"';

    builder << ", ";
    builder << R"("SecurityType": )";
    builder << '"' <<
        writer.getSecurityTypeAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("CFICode": )";
    builder << '"' <<
        writer.getCFICodeAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("StrikePrice": )";
    builder << writer.strikePrice();

    builder << ", ";
    builder << R"("ContractMultiplier": )";
    builder << +writer.contractMultiplier();

    builder << ", ";
    builder << R"("SecurityTradingStatus": )";
    builder << '"' << writer.securityTradingStatus() << '"';

    builder << ", ";
    builder << R"("Currency": )";
    builder << '"' <<
        writer.getCurrencyAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("MarketSegmentID": )";
    builder << '"' << writer.marketSegmentID() << '"';

    builder << ", ";
    builder << R"("TradingSessionID": )";
    builder << '"' << writer.tradingSessionID() << '"';

    builder << ", ";
    builder << R"("ExchangeTradingSessionID": )";
    builder << +writer.exchangeTradingSessionID();

    builder << ", ";
    builder << R"("Volatility": )";
    builder << writer.volatility();

    builder << ", ";
    builder << R"("HighLimitPx": )";
    builder << writer.highLimitPx();

    builder << ", ";
    builder << R"("LowLimitPx": )";
    builder << writer.lowLimitPx();

    builder << ", ";
    builder << R"("MinPriceIncrement": )";
    builder << writer.minPriceIncrement();

    builder << ", ";
    builder << R"("MinPriceIncrementAmount": )";
    builder << writer.minPriceIncrementAmount();

    builder << ", ";
    builder << R"("InitialMarginOnBuy": )";
    builder << writer.initialMarginOnBuy();

    builder << ", ";
    builder << R"("InitialMarginOnSell": )";
    builder << writer.initialMarginOnSell();

    builder << ", ";
    builder << R"("InitialMarginSyntetic": )";
    builder << writer.initialMarginSyntetic();

    builder << ", ";
    builder << R"("TheorPrice": )";
    builder << writer.theorPrice();

    builder << ", ";
    builder << R"("TheorPriceLimit": )";
    builder << writer.theorPriceLimit();

    builder << ", ";
    builder << R"("UnderlyingQty": )";
    builder << writer.underlyingQty();

    builder << ", ";
    builder << R"("UnderlyingCurrency": )";
    builder << '"' <<
        writer.getUnderlyingCurrencyAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("MaturityDate": )";
    builder << +writer.maturityDate();

    builder << ", ";
    builder << R"("MaturityTime": )";
    builder << +writer.maturityTime();

    builder << ", ";
    builder << R"("Flags": )";
    builder << writer.flags();

    builder << ", ";
    builder << R"("MinPriceIncrementAmountCurr": )";
    builder << writer.minPriceIncrementAmountCurr();

    builder << ", ";
    builder << R"("SettlPriceOpen": )";
    builder << writer.settlPriceOpen();

    builder << ", ";
    builder << R"("ValuationMethod": )";
    builder << '"' <<
        writer.getValuationMethodAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("RiskFreeRate": )";
    builder << +writer.riskFreeRate();

    builder << ", ";
    builder << R"("FixedSpotDiscount": )";
    builder << +writer.fixedSpotDiscount();

    builder << ", ";
    builder << R"("ProjectedSpotDiscount": )";
    builder << +writer.projectedSpotDiscount();

    builder << ", ";
    builder << R"("SettlCurrency": )";
    builder << '"' <<
        writer.getSettlCurrencyAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("NegativePrices": )";
    builder << '"' << writer.negativePrices() << '"';

    builder << ", ";
    builder << R"("DerivativeContractMultiplier": )";
    builder << +writer.derivativeContractMultiplier();

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("NoMDFeedTypes": [)";
        writer.noMDFeedTypes().forEach([&](NoMDFeedTypes& noMDFeedTypes)
        {
            if (atLeastOne)
            {
                builder << ", ";
            }
            atLeastOne = true;
            builder << noMDFeedTypes;
        });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("NoUnderlyings": [)";
        writer.noUnderlyings().forEach([&](NoUnderlyings& noUnderlyings)
        {
            if (atLeastOne)
            {
                builder << ", ";
            }
            atLeastOne = true;
            builder << noUnderlyings;
        });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("NoLegs": [)";
        writer.noLegs().forEach([&](NoLegs& noLegs)
        {
            if (atLeastOne)
            {
                builder << ", ";
            }
            atLeastOne = true;
            builder << noLegs;
        });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("NoInstrAttrib": [)";
        writer.noInstrAttrib().forEach([&](NoInstrAttrib& noInstrAttrib)
        {
            if (atLeastOne)
            {
                builder << ", ";
            }
            atLeastOne = true;
            builder << noInstrAttrib;
        });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("NoEvents": [)";
        writer.noEvents().forEach([&](NoEvents& noEvents)
        {
            if (atLeastOne)
            {
                builder << ", ";
            }
            atLeastOne = true;
            builder << noEvents;
        });
        builder << ']';
    }

    builder << ", ";
    builder << R"("SecurityDesc": )";
    builder << '"' <<
        writer.getSecurityDescAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("QuotationList": )";
    builder << '"' <<
        writer.getQuotationListAsJsonEscapedString().c_str() << '"';

    builder << '}';

    return builder;
}

void skip()
{
    noMDFeedTypes().forEach([](NoMDFeedTypes e)
    {
        e.skip();
    });
    noUnderlyings().forEach([](NoUnderlyings e)
    {
        e.skip();
    });
    noLegs().forEach([](NoLegs e)
    {
        e.skip();
    });
    noInstrAttrib().forEach([](NoInstrAttrib e)
    {
        e.skip();
    });
    noEvents().forEach([](NoEvents e)
    {
        e.skip();
    });
    skipSecurityDesc();
    skipQuotationList();
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(
    std::size_t noMDFeedTypesLength = 0,
    std::size_t noUnderlyingsLength = 0,
    std::size_t noLegsLength = 0,
    std::size_t noInstrAttribLength = 0,
    std::size_t noEventsLength = 0,
    std::size_t securityDescLength = 0,
    std::size_t quotationListLength = 0)
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += NoMDFeedTypes::sbeHeaderSize();
    if (noMDFeedTypesLength > 254LL)
    {
        throw std::runtime_error("noMDFeedTypesLength outside of allowed range [E110]");
    }
    length += noMDFeedTypesLength *NoMDFeedTypes::sbeBlockLength();

    length += NoUnderlyings::sbeHeaderSize();
    if (noUnderlyingsLength > 254LL)
    {
        throw std::runtime_error("noUnderlyingsLength outside of allowed range [E110]");
    }
    length += noUnderlyingsLength *NoUnderlyings::sbeBlockLength();

    length += NoLegs::sbeHeaderSize();
    if (noLegsLength > 254LL)
    {
        throw std::runtime_error("noLegsLength outside of allowed range [E110]");
    }
    length += noLegsLength *NoLegs::sbeBlockLength();

    length += NoInstrAttrib::sbeHeaderSize();
    if (noInstrAttribLength > 254LL)
    {
        throw std::runtime_error("noInstrAttribLength outside of allowed range [E110]");
    }
    length += noInstrAttribLength *NoInstrAttrib::sbeBlockLength();

    length += NoEvents::sbeHeaderSize();
    if (noEventsLength > 254LL)
    {
        throw std::runtime_error("noEventsLength outside of allowed range [E110]");
    }
    length += noEventsLength *NoEvents::sbeBlockLength();

    length += securityDescHeaderLength();
    if (securityDescLength > 65534LL)
    {
        throw std::runtime_error("securityDescLength too long for length type [E109]");
    }
    length += securityDescLength;

    length += quotationListHeaderLength();
    if (quotationListLength > 65534LL)
    {
        throw std::runtime_error("quotationListLength too long for length type [E109]");
    }
    length += quotationListLength;

    return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
}
};
}
#endif
