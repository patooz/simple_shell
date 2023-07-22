#include "main.h"

/**
 * our_putnode - puts the character to fd
 * @c: character
 * @f: the file to be written
 * Return: 1 on success, -1 on failure
 */
int our_putnode(char c, int f)
{
	static int i;
	static char b[BUFF_WRITE];

	if (c == FLUSH || i >= BUFF_WRITE)
	{
		write(f, b, i);
		i = 0;
	}
	if (c != FLUSH)
		b[i++] = c;
	return (1);
}

/**
 * our_eputs - prints user input
 * @a: string to be printed
 */
void our_eputs(char *a)
{
	int i = 0;

	if (!a)
		return;
	while (a[i] != '\0')
	{
		our_eputchar(a[i]);
		i++;
	}
}
/**
 * our_putnodes - prints user input
 * @s: string to be printed
 * @f: file to write
 * Return: characters input
 */
int our_putnodes(char *s, int f)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
		i += our_putnode(*s++, f);
	return (i);
}
/**
 * our_eputchar - wriets a character to the error function
 * @c: the character to be printed
 * Return: 0 onsuccess, -1 on error
 */
int our_eputchar(char c)
{
	static int i;
	static char b[BUFF_WRITE];

	if (c == FLUSH || i >= BUFF_WRITE)
	{
		write(2, b, i);
		i = 0;
	}
	if (c != FLUSH)
		b[i++] = c;
	return (1);
}
