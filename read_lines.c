#include "monty.h"

/**
 * read_lines - read line by line and analize structure
 *
 * @text: text to read
 * Return: number of characters readed
 */
void read_lines(char *text)
{
	char *lines = NULL, *line = NULL;
	int clines = 0, i = 0;
	char *commands[100];
	
	/*get the lines and save into  array commands*/
	lines = strtok(text, "\n");
	if (lines != NULL)
	{
		commands[clines] = lines;
		clines++;
		printf("line %d is :%s\n", clines, lines);
	}
	while (lines)
	{
		lines = strtok(NULL, "\n");
		if (lines != NULL)
		{
			commands[clines] = lines;
			clines++;
			printf("line %d is :%s\n", clines, lines);
		}
	}

	/*iterate over array to split the opcode and data*/
	for (i = 0; i < clines; i++)
	{
		line = strtok(commands[i], " ");
		if (line != NULL)
			printf("command is %s line %d\n", line, i + 1);
		while (line)
		{
			line = strtok(NULL, " ");
			if (line != NULL)
				printf("command is %s line %d\n", line, i + 1);
			
		}
	}
}
