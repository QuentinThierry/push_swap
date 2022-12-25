/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:03:50 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/25 21:43:39 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static char	*get_instruction_merge(char *str1, char *str2)
{
	if ((equals(str1, "sa") && equals(str2, "sb")) ||
		(equals(str1, "sb") && equals(str1, "sa")))
		return ("ss");
	if ((equals(str1, "ra") && equals(str2, "rb")) ||
		(equals(str1, "rb") && equals(str1, "ra")))
		return ("rr");
	if ((equals(str1, "rra") && equals(str2, "rrb")) ||
		(equals(str1, "rrb") && equals(str1, "rra")))
		return ("rrr");
	return (NULL);
}

void	send_instruction(t_piles *p, char *str)
{
	char	*res;

	if (!p->buffer)
	{
		p->buffer = str;
		return ;
	}
	res = get_instruction_merge(p->buffer, str);
	if (!res)
	{
		write(1, p->buffer, ft_strlen(p->buffer));
		p->buffer = str;
	}
	else
	{
		write(1, res, ft_strlen(res));
		p->buffer = NULL;
	}
}
