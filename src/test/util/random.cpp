// Copyright (c) 2023-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <test/util/random.h>

#include <logging.h>
#include <random.h>
#include <uint256.h>
#include <util/check.h>

#include <cstdlib>
#include <iostream>

std::atomic<bool> g_seeded_g_prng_zero{false};

extern void MakeRandDeterministicDANGEROUS(const uint256& seed) noexcept;

void SeedRandomStateForTest(SeedRand seedtype)
{
    constexpr auto RANDOM_CTX_SEED{"RANDOM_CTX_SEED"};

    // Do this once, on the first call, regardless of seedtype, because once
    // MakeRandDeterministicDANGEROUS is called, the output of GetRandHash is
    // no longer truly random. It should be enough to get the seed once for the
    // process.
    static const auto g_ctx_seed = []() -> std::optional<uint256> {
        if (EnableFuzzDeterminism()) return {};
        // If RANDOM_CTX_SEED is set, use that as seed.
        if (const char* num{std::getenv(RANDOM_CTX_SEED)}) {
            if (auto num_parsed{uint256::FromUserHex(num)}) {
                return *num_parsed;
            } else {
                std::cerr << RANDOM_CTX_SEED << " must consist of up to " << uint256::size() * 2 << " hex digits (\"0x\" prefix allowed), it was set to: '" << num << "'.\n";
                std::abort();
            }
        }
        // Otherwise use a (truly) random value.
        return GetRandHash();
    }();

    g_seeded_g_prng_zero = seedtype == SeedRand::ZEROS;
    if (EnableFuzzDeterminism()) {
        Assert(g_seeded_g_prng_zero); // Only SeedRandomStateForTest(SeedRand::ZEROS) is allowed in fuzz tests
        Assert(!g_used_g_prng);       // The global PRNG must not have been used before SeedRandomStateForTest(SeedRand::ZEROS)
    }
    const uint256& seed{seedtype == SeedRand::FIXED_SEED ? g_ctx_seed.value() : uint256::ZERO};
    LogInfo("Setting random seed for current tests to %s=%s\n", RANDOM_CTX_SEED, seed.GetHex());
    MakeRandDeterministicDANGEROUS(seed);
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