/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/27 19:26:19 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

// static void	print_all(t_piles *p)
// {
// 	printf("---------a---------\n");
// 	print_stack(p->pa);
// 	printf("---------b---------\n");
// 	print_stack(p->pb);
// 	printf("-------------------\n");
// }

int	main(int argc, char const **argv)
{
	t_piles	p;

	init_stack(argc, (char **)argv, &p);
	p.pa_size = list_count(p.pa);
	p.buffer = NULL;
	p.buffer_a = NULL;
	p.buffer_b = NULL;
	rec_algo(&p, p.pa, p.pa_size);
	if (!*p.pa)
		return (0);
	// printf("final flush\n");
	flush_instruction(&p);
	// print_all(&p);
	free_stack(*p.pa);
	free_stack(*p.pb);
	free(p.pa);
	free(p.pb);
	return (0);
}
