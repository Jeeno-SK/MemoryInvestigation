#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"
#include "parser.h"
#include "analyzer.h"
#include "forensics.h"
#include "report.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    CliOptions opts;
    memset(&opts, 0, sizeof(opts));
    cli_parse(argc, argv, &opts);

    int pid = 0;
    if (opts.pid > 0) {
        pid = opts.pid;
    } else if (opts.proc_name[0] != '\0') {
        pid = utils_find_pid(opts.proc_name);
        if (pid <= 0) {
            fprintf(stderr, "error: process '%s' not found\n", opts.proc_name);
            return 1;
        }
    } else {
        cli_print_help();
        return 0;
    }

    MemMap map;
    memset(&map, 0, sizeof(map));
    map.pid = pid;

    if (parser_load(pid, &map) != 0) {
        fprintf(stderr, "error: could not read /proc/%d/maps\n", pid);
        return 1;
    }

    parser_load_smaps(pid, &map);

    AnalysisResult analysis;
    memset(&analysis, 0, sizeof(analysis));
    analyzer_run(&map, &analysis);

    ForensicsResult forensics;
    memset(&forensics, 0, sizeof(forensics));
    if (opts.run_forensics)
        forensics_run(&map, &forensics);

    report_generate(&map, &analysis, &forensics, &opts);
    return 0;
}
