#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define AES_BLOCK_SIZE 16

void aes_encrypt(uint8_t *data, uint8_t *key) {
    // SubBytes
    // ShiftRows
    // MixColumns
    // AddRoundKey
    printf("AES Encryption Placeholder\n");
}

void aes_decrypt(uint8_t *data, uint8_t *key) {
    // Inverse operations of encryption
    printf("AES Decryption Placeholder\n");
}

int main() {
    uint8_t data[AES_BLOCK_SIZE] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 
                                    0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    uint8_t key[AES_BLOCK_SIZE] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 
                                   0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

    printf("Original Data: ");
    for(int i = 0; i < AES_BLOCK_SIZE; i++) 
        printf("%02x ", data[i]);
    printf("\n");

    aes_encrypt(data, key);
    aes_decrypt(data, key);

    return 0;
}
