/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:09:01 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/23 18:04:31 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

// int	find_pos_of_last_sup(t_stack **src, int pivot_value, int size)
// {
// 	int		i;
// 	int		j;
// 	t_stack	*it;

// 	i = 0;
// 	it = *src;
// 	j = 0;
// 	while (it != NULL && i < size)
// 	{
// 		if (it->value > pivot_value)
// 			j = 0;
// 		else
// 			j++;
// 		it = it->next;
// 		if (it == *src)
// 			break ;
// 		i++;
// 	}
// 	printf("ici : %d / %d / %d\n", size, j, size - j);
// 	return (size - j);
// }

int	split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size, int *size_b)
{
	int	i;
	int	size_a;
	int	total;
	int	nb_rotate;
	int	virtual_size;

	i = 0;
	size_a = 0;
	nb_rotate = 0;
	total = list_count(src);
	if (src == p->pa) // si on split sur a
	{
		while (i++ < size)
		{
			if ((*src)->value < pivot->value)
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
		if (nb_rotate < total - i + 1)
		{
			while (nb_rotate--)
				get_instruction("rra", p, 1);
		}
		else
		{
			while (i++ < total + 1)
				get_instruction("ra", p, 1);
		}
		size_a = size - (*size_b);
	}
	else // si on split sur b
	{
		while (i++ < size)
		{
			if ((*src)->value >= pivot->value)
			{
				get_instruction("pa", p, 1);
				size_a++;
			}
			else
			{
				get_instruction("rb", p, 1);
				nb_rotate++;
			}
		}
		if (nb_rotate < total - i + 1)
		{
			while (nb_rotate--)
				get_instruction("rrb", p, 1);
		}
		else
		{
			while (i++ < total + 1)
				get_instruction("rb", p, 1);
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
		if (nb_elem == 2)
			sort_at_2(p, root);
		else
			nb_elem = sort_at_3(p, root);
		if (on_pile == 'b')
		{
			while (nb_elem--)
				get_instruction("pa", p, 1);
		}
		return ;
	}
	size_b = 0;
	pivot = find_pivot(root, nb_elem);
	size_a = split_stack_pivot(p, root, pivot, nb_elem, &size_b);
	rec_algo(p, p->pa, size_a);
	rec_algo(p, p->pb, size_b);
}