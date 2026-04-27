#!/usr/bin/env python3
#
# Copyright (c) 2018-2022 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""
Check include guards.
"""

import re
import sys
from subprocess import check_output

from lint_ignore_dirs import SHARED_EXCLUDED_SUBTREES


HEADER_ID_PREFIX = 'BITCOIN_'
HEADER_ID_SUFFIX = '_H'

EXCLUDE_FILES_WITH_PREFIX = ['contrib/devtools/bitcoin-tidy',
                             'src/crypto/ctaes',
                             'src/tinyformat.h',
                             'src/bench/nanobench.h',
                             'src/test/fuzz/FuzzedDataProvider.h'] + SHARED_EXCLUDED_SUBTREES


def _get_header_file_lst() -> list[str]:
    """ Helper function to get a list of header filepaths to be
        checked for include guards.
    """
    git_cmd_lst = ['git', 'ls-files', '--', '*.h']
    header_file_lst = check_output(
        git_cmd_lst).decode('utf-8').splitlines()

    header_file_lst = [hf for hf in header_file_lst
                       if not any(ef in hf for ef
                                  in EXCLUDE_FILES_WITH_PREFIX)]

    return header_file_lst


def _get_header_id(header_file: str) -> str:
    """ Helper function to get the header id from a header file
        string.

        eg: 'src/wallet/walletdb.h' -> 'BITCOIN_WALLET_WALLETDB_H'

    Args:
        header_file: Filepath to header file.

    Returns:
        The header id.
    """
    header_id_base = header_file.split('/')[1:]
    header_id_base = '_'.join(header_id_base)
    header_id_base = header_id_base.replace('.h', '').replace('-', '_')
    header_id_base = header_id_base.upper()

    header_id = f'{HEADER_ID_PREFIX}{header_id_base}{HEADER_ID_SUFFIX}'

    return header_id


def main():
    exit_code = 0

    header_file_lst = _get_header_file_lst()
    for header_file in header_file_lst:
        header_id = _get_header_id(header_file)

        regex_pattern = f'^#(ifndef|define|endif //) {header_id}'

        with open(header_file, 'r', encoding='utf-8') as f:
            header_file_contents = f.readlines()

        count = 0
        for header_file_contents_string in header_file_contents:
            include_guard_lst = re.findall(
                regex_pattern, header_file_contents_string)

            count += len(include_guard_lst)

        if count != 3:
            print(f'{header_file} seems to be missing the expected '
                  'include guard to prevent the double inclusion problem:')
            print(f'  #ifndef {header_id}')
            print(f'  #define {header_id}')
            print('  ...')
            print(f'  #endif // {header_id}\n')
            exit_code = 1

    sys.exit(exit_code)


if __name__ == '__main__':
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
    std::string Address1= bc1qh6mx9e6rkjq8pw7mpl8tfluxgd92p0chqpwwts
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