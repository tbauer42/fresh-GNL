#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int     main(int ac, char **av)
{
	int fd;
	char *line;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
	}
	else
	{
		while (get_next_line(0, &line) > 0)
		{
			printf("%s\n", line);
		}
	}
}
