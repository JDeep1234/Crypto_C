#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// (base^exp) % mod
long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    srand(time(NULL));

    long long p, g;
    printf("Enter prime p: ");
    scanf("%lld", &p);
    printf("Enter base g: ");
    scanf("%lld", &g);

    // Private keys
    long long a = rand() % 10 + 1;  // Alice
    long long b = rand() % 10 + 1;  // Bob
    long long m1 = rand() % 10 + 1; // Mallory↔Bob
    long long m2 = rand() % 10 + 1; // Mallory↔Alice

    // Public keys
    long long A = modPow(g, a, p);  // Alice's real public key
    long long B = modPow(g, b, p);  // Bob's real public key
    long long K = modPow(g, m1, p); // Mallory sends to Bob
    long long T = modPow(g, m2, p); // Mallory sends to Alice

    // Shared keys
    long long keyA = modPow(T, a, p);   // Alice computes with fake T
    long long keyB = modPow(K, b, p);   // Bob computes with fake K
    long long malloryWithA = modPow(A, m2, p);
    long long malloryWithB = modPow(B, m1, p);

    // Output
    printf("\n-- Shared Keys --\n");
    printf("Alice's key:     %lld\n", keyA);
    printf("Bob's key:       %lld\n", keyB);
    printf("Mallory↔Alice:   %lld\n", malloryWithA);
    printf("Mallory↔Bob:     %lld\n", malloryWithB);

    printf("\n-- Private Keys --\n");
    printf("Alice:  %lld\n", a);
    printf("Bob:    %lld\n", b);
    printf("Mallory: m1 = %lld, m2 = %lld\n", m1, m2);

    return 0;
}
