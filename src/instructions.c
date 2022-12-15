/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:05:06 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/15 01:51:40 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int	swap_op(char *str, t_piles *p, int show)
{
	if (equals(str, "sa"))
	{
		if (show)
			write(1, "sa\n", 3);
		swap(p->pa);
		return (1);
	}
	else if (equals(str, "sb"))
	{
		if (show)
			write(1, "sb\n", 3);
		swap(p->pb);
		return (1);
	}
	else if (equals(str, "ss"))
	{
		if (show)
			write(1, "ss\n", 3);
		swap(p->pa);
		swap(p->pb);
		return (1);
	}
	return (0);
}

static int	push_op(char *str, t_piles *p, int show)
{
	if (equals(str, "pa"))
	{
		if (show)
			write(1, "pa\n", 3);
		push(p->pa, p->pb);
		return (1);
	}
	else if (equals(str, "pb"))
	{
		if (show)
			write(1, "pb\n", 3);
		push(p->pb, p->pa);
		return (1);
	}
	return (0);
}

static int	rotate_op(char *str, t_piles *p, int show)
{
	if (equals(str, "ra"))
	{
		if (show)
			write(1, "ra\n", 3);
		rotate(p->pa);
		return (1);
	}
	else if (equals(str, "rb"))
	{
		if (show)
			write(1, "rb\n", 3);
		rotate(p->pb);
		return (1);
	}
	else if (equals(str, "rr"))
	{
		if (show)
			write(1, "rr\n", 3);
		rotate(p->pa);
		rotate(p->pb);
		return (1);
	}
	return (0);
}

static int	rrotate_op(char *str, t_piles *p, int show)
{
	if (equals(str, "rra"))
	{
		if (show)
			write(1, "rra\n", 4);
		rrotate(p->pa);
		return (1);
	}
	else if (equals(str, "rrb"))
	{
		if (show)
			write(1, "rrb\n", 4);
		rrotate(p->pb);
		return (1);
	}
	else if (equals(str, "rrr"))
	{
		if (show)
			write(1, "rrr\n", 4);
		rrotate(p->pa);
		rrotate(p->pb);
		return (1);
	}
	return (0);
}

void	get_instruction(char *str, t_piles *p, int show)
{
	if (swap_op(str, p, show))
		return ;
	if (push_op(str, p, show))
		return ;
	if (rotate_op(str, p, show))
		return ;
	rrotate_op(str, p, show);
}
