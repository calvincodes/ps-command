#ifndef HW1_STRUCT_OUTPUT_H
#define HW1_STRUCT_OUTPUT_H

#include <stdio.h>
#include <stdbool.h>
#include "struct_output.h"
#include "read.h"
#include <stdlib.h>
#include <string.h>
#include "input_parser.h"
#include "input_validator.h"
#include "input_post_processor.h"

#endif


int compare_struct(const void *a, const void *b) {
    struct struct_output *o1 = (struct struct_output *) a;
    struct struct_output *o2 = (struct struct_output *) b;
    return strcmp(o1->pid, o2->pid);


}

int main(int argc, char *argv[]) {
    cmdLineArg unprocessedInput = parseAndGetUnprocessedInput(argc, argv);
    validateUnprocessedInput(unprocessedInput);
    cmdLineArg postProcessedInput = getPostProcessedInput(unprocessedInput);
    struct struct_output *output = read_directory(postProcessedInput);

    if (output != NULL) {
        struct struct_output output_array[output->size];
        int size = output->size;
        int index = 0;
        while (output != NULL) {
            output_array[index] = *output;
            output = output->next;
            index++;
        }
        qsort(output_array, size, sizeof(struct struct_output), compare_struct);

        for (int i = 0; i < size; i++) {
            print(output_array[i], postProcessedInput);
        }
    } else if (postProcessedInput.pid > -1) {
        printf("PID: %s not found.", postProcessedInput.processIdArg);
    }

}

