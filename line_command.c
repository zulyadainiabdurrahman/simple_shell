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
	int num_tkns = 0;

	while (1)
	{
		printf("#");
		if (getline(&inpt, &buf_size, stdin) == -1)
		{
			printf("\n");
			break;
		}

		argmts = malloc(sizeof(char *) * (num_tkns + 1));
		tkn = strtok(inpt, " \n");
		while (tkn != NULL)
		{
			argmts[num_tkns++] = tkn;
			tkn = strtok(NULL, " \n");
			argmts = realloc(argmts, sizeof(char *) * (num_tkns +1));
		}

		argmts[num_tkns] = NULL;

		if (num_tkns > 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
			printf("Error: child process failed to be created\n");
			}
			else if (pid == 0)
			{
				if (execve(argmts[0], argmts, NULL) == -1)
				{
				printf("Error: command failed to execute\n");
				}
				exit(0);
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
		free(argmts);
	}

	free(inpt);
}

