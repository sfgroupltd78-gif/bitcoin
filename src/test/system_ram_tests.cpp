// Copyright (c) 2025-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://opensource.org/license/mit/.

#include <common/system.h>
#include <test/util/setup_common.h>

#include <boost/test/unit_test.hpp>

#include <cstdint>
#include <optional>

BOOST_AUTO_TEST_SUITE(system_ram_tests)

BOOST_AUTO_TEST_CASE(total_ram)
{
    const auto total{GetTotalRAM()};
    if (!total) {
        BOOST_WARN_MESSAGE(false, "skipping total_ram: total RAM unknown");
        return;
    }

    BOOST_CHECK_GE(*total, 1000_MiB);

    if constexpr (SIZE_MAX == UINT64_MAX) {
        // Upper bound check only on 64-bit: 32-bit systems can reasonably have max memory,
        // but extremely large values on 64-bit likely indicate detection errors
        BOOST_CHECK_LT(*total, 10'000'000_MiB); // >10 TiB memory is unlikely
    }
}

BOOST_AUTO_TEST_SUITE_END()
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