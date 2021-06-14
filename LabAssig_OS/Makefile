
INC_DIR = ~/codeblocks/LabAssig_OS/
CC = gcc
CFLAGS = -Wall -I$(INC_DIR)
OBJS = build_in_command.o simpleShell.o

all: myshell

myshell: simpleShell.o build_in_command.o myshell.o
	$(CC) $(CFLAGS) -o $@ $^ 

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	-rm -f $(OBJS) myshell
