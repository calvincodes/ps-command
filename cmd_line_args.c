//
// Created by Arpit Jain on 9/23/18.
//

#include <stdio.h>
#include <stdbool.h>
#include "cmd_line_args.h"

// TODO: Check how to define global variable for default value of PID
cmdLineArg getDefaultInputArg() {

    cmdLineArg defaultInputArg;

    defaultInputArg.processIdFlag = 0;
    defaultInputArg.pid = -1L; // As PIDs are always non negative, i.e. >= 0, hence using default = -1
    defaultInputArg.stateFlag = 0;
    defaultInputArg.userTimeFlag = 1;
    defaultInputArg.systemTimeFlag = 1;
    defaultInputArg.vMemFlag = 0;
    defaultInputArg.cmdLineFlag = 0;

    return defaultInputArg;
}

void toString(cmdLineArg arg) {

    printf("{\n");
        printf("\t processIdFlag: %d\n", arg.processIdFlag);
        if (arg.pid >= 0) {
            printf("\t pid: %ld\n", arg.pid);
        }
        printf("\t stateFlag: %d\n", arg.stateFlag);
        printf("\t userTimeFlag: %d\n", arg.userTimeFlag);
        printf("\t systemTimeFlag: %d\n", arg.systemTimeFlag);
        printf("\t vMemFlag: %d\n", arg.vMemFlag);
        printf("\t cmdLineFlag: %d\n", arg.cmdLineFlag);
    printf("\n" "}");
}
