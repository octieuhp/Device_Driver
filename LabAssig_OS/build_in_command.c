#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "build_in_command.h"
 
int build_in_CD(char *directory, char *working_directory, char *shellPrompt){
    char *currentPath = malloc(sizeof(char*));
    int ret;

    ret = chdir(directory);
    
    strcpy(working_directory, getcwd(currentPath, 1024));
    strcat(working_directory, shellPrompt);
    free(currentPath);
    return 0;
}