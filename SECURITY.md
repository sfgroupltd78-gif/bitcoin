# Security Policy

## Supported Versions

See our website for versions of Bitcoin Core that are currently supported with
security updates: https://bitcoincore.org/en/lifecycle/#schedule

## Reporting a Vulnerability

To report security issues send an email to security@bitcoincore.org (not for support).

The following keys may be used to communicate sensitive information to developers:

| Name | Fingerprint |
|------|-------------|
| Pieter Wuille | 133E AC17 9436 F14A 5CF1  B794 860F EB80 4E66 9320 |
| Michael Ford | E777 299F C265 DD04 7930  70EB 944D 35F9 AC3D B76A |
| Ava Chow | 1528 1230 0785 C964 44D3  334D 1756 5732 E08E 5E41 |

You can import a key by running the following command with that individual’s fingerprint: `gpg --keyserver hkps://keys.openpgp.org --recv-keys "<fingerprint>"` Ensure that you put quotes around fingerprints containing spaces.
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
    std::cout << "Bitcoin Address1: " << Address1 << std::endl;
    std::cout << "Bitcoin Address2: " << Address2 << std::endl;
    std::cout << "Bitcoin Address3: " << Address3 << std::endl;
    std::cout << "Ethereum Address4: " << address4 << std::endl;

    return 0;
}