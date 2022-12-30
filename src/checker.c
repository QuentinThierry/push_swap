/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:12:24 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/30 19:51:24 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int	on_descending(t_stack **root)
{
	t_stack	*it;

	it = *root;
	while (1)
	{
		it = it->next;
		if (it == *root)
			break ;
		if (it->prev->value > it->value)
			return (0);
	}
	return (1);
}

static int	on_ascending(t_stack **root)
{
	t_stack	*it;

	it = *root;
	while (1)
	{
		it = it->next;
		if (it == *root)
			break ;
		if (it->prev->value < it->value)
			return (0);
	}
	return (1);
}

int	is_sorted(t_stack **root, int is_descending)
{
	if (!root || !*root)
		return (0);
	if (!is_descending)
		return (on_descending(root));
	return (on_ascending(root));
}
