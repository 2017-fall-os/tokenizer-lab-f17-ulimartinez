#include "mytoc.h"
#include <unistd.h>
#include "util.h"

short exit(char *);
int main(){
    while(1){
        write(1, "$", 2);
        char *str = getStdIn();
        if(exit(str))
            return 0;
        char **tokens = mytoc(str, ' ');
        printTokens(tokens);
    }
}
short exit(char *str){
    char *exit = "exit";
    short ind = 0;
    while(str[ind]==exit[ind]) {
        if(str[ind]=='\0'||exit[ind]=='\0')
            break;
        ind++;
    }
    if(str[ind]=='\0' && exit[ind]=='\0')
        return 1;
    else
        return 0;
}
