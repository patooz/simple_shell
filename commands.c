#include "main.h"
/**
 * is_c_command - check if cahr is cahin delimeter
 * @data: struct parameter
 * @b: character
 * @n: buffer address
 * Return: 1
 */
int is_c_command(data_t *data, char *b, size_t *n)
{
	size_t i = *n;

	if (b[i] == '|' && b[i + 1] == '|')
	{
		b[i] = 0;
		i++;
		data->d_buff_t = C_O;
	}
	else if (b[i] == '&' && b[i + 1] == '&')
	{
		b[i] = 0;
		i++;
		data->d_buff_t = C_A;
	}
	else if (b[i] == ';')
	{
		b[i] = 0;
		data->d_buff_t = C_C;
	}
	else
		return (0);
	*n = i;
	return (1);
}
/**
 * find_command - checks command
 * @data: struct parameter
 * @b: character
 * @n: address in the buff
 * @x: buff starting point
 * @l: lenght of the buff
 */
void find_command(data_t *data, char *b, size_t *n, size_t x, size_t l)
{
	size_t i = *n;

	if (data->d_buff_t == C_A)
	{
		if (data->condition)
		{
			b[x] = 0;
			i = l;
		}
	}
	if (data->d_buff_t == C_O)
	{
		if (!data->condition)
		{
			b[x] = 0;
			i = l;
		}
	}
	*n = i;
}
/**
 * r_command - replaces a variable
 * @data: struct parameter
 * Return: 1 if command replaced, else 0
 */
int r_command(data_t *data)
{
	int x = 0;
	node_t *list;

	for (x = 0; data->argv[x]; x++)
	{
		if (data->argv[x][0] != '$' || !data->argv[x][1])
			continue;
		if (!our_strcmp(data->argv[x], "$?"))
		{
			rs_command(&(data->argv[x]),
				our_strdup(novit_char(data->condition, 10, 0)));
			continue;
		}
		if (!our_strcmp(data->argv[x], "$$"))
		{
			rs_command(&(data->argv[x]),
					our_strdup(novit_char(getpid(), 10, 0)));
			continue;
		}
		list = init_from(data->env, &data->argv[x][1], '=');
		if (list)
		{
			rs_command(&(data->argv[x]), our_strdup(our_strchr(list->s, '=') + 1));
			continue;
		}
		rs_command(&data->argv[x], our_strdup(""));
	}
	return (0);
}
/**
 * other_wise_command - substitutes alias
 * @data: struct parameter
 * Return: 1
 */
int other_wise_command(data_t *data)
{
	int x;
	node_t *liist;
	char *n;

	for (x = 0; x < 10; x++)
	{
		list = init_from(data->otherwise, data->argv[0], '=');
		if (!list)
			return (0);
		free(data->argv[0]);
		n = our_strchr(list->s, '=');
		if (!n)
			return (0);
		n = our_stdrup(n + 1);
		if (!n)
			return (0);
		data->argv[0] = n;
	}
	return (1);
}
/**
 * rs_command - replaces a string
 * @fossil: old string
 * @current: new string
 * Return: 1
 */
int rs_command(char **fossil, char *current)
{
	free(*fossil);
	*fossil = current;
	return (1);
}
