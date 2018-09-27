//
// Created by Arpit Jain on 9/23/18.
// Co-author Anshu Verma
//

#include <stdio.h>
#include <stdbool.h>
#include "struct_input.h"

/**
 * This method created a inputArg with default values and all argument pointers as null
 * @return inputArg with default values and all argument pointers as null
 */
struct_input get_default_input_arg() {

    struct_input defaultInputArg;

    defaultInputArg.processIdFlag = false;
    defaultInputArg.processIdArg = NULL;
    // TODO: Add default value of PID to global.h
    defaultInputArg.pid = -1L; // As PIDs are always non negative, i.e. >= 0, hence using default = -1

    defaultInputArg.stateFlag = false;
    defaultInputArg.stateOptArg = NULL;

    defaultInputArg.userTimeFlag = true;
    defaultInputArg.userTimeOptArg = NULL;

    defaultInputArg.systemTimeFlag = false;
    defaultInputArg.systemTimeOptArg = NULL;

    defaultInputArg.vMemFlag = false;
    defaultInputArg.vMemOptArg = NULL;

    defaultInputArg.cmdLineFlag = true;
    defaultInputArg.cmdLineOptArg = NULL;

    return defaultInputArg;
}

void to_string(struct_input arg) {

    printf("\n");
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
    printf("\n");
}
