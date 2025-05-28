#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    char input[17]; // 16 chars + null
    printf("Enter text (max 16 chars): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline

    // Pad input to 16 bytes with nulls
    unsigned char plaintext[16] = {0};
    strncpy((char *)plaintext, input, 16);

    // 16-byte key for AES-128
    unsigned char key[16] = {
        0x2b, 0x7e, 0x15, 0x16,
        0x28, 0xae, 0xd2, 0xa6,
        0xab, 0xf7, 0x15, 0x88,
        0x09, 0xcf, 0x4f, 0x3c
    };

    AES_KEY enc_key, dec_key;
    unsigned char encrypted[16], decrypted[16];

    AES_set_encrypt_key(key, 128, &enc_key);
    AES_encrypt(plaintext, encrypted, &enc_key);

    printf("Encrypted text (hex): ");
    for (int i = 0; i < 16; i++)
        printf("%02X ", encrypted[i]);
    printf("\n");

    AES_set_decrypt_key(key, 128, &dec_key);
    AES_decrypt(encrypted, decrypted, &dec_key);

    printf("Decrypted text: ");
    for (int i = 0; i < 16; i++)
        printf("%c", decrypted[i]);
    printf("\n");

    return 0;
}
