#ifndef FORENSICS_H
#define FORENSICS_H

#include "parser.h"

#define MAX_WARNINGS 256
#define MAX_WARN_LEN 512

typedef enum {
    WARN_RWX_REGION,
    WARN_DELETED_MAPPING,
    WARN_EXEC_ANON
} WarnType;

typedef struct {
    WarnType      type;
    char          message[MAX_WARN_LEN];
    unsigned long address_start;
} ForensicWarning;

typedef struct {
    ForensicWarning warnings[MAX_WARNINGS];
    int             count;
    int             rwx_found;
    int             deleted_found;
    int             exec_anon_found;
} ForensicsResult;

void forensics_run(const MemMap *map, ForensicsResult *result);

#endif
