//
// Created by Arpit Jain on 9/25/18.
//

#include <stddef.h>
#include <stdlib.h>
#include "input_post_processor.h"

/**
 * This method applies the functionality of relevant option arguments to the options.
 * For example, if -U- is passed by user, then flag for userTime will be turned off by this method.
 * NOTE: This method ASSUMES that the input cmdLineArg object is pre-VALIDATED.
 * @param unprocessedInput pre-validated cmdLineArg object as per user input
 * @return processed and updated cmdLineArg as per option arguments
 */
cmdLineArg getPostProcessedInput(cmdLineArg unprocessedInput) {

    if (unprocessedInput.processIdFlag == true) {
        char *ptr;
        unprocessedInput.pid = strtol(unprocessedInput.processIdArg, &ptr, 10);
    }

    if (unprocessedInput.userTimeOptArg != NULL && *unprocessedInput.userTimeOptArg == '-') {
        unprocessedInput.userTimeFlag = false;
    }

    if (unprocessedInput.cmdLineOptArg != NULL && *unprocessedInput.cmdLineOptArg == '-') {
        unprocessedInput.cmdLineFlag = false;
    }

    return unprocessedInput;
}