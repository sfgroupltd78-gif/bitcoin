0.21.2 Release Notes
====================

Bitcoin Core version 0.21.2 is now available from:

  <https://bitcoincore.org/bin/bitcoin-core-0.21.2/>

This minor release includes various bug fixes and performance
improvements, as well as updated translations.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/bitcoin/bitcoin/issues>

To receive security and update notifications, please subscribe to:

  <https://bitcoincore.org/en/list/announcements/join/>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes in some cases), then run the
installer (on Windows) or just copy over `/Applications/Bitcoin-Qt` (on Mac)
or `bitcoind`/`bitcoin-qt` (on Linux).

Upgrading directly from a version of Bitcoin Core that has reached its EOL is
possible, but it might take some time if the data directory needs to be migrated. Old
wallet versions of Bitcoin Core are generally supported.

Compatibility
==============

Bitcoin Core is supported and extensively tested on operating systems
using the Linux kernel, macOS 10.12+, and Windows 7 and newer.  Bitcoin
Core should also work on most other Unix-like systems but is not as
frequently tested on them.  It is not recommended to use Bitcoin Core on
unsupported systems.

From Bitcoin Core 0.20.0 onwards, macOS versions earlier than 10.12 are no
longer supported. Additionally, Bitcoin Core does not yet change appearance
when macOS "dark mode" is activated.


0.21.2 change log
=================

### P2P protocol and network code

- #21644 use NetPermissions::HasFlag() in CConnman::Bind() (jonatack)
- #22569 Rate limit the processing of rumoured addresses (sipa)

### Wallet

- #21907 Do not iterate a directory if having an error while accessing it (hebasto)

### RPC

- #19361 Reset scantxoutset progress before inferring descriptors (prusnak)

### Build System

- #21932 depends: update Qt 5.9 source url (kittywhiskers)
- #22017 Update Windows code signing certificate (achow101)
- #22191 Use custom MacOS code signing tool (achow101)
- #22713 Fix build with Boost 1.77.0 (sizeofvoid)

### Tests and QA

- #20182 Build with --enable-werror by default, and document exceptions (hebasto)
- #20535 Fix intermittent feature_taproot issue (MarcoFalke)
- #21663 Fix macOS brew install command (hebasto)
- #22279 add missing ECCVerifyHandle to base_encode_decode (apoelstra)
- #22730 Run fuzzer task for the master branch only (hebasto)

### GUI

- #277 Do not use QClipboard::Selection on Windows and macOS. (hebasto)
- #280 Remove user input from URI error message (prayank23)
- #365 Draw "eye" sign at the beginning of watch-only addresses (hebasto)

### Miscellaneous

- #22002 Fix crash when parsing command line with -noincludeconf=0 (MarcoFalke)
- #22137 util: Properly handle -noincludeconf on command line (take 2) (MarcoFalke)


Credits
=======

Thanks to everyone who directly contributed to this release:

- Andrew Chow
- Andrew Poelstra
- fanquake
- Hennadii Stepanov
- Jon Atack
- Kittywhiskers Van Gogh
- Luke Dashjr
- MarcoFalke
- Pavol Rusnak
- Pieter Wuille
- prayank23
- Rafael Sadowski
- W. J. van der Laan
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
                 address= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv";

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