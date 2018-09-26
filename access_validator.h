//
// Created by Anshu on 9/26/18.
//

#ifndef HW1_ACCESS_VALIDATOR_H
#define HW1_ACCESS_VALIDATOR_H

#endif //HW1_ACCESS_VALIDATOR_H

#ifndef HW1_CMD_LINE_ARGS_H
#define HW1_CMD_LINE_ARGS_H
#include "struct_input.h"
#endif //HW1_CMD_LINE_ARGS_H





char *get_process_uid(char *directory_name, char *file_name);
bool is_valid_proc_directory(char *name, struct_input postProcessedInput);
bool is_process_belongs_to_user(char *user_id, char directory_name[], struct_input postProcessedInput);
