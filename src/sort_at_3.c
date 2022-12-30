/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_at_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:21:19 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/30 18:25:56 by qthierry         ###   ########.fr       */
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
	if (on_pile == 'b')
	{
		if (equals(order, "123"))
		{
			get_double_instruction("rb", "sb", p, 1);
			get_double_instruction("pa", "pa", p, 1);
			get_double_instruction("rrb", "pa", p, 1);
		}
		else
		{
			get_double_instruction("pa", "pa", p, 1);
			get_instruction("pa", p, 1);
		}
	}
	else
	{
		if (equals(order, "321"))
		{
			get_double_instruction("sa", "ra", p, 1);
			get_double_instruction("sa", "rra", p, 1);
			get_instruction("sa", p, 1);
		}
	}
}

static void	sort_132_312(t_piles *p, char *order, char on_pile)
{
	if (on_pile == 'b')
	{
		if (equals(order, "132"))
		{
			get_double_instruction("sb", "pa", p, 1);
			get_double_instruction("sb", "pa", p, 1);
			get_instruction("pa", p, 1);
		}
		else
		{
			get_double_instruction("pa", "sb", p, 1);
			get_double_instruction("pa", "pa", p, 1);
		}
		return ;
	}
	if (equals(order, "132"))
	{
		get_double_instruction("ra", "sa", p, 1);
		get_instruction("rra", p, 1);
	}
	else
	{
		get_double_instruction("sa", "ra", p, 1);
		get_double_instruction("sa", "rra", p, 1);
	}
}

static void	sort_213_231(t_piles *p, char *order, char on_pile)
{
	if (on_pile == 'b')
	{
		if (equals(order, "213"))
		{
			get_double_instruction("rb", "sb", p, 1);
			get_double_instruction("pa", "rrb", p, 1);
			get_double_instruction("pa", "pa", p, 1);
		}
		else
		{
			get_double_instruction("sb", "pa", p, 1);
			get_double_instruction("pa", "pa", p, 1);
		}
	}
	else
	{
		if (equals(order, "213"))
			get_instruction("sa", p, 1);
		else
		{
			get_double_instruction("ra", "sa", p, 1);
			get_double_instruction("rra", "sa", p, 1);
		}
	}
}

int	sort_at_3(t_piles *p, t_stack **root)
{
	char	on_pile;
	char	*order;
	int		nb_elem;

	if (root == p->pa)
		on_pile = 'a';
	else
		on_pile = 'b';
	order = find_order(root);
	nb_elem = 3;
	if (equals(order, "123") || equals(order, "321"))
		sort_123_321(p, order, on_pile);
	else if (equals(order, "132") || equals(order, "312"))
		sort_132_312(p, order, on_pile);
	else if (equals(order, "213") || equals(order, "231"))
		sort_213_231(p, order, on_pile);
	return (nb_elem);
}

//top-bot
//	a								| b

//123 ok							| rot, swap, pa, pa, rrot, pa
//132 rot, swap, rrot				| swap pa swap pa pa
//213 swap 							| rot, swap, pa, rrot, pa, pa
//231 rot, swap, rrot, swap			| swap, pa, pa, pa
//312 swap, rot, swap, rrot			| pa, swap, pa, pa
//321 swap, rot, swap, rrot, swap	| pa, pa, pa