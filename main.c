#include "monty.h"
con_t con = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *leap;
	FILE *file;
	size_t size = 0;
	ssize_t check_line = 1;
	stack_t *stack = NULL;
	unsigned int nt = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	con.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (check_line > 0)
	{
		leap = NULL;
		check_line = getline(&leap, &size, file);
		con.item = leap;
		nt++;
		if (check_line > 0)
		{
			_exec(leap, &stack, nt, file);
		}
		free(leap);
	}
	_free_stack(stack);
	fclose(file);
return (0);
}
