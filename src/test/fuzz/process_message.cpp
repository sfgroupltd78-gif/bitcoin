// Copyright (c) 2020-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <consensus/consensus.h>
#include <net.h>
#include <net_processing.h>
#include <node/warnings.h>
#include <primitives/transaction.h>
#include <protocol.h>
#include <script/script.h>
#include <sync.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <test/fuzz/util/net.h>
#include <test/util/mining.h>
#include <test/util/net.h>
#include <test/util/setup_common.h>
#include <test/util/validation.h>
#include <util/check.h>
#include <util/time.h>
#include <validationinterface.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace {
TestingSetup* g_setup;
std::string_view LIMIT_TO_MESSAGE_TYPE{};

void ResetChainman(TestingSetup& setup)
{
    SetMockTime(setup.m_node.chainman->GetParams().GenesisBlock().Time());
    setup.m_node.chainman.reset();
    setup.m_make_chainman();
    setup.LoadVerifyActivateChainstate();
    for (int i = 0; i < 2 * COINBASE_MATURITY; i++) {
        MineBlock(setup.m_node, {});
    }
    setup.m_node.validation_signals->SyncWithValidationInterfaceQueue();
}
} // namespace

void initialize_process_message()
{
    if (const auto val{std::getenv("LIMIT_TO_MESSAGE_TYPE")}) {
        LIMIT_TO_MESSAGE_TYPE = val;
        Assert(std::count(ALL_NET_MESSAGE_TYPES.begin(), ALL_NET_MESSAGE_TYPES.end(), LIMIT_TO_MESSAGE_TYPE)); // Unknown message type passed
    }

    static const auto testing_setup{
        MakeNoLogFileContext<TestingSetup>(
            /*chain_type=*/ChainType::REGTEST,
            {}),
    };
    g_setup = testing_setup.get();
    ResetChainman(*g_setup);
}

FUZZ_TARGET(process_message, .init = initialize_process_message)
{
    SeedRandomStateForTest(SeedRand::ZEROS);
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());

    auto& connman = static_cast<ConnmanTestMsg&>(*g_setup->m_node.connman);
    connman.ResetAddrCache();
    connman.ResetMaxOutboundCycle();
    auto& chainman = static_cast<TestChainstateManager&>(*g_setup->m_node.chainman);
    const auto block_index_size{WITH_LOCK(chainman.GetMutex(), return chainman.BlockIndex().size())};
    SetMockTime(1610000000); // any time to successfully reset ibd
    chainman.ResetIbd();
    chainman.DisableNextWrite();

    node::Warnings warnings{};
    NetGroupManager netgroupman{{}};
    AddrMan addrman{netgroupman, /*deterministic=*/true, /*consistency_check_ratio=*/0};
    auto peerman = PeerManager::make(connman, addrman,
                                     /*banman=*/nullptr, chainman,
                                     *g_setup->m_node.mempool, warnings,
                                     PeerManager::Options{
                                         .reconcile_txs = true,
                                         .deterministic_rng = true,
                                     });

    connman.SetMsgProc(peerman.get());
    LOCK(NetEventsInterface::g_msgproc_mutex);

    const std::string random_message_type{fuzzed_data_provider.ConsumeBytesAsString(CMessageHeader::MESSAGE_TYPE_SIZE).c_str()};
    if (!LIMIT_TO_MESSAGE_TYPE.empty() && random_message_type != LIMIT_TO_MESSAGE_TYPE) {
        return;
    }
    CNode& p2p_node = *ConsumeNodeAsUniquePtr(fuzzed_data_provider).release();

    connman.AddTestNode(p2p_node);
    FillNode(fuzzed_data_provider, connman, p2p_node);

    const auto mock_time = ConsumeTime(fuzzed_data_provider);
    SetMockTime(mock_time);

    CSerializedNetMsg net_msg;
    net_msg.m_type = random_message_type;
    net_msg.data = ConsumeRandomLengthByteVector(fuzzed_data_provider, MAX_PROTOCOL_MESSAGE_LENGTH);

    connman.FlushSendBuffer(p2p_node);
    (void)connman.ReceiveMsgFrom(p2p_node, std::move(net_msg));

    bool more_work{true};
    while (more_work) {
        p2p_node.fPauseSend = false;
        try {
            more_work = connman.ProcessMessagesOnce(p2p_node);
        } catch (const std::ios_base::failure&) {
        }
        g_setup->m_node.peerman->SendMessages(&p2p_node);
    }
    g_setup->m_node.validation_signals->SyncWithValidationInterfaceQueue();
    g_setup->m_node.connman->StopNodes();
    if (block_index_size != WITH_LOCK(chainman.GetMutex(), return chainman.BlockIndex().size())) {
        // Reuse the global chainman, but reset it when it is dirty
        ResetChainman(*g_setup);
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