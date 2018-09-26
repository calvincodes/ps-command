//
// Created by Arpit Jain on 9/25/18.
//
#include <stdlib.h>
#include <stdio.h>
#include "input_validator.h"

void validateUnprocessedInput(cmdLineArg unprocessedInputArg) {

    // TODO: Check if you can add a NULL check on unprocessedInputArg

    // Process Id flag has been passed as an input argument
    if (unprocessedInputArg.processIdFlag) {

        if (unprocessedInputArg.processIdArg == NULL) {
            fprintf(stderr, "Pass process id with -p");
            exit(EXIT_FAILURE);
        }

        int processId = atoi (unprocessedInputArg.processIdArg);
        if (processId == 0 && unprocessedInputArg.processIdArg[0] != '0') {
            fprintf(stderr, "Process id should be a number");
            exit(EXIT_FAILURE);
        }
    }

    if (unprocessedInputArg.stateOptArg != NULL
            && *unprocessedInputArg.stateOptArg != '-') {
        fprintf(stderr, "Argument for s should be - only");
        exit(EXIT_FAILURE);
    }

    if (unprocessedInputArg.userTimeOptArg != NULL
            && *unprocessedInputArg.userTimeOptArg != '-') {
        fprintf(stderr, "Argument for U should be - only");
        exit(EXIT_FAILURE);
    }

    if (unprocessedInputArg.systemTimeOptArg != NULL
            && *unprocessedInputArg.systemTimeOptArg != '-') {
        fprintf(stderr, "Argument for S should be - only");
        exit(EXIT_FAILURE);
    }

    if (unprocessedInputArg.vMemOptArg != NULL
            && *unprocessedInputArg.vMemOptArg != '-') {
        fprintf(stderr, "Argument for v should be - only");
        exit(EXIT_FAILURE);
    }

    if (unprocessedInputArg.cmdLineOptArg != NULL
            && *unprocessedInputArg.cmdLineOptArg != '-') {
        fprintf(stderr, "Argument for c should be - only");
        exit(EXIT_FAILURE);
    }

}