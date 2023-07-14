#include  "main.h"

/**
 * strip_c - change a string to ana int
 * @a: string
 * Return: 0
 */
int strip_c(char *a)
{
	unsigned long int x = 0;
	int y = 0;

	if (*a == '+')
		a++;
	for (y = 0; a[y] != '\0'; y++)
	{
		if (a[y] >= '0' && a[y] <= '9')
		{
			x *= 10;
			x += (a[y] - '0');
			if (x > INT_MAX)
			{
				return (-1);
			}
		}
		else
			return (-1);
	}
	return (x);
}
/**
 * show_fig - prints a figure in decimal
 * @a: input figure
 * @b: file to be written
 * Return: fugures printed
 */
int show_fig(int a, int b)
{
	int (*our__putchar)(char) = our_putchar;
	int x, y = 0;
	unsigned int i, j;

	if (b == STDERR_FILENO)
		our__putchar = our_eputchar;
	if (a < 0)
	{
		i = -a;
		our__putchar('-');
		y++;
	}
	else
		i = a;
	j = i;
	for  (x = 1000000000; x > 1; x /= 10)
	{
		if (i / x)
		{
			our__putchar('0' + j / x);
			y++;
		}
		j %= x;
	}
	our__putchar('0' + j);
	y++;
	return (y);
}
/**
 * show_emsg - show an error message
 * @data: struct parameter
 * @s: string
 * Return: 0 if string, else -1 on error
 */
void show_emsg(data_t *data, char *s)
{
	our_eputs(data->_file);
	our_eputs(": ");
	show_fig(data->ren_counter, STDERR_FILENO);
	our_eputs(": ");
	our_eputs(data->argv[0]);
	our_eputs(": ");
	our_eputs(s);
}
/**
 * novit_char - number converter
 * @a: number
 * @b: base of number
 * @c: argument
 * Return: a string
 */
char *novit_char(long int a, int b, int c)
{
	static char *i;
	static char j[50];
	char k = 0;
	char *s;
	unsigned long l = a;

	if (!(c & NOVIT_UNSIGNED) && a < 0)
	{
		l = -a;
		k = '-';
	}
	i = c & NOVIT_LOWER ? "123456789abcdef" : "123456789ABCDEF";
	s = &j[49];
	*s = '\0';
	do {
		*--s = i[l % b];
		l /= b;
	} while (l != 0);
	if (k)
		*--s = k;
	return (s);
}
/**
 * novit_words - removes #
 * @b: address of the string
 */
void novit_words(char *b)
{
	int x;

	for (x = 0; b[x] != '\0'; x++)
	{
		if (b[x] == '#' && (!x || b[x - 1] == ' '))
		{
			b[x] = '\0';
			break;
		}
	}
}
