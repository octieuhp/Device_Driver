#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "build_in_command.h"
#include "simpleShell.h"

#define shellPrompt "][myShell> "

static char *working_directory;

int main(int argc, char *argv[]){
    char *cmd, *token = malloc(1024*sizeof(char*));
    char *current_directory = malloc(1024*sizeof(char*));
    working_directory = malloc(1024*sizeof(char*));
    int numElement = 0, i;

    char *arg[100]; 
    for(int i = 0; i < 100; i++)
        arg[i] = malloc(100*sizeof(char *));

    char *pathEnv[100];
    for(int i = 0; i < 100; i++){
        pathEnv[i] = malloc(50*sizeof(char *));
    }

    cmd = malloc(1024*sizeof(char*));
    working_directory = getcwd(current_directory, 1024);
    strcat(working_directory, shellPrompt);

	while(1)
	{
        printf("%s", working_directory);
        fgets(cmd, 1024, stdin);

		if(cmd[0] != 0x0A)
		{
            cmd[strlen(cmd)-1] = '\0';
            parseInput(token, cmd, arg);
		}
		else
            continue;
        if(0 == strcmp(arg[0], "exit"))
            exit(0);

        if(!strcmp(arg[0], "cd")){
            build_in_CD(arg[1], working_directory, shellPrompt);
            continue;
        }

        if(!strcmp(arg[0], "PATH")){
            build_in_PATH(pathEnv, arg, &numElement);
            continue;
        }

        // run command
        run(arg, pathEnv, numElement);

	}

    for (int i = 0; i < 100; i++){
        free(arg[i]);
        free(pathEnv[i]);
    }
    free(working_directory);
    free(cmd);
    free(token);
    free(current_directory);
	return 0;  
}
  

