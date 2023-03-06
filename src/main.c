/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2023/03/06 18:38:02 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	main(int argc, char const **argv)
{
	t_piles	p;
	t_list	*tmp;

	init_stack(argc, (char **)argv, &p);
	p.pa_size = list_count(p.pa);
	p.instruc = NULL;
	p.buffer_a = NULL;
	p.buffer_b = NULL;
	rec_algo(&p, p.pa, p.pa_size);
	if (!*p.pa)
		return (0);
	append_instruction(&p);
	final_merge(&p.instruc);
	tmp = p.instruc;
	while (tmp)
	{
		write(1, tmp->str, ft_strlen(tmp->str));
		tmp = tmp->next;
	}
	free_tlist(&p.instruc);
	free_stack(*p.pa);
	free_stack(*p.pb);
	free(p.pa);
	free(p.pb);
	return (0);
}
