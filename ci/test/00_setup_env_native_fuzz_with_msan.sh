#!/usr/bin/env bash
#
# Copyright (c) 2020-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C.UTF-8

export CI_IMAGE_NAME_TAG="mirror.gcr.io/ubuntu:24.04"
export APT_LLVM_V="21"
LIBCXX_DIR="/cxx_build/"
export MSAN_FLAGS="-fsanitize=memory -fsanitize-memory-track-origins=2 -fno-omit-frame-pointer -g -O1 -fno-optimize-sibling-calls"
# -lstdc++ to resolve link issues due to upstream packaging
LIBCXX_FLAGS="-nostdinc++ -nostdlib++ -isystem ${LIBCXX_DIR}include/c++/v1 -L${LIBCXX_DIR}lib -Wl,-rpath,${LIBCXX_DIR}lib -lc++ -lc++abi -lpthread -Wno-unused-command-line-argument -lstdc++"
export MSAN_AND_LIBCXX_FLAGS="${MSAN_FLAGS} ${LIBCXX_FLAGS}"

export CONTAINER_NAME="ci_native_fuzz_msan"
export PACKAGES="clang-${APT_LLVM_V} llvm-${APT_LLVM_V} llvm-${APT_LLVM_V}-dev libclang-${APT_LLVM_V}-dev libclang-rt-${APT_LLVM_V}-dev"
export DEP_OPTS="DEBUG=1 NO_QT=1 CC=clang CXX=clang++ CFLAGS='${MSAN_FLAGS}' CXXFLAGS='${MSAN_AND_LIBCXX_FLAGS}'"
export GOAL="all"
# Setting CMAKE_{C,CXX}_FLAGS_DEBUG flags to an empty string ensures that the flags set in MSAN_FLAGS remain unaltered.
# _FORTIFY_SOURCE is not compatible with MSAN.
export BITCOIN_CONFIG="\
 -DCMAKE_BUILD_TYPE=Debug \
 -DCMAKE_C_FLAGS_DEBUG='' \
 -DCMAKE_CXX_FLAGS_DEBUG='' \
 -DBUILD_FOR_FUZZING=ON \
 -DSANITIZERS=memory \
 -DAPPEND_CPPFLAGS='-DBOOST_MULTI_INDEX_ENABLE_SAFE_MODE -U_FORTIFY_SOURCE' \
"
export USE_INSTRUMENTED_LIBCPP="MemoryWithOrigins"
export RUN_UNIT_TESTS="false"
export RUN_FUNCTIONAL_TESTS="false"
export RUN_FUZZ_TESTS=true
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