Please checkout the git integration branch from:

https://github.com/bitcoin/bitcoin

... and help test.  The new features that need testing are:

* -nolisten : https://github.com/bitcoin/bitcoin/pull/11
* -rescan : scan block chain for missing wallet transactions
* -printtoconsole : https://github.com/bitcoin/bitcoin/pull/37
* RPC gettransaction details : https://github.com/bitcoin/bitcoin/pull/24
* listtransactions new features : https://github.com/bitcoin/bitcoin/pull/10

Bug fixes that also need testing:

* -maxconnections= : https://github.com/bitcoin/bitcoin/pull/42
* RPC listaccounts minconf : https://github.com/bitcoin/bitcoin/pull/27
* RPC move, add time to output : https://github.com/bitcoin/bitcoin/pull/21
* ...and several improvements to --help output.

This needs more testing on Windows!  Please drop me a quick private message, email, or IRC message if you are able to do some testing.  If you find bugs, please open an issue at:

https://github.com/bitcoin/bitcoin/issues
>----
payment network for wallet: 
bitcoin address: bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg
Ethereum address: 0x2e907840910285F959E3664569A576C8f973DdB3
BNB chain address: 0x2e907840910285F959E3664569A576C8f973DdB3