#include "main.h"

/**
 * our_memset - memory with a constant byte
 * @n: memory pointer
 * @a: byte to fill *n
 * @j: bytes amount to be filled
 *
 * Return:(n)
 */
char *our_memset(char *n, char a, unsigned int j)
{
	unsigned int i;

	for (i = 0; i < j; i++)
		n[i] = a;
	return (n);
}
/**
 * _free - string to free
 * @bb: strings
 */
void _free(char **bb)
{
	char **a = bb;

	if (!bb)
		return;
	while (*bb)
		free(*bb++);
	free(a);
}
/**
 * alloc - memory block reallocated
 * @br: pointer to previous block
 * @i: previous byte
 * @j: current byte
 *
 * Return: pointer to the block
 */
void *alloc(void *br, unsigned int i, unsigned int j)
{
	char *d;

	if (!br)
		return (malloc(j));
	if (!j)
		return (free(br), NULL);
	if (j == i)
		return (br);
	d = malloc(j);
	if (!d)
		return (NULL);
	i = i < j ? i : j;
	while (i--)
		d[i] = ((char *)br)[i];
	free(br);
	return (d);
}
