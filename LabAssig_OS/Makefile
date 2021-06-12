
INC_DIR = ~/codeblocks/LabAssig_OS/
CC = gcc
CFLAGS = -Wall -I$(INC_DIR)
OBJS = build_in_command.o simpleShell.o

all: simpleShell

simpleShell: simpleShell.o build_in_command.o
	$(CC) $(CFLAGS) -o $@ simpleShell.o build_in_command.o

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	-rm -f $(OBJS) simpleShell