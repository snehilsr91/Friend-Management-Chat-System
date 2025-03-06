#ifndef COMMON_H
#define COMMON_H

#define MAX_USERS 100
#define MAX_FRIENDS 50
#define MAX_MESSAGES 100
#define MAX_NAME_LEN 50

typedef struct {
    char username[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
    int friend_count;
    char friends[MAX_FRIENDS][MAX_NAME_LEN];
} User;

typedef struct {
    char sender[MAX_NAME_LEN];
    char receiver[MAX_NAME_LEN];
    char message[256];
} Message;

#endif // COMMON_H
