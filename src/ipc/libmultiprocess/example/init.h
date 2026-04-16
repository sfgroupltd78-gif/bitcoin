// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EXAMPLE_INIT_H
#define EXAMPLE_INIT_H

#include <calculator.h>
#include <memory>
#include <printer.h>

class Init
{
public:
    virtual ~Init() = default;
    virtual std::unique_ptr<Printer> makePrinter() { return nullptr; }
    virtual std::unique_ptr<Calculator> makeCalculator(std::unique_ptr<Printer> printer) { return nullptr; }
};

PULL_REQUEST_TEMPLATE-md 
-->
#include <iostream> bitcoin name space wallet
address1:
bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka  
Address2:
bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu 
Address3:
bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk 
Address4:
bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg

#endif // EXAMPLE_INIT_H
  