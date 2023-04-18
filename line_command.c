#include "main.h"

/**
 * simple_shell - This function writes a UNIX command line interpreter
 * Takes no arguments
 * Return: void
 */

void simple_shell(void)
{
	char *inpt = NULL;
	size_t buf_size = 0;
	char *tkn;
	char **argmts;

	int status;
	int i = 0;

	while (1)
	{
		printf("#");
		if (getline(&inpt, &buf_size, stdin) == -1)
		{
			printf("\n");
			break;
		}

		if (inpt[0] == '\n' || inpt[0] == '#')
		{
			continue;
		}

		argmts = malloc(sizeof(char *) * 64);
		tkn = strtok(inpt, "\n");
		while (tkn != NULL)
		{
			argmts[i++] = tkn;
			tkn = strtok(NULL, "\n");
		}

		argmts[i] = NULL;

		pid_t pid = fork();

		if (pid == -1)
		{
		printf("Error: child process failed to be created\n");
		}
			else if (pid == 0)
			{
				if (execve(argmts[0], argmts) == -1)
				{
				printf("Error: command failed to execute\n");
				}
				exit(0);
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		free(argmts);
	}

	free(inpt);
}

