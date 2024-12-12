#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *error_file = NULL;

void redirect_errors(const char *path) {
    error_file = fopen(path, "w");
    if (!error_file) {
        perror("Error opening error file");
        exit(EXIT_FAILURE);
    }
    dup2(fileno(error_file), STDERR_FILENO);
}

void close_errors() {
    if (error_file) {
        fclose(error_file);
        error_file = NULL;
    }
}
