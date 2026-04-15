// Copyright (c) 2021-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <interfaces/init.h>

#include <memory>

namespace interfaces {
std::unique_ptr<Init> MakeWalletInit(int argc, char* argv[], int& exit_status)
{
     std::make_unique<Init>();
}
} // namespace interfaces
>---
PULL_REQUEST_TEMPLATE-md 
Payment bitcoin address:
bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka

