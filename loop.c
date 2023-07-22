#include "main.h"
/**
 * loop - main loop
 * @data: struct parametr
 * @p: aargument for main funcion
 * Return: 0 on success, else 1 on error
 */
int loop(data_t *data, char **p)
{
	ssize_t a = 0;
	int b = 0;

	while (a != -1 && b != -2)
	{
		cdata_t(data);
		if (active(data))
			our_puts("$ ");
		our_eputchar(FLUSH);
		a = find_input(data);
		if (a != -1)
		{
			sdata_t(data, p);
			b = get_inherent(data);
			if (b == -1)
				get_d(data);
		}
		else if (active(data))
			our_putchar('\n');
		fdata_t(data, 0);
	}
	geowrite(data);
	fdata_t(data, 1);
	if (!active(data) && data->condition)
		exit(data->condition);
	if (b == -2)
	{
		if (data->char_fail == -1)
			exit(data->condition);
		exit(data->char_fail);
	}
	return (b);
}
/**
 * get_inherent - gets a system command
 * @data: struct parameter
 * Return: 0 if sucess, 1 if found , -1 if found, -2 if exit
 */
int get_inherent(data_t *data)
{
	int x, b = -1;
	sys_data sysdata[] = {
		{"cd", our_dir},
		{"env", our_env},
		{"setenv", our_set},
		{"unsetenv", our_unset},
		{"alias", our_otherwise},
		{"history", our_hist},
		{"help", our_help},
		{"exit", our_quit},
		{NULL, NULL}
	};

	for (x = 0; sysdata[x].type; x++)
		if (our_strcmp(data->argv[0], sysdata[x].type) == 0)
		{
			data->ren_counter++;
			b = sysdata[x].func(data);
			break;
		}
	return (b);
}
/**
 * get_d - gets a command in the PATH
 * @data: struct parameter
 */
void get_d(data_t *data)
{
	char *p = NULL;
	int b, c;

	data->p = data->argv[0];
	if (data->emblem_ln == 1)
	{
		data->ren_counter++;
		data->emblem_ln = 0;
	}
	for (b = 0, c = 0; data->arg[b]; b++)
	{
		if (!denim(data->arg[b], " \t\n"))
			c++;
	}
	if (!c)
		return;
	p = our_path(data, get(data, "PATH="), data->argv[0]);
	if (p)
	{
		data->p = p;
		hook_c(data);
	}
	else
	{
		if ((active(data) || get(data, "PATH=")
					|| data->argv[0][0] == '/') && pass(data, data->argv[0]))
			hook_c(data);
		else if (*(data->arg) != '\n')
		{
			data->condition = 127;
			show_emsg(data, "cannot be found\n");
		}
	}
}
/**
 * hook_c - executes command to run the shell
 * @data: struct parameter
 */
void hook_c(data_t *data)
{
	pid_t a;

	a = fork();
	if (a == -1)
	{
		perror("Erro:");
		return;
	}
	if (a == 0)
	{
		if (execve(data->p, data->argv, general(data)) == -1)
		{
			fdata_t(data, 1);
			if (errno == EACCES)
				exit(1);
		}
	}
	else
	{
		wait(&(data->condition));
		if (WIFEXITED(data->condition))
		{
			data->condition = WEXITSTATUS(data->condition);
			if (data->condition == 126)
				show_emsg(data, "Not allowed\n");
		}
	}
}
