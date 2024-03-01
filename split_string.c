#include "main.h"

/**
* split_string - shell with arguments.
* @string: arguments string
*@nbr_char: number chars in string.
* Return: array type strings.
*/

char** split_string(char *string, size_t nbr_char)
{

	int i;
	char* word;
	char** words;
	
	word = strtok(string, " \t\n");
	if (word == NULL)
	{
		free(string), string = NULL;
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
	}
	else
	{
		words = (char **)malloc((nbr_char + 2) * sizeof(char *));
		if (words == NULL)
		{
			perror("malloc");
			free(string), string = NULL;
			exit(EXIT_FAILURE);
		}
		while (word != NULL)
		{
			words[i] = word;
			i++;
			word = strtok(NULL, " \t\n");
		}
		words[i] = NULL;	
	}
	return (words);
}	/*word = strtok(string, " \t\n");
	while (word != NULL) {
		i++;
		word = strtok(NULL, " \t\n");
	}

	words = (char**)malloc(i * sizeof(char*));
	if (word == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	word = strtok(string, " \t\n");
	for (i = 0; word; i++)
	{
		words[i] = word;
		word = strtok(NULL, " \t\n");
	}
	words[i] = NULL;
	return (words);
	}*/
