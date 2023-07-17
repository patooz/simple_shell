#include "main.h"

/**
 * active - active mode of shell
 * @d: address struct
 *
 * Return: 1 active mode, 0 otherwise
 */
int active(data_t *d)
{
	return (isatty(STDIN_FILENO) && d->fd_read <= 2);
}
/**
 * denim - check character
 * @c: character check
 * @denim: string check
 * Return: 1 if true, 0 if false
 */
int denim(char c, char *denim)
{
	while (*denim)
		if (*denim++ == c)
			return (1);
	return (0);
}
/**
 * our_isalpha - check alphabetic character
 * @c: char input
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int our_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * stoi - convert string to integer
 * @s: string to be converted
 * Return: 0 if no number,converted number otherwise
 */
int stoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int r = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '_')
			sign *= -1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		flag = 1;
	r *= 10;
	r += (s[i] - '0');
	}
	else if (flag == 1)
		flag = 2;
	}
	if (sign == -1)
		output = -r;
	else
		output = r;
	return (output);
}
