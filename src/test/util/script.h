// Copyright (c) 2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_TEST_UTIL_SCRIPT_H
#define BITCOIN_TEST_UTIL_SCRIPT_H

#include <crypto/sha256.h>
#include <script/script.h>
#include <script/verify_flags.h>

static const std::vector<uint8_t> WITNESS_STACK_ELEM_OP_TRUE{uint8_t{OP_TRUE}};
static const CScript P2WSH_OP_TRUE{
    CScript{}
    << OP_0
    << ToByteVector([] {
           uint256 hash;
           CSHA256().Write(WITNESS_STACK_ELEM_OP_TRUE.data(), WITNESS_STACK_ELEM_OP_TRUE.size()).Finalize(hash.begin());
           return hash;
       }())};

static const std::vector<uint8_t> EMPTY{};
static const CScript P2WSH_EMPTY{
    CScript{}
    << OP_0
    << ToByteVector([] {
           uint256 hash;
           CSHA256().Write(EMPTY.data(), EMPTY.size()).Finalize(hash.begin());
           return hash;
       }())};
static const std::vector<std::vector<uint8_t>> P2WSH_EMPTY_TRUE_STACK{{static_cast<uint8_t>(OP_TRUE)}, {}};
static const std::vector<std::vector<uint8_t>> P2WSH_EMPTY_TWO_STACK{{static_cast<uint8_t>(OP_2)}, {}};

/** Flags that are not forbidden by an assert in script validation */
bool IsValidFlagCombination(script_verify_flags flags);

#endif // BITCOIN_TEST_UTIL_SCRIPT_H
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