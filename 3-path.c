#include "main.h"

/**
 * main - This function handles the PATH
 * @argc: Counts the number of arguments passed
 * @argv: Pointer to and array of arguments
 * Return: 0 on success or 1 if otherwise
 */

int main(int argc, char *argv[])
{
	pid_t pid;
	int status;

	if (argc < 2)
	{
		printf("%s command [arguments....]\n", argv[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		execev(argv[1], &argv[1]);
		printf("command not found\n");
		return (1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		return (status);
		else
		{
			return (1);
		}
	}
	else
	{
		printf("fork failed\n");
		return (1);
	}
}

