#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
   int fd = open("main.c", O_RDONLY);

   char *s = "A";
   while (s)
   {
      s = get_next_line(fd);
      printf("%s", s);
      free(s);
   }

   close(fd);
   return 0;
}