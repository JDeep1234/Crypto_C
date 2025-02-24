#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Compute GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

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

void generate_keypair(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p-1) * (q-1);

    // Choose e
    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1) break;
    }

    // Compute d
    for (*d = 1; (*d * *e) % phi != 1; (*d)++);
}

long long encrypt(long long msg, int e, int n) {
    return mod_pow(msg, e, n);
}

long long decrypt(long long cipher, int d, int n) {
    return mod_pow(cipher, d, n);
}

int main() {
    int p = 61, q = 53;
    int n, e, d;
    
    generate_keypair(p, q, &n, &e, &d);
    
    long long msg = 42;
    printf("Original Message: %lld\n", msg);
    
    long long encrypted = encrypt(msg, e, n);
    printf("Encrypted Message: %lld\n", encrypted);
    
    long long decrypted = decrypt(encrypted, d, n);
    printf("Decrypted Message: %lld\n", decrypted);

    return 0;
}
