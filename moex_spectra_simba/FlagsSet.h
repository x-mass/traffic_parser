/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MOEX_SPECTRA_SIMBA_FLAGSSET_H_
#define _MOEX_SPECTRA_SIMBA_FLAGSSET_H_

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

class FlagsSet
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

    FlagsSet() = default;

    FlagsSet(
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

    FlagsSet(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        FlagsSet(buffer, 0, bufferLength, actingVersion)
    {
    }

    FlagsSet(
        char *buffer,
        const std::uint64_t bufferLength) :
        FlagsSet(buffer, 0, bufferLength, sbeSchemaVersion())
    {
    }

    FlagsSet &wrap(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        return *this = FlagsSet(buffer, offset, bufferLength, actingVersion);
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

    FlagsSet &clear()
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

    FlagsSet &rawValue(std::uint64_t value)
    {
        std::memcpy(m_buffer + m_offset, &value, sizeof(std::uint64_t));
        return *this;
    }

    static bool eveningOrMorningSession(const std::uint64_t bits)
    {
        return (bits & (1u << 0u)) != 0;
    }

    static std::uint64_t eveningOrMorningSession(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 0u)) : static_cast<std::uint64_t>(bits & ~(1u << 0u));
    }

    SBE_NODISCARD bool eveningOrMorningSession() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 0u)) != 0;
    }

    FlagsSet &eveningOrMorningSession(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 0u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 0u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool anonymousTrading(const std::uint64_t bits)
    {
        return (bits & (1u << 4u)) != 0;
    }

    static std::uint64_t anonymousTrading(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 4u)) : static_cast<std::uint64_t>(bits & ~(1u << 4u));
    }

    SBE_NODISCARD bool anonymousTrading() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 4u)) != 0;
    }

    FlagsSet &anonymousTrading(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 4u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 4u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool privateTrading(const std::uint64_t bits)
    {
        return (bits & (1u << 5u)) != 0;
    }

    static std::uint64_t privateTrading(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 5u)) : static_cast<std::uint64_t>(bits & ~(1u << 5u));
    }

    SBE_NODISCARD bool privateTrading() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 5u)) != 0;
    }

    FlagsSet &privateTrading(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 5u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 5u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool daySession(const std::uint64_t bits)
    {
        return (bits & (1u << 6u)) != 0;
    }

    static std::uint64_t daySession(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 6u)) : static_cast<std::uint64_t>(bits & ~(1u << 6u));
    }

    SBE_NODISCARD bool daySession() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 6u)) != 0;
    }

    FlagsSet &daySession(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 6u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 6u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool multiLeg(const std::uint64_t bits)
    {
        return (bits & (1u << 8u)) != 0;
    }

    static std::uint64_t multiLeg(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 8u)) : static_cast<std::uint64_t>(bits & ~(1u << 8u));
    }

    SBE_NODISCARD bool multiLeg() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 8u)) != 0;
    }

    FlagsSet &multiLeg(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 8u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 8u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool collateral(const std::uint64_t bits)
    {
        return (bits & (1u << 18u)) != 0;
    }

    static std::uint64_t collateral(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 18u)) : static_cast<std::uint64_t>(bits & ~(1u << 18u));
    }

    SBE_NODISCARD bool collateral() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 18u)) != 0;
    }

    FlagsSet &collateral(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 18u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 18u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    static bool intradayExercise(const std::uint64_t bits)
    {
        return (bits & (1u << 19u)) != 0;
    }

    static std::uint64_t intradayExercise(const std::uint64_t bits, const bool value)
    {
        return value ? static_cast<std::uint64_t>(bits | (1u << 19u)) : static_cast<std::uint64_t>(bits & ~(1u << 19u));
    }

    SBE_NODISCARD bool intradayExercise() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint64_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_64(val) & (1u << 19u)) != 0;
    }

    FlagsSet &intradayExercise(const bool value)
    {
        std::uint64_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint64_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_64(value ? static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) | (1u << 19u)) : static_cast<std::uint64_t>(SBE_LITTLE_ENDIAN_ENCODE_64(bits) & ~(1u << 19u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint64_t));
        return *this;
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator << (
        std::basic_ostream<CharT, Traits>& builder, FlagsSet writer)
    {
        builder << '[';
        bool atLeastOne = false;
        if (writer.eveningOrMorningSession())
        {
            builder << R"("eveningOrMorningSession")";
            atLeastOne = true;
        }
        if (writer.anonymousTrading())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("anonymousTrading")";
            atLeastOne = true;
        }
        if (writer.privateTrading())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("privateTrading")";
            atLeastOne = true;
        }
        if (writer.daySession())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("daySession")";
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
        if (writer.collateral())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("collateral")";
            atLeastOne = true;
        }
        if (writer.intradayExercise())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("intradayExercise")";
        }
        builder << ']';
        return builder;
    }
};
}
#endif
