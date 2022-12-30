/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:54:48 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/30 18:30:51 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static char	*find_order(t_stack **root)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = (*root)->value;
	v2 = (*root)->next->value;
	v3 = (*root)->next->next->value;
	if (v1 < v2 && v2 < v3)
		return ("123");
	if (v1 < v3 && v2 > v3 && v1 < v3)
		return ("132");
	if (v1 > v2 && v1 < v3 && v2 < v3)
		return ("213");
	if (v1 < v2 && v2 > v3 && v1 > v3)
		return ("231");
	if (v1 > v2 && v2 < v3 && v1 > v3)
		return ("312");
	if (v1 > v2 && v2 > v3)
		return ("321");
	return ("Error");
}

static void	sort_123_321(t_piles *p, char *order, char on_pile)
{
	if (on_pile == 'a')
	{
		if (equals(order, "321"))
			get_double_instruction("sa", "rra", p, 1);
	}
	else
	{
		if (equals(order, "123"))
			get_double_instruction("sb", "rrb", p, 1);
	}
}

static void	sort_132_312(t_piles *p, char *order, char on_pile)
{
	if (on_pile == 'a')
	{
		if (equals(order, "132"))
			get_double_instruction("sa", "ra", p, 1);
		else if (equals(order, "312"))
			get_instruction("ra", p, 1);
	}
	else
	{
		if (equals(order, "132"))
			get_instruction("rb", p, 1);
		else if (equals(order, "312"))
			get_double_instruction("sb", "rb", p, 1);
	}
}

static void	sort_213_231(t_piles *p, char *order, char on_pile)
{
	if (on_pile == 'a')
	{
		if (equals(order, "213"))
			get_instruction("sa", p, 1);
		else if (equals(order, "231"))
			get_instruction("rra", p, 1);
	}
	else
	{
		if (equals(order, "213"))
			get_instruction("rrb", p, 1);
		else if (equals(order, "231"))
			get_instruction("sb", p, 1);
	}
}

void	special_sort_3(t_piles *p, t_stack **root)
{
	char	on_pile;
	char	*order;

	if (root == p->pa)
		on_pile = 'a';
	else
		on_pile = 'b';
	order = find_order(root);
	if (equals(order, "123") || equals(order, "321"))
		sort_123_321(p, order, on_pile);
	else if (equals(order, "132") || equals(order, "312"))
		sort_132_312(p, order, on_pile);
	else if (equals(order, "213") || equals(order, "231"))
		sort_213_231(p, order, on_pile);
	if (on_pile == 'b')
	{
		get_double_instruction("pa", "pa", p, 1);
		get_instruction("pa", p, 1);
	}
}

//	top-bot

//		a			|	b

//123	ok			|	swap rrot
//132	swap rot	|	rot
//213	swap		|	rrot
//231	rrot		|	swap
//312	rot			|	swap rot
//321	swap rrot	|	ok
