/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/20 19:18:34 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

// consider only use pivot value and not t_stack
// return the number of elements send to the other stack
int	split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size, int *size_b)
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
	(*size_b) = res;
	size = size - res;
	if (on_pile == 'a')
		int_swap(&(*size_b), &size);
	return (size);
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
	int	cmp;
	int	i;
	int	size_first;
	int	size_second;

	cmp = 0;
	print_all(p);
	if (nb_elem <= 3)
	{
		if (nb_elem == 3)
			sort_at_3(p, root);
		else
			sort_at_2(p, root);
		print_n_stack(root, nb_elem);
		if (root == p->pb)
		{
			while (nb_elem--)
				get_instruction("pa", p, 1);
		}
		else
		{
			if (list_count(p->pa) > 3)
			{
				while (nb_elem--)
					get_instruction("pb", p, 1);
			}
		}
		printf("fin nb <= 3\n");
		return ;
	}
	new_root = root;
	printf("deb : %d\n", nb_elem);

	printf("PIVOT\n");
	size_second = 0;
	pivot = find_pivot(root, nb_elem);
	size_first = split_stack_pivot(p, root, pivot, nb_elem, &size_second);
	printf("nb_elem de taille %d\n", nb_elem);
	print_all(p);
	//print_n_stack(root, nb_elem);
	printf("rec a\n");
	rec_algo(p, p->pa, size_first);
	print_all(p);
	printf("rec b\n");
	rec_algo(p, p->pb, size_second);
	print_all(p);

	// i = 0;
	// while (i < size_first)
	// {
	// 	if ((*p->pb))
	// 		printf("repush %d on a\n", (*p->pb)->value);
	// 	else
	// 		printf("repush NULL on a\n");
	// 	get_instruction("pa", p, 1);
	// 	i++;
	// }
	// print_all(p);

	// i = 0;
	// while (i < size_second)
	// {
	// 	if ((*p->pa))
	// 		printf("repush %d on b\n", (*p->pa)->value);
	// 	else
	// 		printf("repush NULL on b\n");
	// 	get_instruction("pb", p, 1);
	// 	i++;
	// }


	printf("fin : %d\n", size_first + size_second);
	print_all(p);

}