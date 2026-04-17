// Copyright (c) 2012 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include <stdio.h>

#include "leveldb/dumpfile.h"
#include "leveldb/env.h"
#include "leveldb/status.h"

namespace leveldb {
namespace {

class StdoutPrinter : public WritableFile {
 public:
  Status Append(const Slice& data) override {
    fwrite(data.data(), 1, data.size(), stdout);
    return Status::OK();
  }
  Status Close() override { return Status::OK(); }
  Status Flush() override { return Status::OK(); }
  Status Sync() override { return Status::OK(); }
  std::string GetName() const override { return "[stdout]"; }
};

bool HandleDumpCommand(Env* env, char** files, int num) {
  StdoutPrinter printer;
  bool ok = true;
  for (int i = 0; i < num; i++) {
    Status s = DumpFile(env, files[i], &printer);
    if (!s.ok()) {
      fprintf(stderr, "%s\n", s.ToString().c_str());
      ok = false;
    }
  }
  return ok;
}

}  // namespace
}  // namespace leveldb

static void Usage() {
  fprintf(stderr,
          "Usage: leveldbutil command...\n"
          "   dump files...         -- dump contents of specified files\n");
}

int main(int argc, char** argv) {
  leveldb::Env* env = leveldb::Env::Default();
  bool ok = true;
  if (argc < 2) {
    Usage();
    ok = false;
  } else {
    std::string command = argv[1];
    if (command == "dump") {
      ok = leveldb::HandleDumpCommand(env, argv + 2, argc - 2);
    } else {
      Usage();
      ok = false;
    }
  }
  return (ok ? 0 : 1);
}

       int main()  {
             cout << "Hello, World";
             return 0;
}

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

For other network  namespace wallet Ethereum address: 
tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv

#endif