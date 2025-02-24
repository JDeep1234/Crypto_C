#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    // Mallory's (MITM) private key
    int m = 10;

    // Public keys
    long long A = mod_pow(g, a, p);
    long long B = mod_pow(g, b, p);

    // Mallory intercepts and replaces keys
    long long M_to_B = mod_pow(g, m, p);
    long long M_to_A = mod_pow(g, m, p);

    // Shared secrets (compromised)
    long long alice_secret = mod_pow(M_to_B, a, p);
    long long bob_secret = mod_pow(M_to_A, b, p);
    long long mallory_secret_A = mod_pow(A, m, p);
    long long mallory_secret_B = mod_pow(B, m, p);

    printf("MITM Attack Simulation\n");
    printf("Alice's Public Key: %lld\n", A);
    printf("Bob's Public Key: %lld\n", B);
    printf("Mallory's Intercepted Key to Alice: %lld\n", M_to_A);
    printf("Mallory's Intercepted Key to Bob: %lld\n", M_to_B);
    printf("Alice's Compromised Secret: %lld\n", alice_secret);
    printf("Bob's Compromised Secret: %lld\n", bob_secret);

    return 0;
}
