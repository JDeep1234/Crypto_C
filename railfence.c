#include <stdio.h>

int main() {
    char text[200];
    char even[200], odd[200];
    int i, e = 0, o = 0;

    printf("Enter a sentence: ");
    gets(text); 

    for (i = 0; text[i] != '\0'; i++) {
        if (i % 2 == 0)
            even[e++] = text[i];
        else
            odd[o++] = text[i];
    }

    even[e] = '\0';
    odd[o] = '\0';

    printf("Encrypted text: %s%s\n", even, odd);

    return 0;
}
