#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Efficient Modular Exponentiation: (base^exp) % mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 != 0)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Get random number in range (1, max-1)
long long get_random(long long max) {
    return (rand() % (max - 2)) + 2;
}

int main() {
    srand(time(NULL));
    long long p, g;

    // Step 1: Initialization
    printf("Enter a prime number p (recommend small like 467 for demo): ");
    scanf("%lld", &p);

    printf("Enter a generator g (primitive root modulo p): ");
    scanf("%lld", &g);

    // Step 2: Key Generation
    long long xA = get_random(p); // Private key A
    long long yA = mod_pow(g, xA, p); // Public key A

    long long xB = get_random(p); // Private key B
    long long yB = mod_pow(g, xB, p); // Public key B

    printf("\n[Party A] Private key xA: %lld, Public key yA: %lld\n", xA, yA);
    printf("[Party B] Private key xB: %lld, Public key yB: %lld\n", xB, yB);

    // Step 3: Party A -> Party B
    long long k = get_random(p); // Ephemeral key
    long long c1 = mod_pow(g, k, p); // Send to B
    long long sharedA = mod_pow(yB, k, p); // Shared secret

    printf("\n[Party A] Chose ephemeral key k = %lld\n", k);
    printf("[Party A] Sent c1 = %lld to Party B\n", c1);
    printf("[Party A] Computed shared secret = %lld\n", sharedA);

    // Step 4: Party B receives c1 and computes shared secret
    long long sharedB = mod_pow(c1, xB, p);

    printf("\n[Party B] Received c1 = %lld\n", c1);
    printf("[Party B] Computed shared secret = %lld\n", sharedB);

    // Step 5: Verification
    if (sharedA == sharedB) {
        printf("\ Key exchange successful! Shared secret = %lld\n", sharedA);
    } else {
        printf("\n Key mismatch! Something went wrong.\n");
    }

    return 0;
}
