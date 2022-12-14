/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:52:48 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/14 02:13:25 by qthierry         ###   ########.fr       */
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

void	print_list(t_stack **root)
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
