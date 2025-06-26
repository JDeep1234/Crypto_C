#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hashPassword(char *pass, char *output) {
    unsigned char temp[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)pass, strlen(pass), temp);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output + i * 2, "%02x", temp[i]);
}

int main() {
    int choice;
    char user[50], pass[50], hash[65];

    printf("1. Register\n2. Login\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("New username: ");
        scanf("%s", user);
        printf("New password: ");
        scanf("%s", pass);

        hashPassword(pass, hash);

        FILE *f = fopen("users.txt", "a");
        fprintf(f, "%s %s\n", user, hash);
        fclose(f);

        printf("✅ Registered!\n");

    } else if (choice == 2) {
        char u[50], h[65];
        int found = 0;

        printf("Username: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", pass);

        hashPassword(pass, hash);

        FILE *f = fopen("users.txt", "r");
        while (fscanf(f, "%s %s", u, h) != EOF) {
            if (strcmp(user, u) == 0) {
                found = 1;
                if (strcmp(hash, h) == 0)
                    printf("✅ Login successful!\n");
                else
                    printf("❌ Wrong password.\n");
                break;
            }
        }
        fclose(f);
        if (!found)
            printf("❌ User not found.\n");

    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
