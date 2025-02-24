#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = ((text[i] - base + shift) % 26) + base;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift);
}

int main() {
    char message[] = "HELLO WORLD";
    int shift = 3;

    printf("Original: %s\n", message);
    
    encrypt(message, shift);
    printf("Encrypted: %s\n", message);
    
    decrypt(message, shift);
    printf("Decrypted: %s\n", message);

    return 0;
}
