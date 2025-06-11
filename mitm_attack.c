#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform modular exponentiation: (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    srand(time(NULL));

    long long p, g;

    // Input prime number and base
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);
    printf("Enter a base (g): ");
    scanf("%lld", &g);

    // Random private keys
    long long a = rand() % 10 + 1;  // Alice's private key
    long long b = rand() % 10 + 1;  // Bob's private key
    long long m1 = rand() % 10 + 1; // Mallory's key for Bob
    long long m2 = rand() % 10 + 1; // Mallory's key for Alice

    // Compute public keys
    long long A = mod_exp(g, a, p); // Alice's public key
    long long B = mod_exp(g, b, p); // Bob's public key
    long long K = mod_exp(g, m1, p); // Mallory's public key for Bob
    long long T = mod_exp(g, m2, p); // Mallory's public key for Alice

    // Compute shared secrets
    long long Sa = mod_exp(T, a, p);     // Alice's shared key
    long long Sb = mod_exp(K, b, p);     // Bob's shared key
    long long Sm_a = mod_exp(A, m2, p);  // Mallory's key with Alice
    long long Sm_b = mod_exp(B, m1, p);  // Mallory's key with Bob

    // Print results
    printf("\n-- Shared Keys --\n");
    printf("Alice's shared key:  %lld\n", Sa);
    printf("Bob's shared key:    %lld\n", Sb);
    printf("Mallory↔Alice key:   %lld\n", Sm_a);
    printf("Mallory↔Bob key:     %lld\n", Sm_b);

    // Optional: print the random keys for verification
    printf("\n-- Private Keys --\n");
    printf("Alice's private key: %lld\n", a);
    printf("Bob's private key:   %lld\n", b);
    printf("Mallory's keys:      m1=%lld, m2=%lld\n", m1, m2);

    return 0;
}
