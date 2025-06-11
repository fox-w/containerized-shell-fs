#include <stdio.h>

#include "tokenizer.h"

// TODO test with "my tokenizer works now buddy" because that made it fail for some reason

int main(){
    // This is a simple C program that does nothing.
    // It serves as a placeholder for future shell implementation.

    char line[200];

    printf("$");
    fgets(line, sizeof(line), stdin);
    printf("%s is what you entered bruh\n", line);

    char* *tokensArr = tokenize(line);

    // add something to print tokens
    int tokenIndex = 0;
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
    

    return 0;
}

// What does the shell need to do?
// ✔ Prompt: $
// ✔ Wait for user input.
// ✔ Read the input command.
// Parse the command into arguments.
// Tokenize the command string into an array of strings.
// Execute the command using execvp or a similar function.
// Handle errors if the command fails to execute.
// Handle built-in commands like 'exit' or 'cd'.