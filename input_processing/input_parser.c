//
// Created by Arpit Jain on 9/22/18.
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../entities/struct_input.h"

/**
 * This methods parses the input arguments and formulates a corresponding inputArg object
 * @param argc count of arguments passed along with the command
 * @param argv array of arguments passed along with the command
 * @return inputArg object as per the user input
 */
struct_input parse_and_get_unprocessed_input(int argc, char **argv) {

    int optionAsInt;

    struct_input unprocessedInputArg = get_default_input_arg();

    while ((optionAsInt = getopt(argc, argv, "p:s::U::S::v::c::")) != -1) {

        switch (optionAsInt) {

            case 'p':
                unprocessedInputArg.processIdFlag = true;
                unprocessedInputArg.processIdArg = optarg;
                break;

            case 's':
                unprocessedInputArg.stateFlag = true;
                unprocessedInputArg.stateOptArg = optarg;
                break;

            case 'U':
                unprocessedInputArg.userTimeFlag = true;
                unprocessedInputArg.userTimeOptArg = optarg;
                break;

            case 'S':
                unprocessedInputArg.systemTimeFlag = true;
                unprocessedInputArg.systemTimeOptArg = optarg;
                break;

            case 'v':
                unprocessedInputArg.vMemFlag = true;
                unprocessedInputArg.vMemOptArg = optarg;
                break;

            case 'c':
                unprocessedInputArg.cmdLineFlag = true;
                unprocessedInputArg.cmdLineOptArg = optarg;
                break;

            default: // Error Input Option
                fprintf(stderr, "Usage: %s [-p <pid>] [-s] [-U] [-S] [-v] [-c]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // INTERESTING ONE HERE :)
    // In case the user passes some redundant arguments, say 537ps -p 123 -v ABC
    // now, for this case, the count of arguments passed > the count of (option + option argument) read.
    // So, putting the same as a if clause to detect this anomaly and report error.
    if (argc > optind) {
        fprintf(stderr, "Redundant argument %s passed\n", argv[argc-1]);
        exit(EXIT_FAILURE);
    }

    return unprocessedInputArg;
}