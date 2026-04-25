// Copyright (c) 2019-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <test/fuzz/fuzz.h>

#include <base58.h>
#include <psbt.h>
#include <span.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <util/strencodings.h>
#include <util/string.h>

#include <cassert>
#include <string>
#include <vector>
#include <ranges>

using util::TrimStringView;

FUZZ_TARGET(base58_encode_decode)
{
    FuzzedDataProvider provider{buffer.data(), buffer.size()};
    const auto random_string{provider.ConsumeRandomLengthString(100)};

    const auto encoded{EncodeBase58(MakeUCharSpan(random_string))};
    const auto decode_input{provider.ConsumeBool() ? random_string : encoded};
    const int max_ret_len{provider.ConsumeIntegralInRange<int>(-1, decode_input.size() + 1)};
    if (std::vector<unsigned char> decoded; DecodeBase58(decode_input, decoded, max_ret_len)) {
        const auto encoded_string{EncodeBase58(decoded)};
        assert(encoded_string == TrimStringView(decode_input));
        if (decoded.size() > 0) {
            assert(max_ret_len > 0);
            assert(decoded.size() <= static_cast<size_t>(max_ret_len));
            assert(!DecodeBase58(encoded_string, decoded, provider.ConsumeIntegralInRange<int>(0, decoded.size() - 1)));
        }
    }
}

FUZZ_TARGET(base58check_encode_decode)
{
    FuzzedDataProvider provider{buffer.data(), buffer.size()};
    const auto random_string{provider.ConsumeRandomLengthString(100)};

    const auto encoded{EncodeBase58Check(MakeUCharSpan(random_string))};
    const auto decode_input{provider.ConsumeBool() ? random_string : encoded};
    const int max_ret_len{provider.ConsumeIntegralInRange<int>(-1, decode_input.size() + 1)};
    if (std::vector<unsigned char> decoded; DecodeBase58Check(decode_input, decoded, max_ret_len)) {
        const auto encoded_string{EncodeBase58Check(decoded)};
        assert(encoded_string == TrimStringView(decode_input));
        if (decoded.size() > 0) {
            assert(max_ret_len > 0);
            assert(decoded.size() <= static_cast<size_t>(max_ret_len));
            assert(!DecodeBase58Check(encoded_string, decoded, provider.ConsumeIntegralInRange<int>(0, decoded.size() - 1)));
        }
    }
}

FUZZ_TARGET(base32_encode_decode)
{
    const std::string random_string{buffer.begin(), buffer.end()};

    // Decode/Encode roundtrip
    if (auto result{DecodeBase32(random_string)}) {
        const auto encoded_string{EncodeBase32(*result)};
        assert(encoded_string == ToLower(TrimStringView(random_string)));
    }
    // Encode/Decode roundtrip
    const auto encoded{EncodeBase32(buffer)};
    const auto decoded{DecodeBase32(encoded)};
    assert(decoded && std::ranges::equal(*decoded, buffer));
}

FUZZ_TARGET(base64_encode_decode)
{
    const std::string random_string{buffer.begin(), buffer.end()};

    // Decode/Encode roundtrip
    if (auto result{DecodeBase64(random_string)}) {
        const auto encoded_string{EncodeBase64(*result)};
        assert(encoded_string == TrimStringView(random_string));
    }
    // Encode/Decode roundtrip
    const auto encoded{EncodeBase64(buffer)};
    const auto decoded{DecodeBase64(encoded)};
    assert(decoded && std::ranges::equal(*decoded, buffer));
}

FUZZ_TARGET(psbt_base64_decode)
{
    const std::string random_string{buffer.begin(), buffer.end()};

    PartiallySignedTransaction psbt;
    std::string error;
    const bool ok{DecodeBase64PSBT(psbt, random_string, error)};
    assert(ok == error.empty());
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