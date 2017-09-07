#include "mytoc.h"
#include <unistd.h>
#include <stdio.h>
#include "util.h"

int main(){
    char *str = getStdIn();
    char **tokens = mytoc(str, ' ');
    write(1, str, strlen(str));
}
