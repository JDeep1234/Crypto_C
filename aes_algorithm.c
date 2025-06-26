#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    AES_KEY encKey, decKey;
    unsigned char key[16] = "1234567890abcdef";  // 16-byte key

    char input[17];  // Max 16 chars + null
    printf("Enter text (max 16 chars): ");
    gets(input); 

    // Prepare 16-byte plaintext buffer (pad with zeros)
    unsigned char plain[16] = {0};
    strncpy((char *)plain, input, 16);

    unsigned char cipher[16], decrypted[16];

    AES_set_encrypt_key(key, 128, &encKey);
    AES_set_decrypt_key(key, 128, &decKey);

    AES_encrypt(plain, cipher, &encKey);

    printf("Encrypted (hex): ");
    for (int i = 0; i < 16; i++) {
        printf("%02X ", cipher[i]);
    }
    printf("\n");

    AES_decrypt(cipher, decrypted, &decKey);

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
