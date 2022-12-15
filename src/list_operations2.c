/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:48 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/15 01:56:07 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	init_stack(int argc, char **argv, t_piles *p)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	p->pa = malloc(sizeof(t_stack *));
	if (!p->pa)
		return (exit(EXIT_FAILURE));
	p->pb = malloc(sizeof(t_stack *));
	if (!p->pb)
		return (free(p->pa), exit(EXIT_FAILURE));
	if (argc == 2)
		*p->pa = parsing_one(argv[1]);
	else
		*p->pa = parsing_mult(argc, argv);
	if (!*p->pa)
		return (free(p->pa), free(p->pb), exit(EXIT_FAILURE));
	*p->pb = NULL;
	p->pa_size = 0;
	p->pb_size = 0;
}

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

int	list_count(t_stack **root)
{
	t_stack	*it;
	int		count;

	if (!*root)
		return (0);
	count = 0;
	it = *root;
	while (1)
	{
		count++;
		it = it->next;
		if (it == *root)
			break ;
	}
	return (count);
}