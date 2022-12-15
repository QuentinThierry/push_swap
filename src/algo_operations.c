/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:47:16 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/15 18:46:39 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static t_stack	*find_closest(t_stack **root, int size, int val)
{
	t_stack	*it;
	t_stack	*tmp;
	long	min;
	int		i;
	int		test;

	i = 0;
	it = *root;
	min = it->value - val;
	if (min < 0)
		min *= -1;
	while (i < size)
	{
		test = it->value - val;
		if (test < 0)
			test *= -1;
		if (test < min)
		{
			min = val - it->value;
			tmp = it;
		}
		it = it->next;
		i++;
	}
	return (tmp);
}

t_stack	*find_average(t_stack **root, int size)
{
	int			i;
	long long	total;
	long long	average;
	t_stack		*it;
	t_stack		*tmp;

	if (!size)
		return (*root);
	i = 0;
	total = 0;
	it = *root;
	while (i < size)
	{
		total += it->value;
		it = it->next;
		i++;
	}
	average = total / size;
	printf("average : %lld\n", average);
	tmp = find_closest(root, size, average);
	printf("ICI AVERAGE : %d\n", tmp->value);
	return (it);
}
