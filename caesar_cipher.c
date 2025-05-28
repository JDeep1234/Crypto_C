#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = ((ch - offset + key) % 26) + offset;
        }
        text[i] = ch;
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = ((ch - offset - key + 26) % 26) + offset;
        }
        text[i] = ch;
    }
}

int main() {
    char text[MAX_LEN];
    int key;

    printf("Enter text: ");
    fgets(text, MAX_LEN, stdin);

    printf("Enter key (shift): ");
    scanf("%d", &key);

    encrypt(text, key);
    printf("Encrypted: %s\n", text);

    decrypt(text, key);
    printf("Decrypted: %s\n", text);

    return 0;
}
