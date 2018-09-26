//
// Created by Anshu on 9/26/18.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "access_validator.h"

int CHAR_SIZE = 255;
int ASCII_VALUE_OF_0 = 48;
int ASCII_VALUE_OF_9 = 57;
char PROC[]  =  "/proc/";
char STATUS_FILE[] = "status";

char *get_process_uid(char *directory_name, char *file_name) {
    FILE *file_pointer;
    char full_path[CHAR_SIZE];
    strcpy(full_path, PROC);
    char *line = NULL;
    size_t len = 0;
    strcat(full_path, directory_name);
    strcat(full_path, "/");
    strcat(full_path, file_name);
    file_pointer = fopen(full_path, "r");
    int index = 1;
    if (file_pointer != NULL) {
        while (getline(&line, &len, file_pointer) != -1 && index < 9) {
            index++;
        }
    } else {
        perror("Failed to read the file");
    }
    char *string_tokens;
    // This returns first character which is keyword UID
    string_tokens = strtok(line, "\t");
    //This returns actual UID
    string_tokens = strtok(NULL, "\t");
//        printf(" %s\n", string_tokens);

    return string_tokens;
}

bool is_process_belongs_to_user(char *user_id, char directory_name[], cmdLineArg postProcessedInput) {
    if (postProcessedInput.pid == -1) {
        char *process_uid = get_process_uid(directory_name, STATUS_FILE);
        if (strcmp(user_id, process_uid) != 0) {
            return false;
        }
    }
    return true;
}

bool is_valid_proc_directory(char *name, cmdLineArg postProcessedInput) {
    if (postProcessedInput.pid > -1) {
        if (strcmp(postProcessedInput.processIdArg, name) != 0) {
            return false;
        }
    }
    while (*name != '\0') {
        if (*name < ASCII_VALUE_OF_0 || *name > ASCII_VALUE_OF_9) {
            return false;
        }
        name++;
    }
    return true;
}

