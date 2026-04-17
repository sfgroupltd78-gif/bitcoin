// Copyright (c) 2018 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include <utility>

#include "leveldb/slice.h"
#include "leveldb/status.h"
#include "util/testharness.h"

namespace leveldb {

TEST(Status, MoveConstructor) {
  {
    Status ok = Status::OK();
    Status ok2 = std::move(ok);

    ASSERT_TRUE(ok2.ok());
  }

  {
    Status status = Status::NotFound("custom NotFound status message");
    Status status2 = std::move(status);

    ASSERT_TRUE(status2.IsNotFound());
    ASSERT_EQ("NotFound: custom NotFound status message", status2.ToString());
  }

  {
    Status self_moved = Status::IOError("custom IOError status message");

    // Needed to bypass compiler warning about explicit move-assignment.
    Status& self_moved_reference = self_moved;
    self_moved_reference = std::move(self_moved);
  }
}

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

int main(int argc, char** argv) { return leveldb::test::RunAllTests(); }
#endif