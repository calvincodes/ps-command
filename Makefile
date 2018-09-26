TARGET = 537ps

all: driver.c input_parser.c struct_input.c input_validator.c input_post_processor.c read_proc_dir.c global.h access_validator.c proc_file_parser.c struct_output.c
	gcc -g -Wall -Wextra -pedantic -o $(TARGET) driver.c input_parser.c struct_input.c input_validator.c input_post_processor.c read_proc_dir.c global.h access_validator.c proc_file_parser.c struct_output.c

clean:
	$(RM) $(TARGET)