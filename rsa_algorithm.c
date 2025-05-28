#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

int mod_inverse(int e, int phi) {
    int t = 0, newt = 1, r = phi, newr = e;
    while (newr != 0) {
        int q = r / newr, temp = newt;
        newt = t - q * newt; t = temp;
        temp = newr; newr = r - q * newr; r = temp;
    }
    return t < 0 ? t + phi : t;
}

int main() {
    int p, q, e;
    printf("Enter prime number p: "); scanf("%d", &p);
    printf("Enter prime number q: "); scanf("%d", &q);

    int n = p * q, phi = (p - 1) * (q - 1);
    printf("Enter public exponent e (coprime with %d): ", phi); scanf("%d", &e);
    while (gcd(e, phi) != 1) {
        printf("e is not coprime with phi. Enter again: ");
        scanf("%d", &e);
    }

    int d = mod_inverse(e, phi);
    printf("\nPublic Key: (%d, %d)\nPrivate Key: (%d, %d)\n", e, n, d, n);

    char msg[100]; printf("Enter message (plaintext): "); scanf("%s", msg);
    int len = strlen(msg);
    long long enc[100];

    printf("\nEncrypted: ");
    for (int i = 0; i < len; i++) {
        enc[i] = mod_pow((int)msg[i], e, n);
        printf("%lld ", enc[i]);
    }

    printf("\nDecrypted: ");
    for (int i = 0; i < len; i++)
        printf("%c", (char)mod_pow(enc[i], d, n));
    printf("\n");

    return 0;
}
