#!/usr/bin/env bash
#
# Copyright (c) 2019-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C.UTF-8

export CONTAINER_NAME="ci_mac_native"  # macos does not use a container, but the env var is needed for logging
export PIP_PACKAGES="--break-system-packages pycapnp zmq"
export GOAL="install deploy"
export CMAKE_GENERATOR="Ninja"
export BITCOIN_CONFIG="-DBUILD_GUI=ON -DWITH_ZMQ=ON -DBUILD_KERNEL_LIB=ON -DBUILD_UTIL_CHAINSTATE=ON -DBUILD_KERNEL_TEST=ON -DREDUCE_EXPORTS=ON -DCMAKE_EXE_LINKER_FLAGS='-Wl,-stack_size -Wl,0x80000'"
export CI_OS_NAME="macos"
export NO_DEPENDS=1
export OSX_SDK=""
export BITCOIN_CMD="bitcoin -m" # Used in functional tests
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