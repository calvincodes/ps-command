//
// Created by Arpit Jain on 9/23/18.
//

#include <stdio.h>
#include <stdbool.h>
#include "cmd_line_args.h"

void toString(cmdLineArg arg) {

    printf("{\n"
               "\t processIdFlag: %d\n"
               "\t pid: %ld\n"
               "\t stateFlag: %d\n"
               "\t userTimeFlag: %d\n"
               "\t systemTimeFlag: %d\n"
               "\t vMemFlag: %d\n"
               "\t cmdLineFlag: %d\n"
               "\n"
           "}", arg.processIdFlag, arg.pid,
               arg.stateFlag, arg.userTimeFlag, arg.systemTimeFlag, arg.vMemFlag, arg.cmdLineFlag);
}
