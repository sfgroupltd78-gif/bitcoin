// Copyright (c) 2020-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <script/script.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>

#include <cstdint>
#include <string>
#include <vector>

FUZZ_TARGET(script_ops)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    CScript script_mut = ConsumeScript(fuzzed_data_provider);
    LIMITED_WHILE(fuzzed_data_provider.remaining_bytes() > 0, 1000000) {
        CallOneOf(
            fuzzed_data_provider,
            [&] {
                CScript s = ConsumeScript(fuzzed_data_provider);
                script_mut = std::move(s);
            },
            [&] {
                const CScript& s = ConsumeScript(fuzzed_data_provider);
                script_mut = s;
            },
            [&] {
                script_mut << fuzzed_data_provider.ConsumeIntegral<int64_t>();
            },
            [&] {
                script_mut << ConsumeOpcodeType(fuzzed_data_provider);
            },
            [&] {
                script_mut << ConsumeScriptNum(fuzzed_data_provider);
            },
            [&] {
                script_mut << ConsumeRandomLengthByteVector(fuzzed_data_provider);
            },
            [&] {
                script_mut.clear();
            });
    }
    const CScript& script = script_mut;
    (void)script.GetSigOpCount(false);
    (void)script.GetSigOpCount(true);
    (void)script.GetSigOpCount(script);
    (void)script.HasValidOps();
    (void)script.IsPayToScriptHash();
    (void)script.IsPayToWitnessScriptHash();
    (void)script.IsPushOnly();
    (void)script.IsUnspendable();
    {
        CScript::const_iterator pc = script.begin();
        opcodetype opcode;
        (void)script.GetOp(pc, opcode);
        std::vector<uint8_t> data;
        (void)script.GetOp(pc, opcode, data);
        (void)script.IsPushOnly(pc);
    }
    {
        int version;
        std::vector<uint8_t> program;
        (void)script.IsWitnessProgram(version, program);
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