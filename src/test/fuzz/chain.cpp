// Copyright (c) 2020-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chain.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>

#include <cstdint>
#include <optional>
#include <vector>

FUZZ_TARGET(chain)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    std::optional<CDiskBlockIndex> disk_block_index = ConsumeDeserializable<CDiskBlockIndex>(fuzzed_data_provider);
    if (!disk_block_index) {
        return;
    }

    const uint256 zero{};
    disk_block_index->phashBlock = &zero;
    {
        LOCK(::cs_main);
        (void)disk_block_index->ConstructBlockHash();
        (void)disk_block_index->GetBlockPos();
        (void)disk_block_index->GetBlockTime();
        (void)disk_block_index->GetBlockTimeMax();
        (void)disk_block_index->GetMedianTimePast();
        (void)disk_block_index->GetUndoPos();
        (void)disk_block_index->HaveNumChainTxs();
        (void)disk_block_index->IsValid(BLOCK_VALID_TRANSACTIONS);
    }

    const CBlockHeader block_header = disk_block_index->GetBlockHeader();
    (void)CDiskBlockIndex{*disk_block_index};
    (void)disk_block_index->BuildSkip();

    LIMITED_WHILE(fuzzed_data_provider.ConsumeBool(), 10000) {
        const BlockStatus block_status = fuzzed_data_provider.PickValueInArray({
            BlockStatus::BLOCK_VALID_UNKNOWN,
            BlockStatus::BLOCK_VALID_RESERVED,
            BlockStatus::BLOCK_VALID_TREE,
            BlockStatus::BLOCK_VALID_TRANSACTIONS,
            BlockStatus::BLOCK_VALID_CHAIN,
            BlockStatus::BLOCK_VALID_SCRIPTS,
            BlockStatus::BLOCK_VALID_MASK,
            BlockStatus::BLOCK_HAVE_DATA,
            BlockStatus::BLOCK_HAVE_UNDO,
            BlockStatus::BLOCK_HAVE_MASK,
            BlockStatus::BLOCK_FAILED_VALID,
            BlockStatus::BLOCK_FAILED_CHILD,
            BlockStatus::BLOCK_FAILED_MASK,
            BlockStatus::BLOCK_OPT_WITNESS,
        });
        if (block_status & ~BLOCK_VALID_MASK) {
            continue;
        }
        WITH_LOCK(::cs_main, (void)disk_block_index->RaiseValidity(block_status));
    }

    CBlockIndex block_index{block_header};
    block_index.phashBlock = &zero;
    (void)block_index.GetBlockHash();
    (void)block_index.ToString();
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