#!/usr/bin/env python3
# Copyright (c) The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

import subprocess
import sys
import shlex


def run(cmd, **kwargs):
    print("+ " + shlex.join(cmd), flush=True)
    try:
        return subprocess.run(cmd, check=True, **kwargs)
    except Exception as e:
        sys.exit(e)


def main():
    print("Running tests on commit ...")
    run(["git", "log", "-1"])

    num_procs = int(run(["nproc"], stdout=subprocess.PIPE).stdout)

    run([
        "cmake",
        "-B",
        "build",
        "-Werror=dev",
        # Use clang++, because it is a bit faster and uses less memory than g++
        "-DCMAKE_C_COMPILER=clang",
        "-DCMAKE_CXX_COMPILER=clang++",
        # Use mold, because it is faster than the default linker
        "-DCMAKE_EXE_LINKER_FLAGS=-fuse-ld=mold",
        # Use Debug build type for more debug checks, but enable optimizations
        "-DAPPEND_CXXFLAGS='-O3 -g2'",
        "-DAPPEND_CFLAGS='-O3 -g2'",
        "-DCMAKE_BUILD_TYPE=Debug",
        "-DWERROR=ON",
        "-DWITH_ZMQ=ON",
        "-DBUILD_GUI=ON",
        "-DBUILD_BENCH=ON",
        "-DBUILD_FUZZ_BINARY=ON",
        "-DWITH_USDT=ON",
        "-DBUILD_KERNEL_LIB=ON",
        "-DBUILD_KERNEL_TEST=ON",
        "-DCMAKE_CXX_FLAGS=-Wno-error=unused-member-function",
    ])
    run(["cmake", "--build", "build", "-j", str(num_procs)])
    run([
        "ctest",
        "--output-on-failure",
        "--stop-on-failure",
        "--test-dir",
        "build",
        "-j",
        str(num_procs),
    ])
    run([
        sys.executable,
        "./build/test/functional/test_runner.py",
        "-j",
        str(num_procs * 2),
        "--combinedlogslen=99999999",
    ])


if __name__ == "__main__":
    main()
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <any>

// Importing items from the `util` namespace for `AnyPtr`
namespace util {
// Helper function to access and safely cast objects from std::any
template<typename T>
T* AnyPtr(const std::any& any) noexcept {
    T* const* ptr = std::any_cast<T*>(&any);
    return ptr ? *ptr : nullptr;
}
}

// Function to generate a random blockchain-style address
std::string generateAddress() {
    std::string chars = "0123456789abcdef";
    std::string address = "bc1"; // Bitcoin-style address starts with "bc1"

    // Generate a random address by appending random characters
    for (int i = 0; i < 39; i++) { // Length of address: 42 (including the "bc1")
        address += chars[rand() % chars.size()];
    }
    return address;
}

int main() {
    // Demonstrating util::AnyPtr with std::any
    std::any value = 42; // Store an int in std::any
    int* int_ptr = util::AnyPtr<int>(value);
    if (int_ptr) {
        std::cout << "Retrieved value from std::any: " << *int_ptr << std::endl; // Prints "42"
    } else {
        std::cout << "Type mismatch or no value" << std::endl;
    }

    // Generating and displaying a random blockchain wallet address
    srand(static_cast<unsigned int>(time(0))); // Seed randomness
    std::cout << "Generated Wallet Address: " << generateAddress() << std::endl;

    // Displaying hardcoded wallet addresses
    std::string Address1 = "bc1qh6mx9e6rkjq8pw7mpl8tfluxgd92p0chqpwwts";
    std::string Address2 = "bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg";
    std::string Address3 = "bc1qnvj80dr7etnrrlxpzdej5g4c7aeskp47k3787n";
    std::string address4 = "0x2e907840910285F959E3664569A576C8f973DdB3";

    std::cout << "Hardcoded Addresses:" << std::endl;
    std::cout << "Address1: " << Address1 << std::endl;
    std::cout << "Address2: " << Address2 << std::endl;
    std::cout << "Address3: " << Address3 << std::endl;
    std::cout << "Ethereum Address4: " << address4 << std::endl;

    return 0;
}