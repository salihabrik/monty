#include "monty.h"

/**
 * error_usage - Print error message for incorrect usage
 * @line_number: The line number where the error occurred
<<<<<<< HEAD
 *
=======
>>>>>>> aeb096e71b852d5127b48ef233adfb1288e9f77e
 */
void error_usage(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: monty file\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * error_file_open - Print error message for file open failure
 * @file: The name of the file that failed to open
<<<<<<< HEAD
 *
=======
>>>>>>> aeb096e71b852d5127b48ef233adfb1288e9f77e
 */
void error_file_open(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * error_unknown_instruction - Print error message for unknown instruction
 * @line_number: The line number where the error occurred
 * @opcode: The unknown opcode
<<<<<<< HEAD
 *
=======
>>>>>>> aeb096e71b852d5127b48ef233adfb1288e9f77e
 */
void error_unknown_instruction(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

<<<<<<< HEAD
=======
/**
 * error_malloc_failed - Print error message for malloc failure
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

>>>>>>> aeb096e71b852d5127b48ef233adfb1288e9f77e
