/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:29 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 02:49:26 by qthierry         ###   ########.fr       */
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
