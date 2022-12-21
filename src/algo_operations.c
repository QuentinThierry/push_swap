/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/21 18:27:24 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

// consider only use pivot value and not t_stack
// return the number of elements send to the other stack
int	split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size, int *size_b)
{
	int	i;
	int	size_a;
	int	total;
	int	nb_rotate;

	i = 0;
	size_a = 0;
	nb_rotate = 0;
	total = list_count(src);
	if (src == p->pa) // si on split sur a
	{
		while (i++ < size)
		{
			if ((*src)->value < pivot->value) // valeurs inferieurs son envoyees sur b
			{
				get_instruction("pb", p, 1);
				(*size_b)++;
			}
			else
			{
				get_instruction("ra", p, 1);
				nb_rotate++;
			}
		}
		// printf("ici : nb %d < %d tot-i (%d)\n", nb_rotate, total - i + 1, (nb_rotate < total - i + 1));
		if (nb_rotate < total - i + 1)
		{
			while (nb_rotate--)
				get_instruction("rra", p, 1);
		}
		else
		{
			while (i++ < total + 1)
			{
				// printf("ici\n");
				get_instruction("ra", p, 1);
			}
		}
		size_a = size - (*size_b);
	}
	else
	{
		while (i++ < size) // si on split sur b
		{
			if ((*src)->value >= pivot->value) // valeurs superieurs son envoyees sur a
			{
				get_instruction("pa", p, 1);
				size_a++;
			}
			else
				get_instruction("rb", p, 1);
		}
		if (total - i + 1 < nb_rotate)
		{
			while (nb_rotate--)
				get_instruction("rrb", p, 1);
		}
		else
		{
			while (i++ < total + 1)
			{
				// printf("ici\n");
				get_instruction("rb", p, 1);
			}
		}
		*size_b = size - size_a;
	}
	return (size_a);
	
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
	t_stack	*pivot;
	char	on_pile;
	int		size_a;
	int		size_b;

	if (root == p->pa)
		on_pile = 'a';
	else
		on_pile = 'b';
	
	if (nb_elem <= 3)
	{
		// printf("Tri %d elems\n", nb_elem);
		if (nb_elem == 2)
			sort_at_2(p, root);
		else
			sort_at_3(p, root);
		if (on_pile == 'b')
		{
			while (nb_elem--)
				get_instruction("pa", p, 1);
		}
		// printf("Fin sur nb_elem\n");
		return ;
	}
	size_b = 0;
	pivot = find_pivot(root, nb_elem);
	size_a = split_stack_pivot(p, root, pivot, nb_elem, &size_b);
	// print_all(p);
	// printf("TAILLE A : %d\n", size_a);
	// printf("TAILLE B : %d\n", size_b);
	// printf("Rentre rec A\n");
	rec_algo(p, p->pa, size_a);
	// print_all(p);
	// printf("Rentre rec B\n");
	rec_algo(p, p->pb, size_b);
	
	// printf("Fin algo\n");
	// print_all(p);
}