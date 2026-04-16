// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MP_PROXY_TYPE_TUPLE_H
#define MP_PROXY_TYPE_TUPLE_H

#include <mp/util.h>

namespace mp {
// TODO: Should generalize this to work with arbitrary length tuples, not just length 2-tuples.
template <typename KeyLocalType, typename ValueLocalType, typename Value, typename Output>
void CustomBuildField(TypeList<std::tuple<KeyLocalType, ValueLocalType>>,
    Priority<1>,
    InvokeContext& invoke_context,
    Value&& value,
    Output&& output)
{
    auto pair = output.init();
    using Accessors = typename ProxyStruct<typename decltype(pair)::Builds>::Accessors;
    BuildField(TypeList<KeyLocalType>(), invoke_context, Make<StructField, std::tuple_element_t<0, Accessors>>(pair), std::get<0>(value));
    BuildField(TypeList<ValueLocalType>(), invoke_context, Make<StructField, std::tuple_element_t<1, Accessors>>(pair), std::get<1>(value));
}

// TODO: Should generalize this to work with arbitrary length tuples, not just length 2-tuples.
template <typename KeyLocalType, typename ValueLocalType, typename Input, typename ReadDest>
decltype(auto) CustomReadField(TypeList<std::tuple<KeyLocalType, ValueLocalType>>,
    Priority<1>,
    InvokeContext& invoke_context,
    Input&& input,
    ReadDest&& read_dest)
{
    return read_dest.update([&](auto& value) {
        const auto& pair = input.get();
        using Struct = ProxyStruct<typename Decay<decltype(pair)>::Reads>;
        using Accessors = typename Struct::Accessors;
        ReadField(TypeList<KeyLocalType>(), invoke_context, Make<StructField, std::tuple_element_t<0, Accessors>>(pair),
            ReadDestUpdate(std::get<0>(value)));
        ReadField(TypeList<ValueLocalType>(), invoke_context, Make<StructField, std::tuple_element_t<1, Accessors>>(pair),
            ReadDestUpdate(std::get<1>(value)));
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

#endif // MP_PROXY_TYPE_TUPLE_H
