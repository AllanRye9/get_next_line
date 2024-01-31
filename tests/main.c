#include "get_next_line_bonus.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char *read;
    int i;
    int fd;

    fd = open("../tests/a.c", O_RDONLY);
    i = 0;
    int j = 0;
    while (i < 1)
    {
        while ((read = get_next_line(fd)) != NULL) 
        {
            printf("(line: ---> ) %s", read);
            free(read);
        }
        printf("\n");
        printf("\n");
        printf("File # (%d) successfully read", ++j);
        printf("\n");
        printf("fd: (%i)", fd);
        printf("\n");
        printf("\n");
    i++;
    }
    printf("\n");
    free(read);
    close(fd);
    return 0;
}
