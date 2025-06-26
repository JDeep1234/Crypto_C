#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    AES_KEY ekey, dkey;
    unsigned char k[16] = "1234567890abcdef";
    char input[17], plain[16] = {0}, cipher[16], dec[16];
    
    printf("Text: "); fgets(input, 17, stdin);
    strncpy(plain, input, 16);
    
    AES_set_encrypt_key(k, 128, &ekey);
    AES_set_decrypt_key(k, 128, &dkey);
    
    AES_encrypt(plain, cipher, &ekey);
    printf("Encrypted: ");
    for(int i = 0; i < 16; i++) printf("%02X", cipher[i]);
    
    AES_decrypt(cipher, dec, &dkey);
    printf("\nDecrypted: %s\n", dec);
    
    return 0;
}
