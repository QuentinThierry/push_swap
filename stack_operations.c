/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:23:24 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 19:24:58 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
	// *at_elem = tmp;
}

void	list_addtop(t_stack **root, t_stack *added)
{
	t_stack	*tmp;

	tmp = (*root)->prev;
	(*root)->prev = added;
	added->next = *root;
	added->prev = tmp;
	tmp->next = added;
	*root = added;
}

t_stack	*list_delfirst(t_stack **root)
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
