#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"
#include "process.h"
#include "log.h"
#include "errors.h"
#include "help.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Отсутвует аргументы. Используйте -h или --help для получения информации.\n");
        return EXIT_FAILURE;
    }

    const char *log_path = NULL;
    const char *error_path = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            list_users();
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            list_processes();
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return EXIT_SUCCESS;
        } else if ((strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) && i + 1 < argc) {
            log_path = argv[++i];
            redirect_logs(log_path);
        } else if ((strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) && i + 1 < argc) {
            error_path = argv[++i];
            redirect_errors(error_path);
        } else {
            fprintf(stderr, "Неизвестный аргумент: %s. Используйте -h или --help для получения информации.\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    close_logs();
    close_errors();
    return EXIT_SUCCESS;
}
