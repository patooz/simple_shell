#include "main.h"

/**
 * *geofile - gets the file
 * @i: parameter struct
 *
 * Return:  string containg  file
 */

char *geofile(data_t *i)
{
	char *buf, *d;

	d = get(i, "HOME=");
	if (!d)
		return (NULL);
	buf = malloc(sizeof(char) * (our_strlen(d) + our_strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	our_strcpy(buf, d);
	our_strcat(buf, "/");
	our_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * geowrite - writes a file
 * @data: parameter struct
 *
 * Return: 1 on success, else -1
 */
int geowrite(data_t *data)
{
	ssize_t f;
	char *filename = geofile(data);
	node_t *node = NULL;

	if (!filename)
		return (-1);

	f = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (f == -1)
		return (-1);
	for (node = data->hist; node; node = node->in)
	{
		our_putnodes(node->s, f);
		our_putnode('\n', f);
	}
	our_putnode(FLUSH, f);
	close(f);
	return (1);
}

/**
 * georead - reads from file
 * @data: parameter struct
 *
 * Return: hist_c on success, 0 otherwise
 */
int georead(data_t *data)
{
	int i, last = 0, linecount = 0;
	ssize_t f, rdlen, fs = 0;
	struct stat st;
	char *buf = NULL, *filename = geofile(data);

	if (!filename)
		return (0);

	f = open(filename, O_RDONLY);
	free(filename);
	if (f == -1)
		return (0);
	if (!fstat(f, &st))
		fs = st.st_size;
	if (fs < 2)
		return (0);
	buf = malloc(sizeof(char) * (fs + 1));
	if (!buf)
		return (0);
	rdlen = read(f, buf, fs);
	buf[fs] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(f);
	for (i = 0; i < fs; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			geolist(data, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		geolist(data, buf + last, linecount++);
	free(buf);
	data->hist_c = linecount;
	while (data->hist_c-- >= HIST_MAX)
		rm_listn(&(data->hist), 0);
	georenumber(data);
	return (data->hist_c);
}

/**
 * geolist -  entry to a linked list
 * @i: Structure Used to maintain argument
 * @buf: buffer
 * @linecount: the hist linecount, hist_c
 *
 * Return: Always 0
 */
int geolist(data_t *i, char *buf, int linecount)
{
	node_t *node = NULL;

	if (i->hist)
		node = i->hist;
	a_listn_last(&node, buf, linecount);

	if (!i->hist)
		i->hist = node;
	return (0);
}

/**
 * georenumber - renumbers the hist linked list after changes
 * @data: Structure Used to maintain argument
 *
 * Return: the new hist_c
 */
int georenumber(data_t *data)
{
	node_t *node = data->hist;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->in;
	}
	return (data->hist_c = i);
}
