#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    long long p = 23, g = 5;
    long long a = rand() % 10 + 1; // Alice's private key
    long long b = rand() % 10 + 1; // Bob's private key
    long long m1 = rand() % 10 + 1; // Mallory's key for Bob
    long long m2 = rand() % 10 + 1; // Mallory's key for Alice

    long long A = mod_exp(g, a, p);
    long long B = mod_exp(g, b, p);
    long long K = mod_exp(g, m1, p);
    long long T = mod_exp(g, m2, p);

    long long Sa = mod_exp(T, a, p);     // Alice's shared key
    long long Sb = mod_exp(K, b, p);     // Bob's shared key
    long long Sm_a = mod_exp(A, m2, p);  // Mallory with Alice
    long long Sm_b = mod_exp(B, m1, p);  // Mallory with Bob

    printf("Alice's shared key: %lld\n", Sa);
    printf("Bob's shared key:   %lld\n", Sb);
    printf("Mallory↔Alice key:  %lld\n", Sm_a);
    printf("Mallory↔Bob key:    %lld\n", Sm_b);

    return 0;
}
