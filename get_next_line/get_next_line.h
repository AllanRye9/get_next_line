#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 1024

size_t ft_strlen(const char *s);
char *ft_strchr(char *s, char c);
char *ft_strdup(char *str);
char *ft_strjoin(char *s, char *s1);
char *ft_substr(char const *s, size_t start, size_t len);
char *get_next_line(int fd);
#endif