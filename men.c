#include "main.h"

/**
 * main - entry point
 * @a: arg count
 * @b: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int a, char **b)
{
	data_t data[] = { DATA_IT };
	int f = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (f)
		: "r" (f));

	if (a == 2)
	{
		f = open(b[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				our_eputs(b[0]);
				our_eputs(": 0: Can't open ");
				our_eputs(b[1]);
				our_eputchar('\n');
				our_eputchar(FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		data->fd_read = f;
	}
	our_list(data);
	georead(data);
	loop(data, b);
	return (EXIT_SUCCESS);
}
