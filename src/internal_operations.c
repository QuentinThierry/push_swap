/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:29 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 22:16:47 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack	**root)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_val;

	first = *root;
	second = first->next;
	tmp_val = first->value;
	first->value = second->value;
	second->value = tmp_val;
}

void	push(t_stack **dest, t_stack **src)
{
	int	tmp_val;
	t_stack	*tmp;

	if (!*dest || !*src)
	{
		printf("empty stack\n");
		return ;
	}
	tmp = list_delfirst(src);
	list_addtop(dest, tmp);
	if (tmp == *src)
		*src = NULL;
}

void	rotate(t_stack **root)
{
	*root = (*root)->next;
}

void	rrotate(t_stack **root)
{
	*root = (*root)->prev;
}
