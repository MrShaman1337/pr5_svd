#include "users.h"
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

void list_users() {
    struct passwd *pwd;
    FILE *fp = popen("getent passwd | sort", "r");
    if (!fp) {
        perror("Ошибка при получения списка пользователей.");
        return;
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    pclose(fp);
}