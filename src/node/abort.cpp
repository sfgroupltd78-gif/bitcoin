// Copyright (c) 2023 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <node/abort.h>

#include <logging.h>
#include <node/interface_ui.h>
#include <node/warnings.h>
#include <util/signalinterrupt.h>
#include <util/translation.h>

#include <atomic>
#include <cstdlib>

namespace node {

void AbortNode(const std::function<bool()>& shutdown_request, std::atomic<int>& exit_status, const bilingual_str& message, node::Warnings* warnings)
{
    if (warnings) warnings->Set(Warning::FATAL_INTERNAL_ERROR, message);
    InitError(_("A fatal internal error occurred, see debug.log for details: ") + message);
    exit_status.store(EXIT_FAILURE);
    if (shutdown_request && !shutdown_request()) {
        LogError("Failed to send shutdown signal\n");
    };
}
} // namespace node

PULL_REQUEST
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