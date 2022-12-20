/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:09:06 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/20 15:16:36 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

char	*mini_join(char *str, char letter)
{
	if (letter == 'a')
	{
		if (equals(str, "s"))
			return ("sa");
		if (equals(str, "p"))
			return ("pa");
		if (equals(str, "r"))
			return ("ra");
		if (equals(str, "rr"))
			return ("rra");
	}
	else if (letter == 'b')
	{
		if (equals(str, "s"))
			return ("sb");
		if (equals(str, "p"))
			return ("pb");
		if (equals(str, "r"))
			return ("rb");
		if (equals(str, "rr"))
			return ("rrb");
	}
	return (write(1, "Error mini_join.\n", 18), str);
}

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
