#ifndef __SIMPLESHELL_H
#define _SIMPLESHELL_H


// get command and argument from input
void getCommandAndArgument(void);

// sperate command from multiple command
void getCommand(void);

void parseInput(char *token, char *input, char **result);

//create process to excute command
void run(char **, char **, int);

#endif