/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:59:40 by qthierry          #+#    #+#             */
/*   Updated: 2023/01/03 20:01:56 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/get_next_line.h"

static char	*get_as_static(char *str)
{
	if (equals(str, "sa\n"))
		return ("sa");
	if (equals(str, "sb\n"))
		return ("sb");
	if (equals(str, "ss\n"))
		return ("ss");
	if (equals(str, "ra\n"))
		return ("ra");
	if (equals(str, "rb\n"))
		return ("rb");
	if (equals(str, "rr\n"))
		return ("rr");
	if (equals(str, "rra\n"))
		return ("rra");
	if (equals(str, "rrb\n"))
		return ("rrb");
	if (equals(str, "rrr\n"))
		return ("rrr");
	if (equals(str, "pa\n"))
		return ("pa");
	if (equals(str, "pb\n"))
		return ("pb");
	return (NULL);
}

static t_list	*get_all_instructions(void)
{
	char	*gnl_res;
	char	*str;
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	gnl_res = get_next_line(0);
	while (gnl_res)
	{
		str = get_as_static(gnl_res);
		free(gnl_res);
		if (!str)
			return (write(1, "Error\n", 6), NULL);
		tmp = ft_lst_new(str);
		if (!tmp)
			return (free_tlist(&res), NULL);
		ft_lstadd_back(&res, tmp);
		gnl_res = get_next_line(0);
	}
	return (res);
}

int	main(int argc, char const **argv)
{
	t_piles	p;
	t_list	*instruc;
	t_list	*tmp;

	init_stack(argc, (char **)argv, &p);
	instruc = get_all_instructions();
	if (!instruc)
		return (1);
	tmp = instruc;
	while (tmp)
	{
		get_instruction(tmp->str, &p, 0);
		tmp = tmp->next;
	}
	free_tlist(&instruc);
	if (is_sorted(p.pa, 0) && !*p.pb)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(*p.pa);
	free_stack(*p.pb);
	free(p.pa);
	free(p.pb);
	return (EXIT_SUCCESS);
}
