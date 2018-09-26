TARGET = 537ps

all: main.c input_parser.c cmd_line_args.c input_validator.c input_post_processor.c
	gcc -g -Wall -Wextra -pedantic -o $(TARGET) main.c input_parser.c cmd_line_args.c input_validator.c input_post_processor.c

clean:
	$(RM) $(TARGET)