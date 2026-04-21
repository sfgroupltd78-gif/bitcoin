#!/usr/bin/env bash
#
# Copyright (c) 2023-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C.UTF-8

export CI_IMAGE_NAME_TAG="mirror.gcr.io/ubuntu:24.04"
export CONTAINER_NAME=ci_native_tidy
export TIDY_LLVM_V="21"
export APT_LLVM_V="${TIDY_LLVM_V}"
export PACKAGES="clang-${TIDY_LLVM_V} libclang-${TIDY_LLVM_V}-dev llvm-${TIDY_LLVM_V}-dev libomp-${TIDY_LLVM_V}-dev clang-tidy-${TIDY_LLVM_V} jq libevent-dev libboost-dev libzmq3-dev systemtap-sdt-dev qt6-base-dev qt6-tools-dev qt6-l10n-tools libqrencode-dev libsqlite3-dev libcapnp-dev capnproto"
export NO_DEPENDS=1
export RUN_UNIT_TESTS=false
export RUN_FUNCTIONAL_TESTS=false
export RUN_FUZZ_TESTS=false
export RUN_CHECK_DEPS=true
export RUN_TIDY=true
export GOAL="install"
export BITCOIN_CONFIG="\
 --preset dev-mode \
 -DCMAKE_C_COMPILER=clang-${TIDY_LLVM_V} \
 -DCMAKE_CXX_COMPILER=clang++-${TIDY_LLVM_V} \
 -DCMAKE_C_FLAGS_RELWITHDEBINFO='-O0 -g0' \
 -DCMAKE_CXX_FLAGS_RELWITHDEBINFO='-O0 -g0' \
"
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