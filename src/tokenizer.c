#include "tokenizer.h"


char* *tokenize(char* inputString)
{
    printf("---tokenizer func---\n");
    // This function is a placeholder for the actual tokenization logic.
    // It should split the input_string into tokens based on whitespace and return an array of strings.
    // An array of strings is just an array of char array pointers char string[]
    // So we need to create new char arrays for each new string we encounter

    // To start, lets figure out how to get every char until we find whitespace
    // uint8_t i = 0;
    // while (inputString[i] != '\0')
    // {
    //     printf("%c", inputString[i]);
    //     i++;
    //     if (inputString[i] == ' ')
    //     {
    //         printf("%c", '\n');
    //         break;
    //     }
    // }
    
    // Now, how do we store each of those chars in a char array
    uint8_t i = 0;
    uint8_t charsSinceWhitespace = 0;
    char* *tokens = malloc(sizeof(char*) * 4);
    uint8_t nextOpenTokenIndex = 0;
    uint8_t tokensCap = 4;
    while (inputString[i] != '\0')
    {
        printf("Input string char is %c\n", inputString[i]);
        if (inputString[i] == ' ' || inputString[i] == '\t' || inputString[i] == '\n')
        {
            if (charsSinceWhitespace > 0)
            {
                // check if there is space in tokens, and if not, realloc memory with double size
                if (nextOpenTokenIndex > tokensCap - 1)
                {
                    tokensCap *= 2;
                    tokens = realloc(tokens, tokensCap * sizeof(char*));
                    printf("-------------doubled memory of tokens\n");
                    if (tokens == NULL)
                    {
                        perror("Failed to allocate memory");
                        return NULL;
                    }
                }
                // create new mem location with the size of the string and copy the token in
                tokens[nextOpenTokenIndex] = malloc(sizeof(char) * (charsSinceWhitespace + 1));
                memcpy(tokens[nextOpenTokenIndex], &inputString[i-charsSinceWhitespace], charsSinceWhitespace);
                printf("copied new token %s| into tokens array\n", tokens[nextOpenTokenIndex]);
                tokens[nextOpenTokenIndex][charsSinceWhitespace] = '\0';
                // now that the string is copied, increment nextOpenTokenIndex
                nextOpenTokenIndex++;
                charsSinceWhitespace = 0;
            }
        }
        else
        {
            charsSinceWhitespace++;
        }
        i++;
        printf("incremented i to %i and token is %c|\n", i, inputString[i]);
    }    
    
    return tokens;  // 
}

void printString(char* arrPtr)
{
    int index = 0;
    while(arrPtr[index] != '\0')
    {
        printf("%c", arrPtr[index]);
        index++;
    }
}