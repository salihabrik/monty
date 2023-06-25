#include "monty.h"

/**
 * stack - Sets the stack mode (LIFO)
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_struct.mode = STACK;
}

/**
 * queue - Sets the queue mode (FIFO)
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_struct.mode = QUEUE;
}
