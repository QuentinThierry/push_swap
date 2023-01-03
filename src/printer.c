/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:03:50 by qthierry          #+#    #+#             */
/*   Updated: 2023/01/03 17:00:55 by qthierry         ###   ########.fr       */
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

void	append_instruction(t_piles *p)
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
	ft_lstadd_back(&p->instruc, to_print);
	p->buffer_a = NULL;
	p->buffer_b = NULL;
}

void	send_instruction(t_piles *p, char *str)
{
	t_list	*tmp;

	if (equals(str, "pa\n") || equals(str, "pb\n"))
	{
		append_instruction(p);
		tmp = ft_lst_new(str);
		if (!tmp)
			return ;
		ft_lstadd_back(&p->instruc, tmp);
		return ;
	}
	add_instruction(p, str);
}
