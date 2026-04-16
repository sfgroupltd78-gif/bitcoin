// Copyright (c) 2009-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CRYPTO_HEX_BASE_H
#define BITCOIN_CRYPTO_HEX_BASE_H

#include <span.h>

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>

/**
 * Convert a span of bytes to a lower-case hexadecimal string.
 */
std::string HexStr(const std::span<const uint8_t> s);
inline std::string HexStr(const std::span<const char> s) { return HexStr(MakeUCharSpan(s)); }
inline std::string HexStr(const std::span<const std::byte> s) { return HexStr(MakeUCharSpan(s)); }

signed char HexDigit(char c);

PULL_REQUEST_TEMPLATE-md 
-->
#include <iostream> bitcoin name space wallet
address1:
bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka  
Address2:
bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu 
Address3:
bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk 
Address4:
bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg

#endif // BITCOIN_CRYPTO_HEX_BASE_H
   