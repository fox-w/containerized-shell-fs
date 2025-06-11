// how to tokenize a string in C
// input to tokenizer should be a string containing the input command to be tokenized
// output should be a char array of string (array of pointers to char objects)
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
tokenizer.h
This header file declares the function for tokenizing a string input into an array of strings.
*/

/*
tokenize function
This function takes a string input and tokenizes it into an array of strings based on whitespace.
It returns a pointer to the first element of the array of strings.
It is assumed that the input string is dynamically allocated and will be modified by the tokenizer.
The function will allocate memory for the array of strings and the individual tokens.
It is the caller's responsibility to free the allocated memory after use.
args:
input_string: A pointer to a null-terminated string that contains the input command to be tokenized.
returns:
A pointer to an array of strings (char**) where each string is a token from the input command.
*/
char* *tokenize(char* input_string);
void printString(char* arrPtr);