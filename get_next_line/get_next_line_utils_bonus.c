/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:03:00 by oallan            #+#    #+#             */
/*   Updated: 2024/01/30 17:03:14 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc((sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!p)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(const	char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_s;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	else if (len > ft_strlen(s))
		sub_s = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		sub_s[i++] = s[start++];
	sub_s[i] = '\0';
	return (sub_s);
}
