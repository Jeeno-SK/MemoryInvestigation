#include <stdio.h>
#include "report.h"

void report_generate(const MemMap         *map,
                     const AnalysisResult  *analysis,
                     const ForensicsResult *forensics,
                     const CliOptions      *opts) {
    (void)forensics;
    (void)opts;
    printf("========================\n");
    printf("MEMSCAN REPORT\n");
    printf("========================\n");
    printf("PID:     %d\n", map->pid);
    printf("Regions: %d\n", analysis->total_regions);
    /* full implementation Day 8 */
}
