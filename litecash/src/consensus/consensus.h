// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CONSENSUS_CONSENSUS_H
#define BITCOIN_CONSENSUS_CONSENSUS_H

#include <stdint.h>


static const uint64_t LCH_FORK_BLOCK_NUM = 1338540;
/** 1MB */
static const uint64_t ONE_MEGABYTE = 1000000;
/** The maximum allowed size for a transaction, in bytes */
static const uint64_t MAX_TX_SIZE = ONE_MEGABYTE;
/** The maximum allowed size for a block, before the UAHF */
static const uint64_t LEGACY_MAX_BLOCK_SIZE = ONE_MEGABYTE;
/** Default setting for maximum allowed size for a block, in bytes */
static const uint64_t DEFAULT_MAX_BLOCK_SIZE = 8 * ONE_MEGABYTE;
/** The maximum allowed number of signature check operations per MB in a block
 * (network rule) */
static const int64_t MAX_BLOCK_SIGOPS_PER_MB = 20000;
/** allowed number of signature check operations per transaction. */
static const uint64_t MAX_TX_SIGOPS_COUNT = 20000;

/** Timestamp at which the UAHF starts. */
//static const uint64_t DEFAULT_UAHF_START_TIME = 1501590000;




/** The maximum allowed size for a serialized block, in bytes (only for buffer size limits) */
static const unsigned int MAX_BLOCK_SERIALIZED_SIZE = 32000000;
/** The maximum allowed weight for a block, see BIP 141 (network rule) */
static const unsigned int MAX_BLOCK_WEIGHT = 4000000;
/** The maximum allowed size for a block excluding witness data, in bytes (network rule) */
static const unsigned int MAX_BLOCK_BASE_SIZE = 8 * ONE_MEGABYTE;

/** The maximum allowed number of signature check operations in a block (network rule) */
static const int64_t MAX_BLOCK_SIGOPS_COST = 80000;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int COINBASE_MATURITY = 100;

/** Flags for nSequence and nLockTime locks */
enum {
    /* Interpret sequence numbers as relative lock-time constraints. */
    LOCKTIME_VERIFY_SEQUENCE = (1 << 0),

    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST = (1 << 1),
};
/**
 * Compute the maximum number of sigops operation that can contained in a block
 * given the block size as parameter. It is computed by multiplying
 * MAX_BLOCK_SIGOPS_PER_MB by the size of the block in MB rounded up to the
 * closest integer.
 */
inline uint64_t GetMaxBlockSigOpsCount(uint64_t blockSize) {
    auto nMbRoundedUp = 1 + ((blockSize - 1) / ONE_MEGABYTE);
    return nMbRoundedUp * MAX_BLOCK_SIGOPS_PER_MB;
}

#endif // BITCOIN_CONSENSUS_CONSENSUS_H