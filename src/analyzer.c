#include <string.h>
#include "analyzer.h"

void analyzer_run(const MemMap *map, AnalysisResult *result) {
    memset(result, 0, sizeof(*result));
    result->total_regions = map->count;
    /* full implementation Day 6 */
}
