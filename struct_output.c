//
// Created by Anshu on 9/24/18.
//

#include <stdio.h>
#include "struct_output.h"

void print(struct struct_output output, cmdLineArg cmd_args) {

    if(cmd_args.pid > -1) printf("%s", output.pid);
    if(cmd_args.stateFlag) printf("\t%s", output.status);
    if(cmd_args.userTimeFlag) printf("\t%s",output.utime);
    if(cmd_args.systemTimeFlag) printf("\t%s", output.stime);
    if(cmd_args.vMemFlag) printf("\t%s", output.virtual_memory);
    if(cmd_args.cmdLineFlag) printf("\t%s", output.command_line);
}

void print_test(struct struct_output output) {

    printf("\n");
     printf("%s", output.pid);
    printf("\t%s", output.status);
     printf("\t%s",output.utime);
    printf("\t%s", output.stime);
    printf("\t%s", output.virtual_memory);
     printf("\t%s", output.command_line);
}

void print_header(cmdLineArg cmd_args){
    if(cmd_args.pid > -1) printf("%s", "PID");
    if(cmd_args.stateFlag) printf("\t%s", "STATUS");
    if(cmd_args.userTimeFlag) printf("\t%s", "UTIME");
    if(cmd_args.systemTimeFlag) printf("\t%s", "STIME");
    if(cmd_args.vMemFlag) printf("\t%s", "VMEM");
    if(cmd_args.cmdLineFlag) printf("\t%s\n", "CMD");
}
