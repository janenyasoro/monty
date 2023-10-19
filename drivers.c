#include "montymain.h"
char **tok = NULL;
/**
 *main - Entry point
 *@argc: Argument count
 *@argv: Arguments passed from terminal
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	size_t exit_stat;
	FILE *fmonty = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fmonty = fopen(argv[1], "r");
	if (fmonty == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	exit_stat = interpreter(fmonty);
	fclose(fmonty);

	return (exit_stat);
}
