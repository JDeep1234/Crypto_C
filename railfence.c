#include <stdio.h>

int main() {
    char userInput[200];
    char s1[200], s2[200];
    int i, j = 0, k = 0;

    printf("Enter the sentence: ");
    gets(userInput);  // Note: Use `fgets` instead of `gets` for safety

    for (i = 0; userInput[i] != '\0'; i++) {
        if (i % 2 != 0) {
            s2[k++] = userInput[i];
        } else {
            s1[j++] = userInput[i];
        }
    }

    s1[j] = '\0';
    s2[k] = '\0';

    printf("Encrypted text: %s%s\n", s1, s2);

    return 0;
}
