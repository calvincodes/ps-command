#include <stdio.h>
#include <stdbool.h>

int validateInput(char input[]){
    return true;
}

char* readInput(){
    char *input = NULL;
    size_t  sizeOfInput;
    if (getline(&input, &sizeOfInput, stdin) != 0){
        printf("Failed to read input");
    }
    return input;
}

// I don't think I need this function
int getSizeOfInput(char input[]){
    int size = 0;
    while(input[size] != '\n'){
        printf("%c", input[size]);
        size++;
    }
    return size;
}

int splitInput(char input[]){
    const char delimiter[2] = " ";

}

//
//int main() {
//
//    return 0;
//}