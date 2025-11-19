#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("main.c", O_RDONLY);
	s = "A";
	for (;;)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
