#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * splitw - split arguments
 * @str: a pointer to the string
 *
 * Return: words
 */

char **splitw(char *str)
{
	char *word, **words = NULL;
	int n = 0;

	word = strtok(str,  " \t\n");
	while (word != NULL)
	{
		n++;
		words = realloc(words, n  * sizeof(char *));
		if (words  == NULL)
		{
			perror("invalid input");
		}
		words[n - 1] = word;
		word = strtok(NULL, " \t\n");
	}
	for (int i = 0; words[i]; i++)
		printf("%s\n", words[i]);

	return (words);
}

/**
 * main - Function that prints arguemnts
 * @ac: NUMBERS OF ARGS
 * @av: LIST OF ARGUMENTS
 *
 * Return: Always  0
 */

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char *line = NULL, **words;
	size_t line_cap = 0;
	int n = 0;

	write(1, "$ ", 2);
	n = getline(&line, &line_cap, stdin);
	if (n == -1)
		perror("getline");
	line[n - 1] = '\0';
	words = splitw(line);

	for (int i = 0; words[i]; i++)
{
	free(words[i]);
}
	free(words);

	free(line);

	return (0);
}
