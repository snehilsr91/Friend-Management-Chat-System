#include <stdio.h>
#include <string.h>
#include "friend.h"
#include "user.h"

void send_friend_request(const char *from, const char *to) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, from) == 0) {
            if (users[i].friend_count >= MAX_FRIENDS) {
                printf("%s has too many friends!\n", from);
                return;
            }
            strcpy(users[i].friends[users[i].friend_count], to);
            users[i].friend_count++;
            printf("%s and %s are now friends!\n", from, to);
            return;
        }
    }
    printf("User %s not found!\n", from);
}

void list_friends(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Friends of %s:\n", username);
            for (int j = 0; j < users[i].friend_count; j++) {
                printf("%s\n", users[i].friends[j]);
            }
            return;
        }
    }
    printf("User %s not found!\n", username);
}
