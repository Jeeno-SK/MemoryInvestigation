#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"

void cli_parse(int argc, char *argv[], CliOptions *opts) {
    (void)argc;
    (void)argv;
    memset(opts, 0, sizeof(*opts));
    /* full implementation Day 2 */
}

void cli_print_help(void) {
    printf("Usage: memscan [OPTIONS]\n");
    printf("  -p PID        target process by PID\n");
    printf("  -n NAME       target process by name\n");
    printf("  --all         scan all processes\n");
    printf("  --forensics   run forensic checks\n");
    printf("  --json        output as JSON\n");
    printf("  --help        show this help\n");
    printf("  --version     show version\n");
}

void cli_print_version(void) {
    printf("memscan v1.0.0\n");
}
