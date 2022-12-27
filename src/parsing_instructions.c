/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:05:06 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/27 19:18:58 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int	swap_op(char *str, t_piles *p, int show)
{
	if (equals(str, "sa"))
	{
		if (show)
			send_instruction(p, "sa\n");
		swap(p->pa);
		return (1);
	}
	else if (equals(str, "sb"))
	{
		if (show)
			send_instruction(p, "sb\n");
		swap(p->pb);
		return (1);
	}
	else if (equals(str, "ss"))
	{
		if (show)
			send_instruction(p, "ss\n");
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
			send_instruction(p, "pa\n");
		push(p->pa, p->pb);
		return (1);
	}
	else if (equals(str, "pb"))
	{
		if (show)
			send_instruction(p, "pb\n");
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
			send_instruction(p, "ra\n");
		rotate(p->pa);
		return (1);
	}
	else if (equals(str, "rb"))
	{
		if (show)
			send_instruction(p, "rb\n");
		rotate(p->pb);
		return (1);
	}
	else if (equals(str, "rr"))
	{
		if (show)
			send_instruction(p, "rr\n");
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
			send_instruction(p, "rra\n");
		rrotate(p->pa);
		return (1);
	}
	else if (equals(str, "rrb"))
	{
		if (show)
			send_instruction(p, "rrb\n");
		rrotate(p->pb);
		return (1);
	}
	else if (equals(str, "rrr"))
	{
		if (show)
			send_instruction(p, "rrr\n");
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
