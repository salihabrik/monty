#include "monty.h"

/**
 * error_malloc_failed - Print error message for malloc failure
 *
 */
void error_malloc_failed(void)
{
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
}

/**
 * error_stack_empty - Print error message for empty stack
 * @line_number: The line number where the error occurred
 * @op: The name of the operation that requires a non-empty stack
 *
 */
void error_stack_empty(unsigned int line_number, char *op)
{
        fprintf(stderr, "L%u: can't %s, stack empty\n", line_number, op);
        exit(EXIT_FAILURE);
}

/**
 * error_stack_short - Print error message for stack being too short
 * @line_number: The line number where the error occurred
 * @op: The name of the operation that requires a longer stack
 */

void error_stack_short(unsigned int line_number, char *op)
{
        fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
        exit(EXIT_FAILURE);
}
