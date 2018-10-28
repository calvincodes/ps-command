# 537ps

A simple version of the ps command, called 537ps which can be executed from a command line.

## Task List

This project is divided in 3 major modules.

* **entities**: Comprises of struct_input and struct_output, which are the entity mapping of user input and display output respectively.

* **input_processing**: Comprises of the following sub modules.
    * input_parser: Parses the input arguments and formulates a corresponding struct_input object.
    * input_validator: Validates if the arguments passed for various options are valid.
    * input_post_processor: Applies the functionality of relevant option arguments to the options.

* **proc_processing**:
    * Iterated over /proc directory.
    * Verifying the correct process folders.
    * Reading stat, status and cmdLine file and parsing the contents of the file to find the required output data.
    * After parsing, enriching all the data back in output structure.
    * Verifying if the active userId belongs to process' user id
    * Displaying all the output on the screen with proper formatting and sequence.
    * Handling cases if the requested process is not found or if the files/directories being read do not have enough permission.

* **driver.c** is the driver module for the entire project.

## Authors

* **Arpit Jain**
* **Anshu Verma**
