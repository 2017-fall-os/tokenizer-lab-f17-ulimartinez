#include <unistd.h>
#include <stdlib.h>
#include "util.h"
char* getStdIn(){
  char buf[1000];
  char *str;
  read(0, buf, 1000);
  for(int i = 0; i < 1000; i++){
    if(buf[i] == '\n')
      str = (char *)malloc(i+1);
  }
  char *pstr = str;
  for(int i = 0; i < sizeof(str); i++){
    *(pstr++) = buf[i];
  }
  *pstr = 0;
  return str;
}
    
