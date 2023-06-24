#include "monty.h"

/**
 * execute_opcode - Executes the opcode function based on the instruction
 * @instruction: Instruction containing the opcode and its function
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void execute_opcode(instruction_t *instruction, stack_t **stack, unsigned int line_number)
{
	if (instruction->f != NULL)
		instruction->f(stack, line_number);
	else
	{
		free_stack(*stack);
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
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		instruction_t instruction;
		char *opcode = NULL;

		opcode = strtok(line, " \t\n");
		if (opcode != NULL && opcode[0] != '#')
		{
			instruction.opcode = opcode;
			instruction.f = get_opcode_function(opcode);
			if (instruction.f == NULL)
			{
				free(line);
				free_stack(stack);
				error_unknown_instruction(line_number, opcode);
			}
			execute_opcode(&instruction, &stack, line_number);
		}
		line_number++;
	}
	free(line);
	free_stack(stack);
}

/**
 * get_opcode_function - Retrieves the function associated with the opcode
 * @opcode: The opcode
 *
 * Return: Pointer to the function associated with the opcode, NULL if not found
 */
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opcode_functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i = 0;

	while (opcode_functions[i].opcode != NULL)
	{
		if (strcmp(opcode_functions[i].opcode, opcode) == 0)
			return (opcode_functions[i].f);
		i++;
	}

	return (NULL);
}
