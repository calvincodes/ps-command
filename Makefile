# build an executable named myprog from myprog.c
all: main.c input_parser.c cmd_line_args.c input_validator.c input_post_processor.c
	gcc -g -Wall -Wextra -pedantic -o 537ps main.c input_parser.c cmd_line_args.c input_validator.c input_post_processor.c

clean:
	$(RM) 537ps