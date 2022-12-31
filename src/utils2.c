/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:09:06 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/31 18:22:01 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	get_double_instruction(char *str1, char *str2, t_piles *p, int show)
{
	get_instruction(str1, p, show);
	get_instruction(str2, p, show);
}

void	int_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*get_merge(char *str)
{
	if (equals(str, "ra\n") || equals(str, "rb\n"))
		return ("rr\n");
	if (equals(str, "rra\n") || equals(str, "rrb\n"))
		return ("rrr\n");
	if (equals(str, "sa\n") || equals(str, "sb\n"))
		return ("ss\n");
	return (NULL);
}
