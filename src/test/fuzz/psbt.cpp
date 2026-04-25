// Copyright (c) 2019-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <node/psbt.h>
#include <psbt.h>
#include <pubkey.h>
#include <script/script.h>
#include <streams.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/util/random.h>
#include <util/check.h>

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

using node::AnalyzePSBT;
using node::PSBTAnalysis;
using node::PSBTInputAnalysis;

FUZZ_TARGET(psbt)
{
    SeedRandomStateForTest(SeedRand::ZEROS);
    FuzzedDataProvider fuzzed_data_provider{buffer.data(), buffer.size()};
    PartiallySignedTransaction psbt_mut;
    std::string error;
    auto str = fuzzed_data_provider.ConsumeRandomLengthString();
    if (!DecodeRawPSBT(psbt_mut, MakeByteSpan(str), error)) {
        return;
    }
    const PartiallySignedTransaction psbt = psbt_mut;

    const PSBTAnalysis analysis = AnalyzePSBT(psbt);
    (void)PSBTRoleName(analysis.next);
    for (const PSBTInputAnalysis& input_analysis : analysis.inputs) {
        (void)PSBTRoleName(input_analysis.next);
    }

    (void)psbt.IsNull();

    std::optional<CMutableTransaction> tx = psbt.tx;
    if (tx) {
        const CMutableTransaction& mtx = *tx;
        const PartiallySignedTransaction psbt_from_tx{mtx};
    }

    for (const PSBTInput& input : psbt.inputs) {
        (void)PSBTInputSigned(input);
        (void)input.IsNull();
    }
    (void)CountPSBTUnsignedInputs(psbt);

    for (const PSBTOutput& output : psbt.outputs) {
        (void)output.IsNull();
    }

    for (size_t i = 0; i < psbt.tx->vin.size(); ++i) {
        CTxOut tx_out;
        if (psbt.GetInputUTXO(tx_out, i)) {
            (void)tx_out.IsNull();
            (void)tx_out.ToString();
        }
    }

    psbt_mut = psbt;
    (void)FinalizePSBT(psbt_mut);

    psbt_mut = psbt;
    CMutableTransaction result;
    if (FinalizeAndExtractPSBT(psbt_mut, result)) {
        const PartiallySignedTransaction psbt_from_tx{result};
    }

    PartiallySignedTransaction psbt_merge;
    str = fuzzed_data_provider.ConsumeRandomLengthString();
    if (!DecodeRawPSBT(psbt_merge, MakeByteSpan(str), error)) {
        psbt_merge = psbt;
    }
    psbt_mut = psbt;
    (void)psbt_mut.Merge(psbt_merge);
    psbt_mut = psbt;
    (void)CombinePSBTs(psbt_mut, {psbt_mut, psbt_merge});
    psbt_mut = psbt;
    for (unsigned int i = 0; i < psbt_merge.tx->vin.size(); ++i) {
        (void)psbt_mut.AddInput(psbt_merge.tx->vin[i], psbt_merge.inputs[i]);
    }
    for (unsigned int i = 0; i < psbt_merge.tx->vout.size(); ++i) {
        Assert(psbt_mut.AddOutput(psbt_merge.tx->vout[i], psbt_merge.outputs[i]));
    }
    psbt_mut.unknown.insert(psbt_merge.unknown.begin(), psbt_merge.unknown.end());
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