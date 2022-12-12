/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:10:02 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 23:39:39 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	append_string(t_buf_list *list, char **res)
{
	char	*tmp;

	while (list)
	{
		tmp = ft_strchr(list->string, '\n');
		if (tmp)
		{
			ft_memmove((*res), list->string, (tmp - list->string) + 1);
			(*res)[(tmp - list->string) + 1] = 0;
			return (1);
		}
		ft_memmove((*res), list->string, list->length);
		(*res) += list->length;
		list = list->next;
	}
	return (0);
}

static char	*list_to_str(t_buf_list *list)
{
	char		*res;
	char		*cpy;
	size_t		m_size;
	t_buf_list	*start;

	res = NULL;
	if (!list)
		return (NULL);
	m_size = 0;
	start = list;
	while (start)
	{
		m_size += start->length;
		start = start->next;
	}
	res = malloc(sizeof(char) * (m_size + 1));
	if (!res)
		return (NULL);
	cpy = res;
	if (!append_string(list, &res))
		cpy[m_size] = 0;
	return (cpy);
}

static int	get_a_line(int fd, t_buf_list **list, char *buffer)
{
	ssize_t	read_size;
	int		ready;

	ready = 1;
	if (*list)
	{
		read_size = (*list)->length;
		copy_array(&buffer, &(*list)->string, (*list)->length);
		ready = 0;
	}
	else
		read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = 0;
		if (ready)
			if (!lst_add_back(list, buffer, read_size))
				return (gnl_free_list(list), -1);
		if (ft_strchr(buffer, '\n'))
			return (1);
		read_size = read(fd, buffer, BUFFER_SIZE);
		ready = 1;
	}
	return (0);
}

static void	get_new_buffer(t_buf_list **list, int is_end)
{
	t_buf_list	*tmp;
	size_t		size;
	char		*new_line;

	while ((*list)->next)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	new_line = ft_strchr((*list)->string, '\n');
	if (new_line)
	{
		size = new_line - (*list)->string + 1;
		ft_memmove((*list)->string, \
			(*list)->string + size, (*list)->length - size + 1);
		(*list)->length -= size;
	}
	if (is_end || (*list)->length == 0)
	{
		free(*list);
		*list = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_buf_list	*res_list = NULL;
	char				*res;
	int					is_end;
	char				*buffer;

	if (BUFFER_SIZE == 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (gnl_free_list(&res_list), NULL);
	is_end = get_a_line(fd, &res_list, buffer);
	free(buffer);
	if (is_end == -1)
		return (NULL);
	res = list_to_str(res_list);
	if (!res)
		return (gnl_free_list(&res_list), NULL);
	get_new_buffer(&res_list, !is_end);
	return (res);
}
