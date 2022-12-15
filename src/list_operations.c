/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:23:24 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/15 02:14:47 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_stack	*list_new(int value)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->value = value;
	res->next = res;
	res->prev = res;
	return (res);
}

void	list_insert_after(t_stack **at_elem, t_stack *added)
{
	t_stack	*tmp;

	if (!*at_elem)
	{
		*at_elem = added;
		return ;
	}
	tmp = (*at_elem)->next;
	(*at_elem)->next = added;
	added->prev = *at_elem;
	added->next = tmp;
	tmp->prev = added;
}

void	list_insert_before(t_stack **at_elem, t_stack *added)
{
	t_stack	*tmp;

	if (!*at_elem)
	{
		*at_elem = added;
		return ;
	}
	tmp = (*at_elem)->prev;
	(*at_elem)->prev = added;
	added->next = *at_elem;
	added->prev = tmp;
	tmp->next = added;
}

void	list_push(t_stack **root, t_stack *added)
{
	t_stack	*tmp;

	if (!*root)
	{
		added->prev = added;
		added->next = added;
		*root = added;
		return ;
	}
	tmp = (*root)->prev;
	(*root)->prev = added;
	added->next = *root;
	added->prev = tmp;
	tmp->next = added;
	*root = added;
}

t_stack	*list_pop(t_stack **root)
{
	t_stack	*tmp;
	t_stack	*previous;
	t_stack	*next;

	tmp = *root;
	previous = (*root)->prev;
	next = (*root)->next;
	previous->next = next;
	next->prev = previous;
	*root = next;
	return (tmp);
}
