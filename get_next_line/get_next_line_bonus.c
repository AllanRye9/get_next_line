#include "get_next_line_bonus.h"

static char	*read_lines(char *value, int fd)
{
	char			*buf;
	int				out_p;
	
	while (fd > 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE);
		out_p = read(fd, buf, BUFFER_SIZE);
		if (out_p < 0)
		{
			free (buf);
			return (NULL);
		}
		if (out_p == 0)
		{
			free(buf);
			break ;
		}
		buf[out_p] = '\0';
		value = ft_strjoin(value, buf);
		if (ft_strchr(value))
			break ;
		free(buf);
	}
	return (value);
}

static char	*return_lines(char *value, int len, int i)
{
	int			j;
	char		*ptr;

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < len)
		ptr[j++] = value[i++];
	ptr[j] = '\0';
	if (ptr[0] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

static char	*get_lines(char *value)
{
	int			i;
	int			len;

	len = (int)ft_strlen(value);
	i = 0;
	while (value[i] && value[i] != '\n')
		i++;
	if (value[i] == '\0')
	{
		free(value);
		return (NULL);
	}
	if (value[i] == '\n')
		i++;
	len = ((len - i ) + 1);
	return (return_lines(value, len, i));
}

static char	*copy_lines(char *value)
{
	int		i;
	char	*ptr;
	int		j;

	i = 0;
	while (value[i] && value[i] != '\n')
		i++;
	if (value[i] == '\n')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ptr[j] = value[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*value[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	value[fd] = read_lines(value[fd], fd);
	if (!value[fd])
		return NULL;
	line = copy_lines(value[fd]);
	value[fd] = get_lines(value[fd]);
	return (line);
}