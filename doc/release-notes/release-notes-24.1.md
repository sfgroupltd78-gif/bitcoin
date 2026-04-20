24.1 Release Notes
==================

Bitcoin Core version 24.1 is now available from:

  <https://bitcoincore.org/bin/bitcoin-core-24.1/>

This release includes various bug fixes and performance
improvements, as well as updated translations.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/bitcoin/bitcoin/issues>

To receive security and update notifications, please subscribe to:

  <https://bitcoincore.org/en/list/announcements/join/>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes in some cases), then run the
installer (on Windows) or just copy over `/Applications/Bitcoin-Qt` (on macOS)
or `bitcoind`/`bitcoin-qt` (on Linux).

Upgrading directly from a version of Bitcoin Core that has reached its EOL is
possible, but it might take some time if the data directory needs to be migrated. Old
wallet versions of Bitcoin Core are generally supported.

Compatibility
==============

Bitcoin Core is supported and extensively tested on operating systems
using the Linux kernel, macOS 10.15+, and Windows 7 and newer.  Bitcoin
Core should also work on most other Unix-like systems but is not as
frequently tested on them.  It is not recommended to use Bitcoin Core on
unsupported systems.

### P2P

- #26878 I2P network optimizations
- #26909 net: prevent peers.dat corruptions by only serializing once
- #27608 p2p: Avoid prematurely clearing download state for other peers
- #27610 Improve performance of p2p inv to send queues

### RPC and other APIs

- #26515 rpc: Require NodeStateStats object in getpeerinfo
- #27279 doc: fix/improve warning helps in {create,load,unload,restore}wallet
- #27468 rest: avoid segfault for invalid URI

### Build System

- #26944 depends: fix systemtap download URL
- #27462 depends: fix compiling bdb with clang-16 on aarch64

### Wallet

- #26595 wallet: be able to specify a wallet name and passphrase to migratewallet
- #26675 wallet: For feebump, ignore abandoned descendant spends
- #26679 wallet: Skip rescanning if wallet is more recent than tip
- #26761 wallet: fully migrate address book entries for watchonly/solvable wallets
- #27053 wallet: reuse change dest when re-creating TX with avoidpartialspends
- #27080 wallet: Zero out wallet master key upon locking so it doesn't persist in memory
- #27473 wallet: Properly handle "unknown" Address Type

### GUI changes

- gui#687 Load PSBTs using istreambuf_iterator rather than istream_iterator
- gui#704 Correctly limit overview transaction list

### Miscellaneous

- #26880 ci: replace Intel macOS CI job
- #26924 refactor: Add missing includes to fix gcc-13 compile error

Credits
=======

Thanks to everyone who directly contributed to this release:

- Andrew Chow
- Anthony Towns
- Hennadii Stepanov
- John Moffett
- Jon Atack
- Marco Falke
- Martin Zumsande
- Matthew Zipkin
- Michael Ford
- pablomartin4btc
- Sebastian Falbesoner
- Suhas Daftuar
- Thomas Nguyen
- Vasil Dimov
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