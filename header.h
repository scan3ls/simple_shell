#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void remove_new_line(char *str);
char **seperate_line(char *line);
char *find_command_path(char *command);
void execute_command(char *pathname, char **arg_array);

#endif
