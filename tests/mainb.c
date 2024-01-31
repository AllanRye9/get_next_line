#include "get_next_line_bonus.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char *read;
    int i;
    int fd[8];

    fd[0] = open("../tests/c.c", O_RDONLY);
    fd[1] = open("../tests/d.c", O_RDONLY);
    fd[2] = open("../tests/e.c", O_RDONLY);
    fd[3] = open("../tests/a.c", O_RDONLY);
    fd[4] = open("../tests/b.c", O_RDONLY);
    fd[5] = open("../tests/f.c", O_RDONLY);
    fd[6] = open("../tests/text.txt", O_RDONLY);
    fd[7] = open("../tests/g.c", O_RDONLY);
    i = 0;
    int j = 0;
    while (i < 8)
    {
        while ((read = get_next_line(fd[i])) != NULL) 
        {
            printf("(line: ---> ) %s", read);
            free(read);
        }
        close(fd[i]);
        printf("\n");
        printf("\n");
        printf("File # (%d) successfully read", ++j);
        printf("\n");
        printf("fd: (%i)", fd[i]);
        printf("\n");
        printf("\n");
    i++;
    }
    printf("\n");
    free(read);
    return 0;
}
