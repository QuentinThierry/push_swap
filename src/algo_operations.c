/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2023/01/03 02:58:43 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

// find the position of the last greatest(a)/lowest(b) in stack
int	find_pos_of_last(t_piles *p, t_stack **src, int pivot_value, int size)
{
	int		i;
	int		j;
	t_stack	*it;

	i = 0;
	it = *src;
	j = 0;
	while (it != NULL && i < size)
	{
		if ((it->value < pivot_value && p->pa == src)
			|| (it->value >= pivot_value && p->pb == src))
			j = 0;
		else
			j++;
		it = it->next;
		if (it == *src)
			break ;
		i++;
	}
	return (size - j);
}

int	split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size)
{
	int	size_a;

	size_a = 0;
	if (src == p->pa)
		size_a = split_on_a(p, src, pivot, size);
	else
		size_a = split_on_b(p, src, pivot, size);
	return (size_a);
}

static void	under_3_elem(t_piles *p, t_stack **root, int nb_elem)
{
	if (nb_elem == 2)
		sort_at_2(p, root);
	else
	{
		if (list_count(root) == 3)
			special_sort_3(p, root);
		else
			nb_elem = sort_at_3(p, root);
	}
}

void	rec_algo(t_piles *p, t_stack **root, int nb_elem)
{
	t_stack	*pivot;
	int		size_a;
	int		size_b;

	if (root == p->pa && is_sorted(root, 0))
		return ;
	if (root == p->pb && is_sorted(root, 1))
	{
		while (nb_elem--)
			get_instruction("pa", p, 1);
		return ;
	}
	if (nb_elem <= 3)
	{
		under_3_elem(p, root, nb_elem);
		return ;
	}
	pivot = find_pivot(root, nb_elem, 0);
	size_a = split_stack_pivot(p, root, pivot, nb_elem);
	size_b = nb_elem - size_a;
	rec_algo(p, p->pa, size_a);
	rec_algo(p, p->pb, size_b);
}
