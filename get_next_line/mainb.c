#include "get_next_line_bonus.h"
#include <stdio.h>
#include <string.h>

int main()
{
    // char str[] = "You’ve gona be Incognito";
    // char str2[] = "You are not alone";
    // char c = 'n';
    // char *s;
    // char *st;
    // char *up;
    // char *chr;
    // int x = ft_strlen(str);
    // st = ft_strjoin(str, str2);
    // s = ft_substr(str, 1, 10);
    // up = ft_strdup(st);
    // chr = ft_strchr(str2, c);
    // printf("%s\n%i\n%s\n%s\n%s\n", s, x, st, up, chr);

    // printf("***TEST FOR GET_NEXT_LINE MAIN FUNCTION***\n");
    char *read;
    int i;
    int fd[3];
    fd[0] = open("../tests/t1.c", O_RDONLY);
    fd[1] = open("../tests/t2.c", O_RDONLY);
    fd[2] = open("../tests/text.txt", O_RDONLY);
    fd[3] = open("../tests/a.c", O_RDONLY);
    fd[4] = open("../tests/b.c", O_RDONLY);
    // fd[5] = open("c.txt", O_RDONLY);
    // fd[6] = open("d.txt", O_RDONLY);
    // fd[7] = open("g.txt", O_RDONLY);
    i = 0;
    int j = 0;
    while (i < 5)
    {
        while ((read = get_next_line(fd[i])) != NULL) 
        {
            printf("(line: ---> ) %s", read);
            free(read);
        }
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
    close(fd[i]);
    system("leaks a.out");
    // free(st);
    // free(s);
    // free(up);
    return 0;
}
