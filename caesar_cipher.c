#include <stdio.h>
#include <ctype.h>

void encryptText(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Only shift letters
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + key) % 26 + base;
        }

        text[i] = ch;
    }
}

void decryptText(char *text, int key) {
    encryptText(text, 26 - (key % 26));  // Reverse shift using same function
}

int main() {
    char text[1000];
    int key;

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift key: ");
    scanf("%d", &key);

    encryptText(text, key);
    printf("Encrypted: %s", text);

    decryptText(text, key);
    printf("Decrypted: %s", text);

    return 0;
}
