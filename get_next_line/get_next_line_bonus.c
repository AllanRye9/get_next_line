#include "get_next_line_bonus.h"

static char	*read_lines(char *value, int fd)
{
	char			*buf;
	
	while (fd > 0)
	{
		buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
		fd = read(fd, buf, BUFFER_SIZE);
		if (fd < 0)
		{
			free (buf);
			return (NULL);
		}
		if (fd == 0)
		{
			free(buf);
			break ;
		}
		buf[fd] = '\0';
		value = ft_strjoin(value, buf);
		free(buf);
		if (ft_strchr(value))
			break ;
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
		free(value);
		return (NULL);
	}
	free(value);
	return (ptr);
}

static char	*get_lines(char *value)
{
	int			i;
	int			len;

	i = 0;
	len = (int) ft_strlen(value);
	while (value[i] && value[i] != '\n')
		i++;
	if (value[i] == '\0')
	{
		free(value);
		return (NULL);
	}
	else if (value[i] == '\n')
		i++;
	len = (len - i )+ 1;
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
	static char		*value[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	value[fd] = read_lines(value[fd], fd);
	if (!value[fd])
		return (NULL);
	line = copy_lines(value[fd]);
	value[fd] = get_lines(value[fd]);
	return (line);
}