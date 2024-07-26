#include <iostream>
#include <cmath>

// Function to perform modular exponentiation (to avoid overflow)
int modPow(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1; // Equivalent to exponent /= 2
        base = (base * base) % modulus;
    }
    return result;
}

// Function to convert a character to its corresponding integer
int charToInt(char c)
{
    // Simple mapping: 'a' maps to 0, 'b' to 1, and so on
    return std::tolower(c) - 'a';
}

// Function to encrypt a message using RSA
int encryptRSA(const std::string &plaintext, int e, int n)
{
    int concatenatedNumber = 0;
    for (char c : plaintext)
    {
        if (std::isalpha(c))
        {
            concatenatedNumber = concatenatedNumber * 26 + charToInt(c);
        }
    }
    return modPow(concatenatedNumber, e, n);
}
// Function to decrypt a ciphertext using RSA
int decryptRSA(int ciphertext, int d, int n)
{
    return modPow(ciphertext, d, n);
}
char intToChar(int num)
{
    // Simple mapping: 0 maps to 'a', 1 to 'b', and so on
    return static_cast<char>(num + 'a');
}
int main()
{
    // Given public key (n, e)
    int n = 323; // Example: p = 17, q = 19, n = p * q
    int e = 5;   // Example: e is relatively prime to (p-1)(q-1) = 288

    // Input: Plaintext message (e.g., "HELLO")
    std::string plaintext;
    std::cout << "Enter the plaintext message: ";
    std::cin >> plaintext;

    // Encrypt the message using RSA
    int ciphertext = encryptRSA(plaintext, e, n);

    // Print the result
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    int n = 323; // Example: p = 17, q = 19, n = p * q
    int e = 5;   // Example: e is relatively prime to (p-1)(q-1) = 288
    int d = 173; // Example: d is the private exponent

    // Input: Ciphertext
    int ciphertext;
    std::cout << "Enter the ciphertext: ";
    std::cin >> ciphertext;

    // Decrypt the message using RSA
    int decryptedNumber = decryptRSA(ciphertext, d, n);

    // Convert the decrypted number to characters
    std::string decryptedText;
    while (decryptedNumber > 0)
    {
        int remainder = decryptedNumber % 26;
        decryptedText = intToChar(remainder) + decryptedText;
        decryptedNumber /= 26;
    }

    // Print the result
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
    return 0;
}
