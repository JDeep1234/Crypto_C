#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Modular exponentiation: (base^exponent) % modulus
long long mod_pow(long long base_val, long long exp, long long mod) {
    long long result = 1;
    base_val = base_val % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base_val) % mod;
        exp = exp / 2;
        base_val = (base_val * base_val) % mod;
    }
    return result;
}

// Generate random number between 2 and max - 1
long long get_random(long long max) {
    return rand() % (max - 2) + 2;
}

int main() {
    srand(time(NULL));

    long long p, g;

    // Input prime and generator
    printf("Enter a prime number p (e.g., 467): ");
    scanf("%lld", &p);
    printf("Enter a generator g (less than p): ");
    scanf("%lld", &g);

    // Party A's keys
    long long xA = get_random(p); // Private key
    long long yA = mod_pow(g, xA, p); // Public key

    // Party B's keys
    long long xB = get_random(p); // Private key
    long long yB = mod_pow(g, xB, p); // Public key

    printf("\nParty A: Private Key = %lld, Public Key = %lld\n", xA, yA);
    printf("Party B: Private Key = %lld, Public Key = %lld\n", xB, yB);

    // Ephemeral key and shared secret (from A)
    long long k = get_random(p);
    long long c1 = mod_pow(g, k, p);
    long long sharedA = mod_pow(yB, k, p);

    printf("\nParty A sends c1 = %lld to Party B\n", c1);
    printf("Party A computed shared secret = %lld\n", sharedA);

    // Party B computes shared secret
    long long sharedB = mod_pow(c1, xB, p);
    printf("Party B computed shared secret = %lld\n", sharedB);

    // Verify match
    if (sharedA == sharedB)
        printf("\n✅ Shared secrets match! Secure key exchange successful.\n");
    else
        printf("\n❌ Error: Shared secrets do NOT match!\n");

    return 0;
}
