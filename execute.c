#include "monty.h"

/**
 * execute_opcode - Executes the opcode function associated with the instruction
 * @instruction: Pointer to the instruction
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void execute_opcode(instruction_t *instruction, stack_t **stack, unsigned int line_number)
{
	if (instruction->opcode)
	{
		void (*f)(stack_t **, unsigned int);

		f = get_opcode_function(instruction->opcode);
		if (f)
			f(stack, line_number);
		else
			error_unknown_instruction(line_number, instruction->opcode);
	}
}

/**
 * execute_file - Executes the Monty bytecode file
 * @file: Pointer to the Monty bytecode file
 */
void execute_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instruction;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		instruction = parse_instruction(line);
		execute_opcode(&instruction, &stack, line_number);
		free(instruction.opcode);
		free(line);
		line = NULL;
	}
	free(line);
	free_stack(&stack);
}

