#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number being executed in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	if (!value)
	{
		handle_error(line_number, "usage: push integer");
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		handle_malloc_error();
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}
