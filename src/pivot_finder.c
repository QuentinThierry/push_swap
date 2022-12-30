/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:47:16 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/30 18:31:19 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int	partition(int *tab, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (tab[j] <= pivot)
		{
			i++;
			int_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	int_swap(&tab[i + 1], &tab[right]);
	return (i + 1);
}

static void	quick_sort(int *tab, int left, int right)
{
	int	pos;

	if (left < right)
	{
		pos = partition(tab, left, right);
		quick_sort(tab, left, pos - 1);
		quick_sort(tab, pos + 1, right);
	}
}

static t_stack	*find_value(t_stack **root, int value)
{
	t_stack	*it;

	it = *root;
	while (it->value != value)
	{
		it = it->next;
		if (it == *root)
			break ;
	}
	return (it);
}

t_stack	*find_pivot(t_stack **root, int size, int is_first)
{
	int		*to_sort;
	int		i;
	int		position;
	t_stack	*it;

	to_sort = malloc(sizeof(int) * size);
	if (!to_sort)
		return (NULL);
	it = *root;
	i = 0;
	while (i < size)
	{
		to_sort[i] = it->value;
		it = it->next;
		i++;
	}
	quick_sort(to_sort, 0, size - 1);
	position = size / 2;
	if (is_first)
		position = size / 4;
	it = find_value(root, to_sort[position]);
	free(to_sort);
	return (it);
}
