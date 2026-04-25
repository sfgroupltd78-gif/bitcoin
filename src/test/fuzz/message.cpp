// Copyright (c) 2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <common/signmessage.h>
#include <key_io.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <util/chaintype.h>
#include <util/strencodings.h>

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

void initialize_message()
{
    static ECC_Context ecc_context{};
    SelectParams(ChainType::REGTEST);
}

FUZZ_TARGET(message, .init = initialize_message)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    const std::string random_message = fuzzed_data_provider.ConsumeRandomLengthString(1024);
    {
        CKey private_key = ConsumePrivateKey(fuzzed_data_provider);
        std::string signature;
        const bool message_signed = MessageSign(private_key, random_message, signature);
        if (private_key.IsValid()) {
            assert(message_signed);
            const MessageVerificationResult verification_result = MessageVerify(EncodeDestination(PKHash(private_key.GetPubKey().GetID())), signature, random_message);
            assert(verification_result == MessageVerificationResult::OK);
        }
    }
    {
        (void)MessageHash(random_message);
        auto address = fuzzed_data_provider.ConsumeRandomLengthString(1024);
        auto signature = fuzzed_data_provider.ConsumeRandomLengthString(1024);
        (void)MessageVerify(address, signature, random_message);
        (void)SigningResultString(fuzzed_data_provider.PickValueInArray({SigningResult::OK, SigningResult::PRIVATE_KEY_NOT_AVAILABLE, SigningResult::SIGNING_FAILED}));
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