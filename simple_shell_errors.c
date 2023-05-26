#include "simple_shell.h"

char *error_check(command_t *data, char *msg, char *err_buf, char *vrsn_str);
char *env_error_message(command_t *data);
char *path_126_error(command_t *data);
char *uknown_command(command_t *data);
char *shell_exit_error(command_t *data);
char *cd_error_message(command_t *data);
int error_msg(command_t *data, int value);

/**
 * error_check - checks for error
 * @data: ...
 * @msg: error message
 * @err_buf: display error
 * @vrsn_str: lines checked
 *
 * Return: error message
 */

char *error_check(command_t *data, char *msg, char *err_buf, char *vrsn_str)
{
	char *uknown_cmd = NULL;

	_strcpy(err_buf, data->arg_vector[0]);
	_strcat(err_buf, ": ");
	_strcat(err_buf, vrsn_str);
	_strcat(err_buf, ": ");
	_strcat(err_buf, data->args[0]);
	_strcat(err_buf, msg);

	if (data->args[1][0] == '-')
	{
		uknown_cmd = malloc(3);
		uknown_cmd[0] = '-';
		uknown_cmd[1] = data->args[1][1];
		uknown_cmd[2] = '\0';
		_strcat(err_buf, uknown_cmd);
		free(uknown_cmd);
	}
	else
	{
		_strcat(err_buf, data->args[1]);
	}

	_strcat(err_buf, "\n");
	_strcat(err_buf, "\0");

	return (err_buf);
}

/**
 * env_error_message - environment error message
 * @data: ....
 * Return: error message.
 */
char *env_error_message(command_t *data)
{
	int len;
	char *error;
	char *str_vector;
	char *error_msg;

	str_vector = int_str(data->check);
	error_msg = ": Operation failed. Environment not added\n";
	len = _strlen(data->arg_vector[0]) + _strlen(str_vector);
	len += _strlen(data->args[0]) + _strlen(error_msg) + 4;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(str_vector);
		return (NULL);
	}

	_strcpy(error, data->arg_vector[0]);
	_strcat(error, ": ");
	_strcat(error, str_vector);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, error_msg);
	_strcat(error, "\0");
	free(str_vector);

	return (error);
}
/**
 * path_126_error - denied permission error message
 * @data:....
 *
 * Return: Error.
 */
char *path_126_error(command_t *data)
{
	int len;
	char *str_vector;
	char *error;

	str_vector = int_str(data->check);
	len = _strlen(data->arg_vector[0]) + _strlen(str_vector);
	len += _strlen(data->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(str_vector);
		return (NULL);
	}
	_strcpy(error, data->arg_vector[0]);
	_strcat(error, ": ");
	_strcat(error, str_vector);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, ": No sufficient permission for this operation\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * uknown_command - error message for non- existence commands
 * @data: ....
 * Return: Error message
 */
char *uknown_command(command_t *data)
{
	int len;
	char *error;
	char *str_vector;

	ver_str = int_str(data->check);
	len = _strlen(data->arg_vector[0]) + _strlen(str_vector);
	len += _strlen(data->args[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(str_vector);
		return (NULL);
	}
	_strcpy(error, data->arg_vector[0]);
	_strcat(error, ": ");
	_strcat(error, str_vector);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, ": uknown command\n");
	_strcat(error, "\0");
	free(str_vector);
	return (error);
}

/**
 * shell_exit_error - error message incase of simple_shell exit error
 * @data: ....
 *
 * Return: Error message
 */
char *shell_exit_error(command_t *data)
{
	int len;
	char *error;
	char *str_vector;

	ver_str = int_str(data->check);
	len = _strlen(data->arg_vector[0]) + _strlen(str_vector);
	len += _strlen(data->args[0]) + 23;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(str_vector);
		return (NULL);
	}
	_strcpy(error, data->arg_vector[0]);
	_strcat(error, ": ");
	_strcat(error, str_vector);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, ": Unable to exit simple_shell\n");
	_strcat(error, "\0");
	free(str_vector);
	return (error);
}
/**
 * cd_error_message - change directory error message
 * @data: ....
 *
 * Return: The error
 */

char *cd_error_message(command_t *data)
{
	char *error_message = NULL;
	const char *cd_error = "Operation Failed!";

	size_t prefix_length = _strlen("CD error: ");
	size_t error_length = _strlen(cd_error);
	size_t message_length = prefix_length + error_length + 1;

	error_message = (char *)malloc(message_length * sizeof(char));

	if (error_message != NULL)
	{
		_strncpy(error_message, "CD error: ", prefix_length);
		_strncpy(error_message + prefix_length, cd_error, error_length);
		error_message[message_length - 1] = '\0';

		write(STDERR_FILENO, error_message, message_length - 1);
	}

	return (error_message);
}

/**
 * error_msg - gets error messages in case of inaccurate commands
 * @data: arguments
 * @value: error value
 *
 * Return: error
 */

int error_msg(command_t *data, int value)
{
	char *error_message = NULL;

	if (value == -1)
		error_message = env_error_message(data);
	else if (value == 126)
		error_message = path_126_error(data);
	else if (value == 127)
		error_message = uknown_command(data);
	else if (value == 2)
	{
		if (_strcmp("exit", data->args[0]) == 0)
			error_message = shell_exit_error(data);
		else if (_strcmp("cd", data->args[0]) == 0)
			error_message = cd_error_message(data);
	}

	if (error_message)
	{
		write(STDERR_FILENO, error_message, _strlen(error_message));
		free(error_message);
	}

	data->state = value;
	return (value);
}
