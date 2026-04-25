// Copyright (c) 2020-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <cuckoocache.h>
#include <script/sigcache.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <test/util/setup_common.h>

#include <cstdint>
#include <string>
#include <vector>

namespace {
FuzzedDataProvider* fuzzed_data_provider_ptr = nullptr;

struct RandomHasher {
    template <uint8_t>
    uint32_t operator()(const bool& /* unused */) const
    {
        assert(fuzzed_data_provider_ptr != nullptr);
        return fuzzed_data_provider_ptr->ConsumeIntegral<uint32_t>();
    }
};
} // namespace

FUZZ_TARGET(cuckoocache)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    fuzzed_data_provider_ptr = &fuzzed_data_provider;
    CuckooCache::cache<int, RandomHasher> cuckoo_cache{};
    if (fuzzed_data_provider.ConsumeBool()) {
        const size_t megabytes = fuzzed_data_provider.ConsumeIntegralInRange<size_t>(0, 16);
        cuckoo_cache.setup_bytes(megabytes << 20);
    } else {
        cuckoo_cache.setup(fuzzed_data_provider.ConsumeIntegralInRange<uint32_t>(0, 4096));
    }
    LIMITED_WHILE(fuzzed_data_provider.ConsumeBool(), 10000) {
        if (fuzzed_data_provider.ConsumeBool()) {
            cuckoo_cache.insert(fuzzed_data_provider.ConsumeBool());
        } else {
            auto e = fuzzed_data_provider.ConsumeBool();
            auto erase = fuzzed_data_provider.ConsumeBool();
            cuckoo_cache.contains(e, erase);
        }
    }
    fuzzed_data_provider_ptr = nullptr;
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