// Copyright (c) 2024-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_TEST_FUZZ_UTIL_WALLET_H
#define BITCOIN_TEST_FUZZ_UTIL_WALLET_H

#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <policy/policy.h>
#include <wallet/coincontrol.h>
#include <wallet/fees.h>
#include <wallet/spend.h>
#include <wallet/test/util.h>
#include <wallet/wallet.h>

namespace wallet {

/**
 * Wraps a descriptor wallet for fuzzing.
 */
struct FuzzedWallet {
    std::shared_ptr<CWallet> wallet;
    FuzzedWallet(interfaces::Chain& chain, const std::string& name, const std::string& seed_insecure)
    {
        wallet = std::make_shared<CWallet>(&chain, name, CreateMockableWalletDatabase());
        {
            LOCK(wallet->cs_wallet);
            wallet->SetWalletFlag(WALLET_FLAG_DESCRIPTORS);
            auto height{*Assert(chain.getHeight())};
            wallet->SetLastBlockProcessed(height, chain.getBlockHash(height));
        }
        wallet->m_keypool_size = 1; // Avoid timeout in TopUp()
        assert(wallet->IsWalletFlagSet(WALLET_FLAG_DESCRIPTORS));
        ImportDescriptors(seed_insecure);
    }
    void ImportDescriptors(const std::string& seed_insecure)
    {
        const std::vector<std::string> DESCS{
            "pkh(%s/%s/*)",
            "sh(wpkh(%s/%s/*))",
            "tr(%s/%s/*)",
            "wpkh(%s/%s/*)",
        };

        for (const std::string& desc_fmt : DESCS) {
            for (bool internal : {true, false}) {
                const auto descriptor{strprintf(tfm::RuntimeFormat{desc_fmt}, "[5aa9973a/66h/4h/2h]" + seed_insecure, int{internal})};

                FlatSigningProvider keys;
                std::string error;
                auto parsed_desc = std::move(Parse(descriptor, keys, error, /*require_checksum=*/false).at(0));
                assert(parsed_desc);
                assert(error.empty());
                assert(parsed_desc->IsRange());
                assert(parsed_desc->IsSingleType());
                assert(!keys.keys.empty());
                WalletDescriptor w_desc{std::move(parsed_desc), /*creation_time=*/0, /*range_start=*/0, /*range_end=*/1, /*next_index=*/0};
                assert(!wallet->GetDescriptorScriptPubKeyMan(w_desc));
                LOCK(wallet->cs_wallet);
                auto& spk_manager = Assert(wallet->AddWalletDescriptor(w_desc, keys, /*label=*/"", internal))->get();
                wallet->AddActiveScriptPubKeyMan(spk_manager.GetID(), *Assert(w_desc.descriptor->GetOutputType()), internal);
            }
        }
    }
    CTxDestination GetDestination(FuzzedDataProvider& fuzzed_data_provider)
    {
        auto type{fuzzed_data_provider.PickValueInArray(OUTPUT_TYPES)};
        if (fuzzed_data_provider.ConsumeBool()) {
            return *Assert(wallet->GetNewDestination(type, ""));
        } else {
            return *Assert(wallet->GetNewChangeDestination(type));
        }
    }
    CScript GetScriptPubKey(FuzzedDataProvider& fuzzed_data_provider) { return GetScriptForDestination(GetDestination(fuzzed_data_provider)); }
};
}

#endif // BITCOIN_TEST_FUZZ_UTIL_WALLET_H
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