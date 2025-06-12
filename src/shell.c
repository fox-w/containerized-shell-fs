/*
Date: 06/11/2025
Author: William Fox

This program establishes functionality for a basic shell that can tokenize inputs and execute commands
*/

// What does the shell need to do?
// ✔ Prompt: $
// ✔ Wait for user input.
// ✔ Read the input command.
// ✔ Tokenize the command string into an array of strings.
// Execute the command using execvp or a similar function.
// Handle errors if the command fails to execute.
// Handle built-in commands like 'exit' or 'cd'.

#include <stdio.h>

#include "tokenizer.h"

int main(){

    char line[200];

    printf("$ ");
    fgets(line, sizeof(line), stdin);

    #ifdef DEBUG
    printf("You entered: %s\n", line);
    #endif

    char* *tokensArr = tokenize(line);

    #ifdef DEBUG
    // add something to print tokens
    int tokenIndex = 0;
    printf("Tokens:\n");
    while (tokensArr[tokenIndex] != NULL)
    {
        printString(tokensArr[tokenIndex]);
        if (tokensArr[tokenIndex+1] == NULL){
            printf("\n");
            break;
        }
        printf(",");
        tokenIndex++;
    }
    #endif
    

    return 0;
}