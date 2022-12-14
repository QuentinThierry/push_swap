/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:48 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/14 17:34:09 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	free_stack(t_stack	*root)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!root)
		return ;
	last = root->prev;
	while (root != last)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}
	free(last);
}

void	print_stack(t_stack **root)
{
	t_stack	*it;

	it = *root;
	if (!it)
	{
		printf("EMPTY\n");
		return ;
	}
	while (1)
	{
		printf("%d\n", it->value);
		it = it->next;
		if (it == *root)
			break ;
	}
}

void	init_stack(int argc, char **argv, t_stack ***root_a, t_stack ***root_b)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	*root_a = malloc(sizeof(t_stack *));
	if (!*root_a)
		return (exit(EXIT_FAILURE));
	*root_b = malloc(sizeof(t_stack *));
	if (!*root_b)
		return (free(*root_a), exit(EXIT_FAILURE));
	if (argc == 2)
		**root_a = parsing_one(argv[1]);
	else
		**root_a = parsing_mult(argc, argv);
	**root_b = NULL;
}
