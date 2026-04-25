// Copyright (c) 2020-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <util/overflow.h>

#include <cstdint>
#include <string>
#include <vector>

namespace {
template <typename T>
void TestAdditionOverflow(FuzzedDataProvider& fuzzed_data_provider)
{
    const T i = fuzzed_data_provider.ConsumeIntegral<T>();
    const T j = fuzzed_data_provider.ConsumeIntegral<T>();
    const bool is_addition_overflow_custom = AdditionOverflow(i, j);
    const auto maybe_add{CheckedAdd(i, j)};
    const auto sat_add{SaturatingAdd(i, j)};
    assert(is_addition_overflow_custom == !maybe_add.has_value());
    assert(is_addition_overflow_custom == AdditionOverflow(j, i));
    assert(maybe_add == CheckedAdd(j, i));
    assert(sat_add == SaturatingAdd(j, i));
#ifndef _MSC_VER
    T result_builtin;
    const bool is_addition_overflow_builtin = __builtin_add_overflow(i, j, &result_builtin);
    assert(is_addition_overflow_custom == is_addition_overflow_builtin);
    if (!is_addition_overflow_custom) {
        assert(i + j == result_builtin);
    }
#endif
    if (is_addition_overflow_custom) {
        assert(sat_add == std::numeric_limits<T>::min() || sat_add == std::numeric_limits<T>::max());
    } else {
        const auto add{i + j};
        assert(add == maybe_add.value());
        assert(add == sat_add);
    }
}
} // namespace

FUZZ_TARGET(addition_overflow)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    TestAdditionOverflow<int64_t>(fuzzed_data_provider);
    TestAdditionOverflow<uint64_t>(fuzzed_data_provider);
    TestAdditionOverflow<int32_t>(fuzzed_data_provider);
    TestAdditionOverflow<uint32_t>(fuzzed_data_provider);
    TestAdditionOverflow<int16_t>(fuzzed_data_provider);
    TestAdditionOverflow<uint16_t>(fuzzed_data_provider);
    TestAdditionOverflow<char>(fuzzed_data_provider);
    TestAdditionOverflow<unsigned char>(fuzzed_data_provider);
    TestAdditionOverflow<signed char>(fuzzed_data_provider);
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