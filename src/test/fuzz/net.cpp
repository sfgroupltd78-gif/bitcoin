// Copyright (c) 2020-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <net.h>
#include <net_permissions.h>
#include <netaddress.h>
#include <protocol.h>
#include <random.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <test/fuzz/util/net.h>
#include <test/util/net.h>
#include <test/util/setup_common.h>
#include <util/asmap.h>
#include <util/chaintype.h>
#include <util/time.h>

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

void initialize_net()
{
    static const auto testing_setup = MakeNoLogFileContext<>(ChainType::MAIN);
}

FUZZ_TARGET(net, .init = initialize_net)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    SetMockTime(ConsumeTime(fuzzed_data_provider));
    CNode node{ConsumeNode(fuzzed_data_provider)};
    node.SetCommonVersion(fuzzed_data_provider.ConsumeIntegral<int>());
    if (const auto service_opt =
            ConsumeDeserializable<CService>(fuzzed_data_provider, ConsumeDeserializationParams<CNetAddr::SerParams>(fuzzed_data_provider)))
    {
        node.SetAddrLocal(*service_opt);
    }
    LIMITED_WHILE(fuzzed_data_provider.ConsumeBool(), 10000) {
        CallOneOf(
            fuzzed_data_provider,
            [&] {
                node.CloseSocketDisconnect();
            },
            [&] {
                CNodeStats stats;
                node.CopyStats(stats);
            },
            [&] {
                const CNode* add_ref_node = node.AddRef();
                assert(add_ref_node == &node);
            },
            [&] {
                if (node.GetRefCount() > 0) {
                    node.Release();
                }
            },
            [&] {
                const std::vector<uint8_t> b = ConsumeRandomLengthByteVector(fuzzed_data_provider);
                bool complete;
                node.ReceiveMsgBytes(b, complete);
            });
    }

    (void)node.GetAddrLocal();
    (void)node.GetId();
    (void)node.GetLocalNonce();
    const int ref_count = node.GetRefCount();
    assert(ref_count >= 0);
    (void)node.GetCommonVersion();

    const NetPermissionFlags net_permission_flags = ConsumeWeakEnum(fuzzed_data_provider, ALL_NET_PERMISSION_FLAGS);
    (void)node.HasPermission(net_permission_flags);
    (void)node.ConnectedThroughNetwork();
}

FUZZ_TARGET(local_address, .init = initialize_net)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());
    SetMockTime(ConsumeTime(fuzzed_data_provider));
    CService service{ConsumeService(fuzzed_data_provider)};
    CNode node{ConsumeNode(fuzzed_data_provider)};
    {
        LOCK(g_maplocalhost_mutex);
        mapLocalHost.clear();
    }
    LIMITED_WHILE(fuzzed_data_provider.ConsumeBool(), 10000) {
        CallOneOf(
            fuzzed_data_provider,
            [&] {
                service = ConsumeService(fuzzed_data_provider);
            },
            [&] {
                const bool added{AddLocal(service, fuzzed_data_provider.ConsumeIntegralInRange<int>(0, LOCAL_MAX - 1))};
                if (!added) return;
                assert(service.IsRoutable());
                assert(IsLocal(service));
                assert(SeenLocal(service));
            },
            [&] {
                (void)RemoveLocal(service);
            },
            [&] {
                (void)SeenLocal(service);
            },
            [&] {
                (void)IsLocal(service);
            },
            [&] {
                (void)GetLocalAddress(node);
            });
    }
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