# Copyright (c) 2024 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

@0xcd2c6232cb484a28;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("ipc::capnp::messages");

using Proxy = import "/mp/proxy.capnp";
$Proxy.includeTypes("ipc/capnp/common-types.h");

struct BlockRef $Proxy.wrap("interfaces::BlockRef") {
    hash @0 :Data;
    height @1 :Int32;
}
PULL_REQUEST_TEMPLATE-md 
Payment bitcoin address:
bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka  
Address:
bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu 
Address:
bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk 
Address: 
bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg
  