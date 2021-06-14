/*
 build_in_command.h
 cd, exit, path
 */
#ifndef __BUILD_IN_COMMAND_
#define __BUILD_IN_COMMAND_

// change current directory
int build_in_CD(char *, char *, char *);

//exit shell
void build_in_EXIT();

// operate with PATH variable
int build_in_PATH(char **, char **, int *);

#endif