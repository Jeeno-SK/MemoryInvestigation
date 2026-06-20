#ifndef CLI_H
#define CLI_H

typedef struct {
    int  pid;
    char proc_name[256];
    int  scan_all;
    int  show_maps;
    int  show_smaps;
    int  show_heap;
    int  show_stack;
    int  run_forensics;
    int  output_json;
    int  verbose;
} CliOptions;

void cli_parse(int argc, char *argv[], CliOptions *opts);
void cli_print_help(void);
void cli_print_version(void);

#endif
