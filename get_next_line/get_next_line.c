#include "get_next_line.h"

static char	*read_lines(char *value, int fd)
{
	int				rd;
	char			*buf;

	rd = 1;
	while (rd > 0)
	{
		buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free (buf);
			return (NULL);
		}
		if (rd == 0)
		{
			free(buf);
			break ;
		}
		buf[rd] = '\0';
		value = ft_strjoin(value, buf);
		free(buf);
		if (ft_strchr(value) != NULL)
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
	static char		*value;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	value = read_lines(value, fd);
	if (!value)
		return (NULL);
	line = copy_lines(value);
	value = get_lines(value);
	return (line);
}