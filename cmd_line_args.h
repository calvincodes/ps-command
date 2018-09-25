//
// Created by Arpit Jain on 9/23/18.
//

#ifndef HW1_CMD_LINE_ARGS_H
#define HW1_CMD_LINE_ARGS_H

#endif //HW1_CMD_LINE_ARGS_H

typedef struct cmdLineArg {

    bool processIdFlag; // Flag for process id argument
    char *processIdArg;
    long pid;

    bool stateFlag; // Default = 0. Flag for state argument
    char *stateOptArg;

    bool userTimeFlag; // Default = 1. Flag for userTime argument
    char *userTimeOptArg;

    bool systemTimeFlag; // Default = 1. Flag for userTime argument
    char *systemTimeOptArg;

    bool vMemFlag; // Default = 0. Flag for virtual memory
    char *vMemOptArg;

    bool cmdLineFlag; // Default = 0. Flag for virtual memory
    char *cmdLineOptArg;

} cmdLineArg;

cmdLineArg getDefaultInputArg();

void toString(cmdLineArg arg);