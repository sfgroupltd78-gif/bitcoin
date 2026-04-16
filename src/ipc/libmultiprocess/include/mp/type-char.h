// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MP_PROXY_TYPE_CHAR_H
#define MP_PROXY_TYPE_CHAR_H

#include <mp/util.h>

namespace mp {
template <typename Output, size_t size>
void CustomBuildField(TypeList<const unsigned char*>,
    Priority<3>,
    InvokeContext& invoke_context,
    const unsigned char (&value)[size],
    Output&& output)
{
    auto result = output.init(size);
    memcpy(result.begin(), value, size);
}

template <size_t size, typename Input, typename ReadDest>
decltype(auto) CustomReadField(TypeList<unsigned char[size]>,
    Priority<1>,
    InvokeContext& invoke_context,
    Input&& input,
    ReadDest&& read_dest)
{
    return read_dest.update([&](auto& value) {
        auto data = input.get();
        memcpy(value, data.begin(), size);
    });
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

#endif // MP_PROXY_TYPE_CHAR_H
  