// Copyright (c) 2019-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_TEST_UTIL_TRANSACTION_UTILS_H
#define BITCOIN_TEST_UTIL_TRANSACTION_UTILS_H

#include <primitives/transaction.h>
#include <script/sign.h>

#include <array>

class FillableSigningProvider;
class CCoinsViewCache;

// create crediting transaction
// [1 coinbase input => 1 output with given scriptPubkey and value]
CMutableTransaction BuildCreditingTransaction(const CScript& scriptPubKey, int nValue = 0);

// create spending transaction
// [1 input with referenced transaction outpoint, scriptSig, scriptWitness =>
//  1 output with empty scriptPubKey, full value of referenced transaction]
CMutableTransaction BuildSpendingTransaction(const CScript& scriptSig, const CScriptWitness& scriptWitness, const CTransaction& txCredit);

// Helper: create two dummy transactions, each with two outputs.
// The first has nValues[0] and nValues[1] outputs paid to a TxoutType::PUBKEY,
// the second nValues[2] and nValues[3] outputs paid to a TxoutType::PUBKEYHASH.
std::vector<CMutableTransaction> SetupDummyInputs(FillableSigningProvider& keystoreRet, CCoinsViewCache& coinsRet, const std::array<CAmount,4>& nValues);

// bulk transaction to reach a certain target weight,
// by appending a single output with padded output script
void BulkTransaction(CMutableTransaction& tx, int32_t target_weight);

/**
 * Produce a satisfying script (scriptSig or witness).
 *
 * @param provider   Utility containing the information necessary to solve a script.
 * @param fromPubKey The script to produce a satisfaction for.
 * @param txTo       The spending transaction.
 * @param nIn        The index of the input in `txTo` referring the output being spent.
 * @param amount     The value of the output being spent.
 * @param nHashType  Signature hash type.
 * @param sig_data   Additional data provided to solve a script. Filled with the resulting satisfying
 *                   script and whether the satisfaction is complete.
 *
 * @return           True if the produced script is entirely satisfying `fromPubKey`.
 **/
bool SignSignature(const SigningProvider &provider, const CScript& fromPubKey, CMutableTransaction& txTo,
                   unsigned int nIn, const CAmount& amount, int nHashType, SignatureData& sig_data);
bool SignSignature(const SigningProvider &provider, const CTransaction& txFrom, CMutableTransaction& txTo,
                   unsigned int nIn, int nHashType, SignatureData& sig_data);

#endif // BITCOIN_TEST_UTIL_TRANSACTION_UTILS_H
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