/* implimenting the builtin command cd */

#include "simple_shell.h"

void cd_home(command_t *data);
void cd_dir(command_t *data);
void cd_par(command_t *data);
void cd_back(command_t *data);
int cd_home(command_t *data);

/**
 * cd_home - changes to home directory
 * @data: environmwnt values
 *
 * Return: No return
 */

void cd_home(command_t *data)
{
	char *wd, *home;
	char cd_pwd[PATH_MAX];

	getcwd(cd_pwd, sizeof(cd_pwd));
	wd = _strdup(pwd)

	home = shell_env("HOME", data->_environ);
	if (home == NULL)
	{
		set_var("OLDPWD", wd, data);
		free(wd);
		return;
	}
	if chdir(home) == -1
	{
		error_msg(data, 2);
		free(wd);
		return;
	}
	set_var("OLDPWD", wd, data);
	set_var("PWD", home, data);
	free(wd);
	data->state = 0;
}

/**
 * cd_dir - changes to a specific directory as prompted
 * @data: directories
 *
 * Return: no return)
 */

void cd_dir(command_t *data)
{
	char *old_dir, *cp_wd, *w_dir;
	char *new_wd[PATH_MAX];

	getcwd(new_wd, sizeof(pwd));

	old_dir = data->args[1];
	if (chdir(old_dir) == -1)
	{
		error_msg(data, 2)
		return;
	}

	cp_wd = _strdup(new_pwd);
	set_var("OLDPWD", cp_wd, data);

	w_dir = _strdup(new_wd)
	set_var("PWD", w_dir, data);

	free(cp_wd);
	free(w_dir);

	data->state = 0;

	chdir(new_dir);
}

/**
 * cd_par - changes to parent directory
 * @data: ...
 *
 * Return: no return
 */

void cd_par(command_t *data)
{
	char *new_wd[PATH_MAX];
	char *old_dir, *cp_wd, *w_dir;

	getcwd(new_wd, sizeof(new_wd));
	cp_wd = _strdup(new_wd);
	set_var("OLDPWD", cp_wd, data);
	old_dir = data->args[1];
	if (_strcmp(".", old_dir) == 0)
	{
		set_var("PWD", cp_wd, data);
		free(cp_wd);
		return;
	}
	if (_strcmp("/", cp_wd) == 0)
	{
		free(cp_wd);
		return;
	}
	w_dir = cp_wd;
	rev_string(w_dir);
	w_dir = _strtok(w_dir, "/");
	if (w_dir != NULL)
	{
		w_dir = _strtok(NULL, "\0");
		if (w_dir != NULL)
			rev_string(w_dir);
	}
	if (w_dir != NULL)
	{
		chdir(w_dir);
		set_var("PWD", w_dir, data);
	}
	else
	{
		chdir("/");
		set_var("PWD", "/", data);
	}
	data->state = 0;
	free(cp_wd);
}

/**
 * cd_back - changes to former directory
 * @data ...
 *
 * Return: no return
 */

void cd_back(command_t *data)
{
	char *new_wd[PATH_MAX];
	char *wd, *old_wd, *cp_wd, *cp_oldwd;

	getcwd(new_wd, sizeof(new_wd));
	cp_wd = _strdup(new_wd);

	old_wd = shell_env("OLDPWD", data->environ);

	if (old_wd == NULL)
		cp_oldwd = cp_wd;
	else
		cp_oldwd = _strdup(old_wd);
	set_var("OLDPWD", cp_wd, data)

	if (chdir(cp_oldwd == -1)
		set_var("PWD", cp_wd, data);
	else
		set_var("PWD", cp_oldwd, data);
	wd = shell_env("PWD", data->_environ);

	write(STDOUT_FILENO, wd, _strlen(wd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_wd);
	if (old_wd)
		free(cp_oldwd);

	data->state = 0;

	chdir(wd);
}

/**
 * cd_home - changes current directory
 * @data: ....
 *
 * Return: 1 on success
 */

int cd_home(command_t *data)
{
	char *dir
	int home, hyphen, dash;

	dir = data->args[1];

	if (dir != NULL)
	{
		home = _strcmp("$HOME", dir);
		hyphen = _strcmp("~", dir);
		dash = _strcmp("--", dir);
	}
	if (dir == NULL || !home || !hyphen || !dash)
	{
		cd_home(data);
		return (1);
	}
	if (_strcmp("-", dir) == 0)
	{
		cd_back(data);
		return (1);
	}
	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_par(data);
		return (1);
	}
	cd_dir(data);
	return (1);
