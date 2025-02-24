#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

// Initial and Final Permutation tables (standard DES)
static const int IP[64] = {  
    58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
};

static const int FP[64] = {  
    40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25
};

// Permutes the input block based on the given table
uint64_t permute(uint64_t block, const int *table, int size) {
    uint64_t result = 0;
    for (int i = 0; i < size; i++) {
        result <<= 1;
        result |= (block >> (64 - table[i])) & 1;
    }
    return result;
}

// DES Feistel function (simplified for brevity)
uint32_t feistel(uint32_t half_block, uint64_t subkey) {
    // Placeholder for S-Box, Expansion (E), and P-Box operations
    return half_block ^ (subkey & 0xFFFFFFFF);  // Simple XOR for now
}

// Generates round keys (placeholder, implement full key schedule for real DES)
void generate_keys(uint64_t key, uint64_t subkeys[16]) {
    for (int i = 0; i < 16; i++) {
        subkeys[i] = key ^ (i * 0x1111111111111111);  // Placeholder logic
    }
}

// DES Encryption function
uint64_t des_encrypt(uint64_t plaintext, uint64_t key) {
    uint64_t subkeys[16];
    generate_keys(key, subkeys);

    uint64_t permuted = permute(plaintext, IP, 64);
    uint32_t L = permuted >> 32, R = permuted & 0xFFFFFFFF;

    for (int i = 0; i < 16; i++) {
        uint32_t temp = R;
        R = L ^ feistel(R, subkeys[i]);
        L = temp;
    }

    uint64_t pre_output = ((uint64_t)R << 32) | L;
    return permute(pre_output, FP, 64);
}

// DES Decryption function
uint64_t des_decrypt(uint64_t ciphertext, uint64_t key) {
    uint64_t subkeys[16];
    generate_keys(key, subkeys);

    uint64_t permuted = permute(ciphertext, IP, 64);
    uint32_t L = permuted >> 32, R = permuted & 0xFFFFFFFF;

    for (int i = 15; i >= 0; i--) {
        uint32_t temp = R;
        R = L ^ feistel(R, subkeys[i]);
        L = temp;
    }

    uint64_t pre_output = ((uint64_t)R << 32) | L;
    return permute(pre_output, FP, 64);
}

// Main function to test DES implementation
int main() {
    uint64_t data = 0x0123456789ABCDEF;
    uint64_t key = 0x133457799BBCDFF1;

    printf("Original Data:  0x%" PRIX64 "\n", data);
    
    uint64_t encrypted = des_encrypt(data, key);
    printf("Encrypted Data: 0x%" PRIX64 "\n", encrypted);

    uint64_t decrypted = des_decrypt(encrypted, key);
    printf("Decrypted Data: 0x%" PRIX64 "\n", decrypted);

    return 0;
}
