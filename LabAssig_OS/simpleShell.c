#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "simpleShell.h"

void test(void){
    return;
}

void parseInput(char *token, char *input, char **result)
{   
    int i = 0;
    token = strtok(input, " ");
    while(token != NULL){
        result[i++] = token;
        //strcpy(result[i++], token);
        token = strtok(NULL, " ");
    }
    result[i] = NULL;
    return ;
}

void run(char **command, char *path[], int numberElement){

    char *cmdtemp = malloc(1024*sizeof(char*));
    int ret;
    if((numberElement) == 0){
        printf("Can't found Path!\n");
        free(cmdtemp);
        return;
    }

    for(int i = 0; i < numberElement; i++){
        strcpy(cmdtemp, path[i]);
        cmdtemp = strcat(cmdtemp, command[0]);
        ret = access(cmdtemp, X_OK);
        if(!ret){
            //strcpy(command[0], cmdtemp);
            ret = fork();
            if(ret < 0){
                printf("Can't run program!\n");
                free(cmdtemp);
                return;
            }
            if(ret == 0){
                //execv(command[0], command);
                execv(cmdtemp, command);
            }
            else
                wait(NULL);
            free(cmdtemp);
            return;
        }
    }
    printf("Command %s not found!!\n", command[0]);
    free(cmdtemp);
    return;
}