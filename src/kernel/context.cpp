// Copyright (c) 2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <kernel/context.h>

#include <crypto/sha256.h>
#include <logging.h>
#include <random.h>

#include <mutex>
#include <string>

namespace kernel {
Context::Context()
{
    static std::once_flag globals_initialized{};
    std::call_once(globals_initialized, []() {
        std::string sha256_algo = SHA256AutoDetect();
        LogInfo("Using the '%s' SHA256 implementation\n", sha256_algo);
        RandomInit();
    });
}


} // namespace kernel

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

For other network  namespace wallet Ethereum         
address: 
tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv

#endif