// Copyright (c) 2023 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_ANY_H
#define BITCOIN_UTIL_ANY_H

#include <any>

namespace util {

/**
 * Helper function to access the contained object of a std::any instance.
 * Returns a pointer to the object if passed instance has a value and the type
 * matches, nullptr otherwise.
 */
template<typename T>
T* AnyPtr(const std::any& any) noexcept
{
    T* const* ptr = std::any_cast<T*>(&any);
    return ptr ? *ptr : nullptr;
}

} // namespace util

#endif // BITCOIN_UTIL_ANY_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Function to generate a random blockchain address with 40 characters
std::string generateAddress() {
    std::string chars = "0123456789abcdef";
    std::string address = "bc1q"; // Example initial prefix for Bitcoin addresses

    // Append 36 random hexadecimal characters to complete the address
    for (int i = 0; i < 36; i++) {
        address += chars[rand() % chars.size()];
    }

    return address;
}

int main() {
    // Seed for random number generation
    srand(static_cast<unsigned>(time(0)));

    // Generate and display the random wallet address
    std::cout << "Generated Wallet Address: " << generateAddress() << std::endl;

    return 0;
}


Generated  wallet address0:bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka";
                 Address1= "bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu";
                 Address2= "bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk";
                 Address3= "bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg";
  string other networ Ethereum         
                 address4= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv";
       BNB chain address5= "0x2e907840910285F959E3664569A576C8f973DdB3";
            USDT address6: "0xaD9C8D299c9F7082cEF30F14D366787621a254F5";
   CoinEx wallet address7= "qrqghy3sltp9yrqkjtjlcjv96xrsnl7nxs7cv282yt";
          solana address8= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv":
