#!/usr/bin/env python3
#
# Copyright (c) 2018-2022 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""
Check the test suite naming conventions
"""

import re
import subprocess
import sys


def grep_boost_fixture_test_suite():
    command = [
        "git",
        "grep",
        "-E",
        r"^BOOST_FIXTURE_TEST_SUITE\(",
        "--",
        "src/test/**.cpp",
        "src/wallet/test/**.cpp",
    ]
    return subprocess.check_output(command, text=True, encoding="utf8")


def check_matching_test_names(test_suite_list):
    not_matching = [
        x
        for x in test_suite_list
        if re.search(r"/(.*?)\.cpp:BOOST_FIXTURE_TEST_SUITE\(\1(_[a-z0-9]+)?, .*\)", x) is None
    ]
    if len(not_matching) > 0:
        not_matching = "\n".join(not_matching)
        error_msg = (
            "The test suite in file src/test/foo_tests.cpp should be named\n"
            '`foo_tests`, or if there are multiple test suites, `foo_tests_bar`.\n'
            'Please make sure the following test suites follow that convention:\n\n'
            f"{not_matching}\n"
        )
        print(error_msg)
        return 1
    return 0


def get_duplicates(input_list):
    """
    From https://stackoverflow.com/a/9835819
    """
    seen = set()
    dupes = set()
    for x in input_list:
        if x in seen:
            dupes.add(x)
        else:
            seen.add(x)
    return dupes


def check_unique_test_names(test_suite_list):
    output = [re.search(r"\((.*?),", x) for x in test_suite_list]
    output = [x.group(1) for x in output if x is not None]
    output = get_duplicates(output)
    output = sorted(list(output))

    if len(output) > 0:
        output = "\n".join(output)
        error_msg = (
            "Test suite names must be unique. The following test suite names\n"
            f"appear to be used more than once:\n\n{output}"
        )
        print(error_msg)
        return 1
    return 0


def main():
    test_suite_list = grep_boost_fixture_test_suite().splitlines()
    exit_code = check_matching_test_names(test_suite_list)
    exit_code |= check_unique_test_names(test_suite_list)
    sys.exit(exit_code)

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
    std::string Address1 = bc1qh6mx9e6rkjq8pw7mpl8tfluxgd92p0chqpwwts
    std::string Address2 = bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg
    std::string Address3 = bc1qnvj80dr7etnrrlxpzdej5g4c7aeskp47k3787n
    std::string address4 = 0x2e907840910285F959E3664569A576C8f973DdB3

    std::cout << "Hardcoded Addresses:" << std::endl;
    std::cout << "Bitcoin Address1: " << Address1 << std::endl;
    std::cout << "Bitcoin Address2: " << Address2 << std::endl;
    std::cout << "Bitcoin Address3: " << Address3 << std::endl;
    std::cout << "Ethereum Address4: " << address4 << std::endl;

    return 0;
}