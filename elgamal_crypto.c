#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// (base^exp) % mod
long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

// Random number in range [2, p-2]
long long getRand(long long p) {
    return rand() % (p - 3) + 2;
}

int main() {
    srand(time(NULL));
    long long p, g;

    printf("Enter prime (p): ");
    scanf("%lld", &p);
    printf("Enter generator (g): ");
    scanf("%lld", &g);

    // Private and public keys
    long long a = getRand(p);         // A's private
    long long A_pub = modPow(g, a, p); // A's public

    long long b = getRand(p);         // B's private
    long long B_pub = modPow(g, b, p); // B's public

    printf("\nA: private = %lld, public = %lld\n", a, A_pub);
    printf("B: private = %lld, public = %lld\n", b, B_pub);

    // A sends encrypted message
    long long k = getRand(p);         // random session key
    long long c1 = modPow(g, k, p);   // part 1 of ciphertext
    long long shared_A = modPow(B_pub, k, p); // part 2 (shared key)

    printf("\nA sends c1 = %lld\n", c1);
    printf("A computes shared key = %lld\n", shared_A);

    // B receives c1 and computes shared key
    long long shared_B = modPow(c1, b, p);
    printf("B computes shared key = %lld\n", shared_B);

    if (shared_A == shared_B)
        printf("\n✅ Keys match! Secure key exchange successful.\n");
    else
        printf("\n❌ Keys do NOT match!\n");

    return 0;
}
