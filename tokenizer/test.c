#include "mytoc.h"
#include <unistd.h>
#include <stdio.h>
#include "util.h"

int main(){
  char *str = getStdIn();
  write(1, str, sizeof(str));
}
