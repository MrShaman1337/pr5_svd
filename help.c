#include "help.h"
#include <stdio.h>

void print_help() {
    printf("Описание команд:\n");
    printf("  -u, --users         Список пользователей и их домашних директорий.\n");
    printf("  -p, --processes     Список процессов по PID.\n");
    printf("  -h, --help          Отображение описания команд.\n");
    printf("  -l PATH, --log PATH Переадресация вывода в файл логирования.\n");
    printf("  -e PATH, --errors PATH Переадресация вывода ошибок в отдельный файл.\n");
}
