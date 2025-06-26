#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    char input[9];  // 8 chars max for DES

    printf("Enter text (max 8 chars): ");
    gets(input);  

    // Prepare key and schedule
    DES_cblock key = "mysecret";  // 8-byte key
    DES_key_schedule ks;
    DES_set_key_checked(&key, &ks);

    // Encrypt
    DES_cblock cipher;
    DES_ecb_encrypt((DES_cblock *)input, &cipher, &ks, DES_ENCRYPT);

    printf("Encrypted (hex): ");
    for (int i = 0; i < 8; i++) printf("%02X ", cipher[i]);
    printf("\n");

    // Decrypt
    DES_cblock plain;
    DES_ecb_encrypt(&cipher, &plain, &ks, DES_DECRYPT);

    printf("Decrypted text: %s\n", plain);

    return 0;
}
