/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:29 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/15 01:52:58 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	swap(t_stack	**root)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_val;

	if (!*root)
		return ;
	first = *root;
	second = first->next;
	tmp_val = first->value;
	first->value = second->value;
	second->value = tmp_val;
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
	{
		printf("empty stack\n");
		return ;
	}
	tmp = list_pop(src);
	list_push(dest, tmp);
	if (tmp == *src)
		*src = NULL;
}

void	rotate(t_stack **root)
{
	if (!*root)
		return ;
	*root = (*root)->next;
}

void	rrotate(t_stack **root)
{
	if (!*root)
		return ;
	*root = (*root)->prev;
}
