/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:47:16 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/15 02:02:56 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_stack	*find_median(t_stack **root, int size)
{
	int	i;
	t_stack	*it;

	if (!size)
		return (*root);
	i = 0;
	size /= 2;
	it = *root;
	while (i < size)
	{
		it = it->next;
		i++;
	}
	return (it);
}
