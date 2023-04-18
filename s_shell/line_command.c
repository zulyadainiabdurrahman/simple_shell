#include "main.h"
#include <stdio.h>

/**
 * main - This program writes a UNIX command line interpreter
 * Takes no arguments
 * return: 0 when the program is successful

int main()
{
	char *inpts[MAX_COMMAND_LENGTH];
	char cmd[MAX_COMMAND_LENGTH];
	char *tkn

	int i = 0;

	while (1)
	{
		printf("#");
		
		if (fgets(cmd, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("End of line");
		}
	
		cmd[strcspn(cmd, "\n")] = '\0';

		tkn = strtok(cmd, " ");
		while (tkn != NULL)
		{
			inpts[i++] = tkn;
			tkn = strtok(NULL, " ");
		}

		inpts[i] = NULL;

		if (execve(args[0], inpts, NULL) == -1)
		{
			printf("%s failed to execute\n", inpts[0]);
		}
	}
	return (0);
}

