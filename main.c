#include "main.h"

/**
* main - shell with arguments.
* @argc: arguments counts
* @argv: pointer of strings.
* Return: Always 0.
*/

int main(int argc, char **argv)
{
	int pid, stemp;
	char *buffer = NULL, **words = NULL;
	size_t nbr_char = 0;
	ssize_t read;
	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
	while ((read = getline(&buffer, &nbr_char, stdin) != -1))
	{
		if (read == -1)
		{
			perror("getline");
			free(buffer);
			buffer = NULL;
			exit(EXIT_FAILURE);
		}
		if (read == 0)
		{
			free(buffer);
			continue;
		}
		if (f_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer), buffer = NULL;
			break;
		}
		if (f_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer), buffer = NULL;
			break;
		}
		words = split_string(buffer, nbr_char);
		if (words == NULL)
		{
			free(buffer), buffer = NULL;
			if (isatty(STDIN_FILENO) == 1)
				write(1, "$ ", 2);
			continue;		
		}
		else
		{
			pid = fork();
			if (pid < 0)
			{
				perror("fork");
				free(words), words = NULL;
				free(buffer), buffer = NULL;
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				if (execve(words[0], words, environ) == -1)
				{
					perror(argv[0]);
					exit(127);
				}
			}
			else if (pid > 0)
			{
				wait(&stemp);
				if (isatty(STDIN_FILENO) == 1)
					write(1, "$ ", 2);
				free(words), words = NULL;
			}
		}
	}
	free(buffer);
	free(words);
	return (0);
}
