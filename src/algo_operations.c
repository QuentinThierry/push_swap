/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/16 23:17:23 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

// consider only use pivot value and not t_stack
void	split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot)
{
	int		size;
	int		i;
	char	on_pile;
	char	on_pile2;

	size = list_count(src);
	on_pile = 'a';
	on_pile2 = 'b';
	if (src == p->pa)
	{
		on_pile = 'b';
		on_pile2 = 'a';
	}
	i = 0;
	while (i++ < size)
	{
		if ((*src)->value < pivot->value)
			get_instruction(mini_join("p", on_pile), p, 1);
		else
			get_instruction(mini_join("r", on_pile2), p, 1);
	}
}
