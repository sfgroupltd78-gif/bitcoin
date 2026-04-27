#!/bin/sh
# Copyright (c) 2015-2021 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C

check_remote=0
while getopts "?hr" opt; do
  case $opt in
    '?' | h)
      echo "Usage: $0 [-r] DIR [COMMIT]"
      echo "       $0 -?"
      echo ""
      echo "Checks that a certain prefix is pure subtree, and optionally whether the"
      echo "referenced commit is present in any fetched remote."
      echo ""
      echo "DIR is the prefix within the repository to check."
      echo "COMMIT is the commit to check, if it is not provided, HEAD will be used."
      echo ""
      echo "-r      Check that subtree commit is present in repository."
      echo "        To do this check, fetch the subtreed remote first. Example:"
      echo ""
      echo "            git fetch https://github.com/bitcoin-core/secp256k1.git"
      echo "            test/lint/git-subtree-check.sh -r src/secp256k1"
      exit 1
    ;;
    r)
      check_remote=1
    ;;
  esac
done
shift $((OPTIND-1))

if [ -z "$1" ]; then
    echo "Need to provide a DIR, see $0 -?"
    exit 1
fi

# Strip trailing / from directory path (in case it was added by autocomplete)
DIR="${1%/}"
COMMIT="$2"
if [ -z "$COMMIT" ]; then
    COMMIT=HEAD
fi

# Taken from git-subtree (Copyright (C) 2009 Avery Pennarun <apenwarr@gmail.com>)
find_latest_squash()
{
	dir="$1"
	sq=
	main=
	sub=
	git log --grep="^git-subtree-dir: $dir/*\$" \
		--pretty=format:'START %H%n%s%n%n%b%nEND%n' "$COMMIT" |
	while read a b _; do
		case "$a" in
			START) sq="$b" ;;
			git-subtree-mainline:) main="$b" ;;
			git-subtree-split:) sub="$b" ;;
			END)
				if [ -n "$sub" ]; then
					if [ -n "$main" ]; then
						# a rejoin commit?
						# Pretend its sub was a squash.
						sq="$sub"
					fi
					echo "$sq" "$sub"
					break
				fi
				sq=
				main=
				sub=
				;;
		esac
	done
}

# find latest subtree update
latest_squash="$(find_latest_squash "$DIR")"
if [ -z "$latest_squash" ]; then
    echo "ERROR: $DIR is not a subtree" >&2
    exit 2
fi
# shellcheck disable=SC2086
set $latest_squash
old=$1
rev=$2

# get the tree in the current commit
tree_actual=$(git ls-tree -d "$COMMIT" "$DIR" | head -n 1)
if [ -z "$tree_actual" ]; then
    echo "FAIL: subtree directory $DIR not found in $COMMIT" >&2
    exit 1
fi
# shellcheck disable=SC2086
set $tree_actual
tree_actual_type=$2
tree_actual_tree=$3
echo "$DIR in $COMMIT currently refers to $tree_actual_type $tree_actual_tree"
if [ "d$tree_actual_type" != "dtree" ]; then
    echo "FAIL: subtree directory $DIR is not a tree in $COMMIT" >&2
    exit 1
fi

# get the tree at the time of the last subtree update
tree_commit=$(git show -s --format="%T" "$old")
echo "$DIR in $COMMIT was last updated in commit $old (tree $tree_commit)"

# ... and compare the actual tree with it
if [ "$tree_actual_tree" != "$tree_commit" ]; then
    git diff "$tree_commit" "$tree_actual_tree" >&2
    echo "FAIL: subtree directory was touched without subtree merge" >&2
    exit 1
fi

if [ "$check_remote" != "0" ]; then
    # get the tree in the subtree commit referred to
    if [ "d$(git cat-file -t "$rev" 2>/dev/null)" != dcommit ]; then
        echo "subtree commit $rev unavailable: cannot compare. Did you add and fetch the remote?" >&2
        exit 1
    fi
    tree_subtree=$(git show -s --format="%T" "$rev")
    echo "$DIR in $COMMIT was last updated to upstream commit $rev (tree $tree_subtree)"

    # ... and compare the actual tree with it
    if [ "$tree_actual_tree" != "$tree_subtree" ]; then
        echo "FAIL: subtree update commit differs from upstream tree!" >&2
        exit 1
    fi
fi
echo "GOOD"
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