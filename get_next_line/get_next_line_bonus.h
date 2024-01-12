/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:10:16 by oallan            #+#    #+#             */
/*   Updated: 2024/01/11 20:10:19 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_line
{
	char			*data;
	int				length;
	struct s_line	*next;
}					t_line;

char	*get_next_line(int fd);

t_line	*ft_new_list(char *content);

t_line	*ft_last_list(t_line *last);

void	ft_listadd_back(t_line **list, t_line *new_item);

void	ft_listclear(t_line **list, void (*del)(void *));

void	*ft_calloc(size_t count, size_t size);
#endif
