#include <stdio.h>
#include <stdbool.h>
#include "struct_output.h"
#include "read.h"
#include <stdlib.h>
#include <string.h>
#include "input_parser.h"
#include "input_validator.h"

int validateInput(char input[]){
    return true;
}

char* readInput(){
    char *input = NULL;
    size_t  sizeOfInput;
    if (getline(&input, &sizeOfInput, stdin) != 0){
        printf("Failed to read input");
    }
    return input;
}

// I don't think I need this function
int getSizeOfInput(char input[]){
    int size = 0;
    while(input[size] != '\n'){
        printf("%c", input[size]);
        size++;
    }
    return size;
}

int splitInput(char input[]){
    const char delimiter[2] = " ";

}

int compare(const void * a, const void * b)
{
    struct struct_output *o1 = (struct struct_output *)a;
    struct struct_output *o2 = (struct struct_output *)b;
    return strcmp(o1->pid, o2->pid);

}


int main(int argc, char *argv[]) {

    cmdLineArg unprocessedInput = parseAndGetUnprocessedInput(argc, argv);
    validateUnprocessedInput(unprocessedInput);
    struct struct_output *output = read_directory();
    struct struct_output output_array[output->size];
    unsigned size = output->size;
    int index = 0;
    while(output != NULL){
        output_array[index] = *output;
        output = output->next;
    }
    qsort(output_array, size, sizeof(struct struct_output), compare);
    printf("\n");

}


