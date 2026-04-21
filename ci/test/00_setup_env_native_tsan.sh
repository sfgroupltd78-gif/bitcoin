#!/usr/bin/env bash
#
# Copyright (c) 2019-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C.UTF-8

export CONTAINER_NAME=ci_native_tsan
export CI_IMAGE_NAME_TAG="mirror.gcr.io/ubuntu:24.04"
export APT_LLVM_V="21"
LIBCXX_DIR="/cxx_build/"
LIBCXX_FLAGS="-fsanitize=thread -nostdinc++ -nostdlib++ -isystem ${LIBCXX_DIR}include/c++/v1 -L${LIBCXX_DIR}lib -Wl,-rpath,${LIBCXX_DIR}lib -lc++ -lc++abi -lpthread -Wno-unused-command-line-argument"
export PACKAGES="clang-${APT_LLVM_V} llvm-${APT_LLVM_V} llvm-${APT_LLVM_V}-dev libclang-${APT_LLVM_V}-dev libclang-rt-${APT_LLVM_V}-dev python3-zmq python3-pip"
export PIP_PACKAGES="--break-system-packages pycapnp"
export DEP_OPTS="CC=clang CXX=clang++ CXXFLAGS='${LIBCXX_FLAGS}' NO_QT=1"
export GOAL="install"
export CI_LIMIT_STACK_SIZE=1
export BITCOIN_CONFIG="-DWITH_ZMQ=ON -DSANITIZERS=thread \
-DAPPEND_CPPFLAGS='-DARENA_DEBUG -DDEBUG_LOCKCONTENTION -D_LIBCPP_REMOVE_TRANSITIVE_INCLUDES'"
export USE_INSTRUMENTED_LIBCPP="Thread"
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