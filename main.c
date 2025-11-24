#include "fcntl.h"
#include "stdio.h"
#include "gnl/get_next_line_bonus.h"

int	main(void)
{
	int	fd1 = open("test1", O_RDONLY);
	int	fd2 = open("test2", O_RDONLY);
	int	fd3 = open("test3", O_RDONLY);

    // int fd = -1;
	char	*linef1;
    char	*linef2;
    char	*linef3_1;
    while (1)
    {
        linef1 = get_next_line(fd1);
        linef2 = get_next_line(fd2);
        linef3_1 = get_next_line(fd3);
        if (!linef1 || !linef2 || !linef3_1)
            break;
        printf("%s", linef1);
        printf("%s", linef2);
        printf("%s", linef3_1);
        free(linef1);
        free(linef2);
        free(linef3_1);
    }
    free(linef1);
    free(linef2);
    free(linef3_1);
	return (0);
}
