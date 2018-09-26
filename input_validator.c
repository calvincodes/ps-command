//
// Created by Arpit Jain on 9/25/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input_validator.h"

/**
 * This method validates if the arguments passed for various options are valid.
 * For example,
 * 1. -v- is the only valid option-argument pair, or
 * 2. -p abc is not a valid argument for process id
 * @param unprocessedInputArg inputArg object in vanilla format as typed by user
 */
void validate_unprocessed_input(struct_input unprocessedInputArg) {

    // Process Id flag has been passed as an input argument
    if (unprocessedInputArg.processIdFlag) {

        // No process id passed with -p
        if (unprocessedInputArg.processIdArg == NULL) {
            fprintf(stderr, "Pass process id with -p\n");
            exit(EXIT_FAILURE);
        }

        // Non-numeric process id passed with -p
        int processId = atoi (unprocessedInputArg.processIdArg);
        // As atoi returns 0 if the string param is not a number,
        // hence explicitly check if first element of processIdArg is actually 0.
        if (processId == 0 && unprocessedInputArg.processIdArg[0] != '0') {
            fprintf(stderr, "Process id should be a number\n");
            exit(EXIT_FAILURE);
        }
    }

    // If stateOptArg is passed, it should only be '-'
    if (unprocessedInputArg.stateOptArg != NULL
        && strcmp(unprocessedInputArg.stateOptArg, "-") != 0) {
        fprintf(stderr, "Argument for s should be - only\n");
        exit(EXIT_FAILURE);
    }

    // If userTimeOptArg is passed, it should only be '-'
    if (unprocessedInputArg.userTimeOptArg != NULL
        && strcmp(unprocessedInputArg.userTimeOptArg, "-") != 0) {
        fprintf(stderr, "Argument for U should be - only\n");
        exit(EXIT_FAILURE);
    }

    // If systemTimeOptArg is passed, it should only be '-'
    if (unprocessedInputArg.systemTimeOptArg != NULL
        && strcmp(unprocessedInputArg.systemTimeOptArg, "-") != 0) {
        fprintf(stderr, "Argument for S should be - only\n");
        exit(EXIT_FAILURE);
    }

    // If vMemOptArg is passed, it should only be '-'
    if (unprocessedInputArg.vMemOptArg != NULL
        && strcmp(unprocessedInputArg.vMemOptArg, "-") != 0) {
        fprintf(stderr, "Argument for v should be - only\n");
        exit(EXIT_FAILURE);
    }

    // If cmdLineOptArg is passed, it should only be '-'
    if (unprocessedInputArg.cmdLineOptArg != NULL
        && strcmp(unprocessedInputArg.cmdLineOptArg, "-") != 0) {
        fprintf(stderr, "Argument for c should be - only\n");
        exit(EXIT_FAILURE);
    }

}