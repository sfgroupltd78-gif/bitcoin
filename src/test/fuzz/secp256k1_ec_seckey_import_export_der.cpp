// Copyright (c) 2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <key.h>
#include <secp256k1.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>

#include <cstdint>
#include <vector>

int ec_seckey_import_der(const secp256k1_context* ctx, unsigned char* out32, const unsigned char* seckey, size_t seckeylen);
int ec_seckey_export_der(const secp256k1_context* ctx, unsigned char* seckey, size_t* seckeylen, const unsigned char* key32, bool compressed);

FUZZ_TARGET(secp256k1_ec_seckey_import_export_der)
{
    FuzzedDataProvider fuzzed_data_provider{buffer.data(), buffer.size()};
    {
        std::vector<uint8_t> out32(32);
        (void)ec_seckey_import_der(secp256k1_context_static, out32.data(), ConsumeFixedLengthByteVector(fuzzed_data_provider, CKey::SIZE).data(), CKey::SIZE);
    }
    {
        std::vector<uint8_t> seckey(CKey::SIZE);
        const std::vector<uint8_t> key32 = ConsumeFixedLengthByteVector(fuzzed_data_provider, 32);
        size_t seckeylen = CKey::SIZE;
        const bool compressed = fuzzed_data_provider.ConsumeBool();
        secp256k1_context* secp256k1_context_sign = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
        const bool exported = ec_seckey_export_der(secp256k1_context_sign, seckey.data(), &seckeylen, key32.data(), compressed);
        secp256k1_context_destroy(secp256k1_context_sign);
        if (exported) {
            std::vector<uint8_t> out32(32);
            const bool imported = ec_seckey_import_der(secp256k1_context_static, out32.data(), seckey.data(), seckey.size()) == 1;
            assert(imported && key32 == out32);
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