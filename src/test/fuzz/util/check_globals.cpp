// Copyright (c) 2024-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <test/fuzz/util/check_globals.h>

#include <test/util/random.h>
#include <util/time.h>

#include <iostream>
#include <memory>
#include <optional>
#include <string>

struct CheckGlobalsImpl {
    CheckGlobalsImpl()
    {
        g_used_g_prng = false;
        g_seeded_g_prng_zero = false;
        g_used_system_time = false;
        SetMockTime(0s);
    }
    ~CheckGlobalsImpl()
    {
        if (g_used_g_prng && !g_seeded_g_prng_zero) {
            std::cerr << "\n\n"
                         "The current fuzz target used the global random state.\n\n"

                         "This is acceptable, but requires the fuzz target to call \n"
                         "SeedRandomStateForTest(SeedRand::ZEROS) in the first line \n"
                         "of the FUZZ_TARGET function.\n\n"

                         "An alternative solution would be to avoid any use of globals.\n\n"

                         "Without a solution, fuzz instability and non-determinism can lead \n"
                         "to non-reproducible bugs or inefficient fuzzing.\n\n"
                      << std::endl;
            std::abort(); // Abort, because AFL may try to recover from a std::exit
        }

        if (g_used_system_time) {
            std::cerr << "\n\n"
                         "The current fuzz target accessed system time.\n\n"

                         "This is acceptable, but requires the fuzz target to call \n"
                         "SetMockTime() at the beginning of processing the fuzz input.\n\n"

                         "Without setting mock time, time-dependent behavior can lead \n"
                         "to non-reproducible bugs or inefficient fuzzing.\n\n"
                      << std::endl;
            std::abort();
        }
    }
};

CheckGlobals::CheckGlobals() : m_impl(std::make_unique<CheckGlobalsImpl>()) {}
CheckGlobals::~CheckGlobals() = default;
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