/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:58:54 by qthierry          #+#    #+#             */
/*   Updated: 2023/01/03 02:59:30 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	rotate_send_b(t_piles *p, t_stack **root, t_stack *pivot, int size)
{
	int	i;
	int	virtual_size;
	int	nb_rotate;

	i = 0;
	nb_rotate = 0;
	virtual_size = find_pos_of_last(p, root, pivot->value, size);
	while (i++ < virtual_size)
	{
		if ((*root)->value >= pivot->value)
			get_instruction("pa", p, 1);
		else
		{
			get_instruction("rb", p, 1);
			nb_rotate++;
		}
	}
	return (nb_rotate);
}

int	split_on_b(t_piles *p, t_stack **root, t_stack *pivot, int size)
{
	int	virtual_size;
	int	nb_rotate;
	int	size_a;
	int	total;
	int	i;

	i = 0;
	size_a = 0;
	total = list_count(root);
	virtual_size = find_pos_of_last(p, root, pivot->value, size);
	nb_rotate = rotate_send_b(p, root, pivot, size);
	i = virtual_size + 1;
	size_a = virtual_size - nb_rotate;
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
	return (size_a);
}
