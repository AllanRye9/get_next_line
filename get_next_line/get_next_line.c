/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:33:14 by oallan            #+#    #+#             */
/*   Updated: 2024/01/07 19:33:17 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
static int is_new_line(l_line *load);
static void join_l_line(l_line *load, char **line);
static void read_l_line(l_line **load, int fd);
static void create_new_end_list(l_line **load);

char    *get_next_line(int fd)
{
    static l_line   *load = NULL;
    char            *line;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    read_l_line(&load, fd);
    if (!load)
        return (NULL);
    join_l_line(load, &line);
    create_new_end_list(&load);
    return (line);
}

static int is_new_line(l_line *load)
{
    int     i;

    load = ft_last_list(load);
    if (!load)
        return (0);
    i = 0;
    while (load->data[i] != '\0')
    {
        if (load->data[i] == '\n')
        {
            load->length = ++i;
            return (1);
        }
        i++;
    }
    load->length = i;
    return (0);
}

static void read_l_line(l_line **load, int fd)
{
    int     output;
    char    *buffer;
    l_line  *new_node;

    output = 0;
    buffer = NULL;
    while (!is_new_line(*load))
    {
        new_node = ft_new_list(buffer);
        new_node->data = ft_calloc(sizeof(*buffer) , (BUFFER_SIZE + 1));
        output = read(fd, new_node->data, BUFFER_SIZE);
        if (output == 0 || output == -1)
        {
            free(new_node->data);
            free(new_node);
            return ;
        }
    new_node->data[BUFFER_SIZE] = '\0';
    ft_listadd_back(load, new_node);
    }
}

static void join_l_line(l_line *load, char **line)
{
    l_line  *tem;
    int     total_length;
    int     i;

    tem = load;
    total_length = 0;
    while (tem)
    {
        total_length = total_length + tem->length;
        tem = tem->next;
    }
    if (!total_length)
        return ;
    *line = malloc(sizeof(**line) * (total_length + 1));
    if (!line)
        return ;
    total_length = 0;
    while (load && load->data)
    {
        i = 0;
        while (load->data[i] && load->length > i)
            (*line)[total_length++] = load->data[i++];
            load = load->next;
    }
    (*line)[total_length] = '\0';
}

static void create_new_end_list(l_line **load)
{
    l_line *tem;
    l_line  *new_node;
    char    *content;
    int     size;
    int     i;

    size = 0;
    tem = ft_last_list(*load);
    if (!tem)
        return ;
    content = tem->data;
    size    = tem->length;
    tem->data = NULL;
    ft_listclear(load, free);
    i = 0;
    if (content[size] != '\0')
    {
        while (content[size] != '\0')
            content[i++] = content[size++];
        content[i] = '\0';
        new_node = ft_new_list(content);
        ft_listadd_back(load, new_node);
    }
    else
        free(content);
}
