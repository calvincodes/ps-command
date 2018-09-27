//
// Created by Anshu Verma on 9/24/18.
// Co-author Arpit Jain
//

#ifndef HW1_CMD_LINE_ARGS_H
#define HW1_CMD_LINE_ARGS_H
#include "struct_input.h"
#endif

#ifndef HW1_STRUCT_OUTPUT_H
#define HW1_STRUCT_OUTPUT_H

#endif //HW1_STRUCT_OUTPUT_H

struct struct_output {

    char *pid; // Displays process_id
    char *status; // Displays status of the process
    char *utime; // Displays the up time
    char *stime; //system time consumed so far by this process
    char *virtual_memory; //Virtual memory currently beings used
    char *command_line; // Command line that initiated the process
    unsigned size;
    struct struct_output *next;
};

void print(struct struct_output output, struct_input cmd_args);
void print_test(struct struct_output output);
