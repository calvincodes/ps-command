# Co-author Anshu Verma
# Co-author Arpit Jain

cmake_minimum_required(VERSION 3.12)
project(hw1 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw1 driver.c input_processing/input_parser.c input_processing/input_parser.h entities/struct_input.c entities/struct_input.h input_processing/input_validator.c input_processing/input_validator.h input_processing/input_post_processor.c input_processing/input_post_processor.h proc_processing/read_proc_dir.c proc_processing/read_proc_dir.h entities/struct_output.c entities/struct_output.h proc_processing/proc_file_parser.c proc_processing/proc_file_parser.h proc_processing/access_validator.c proc_processing/access_validator.h)
