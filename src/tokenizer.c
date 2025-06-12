#include "tokenizer.h"

/*
tokenize: splits an array of chars as as input into an array of pointers to char arrays, each a different "token"
args:
    inputString: char*
returns:
    **tokens (pointer to array of tokens, each a char array)
*/
char* *tokenize(char* inputString)
{
    uint8_t i = 0;
    uint8_t charsSinceWhitespace = 0;
    char* *tokens = malloc(sizeof(char*) * 4);
    uint8_t nextOpenTokenIndex = 0;
    uint8_t tokensCap = 4;
    while (inputString[i] != '\0')
    {
        #ifdef DEBUG
        printf("Input string char is %c\n", inputString[i]);
        #endif
        if (inputString[i] == ' ' || inputString[i] == '\t' || inputString[i] == '\n')
        {
            if (charsSinceWhitespace > 0)
            {
                // check if there is space in tokens, and if not, realloc memory with double size
                if (nextOpenTokenIndex > tokensCap - 1)
                {
                    tokensCap *= 2;
                    tokens = realloc(tokens, tokensCap * sizeof(char*));
                    #ifdef DEBUG
                    printf("doubled memory of tokens\n");
                    # endif
                    if (tokens == NULL)
                    {
                        perror("Failed to allocate memory");
                        return NULL;
                    }
                }
                // create new mem location with the size of the string and copy the token in
                tokens[nextOpenTokenIndex] = malloc(sizeof(char) * (charsSinceWhitespace + 1));
                memcpy(tokens[nextOpenTokenIndex], &inputString[i-charsSinceWhitespace], charsSinceWhitespace);
                #ifdef DEBUG
                printf("copied new token %s| into tokens array\n", tokens[nextOpenTokenIndex]);
                #endif
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
        #ifdef DEBUG
        printf("incremented i to %i and token is %c|\n", i, inputString[i]);
        #endif
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