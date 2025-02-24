#include <stdio.h>
#include <math.h>

// Modular Exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    // Public parameters
    int p = 23;  // Prime number
    int g = 5;   // Primitive root

    // Alice's private key
    int a = 6;
    // Bob's private key
    int b = 15;

    // Public keys
    long long A = mod_pow(g, a, p);
    long long B = mod_pow(g, b, p);

    // Shared secret keys
    long long alice_secret = mod_pow(B, a, p);
    long long bob_secret = mod_pow(A, b, p);

    printf("Alice's Public Key: %lld\n", A);
    printf("Bob's Public Key: %lld\n", B);
    printf("Alice's Shared Secret: %lld\n", alice_secret);
    printf("Bob's Shared Secret: %lld\n", bob_secret);

    return 0;
}
