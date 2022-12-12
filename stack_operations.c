/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:23:24 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 02:24:49 by qthierry         ###   ########.fr       */
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

void	list_insert(t_stack **at_elem, t_stack *added)
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
