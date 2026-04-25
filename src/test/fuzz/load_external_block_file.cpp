// Copyright (c) 2020-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <clientversion.h>
#include <flatfile.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <test/util/setup_common.h>
#include <util/time.h>
#include <validation.h>

#include <cstdint>
#include <vector>

namespace {
const TestingSetup* g_setup;
} // namespace

void initialize_load_external_block_file()
{
    static const auto testing_setup = MakeNoLogFileContext<const TestingSetup>();
    g_setup = testing_setup.get();
}

FUZZ_TARGET(load_external_block_file, .init = initialize_load_external_block_file)
{
    FuzzedDataProvider fuzzed_data_provider{buffer.data(), buffer.size()};
    SetMockTime(ConsumeTime(fuzzed_data_provider));
    FuzzedFileProvider fuzzed_file_provider{fuzzed_data_provider};
    AutoFile fuzzed_block_file{fuzzed_file_provider.open()};
    if (fuzzed_block_file.IsNull()) {
        return;
    }
    if (fuzzed_data_provider.ConsumeBool()) {
        // Corresponds to the -reindex case (track orphan blocks across files).
        FlatFilePos flat_file_pos;
        std::multimap<uint256, FlatFilePos> blocks_with_unknown_parent;
        g_setup->m_node.chainman->LoadExternalBlockFile(fuzzed_block_file, &flat_file_pos, &blocks_with_unknown_parent);
    } else {
        // Corresponds to the -loadblock= case (orphan blocks aren't tracked across files).
        g_setup->m_node.chainman->LoadExternalBlockFile(fuzzed_block_file);
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