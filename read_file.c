#include "monty.h"

/**
 * read_file - read a file sended
 *
 * @filename: file to read
 * @fsize: size of buffer to read
 * Return: number of characters readed
 */
ssize_t read_file(const char *filename, size_t fsize)
{
	int fd, read_text, write_text;
	char *text = NULL, *line = NULL;
	char delim[] = "\n";

	/*validate if filename is don't  send*/
	if (filename == NULL)
		return (0);
	/*allocate memory for buffer*/
	text = malloc(sizeof(char) * fsize);
	if (text == NULL)
		return (0);
	/*open file read only*/
	fd = open(filename, O_RDONLY);
	/*validate if open file fail */
	if (fd == -1)
	{
		free(text);
		return (0);
	}

	/*read file*/
	read_text = read(fd, text, fsize);
	/*validate if read file fail*/
	if (fd == -1)
	{
		free(text);
		close(fd);
		return (0);
	}
	/*printf("the text is: %s\n", text);
	line = strtok(text, delim);
	printf("the first line is: %s\n", line);*/



	read_lines(text);

	/*write text readed*/
	/*write_text = write(STDOUT_FILENO, text, read_text);*/
	/*validate if write file fail*/
	/*if (write_text == -1)
		return (0);
	free(text);
	close(fd);*/
	/*return number of charcaters readed*/
	return (read_text);
}
