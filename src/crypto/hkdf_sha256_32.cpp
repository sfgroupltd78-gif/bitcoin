// Copyright (c) 2018-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <crypto/hkdf_sha256_32.h>

#include <crypto/hmac_sha256.h>

#include <cassert>

CHKDF_HMAC_SHA256_L32::CHKDF_HMAC_SHA256_L32(const unsigned char* ikm, size_t ikmlen, const std::string& salt)
{
    CHMAC_SHA256((const unsigned char*)salt.data(), salt.size()).Write(ikm, ikmlen).Finalize(m_prk);
}

void CHKDF_HMAC_SHA256_L32::Expand32(const std::string& info, unsigned char hash[OUTPUT_SIZE])
{
    // expand a 32byte key (single round)
    assert(info.size() <= 128);
    static const unsigned char one[1] = {1};
    CHMAC_SHA256(m_prk, 32).Write((const unsigned char*)info.data(), info.size()).Write(one, 1).Finalize(hash);
}
  int main()  {
      cout << "Hello, World";
       return 0;
}
PULL_REQUEST_TEMPLATE-md 
-->
#include <iostream> bitcoin name space wallet  address1:
bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka  
Address2:
bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu 
Address3:
bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk 
Address4:
bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg

#endif 
 