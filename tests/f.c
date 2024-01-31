#include "get_next_line_bonus.h"

char	*ft_gnljoin(char *s1[], char *s2)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	temp = str;
	if (!str)
		return (NULL);
	while ((*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	if (**s1)
		free(*s1);
	return (temp);
}

char	*check_prev(char *prev_str[], char **line)
{
	char	*copy;
	int		i;

	copy = "";
	i = ft_strchr_i(*prev_str, '\n');
	if (i >= 0)
	{
		*line = ft_strldup(*prev_str, i + 1);
		if (*(*prev_str + i + 1))
			copy = ft_strdup(*prev_str + i + 1);
		if (*prev_str[0])
			free(*prev_str);
		if (*copy && *copy != '\xff')
			*prev_str = ft_strdup(copy);
		else
			*prev_str = "";
		if (*copy)
			free(copy);
		return (*line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			r;
	static char	*prev_str[1024];
	char		*buff;
	char		*line;

	if (fd >= 0 && fd < 1024 && !prev_str[fd])
		prev_str[fd] = "";
	r = read(fd, buff = malloc(sizeof(char) * BUFFER_SIZE + 1), BUFFER_SIZE);
	while (r > 0)
	{
		buff[r] = 0;
		prev_str[fd] = ft_gnljoin(&prev_str[fd], buff);
		free(buff);
		if (check_prev(&prev_str[fd], &line))
			return (line);
		r = read(fd, buff = malloc(sizeof(char)
					* BUFFER_SIZE + 1), BUFFER_SIZE);
	}
	free(buff);
	if (fd >= 0 && fd < 1024 && prev_str[fd][0])
	{
		prev_str[fd] = ft_gnljoin(&prev_str[fd], "\xff");
		return (check_prev(&prev_str[fd], &line));
	}
	return (NULL);
}