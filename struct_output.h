//
// Created by Anshu on 9/24/18.
//

#include "cmd_line_args.h"
#ifndef HW1_STRUCT_OUTPUT_H
#define HW1_STRUCT_OUTPUT_H

#endif //HW1_STRUCT_OUTPUT_H


typedef struct struct_output {

    char *pid; // Displays process_id
    char status; // Displays status of the process
    char *utime; // Displays the up time
    char *stime; //system time consumed so far by this process
    char *virtual_memory; //Virtual memory currently beings used
    char *command_line; // Command line that initiated the process


} struct_output;

void print(struct_output output, cmdLineArg cmd_args);
