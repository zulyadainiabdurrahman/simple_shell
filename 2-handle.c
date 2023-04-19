#include "main.h"
/**
 * handle_argument - function that handle command line argument
 * @argc: argument count
 * @argv: argument victor
 * Return: 0 for success
 */

int handle_argument(int argc, char *argv[])
{
	int i;

	for (i = 0 ; i < argc ; i++)
	{
		printf("argument %d: %s\n", i, argv[i]);
	}
	return (0);

}
/**
 * main - main entry point
 * @argc: argument count
 * @argv: argument victor
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	handle_argument(argc, argv);

	return (0);
}
