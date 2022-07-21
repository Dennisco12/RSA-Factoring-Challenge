#include "factors.h"

/**
 * read_file - This opens and copies the content
 * of the command file into a buffer
 * @filename: The path to the file to be executed
 * Return: a buffer containing the content
 */

char *read_file(char * filename)
{
	int fd, bytes_read;
	char *buffer;

	buffer = malloc(sizeof(char *) * 1024);
	fd = open(filename, O_RDWR);
	if (fd == -1)
	{
		dprintf(2, "can't open file\n");
		exit(EXIT_FAILURE);
	}

	bytes_read = read(fd, buffer, 1024);
	if (bytes_read == -1)
	{
		dprintf(2, "can't read file\n");
		exit(EXIT_FAILURE);
	}
	close (fd);
	printf("file successfully read\n");
	return (buffer);
}


/**
 * tokenise - This splits the content of the file
 * into lines and store these lines into an array
 * @buffer: content of file
 */

void tokenise(char *buffer)
{
	unsigned int lines[75];
	int j = 1, n;
	char *token;

	token = strtok(buffer, "\n");
	lines[0] = atoi(token);
	factor(lines[0]);
	while (token != NULL)
	{
		token = strtok(NULL, "\n");
		lines[j] = atoi(token);
		factor(lines[j]);
		j++;
	}

	printf("All lines succesfully read\n");
	/*n = 0;
	while (lines[n])
	{
		factor(lines[n]);
		n++;
	}*/
	printf("tokenise function completed\n");
}


/**
 * factor - prints the result of the two multiplying
 * factors
 * @num: The number to be factored
 */

void factor(unsigned int num)
{
	int n;

	for (n = 2; n < num; n++)
	{
		if (num % n == 0)
		{
			printf("%d=%d*%d\n", num, num / n, n);
			return;
		}
	}
}


/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *buf;
	(void)argc;

	buf = read_file(argv[1]);
	tokenise(buf);
	return (0);
}
