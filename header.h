#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

void remove_new_line(char *str);
char **seperate_line(char *line);
char *find_command_path(char *command);
void execute_command(char **arg_array, char *line, char **tokens);
char **pathTok(void);

#endif
