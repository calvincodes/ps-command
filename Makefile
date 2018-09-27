TARGET = 537ps

all: driver.c input_processing/input_parser.c entities/struct_input.c input_processing/input_validator.c input_processing/input_post_processor.c proc_processing/read_proc_dir.c constants/global.h proc_processing/access_validator.c proc_processing/proc_file_parser.c entities/struct_output.c
	gcc -g -Wall -Wextra -pedantic -o $(TARGET) driver.c input_processing/input_parser.c entities/struct_input.c input_processing/input_validator.c input_processing/input_post_processor.c proc_processing/read_proc_dir.c constants/global.h proc_processing/access_validator.c proc_processing/proc_file_parser.c entities/struct_output.c

clean:
	$(RM) $(TARGET)