/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:03:50 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/30 18:30:04 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_list	*ft_lst_new(char *str)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->str = str;
	return (res);
}

char	*get_match(char *str)
{
	if (equals(str, "ra\n"))
		return ("rb\n");
	if (equals(str, "rb\n"))
		return ("ra\n");
	if (equals(str, "rra\n"))
		return ("rrb\n");
	if (equals(str, "rrb\n"))
		return ("rra\n");
	if (equals(str, "sa\n"))
		return ("sb\n");
	if (equals(str, "sb\n"))
		return ("sa\n");
	return ("");
}

void	free_tlist(t_list **lst)
{
	t_list	*cpy;

	if (!lst)
		return ;
	while (*lst)
	{
		cpy = *lst;
		*lst = (*lst)->next;
		free(cpy);
	}
}

int	distance_to_match(t_list *list, char *to_match)
{
	int	dist;

	dist = 0;
	while (list)
	{
		if (equals(list->str, to_match))
			return (dist);
		list = list->next;
		dist++;
	}
	return (__INT_MAX__);
}

char	*get_merge(char *str)
{
	if (equals(str, "ra\n") || equals(str, "rb\n"))
		return ("rr\n");
	if (equals(str, "rra\n") || equals(str, "rrb\n"))
		return ("rrr\n");
	if (equals(str, "sa\n") || equals(str, "sb\n"))
		return ("ss\n");
	return (NULL);
}

t_list	*merge_instruction(t_piles *p)
{
	int		dist_a;
	int		dist_b;
	char	*match_a;
	char	*match_b;
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	dist_a = 0;
	dist_b = 0;
	tmp = p->buffer_a;
	while (p->buffer_a && p->buffer_a->next)
	{
		if (p->buffer_a->next)
		{
			if (equals(p->buffer_a->str, "rra\n") && equals(p->buffer_a->next->str, "ra\n"))
			{
				p->buffer_a->str = "";
				p->buffer_a->next->str = "";
			}
		}
		p->buffer_a = p->buffer_a->next;
	}
	p->buffer_a = tmp;
	while (p->buffer_a && p->buffer_a->next)
	{
		if (p->buffer_a->next)
		{
			if (equals(p->buffer_a->str, "ra\n") && equals(p->buffer_a->next->str, "rra\n"))
			{
				p->buffer_a->str = "";
				p->buffer_a->next->str = "";
			}
		}
		p->buffer_a = p->buffer_a->next;
	}
	p->buffer_a = tmp;
	tmp = p->buffer_b;
	while (p->buffer_b && p->buffer_b->next)
	{
		if (p->buffer_b->next)
		{
			if (equals(p->buffer_b->str, "rrb\n") && equals(p->buffer_b->next->str, "rb\n"))
			{
				p->buffer_b->str = "";
				p->buffer_b->next->str = "";
			}
		}
		p->buffer_b = p->buffer_b->next;
	}
	p->buffer_b = tmp;
	tmp = p->buffer_b;
	while (p->buffer_b && p->buffer_b->next)
	{
		if (p->buffer_b->next)
		{
			if (equals(p->buffer_b->str, "rb\n") && equals(p->buffer_b->next->str, "rrb\n"))
			{
				p->buffer_b->str = "";
				p->buffer_b->next->str = "";
			}
		}
		p->buffer_b = p->buffer_b->next;
	}
	p->buffer_b = tmp;
	while (p->buffer_a && p->buffer_b)
	{
		match_a = get_match(p->buffer_a->str);
		match_b = get_match(p->buffer_b->str);
		if (equals(match_a, p->buffer_b->str))
		{
			tmp = ft_lst_new(get_merge(match_a));
			if (!tmp)
				return (free_tlist(&res), NULL);
			ft_lstadd_back(&res, tmp);
			p->buffer_a = p->buffer_a->next;
			p->buffer_b = p->buffer_b->next;
		}
		else
		{
			dist_a = distance_to_match(p->buffer_b, match_a);
			dist_b = distance_to_match(p->buffer_a, match_b);
			if (dist_a > dist_b)
			{
				tmp = ft_lst_new(p->buffer_a->str);
				if (!tmp)
					return (free_tlist(&res), NULL);
				ft_lstadd_back(&res, tmp);
				p->buffer_a = p->buffer_a->next;
			}
			else
			{
				tmp = ft_lst_new(p->buffer_b->str);
				if (!tmp)
					return (free_tlist(&res), NULL);
				ft_lstadd_back(&res, tmp);
				p->buffer_b = p->buffer_b->next;
			}
		}
	}
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

void	add_instruction(t_piles *p, char *instruc)
{
	char	on_pile;
	t_list	*tmp;

	tmp = ft_lst_new(instruc);
	if (!tmp)
		return ;
	on_pile = instruc[ft_strlen(instruc) - 2];
	if (on_pile == 'a')
		ft_lstadd_back(&p->buffer_a, tmp);
	else
		ft_lstadd_back(&p->buffer_b, tmp);
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
