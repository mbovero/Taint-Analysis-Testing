// example.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that simulates getting user input
char* getUserInput() {
    char* input = (char*)malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    return input;
}

// Function that processes input
void processInput(char* input, char* buffer) {
    strcpy(buffer, input); // Potentially dangerous if input is not properly sanitized
}

// Function that executes a command
void executeCommand(char* command) {
    system(command); // Vulnerable to command injection if command is tainted
}

int main() {
    char* userInput = getUserInput();
    char buffer[100];
    processInput(userInput, buffer);
    executeCommand(buffer);
    free(userInput);
    return 0;
}
