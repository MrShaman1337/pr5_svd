#include "process.h"
#include <stdio.h>
#include <stdlib.h>

void list_processes() {
    FILE *fp = popen("ps -e --no-headers --sort pid", "r");
    if (!fp) {
        perror("Ошибка при отображения списка процессов");
        return;
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    pclose(fp);
}
