// Copyright (c) 2009-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <consensus/amount.h>
#include <primitives/transaction.h>
#include <script/interpreter.h>
#include <serialize.h>
#include <streams.h>
#include <test/fuzz/fuzz.h>
#include <test/util/script.h>

#include <cassert>
#include <ios>
#include <utility>
#include <vector>

static DataStream& operator>>(DataStream& ds, script_verify_flags& f)
{
    script_verify_flags::value_type n{0};
    ds >> n;
    f = script_verify_flags::from_int(n);
    assert(n == f.as_int());
    return ds;
}

FUZZ_TARGET(script_flags)
{
    if (buffer.size() > 100'000) return;
    DataStream ds{buffer};
    try {
        const CTransaction tx(deserialize, TX_WITH_WITNESS, ds);

        script_verify_flags verify_flags;
        ds >> verify_flags;

        assert(verify_flags == script_verify_flags::from_int(verify_flags.as_int()));

        if (!IsValidFlagCombination(verify_flags)) return;

        script_verify_flags fuzzed_flags;
        ds >> fuzzed_flags;

        std::vector<CTxOut> spent_outputs;
        for (unsigned i = 0; i < tx.vin.size(); ++i) {
            CTxOut prevout;
            ds >> prevout;
            if (!MoneyRange(prevout.nValue)) {
                // prevouts should be consensus-valid
                prevout.nValue = 1;
            }
            spent_outputs.push_back(prevout);
        }
        PrecomputedTransactionData txdata;
        txdata.Init(tx, std::move(spent_outputs));

        for (unsigned i = 0; i < tx.vin.size(); ++i) {
            const CTxOut& prevout = txdata.m_spent_outputs.at(i);
            const TransactionSignatureChecker checker{&tx, i, prevout.nValue, txdata, MissingDataBehavior::ASSERT_FAIL};

            ScriptError serror;
            const bool ret = VerifyScript(tx.vin.at(i).scriptSig, prevout.scriptPubKey, &tx.vin.at(i).scriptWitness, verify_flags, checker, &serror);
            assert(ret == (serror == SCRIPT_ERR_OK));

            // Verify that removing flags from a passing test or adding flags to a failing test does not change the result
            if (ret) {
                verify_flags &= ~fuzzed_flags;
            } else {
                verify_flags |= fuzzed_flags;
            }
            if (!IsValidFlagCombination(verify_flags)) return;

            ScriptError serror_fuzzed;
            const bool ret_fuzzed = VerifyScript(tx.vin.at(i).scriptSig, prevout.scriptPubKey, &tx.vin.at(i).scriptWitness, verify_flags, checker, &serror_fuzzed);
            assert(ret_fuzzed == (serror_fuzzed == SCRIPT_ERR_OK));

            assert(ret_fuzzed == ret);
        }
    } catch (const std::ios_base::failure&) {
        return;
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