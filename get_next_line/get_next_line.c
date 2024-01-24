#include "get_next_line.h"

char *ft_read_line_end(char *s)
{
    size_t i;
    size_t len;
    char *tem;
    
    i = 0;
    len = 0;
    while (s[i] != '\0' && s[i] != '\n')
    i++;
    if (s[i] == '\n')
        tem = ft_substr(s, 0, len + 1);
    else
        tem = ft_substr(s, 0, len);
    return (tem);
    free(tem);
}
char *read_line(int fd, char *rd)
{
    char *dyn_buff;
    char *tem;
    int out;

    dyn_buff = (char *)malloc(sizeof(char) * BUFFERSIZE);
    if (!dyn_buff)
        return NULL;
    out = read(fd, dyn_buff, BUFFERSIZE);
    while (out > 0)
    {
        if (!rd)
        {
            rd = strdup(dyn_buff);
        }
        else
        {
            tem = ft_strjoin(rd, dyn_buff);
            free(rd);
            rd = tem;
        }
        if (ft_strchr(rd, '\n'))
            break;
        out = read(fd, dyn_buff, BUFFERSIZE);
    }
    if (out == 0 || out == -1)
    {
        free(dyn_buff);
        free(rd);
        return NULL;
    }
    free(dyn_buff);
    return (rd);
}

char *left_char(char *str)
{
    size_t i;
    char *dyn_point;
    size_t j;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    i++;
    if (str[i] == '\0')
        return NULL;
    dyn_point = (char *)malloc(sizeof(char) *(ft_strlen(str) - i));
    if (!dyn_point)
        return NULL;
    j = 0;
    while (str[i] != '\0')
        dyn_point[j++] = str[i++];
    dyn_point[j] = '\0';
    return(dyn_point);
    free(dyn_point);
}

char *get_next_line(int fd)
{
    static char *rd;
    char        *line;

    rd = read_line(fd, rd);
    if (!rd)
        return NULL;
    line = ft_read_line_end(rd);
    rd = left_char(rd);
    return (line);
}