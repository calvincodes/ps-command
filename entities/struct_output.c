//
// Created by Anshu Verma on 9/24/18.
// Co-author Arpit Jain
//

#include <stdio.h>
#include "struct_output.h"

void print(struct struct_output output, struct_input cmd_args) {

    printf("%-*s",7, output.pid);
    if (cmd_args.stateFlag) printf("%-*s",3, output.status);
    if (cmd_args.userTimeFlag) printf("utime=%-*s",4, output.utime);
    if (cmd_args.systemTimeFlag) printf("stime=%-*s",7, output.stime);
    if (cmd_args.vMemFlag) printf("\tvmemory=%-*s",10, output.virtual_memory);
    if (cmd_args.cmdLineFlag) printf("\t[%-s]", output.command_line);
    printf("\n");
}

void print_test(struct struct_output output) {

    printf("\n");
    printf("%s", output.pid);
    printf("\t%s", output.status);
    printf("\t%s", output.utime);
    printf("\t%s", output.stime);
    printf("\t%s", output.virtual_memory);
    printf("\t%s", output.command_line);
}


