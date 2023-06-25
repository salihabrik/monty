#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		error_add_short(line_number);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}




/**
 * nop - Does nothing
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
