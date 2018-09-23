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

int main(int argc, char *argv[]) {
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;

    bool processIdFlag = 0; // Flag for process id argument
    bool stateFlag = 0; // Default = 0. Flag for state argument
    bool userTimeFlag = 1; // Default = 1. Flag for userTime argument
    bool systemTimeFlag = 1; // Default = 1. Flag for userTime argument
    long pid;

    while ((opt = getopt(argc, argv, "p:sU::S::vc")) != -1) {

        switch (opt) {

            case 'p':
                processIdFlag = 1;
                pid = atoi(optarg);
                break;

            case 's':
                stateFlag = 1;
                break;

            case 'U':
                userTimeFlag = '0';
                break;

            case 'S':
                systemTimeFlag = '0';
                break;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
           flags, tfnd, nsecs, optind);

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }

    printf("name argument = %s\n", argv[optind]);
    printf("t argument = %s\n", argv[optind]);

    /* Other code omitted */

    exit(EXIT_SUCCESS);
}