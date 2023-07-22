#include "main.h"

/**
 * our_strcmp - compares two strings
 * @string1: first string
 * @string2: second string
 * Return: if string1 is less than string2, return negative
 * else return 0 if the strings are thr same
 */
int our_strcmp(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	if (*string1 == *string2)
		return (0);
	else
		return (*string1 < *string2 ? -1 : 1);
}

/**
 * first_char - searches through for a string
 * @find: string to find
 * @search: string to search
 * Return: NULL if no address, else retun the address
 */
char *first_char(const char *find, const char *search)
{
	while (*find)
	{
		if (*find++ != *search++)
			return (NULL);
	}
	return ((char *)search);
}

/**
 * our_strlen - lenght of the strinf
 * @p: the string
 * Return: length of the string
 */
int our_strlen(char *p)
{
	int x = 0;

	if (!p)
		return (0);
	while (*p++)
		x++;
	return (x);
}

/**
 * our_strcat - concatnates two strings
 * @string1: first string
 * @string2: second string
 * Return: pointer ti the second string
 */
char *our_strcat(char *string2, char *string1)
{
	char *s = string2;

	while (*string2)
		string2++;
	while (*string1)
		*string2++ = *string1++;
	*string2 = *string1;
	return (s);
}
