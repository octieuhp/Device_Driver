#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "build_in_command.h"

#define shellPrompt "][myShell> "

static char *working_directory;

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

int main(int argc, char *argv[]){
    char *cmd, *token = malloc(sizeof(char*));
    char *current_directory = malloc(sizeof(char*));
    working_directory = malloc(sizeof(char*));
    //char **arg = malloc(sizeof(char**));
    char *arg[10];
    int i;
    /* for(int i = 0; i < 10; i++)
        arg[i] = malloc(sizeof(char*)); */

    for(int i = 0; i < 10; i++)
        arg[i] = malloc(sizeof(char*));

    cmd = malloc(sizeof(char*));
    working_directory = getcwd(current_directory, 1024);
    strcat(working_directory, shellPrompt);

	while(1)
	{
        printf("%s", working_directory);
        fgets(cmd, 1024, stdin);

		if(cmd[0] != 0x0A)
		{
            cmd[strlen(cmd)-1] = '\0';
            //printf("%s",cmd);

            parseInput(token, cmd, arg);
           /*  printf("%s+", arg[0]);*/
            printf("[%s]", arg[1]); 
		}
		else
            continue;
        if(0 == strcmp(arg[0], "exit"))
            exit(0);

        if(!strcmp(arg[0], "cd")){
            build_in_CD(arg[1], working_directory, shellPrompt);
            continue;
        }

        char *command = malloc(sizeof(char*));
        strcpy(command, "/bin/");
        strcat(command, arg[0]);
        i = fork();
        if(i == 0){
            //execvp(arg[0], arg);
            execv(command, arg);
        }
        else
        {
            wait(NULL);
        }
	}

    for (int i = 0; i < 10; i++)
        free(arg[i]);
    free(working_directory);
    free(cmd);
    free(token);
    free(current_directory);
	return 0;  
}
  

