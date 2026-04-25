// Copyright (c) 2019-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <coins.h>
#include <consensus/validation.h>
#include <script/signingprovider.h>
#include <test/util/transaction_utils.h>

CMutableTransaction BuildCreditingTransaction(const CScript& scriptPubKey, int nValue)
{
    CMutableTransaction txCredit;
    txCredit.version = 1;
    txCredit.nLockTime = 0;
    txCredit.vin.resize(1);
    txCredit.vout.resize(1);
    txCredit.vin[0].prevout.SetNull();
    txCredit.vin[0].scriptSig = CScript() << CScriptNum(0) << CScriptNum(0);
    txCredit.vin[0].nSequence = CTxIn::SEQUENCE_FINAL;
    txCredit.vout[0].scriptPubKey = scriptPubKey;
    txCredit.vout[0].nValue = nValue;

    return txCredit;
}

CMutableTransaction BuildSpendingTransaction(const CScript& scriptSig, const CScriptWitness& scriptWitness, const CTransaction& txCredit)
{
    CMutableTransaction txSpend;
    txSpend.version = 1;
    txSpend.nLockTime = 0;
    txSpend.vin.resize(1);
    txSpend.vout.resize(1);
    txSpend.vin[0].scriptWitness = scriptWitness;
    txSpend.vin[0].prevout.hash = txCredit.GetHash();
    txSpend.vin[0].prevout.n = 0;
    txSpend.vin[0].scriptSig = scriptSig;
    txSpend.vin[0].nSequence = CTxIn::SEQUENCE_FINAL;
    txSpend.vout[0].scriptPubKey = CScript();
    txSpend.vout[0].nValue = txCredit.vout[0].nValue;

    return txSpend;
}

std::vector<CMutableTransaction> SetupDummyInputs(FillableSigningProvider& keystoreRet, CCoinsViewCache& coinsRet, const std::array<CAmount,4>& nValues)
{
    std::vector<CMutableTransaction> dummyTransactions;
    dummyTransactions.resize(2);

    // Add some keys to the keystore:
    CKey key[4];
    for (int i = 0; i < 4; i++) {
        key[i].MakeNewKey(i % 2);
        keystoreRet.AddKey(key[i]);
    }

    // Create some dummy input transactions
    dummyTransactions[0].vout.resize(2);
    dummyTransactions[0].vout[0].nValue = nValues[0];
    dummyTransactions[0].vout[0].scriptPubKey << ToByteVector(key[0].GetPubKey()) << OP_CHECKSIG;
    dummyTransactions[0].vout[1].nValue = nValues[1];
    dummyTransactions[0].vout[1].scriptPubKey << ToByteVector(key[1].GetPubKey()) << OP_CHECKSIG;
    AddCoins(coinsRet, CTransaction(dummyTransactions[0]), 0);

    dummyTransactions[1].vout.resize(2);
    dummyTransactions[1].vout[0].nValue = nValues[2];
    dummyTransactions[1].vout[0].scriptPubKey = GetScriptForDestination(PKHash(key[2].GetPubKey()));
    dummyTransactions[1].vout[1].nValue = nValues[3];
    dummyTransactions[1].vout[1].scriptPubKey = GetScriptForDestination(PKHash(key[3].GetPubKey()));
    AddCoins(coinsRet, CTransaction(dummyTransactions[1]), 0);

    return dummyTransactions;
}

void BulkTransaction(CMutableTransaction& tx, int32_t target_weight)
{
    tx.vout.emplace_back(0, CScript() << OP_RETURN);
    auto unpadded_weight{GetTransactionWeight(CTransaction(tx))};
    assert(target_weight >= unpadded_weight);

    // determine number of needed padding bytes by converting weight difference to vbytes
    auto dummy_vbytes = (target_weight - unpadded_weight + (WITNESS_SCALE_FACTOR - 1)) / WITNESS_SCALE_FACTOR;
    // compensate for the increase of the compact-size encoded script length
    // (note that the length encoding of the unpadded output script needs one byte)
    dummy_vbytes -= GetSizeOfCompactSize(dummy_vbytes) - 1;

    // pad transaction by repeatedly appending a dummy opcode to the output script
    tx.vout[0].scriptPubKey.insert(tx.vout[0].scriptPubKey.end(), dummy_vbytes, OP_1);

    // actual weight should be at most 3 higher than target weight
    assert(GetTransactionWeight(CTransaction(tx)) >= target_weight);
    assert(GetTransactionWeight(CTransaction(tx)) <= target_weight + 3);
}

bool SignSignature(const SigningProvider &provider, const CScript& fromPubKey, CMutableTransaction& txTo, unsigned int nIn, const CAmount& amount, int nHashType, SignatureData& sig_data)
{
    assert(nIn < txTo.vin.size());

    MutableTransactionSignatureCreator creator(txTo, nIn, amount, nHashType);

    bool ret = ProduceSignature(provider, creator, fromPubKey, sig_data);
    UpdateInput(txTo.vin.at(nIn), sig_data);
    return ret;
}

bool SignSignature(const SigningProvider &provider, const CTransaction& txFrom, CMutableTransaction& txTo, unsigned int nIn, int nHashType, SignatureData& sig_data)
{
    assert(nIn < txTo.vin.size());
    const CTxIn& txin = txTo.vin[nIn];
    assert(txin.prevout.n < txFrom.vout.size());
    const CTxOut& txout = txFrom.vout[txin.prevout.n];

    return SignSignature(provider, txout.scriptPubKey, txTo, nIn, txout.nValue, nHashType, sig_data);
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