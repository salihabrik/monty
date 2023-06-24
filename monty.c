#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: The number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *filename;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	init_stack();
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		parse_line(line, line_number);
	}

	free(line);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

