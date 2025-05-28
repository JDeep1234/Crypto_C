#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    char input[9];  // 8 characters + null terminator
    printf("Enter text (max 8 chars): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    unsigned char plaintext[8] = {0};
    strncpy((char *)plaintext, input, 8);

    // 8-byte DES key
    DES_cblock key = {0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01};
    DES_key_schedule key_schedule;

    // Set key schedule
    DES_set_key_checked(&key, &key_schedule);

    DES_cblock ciphertext, decryptedtext;

    // Encrypt
    DES_ecb_encrypt((DES_cblock *)plaintext, &ciphertext, &key_schedule, DES_ENCRYPT);

    // Display encrypted text
    printf("Encrypted text: ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    // Decrypt
    DES_ecb_encrypt(&ciphertext, &decryptedtext, &key_schedule, DES_DECRYPT);

    // Print decrypted text
    printf("Decrypted text: ");
    for (int i = 0; i < 8; i++) {
        printf("%c", decryptedtext[i]);
    }
    printf("\n");

    return 0;
}
