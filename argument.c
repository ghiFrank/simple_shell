#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	char *line = NULL;
	size_t line_cap = 0;
	int n = 0;

	write(1, "$ ", 2);
	n = getline(&line, &line_cap, stdin);
	if (n == -1)
		perror("getline");
	printf("%s\n", line);

	return (0);
}

