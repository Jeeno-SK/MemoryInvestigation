#ifndef ANALYZER_H
#define ANALYZER_H

#include "parser.h"

typedef struct {
    int    total_regions;
    size_t total_rss_kb;
    size_t total_swap_kb;
    size_t heap_kb;
    size_t stack_kb;
    size_t anon_kb;
    size_t shared_kb;
    size_t private_kb;
} AnalysisResult;

void analyzer_run(const MemMap *map, AnalysisResult *result);

#endif
