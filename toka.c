#include "main.h"

/**
 * *our_strncpy - copies a string
 *@d: the string to be copied to
 *@a:  source string
 *@b: characters to be copied
 *Return: the concatenated string
 */
char *our_strncpy(char *d, char *a, int b)
{
	int i, j;
	char *s = d;

	i = 0;
	while (a[i] != '\0' && i < b - 1)
	{
		d[i] = a[i];
		i++;
	}
	if (i < b)
	{
		j = i;
		while (j < b)
		{
			d[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *our_strncat - concatenates two strings
 * @d:  string 1
 * @a:  string 2
 * @b: amount of bytes
 * Return: the concatenated string
 */

char *our_strncat(char *d, char *a, int b)
{
	int i, j;
	char *s = d;

	i = 0;
	j = 0;
	while (d[i] != '\0')
		i++;
	while (a[j] != '\0' && j < b)
	{
		d[i] = a[j];
		i++;
		j++;
	}
	if (j < b)
		d[i] = '\0';
	return (s);
}

/**
 * *our_strchr - locates a character in a string
 *@s:  string to pass
 *@c:  character to check
 *Return: (s) a pointer to the memory area s
 */
char *our_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
