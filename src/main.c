/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/25 21:16:08 by qthierry         ###   ########.fr       */
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
	rec_algo(&p, p.pa, p.pa_size);
	if (!*p.pa)
		return (0);
	if (p.buffer)
		write(1, p.buffer, ft_strlen(p.buffer));
	free_stack(*p.pa);
	free_stack(*p.pb);
	free(p.pa);
	free(p.pb);
	return (0);
}
