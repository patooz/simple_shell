#include "main.h"

/**
 * find_input - finds the line
 * @data: parameter for the struct
 * Return: bytes
 */
ssize_t find_input(data_t *data)
{
	static size_t i, j, k;
	ssize_t l = 0;
	static char *m;
	char **o = &(data->arg), *p;

	our_putchar(FLUSH);
	l = b_input(data, &m, &k);
	if (l == -1)
		return (-1);
	if (k)
	{
		j = i;
		p = m + i;
		find_command(data, m, &j, i, k);
		while (j < k)
		{
			if (is_c_command(data, m, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= k)
		{
			i = k = 0;
			data->command_t = C_NORM;
		}
		*o = p;
		return (our_strlen(p));
	}
	*o = m;
	return (1);
}
/**
 * find_ln - finds the next line
 * @data: prameter to the struct
 * @a: pointer to the buffer
 * @ln: lenght of the buffer size
 * Return: next line (n)
 */
int find_ln(data_t *data, char **a, size_t *ln)
{
	static char b[BUFF_READ];
	static size_t i, l;
	size_t k;
	ssize_t m = 0, n = 0;
	char *o = NULL, *_o = NULL, *p;

	o = *a;
	if (o && ln)
		n = *ln;
	if (i == l)
		i = l = 0;
	m = b_read(data, b, &l);
	if (m == -1 || (m == 0 && l == 0))
		return (-1);
	p = our_strchr(b + i, '\n');
	k = p ? 1 + (unsigned int)(p - b) : l;
	_o = alloc(o, n, n ? n + k : k + 1);
	if (!_o)
		return (o ? free(o), -1 : -1);
	if (n)
		our_strncat(_o, b + i, k - i);
	else
		our_strncpy(_o, b + i, k - i + 1);
	n += k - i;
	i = k;
	o = _o;
	if (ln)
		*ln = n;
	*a = o;
	return (n);
}
/**
 * b_read - reads the buffer
 * @data: parameter to the struct
 * @b: the buffer itself
 * @size: the size f the buffer
 * Return: i
 */
ssize_t b_read(data_t *data, char *b, size_t *size)
{
	ssize_t i = 0;

	if (*size)
		return (0);
	i = read(data->fd_read, b, BUFF_READ);
	if (i >= 0)
		*size = i;
	return (i);
}
/**
 * b_input - chain commands of the buffer
 * @data: parameter t the struct
 * @b: buffer address
 * @l: address of l
 * Return: number of the bytes
 */
ssize_t b_input(data_t *data, char **b, size_t *l)
{
	size_t ln = 0;
	ssize_t i = 0;

	if (!*l)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, sig_h);
#if SYS_GETLINE
		i = getline(b, &ln, stdin);
#else
		i = find_ln(data, b, &ln);
#endif
		if (i > 0)
		{
			if ((*b)[i - 1] == '\n')
			{
				(*b)[i - 1] = '\0';
				i--;
			}
			data->c_line = 1;
			strip_c(*b);
			geolist(data, *b, data->hist_c++);
			if (our_strchr(*b, ';'))
			{
				*l = i;
				data->d_buff = b;
			}
		}
	}
	return (i);
}
/**
 * sig_h - prevents ctrl+c
 * @n: signall number
 */
void sig_h(__attribute__((unused)) int n)
{
	our_puts("\n");
	our_puts("> ");
	our_putchar(FLUSH);
}
