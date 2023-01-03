/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:57:22 by qthierry          #+#    #+#             */
/*   Updated: 2023/01/03 02:59:32 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	rotate_send_a(t_piles *p, t_stack **root, t_stack *pivot, int size)
{
	int	nb_rotate;
	int	first_pivot;
	int	virtual_size;
	int	is_first;

	is_first = list_count(p->pb) == 0;
	virtual_size = find_pos_of_last(p, root, pivot->value, size);
	nb_rotate = virtual_size;
	if (is_first)
		first_pivot = find_pivot(root, size, 1)->value;
	while (virtual_size--)
	{
		if ((*root)->value < pivot->value)
		{
			get_instruction("pb", p, 1);
			if (is_first && (*p->pb)->value < first_pivot)
				get_instruction("rb", p, 1);
			nb_rotate--;
		}
		else
			get_instruction("ra", p, 1);
	}
	return (nb_rotate);
}

void	reset_position(t_piles *p, int nb_rotate, int virtual_size, int total)
{
	if (nb_rotate < total - virtual_size + 1)
	{
		while (nb_rotate--)
			get_instruction("rra", p, 1);
	}
	else
	{
		while (virtual_size++ < total + 1)
			get_instruction("ra", p, 1);
	}
}

int	split_on_a(t_piles *p, t_stack **root, t_stack *pivot, int size)
{
	int	virtual_size;
	int	nb_rotate;
	int	total;

	total = list_count(root);
	virtual_size = find_pos_of_last(p, root, pivot->value, size);
	nb_rotate = rotate_send_a(p, root, pivot, size);
	reset_position(p, nb_rotate, virtual_size + 1, total);
	return (size - (virtual_size - nb_rotate));
}
