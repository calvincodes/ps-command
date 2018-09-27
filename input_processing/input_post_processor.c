//
// Created by Arpit Jain on 9/25/18.
// Co-author Anshu Verma
//

#include <stddef.h>
#include <stdlib.h>
#include "input_post_processor.h"

/**
 * This method applies the functionality of relevant option arguments to the options.
 * For example, if -U- is passed by user, then flag for userTime will be turned off by this method.
 * NOTE: This method ASSUMES that the input inputArg object is pre-VALIDATED.
 * @param unprocessedInput pre-validated inputArg object as per user input
 * @return processed and updated inputArg as per option arguments
 */
struct_input get_post_processed_input(struct_input unprocessedInput) {

    if (unprocessedInput.processIdFlag == true) {
        char *ptr;
        unprocessedInput.pid = strtol(unprocessedInput.processIdArg, &ptr, 10);
    }

    if (unprocessedInput.stateOptArg != NULL && *unprocessedInput.stateOptArg == '-') {
        unprocessedInput.stateFlag = false;
    }

    if (unprocessedInput.userTimeOptArg != NULL && *unprocessedInput.userTimeOptArg == '-') {
        unprocessedInput.userTimeFlag = false;
    }

    if (unprocessedInput.systemTimeOptArg != NULL && *unprocessedInput.systemTimeOptArg == '-') {
        unprocessedInput.systemTimeFlag = false;
    }

    if (unprocessedInput.vMemOptArg != NULL && *unprocessedInput.vMemOptArg == '-') {
        unprocessedInput.vMemFlag = false;
    }

    if (unprocessedInput.cmdLineOptArg != NULL && *unprocessedInput.cmdLineOptArg == '-') {
        unprocessedInput.cmdLineFlag = false;
    }

    return unprocessedInput;
}