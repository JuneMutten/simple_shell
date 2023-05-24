#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>


/**
 * command_s - struct for builtin command
 * @name: Name of the builtin command
 * @state: State of the builtin command
 * @_environ: Pointer to the environment variables
 *
 * Description: Structure defining a builtin command.
 */


typedef struct command_s
{
	char *name;
	int state;
	char **_environ;
} command_t;


/* Environment array pointer */
extern char **environ;

/* string funtions */
int _strlen(char *s);
void rev_string(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strdup(const char *s);

/* environment variable functions */
int(builtin_funcs(char *cmd))(char **args, char **head);
int variable_names(const char *var const char *name);
char env_var(const char *var, char **_environ);
int shell_env(command_t data);
char *create_info(char *info, *value_info);
void set_var(char *info, char *value_info, command_t *data);
int shell_setenv(command_t *data);
int shell_unsetenv(command_t *data);

/* implimenting the builtin command cd */
void cd_home(command_t *data);
void cd_dir(command_t *data);
void cd_par(command_t *data);
void cd_back(command_t *data);
int cd_home(command_t *data);


#endif
