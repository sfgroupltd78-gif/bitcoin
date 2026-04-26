#include <node/caches.h>
#include <util/byte_units.h>

#include <boost/test/unit_test.hpp>

using namespace node;

BOOST_AUTO_TEST_SUITE(caches_tests)

BOOST_AUTO_TEST_CASE(oversized_dbcache_warning)
{
    // memory restricted setup - cap is DEFAULT_DB_CACHE (450 MiB)
    BOOST_CHECK(!ShouldWarnOversizedDbCache(/*dbcache=*/4_MiB, /*total_ram=*/1024_MiB));    // Under cap
    BOOST_CHECK( ShouldWarnOversizedDbCache(/*dbcache=*/512_MiB, /*total_ram=*/1024_MiB));  // At cap
    BOOST_CHECK( ShouldWarnOversizedDbCache(/*dbcache=*/1500_MiB, /*total_ram=*/1024_MiB)); // Over cap

    // 2 GiB RAM - cap is 75%
    BOOST_CHECK(!ShouldWarnOversizedDbCache(/*dbcache=*/1500_MiB, /*total_ram=*/2048_MiB)); // Under cap
    BOOST_CHECK( ShouldWarnOversizedDbCache(/*dbcache=*/1600_MiB, /*total_ram=*/2048_MiB)); // Over cap

    if constexpr (SIZE_MAX == UINT64_MAX) {
        // 4 GiB RAM - cap is 75%
        BOOST_CHECK(!ShouldWarnOversizedDbCache(/*dbcache=*/2500_MiB, /*total_ram=*/4096_MiB)); // Under cap
        BOOST_CHECK( ShouldWarnOversizedDbCache(/*dbcache=*/3500_MiB, /*total_ram=*/4096_MiB)); // Over cap

        // 8 GiB RAM - cap is 75%
        BOOST_CHECK(!ShouldWarnOversizedDbCache(/*dbcache=*/6000_MiB, /*total_ram=*/8192_MiB)); // Under cap
        BOOST_CHECK( ShouldWarnOversizedDbCache(/*dbcache=*/7000_MiB, /*total_ram=*/8192_MiB)); // Over cap

        // 16 GiB RAM - cap is 75%
        BOOST_CHECK(!ShouldWarnOversizedDbCache(/*dbcache=*/10'000_MiB, /*total_ram=*/16384_MiB)); // Under cap
        BOOST_CHECK( ShouldWarnOversizedDbCache(/*dbcache=*/15'000_MiB, /*total_ram=*/16384_MiB)); // Over cap

        // 32 GiB RAM - cap is 75%
        BOOST_CHECK(!ShouldWarnOversizedDbCache(/*dbcache=*/20'000_MiB, /*total_ram=*/32768_MiB)); // Under cap
        BOOST_CHECK( ShouldWarnOversizedDbCache(/*dbcache=*/30'000_MiB, /*total_ram=*/32768_MiB)); // Over cap
    }
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