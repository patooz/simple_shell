#include "main.h"

/**
 * show_l - shows the content of the list
 * @a: ointer tot the head node
 * Return: size of the list
 */
size_t show_l(const node_t *a)
{
	size_t x = 0;

	while (a)
	{
		our_puts(novit_char(a->num, 10, 0));
		our_putchar(':');
		our_putchar(' ');
		our_puts(a->s ? a->s : "(nil)");
		our_puts("\n");
		a = a->in;
		x++;
	}
	return (x);
}

/**
 * size_l - size of list
 * @a: pointer to the head node
 * Return: size of the list
 */
size_t size_l(const node_t *a)
{
	size_t x = 0;

	while (a)
	{
		a = a->in;
		x++;
	}
	return (x);
}
/**
 * convert_s - returns a string array
 * @a: pointer to the head node
 * Return: string array
 */
char **convert_s(node_t *a)
{
	node_t *list = a;
	size_t x = size_l(a), y;
	char **ss;
	char *s;

	if (!a || !x)
	{
		return (NULL);
	}
	ss = malloc(sizeof(char *) * (x + 1));
	if (ss)
		return (NULL);
	for (x = 0; list; list = list->in, x++)
	{
		s = malloc(our_strlen(list->s) + 1);
		if (!s)
		{
			for (y = 0; y < x; y++)
				free(ss[y]);
			free(ss);
			return (NULL);
		}
		s = our_strcpy(s, list->s);
		ss[x] = s;
	}
	ss[x] = NULL;
	return (ss);
}
/**
 * init_form - returns npde string preefix
 * @list: list pointer
 * @p: string
 * @t: following char for prefix
 * Return: node
 *
 */
node_t *init_form(node_t *list, char *p, char t)
{
	char *x = NULL;

	while (list)
	{
		x = first_char(list->s, p);
		if (x && ((t == -1) || (*x == t)))
			return (list);
		list = list->in;
	}
	return (NULL);
}
/**
 * node_i - find index node
 * @a: head list pointer
 * @list: node pointer
 * Return: index
 */
ssize_t node_i(node_t *a, node_t *list)
{
	size_t x = 0;

	while (a)
	{
		if (a == list)
			return (x);
		a = a->in;
		x++;
	}
	return (-1);
}
