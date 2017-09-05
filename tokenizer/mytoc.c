#include "mytoc.h"
#include "strcopy.h"
#include <stdlib.h>
char ** mytoc(char *str, char delim){
  int numToc = 0;
  char *pStr;
  for(pStr = str; *pStr; pStr++){
    if(*pStr == delim)
      numToc++;
  }
  char **tokens = (char **)malloc(numToc);
  //read str to get length of each token
  int numChars = 0;
  char *tokStart = str;
  int curTokInd = 0;
  for(pStr = str; *pStr; pStr++){
    if(*pStr != delim){
      numChars++;
    }
    else{
      *(&tokens + curTokInd) = substrCopy(tokStart, numChars);
      numChars = 0;
      curTokInd++;
    }
  }
}
