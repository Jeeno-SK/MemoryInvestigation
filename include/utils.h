#ifndef UTILS_H
#define UTILS_H

int  utils_find_pid(const char *name);
void utils_kb_to_human(size_t kb, char *buf, size_t buflen);
int  utils_path_is_deleted(const char *path);
int  utils_is_numeric(const char *str);
void utils_die(const char *fmt, ...);

#endif
