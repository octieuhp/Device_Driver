#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

int build_in_PATH(char **path, char **element, int *numElement){
    
    if(element[1] == 0){
        for (int i = 0; i < (*numElement)-1; i++){
            printf("%s:", path[i]);
        }
        printf("%s\n", path[(*numElement)-1]);
        return 1;
    }
    
    char *index = element[1];
    int indexNumer = *numElement, flag = 0;

    if((*numElement) == 0){
        for(int i = 1; index != NULL; index = element[++i]){
            strcpy(path[(*numElement)++], index);
            //i++;       
        }
    }
    else
    {
        for(int i = 1; index != NULL; index = element[++i]){
            flag = 0;
            for(int j = 0; j < indexNumer; j++){
                if(!strcmp(path[j], index)){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                strcpy(path[(*numElement)++], index);
            }
        }
    }
    
    return 1;
}
