/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_at_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:22:10 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/22 18:03:32 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	sort_at_2(t_piles *p, t_stack **root)
{

	// printf("Sort at 2\n");
	if (*root == (*root)->next)
		return ;
	if (root == p->pa && (*root)->value > (*root)->next->value)
		get_instruction("sa", p, 1);
	else if (root != p->pa && (*root)->value < (*root)->next->value)
		get_instruction("sb", p, 1);
}

//	top-bot
//		a		|	b
// 21	swap	|	ok
// 12	ok		|	swap