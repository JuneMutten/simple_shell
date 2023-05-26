/* List of commands for the simple_shell project */

#include "simple_shell.h"

/**
 * builtin_funcs - finds a command related to a simple_shell builtin function
 * @cmd: command to be found
 *
 * Return: pointer to the builtin function
 */

int builtin_funcs(char *cmd)(command_t *)
{
    command_t functions[] = {
        { "env", shell_env },
        { "setenv", shell_setenv },
        { "unsetenv", shell_unsetenv },
        { "cd", shell_cd },
        { "alias", shell_alias },
        { "help", shell_help },
        { NULL, NULL }
    };
    int i;

    for (i = 0; functions[i].name != NULL; i++)
    {
        if (_strcmp(functions[i].name, cmd) == 0)
            break;
    }
    return (functions[i].p);
}


/* Working with environment variables for simple_shell */

int variable_names(const char *var, const char *name);
char env_var(const char *var, char **_environ);
int print_env(command_t data);
char *create_info(char *info, char *value_info);
void set_var(char *info, char *value_info, command_t *data);

/**
 * variable_names - checks similarity in environmental variable
 * names with the name input
 * @var: name of the environment variable
 * @name: input name
 *
 * Return: 0 if not similar, value of x + 1 if similar
 */

int variable_names(const char *var, const char *name)
{
	int x;

	for (x = 0; var[x] != '='; x++)
	{
		if (var[x] != name[x])
		{
			return (0);
		}
	}
	return (x + 1);
}


/**
 * env_var - identifies an environment variable
 * @var: the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable or NULL
 */

char env_var(const char *var, char **_environ)
{
	char *env;
	int i, j;

	env = NULL;
	j = 0;

	for (i = 0; _environ[i]; i++)
	{
		j = variable_names(_environ[i], var);
		if (j)
		{
			j = (_environ[i], env);
			break;
		}
	}
	return (var + j);
}

/**
 * print_env - prints environment variales
 * @data: ....
 *
 * Return: 1 on success
 */

int print_env(command_t data)
{
	int i, j;

	for (i = 0; data->_envron[i]; i++)
	{
		for (j = 0; data->_envron[i][j]; j++)
			;

		write(STDOUT_FILENO, data->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data->state = 0;

	return (1);
}

/**
 * create_info - creates new information
 * @info: name of the variable created
 * @value_info: value of the variable created
 *
 * Return: New variable
 */

char *create_info(char *info, char *value_info)
{
	char *new;
	int len, name, value;

	name = _strlen(info);
	value = _strlen(value_info);
	len = name + value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, info);
	_strcat(new, "=");
	_strcat(new, value_info);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_var - sets an environment variable
 * @info: name of the variable created
 * @value_info: value of the variable created
 *
 * @data: environ structure
 * Return: New variable
 */

void set_var(char *info, char *value_info, command_t *data)
{
	int i;
	char *var, *env;

	for (i = 0; data->_environ[i]; i++)
	{
		var = _strdup(data->_environ[i]);
		env = _strtok(env, "=");
		if (_strcmp(env, info) == 0)
		{
			free(data->_environ[i]);
			data->_environ[i] = create_info(var, value_info);
			free(var);
			return;
		}
		free(var);
	data->_environ = double_realloc(data->_environ, i, sizeof(char *) * (i + 2));
	data->_environ[i] = create_info(info, value_info);
	data->_environ[i + 1] = NULL;
}

/* implimenting the setenv and unsetwnv builtin commands */

/**
 * shell_setenv - finds similarity between name input and
 * available variable names
 * @data: available environment name and value
 *
 * Return: 1 on success
 */

int shell_setenv(command_t *data)
{
	if (data->args[1] == NULL || data->args[2] == NULL)
	{
		error_msg(data, -1);
		return (1);
	}
	set_var(data->args[1], data->args[2], data);
	return (1);
}

/**
 * shell_unsetenv - deletes an environment variable
 * @data: enironment name and value
 *
 * Return: 1 on success
 */

int shell_unsetenv(command_t *data)
{
	char **new;
	char *var, *name;
	int x, y, z;

	if (data->args[1] == NULL)
	{
		error_msg(data, -1);
		return (1);
	}
	z = -1;
	for (x = 0; data->_environ[i]; i++)
	{
		var = _strdup(data->_environ[x]);
		name = _strtok(name, "=");
		if (_strcmp(var, data->args[1]) == 0)
		{
			z = x;
		}
		free(var);
	}
	if (x == -1)
	{
		error_msg(data, -1);
		return (1);
	}
	new = malloc(sizeof(char *) * (x));
	for (x = y = 0; data->_environ[x]; x++)
	{
		if (x != z)
		{
			new[y] = data->_environ[x];
			y++;
		}
	}
	new[y] = NULL;
	free(data->_environ[z]);
	free(data->_environ);
	data->_environ = new;
	return (1);
}
