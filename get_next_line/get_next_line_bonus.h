#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str);
char    *get_next_line(int fd);
#endif