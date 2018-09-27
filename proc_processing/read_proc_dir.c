//
// Created by Anshu on 9/24/18.
//

#include "read_proc_dir.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "../constants/global.h"
#include "proc_file_parser.h"
#include "access_validator.h"

char *read_file(char directory_name[], char file_name[SIZE_OF_CHAR]) {
    FILE *file_pointer;
    char full_path[SIZE_OF_CHAR];
    strcpy(full_path, FULL_PATH);
    char *line = NULL;
    size_t len = 0;
    strcat(full_path, directory_name);
    strcat(full_path, "/");
    strcat(full_path, file_name);
    file_pointer = fopen(full_path, "r");
    if (file_pointer != NULL) {
        getline(&line, &len, file_pointer);
    } else {
        perror("Failed to read the file");
    }
    fclose(file_pointer);
    return line;
}

struct struct_output *read_directory(struct_input postProcessedInput) {
    // Holds directory structure of /proc folder
    DIR *proc;
    struct dirent *entry;
    struct struct_output *output = NULL;
    struct struct_output *head = NULL;
    unsigned size = 0;
    unsigned int uid_t = getuid();
    char uid[SIZE_OF_CHAR];
    sprintf(uid, "%d", uid_t);

    /*
     * Path where the process will be residing
     */
    // Opening directory /proc
    proc = opendir(FULL_PATH);
    while ((entry = readdir(proc)) != NULL) {

        /*
         * Ignore links to current and previous directory
         */
        if (strcmp(entry->d_name, CURRENT_DIRECTORY) == 0 ||
            strcmp(entry->d_name, PREVIOUS_DIRECTORY) == 0) {
            continue;
        }

        struct stat entry_info;
        /*
         * fstatat is similar to stat except it can take relative path
         * First argument - file descriptor to the parent directory
         * Second argument -  name of the entry
         * Third argument - Information about the entry being read
         * If if fails then that means you don't have enough permission to view the directory
         */
        if (fstatat(dirfd(proc), entry->d_name, &entry_info, 0) < 0) {
            continue;
        }
        /*
         * To check if the entry read is a directory or not.
         * And file_name should be all number
         */
        if (S_ISDIR(entry_info.st_mode) &&
            is_valid_proc_directory(entry->d_name, postProcessedInput)
            && is_process_belongs_to_user(uid, entry->d_name, postProcessedInput)) {

            char *line = read_file(entry->d_name, STAT_FILE_NAME);

            struct struct_output *node = malloc(sizeof *node);
            parse_stat_file(node, line);

            line = read_file(entry->d_name, CMDLINE_FILE_NAME);
            node->command_line = line;
            if (!output) {
                output = node;
                head = node;
                output->next = NULL;
                size++;
            } else {
                output->next = node;
                node->next = NULL;
                output = output->next;
                size++;
            }
        }

    }
    if(head != NULL) {
        head->size = size;
    }
    closedir(proc);
    return head;
}
