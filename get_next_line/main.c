#include "get_next_line.h"
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
    int fd;
    char *read;
    int i;

    // int x = ft_strlen(str);
    // st = ft_strjoin(str, str2);
    // s = ft_substr(str, 1, 10);
    // up = ft_strdup(st);
    // chr = ft_strchr(str2, c);
    // printf("%s\n%i\n%s\n%s\n%s\n", s, x, st, up, chr);

    // printf("***TEST FOR GET_NEXT_LINE MAIN FUNCTION***\n");
    fd = open("text.txt", O_RDONLY);
    read = get_next_line(fd);
    i = 0;
    while (read)
    {
        printf("%s\n", read);
        free(read);
        read = get_next_line(fd);
    }
    system("leaks a.out");
    close(fd);
    free(read);
    // free(st);
    // free(s);
    // free(up);
    return 0;
}
