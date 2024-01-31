#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
int		ft_strchr_i(const char *s, int c);
char	*ft_strldup(const char *s1, int i);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif