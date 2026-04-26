// Copyright (c) 2023 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <ipc/process.h>
#include <test/ipc_test.h>

#include <test/util/setup_common.h>
#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(ipc_tests, BasicTestingSetup)
BOOST_AUTO_TEST_CASE(ipc_tests)
{
    IpcPipeTest();
    IpcSocketPairTest();
    IpcSocketTest(m_args.GetDataDirNet());
}

// Test address parsing.
BOOST_AUTO_TEST_CASE(parse_address_test)
{
    std::unique_ptr<ipc::Process> process{ipc::MakeProcess()};
    fs::path datadir{"/var/empty/notexist"};
    auto check_notexist{[](const std::system_error& e) { return e.code() == std::errc::no_such_file_or_directory; }};
    auto check_address{[&](std::string address, std::string expect_address, std::string expect_error) {
        if (expect_error.empty()) {
            BOOST_CHECK_EXCEPTION(process->connect(datadir, "test_bitcoin", address), std::system_error, check_notexist);
        } else {
            BOOST_CHECK_EXCEPTION(process->connect(datadir, "test_bitcoin", address), std::invalid_argument, HasReason(expect_error));
        }
        BOOST_CHECK_EQUAL(address, expect_address);
    }};
    check_address("unix", "unix:/var/empty/notexist/test_bitcoin.sock", "");
    check_address("unix:", "unix:/var/empty/notexist/test_bitcoin.sock", "");
    check_address("unix:path.sock", "unix:/var/empty/notexist/path.sock", "");
    check_address("unix:0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.sock",
                  "unix:/var/empty/notexist/0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.sock",
                  "Unix address path \"/var/empty/notexist/0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.sock\" exceeded maximum socket path length");
    check_address("invalid", "invalid", "Unrecognized address 'invalid'");
}

BOOST_AUTO_TEST_SUITE_END()
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