#include <stdio.h>
#include <string.h>

// GCD
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// (base^exp) % mod
long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2)
            res = (res * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

// Modular inverse using Extended Euclidean Algorithm
int modInverse(int e, int phi) {
    int t = 0, newt = 1, r = phi, newr = e;
    while (newr != 0) {
        int q = r / newr;
        int tmp = newt;
        newt = t - q * newt;
        t = tmp;
        tmp = newr;
        newr = r - q * newr;
        r = tmp;
    }
    return t < 0 ? t + phi : t;
}

int main() {
    int p, q, e;

    printf("Enter prime p: ");
    scanf("%d", &p);
    printf("Enter prime q: ");
    scanf("%d", &q);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    printf("Enter e (coprime with %d): ", phi);
    scanf("%d", &e);

    while (gcd(e, phi) != 1) {
        printf("Invalid. Enter e again: ");
        scanf("%d", &e);
    }

    int d = modInverse(e, phi);
    printf("\nPublic Key  = (%d, %d)\n", e, n);
    printf("Private Key = (%d, %d)\n", d, n);

    // Encryption
    char msg[100];
    printf("Enter message: ");
    scanf("%s", msg);

    int len = strlen(msg);
    long long enc[100];

    printf("\nEncrypted: ");
    for (int i = 0; i < len; i++) {
        enc[i] = modPow(msg[i], e, n);
        printf("%lld ", enc[i]);
    }

    printf("\nDecrypted: ");
    for (int i = 0; i < len; i++) {
        printf("%c", (char)modPow(enc[i], d, n));
    }

    printf("\n");
    return 0;
}
