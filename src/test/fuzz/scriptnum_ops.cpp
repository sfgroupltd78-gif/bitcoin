// Copyright (c) 2020-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <script/script.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>

#include <cassert>
#include <cstdint>
#include <limits>
#include <vector>

namespace {
bool IsValidAddition(const CScriptNum& lhs, const CScriptNum& rhs)
{
    return rhs == 0 || (rhs > 0 && lhs <= CScriptNum{std::numeric_limits<int64_t>::max()} - rhs) || (rhs < 0 && lhs >= CScriptNum{std::numeric_limits<int64_t>::min()} - rhs);
}

bool IsValidSubtraction(const CScriptNum& lhs, const CScriptNum& rhs)
{
    return rhs == 0 || (rhs > 0 && lhs >= CScriptNum{std::numeric_limits<int64_t>::min()} + rhs) || (rhs < 0 && lhs <= CScriptNum{std::numeric_limits<int64_t>::max()} + rhs);
}
} // namespace

FUZZ_TARGET(scriptnum_ops)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    CScriptNum script_num = ConsumeScriptNum(fuzzed_data_provider);
    LIMITED_WHILE(fuzzed_data_provider.remaining_bytes() > 0, 1000000) {
        CallOneOf(
            fuzzed_data_provider,
            [&] {
                const int64_t i = fuzzed_data_provider.ConsumeIntegral<int64_t>();
                assert((script_num == i) != (script_num != i));
                assert((script_num <= i) != (script_num > i));
                assert((script_num >= i) != (script_num < i));
                // Avoid signed integer overflow:
                // script/script.h:264:93: runtime error: signed integer overflow: -2261405121394637306 + -9223372036854775802 cannot be represented in type 'long'
                if (IsValidAddition(script_num, CScriptNum{i})) {
                    assert((script_num + i) - i == script_num);
                }
                // Avoid signed integer overflow:
                // script/script.h:265:93: runtime error: signed integer overflow: 9223371895120855039 - -9223372036854710486 cannot be represented in type 'long'
                if (IsValidSubtraction(script_num, CScriptNum{i})) {
                    assert((script_num - i) + i == script_num);
                }
            },
            [&] {
                const CScriptNum random_script_num = ConsumeScriptNum(fuzzed_data_provider);
                assert((script_num == random_script_num) != (script_num != random_script_num));
                assert((script_num <= random_script_num) != (script_num > random_script_num));
                assert((script_num >= random_script_num) != (script_num < random_script_num));
                // Avoid signed integer overflow:
                // script/script.h:264:93: runtime error: signed integer overflow: -9223126527765971126 + -9223372036854756825 cannot be represented in type 'long'
                if (IsValidAddition(script_num, random_script_num)) {
                    assert((script_num + random_script_num) - random_script_num == script_num);
                }
                // Avoid signed integer overflow:
                // script/script.h:265:93: runtime error: signed integer overflow: 6052837899185946624 - -9223372036854775808 cannot be represented in type 'long'
                if (IsValidSubtraction(script_num, random_script_num)) {
                    assert((script_num - random_script_num) + random_script_num == script_num);
                }
            },
            [&] {
                const CScriptNum random_script_num = ConsumeScriptNum(fuzzed_data_provider);
                if (!IsValidAddition(script_num, random_script_num)) {
                    // Avoid assertion failure:
                    // ./script/script.h:292: CScriptNum &CScriptNum::operator+=(const int64_t &): Assertion `rhs == 0 || (rhs > 0 && m_value <= std::numeric_limits<int64_t>::max() - rhs) || (rhs < 0 && m_value >= std::numeric_limits<int64_t>::min() - rhs)' failed.
                    return;
                }
                script_num += random_script_num;
            },
            [&] {
                const CScriptNum random_script_num = ConsumeScriptNum(fuzzed_data_provider);
                if (!IsValidSubtraction(script_num, random_script_num)) {
                    // Avoid assertion failure:
                    // ./script/script.h:300: CScriptNum &CScriptNum::operator-=(const int64_t &): Assertion `rhs == 0 || (rhs > 0 && m_value >= std::numeric_limits<int64_t>::min() + rhs) || (rhs < 0 && m_value <= std::numeric_limits<int64_t>::max() + rhs)' failed.
                    return;
                }
                script_num -= random_script_num;
            },
            [&] {
                script_num = script_num & fuzzed_data_provider.ConsumeIntegral<int64_t>();
            },
            [&] {
                script_num = script_num & ConsumeScriptNum(fuzzed_data_provider);
            },
            [&] {
                script_num &= ConsumeScriptNum(fuzzed_data_provider);
            },
            [&] {
                if (script_num == CScriptNum{std::numeric_limits<int64_t>::min()}) {
                    // Avoid assertion failure:
                    // ./script/script.h:279: CScriptNum CScriptNum::operator-() const: Assertion `m_value != std::numeric_limits<int64_t>::min()' failed.
                    return;
                }
                script_num = -script_num;
            },
            [&] {
                script_num = fuzzed_data_provider.ConsumeIntegral<int64_t>();
            },
            [&] {
                const int64_t random_integer = fuzzed_data_provider.ConsumeIntegral<int64_t>();
                if (!IsValidAddition(script_num, CScriptNum{random_integer})) {
                    // Avoid assertion failure:
                    // ./script/script.h:292: CScriptNum &CScriptNum::operator+=(const int64_t &): Assertion `rhs == 0 || (rhs > 0 && m_value <= std::numeric_limits<int64_t>::max() - rhs) || (rhs < 0 && m_value >= std::numeric_limits<int64_t>::min() - rhs)' failed.
                    return;
                }
                script_num += random_integer;
            },
            [&] {
                const int64_t random_integer = fuzzed_data_provider.ConsumeIntegral<int64_t>();
                if (!IsValidSubtraction(script_num, CScriptNum{random_integer})) {
                    // Avoid assertion failure:
                    // ./script/script.h:300: CScriptNum &CScriptNum::operator-=(const int64_t &): Assertion `rhs == 0 || (rhs > 0 && m_value >= std::numeric_limits<int64_t>::min() + rhs) || (rhs < 0 && m_value <= std::numeric_limits<int64_t>::max() + rhs)' failed.
                    return;
                }
                script_num -= random_integer;
            },
            [&] {
                script_num &= fuzzed_data_provider.ConsumeIntegral<int64_t>();
            });
        (void)script_num.getint();
        (void)script_num.getvch();
    }
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