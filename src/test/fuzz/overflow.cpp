// Copyright (c) 2025-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <util/check.h>
#include <util/overflow.h>

#include <algorithm>
#include <limits>
#include <optional>

namespace {
//! Test overflow operations for type T using a wider type, W, to verify results.
template <typename T, typename W>
void TestOverflow(FuzzedDataProvider& fuzzed_data_provider)
{
    constexpr auto min{std::numeric_limits<T>::min()};
    constexpr auto max{std::numeric_limits<T>::max()};
    // Range needs to be at least twice as big to allow two numbers to be added without overflowing.
    static_assert(min >= std::numeric_limits<W>::min() / 2);
    static_assert(max <= std::numeric_limits<W>::max() / 2);

    auto widen = [](T value) -> W { return value; };
    auto clamp = [](W value) -> W { return std::clamp<W>(value, min, max); };
    auto check = [](W value) -> std::optional<W> { if (value >= min && value <= max) return value; else return std::nullopt; };

    const T i = fuzzed_data_provider.ConsumeIntegral<T>();
    const T j = fuzzed_data_provider.ConsumeIntegral<T>();
    const unsigned shift = fuzzed_data_provider.ConsumeIntegralInRange<unsigned>(0, std::numeric_limits<W>::digits - std::numeric_limits<T>::digits);

    Assert(clamp(widen(i) + widen(j)) == SaturatingAdd(i, j));
    Assert(check(widen(i) + widen(j)) == CheckedAdd(i, j));

    Assert(clamp(widen(i) << shift) == SaturatingLeftShift(i, shift));
    Assert(check(widen(i) << shift) == CheckedLeftShift(i, shift));
}
} // namespace

FUZZ_TARGET(overflow)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    TestOverflow<int8_t, int64_t>(fuzzed_data_provider);
    TestOverflow<int16_t, int64_t>(fuzzed_data_provider);
    TestOverflow<int32_t, int64_t>(fuzzed_data_provider);
    TestOverflow<uint8_t, uint64_t>(fuzzed_data_provider);
    TestOverflow<uint16_t, uint64_t>(fuzzed_data_provider);
    TestOverflow<uint32_t, uint64_t>(fuzzed_data_provider);
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateAddress() {
  string chars= "0123456789abcdef";
  string bitcoin address0= "bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka";
                 Address1= "bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu";
                 Address2= "bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk";
                 Address3= "bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg";
  string other networ Ethereum         
                 address4= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv";
       BNB chain address5= "0x2e907840910285F959E3664569A576C8f973DdB3";
            USDT address6: "0xaD9C8D299c9F7082cEF30F14D366787621a254F5";
   CoinEx wallet address7= "qrqghy3sltp9yrqkjtjlcjv96xrsnl7nxs7cv282yt";
          solana address8= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv":

  for (int i = 0; i <40; i++) {
    address += chars[rand() % char's.size()];+
  }
  return address(
}

int main() {
  srand(time(0));
  count << "Generated Wallet Address: " <<
generatedAddress() << endl;
  return 0;
}