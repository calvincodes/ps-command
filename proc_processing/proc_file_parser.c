//
// Created by Anshu Verma on 9/26/18.
// Co-author Arpit Jain
//

#include "proc_file_parser.h"
#include <string.h>

void parse_stat_file(struct struct_output *node, char *line){
    char *string_tokens;
    string_tokens = strtok(line, " ");
    int index = 1; //index of the values in the file
    while (string_tokens != NULL) {
        switch (index) {
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
}

