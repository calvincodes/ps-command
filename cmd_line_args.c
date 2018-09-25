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
    defaultInputArg.processIdArg = NULL;
    defaultInputArg.pid = -1L; // As PIDs are always non negative, i.e. >= 0, hence using default = -1

    defaultInputArg.stateFlag = 0;
    defaultInputArg.stateOptArg = NULL;

    defaultInputArg.userTimeFlag = 1;
    defaultInputArg.userTimeOptArg = NULL;

    defaultInputArg.systemTimeFlag = 0;
    defaultInputArg.systemTimeOptArg = NULL;

    defaultInputArg.vMemFlag = 0;
    defaultInputArg.vMemOptArg = NULL;

    defaultInputArg.cmdLineFlag = 1;
    defaultInputArg.cmdLineOptArg = NULL;

    return defaultInputArg;
}

void toString(cmdLineArg arg) {

    printf("{\n");
        printf("\t processIdFlag: %d\n", arg.processIdFlag);
        printf("\t processIdArg: %s\n", arg.processIdArg);
        if (arg.pid >= 0) {
            printf("\t pid: %ld\n", arg.pid);
        }

        printf("\t stateFlag: %d\n", arg.stateFlag);
        printf("\t stateOptArg: %s\n", arg.stateOptArg);

        printf("\t userTimeFlag: %d\n", arg.userTimeFlag);
        printf("\t userTimeOptArg: %s\n", arg.userTimeOptArg);

        printf("\t systemTimeFlag: %d\n", arg.systemTimeFlag);
        printf("\t systemTimeOptArg: %s\n", arg.systemTimeOptArg);

        printf("\t vMemFlag: %d\n", arg.vMemFlag);
        printf("\t vMemOptArg: %s\n", arg.vMemOptArg);

        printf("\t cmdLineFlag: %d\n", arg.cmdLineFlag);
        printf("\t cmdLineOptArg: %s\n", arg.cmdLineOptArg);
    printf("\n" "}");
}
