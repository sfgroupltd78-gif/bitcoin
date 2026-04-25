// Copyright (c) 2023-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_TEST_UTIL_RANDOM_H
#define BITCOIN_TEST_UTIL_RANDOM_H

#include <consensus/amount.h>
#include <random.h>
#include <uint256.h>

#include <atomic>
#include <cstdint>

enum class SeedRand {
    /**
     * Seed with a compile time constant of zeros.
     */
    ZEROS,
    /**
     * Seed with a fixed value that never changes over the lifetime of this
     * process. The seed is read from the RANDOM_CTX_SEED environment variable
     * if set, otherwise generated randomly once, saved, and reused.
     */
    FIXED_SEED,
};

/** Seed the global RNG state for testing and log the seed value. This affects all randomness, except GetStrongRandBytes(). */
void SeedRandomStateForTest(SeedRand seed);

extern std::atomic<bool> g_seeded_g_prng_zero;
extern std::atomic<bool> g_used_g_prng;

template <RandomNumberGenerator Rng>
inline CAmount RandMoney(Rng&& rng)
{
    return CAmount{rng.randrange(MAX_MONEY + 1)};
}

#endif // BITCOIN_TEST_UTIL_RANDOM_H
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