#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hash(char *pass, char *out) {
    unsigned char temp[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)pass, strlen(pass), temp);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(out + i * 2, "%02x", temp[i]);
}

int main() {
    int choice;
    char user[50], pass[50], hash1[65], u[50], h[65];
    
    printf("1. Register\n2. Login\nChoice: ");
    scanf("%d", &choice);
    
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);
    hash(pass, hash1);
    
    if (choice == 1) {
        FILE *f = fopen("users.txt", "a");
        fprintf(f, "%s %s\n", user, hash1);
        fclose(f);
        printf("Registered!\n");
    }
    else if (choice == 2) {
        FILE *f = fopen("users.txt", "r");
        int found = 0;
        while (fscanf(f, "%s %s", u, h) != EOF) {
            if (strcmp(user, u) == 0 && strcmp(hash1, h) == 0) {
                printf("Login successful!\n");
                found = 1;
                break;
            }
        }
        fclose(f);
        if (!found) printf("Login failed!\n");
    }
    
    return 0;
}
