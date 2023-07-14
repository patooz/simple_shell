#include "main.h"

/**
 * our_putchar - prints character to stdout
 * @c: character to be printed
 * Return: 1 on success, -1 on error
 */
int our_putchar(char c)
{
	static int x;
	static char b[BUFF_WRITE];

	if (c == FLUSH || x >= BUFF_WRITE)
	{
		write(1, b, x);
		x = 0;
	}
	if (c != FLUSH)
		b[x++] = c;
	return (1);
}

/**
 * our_puts - prints a user input
 * @s: string
 */
void our_puts(char *s)
{
	int x = 0;

	if (!s)
		return;
	while (s[x] != '\0')
	{
		our_putchar(s[x]);
		x++;
	}
}

/**
 * our_strdup - returns a duplicated string
 * @s: string
 * Return: duplicated string pointer
 */
char *our_strdup(const char *s)
{
	int i = 0;
	char *y;

	if (s == NULL)
	{
		return (NULL);
	}
	while (*s++)
	{
		i++;
	}
	y = malloc(sizeof(char) * (i + 1));
	if (!y)
	{
		return (NULL);
	}
	for (i++; i--;)
		y[i] = *--s;
	return (y);
}
/**
 * our_strcpy - copies a string
 * @s: soirce
 * @d: destination
 * Return: destination pointer
 */
char *our_strcpy(char *s, char *d)
{
	int x = 0;

	if (d == s || s == 0)
		return (d);
	while (s[x])
	{
		d[x] = s[x];
		x++;
	}
	d[x] = 0;
	return (d);
}
