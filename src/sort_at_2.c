/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_at_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:22:10 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/30 18:25:27 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	sort_at_2(t_piles *p, t_stack **root)
{
	if (*root == (*root)->next)
		return ;
	if (root == p->pa && (*root)->value > (*root)->next->value)
		get_instruction("sa", p, 1);
	else if (root == p->pb && (*root)->value < (*root)->next->value)
		get_instruction("sb", p, 1);
	if (root == p->pb)
	{
		get_instruction("pa", p, 1);
		get_instruction("pa", p, 1);
	}
}

//	top-bot
//		a		|	b
// 21	swap	|	pa pa
// 12	ok		|	swap pa pa