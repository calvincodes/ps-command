//
// Created by Anshu on 9/24/18.
//

#include <stdio.h>
#include "struct_output.h"

void print(struct_output arg, cmdLineArg cmd_args) {

    printf("\n");
    if(cmd_args.pid > -1) printf("%s", arg.pid);
    if(cmd_args.stateFlag) printf("\t%c", arg.status);
    if(cmd_args.userTimeFlag) printf("\t%s",arg.utime);
    if(cmd_args.systemTimeFlag) printf("\t%s", arg.stime);
    if(cmd_args.vMemFlag) printf("\t%s", arg.virtual_memory);
    if(cmd_args.cmdLineFlag) printf("\t%s", arg.command_line);
}
