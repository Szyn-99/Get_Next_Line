#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("test", O_RDONLY);
    int f = open("test2", O_RDONLY);
    int d = open("test3", O_RDONLY);

    char *s = "A";
    // while(s)
    // {
        s = get_next_line(fd);
        if(s == NULL)
            return 1;
        printf("%s", s);
        free(s);
        s = get_next_line(f);
        if(s == NULL)
            return 1;
        printf("%s", s);
        free(s);
        s = get_next_line(d);
        if(s == NULL)
            return 1;
        printf("%s", s);
        free(s);
        s = get_next_line(fd);
        if(s == NULL)
            return 1;
        printf("%s", s);
        free(s);
        s = get_next_line(f);
        if(s == NULL)
            return 1;
        printf("%s", s);
        free(s);
        s = get_next_line(d);
        if(s == NULL)
            return 1;
        printf("%s", s);
        free(s);
    // }
    return 0;
}