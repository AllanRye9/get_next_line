/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:32:07 by oallan            #+#    #+#             */
/*   Updated: 2024/01/12 17:18:33 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_line	*ft_new_list(char *content)
{
	t_line	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->length = 0;
	new_node->next = NULL;
	return (new_node);
}

t_line	*ft_last_list(t_line *last)
{
	if (!last)
		return (NULL);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void	ft_listadd_back(t_line **list, t_line *new)
{
	t_line	*temp;

	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	temp = ft_last_list(*list);
	temp->next = new;
}

void	ft_listclear(t_line **list, void (*del)(void *))
{
	t_line	*temp_lst;

	if (!list || !del)
		return ;
	while (*list != NULL)
	{
		temp_lst = *list;
		*list = (*list)->next;
		free(temp_lst->data);
		free(temp_lst);
	}
	*list = NULL;
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*array;
	size_t			total_size;
	size_t			i;
	unsigned char	*value;

	total_size = count * size;
	if (!total_size || total_size / count != size)
		return (NULL);
	array = malloc(total_size);
	if (array == NULL)
		return (NULL);
	i = 0;
	value = array;
	while (total_size > i)
	{
		value[i] = '\0';
		i++;
	}
	return (value);
}
