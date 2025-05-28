#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to perform modular exponentiation: (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd
            result = (result * base) % mod;

        exp = exp >> 1; // exp = exp / 2
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long p, g, a, b, A, B, sharedKey1, sharedKey2;

    // Step 1: Choose a prime number p and primitive root g
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);
    printf("Enter a primitive root modulo p (g): ");
    scanf("%lld", &g);

    // Step 2: Private keys (random values)
    srand(time(NULL));
    a = rand() % (p - 2) + 1; // 1 <= a < p
    b = rand() % (p - 2) + 1; // 1 <= b < p

    printf("\nPrivate key of Alice (a): %lld\n", a);
    printf("Private key of Bob   (b): %lld\n", b);

    // Step 3: Public keys
    A = power(g, a, p);
    B = power(g, b, p);

    printf("\nPublic key of Alice (A = g^a mod p): %lld\n", A);
    printf("Public key of Bob   (B = g^b mod p): %lld\n", B);

    // Step 5: Shared secret
    sharedKey1 = power(B, a, p); // Alice computes
    sharedKey2 = power(A, b, p); // Bob computes

    printf("\nShared secret computed by Alice: %lld\n", sharedKey1);
    printf("Shared secret computed by Bob:   %lld\n", sharedKey2);

    if (sharedKey1 == sharedKey2)
        printf("\nKey exchange successful. Shared secret key established.\n");
    else
        printf("\nKey exchange failed.\n");

    return 0;
}
