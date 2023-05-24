#include "simple_shell.h"

int _strlen(char *s);
void rev_string(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strdup(const char *s);

/**
 * _strlen - returns the length of a string
 * @s: character to be checked
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * rev_string - reverses a string
 * @s: char to be checked
 *
 * Return : no return
 */

void rev_string(char *s)
{
	int a = 0, b, c;
	char d;

	while (s[a] != '\0')
	{
		a++;
	}
	c = a - 1;
	for (b = 0; c >= 0 && b < c; c--, b++)
	{
		d = s[b];
		s[b] = s[c];
		s[c] = d;
	}
}

/**
 * _strcpy - copy the string pointed to by src to dest
 * @dest: char to check
 * @src: char to check
 *
 * Return: 0 is success
 */

char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

/**
 * _strcat - concatenate two strings
 * @dest: first string
 * @src:  second string
 *
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)

{
	int x, y;

	for (x = 0; dest[x] != '\0'; x++)
		;

	for (y = 0; src[y] != '\0'; y++)
	{
		dest[x] = src[y];
		x++;
	}
	dest[x] = '\0';

	return (dest);
}

/**
 * _strncpy - copies a string
 * @dest: first string
 * @src: second string
 * @n: number of chars to copy
 *
 * Return: dest - edited string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; n > i; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 success
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strstr - locates a substring
 * @haystack: the string
 * @needle: substring
 *
 * Return:  pointer to the beginning of the located
 * substring, or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	char *h;
	char *n;

	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;

		while (*haystack != '\0' && *n != '\0' && *haystack == *n)
		{
			haystack++;
			n++;
		}
		if (!*n)
			return (h);
		haystack = h + 1;
	}
	return (0);
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: initial segment
 * @accept: bytes to include
 *
 * Return: number of bytes in the initial segment of @s
 * which consist only of bytes from @accept
 */

unsigned int _strspn(char *s, char *accept)
{
	int a;
	int b;
	int c = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] != 32)
		{
			for (b = 0; accept[b] != '\0'; b++)
			{
				if (s[a] == accept[b])
					c++;
			}
		}
		else
			return (c);
	}
	return (c);
}

/**
 * _strdup - duplicates a string in the memory
 * @s: pointer to a string
 *
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	char *new_string;
	size_t len;

	len = _strlen(s);
	new_string = malloc(sizeof(char) * (len + 1));

	if (new_string == NULL)
		return (NULL);

	_memcpy(new_string, s, len + 1);

	return (new_string);
}

