#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *log_file = NULL;

void redirect_logs(const char *path) {
    log_file = fopen(path, "w");
    if (!log_file) {
        perror("Ошибка при открытие файла с логами");
        exit(EXIT_FAILURE);
    }
    dup2(fileno(log_file), STDOUT_FILENO);
}

void close_logs() {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}
