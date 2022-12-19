/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/19 17:37:10 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

// consider only use pivot value and not t_stack
// return the number of elements send to the other stack
int	split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size)
{
	int		i;
	int		res;
	char	on_pile;
	char	on_pile2;

	on_pile = 'a';
	on_pile2 = 'b';
	if (src == p->pa)
	{
		on_pile = 'b';
		on_pile2 = 'a';
	}
	i = 0;
	res = 0;
	while (i++ < size)
	{
		if ((*src)->value < pivot->value)
		{
			get_instruction(mini_join("p", on_pile), p, 1);
			res++;
		}
		else
			get_instruction(mini_join("r", on_pile2), p, 1);
	}
	return (res);
}

static void	print_n_stack(t_stack **root, int n)
{
	t_stack	*it;
	int		i;

	it = *root;
	if (!it)
	{
		printf("EMPTY\n");
		return ;
	}
	i = 0;
	printf("n_stack : \n");
	while (i < n)
	{
		printf("%d\n", it->value);
		it = it->next;
		if (it == *root)
			break ;
		i++;
	}
	printf("::::\n");
}

static void	print_all(t_piles *p)
{
	printf("---------a---------\n");
	print_stack(p->pa);
	printf("---------b---------\n");
	print_stack(p->pb);
	printf("-------------------\n");

}

void	rec_algo(t_piles *p, t_stack **root, int nb_elem)
{
	t_stack	**new_root;
	t_stack	*pivot;

	print_all(p);
	if (nb_elem <= 3)
	{
		sort_at_3(p, root);
		print_n_stack(root, nb_elem);
		if (root == p->pb)
		{
			printf("ON B :)\n");
			get_instruction("pa", p, 1);
			get_instruction("pa", p, 1);
			get_instruction("pa", p, 1);
		}
		return ;
	}
	new_root = root;
	printf("deb : %d\n", nb_elem);

	printf("PIVOT\n");
	pivot = find_pivot(root, nb_elem);
	nb_elem = split_stack_pivot(p, root, pivot, nb_elem);

	print_all(p);
	//print_n_stack(root, nb_elem);
	printf("gauche\n");
	rec_algo(p, p->pa, nb_elem);
	print_all(p);
	printf("droite\n");
	rec_algo(p, p->pb, nb_elem);

	printf("fin : %d\n", nb_elem);
	print_all(p);

}