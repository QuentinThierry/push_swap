/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/16 18:45:14 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	print_all(t_piles *p)
{
	printf("---------a---------\n");
	print_stack(p->pa);
	printf("---------b---------\n");
	print_stack(p->pb);
}

int	main(int argc, char const **argv)
{
	t_piles	p;
	t_stack	*pivot;
	t_stack	*it;

	int	i = 0;
	int	j = 0;

	init_stack(argc, (char **)argv, &p);
	p.pa_size = list_count(p.pa);

	printf("Pa : %d elements. \n", p.pa_size);
	print_all(&p);

	pivot = find_pivot(p.pa, p.pa_size);
	split_stack_pivot(p.pb, p.pa, pivot);
	if (!*p.pa)
		return (0);
	it = *p.pa;
	i = 0;

	print_all(&p);

	free_stack(*p.pa);
	free_stack(*p.pb);
	free(p.pa);
	free(p.pb);
	return (0);
}
