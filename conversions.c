#include "simple_shell.h"

int int_len(int n);
char int_str(int n);
int _atoi(char *s);

/**
 * int_len - Gets the lenght of a number.
 * @n: number.
 *
 * Return: Lenghth
 */
int int_len(int n)
{
	unsigned int num;
	int len = 1;

	if (n < 0)
	{
		len++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	while (num > 9)
	{
		len++;
		num = num / 10;
	}

	return (len);
}

/**
 * int_str - converts integers to string.
 * @n: integer
 *
 * Return: converted string.
 */

char int_str(int n)
{
	unsigned int num;
	int len = int_len(n);
	char *temp;

	temp = malloc(sizeof(char) * (len + 1));
	if (temp == 0)
		return;

	*(temp + len) = '\0';

	if (n < 0)
	{
		num = n * -1;
		temp[0] = '-';
	}
	else
	{
		num = n;
	}

	len--;
	do {
		*(temp + len) = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	while (num > 0)
		;
	return (temp);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	int index = 0;
	unsigned int num = 0;
	int sign = 1;
	int digit_found = 0;

	while (s[index])
	{
		if (s[index] == '-')
	{
		sign *= -1;
	}

	while (s[index] >= '0' && s[index] <= '9')
	{
		digit_found = 1;
		num = (num * 10) + (s[index] - '0');
			index++;
	}

	if (digit_found == 1)
	{
		break;
	}

		index++;
	}

	num *= sign;
	return (num);
}
