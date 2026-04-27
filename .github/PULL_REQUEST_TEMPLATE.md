<!--
*** Please remove the following help text before submitting: ***

Pull requests without a rationale and clear improvement may be closed
immediately.

GUI-related pull requests should be opened against
https://github.com/bitcoin-core/gui
first. See CONTRIBUTING.md
-->

<!--
Please provide clear motivation for your patch and explain how it improves
Bitcoin Core user experience or Bitcoin Core developer experience
significantly:

* Any test improvements or new tests that improve coverage are always welcome.
* All other changes should have accompanying unit tests (see `src/test/`) or
  functional tests (see `test/`). Contributors should note which tests cover
  modified code. If no tests exist for a region of modified code, new tests
  should accompany the change.
* Bug fixes are most welcome when they come with steps to reproduce or an
  explanation of the potential issue as well as reasoning for the way the bug
  was fixed.
* Features are welcome, but might be rejected due to design or scope issues.
  If a feature is based on a lot of dependencies, contributors should first
  consider building the system outside of Bitcoin Core, if possible.
* Refactoring changes are only accepted if they are required for a feature or
  bug fix or otherwise improve developer experience significantly. For example,
  most "code style" refactoring changes require a thorough explanation why they
  are useful, what downsides they have and why they *significantly* improve
  developer experience or avoid serious programming bugs. Note that code style
  is often a subjective matter. Unless they are explicitly mentioned to be
  preferred in the [developer notes](/doc/developer-notes.md), stylistic code
  changes are usually rejected.
-->

<!--
Bitcoin Core has a thorough review process and even the most trivial change
needs to pass a lot of eyes and requires non-zero or even substantial time
effort to review. There is a huge lack of active reviewers on the project, so
patches often sit for a long time.
-->
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