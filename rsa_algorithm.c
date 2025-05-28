#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate (base^exp) % mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Extended Euclidean Algorithm to find modular inverse
int mod_inverse(int e, int phi) {
    int t = 0, new_t = 1;
    int r = phi, new_r = e;

    while (new_r != 0) {
        int quotient = r / new_r;
        int temp = t;
        t = new_t;
        new_t = temp - quotient * new_t;

        temp = r;
        r = new_r;
        new_r = temp - quotient * new_r;
    }

    if (r > 1) return -1; // No inverse
    if (t < 0) t += phi;
    return t;
}

int main() {
    // Choose two prime numbers
    int p = 61, q = 53; // You can change these to test multiple runs

    // Compute n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose e
    int e = 17; // Common choice, make sure it's coprime to phi
    while (gcd(e, phi) != 1) e++;

    // Compute d
    int d = mod_inverse(e, phi);
    if (d == -1) {
        printf("Modular inverse not found. Try other primes.\n");
        return 1;
    }

    // Display keys
    printf("Public Key: (e=%d, n=%d)\n", e, n);
    printf("Private Key: (d=%d, n=%d)\n", d, n);

    // Input plaintext
    char msg[100];
    printf("Enter message (plaintext, alphabets only): ");
    scanf("%s", msg);

    int len = strlen(msg);
    long long encrypted[100], decrypted[100];

    // Encrypt each character
    printf("Encrypted message: ");
    for (int i = 0; i < len; i++) {
        encrypted[i] = mod_pow((int)msg[i], e, n);
        printf("%lld ", encrypted[i]);
    }
    printf("\n");

    // Decrypt each character
    printf("Decrypted message: ");
    for (int i = 0; i < len; i++) {
        decrypted[i] = mod_pow(encrypted[i], d, n);
        printf("%c", (char)decrypted[i]);
    }
    printf("\n");

    return 0;
}
