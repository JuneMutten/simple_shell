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
 * struct command_s - struct for builtin command
 * @name: Name of the builtin command
 * @state: State of the builtin command
 * @_environ: Pointer to the environment variables
 * @args: arguments in the command line
 * @check: checks on the number of lines
 * @arg_vector: argument vector
 *
 * Description: Structure defining a builtin command.
 */


typedef struct command_s
{
	char *name;
	int state;
	char **_environ;
	char **arg_vector;
	int check;
	char **args;
} command_t;

/**
 * struct builtin_s - struct for command arguments
 * @name: shell builtin command
 * @p: pointer to a function
 */
typedef struct builtin_s
{
	char *name;
	int (*p)(command_t *data);
} builtin_t;


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
int sprt_psn(char *str, char *sprt);
int deleted_chars(char *str, char *sprt);
char **_strtok(char *str, const char *sprt);

/* environment variable functions */
int builtin_funcs(char *cmd)(command_t *);
int variable_names(const char *var, const char *name);
char env_var(const char *var, char **_environ);
int shell_env(command_t data);
char *create_info(char *info, char *value_info);
void set_var(char *info, char *value_info, command_t *data);
int shell_setenv(command_t *data);
int shell_unsetenv(command_t *data);

/* implimenting the builtin command cd */
void cd_home(command_t *data);
void cd_dir(command_t *data);
void cd_par(command_t *data);
void cd_back(command_t *data);
int cd_home_dir(command_t *data);

/* simple_shell conversion functions */
int int_len(int n);
char int_str(int n);
int _atoi(char *s);

/* error check functions */
char *error_check(command_t *data, char *msg, char *err_buf, char *vrsn_str);
char *env_error_message(command_t *data);
char *path_126_error(command_t *data);
char *uknown_command(command_t *data);
char *shell_exit_error(command_t *data);
char *cd_error_message(command_t *data);
int error_msg(command_t *data, int value);


#endif
