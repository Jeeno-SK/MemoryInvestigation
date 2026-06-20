#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "utils.h"

int utils_find_pid(const char *name) {
    (void)name;
    return -1;  /* implemented Day 3 */
}

void utils_kb_to_human(size_t kb, char *buf, size_t buflen) {
    if (kb >= 1024 * 1024)
        snprintf(buf, buflen, "%.1f GB", kb / (1024.0 * 1024));
    else if (kb >= 1024)
        snprintf(buf, buflen, "%.1f MB", kb / 1024.0);
    else
        snprintf(buf, buflen, "%zu kB", kb);
}

int utils_path_is_deleted(const char *path) {
    return strstr(path, "(deleted)") != NULL;
}

int utils_is_numeric(const char *str) {
    if (!str || !*str) return 0;
    while (*str) {
        if (!isdigit((unsigned char)*str)) return 0;
        str++;
    }
    return 1;
}

void utils_die(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    exit(1);
}
