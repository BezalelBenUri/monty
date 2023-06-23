#include "monty.h"
/**
* _exec - executes the opcode
* @stack: head linked list - stack
* @nt: line_counter
* @file: poiner to monty file
* @leap: line content
* Return: no return
*/
int _execute(char *leap, stack_t **stack, unsigned int nt, FILE *file)
{
	instruction_t operation[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(leap, " \n\t");
	if (op && op[0] == '#')
		return (0);
	con.arg = strtok(NULL, " \n\t");
	while (operation[i].opcode && op)
	{
		if (strcmp(op, operation[i].opcode) == 0)
		{	operation[i].f(stack, nt);
			return (0);
		}
		i++;
	}
	if (op && operation[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", nt, op);
		fclose(file);
		free(leap);
		_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
