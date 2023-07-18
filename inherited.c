#include "main.h"

/**
 * our_quit - quits thr simple_shell
 * @data: argument needed
 * Return: quits shell
 */
int our_quit(data_t *data)
{
	int i;

	if (data->argv[1])
	{
		i = strip_c(data->argv[1]);
		if (i == -1)
		{
			data->condition = 2;
			show_emsg(data, "Unsupported character: ");
			our_eputs(data->argv[1]);
			our_eputchar('\n');
			return (1);
		}
		data->char_fail = strip_c(data->argv[1]);
		return (-2);
	}
	data->char_fail = -1;
	return (-2);
}
/**
 * our_dir - changes the working dir
 * @data: arguments needed
 * Return: 0
 */
int our_dir(data_t *data)
{
	char *p, *rt, b[1024];
	int back;

	p = getcwd(b, 1024);
	if (!p)
		our_puts(">>failure\n");
	if (!data->argv[1])
	{
		rt = get(data, "HOME=");
		if (!rt)
			back = chdir((rt = get(data, "PWD=")) ? rt : "/");
		else
			back = chdir(rt);
	}
	else if (our_strcmp(data->argv[1], "-") == 0)
	{
		if (!get(data, "OLDPWD="))
		{
			our_puts(p);
			our_putchar('\n');
			return (1);
		}
		our_puts(get(data, "OLDPWD=")), our_putchar('\n');
		back = chdir((rt = get(data, "OLDPWD")) ? rt : "/");
	}
	else
		back = chdir(data->argv[1]);
	if (back == -1)
	{
		show_emsg(data, "cannot cd to directrory ");
		our_eputs(data->argv[1]), our_putchar('\n');
	}
	else
	{
		mini(data, "OLDPWD", get(data, "PWD="));
		mini(data, "PWD", getcwd(b, 1024));
	}
	return (0);
}
/**
 * our_help - changes dir
 * @data: arguments needed
 * Return: 0
 */
int our_help(data_t *data)
{
	char **r;

	r = data->argv;
	ourputs("help is okay\n");
	if (0)
		our_puts(*r);
	return (0);
}
