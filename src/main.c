/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/16 16:43:38 by qthierry         ###   ########.fr       */
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

	int	testPetit[1000] = {0};
	int	testGrand[1000] = {0};
	int	i = 0;
	int	j = 0;

	init_stack(argc, (char **)argv, &p);
	p.pa_size = list_count(p.pa);

	printf("Pa : %d elements. \n", p.pa_size);
	print_all(&p);

	pivot = find_pivot(p.pa, p.pa_size);

	if (!*p.pa)
		return (0);
	it = *p.pa;
	while (it != NULL)
	{
		printf("%d < %d\n", it->value, pivot->value);

		if (it->value < pivot->value)
			testPetit[i++] = it->value;
		else if (it->value > pivot->value)
			testGrand[j++] = it->value;
		it = it->next;
		if (it == *p.pa)
			break ;
	}
	i = 0;
	while (i < 9)
	{
		printf("%d | %d\n", testPetit[i], testGrand[i]);
		i++;
	}
	free_stack(*p.pa);
	free_stack(*p.pb);
	free(p.pa);
	free(p.pb);
	return (0);
}
