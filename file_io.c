#include <stdio.h>
#include "file_io.h"
#include "user.h"

void save_users() {
    FILE *file = fopen("users.dat", "wb");
    if (file == NULL) {
        printf("Error saving users!\n");
        return;
    }
    fwrite(&user_count, sizeof(int), 1, file);
    fwrite(users, sizeof(User), user_count, file);
    fclose(file);
}

void load_users() {
    FILE *file = fopen("users.dat", "rb");
    if (file == NULL) {
        return; // No previous data
    }
    fread(&user_count, sizeof(int), 1, file);
    fread(users, sizeof(User), user_count, file);
    fclose(file);
}
