#include "main.h"

/**
 * our_env - print current environment
 * @i:  potential arguments
 * Return: Always 0
 */
int our_env(data_t *i)
{
	show_listn_s(i->env);
	return (0);
}

/**
 * get - gets the value of variable
 * @i: containing potential arguments
 * @n: env var n
 *
 * Return: its value
 */
char *get(data_t *i, const char *n)
{
	node_t *node = i->env;
	char *p;

	while (node)
	{
		p = first_char(node->s, n);
		if (p && *p)
			return (p);
		node = node->in;
	}
	return (NULL);
}

/**
 * our_set - new environment variable
 *
 * @i: potential arguments
 *
 *  Return: Always 0
 */
int our_set(data_t *i)
{
	if (i->argc != 3)
	{
		our_eputs("number of arguements\n");
		return (1);
	}
	if (mini(i, i->argv[1], i->argv[2]))
		return (0);
	return (1);
}

/**
 * our_unset - Remove new environment variable
 * @data: containing potential arguments
 *  Return: Always 0
 */
int our_unset(data_t *data)
{
	int i;

	if (data->argc == 1)
	{
		our_eputs("few arguements.\n");
		return (1);
	}
	for (i = 1; i <= data->argc; i++)
		micro(data, data->argv[i]);

	return (0);
}

/**
 * our_list - linked list
 * @data: containing potential arguments
 * Return: Always 0
 */
int our_list(data_t *data)
{
	node_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		a_listn_last(&node, environ[i], 0);
	data->env = node;
	return (0);
}
