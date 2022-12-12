/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:12:24 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/13 00:22:38 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	is_sorted(t_stack **root)
{
	t_stack	*it;

	if (!root || !*root)
		return (0);
	it = *root;
	while (1)
	{
		it = it->next;
		if (it == *root)
			break;
		if (it->prev->value > it->value)
			return (0);
	}
	return (1);
}
