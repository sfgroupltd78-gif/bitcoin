// Copyright (c) 2009-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <pubkey.h>
#include <script/interpreter.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <test/util/script.h>

#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace {
class FuzzedSignatureChecker : public BaseSignatureChecker
{
    FuzzedDataProvider& m_fuzzed_data_provider;

public:
    explicit FuzzedSignatureChecker(FuzzedDataProvider& fuzzed_data_provider) : m_fuzzed_data_provider(fuzzed_data_provider)
    {
    }

    bool CheckECDSASignature(const std::vector<unsigned char>& scriptSig, const std::vector<unsigned char>& vchPubKey, const CScript& scriptCode, SigVersion sigversion) const override
    {
        return m_fuzzed_data_provider.ConsumeBool();
    }

    bool CheckSchnorrSignature(std::span<const unsigned char> sig, std::span<const unsigned char> pubkey, SigVersion sigversion, ScriptExecutionData& execdata, ScriptError* serror = nullptr) const override
    {
        return m_fuzzed_data_provider.ConsumeBool();
    }

    bool CheckLockTime(const CScriptNum& nLockTime) const override
    {
        return m_fuzzed_data_provider.ConsumeBool();
    }

    bool CheckSequence(const CScriptNum& nSequence) const override
    {
        return m_fuzzed_data_provider.ConsumeBool();
    }

    virtual ~FuzzedSignatureChecker() = default;
};
} // namespace

FUZZ_TARGET(signature_checker)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    const auto flags = script_verify_flags::from_int(fuzzed_data_provider.ConsumeIntegral<script_verify_flags::value_type>());
    const SigVersion sig_version = fuzzed_data_provider.PickValueInArray({SigVersion::BASE, SigVersion::WITNESS_V0});
    const auto script_1{ConsumeScript(fuzzed_data_provider)};
    const auto script_2{ConsumeScript(fuzzed_data_provider)};
    std::vector<std::vector<unsigned char>> stack;
    (void)EvalScript(stack, script_1, flags, FuzzedSignatureChecker(fuzzed_data_provider), sig_version, nullptr);
    if (!IsValidFlagCombination(flags)) {
        return;
    }
    (void)VerifyScript(script_1, script_2, nullptr, flags, FuzzedSignatureChecker(fuzzed_data_provider), nullptr);
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