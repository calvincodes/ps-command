//
// Created by Arpit Jain on 9/23/18.
//

#ifndef HW1_CMD_LINE_ARGS_H
#define HW1_CMD_LINE_ARGS_H

#endif //HW1_CMD_LINE_ARGS_H

#include <stdbool.h>

typedef struct cmdLineArg {

    bool processIdFlag; // Flag for process id argument
    long pid;
    bool stateFlag; // Default = 0. Flag for state argument
    bool userTimeFlag; // Default = 1. Flag for userTime argument
    bool systemTimeFlag; // Default = 1. Flag for userTime argument
    bool vMemFlag; // Default = 0. Flag for virtual memory
    bool cmdLineFlag; // Default = 0. Flag for virtual memory

} cmdLineArg;

cmdLineArg getDefaultInputArg();

void toString(cmdLineArg arg);