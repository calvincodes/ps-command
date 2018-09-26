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
#include "global.h"
//#include "struct_output.h"

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


        printf("Value of line %s\n", line);
    } else{
        perror("Failed to read the file");
    }
    fclose(file_pointer);
    return line;
}


struct_output* read_directory(){
    // Holds directory structure of /proc folder
    DIR *proc;
    struct dirent *subDirectory;
    struct struct_output *output = NULL;
    struct struct_output *head = NULL;
    unsigned size =0;


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
         */
        if (fstatat(dirfd(proc), subDirectory->d_name, &entry_info, 0) < 0) {
            continue;
        }
        /*
         * To check if the entry read is a directory or not.
         * And file_name should be all number
         */
        if (S_ISDIR(entry_info.st_mode) && is_valid_proc_directory(subDirectory->d_name)) {
            char *line = read_file(subDirectory->d_name, STAT_FILE_NAME);
            printf("%s\n", line);
            char *string_tokens;
            struct struct_output *node = malloc(sizeof *node);
            string_tokens = strtok(line, " ");
            int index = 1; //index of the values in the file
            while (string_tokens != NULL){
                switch (index){
                    case 1:
                        *node->pid = *string_tokens;
                        break;
                    case 3:
                        *node->status = *string_tokens;
                        break;
                    case 14:
                        *node->utime = *string_tokens;
                        break;
                    case 15:
                        *node->stime = *string_tokens;
                        break;
                    case 23:
                        *node->virtual_memory = *string_tokens;
                        break;
                }
                string_tokens = strtok(NULL, " ");
                index++;
            }
            line = read_file(subDirectory->d_name, CMDLINE_FILE_NAME);
            *node->command_line = *line;
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

            printf("\n");

            printf("%s\n", line);


//            printf("%s \n",subDirectory->d_name);
        }

    }
    head->size = size;
    closedir(proc);
    return  head;
}

int compare(const void * a, const void * b)
{
    struct struct_output *o1 = (struct struct_output *)a;
    struct struct_output *o2 = (struct struct_output *)b;
    return strcmp(o1->pid, o2->pid);

}

int main(){
    struct_output *output = read_directory();
    struct_output output_array[output->size];
    unsigned size = output->size;
    int index = 0;
    while(output != NULL){
        output_array[index] = *output;
        output = output->next;
    }
    qsort(output_array, size, sizeof(struct_output), compare);
    printf("\n");
    for(int i=0;i<size;i++){
        // pass command_line argument then print will handle all conditions
//        print(output_array[i]);
    }

}

