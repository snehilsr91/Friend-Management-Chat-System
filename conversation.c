#include <stdio.h>
#include <string.h>
#include "conversation.h"

Message messages[MAX_MESSAGES];
int message_count = 0;

void send_message(const char *sender, const char *receiver, const char *message) {
    if (message_count >= MAX_MESSAGES) {
        printf("Message storage full!\n");
        return;
    }

    strcpy(messages[message_count].sender, sender);
    strcpy(messages[message_count].receiver, receiver);
    strcpy(messages[message_count].message, message);
    message_count++;

    printf("Message sent from %s to %s\n", sender, receiver);
}

void list_messages(const char *receiver) {
    printf("Messages for %s:\n", receiver);
    for (int i = 0; i < message_count; i++) {
        if (strcmp(messages[i].receiver, receiver) == 0) {
            printf("From %s: %s\n", messages[i].sender, messages[i].message);
        }
    }
}
