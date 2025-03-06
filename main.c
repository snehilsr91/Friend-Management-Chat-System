#include <stdio.h>
#include "user.h"
#include "friend.h"
#include "conversation.h"
#include "file_io.h"

void menu() {
    printf("\n1. Register User\n");
    printf("2. List Users\n");
    printf("3. Send Friend Request\n");
    printf("4. List Friends\n");
    printf("5. Send Message\n");
    printf("6. View Messages\n");
    printf("7. Exit\n");
}

int main() {
    load_users(); // Load users from file

    int choice;
    char username[MAX_NAME_LEN], email[MAX_NAME_LEN];
    char friend_username[MAX_NAME_LEN], receiver[MAX_NAME_LEN], message[256];

    while (1) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter email: ");
                scanf("%s", email);
                register_user(username, email);
                save_users();
                break;
            case 2:
                list_users();
                break;
            case 3:
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter friend's username: ");
                scanf("%s", friend_username);
                send_friend_request(username, friend_username);
                save_users();
                break;
            case 4:
                printf("Enter username: ");
                scanf("%s", username);
                list_friends(username);
                break;
            case 5:
                printf("Enter sender username: ");
                scanf("%s", username);
                printf("Enter receiver username: ");
                scanf("%s", receiver);
                printf("Enter message: ");
                getchar();
                fgets(message, sizeof(message), stdin);
                send_message(username, receiver, message);
                break;
            case 6:
                printf("Enter your username: ");
                scanf("%s", username);
                list_messages(username);
                break;
            case 7:
                save_users();
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
