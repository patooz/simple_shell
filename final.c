#include "main.h"

/**
 * street - splits string
 * @br: input string
 * @d: the string delimeter
 * Return: pointer to array, NULL on failure
 */
char **street(char *br, char *d)
{
	int i, f, p, n, numwords = 0;
	char **h;

	if (br == NULL || br[0] == 0)
	return (NULL);
	if (!d)
		d = " ";
	for (i = 0; br[i] != '\0'; i++)
		if (!denim(br[i], d) && (denim(br[i + 1], d) || !br[i + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	h = malloc((1 + numwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (i = 0, f = 0; f < numwords; f++)
	{
		while (denim(br[i], d))
			i++;
		p = 0;
		while (!denim(br[i + p], d) && br[i + p])
			p++;
		h[f] = malloc((p + 1) * sizeof(char));
		if (!h[f])
		{
			for (p = 0; p < f; p++)
				free(h[p]);
			free(h);
			return (NULL);
		}
		for (n = 0; n < p; n++)
			h[f][n] = br[i++];
		h[f][n] = 0;
	}
	h[f] = NULL;
	return (h);
}
/**
 * street2 - string to words
 * @br: input string
 * @d:the string delimeter
 *
 * Return: pointer to array,NULL on failure
 */
char **street2(char *br, char d)
{
	int i, f, p, n, numwords = 0;
	char **h;

	if (br == NULL || br[0] == 0)
		return (NULL);
	for (i = 0; br[i] != '\0'; i++)
		if ((br[i] != d && br[i + 1] == d) ||
			       (br[i] != d && !br[i + 1]) || br[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	h = malloc((1 + numwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (i = 0, f = 0; f < numwords; f++)
	{
		while (br[i] == d && br[i] != d)
			i++;
		p = 0;
		while (br[i + p] != d && br[i + p] != d)
			p++;
		h[f] = malloc((p + 1) * sizeof(char));
		if (!h[f])
		{
			for (p = 0; p < f; p++)
				free(h[p]);
			free(h);
			return (NULL);
		}
		for (n = 0; n < p; n++)
			h[f][n] = br[i++];
		h[f][n] = 0;
	}
	h[f] = NULL;
	return (h);
}
