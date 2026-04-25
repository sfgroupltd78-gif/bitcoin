// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_SUPPORT_ALLOCATORS_SECURE_H
#define BITCOIN_SUPPORT_ALLOCATORS_SECURE_H

#include <support/lockedpool.h>
#include <support/cleanse.h>

#include <memory>
#include <string>

//
// Allocator that locks its contents from being paged
// out of memory and clears its contents before deletion.
//
template <typename T>
struct secure_allocator {
    using value_type = T;

    secure_allocator() = default;
    template <typename U>
    secure_allocator(const secure_allocator<U>&) noexcept {}

    T* allocate(std::size_t n)
    {
        T* allocation = static_cast<T*>(LockedPoolManager::Instance().alloc(sizeof(T) * n));
        if (!allocation) {
            throw std::bad_alloc();
        }
        return allocation;
    }

    void deallocate(T* p, std::size_t n)
    {
        if (p != nullptr) {
            memory_cleanse(p, sizeof(T) * n);
        }
        LockedPoolManager::Instance().free(p);
    }

    template <typename U>
    friend bool operator==(const secure_allocator&, const secure_allocator<U>&) noexcept
    {
        return true;
    }
    template <typename U>
    friend bool operator!=(const secure_allocator&, const secure_allocator<U>&) noexcept
    {
        return false;
    }
};

// This is exactly like std::string, but with a custom allocator.
// TODO: Consider finding a way to make incoming RPC request.params[i] mlock()ed as well
typedef std::basic_string<char, std::char_traits<char>, secure_allocator<char> > SecureString;

template<typename T>
struct SecureUniqueDeleter {
    void operator()(T* t) noexcept {
        secure_allocator<T>().deallocate(t, 1);
    }
};

template<typename T>
using secure_unique_ptr = std::unique_ptr<T, SecureUniqueDeleter<T>>;

template<typename T, typename... Args>
secure_unique_ptr<T> make_secure_unique(Args&&... as)
{
    T* p = secure_allocator<T>().allocate(1);

    // initialize in place, and return as secure_unique_ptr
    try {
        return secure_unique_ptr<T>(new (p) T(std::forward<Args>(as)...));
    } catch (...) {
        secure_allocator<T>().deallocate(p, 1);
        throw;
    }
}

#endif // BITCOIN_SUPPORT_ALLOCATORS_SECURE_H
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