cmake_minimum_required(VERSION 3.12)
project(hw1 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw1 main.c parse_cmd_args.c parse_cmd_args.h cmd_line_args.c cmd_line_args.h)

# gcc -o 537ps main.c parse_cmd_args.c parse_cmd_args.h cmd_line_args.c cmd_line_args.h
