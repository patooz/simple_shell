#include  "main.h"

/**
 * c_data - initialize data_t struct
 * @data: struct address
 */
void cdata_t(data_t *data)
{
	data->argv = NULL;
	data->argc = 0;
	data->path = NULL;
	data->arg = NULL;
}

/**
 * sdata_t - initializes data_t struuct
 * @data: struct address
 * @av: argument vecto
 */
void sdata_t(data_t *data, char **a)
{
	int i = 0;

	data->_file = a[0];
	if (data->arg)
	{
		data->argv = street(data->arg, " \t");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = our_strdup(data->arg);
				data->argv[1] = NULL;
			}
		}
		for (i = 0; data->argv && data->argv->[i]; i++)
			;
		data->argc = i;

		other_wise_command(data);
		r_command(data);
	}
}

/**
 * fdata_t - frees dta_t struct fields
 * @dat: struct address
 * @all: true if freeing all fields
 */
void fdata_t(data_t *data, int sawa)
{
	_free(data->argv);
	data->argv = NULL;
	data->p = NULL;
	if  (sawa)
	{
		if (!data->d_buff)
			free(data->arg);
		if (data->env)
			claim_list_mem(&(data->env));
		if (data->hist)
			claim_list_mem(&(data->hist));
		if (data->otherwise)
			claim_list_mem(&(data->otherwise));
		_free(data->environ);
		data->environ = NULL;
		free_all((void **)data->d_buff);
		if (data->fd_read > 2)
			close(data->fd_read);
		our_putchar(FLUSH);
	}
}
