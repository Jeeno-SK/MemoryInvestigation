#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>

#define MAX_REGIONS 4096

typedef struct {
    unsigned long start;
    unsigned long end;
    char          perms[5];
    unsigned long offset;
    char          dev[8];
    unsigned long inode;
    char          path[256];
    size_t        size_kb;
    size_t        rss_kb;
    size_t        swap_kb;
    size_t        private_dirty_kb;
    size_t        shared_clean_kb;
    int           is_heap;
    int           is_stack;
    int           is_anon;
    int           is_deleted;
} Region;

typedef struct {
    Region regions[MAX_REGIONS];
    int    count;
    int    pid;
} MemMap;

int parser_load(int pid, MemMap *map);
int parser_load_smaps(int pid, MemMap *map);

#endif
