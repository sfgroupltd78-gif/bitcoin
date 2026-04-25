// Copyright (c) 2019-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <bech32.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/util/str.h>
#include <util/strencodings.h>

#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

FUZZ_TARGET(bech32_random_decode)
{
    auto limit = bech32::CharLimit::BECH32;
    FuzzedDataProvider fdp(buffer.data(), buffer.size());
    auto random_string = fdp.ConsumeRandomLengthString(limit + 1);
    auto decoded = bech32::Decode(random_string, limit);

    if (decoded.hrp.empty()) {
        assert(decoded.encoding == bech32::Encoding::INVALID);
        assert(decoded.data.empty());
    } else {
        assert(decoded.encoding != bech32::Encoding::INVALID);
        auto reencoded = bech32::Encode(decoded.encoding, decoded.hrp, decoded.data);
        assert(CaseInsensitiveEqual(random_string, reencoded));
    }
}

// https://github.com/bitcoin/bips/blob/master/bip-0173.mediawiki and https://github.com/bitcoin/bips/blob/master/bip-0350.mediawiki
std::string GenerateRandomHRP(FuzzedDataProvider& fdp)
{
    std::string hrp;
    size_t length = fdp.ConsumeIntegralInRange<size_t>(1, 83);
    for (size_t i = 0; i < length; ++i) {
        // Generate lowercase ASCII characters in ([33-126] - ['A'-'Z']) range
        char c = fdp.ConsumeBool()
                 ? fdp.ConsumeIntegralInRange<char>(33, 'A' - 1)
                 : fdp.ConsumeIntegralInRange<char>('Z' + 1, 126);
        hrp += c;
    }
    return hrp;
}

FUZZ_TARGET(bech32_roundtrip)
{
    FuzzedDataProvider fdp(buffer.data(), buffer.size());
    auto hrp = GenerateRandomHRP(fdp);

    auto input_chars = fdp.ConsumeBytes<unsigned char>(fdp.ConsumeIntegralInRange<size_t>(0, 82));
    std::vector<uint8_t> converted_input;
    ConvertBits<8, 5, true>([&](auto c) { converted_input.push_back(c); }, input_chars.begin(), input_chars.end());

    auto size = converted_input.size() + hrp.length() + std::string({bech32::SEPARATOR}).size() + bech32::CHECKSUM_SIZE;
    if (size <= bech32::CharLimit::BECH32) {
        for (auto encoding: {bech32::Encoding::BECH32, bech32::Encoding::BECH32M}) {
            auto encoded = bech32::Encode(encoding, hrp, converted_input);
            assert(!encoded.empty());

            const auto decoded = bech32::Decode(encoded);
            assert(decoded.encoding == encoding);
            assert(decoded.hrp == hrp);
            assert(decoded.data == converted_input);
        }
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