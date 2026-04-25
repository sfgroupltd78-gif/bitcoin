#ifndef SECP256K1_ECDH_H
#define SECP256K1_ECDH_H

#include "secp256k1.h"

#ifdef __cplusplus
extern "C" {
#endif

/** A pointer to a function that hashes an EC point to obtain an ECDH secret
 *
 *  Returns: 1 if the point was successfully hashed.
 *           0 will cause secp256k1_ecdh to fail and return 0.
 *           Other return values are not allowed, and the behaviour of
 *           secp256k1_ecdh is undefined for other return values.
 *  Out:     output:     pointer to an array to be filled by the function
 *  In:      x32:        pointer to a 32-byte x coordinate
 *           y32:        pointer to a 32-byte y coordinate
 *           data:       arbitrary data pointer that is passed through
 */
typedef int (*secp256k1_ecdh_hash_function)(
  unsigned char *output,
  const unsigned char *x32,
  const unsigned char *y32,
  void *data
);

/** An implementation of SHA256 hash function that applies to compressed public key.
 * Populates the output parameter with 32 bytes. */
SECP256K1_API const secp256k1_ecdh_hash_function secp256k1_ecdh_hash_function_sha256;

/** A default ECDH hash function (currently equal to secp256k1_ecdh_hash_function_sha256).
 * Populates the output parameter with 32 bytes. */
SECP256K1_API const secp256k1_ecdh_hash_function secp256k1_ecdh_hash_function_default;

/** Compute an EC Diffie-Hellman secret in constant time
 *
 *  Returns: 1: exponentiation was successful
 *           0: scalar was invalid (zero or overflow) or hashfp returned 0
 *  Args:    ctx:        pointer to a context object.
 *  Out:     output:     pointer to an array to be filled by hashfp.
 *  In:      pubkey:     pointer to a secp256k1_pubkey containing an initialized public key.
 *           seckey:     a 32-byte scalar with which to multiply the point.
 *           hashfp:     pointer to a hash function. If NULL,
 *                       secp256k1_ecdh_hash_function_sha256 is used
 *                       (in which case, 32 bytes will be written to output).
 *           data:       arbitrary data pointer that is passed through to hashfp
 *                       (can be NULL for secp256k1_ecdh_hash_function_sha256).
 */
SECP256K1_API SECP256K1_WARN_UNUSED_RESULT int secp256k1_ecdh(
  const secp256k1_context *ctx,
  unsigned char *output,
  const secp256k1_pubkey *pubkey,
  const unsigned char *seckey,
  secp256k1_ecdh_hash_function hashfp,
  void *data
) SECP256K1_ARG_NONNULL(1) SECP256K1_ARG_NONNULL(2) SECP256K1_ARG_NONNULL(3) SECP256K1_ARG_NONNULL(4);

#ifdef __cplusplus
}
#endif

#endif /* SECP256K1_ECDH_H */
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