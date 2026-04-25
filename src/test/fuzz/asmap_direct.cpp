// Copyright (c) 2020-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <netaddress.h>
#include <util/asmap.h>
#include <test/fuzz/fuzz.h>

#include <cstdint>
#include <optional>
#include <vector>

#include <cassert>

FUZZ_TARGET(asmap_direct)
{
    // Encoding: [asmap using 1 bit / byte] 0xFF [addr using 1 bit / byte]
    std::optional<size_t> sep_pos_opt;
    for (size_t pos = 0; pos < buffer.size(); ++pos) {
        uint8_t x = buffer[pos];
        if ((x & 0xFE) == 0) continue;
        if (x == 0xFF) {
            if (sep_pos_opt) return;
            sep_pos_opt = pos;
        } else {
            return;
        }
    }
    if (!sep_pos_opt) return; // Needs exactly 1 separator
    const size_t sep_pos{sep_pos_opt.value()};
    if (buffer.size() - sep_pos - 1 > 128) return; // At most 128 bits in IP address

    // Checks on asmap
    std::vector<bool> asmap(buffer.begin(), buffer.begin() + sep_pos);
    if (SanityCheckASMap(asmap, buffer.size() - 1 - sep_pos)) {
        // Verify that for valid asmaps, no prefix (except up to 7 zero padding bits) is valid.
        std::vector<bool> asmap_prefix = asmap;
        while (!asmap_prefix.empty() && asmap_prefix.size() + 7 > asmap.size() && asmap_prefix.back() == false) {
            asmap_prefix.pop_back();
        }
        while (!asmap_prefix.empty()) {
            asmap_prefix.pop_back();
            assert(!SanityCheckASMap(asmap_prefix, buffer.size() - 1 - sep_pos));
        }
        // No address input should trigger assertions in interpreter
        std::vector<bool> addr(buffer.begin() + sep_pos + 1, buffer.end());
        (void)Interpret(asmap, addr);
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