#include "main.h"

/**
* f_strcmp - compare two strings.
* @str1: the first string.
* @str2: the second string.
* Return: 0, or > 0, or < 0.
*/

int f_strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
