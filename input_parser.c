//
// Created by Arpit Jain on 9/22/18.
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cmd_line_args.h"

cmdLineArg parseAndGetUnprocessedInput(int argc, char **argv) {

    int optionAsInt;

    cmdLineArg unprocessedInputArg = getDefaultInputArg();

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

    if (argc > optind) {
        fprintf(stderr, "Redundant argument %s passed\n", argv[argc-1]);
        exit(EXIT_FAILURE);
    }

    return unprocessedInputArg;
}