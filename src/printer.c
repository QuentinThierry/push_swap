/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:03:50 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/31 18:20:58 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	remove_neutre_a(t_piles *p)
{
	t_list	*tmp;

	tmp = p->buffer_a;
	while (p->buffer_a && p->buffer_a->next)
	{
		if (p->buffer_a->next)
		{
			if ((equals(p->buffer_a->str, "rra\n")
					&& equals(p->buffer_a->next->str, "ra\n"))
				|| (equals(p->buffer_a->str, "ra\n")
					&& equals(p->buffer_a->next->str, "rra\n")))
			{
				p->buffer_a->str = "";
				p->buffer_a->next->str = "";
			}
		}
		p->buffer_a = p->buffer_a->next;
	}
	p->buffer_a = tmp;
}

static void	remove_neutre_b(t_piles *p)
{
	t_list	*tmp;

	tmp = p->buffer_a;
	while (p->buffer_a && p->buffer_a->next)
	{
		if (p->buffer_a->next)
		{
			if ((equals(p->buffer_a->str, "rrb\n")
					&& equals(p->buffer_a->next->str, "rb\n"))
				|| (equals(p->buffer_a->str, "rb\n")
					&& equals(p->buffer_a->next->str, "rrb\n")))
			{
				p->buffer_a->str = "";
				p->buffer_a->next->str = "";
			}
		}
		p->buffer_a = p->buffer_a->next;
	}
	p->buffer_a = tmp;
}

t_list	*merge_instruction(t_piles *p)
{
	t_list	*tmp;
	t_list	*res;

	remove_neutre_a(p);
	remove_neutre_b(p);
	res = merge_matches(p);
	while (p->buffer_a)
	{
		tmp = ft_lst_new(p->buffer_a->str);
		if (!tmp)
			return (free_tlist(&res), NULL);
		ft_lstadd_back(&res, tmp);
		p->buffer_a = p->buffer_a->next;
	}
	while (p->buffer_b)
	{
		tmp = ft_lst_new(p->buffer_b->str);
		if (!tmp)
			return (free_tlist(&res), NULL);
		ft_lstadd_back(&res, tmp);
		p->buffer_b = p->buffer_b->next;
	}
	return (res);
}

void	flush_instruction(t_piles *p)
{
	t_list	*cpy_a;
	t_list	*cpy_b;
	t_list	*to_print;

	cpy_a = p->buffer_a;
	cpy_b = p->buffer_b;
	to_print = merge_instruction(p);
	free_tlist(&cpy_a);
	free_tlist(&cpy_b);
	cpy_a = to_print;
	while (to_print)
	{
		write(1, to_print->str, ft_strlen(to_print->str));
		to_print = to_print->next;
	}
	free_tlist(&cpy_a);
	p->buffer_a = NULL;
	p->buffer_b = NULL;
}

void	send_instruction(t_piles *p, char *str)
{
	if (equals(str, "pa\n") || equals(str, "pb\n"))
	{
		flush_instruction(p);
		write(1, str, ft_strlen(str));
		return ;
	}
	add_instruction(p, str);
}
