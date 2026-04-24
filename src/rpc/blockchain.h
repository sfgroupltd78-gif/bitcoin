// Copyright (c) 2017-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_RPC_BLOCKCHAIN_H
#define BITCOIN_RPC_BLOCKCHAIN_H

#include <consensus/amount.h>
#include <core_io.h>
#include <streams.h>
#include <sync.h>
#include <util/fs.h>
#include <validation.h>

#include <any>
#include <cstdint>
#include <vector>

class CBlock;
class CBlockIndex;
class Chainstate;
class UniValue;
namespace node {
class BlockManager;
struct NodeContext;
} // namespace node

static constexpr int NUM_GETBLOCKSTATS_PERCENTILES = 5;

/**
 * Get the difficulty of the net wrt to the given block index.
 *
 * @return A floating point number that is a multiple of the main net minimum
 * difficulty (4295032833 hashes).
 */
double GetDifficulty(const CBlockIndex& blockindex);

/** Block description to JSON */
UniValue blockToJSON(node::BlockManager& blockman, const CBlock& block, const CBlockIndex& tip, const CBlockIndex& blockindex, TxVerbosity verbosity, const uint256 pow_limit) LOCKS_EXCLUDED(cs_main);

/** Block header to JSON */
UniValue blockheaderToJSON(const CBlockIndex& tip, const CBlockIndex& blockindex, const uint256 pow_limit) LOCKS_EXCLUDED(cs_main);

/** Used by getblockstats to get feerates at different percentiles by weight  */
void CalculatePercentilesByWeight(CAmount result[NUM_GETBLOCKSTATS_PERCENTILES], std::vector<std::pair<CAmount, int64_t>>& scores, int64_t total_weight);

/**
 * Test-only helper to create UTXO snapshots given a chainstate and a file handle.
 * @return a UniValue map containing metadata about the snapshot.
 */
UniValue CreateUTXOSnapshot(
    node::NodeContext& node,
    Chainstate& chainstate,
    AutoFile&& afile,
    const fs::path& path,
    const fs::path& tmppath);

//! Return height of highest block that has been pruned, or std::nullopt if no blocks have been pruned
std::optional<int> GetPruneHeight(const node::BlockManager& blockman, const CChain& chain) EXCLUSIVE_LOCKS_REQUIRED(::cs_main);
void CheckBlockDataAvailability(node::BlockManager& blockman, const CBlockIndex& blockindex, bool check_for_undo) EXCLUSIVE_LOCKS_REQUIRED(::cs_main);

#endif // BITCOIN_RPC_BLOCKCHAIN_H
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