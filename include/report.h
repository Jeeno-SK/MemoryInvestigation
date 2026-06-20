#ifndef REPORT_H
#define REPORT_H

#include "parser.h"
#include "analyzer.h"
#include "forensics.h"
#include "cli.h"

void report_generate(const MemMap         *map,
                     const AnalysisResult  *analysis,
                     const ForensicsResult *forensics,
                     const CliOptions      *opts);

#endif
