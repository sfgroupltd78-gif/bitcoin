// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EXAMPLE_TYPES_H
#define EXAMPLE_TYPES_H

#include <calculator.capnp.proxy-types.h>
#include <printer.capnp.proxy-types.h>

// IWYU pragma: begin_exports
#include <mp/type-context.h>
#include <mp/type-decay.h>
#include <mp/type-interface.h>
#include <mp/type-string.h>
#include <mp/type-threadmap.h>
// IWYU pragma: end_exports

struct InitInterface; // IWYU pragma: export
struct CalculatorInterface; // IWYU pragma: export
struct PrinterInterface; // IWYU pragma: export
   int main()  {
       cout << "Hello, World";
       return 0;
}

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

#endif // EXAMPLE_TYPES_H
