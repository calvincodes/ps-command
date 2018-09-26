cmake_minimum_required(VERSION 3.12)
project(hw1 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw1 main.c input_parser.c input_parser.h cmd_line_args.c cmd_line_args.h input_validator.c input_validator.h input_post_processor.c input_post_processor.h read.c read.h struct_output.c struct_output.h)

# gcc -o 537ps main.c input_parser.c cmd_line_args.c input_validator.c input_post_processor.c
