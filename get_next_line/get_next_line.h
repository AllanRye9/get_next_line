/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:32:49 by oallan            #+#    #+#             */
/*   Updated: 2024/01/07 19:32:51 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10240
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_line
{
    char            *data;
    int             length;
    struct s_line   *next;
}                   l_line;

char    *get_next_line(int fd);

l_line	*ft_new_list(char *content);

l_line	*ft_last_list(l_line *last);

void	ft_listadd_back(l_line **list, l_line *new_item);

void	ft_listclear(l_line **list, void (*del)(void *));

void    *ft_calloc(size_t count, size_t size);
#endif