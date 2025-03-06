#include <stdio.h>
#include <string.h>
#include "user.h"

User users[MAX_USERS];
int user_count = 0;

void register_user(const char *username, const char *email) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    strcpy(users[user_count].username, username);
    strcpy(users[user_count].email, email);
    users[user_count].friend_count = 0;
    user_count++;
    printf("User %s registered successfully!\n", username);
}

void list_users() {
    printf("Registered Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("%s (Email: %s)\n", users[i].username, users[i].email);
    }
}
