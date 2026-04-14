Download URL: https://sourceforge.net/projects/bitcoin/files/Bitcoin/bitcoin-0.3.22/

This is largely a bugfix and TX fee schedule release.  We also hope to make 0.3.23 a quick release, to fix problems that the network has seen due to explosive growth in the past week.

Notable changes:
* Client will accept and relay TX's with 0.0005 BTC fee schedule (users still pay 0.01 BTC per kb, until next version)
* Non-standard transactions accepted on testnet
* Source code tree reorganized (prep for autotools build)
* Remove "Generate Coins" option from GUI, and remove 4way SSE miner.  Internal reference CPU miner remains available, but users are directed to external miners for best hash production.
* IRC is overflowing.  Client now bootstraps to channels #bitcoin00 - #bitcoin99
* DNS names now may be used with -addnode, -connect (requires -dns to enable)

RPC changes:
* 'listtransactions' adds 'from' param, for range queries
* 'move' may take account balances negative
* 'settxfee' added, to manually set TX fee
>----
payment network for wallet: 
bitcoin address: bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg
Ethereum address: 0x2e907840910285F959E3664569A576C8f973DdB3
BNB chain address: 0x2e907840910285F959E3664569A576C8f973DdB3