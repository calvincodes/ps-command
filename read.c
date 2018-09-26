//
// Created by Anshu on 9/24/18.
//

#include "read.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "global.h"
//#include "struct_output.h"

bool is_valid_proc_directory(char *name, cmdLineArg postProcessedInput){
    if(postProcessedInput.pid > -1){
        if(strcmp(postProcessedInput.processIdArg, name) != 0){
            return false;
        }
    }
    while(*name != '\0'){
        if(*name < ASCII_OF_0 || *name > ASCII_OF_9) {
            return false;
        }
        name++;
    }
    return true;
}

char* read_file(char directory_name[], char file_name[CHAR_SIZE]){
    FILE* file_pointer;
    char full_path[CHAR_SIZE] ;
    strcpy(full_path, FULL_PATH);
    char *line = NULL;
    size_t len = 0;
    strcat(full_path, directory_name);
    strcat(full_path , "/");
    strcat(full_path,file_name);
    file_pointer = fopen(full_path, "r");
    if(file_pointer != NULL){
        getline(&line, &len, file_pointer) ;
    } else{
        perror("Failed to read the file");
    }
    fclose(file_pointer);
    return line;
}

char* get_process_uid(char *directory_name, char *file_name){
    FILE* file_pointer;
    char full_path[CHAR_SIZE] ;
    strcpy(full_path, FULL_PATH);
    char *line = NULL;
    size_t len = 0;
    strcat(full_path, directory_name);
    strcat(full_path , "/");
    strcat(full_path,file_name);
    file_pointer = fopen(full_path, "r");
    int index = 1;
    if(file_pointer != NULL){
        while (getline(&line, &len, file_pointer) != -1 && index < 9){
            index++;
        }
    } else{
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

bool is_process_belongs_to_user(char *user_id,char directory_name[], cmdLineArg postProcessedInput ){
    if(postProcessedInput.pid == -1){
        char *process_uid = get_process_uid(directory_name, STATUS_FILE_NAME);
        if (strcmp(user_id, process_uid) != 0){
            return false;
        }
    }
    return true;
}

struct struct_output* read_directory(cmdLineArg postProcessedInput){
    // Holds directory structure of /proc folder
    DIR *proc;
    struct dirent *subDirectory;
    struct struct_output *output = NULL;
    struct struct_output *head = NULL;
    unsigned size =0;
    unsigned int uid_t = getuid();
    char uid[CHAR_SIZE];
    sprintf(uid, "%d", uid_t);


//    struct struct_output *output;

    /*
     * Path where the process will be residing
     */
    // Opening directory /proc
    proc = opendir(FULL_PATH);
    while((subDirectory = readdir(proc)) != NULL){

        /*
         * Ignore links to current and previous directory
         */
        if(strcmp(subDirectory->d_name, CURRENT_DIRECTORY) == 0 || strcmp(subDirectory->d_name, PREVIOUS_DIRECTORY) == 0){
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
        if (fstatat(dirfd(proc), subDirectory->d_name, &entry_info, 0) < 0) {
            continue;
        }
        /*
         * To check if the entry read is a directory or not.
         * And file_name should be all number
         */
        if (S_ISDIR(entry_info.st_mode) &&
            is_valid_proc_directory(subDirectory->d_name, postProcessedInput)
            && is_process_belongs_to_user(uid, subDirectory->d_name,postProcessedInput )) {

            char *line = read_file(subDirectory->d_name, STAT_FILE_NAME);
            char *string_tokens;
            struct struct_output *node = malloc(sizeof *node);
            string_tokens = strtok(line, " ");
            int index = 1; //index of the values in the file
            while (string_tokens != NULL){
                switch (index){
                    case 1:
                        node->pid = string_tokens;
                        break;
                    case 3:
                        node->status = string_tokens;
                        break;
                    case 14:
                        node->utime = string_tokens;
                        break;
                    case 15:
                        node->stime = string_tokens;
                        break;
                    case 23:
                        node->virtual_memory = string_tokens;
                        break;
                }
                string_tokens = strtok(NULL, " ");
                index++;
            }
            line = read_file(subDirectory->d_name, CMDLINE_FILE_NAME);
            node->command_line = line;
            if(!output){
                output = node;
                head = node;
                output->next = NULL;
                size++;
            } else{
                output->next = node;
                node ->next = NULL;
                output = output ->next;
                size++;
            }
        }

    }
    head->size = size;
    closedir(proc);
    return  head;
}
