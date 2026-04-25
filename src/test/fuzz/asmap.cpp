// Copyright (c) 2020-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <netaddress.h>
#include <netgroup.h>
#include <test/fuzz/fuzz.h>
#include <util/asmap.h>

#include <cstdint>
#include <vector>

//! asmap code that consumes nothing
static const std::vector<bool> IPV6_PREFIX_ASMAP = {};

//! asmap code that consumes the 96 prefix bits of ::ffff:0/96 (IPv4-in-IPv6 map)
static const std::vector<bool> IPV4_PREFIX_ASMAP = {
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, // Match 0x00
    true, true, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,         // Match 0xFF
    true, true, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true          // Match 0xFF
};

FUZZ_TARGET(asmap)
{
    // Encoding: [7 bits: asmap size] [1 bit: ipv6?] [3-130 bytes: asmap] [4 or 16 bytes: addr]
    if (buffer.size() < 1 + 3 + 4) return;
    int asmap_size = 3 + (buffer[0] & 127);
    bool ipv6 = buffer[0] & 128;
    const size_t addr_size = ipv6 ? ADDR_IPV6_SIZE : ADDR_IPV4_SIZE;
    if (buffer.size() < size_t(1 + asmap_size + addr_size)) return;
    std::vector<bool> asmap = ipv6 ? IPV6_PREFIX_ASMAP : IPV4_PREFIX_ASMAP;
    asmap.reserve(asmap.size() + 8 * asmap_size);
    for (int i = 0; i < asmap_size; ++i) {
        for (int j = 0; j < 8; ++j) {
            asmap.push_back((buffer[1 + i] >> j) & 1);
        }
    }
    if (!SanityCheckASMap(asmap, 128)) return;

    const uint8_t* addr_data = buffer.data() + 1 + asmap_size;
    CNetAddr net_addr;
    if (ipv6) {
        assert(addr_size == ADDR_IPV6_SIZE);
        net_addr.SetLegacyIPv6({addr_data, addr_size});
    } else {
        assert(addr_size == ADDR_IPV4_SIZE);
        in_addr ipv4;
        memcpy(&ipv4, addr_data, addr_size);
        net_addr.SetIP(CNetAddr{ipv4});
    }
    NetGroupManager netgroupman{asmap};
    (void)netgroupman.GetMappedAS(net_addr);
}
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