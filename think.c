#include "main.h"

/**
 * free_all - frees null pointer and address
 * @br: pointer to free
 *
 * Return: 1 free, otherwise 0
 */
int free_all(void **br)
{
	if (br && *br)
	{
		free(*br);
		*br = NULL;
		return (1);
	}
	return (0);
}
