/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MOEX_SPECTRA_SIMBA_MDFLAGSSET_H_
#define _MOEX_SPECTRA_SIMBA_MDFLAGSSET_H_

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


namespace moex_spectra_simba {

class MDFlagsSet
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_actingVersion = 0;

public:
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

    MDFlagsSet() = default;

    MDFlagsSet(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_actingVersion(actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 8) > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
    }

    MDFlagsSet(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        MDFlagsSet(buffer, 0, bufferLength, actingVersion)
    {
    }

    MDFlagsSet(
        char *buffer,
        const std::uint64_t bufferLength) :
        MDFlagsSet(buffer, 0, bufferLength, sbeSchemaVersion())
    {
    }

    MDFlagsSet &wrap(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        return *this = MDFlagsSet(buffer, offset, bufferLength, actingVersion);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t encodedLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
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

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(19780);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(3);
    }

    MDFlagsSet &clear()
    {
        std::uint64_t zero = 0;
        std::memcpy(m_buffer + m_offset, &zero, sizeof(std::uint64_t));
        return *this;
    }

    SBE_NODISCARD bool isEmpty() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return 0 == val;
    }

    SBE_NODISCARD std::uint64_t rawValue() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return val;
    }

    MDFlagsSet &rawValue(std::uint64_t value)
    {
        std::memcpy(m_buffer + m_offset, &value, sizeof(std::uint64_t));
        return *this;
    }

    static bool day(const std::uint64_t bits)
    {
        return (bits & (1u << 0u)) != 0;
    }

    static std::uint64_t day(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 0u)) : static_cast<std::uint64_t>(bits & ~(1u << 0u));
    }

    SBE_NODISCARD bool day() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 0u)) != 0;
    }

    MDFlagsSet &day(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 0u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 0u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool iOC(const std::uint64_t bits)
    {
        return (bits & (1u << 1u)) != 0;
    }

    static std::uint64_t iOC(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 1u)) : static_cast<std::uint64_t>(bits & ~(1u << 1u));
    }

    SBE_NODISCARD bool iOC() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 1u)) != 0;
    }

    MDFlagsSet &iOC(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 1u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 1u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool nonQuote(const std::uint64_t bits)
    {
        return (bits & (1u << 2u)) != 0;
    }

    static std::uint64_t nonQuote(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 2u)) : static_cast<std::uint64_t>(bits & ~(1u << 2u));
    }

    SBE_NODISCARD bool nonQuote() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 2u)) != 0;
    }

    MDFlagsSet &nonQuote(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 2u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 2u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool endOfTransaction(const std::uint64_t bits)
    {
        return (bits & (1u << 12u)) != 0;
    }

    static std::uint64_t endOfTransaction(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 12u)) : static_cast<std::uint64_t>(bits & ~(1u << 12u));
    }

    SBE_NODISCARD bool endOfTransaction() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 12u)) != 0;
    }

    MDFlagsSet &endOfTransaction(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 12u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 12u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool dueToCrossCancel(const std::uint64_t bits)
    {
        return (bits & (1u << 13u)) != 0;
    }

    static std::uint64_t dueToCrossCancel(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 13u)) : static_cast<std::uint64_t>(bits & ~(1u << 13u));
    }

    SBE_NODISCARD bool dueToCrossCancel() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 13u)) != 0;
    }

    MDFlagsSet &dueToCrossCancel(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 13u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 13u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool secondLeg(const std::uint64_t bits)
    {
        return (bits & (1u << 14u)) != 0;
    }

    static std::uint64_t secondLeg(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 14u)) : static_cast<std::uint64_t>(bits & ~(1u << 14u));
    }

    SBE_NODISCARD bool secondLeg() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 14u)) != 0;
    }

    MDFlagsSet &secondLeg(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 14u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 14u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool fOK(const std::uint64_t bits)
    {
        return (bits & (1u << 19u)) != 0;
    }

    static std::uint64_t fOK(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 19u)) : static_cast<std::uint64_t>(bits & ~(1u << 19u));
    }

    SBE_NODISCARD bool fOK() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 19u)) != 0;
    }

    MDFlagsSet &fOK(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 19u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 19u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool replace(const std::uint64_t bits)
    {
        return (bits & (1u << 20u)) != 0;
    }

    static std::uint64_t replace(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 20u)) : static_cast<std::uint64_t>(bits & ~(1u << 20u));
    }

    SBE_NODISCARD bool replace() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 20u)) != 0;
    }

    MDFlagsSet &replace(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 20u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 20u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool cancel(const std::uint64_t bits)
    {
        return (bits & (1u << 21u)) != 0;
    }

    static std::uint64_t cancel(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 21u)) : static_cast<std::uint64_t>(bits & ~(1u << 21u));
    }

    SBE_NODISCARD bool cancel() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 21u)) != 0;
    }

    MDFlagsSet &cancel(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 21u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 21u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool massCancel(const std::uint64_t bits)
    {
        return (bits & (1u << 22u)) != 0;
    }

    static std::uint64_t massCancel(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 22u)) : static_cast<std::uint64_t>(bits & ~(1u << 22u));
    }

    SBE_NODISCARD bool massCancel() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 22u)) != 0;
    }

    MDFlagsSet &massCancel(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 22u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 22u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool negotiated(const std::uint64_t bits)
    {
        return (bits & (1u << 26u)) != 0;
    }

    static std::uint64_t negotiated(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 26u)) : static_cast<std::uint64_t>(bits & ~(1u << 26u));
    }

    SBE_NODISCARD bool negotiated() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 26u)) != 0;
    }

    MDFlagsSet &negotiated(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 26u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 26u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool multiLeg(const std::uint64_t bits)
    {
        return (bits & (1u << 27u)) != 0;
    }

    static std::uint64_t multiLeg(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 27u)) : static_cast<std::uint64_t>(bits & ~(1u << 27u));
    }

    SBE_NODISCARD bool multiLeg() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 27u)) != 0;
    }

    MDFlagsSet &multiLeg(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 27u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 27u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool crossTrade(const std::uint64_t bits)
    {
        return (bits & (1u << 29u)) != 0;
    }

    static std::uint64_t crossTrade(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 29u)) : static_cast<std::uint64_t>(bits & ~(1u << 29u));
    }

    SBE_NODISCARD bool crossTrade() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 29u)) != 0;
    }

    MDFlagsSet &crossTrade(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 29u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 29u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool cOD(const std::uint64_t bits)
    {
        return (bits & (1u << 32u)) != 0;
    }

    static std::uint64_t cOD(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 32u)) : static_cast<std::uint64_t>(bits & ~(1u << 32u));
    }

    SBE_NODISCARD bool cOD() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 32u)) != 0;
    }

    MDFlagsSet &cOD(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 32u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 32u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool activeSide(const std::uint64_t bits)
    {
        return (bits & (1u << 41u)) != 0;
    }

    static std::uint64_t activeSide(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 41u)) : static_cast<std::uint64_t>(bits & ~(1u << 41u));
    }

    SBE_NODISCARD bool activeSide() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 41u)) != 0;
    }

    MDFlagsSet &activeSide(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 41u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 41u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool passiveSide(const std::uint64_t bits)
    {
        return (bits & (1u << 42u)) != 0;
    }

    static std::uint64_t passiveSide(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 42u)) : static_cast<std::uint64_t>(bits & ~(1u << 42u));
    }

    SBE_NODISCARD bool passiveSide() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 42u)) != 0;
    }

    MDFlagsSet &passiveSide(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 42u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 42u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool synthetic(const std::uint64_t bits)
    {
        return (bits & (1u << 45u)) != 0;
    }

    static std::uint64_t synthetic(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 45u)) : static_cast<std::uint64_t>(bits & ~(1u << 45u));
    }

    SBE_NODISCARD bool synthetic() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 45u)) != 0;
    }

    MDFlagsSet &synthetic(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 45u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 45u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool rFS(const std::uint64_t bits)
    {
        return (bits & (1u << 46u)) != 0;
    }

    static std::uint64_t rFS(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 46u)) : static_cast<std::uint64_t>(bits & ~(1u << 46u));
    }

    SBE_NODISCARD bool rFS() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 46u)) != 0;
    }

    MDFlagsSet &rFS(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 46u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 46u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool syntheticPassive(const std::uint64_t bits)
    {
        return (bits & (1u << 57u)) != 0;
    }

    static std::uint64_t syntheticPassive(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 57u)) : static_cast<std::uint64_t>(bits & ~(1u << 57u));
    }

    SBE_NODISCARD bool syntheticPassive() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 57u)) != 0;
    }

    MDFlagsSet &syntheticPassive(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 57u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 57u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool bOC(const std::uint64_t bits)
    {
        return (bits & (1u << 60u)) != 0;
    }

    static std::uint64_t bOC(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 60u)) : static_cast<std::uint64_t>(bits & ~(1u << 60u));
    }

    SBE_NODISCARD bool bOC() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 60u)) != 0;
    }

    MDFlagsSet &bOC(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 60u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 60u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool duringDiscreteAuction(const std::uint64_t bits)
    {
        return (bits & (1u << 62u)) != 0;
    }

    static std::uint64_t duringDiscreteAuction(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 62u)) : static_cast<std::uint64_t>(bits & ~(1u << 62u));
    }

    SBE_NODISCARD bool duringDiscreteAuction() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 62u)) != 0;
    }

    MDFlagsSet &duringDiscreteAuction(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 62u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 62u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator << (
        std::basic_ostream<CharT, Traits>& builder, MDFlagsSet writer)
    {
        builder << '[';
        bool atLeastOne = false;
        if (writer.day())
        {
            builder << R"("day")";
            atLeastOne = true;
        }
        if (writer.iOC())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("iOC")";
            atLeastOne = true;
        }
        if (writer.nonQuote())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("nonQuote")";
            atLeastOne = true;
        }
        if (writer.endOfTransaction())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("endOfTransaction")";
            atLeastOne = true;
        }
        if (writer.dueToCrossCancel())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("dueToCrossCancel")";
            atLeastOne = true;
        }
        if (writer.secondLeg())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("secondLeg")";
            atLeastOne = true;
        }
        if (writer.fOK())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("fOK")";
            atLeastOne = true;
        }
        if (writer.replace())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("replace")";
            atLeastOne = true;
        }
        if (writer.cancel())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("cancel")";
            atLeastOne = true;
        }
        if (writer.massCancel())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("massCancel")";
            atLeastOne = true;
        }
        if (writer.negotiated())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("negotiated")";
            atLeastOne = true;
        }
        if (writer.multiLeg())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("multiLeg")";
            atLeastOne = true;
        }
        if (writer.crossTrade())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("crossTrade")";
            atLeastOne = true;
        }
        if (writer.cOD())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("cOD")";
            atLeastOne = true;
        }
        if (writer.activeSide())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("activeSide")";
            atLeastOne = true;
        }
        if (writer.passiveSide())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("passiveSide")";
            atLeastOne = true;
        }
        if (writer.synthetic())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("synthetic")";
            atLeastOne = true;
        }
        if (writer.rFS())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("rFS")";
            atLeastOne = true;
        }
        if (writer.syntheticPassive())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("syntheticPassive")";
            atLeastOne = true;
        }
        if (writer.bOC())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("bOC")";
            atLeastOne = true;
        }
        if (writer.duringDiscreteAuction())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("duringDiscreteAuction")";
        }
        builder << ']';
        return builder;
    }
};
}
#endif
