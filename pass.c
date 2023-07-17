#include "main.h"

/**
 * pass - check file if it is an executable
 * @i: the info struct
 * @p: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int pass(data_t *i, char *p)
{
	struct stat st;

	(void)i;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * new_char - other characters
 * @ps: PATH string
 * @s: starting index
 * @sp: stopping index
 *
 * Return: pointer to new buffer
 */
char *new_char(char *ps, int s, int sp)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = s; i < sp; i++)
		if (ps[i] != ':')
			buf[k++] = ps[i];
	buf[k] = 0;
	return (buf);
}

/**
 * our_path - the PATH string
 * @data: the info struct
 * @ps: the PATH string
 * @cd: the cd to find
 *
 * Return:  path of cd if found or NULL
 */
char *our_path(data_t *data, char *ps, char *cd)
{
	int i = 0, cs = 0;
	char *path;

	if (!ps)
		return (NULL);
	if ((our_strlen(cd) > 2) && first_char(cd, "./"))
	{
		if (pass(data, cd))
			return (cd);
	}
	while (1)
	{
		if (!ps[i] || ps[i] == ':')
		{
			path = new_char(ps, cs, i);
			if (!*path)
				our_strcat(path, cd);
			else
			{
				our_strcat(path, "/");
				our_strcat(path, cd);
			}
			if (pass(data, path))
				return (path);
			if (!ps[i])
				break;
			cs = i;
		}
		i++;
	}
	return (NULL);
}
