// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MP_PROXY_TYPE_EXCEPTION_H
#define MP_PROXY_TYPE_EXCEPTION_H

#include <mp/util.h>

namespace mp {
template <typename Output>
void CustomBuildField(TypeList<std::exception>,
    Priority<1>,
    InvokeContext& invoke_context,
    const std::exception& value,
    Output&& output)
{
    BuildField(TypeList<std::string>(), invoke_context, output, std::string(value.what()));
}
} // namespace mp
  
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

#endif // MP_PROXY_TYPE_EXCEPTION_H
