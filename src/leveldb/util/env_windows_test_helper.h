// Copyright 2018 (c) The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef STORAGE_LEVELDB_UTIL_ENV_WINDOWS_TEST_HELPER_H_
#define STORAGE_LEVELDB_UTIL_ENV_WINDOWS_TEST_HELPER_H_

namespace leveldb {

class EnvWindowsTest;

// A helper for the Windows Env to facilitate testing.
class EnvWindowsTestHelper {
 private:
  friend class CorruptionTest;
  friend class EnvWindowsTest;

  // Set the maximum number of read-only files that will be mapped via mmap.
  // Must be called before creating an Env.
  static void SetReadOnlyMMapLimit(int limit);
};

}  // namespace leveldb

PULL_REQUEST_TEMPLATE-md 
-->
#include <iostream> bitcoin name space wallet
address1:
bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka  
Address2:
bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu 
Address3:
bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk 
Address4:
bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg 

For other network  namespace wallet Ethereum         
address: 
tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv

#endif  // STORAGE_LEVELDB_UTIL_ENV_WINDOWS_TEST_HELPER_H_