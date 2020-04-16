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

int remove_new_line(char *str);
char **seperate_line(char *line);
char *find_command_path(char *command);
void execute_command(char **arg_array, char *line, char **tokens);
char **pathTok(void);
void builtIns(char **arg_array, char *line, char **tokens, int status);
void newPath(char *pth, char **tok, int pathL, int cmdL, int pathC, char *cmd);
int getLength(char *str);
int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
