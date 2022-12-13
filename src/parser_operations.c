/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:05:06 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/13 19:00:17 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static int	swap_op(char *string, t_stack **root_a, t_stack **root_b)
{
	if (equals(string, "sa"))
	{
		write(1, "sa\n", 3);
		swap(root_a);
		return (1);
	}
	else if (equals(string, "sb"))
	{
		write(1, "sb\n", 3);
		swap(root_b);
		return (1);
	}
	else if (equals(string, "ss"))
	{
		write(1, "ss\n", 3);
		swap(root_a);
		swap(root_b);
		return (1);
	}
	return (0);
}

static int	push_op(char *string, t_stack **root_a, t_stack **root_b)
{
	if (equals(string, "pa"))
	{
		write(1, "pa\n", 3);
		push(root_a, root_b);
		return (1);
	}
	else if (equals(string, "pb"))
	{
		write(1, "pb\n", 3);
		push(root_b, root_a);
		return (1);
	}
	return (0);
}

static int	rotate_op(char *string, t_stack **root_a, t_stack **root_b)
{
	if (equals(string, "ra"))
	{
		write(1, "ra\n", 3);
		rotate(root_a);
		return (1);
	}
	else if (equals(string, "rb"))
	{
		write(1, "rb\n", 3);
		rotate(root_b);
		return (1);
	}
	else if (equals(string, "rr"))
	{
		write(1, "rr\n", 3);
		rotate(root_a);
		rotate(root_b);
		return (1);
	}
	return (0);
}

static int	rrotate_op(char *string, t_stack **root_a, t_stack **root_b)
{
	if (equals(string, "rra"))
	{
		write(1, "rra\n", 4);
		rrotate(root_a);
		return (1);
	}
	else if (equals(string, "rrb"))
	{
		write(1, "rrb\n", 4);
		rrotate(root_b);
		return (1);
	}
	else if (equals(string, "rrr"))
	{
		write(1, "rrr\n", 4);
		rrotate(root_a);
		rrotate(root_b);
		return (1);
	}
	return (0);
}

void	get_instruction(char *string, t_stack **root_a, t_stack **root_b)
{
	if (swap_op(string, root_a, root_b))
		return ;
	if (push_op(string, root_a, root_b))
		return ;
	if (rotate_op(string, root_a, root_b))
		return ;
	rrotate_op(string, root_a, root_b);
}