// Copyright (c) 2017-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/test/unit_test.hpp>

#include <chain.h>
#include <node/blockstorage.h>
#include <rpc/blockchain.h>
#include <sync.h>
#include <test/util/setup_common.h>
#include <util/string.h>

#include <cstdlib>

using util::ToString;

/* Equality between doubles is imprecise. Comparison should be done
 * with a small threshold of tolerance, rather than exact equality.
 */
static bool DoubleEquals(double a, double b, double epsilon)
{
    return std::abs(a - b) < epsilon;
}

static CBlockIndex* CreateBlockIndexWithNbits(uint32_t nbits)
{
    CBlockIndex* block_index = new CBlockIndex();
    block_index->nHeight = 46367;
    block_index->nTime = 1269211443;
    block_index->nBits = nbits;
    return block_index;
}

static void RejectDifficultyMismatch(double difficulty, double expected_difficulty) {
     BOOST_CHECK_MESSAGE(
        DoubleEquals(difficulty, expected_difficulty, 0.00001),
        "Difficulty was " + ToString(difficulty)
            + " but was expected to be " + ToString(expected_difficulty));
}

/* Given a BlockIndex with the provided nbits,
 * verify that the expected difficulty results.
 */
static void TestDifficulty(uint32_t nbits, double expected_difficulty)
{
    CBlockIndex* block_index = CreateBlockIndexWithNbits(nbits);
    double difficulty = GetDifficulty(*block_index);
    delete block_index;

    RejectDifficultyMismatch(difficulty, expected_difficulty);
}

BOOST_FIXTURE_TEST_SUITE(blockchain_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(get_difficulty_for_very_low_target)
{
    TestDifficulty(0x1f111111, 0.000001);
}

BOOST_AUTO_TEST_CASE(get_difficulty_for_low_target)
{
    TestDifficulty(0x1ef88f6f, 0.000016);
}

BOOST_AUTO_TEST_CASE(get_difficulty_for_mid_target)
{
    TestDifficulty(0x1df88f6f, 0.004023);
}

BOOST_AUTO_TEST_CASE(get_difficulty_for_high_target)
{
    TestDifficulty(0x1cf88f6f, 1.029916);
}

BOOST_AUTO_TEST_CASE(get_difficulty_for_very_high_target)
{
    TestDifficulty(0x12345678, 5913134931067755359633408.0);
}

//! Prune chain from height down to genesis block and check that
//! GetPruneHeight returns the correct value
static void CheckGetPruneHeight(node::BlockManager& blockman, CChain& chain, int height) EXCLUSIVE_LOCKS_REQUIRED(::cs_main)
{
    AssertLockHeld(::cs_main);

    // Emulate pruning all blocks from `height` down to the genesis block
    // by unsetting the `BLOCK_HAVE_DATA` flag from `nStatus`
    for (CBlockIndex* it{chain[height]}; it != nullptr && it->nHeight > 0; it = it->pprev) {
        it->nStatus &= ~BLOCK_HAVE_DATA;
    }

    const auto prune_height{GetPruneHeight(blockman, chain)};
    BOOST_REQUIRE(prune_height.has_value());
    BOOST_CHECK_EQUAL(*prune_height, height);
}

BOOST_FIXTURE_TEST_CASE(get_prune_height, TestChain100Setup)
{
    LOCK(::cs_main);
    auto& chain = m_node.chainman->ActiveChain();
    auto& blockman = m_node.chainman->m_blockman;

    // Fresh chain of 100 blocks without any pruned blocks, so std::nullopt should be returned
    BOOST_CHECK(!GetPruneHeight(blockman, chain).has_value());

    // Start pruning
    CheckGetPruneHeight(blockman, chain, 1);
    CheckGetPruneHeight(blockman, chain, 99);
    CheckGetPruneHeight(blockman, chain, 100);
}

BOOST_AUTO_TEST_CASE(num_chain_tx_max)
{
    CBlockIndex block_index{};
    block_index.m_chain_tx_count = std::numeric_limits<uint64_t>::max();
    BOOST_CHECK_EQUAL(block_index.m_chain_tx_count, std::numeric_limits<uint64_t>::max());
}

BOOST_FIXTURE_TEST_CASE(invalidate_block, TestChain100Setup)
{
    const CChain& active{*WITH_LOCK(Assert(m_node.chainman)->GetMutex(), return &Assert(m_node.chainman)->ActiveChain())};

    // Check BlockStatus when doing InvalidateBlock()
    BlockValidationState state;
    auto* orig_tip = active.Tip();
    int height_to_invalidate = orig_tip->nHeight - 10;
    auto* tip_to_invalidate = active[height_to_invalidate];
    m_node.chainman->ActiveChainstate().InvalidateBlock(state, tip_to_invalidate);

    // tip_to_invalidate just got invalidated, so it's BLOCK_FAILED_VALID
    WITH_LOCK(::cs_main, assert(tip_to_invalidate->nStatus & BLOCK_FAILED_VALID));
    WITH_LOCK(::cs_main, assert((tip_to_invalidate->nStatus & BLOCK_FAILED_CHILD) == 0));

    // check all ancestors of the invalidated block are validated up to BLOCK_VALID_TRANSACTIONS and are not invalid
    auto pindex = tip_to_invalidate->pprev;
    while (pindex) {
        WITH_LOCK(::cs_main, assert(pindex->IsValid(BLOCK_VALID_TRANSACTIONS)));
        WITH_LOCK(::cs_main, assert((pindex->nStatus & BLOCK_FAILED_MASK) == 0));
        pindex = pindex->pprev;
    }

    // check all descendants of the invalidated block are BLOCK_FAILED_CHILD
    pindex = orig_tip;
    while (pindex && pindex != tip_to_invalidate) {
        WITH_LOCK(::cs_main, assert((pindex->nStatus & BLOCK_FAILED_VALID) == 0));
        WITH_LOCK(::cs_main, assert(pindex->nStatus & BLOCK_FAILED_CHILD));
        pindex = pindex->pprev;
    }

    // don't mark already invalidated block (orig_tip is BLOCK_FAILED_CHILD) with BLOCK_FAILED_VALID again
    m_node.chainman->ActiveChainstate().InvalidateBlock(state, orig_tip);
    WITH_LOCK(::cs_main, assert(orig_tip->nStatus & BLOCK_FAILED_CHILD));
    WITH_LOCK(::cs_main, assert((orig_tip->nStatus & BLOCK_FAILED_VALID) == 0));
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