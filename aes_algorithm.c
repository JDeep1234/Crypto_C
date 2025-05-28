#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    AES_KEY encryptKey, decryptKey;
    unsigned char key[16] = "1234567890abcdef"; // 16-byte AES key

    char input[128];
    printf("Enter text (max 16 chars): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline

    // Ensure plaintext is 16 bytes by padding with spaces
    unsigned char plaintext[16] = {0};
    strncpy((char *)plaintext, input, 16);

    unsigned char encrypted[16], decrypted[16];

    // Set encryption and decryption keys
    AES_set_encrypt_key(key, 128, &encryptKey);
    AES_set_decrypt_key(key, 128, &decryptKey);

    // Encrypt
    AES_encrypt(plaintext, encrypted, &encryptKey);

    printf("Encrypted text (hex): ");
    for (int i = 0; i < 16; i++) {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    // Decrypt
    AES_decrypt(encrypted, decrypted, &decryptKey);

    printf("Decrypted text: ");
    for (int i = 0; i < 16; i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}
