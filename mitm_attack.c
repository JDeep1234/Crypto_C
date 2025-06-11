#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_LEN 65

// Hash password using SHA-256
void hash_pass(const char *pass, char *hash) {
    unsigned char tmp[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)pass, strlen(pass), tmp);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(hash + (i * 2), "%02x", tmp[i]);
}

int main() {
    int choice;
    printf("1. Register\n2. Login\nChoice: ");
    scanf("%d", &choice);

    char user[50], pass[50], hash[HASH_LEN];

    if (choice == 1) { // Register
        printf("Username: "); scanf("%s", user);
        printf("Password: "); scanf("%s", pass);
        hash_pass(pass, hash);

        FILE *f = fopen("users.txt", "a");
        fprintf(f, "%s %s\n", user, hash);
        fclose(f);
        printf("User registered!\n");

    } else if (choice == 2) { // Login
        char file_user[50], file_hash[HASH_LEN];
        int found = 0;

        printf("Username: "); scanf("%s", user);
        printf("Password: "); scanf("%s", pass);
        hash_pass(pass, hash);

        FILE *f = fopen("users.txt", "r");
        while (fscanf(f, "%s %s", file_user, file_hash) != EOF) {
            if (strcmp(user, file_user) == 0) {
                found = 1;
                if (strcmp(hash, file_hash) == 0)
                    printf("Login successful!\n");
                else
                    printf("Wrong password.\n");
                break;
            }
        }
        fclose(f);
        if (!found) printf("User not found.\n");

    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
