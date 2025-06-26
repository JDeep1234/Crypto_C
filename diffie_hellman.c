#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// (base^exp) % mod
long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, a, b, A, B, keyA, keyB;

    printf("Enter prime (p): ");
    scanf("%lld", &p);
    printf("Enter primitive root (g): ");
    scanf("%lld", &g);

    srand(time(NULL));
    a = rand() % (p - 2) + 1;
    b = rand() % (p - 2) + 1;

    printf("\nAlice's private key (a): %lld\n", a);
    printf("Bob's private key   (b): %lld\n", b);

    A = modPower(g, a, p);  // Alice's public key
    B = modPower(g, b, p);  // Bob's public key

    printf("\nAlice's public key (A): %lld\n", A);
    printf("Bob's public key   (B): %lld\n", B);

    keyA = modPower(B, a, p);  // Alice computes secret
    keyB = modPower(A, b, p);  // Bob computes secret

    printf("\nShared secret by Alice: %lld\n", keyA);
    printf("Shared secret by Bob:   %lld\n", keyB);

    if (keyA == keyB)
        printf("\n✅ Key exchange successful!\n");
    else
        printf("\n❌ Key exchange failed.\n");

    return 0;
}
