/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MOEX_SPECTRA_SIMBA_SECURITYTRADINGSTATUS_H_
#define _MOEX_SPECTRA_SIMBA_SECURITYTRADINGSTATUS_H_

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

class SecurityTradingStatus
{
public:
    enum Value
    {
        TradingHalt = static_cast<std::uint8_t>(2),
        ReadyToTrade = static_cast<std::uint8_t>(17),
        NotAvailableForTrading = static_cast<std::uint8_t>(18),
        NotTradedOnThisMarket = static_cast<std::uint8_t>(19),
        UnknownOrInvalid = static_cast<std::uint8_t>(20),
        PreOpen = static_cast<std::uint8_t>(21),
        DiscreteAuctionOpen = static_cast<std::uint8_t>(119),
        DiscreteAuctionClose = static_cast<std::uint8_t>(121),
        InstrumentHalt = static_cast<std::uint8_t>(122),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static SecurityTradingStatus::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(2): return TradingHalt;
            case static_cast<std::uint8_t>(17): return ReadyToTrade;
            case static_cast<std::uint8_t>(18): return NotAvailableForTrading;
            case static_cast<std::uint8_t>(19): return NotTradedOnThisMarket;
            case static_cast<std::uint8_t>(20): return UnknownOrInvalid;
            case static_cast<std::uint8_t>(21): return PreOpen;
            case static_cast<std::uint8_t>(119): return DiscreteAuctionOpen;
            case static_cast<std::uint8_t>(121): return DiscreteAuctionClose;
            case static_cast<std::uint8_t>(122): return InstrumentHalt;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SecurityTradingStatus [E103]");
    }

    static const char *c_str(const SecurityTradingStatus::Value value)
    {
        switch (value)
        {
            case TradingHalt: return "TradingHalt";
            case ReadyToTrade: return "ReadyToTrade";
            case NotAvailableForTrading: return "NotAvailableForTrading";
            case NotTradedOnThisMarket: return "NotTradedOnThisMarket";
            case UnknownOrInvalid: return "UnknownOrInvalid";
            case PreOpen: return "PreOpen";
            case DiscreteAuctionOpen: return "DiscreteAuctionOpen";
            case DiscreteAuctionClose: return "DiscreteAuctionClose";
            case InstrumentHalt: return "InstrumentHalt";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum SecurityTradingStatus [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator << (
        std::basic_ostream<CharT, Traits>& os, SecurityTradingStatus::Value m)
    {
        return os << SecurityTradingStatus::c_str(m);
    }
};

}

#endif
