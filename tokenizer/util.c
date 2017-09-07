#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#define MAX_CHARS 1000
char* getStdIn(){
    char buf[MAX_CHARS];
    char *str;
    int i = read(0, buf, MAX_CHARS);
    /*
    for(int i = 0; i < MAX_CHARS; i++){
      if(buf[i] == '\n'){
        str = (char *)malloc(i);
        break;
      }
    }
    */
    str = (char *)malloc(i);
    char *pstr = str;
    for(int j = 0; j < i-1; j++){
        *(pstr++) = buf[j];
    }
    *pstr = 0;
    return str;
}
int strlen(char *str){
    int i = 0;
    for(char *pstr = str; *pstr; pstr++)
        i++;
    return i;
}

