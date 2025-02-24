#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simple hash function
unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

typedef struct {
    char username[50];
    unsigned long password_hash;
} User;

int authenticate(User *users, int num_users, char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            unsigned long input_hash = hash((unsigned char*)password);
            return input_hash == users[i].password_hash;
        }
    }
    return 0;
}

int main() {
    User users[2] = {
        {"alice", hash((unsigned char*)"password123")},
        {"bob", hash((unsigned char*)"securepass")}
    };

    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (authenticate(users, 2, username, password)) {
        printf("Authentication Successful!\n");
    } else {
        printf("Authentication Failed!\n");
    }

    return 0;
}
