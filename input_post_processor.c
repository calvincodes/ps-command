//
// Created by Arpit Jain on 9/25/18.
//

#include <stddef.h>
#include "input_post_processor.h"

cmdLineArg getPostProcessedInput(cmdLineArg unprocessedInput) {

    if (unprocessedInput.userTimeOptArg != NULL && *unprocessedInput.userTimeOptArg == '-') {
        unprocessedInput.userTimeFlag = false;
    }

    if (unprocessedInput.cmdLineOptArg != NULL && *unprocessedInput.cmdLineOptArg == '-') {
        unprocessedInput.cmdLineFlag = false;
    }

    return unprocessedInput;
}