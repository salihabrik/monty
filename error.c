#include "monty.h"

/**
 * error_usage - Print error message for incorrect usage
 * @line_number: The line number where the error occurred
 *
 */
void error_usage(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: monty file\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * error_file_open - Print error message for file open failure
 * @file: The name of the file that failed to open
 *
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
 *
 */
void error_unknown_instruction(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

