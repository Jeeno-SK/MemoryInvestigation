#include <stdio.h>
#include <string.h>
#include "parser.h"

int parser_load(int pid, MemMap *map) {
    map->pid   = pid;
    map->count = 0;
    /* full implementation Day 4 */
    return 0;
}

int parser_load_smaps(int pid, MemMap *map) {
    (void)pid;
    (void)map;
    /* full implementation Day 5 */
    return 0;
}
