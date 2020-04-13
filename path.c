#include "header.h"

char **pathTok(void)
{
  char **tokens;
  char *tok;
  int i, j;
  char *path;
  char *env = *environ;


  for (i = 1; env != NULL; i++)
  {
	  if (env[0] == 'P' && env[1] == 'A')
		  break;
	  env = *(environ + i);
  }
  path = env + 5;
  i = 0;

  tokens = malloc(1000);

  tok = strtok(path, ":");
  while (tok != NULL)
    {
      tokens[i] = tok;
      i++;
      tok = strtok(NULL, ":");
    }
  tokens[i] = NULL;
  return (tokens);
}
