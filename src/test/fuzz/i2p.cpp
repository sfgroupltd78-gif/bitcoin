// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <common/args.h>
#include <i2p.h>
#include <netaddress.h>
#include <netbase.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <test/fuzz/util/net.h>
#include <test/fuzz/util/threadinterrupt.h>
#include <test/util/setup_common.h>
#include <util/fs_helpers.h>
#include <util/threadinterrupt.h>

void initialize_i2p()
{
    static const auto testing_setup = MakeNoLogFileContext<>();
}

FUZZ_TARGET(i2p, .init = initialize_i2p)
{
    SeedRandomStateForTest(SeedRand::ZEROS);
    FuzzedDataProvider fuzzed_data_provider{buffer.data(), buffer.size()};

    SetMockTime(ConsumeTime(fuzzed_data_provider));

    // Mock CreateSock() to create FuzzedSock.
    auto CreateSockOrig = CreateSock;
    CreateSock = [&fuzzed_data_provider](int, int, int) {
        return std::make_unique<FuzzedSock>(fuzzed_data_provider);
    };

    const fs::path private_key_path = gArgs.GetDataDirNet() / "fuzzed_i2p_private_key";
    const CService addr{in6_addr(IN6ADDR_LOOPBACK_INIT), 7656};
    const Proxy sam_proxy{addr, /*tor_stream_isolation=*/false};
    auto interrupt{ConsumeThreadInterrupt(fuzzed_data_provider)};

    i2p::sam::Session session{private_key_path, sam_proxy, interrupt};
    i2p::Connection conn;

    if (session.Listen(conn)) {
        if (session.Accept(conn)) {
            try {
                (void)conn.sock->RecvUntilTerminator('\n', 10ms, *interrupt, i2p::sam::MAX_MSG_SIZE);
            } catch (const std::runtime_error&) {
            }
        }
    }

    bool proxy_error;

    if (session.Connect(CService{}, conn, proxy_error)) {
        try {
            conn.sock->SendComplete("verack\n", 10ms, *interrupt);
        } catch (const std::runtime_error&) {
        }
    }

    fs::remove_all(private_key_path);

    CreateSock = CreateSockOrig;
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