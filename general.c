#include "main.h"

/**
 * general - returns the string to array
 * @i:  arguments to check
 *
 * Return: Always 0
 */
char **general(data_t *i)
{
	if (!i->environ || i->envi_shift)
	{
		i->environ = convert_s(i->env);
		i->envi_shift = 0;
	}

	return (i->environ);
}

/**
 * micro - Remove environment variable
 * @data: arguments to check
 * Return: 1 on delete, 0 otherwise
 * @vr: the string
 */
int micro(data_t *data, char *vr)
{
	node_t *node = data->env;
	size_t i = 0;
	char *p;

	if (!node || !vr)
		return (0);
	while (node)
	{
		p = first_char(node->s, vr);
		if (p && *p == '=')
		{
			data->envi_shift = rm_listn(&(data->env), i);
			i = 0;
			node = data->env;
			continue;
		}
		node = node->in;
		i++;
	}
	return (data->envi_shift);
}

/**
 * mini - new environment
 * @i: arguments to check
 * @vr: the string
 * @v: the string value
 *  Return: Always 0
 */
int mini(data_t *i, char *vr, char *v)
{
	char *buf = NULL;
	node_t *node;
	char *p;

	if (!vr || !v)
		return (0);

	buf = malloc(our_strlen(vr) + our_strlen(v) + 2);
	if (!buf)
		return (1);
	our_strcpy(buf, vr);
	our_strcat(buf, "=");
	our_strcat(buf, v);
	node = i->env;
	while (node)
	{
		p = first_char(node->s, vr);
		if (p && *p == '=')
		{
			free(node->s);
			node->s = buf;
			i->envi_shift = 1;
			return (0);
		}
		node = node->in;
	}
	a_listn_last(&(i->env), buf, 0);
	free(buf);
	i->envi_shift = 1;
	return (0);
}
