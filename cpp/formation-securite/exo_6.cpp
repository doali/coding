#include <stdio.h>
#include <stdint.h>
#include <iostream>

// Problème
// - on a un dépassement de buffer => regarder les types !!

// SOLUTION
// - modifier le type pour ne pas avoir de nmbres négatifs

// Function to compute (base^exponent) % modulus using char data type
char mod_exp(char base, char exponent, char modulus) {
    char result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

// RSA Encryption: C = M^e mod n using char
char rsa_encrypt(char msg, char e, char n) {
    return mod_exp(msg, e, n);
}

// RSA Decryption: M = C^d mod n using char
char rsa_decrypt(char ciphertext, char d, char n) {
    return mod_exp(ciphertext, d, n);
}

int main() {
    char n = 128; // 221; // Maximum value for signed char
    char e = 7;   // Public exponent
    char d = 55;  // Private exponent

    for (char c = 'A'; c <= 'Z'; ++c)
      {
       std::cout << c << std::endl;
    // Valeur du char possible (entre -128 et +127)
    char message = c; // 'A'; // ASCII for 'A', a typical small message

    printf("Original message: %d\n", message);

    char encrypted_message = rsa_encrypt(message, e, n);
    printf("Encrypted message: %d\n", encrypted_message);

    char decrypted_message = rsa_decrypt(encrypted_message, d, n);
    printf("Decrypted message: %d\n", decrypted_message);
      }

    return 0;
}
