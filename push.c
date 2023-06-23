#include "monty.h"
/**
 * _push - add node to the stack
 * @hd: stack head
 * @nt: line_number
 * Return: no return
*/
void _push(stack_t **hd, unsigned int nt)
{
	int n, a = 0, flag = 0;

	if (con.arg)
	{
		if (con.arg[0] == '-')
			a++;
		for (; con.arg[a] != '\0'; a++)
		{
			if (con.arg[a] > 57 || con.arg[a] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", nt);
			fclose(con.file);
			free(con.item);
			_free_stack(*hd);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", nt);
		fclose(con.file);
		free(con.item);
		_free_stack(*hd);
		exit(EXIT_FAILURE); }
	n = atoi(con.arg);
	if (con.lifi == 0)
		_add_node(hd, n);
	else
		_add_queue(hd, n);
}
