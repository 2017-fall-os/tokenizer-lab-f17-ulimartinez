#include "mytoc.h"
#include "strcopy.h"
#include "util.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char ** mytoc(char *str, char delim){
    if(!*str)
        return NULL;
    int numToc = 1;
    char *pStr;
    for(pStr = str; *pStr; pStr++){
        if(*pStr == delim)
            numToc++;
    }
    char **tokens = (char **)malloc(sizeof(char*) * (numToc+1));
    //read str to get length of each token
    int numChars = 0;
    char *tokStart = str;
    int curTokInd = 0;
    for(pStr = str; *pStr; pStr++){
        if(*pStr != delim){
            numChars++;
        }
        else{
            char *cstr = substrCopy(tokStart, numChars);
            *(tokens + curTokInd) = cstr;
            numChars = 0;
            curTokInd++;
            tokStart = pStr+1;
        }
    }
    *(tokens + curTokInd++) = substrCopy(tokStart, numChars);
    *(tokens + curTokInd) = (char *)0;
    return tokens;
}
void printTokens(char ** tokens){
    for(char **ptokens = tokens; *ptokens; ptokens++){
        write(1, *ptokens, (size_t)strlen(*ptokens));
        free(*ptokens);
        write(1, "\n", 1);
    }
    free(tokens);
}