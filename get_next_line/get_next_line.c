/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:59:11 by oallan            #+#    #+#             */
/*   Updated: 2024/01/30 16:59:28 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*next_line(char *str)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	p = malloc(sizeof(char) * ft_strlen(str) - i);
	i++;
	j = 0;
	while (str[i])
		p[j++] = str[i++];
	p[j] = '\0';
	free (str);
	return (p);
}

int	ft_error(ssize_t out_p, char *buff, char *ptr)
{
	if (out_p < 0)
	{
		free(buff);
		if (ptr != NULL)
			free(ptr);
		return (1);
	}
	else if (!ptr && out_p == 0)
	{
		free(buff);
		return (1);
	}
	else if (ptr[0] == '\0')
	{
		free(ptr);
		free(buff);
		return (1);
	}
	free (buff);
	return (0);
}

char	*read_line(int fd, char *str)
{
	char	*buff;
	char	*t;
	ssize_t	out_p;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	out_p = read(fd, buff, BUFFER_SIZE);
	while (out_p > 0)
	{
		buff[out_p] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
		{
			t = ft_strjoin(str, buff);
			free (str);
			str = t;
		}
		if (ft_strchr(str, '\n'))
			break ;
		out_p = read(fd, buff, BUFFER_SIZE);
	}
	if (ft_error(out_p, buff, str))
		return (0);
	return (str);
}

char	*copy_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = ft_substr(str, 0, i + 1);
	else
		line = ft_substr(str, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;

	ptr = read_line(fd, ptr);
	if (!ptr)
		return (NULL);
	line = copy_line(ptr);
	ptr = next_line(ptr);
	return (line);
}
