/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:13:02 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/31 18:21:32 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static char	*get_match(char *str)
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

static int	distance_to_match(t_list *list, char *to_match)
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

static void	*not_match(t_piles *p, t_list **res, char *match_a, char *match_b)
{
	int		dist_a;
	int		dist_b;
	t_list	*tmp;

	dist_a = distance_to_match(p->buffer_b, match_a);
	dist_b = distance_to_match(p->buffer_a, match_b);
	if (dist_a > dist_b)
	{
		tmp = ft_lst_new(p->buffer_a->str);
		if (!tmp)
			return (free_tlist(res), NULL);
		ft_lstadd_back(res, tmp);
		p->buffer_a = p->buffer_a->next;
	}
	else
	{
		tmp = ft_lst_new(p->buffer_b->str);
		if (!tmp)
			return (free_tlist(res), NULL);
		ft_lstadd_back(res, tmp);
		p->buffer_b = p->buffer_b->next;
	}
	return (tmp);
}

t_list	*merge_matches(t_piles *p)
{
	t_list	*res;
	t_list	*tmp;
	char	*match_a;
	char	*match_b;

	res = NULL;
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
			tmp = not_match(p, &res, match_a, match_b);
		if (!tmp)
			return (NULL);
	}
	return (res);
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
