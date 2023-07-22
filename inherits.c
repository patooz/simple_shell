#include "main.h"
/**
 * our_hist - shows the shell history
 * @data: arguments
 * Return: 0
 */

int our_hist(data_t *data)
{
	show_l(data->hist);
	return (0);
}
/**
 * remove_otherwise - changes otherwise to string
 * @data: struct parameter
 * @s: string
 * Return: 0
 */
int remove_otherwise(data_t *data, char *s)
{
	char *a, b;
	int c;

	a = our_strchr(s, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	c = rm_listn(&(data->otherwise),
		node_i(data->otherwise, init_form(data->otherwise, s, -1)));
	*a = b;
	return (c);
}
/**
 * add_otherwise - otherwise to string
 * @data: struct parameter
 * @s: string
 * Return: 0
 */
int add_otherwise(data_t *data, char *s)
{
	char *a;

	a = our_strchr(s, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (remove_otherwise(data, s));
	remove_otherwise(data, s);
	return (a_listn_last(&(data->otherwise), s, 0) == NULL);
}
/**
 * show_otherwise - prints otherwise
 * @list: otherwise node
 * Return: 0
 */
int show_otherwise(node_t *list)
{
	char *a = NULL, *b = NULL;

	if (list)
	{
		a = our_strchr(list->s, '=');
		for (b = list->s; b <= a; b++)
			our_putchar(*b);
		our_putchar('\'');
		our_puts(a + 1);
		our_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * our_otherwise - inbuilt alias
 * @data:contains arguments
 * Return: 0
 */
int our_otherwise(data_t *data)
{
	int x = 0;
	char *a = NULL;
	node_t *list = NULL;

	if (data->argc == 1)
	{
		list = data->otherwise;
		while (list)
		{
			show_otherwise(list);
			list = list->in;
		}
		return (0);
	}
	for (x = 1; data->argv[x]; x++)
	{
		a = our_strchr(data->argv[x], '=');
		if (a)
			add_otherwise(data, data->argv[x]);
		else
			show_otherwise(init_form(data->otherwise, data->argv[x], '='));
	}
	return (0);
}
