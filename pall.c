#include "monty.h"
/**
 * _pall - prints the stack
 * @hd: stack head
 * @nt: no used
 * Return: no return
*/
void _pall(stack_t **hd, unsigned int nt)
{
	stack_t *mt;
	(void)nt;

	mt = *hd;
	if (mt == NULL)
		return;
	while (mt)
	{
		printf("%d\n", mt->n);
		mt = mt->next;
	}
}
