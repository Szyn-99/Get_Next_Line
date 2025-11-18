#include <stdio.h>
#include "get_next_line.h"

int main()
{
   int fd = open("get_next_line.c", O_RDONLY);
   char *s;
   for(;;)
   {
      s = get_next_line(fd);
      printf("%s", s);
      free(s);
   }
   close(fd);
}