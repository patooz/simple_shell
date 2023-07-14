#include "main.h"

/**
 * a_listn - add list node
 * @a: pointer to the head
 * @s: string of te node
 * @i: list node at index
 * Return: list bytes
 */
node_t *a_listn(node_t **a, const char *s, int i)
{
	node_t *n_a;

	if (!a)
		return (NULL);
	n_a = malloc(sizeof(node_t));
	if (!n_a)
		return (NULL);
	our_memset((void *)n_a, 0, sizeof(node_t));
	n_a->num = i;
	if (s)
	{
		n_a->s = our_strdup(s);
		if (!n_a->s)
		{
			free(n_a);
			return (NULL);
		}
	}
	n_a->in = *a;
	*a = n_a;
	return (n_a);
}
/**
 * a_listn_last - adds a list node to the last node
 * @a: pointer to the head
 * @s: string of the node
 * @i: list node at index
 * Return: the size of the list
 */
node_t *a_listn_last(node_t **a, const char *s, int i)
{
	node_t *n_list, *list;

	if (!a)
	{
		return (NULL);
	}
	list = *a;
	n_list = malloc(sizeof(node_t));
	if (!n_list)
		return (NULL);
	our_memset((void *)n_list., 0, sizeof(node_t));
	n_list->num = i;
	if (s)
	{
		n_list->s = our_strdup(s);
		if (!n_list->s)
		{
			free(n_list);
			return (NULL);
		}
	}
	if (list)
	{
		while (list->in)
			list = list->in;
		list->in = n_list;
	}
	else
		*a = n_list;
	return (n_list);
}
/**
 * show_listn_s - returns the string element of the linked kist
 * @a: pointer o the head node
 * Return: list in bytes
 */
size_t show_listn_s(const node_t *a)
{
	size_t x = 0;

	while (a)
	{
		our_puts(a->s ? a->s : "(nil)");
		our_puts("\n");
		a = a->in;
		x++;
	}
	return (x);
}
/**
 * rm_listn - removes node at index
 * @a: pointer to thr node
 * @i: index
 * Return: 1 is success, 0 if failed
 */
int rm_listn(node_t **a, unsigned int i)
{
	node_t *list, *p_list;
	unsigned int x = 0;

	if (!a || !*a)
		return (0);
	if (!i)
	{
		list = *a;
		*a = (*a)->in;
		free(list->s);
		free(list);
		return (1);
	}
	list = *a;
	while (list)
	{
		if (x == i)
		{
			p_list->in = list->in;
			free(list->d);
			free(list);
			return (1);
		}
		x++;
		p_list = list;
		list = list->in;
	}
	return (0);
}
/**
 * claim_list_mem - frees the memory of the list
 * @a: pointer to the head
 */
void claim_list_mem(node_t **a)
{
	node_t *list, *n_list, *h;

	if (!a || !*a)
		return;
	h = *a;
	list = h;
	while (list)
	{
		n_list = list->in;
		free(list->s);
		free(list);
		list = n_list;
	}
	*a = NULL;
}
