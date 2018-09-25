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
#include "global.h"

bool is_valid_proc_directory(char *name){
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
//            printf("%s\n", line);
//            char *string_tokens;
//            string_tokens = strtok(line, " ");
//            while (string_tokens != NULL){
////                printf("%s \n", string_tokens);
//                string_tokens = strtok(NULL, " ");
//            }

        printf("Value of line %s\n", line);
    } else{
        perror("Failed to read the file");
    }
    fclose(file_pointer);
    return line;
}

void read_directory(){
    // Holds directory structure of /proc folder
    DIR *proc;
    struct dirent *subDirectory;

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
         */
        if (fstatat(dirfd(proc), subDirectory->d_name, &entry_info, 0) < 0) {
            continue;
        }
        /*
         * To check if the entry read is a directory or not.
         * And file_name should be all number
         */
        if (S_ISDIR(entry_info.st_mode) && is_valid_proc_directory(subDirectory->d_name)) {
            read_file(subDirectory->d_name, CMDLINE_FILE_NAME);
            printf("\n");
            read_file(subDirectory->d_name, STAT_FILE_NAME);
//            printf("%s \n",subDirectory->d_name);
        }

    }
    closedir(proc);

}



int main(){
    read_directory();
}

