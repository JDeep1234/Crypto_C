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

void elgamal_encrypt(int msg, int p, int g, int y, int *c1, int *c2) {
    int k = 7;  // Random key
    *c1 = mod_pow(g, k, p);
    *c2 = (msg * mod_pow(y, k, p)) % p;
}

int elgamal_decrypt(int c1, int c2, int p, int x) {
    int s = mod_pow(c1, x, p);
    // Modular multiplicative inverse
    int s_inv = 1;
    while ((s * s_inv) % p != 1) s_inv++;
    return (c2 * s_inv) % p;
}

int main() {
    int p = 23;     // Prime number
    int g = 5;      // Primitive root
    int x = 6;      // Private key
    int y = mod_pow(g, x, p);  // Public key

    int msg = 15;
    int c1, c2;

    elgamal_encrypt(msg, p, g, y, &c1, &c2);
    int decrypted = elgamal_decrypt(c1, c2, p, x);

    printf("Original Message: %d\n", msg);
    printf("Encrypted Message (c1, c2): (%d, %d)\n", c1, c2);
    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}
