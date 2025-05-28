#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 65
#define FILE_NAME "users.txt"

// Function to compute SHA-256 hash
void hash_password(const char *password, char *output) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)password, strlen(password), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output + (i * 2), "%02x", hash[i]);
    output[64] = 0;
}

// Register a new user
void register_user() {
    char username[50], password[50], hashed[HASH_SIZE];
    printf("Register\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    hash_password(password, hashed);

    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fprintf(fp, "%s %s\n", username, hashed);
    fclose(fp);
    printf("User registered successfully!\n");
}

// Authenticate existing user
void login_user() {
    char username[50], password[50], hashed_input[HASH_SIZE];
    char file_user[50], file_hash[HASH_SIZE];
    int found = 0;

    printf("Login\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    hash_password(password, hashed_input);

    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    while (fscanf(fp, "%s %s", file_user, file_hash) != EOF) {
        if (strcmp(username, file_user) == 0) {
            found = 1;
            if (strcmp(hashed_input, file_hash) == 0)
                printf("Authentication successful!\n");
            else
                printf("Authentication failed: Incorrect password.\n");
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Authentication failed: Username not found.\n");
}

int main() {
    int choice;
    printf("1. Register\n2. Login\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1)
        register_user();
    else if (choice == 2)
        login_user();
    else
        printf("Invalid option.\n");

    return 0;
}
