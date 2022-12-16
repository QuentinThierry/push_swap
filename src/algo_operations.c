/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/16 18:58:17 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	push_to_a()
{
	
}

static void	push_to_a()
{
	
}

// consider only use pivot value and not t_stack
void	split_stack_pivot(t_stack **dest, t_stack **src, t_stack *pivot)
{
	t_stack	*start;

	start = *src;
	while (start != NULL)
	{
		if ((*src)->value > pivot->value)	// push on other
			push(dest, src);
		else
			rotate(src);
		if (start == *src)
			break ;
	}
}
