/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:02:30 by qthierry          #+#    #+#             */
/*   Updated: 2023/01/03 18:04:17 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static char	*get_neutre(char *str)
{
	if (equals(str, "ra\n"))
		return ("rra\n");
	if (equals(str, "rb\n"))
		return ("rrb\n");
	if (equals(str, "rra\n"))
		return ("ra\n");
	if (equals(str, "rrb\n"))
		return ("rb\n");
	if (equals(str, "sa\n"))
		return ("sb\n");
	if (equals(str, "sb\n"))
		return ("sa\n");
	if (equals(str, "pb\n"))
		return ("pa\n");
	if (equals(str, "pa\n"))
		return ("pb\n");
	return ("");
}

t_list	*merge_pa_pb(t_list *list, t_list *previous, t_list **instruc)
{
	if (!list->next)
		return (NULL);
	if (list == previous)
	{
		if (equals(list->str, get_neutre(list->next->str)))
		{
			previous = list->next->next;
			list->str = "";
			list->next->str = "";
			*instruc = previous;
			return (previous);
		}
		return (list->next);
	}
	if (equals(list->str, get_neutre(list->next->str)))
	{
		previous->next = list->next->next;
		free(list->next);
		free(list);
		list = previous;
		return (list);
	}
	return (list->next);
}

static t_list	*find_previous(t_list *root, t_list *to_find)
{
	t_list	*previous;

	previous = root;
	while (root)
	{
		if (root == to_find)
			return (previous);
		previous = root;
		root = root->next;
	}
	return (NULL);
}

void	final_merge(t_list **instruc)
{
	t_list	*tmp;
	t_list	*previous;

	tmp = *instruc;
	previous = tmp;
	while (tmp)
	{
		tmp = merge_pa_pb(tmp, previous, instruc);
		previous = find_previous(*instruc, tmp);
	}
}
