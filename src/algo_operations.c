/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/31 18:33:37 by qthierry         ###   ########.fr       */
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

int	split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size, int *size_b)
{
	int	i;
	int	size_a;
	int	total;
	int	nb_rotate;
	int	virtual_size;
	int	first_pivot;
	int	is_first;

	i = 0;
	size_a = 0;
	nb_rotate = 0;
	is_first = list_count(p->pb) == 0;
	virtual_size = find_pos_of_last(p, src, pivot->value, size);
	total = list_count(src);
	if (is_first)
		first_pivot = find_pivot(src, size, 1)->value;
	if (src == p->pa) // si on split sur a
	{
		while (i++ < virtual_size)
		{
			if ((*src)->value < pivot->value)
			{
				get_instruction("pb", p, 1);
				if (is_first && (*p->pb)->value < first_pivot)
					get_instruction("rb", p, 1);
				(*size_b)++;
			}
			else
			{
				get_instruction("ra", p, 1);
				nb_rotate++;
			}
		}
		if (nb_rotate < total - i + 1)
		{
			while (nb_rotate--)
				get_instruction("rra", p, 1);
		}
		else
		{
			while (i++ < total + 1)
				get_instruction("ra", p, 1);
		}
		size_a = size - (*size_b);
	}
	else // si on split sur b
	{
		while (i++ < virtual_size)
		{
			if ((*src)->value >= pivot->value)
			{
				get_instruction("pa", p, 1);
				size_a++;
			}
			else
			{
				get_instruction("rb", p, 1);
				nb_rotate++;
			}
		}
		if (nb_rotate < total - i + 1)
		{
			while (nb_rotate--)
				get_instruction("rrb", p, 1);
		}
		else
		{
			while (i++ < total + 1)
				get_instruction("rb", p, 1);
		}
		*size_b = size - size_a;
	}
	return (size_a);
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
		if (nb_elem == 2)
			sort_at_2(p, root);
		else
		{
			if (list_count(root) == 3)
				special_sort_3(p, root);
			else
				nb_elem = sort_at_3(p, root);
		}
		return ;
	}
	size_b = 0;
	pivot = find_pivot(root, nb_elem, 0);
	size_a = split_stack_pivot(p, root, pivot, nb_elem, &size_b);
	rec_algo(p, p->pa, size_a);
	rec_algo(p, p->pb, size_b);
}
