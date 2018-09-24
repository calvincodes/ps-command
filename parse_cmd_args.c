//
//
//
/**
 * Created by Arpit Jain on 9/22/18.
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "cmd_line_args.h"

int main(int argc, char *argv[]) {

    int opt;

    bool processIdFlag = 0; // Flag for process id argument
    bool stateFlag = 0; // Default = 0. Flag for state argument
    bool userTimeFlag = 1; // Default = 1. Flag for userTime argument
    bool systemTimeFlag = 1; // Default = 1. Flag for userTime argument
    long pid;

    while ((opt = getopt(argc, argv, "p:s::U::S::vc")) != -1) {

        switch (opt) {

            case 'p':
                processIdFlag = 1;
                pid = atoi(optarg);
                printf("Detected p with process id %lu \n", pid);
                break;

            case 's':
                stateFlag = 1;
                printf("Detected s \n");
                break;

            case 'U':
                userTimeFlag = '0';
                printf("Detected U \n");
                break;

            case 'S':
                systemTimeFlag = '0';
                printf("Detected S \n");
                break;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }

//    if (optind >= argc) {
//        fprintf(stderr, "Expected argument after options\n");
//        exit(EXIT_FAILURE);
//    }

//    printf("name argument = %s\n", argv[optind]);
//    printf("t argument = %s\n", argv[optind]);

    exit(EXIT_SUCCESS);
}