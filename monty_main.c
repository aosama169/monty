#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - monty app entry point
 *
 * @argc: count of args passed to program
 * @argv: pointer to array of char pointers to args
 *
 * Return: exit status success or failure
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exitCode = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exitCode = run_monty(script_fd);
	fclose(script_fd);
	return (exitCode);
}
