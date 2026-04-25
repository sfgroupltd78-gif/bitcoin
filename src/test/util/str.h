// Copyright (c) 2019 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_TEST_UTIL_STR_H
#define BITCOIN_TEST_UTIL_STR_H

#include <string>

bool CaseInsensitiveEqual(const std::string& s1, const std::string& s2);

/**
 * Increment a string. Useful to enumerate all fixed length strings with
 * characters in [min_char, max_char].
 */
template <typename CharType, size_t StringLength>
bool NextString(CharType (&string)[StringLength], CharType min_char, CharType max_char)
{
    for (CharType& elem : string) {
        bool has_next = elem != max_char;
        elem = elem < min_char || elem >= max_char ? min_char : CharType(elem + 1);
        if (has_next) return true;
    }
    return false;
}

/**
 * Iterate over string values and call function for each string without
 * successive duplicate characters.
 */
template <typename CharType, size_t StringLength, typename Fn>
void ForEachNoDup(CharType (&string)[StringLength], CharType min_char, CharType max_char, Fn&& fn) {
    for (bool has_next = true; has_next; has_next = NextString(string, min_char, max_char)) {
        int prev = -1;
        bool skip_string = false;
        for (CharType c : string) {
            if (c == prev) skip_string = true;
            if (skip_string || c < min_char || c > max_char) break;
            prev = c;
        }
        if (!skip_string) fn();
    }
}

#endif // BITCOIN_TEST_UTIL_STR_H
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