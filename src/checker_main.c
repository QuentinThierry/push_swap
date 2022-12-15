/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:59:40 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/15 01:46:38 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/get_next_line.h"

static void	wait_instructions(t_piles	*p)
{
	char	*gnl_res;

	gnl_res = get_next_line(0);
	if (gnl_res)
		gnl_res[strlen(gnl_res) - 1] = 0;
	while (gnl_res)
	{
		get_instruction(gnl_res, p, 0);
		free(gnl_res);
		gnl_res = get_next_line(0);
		if (gnl_res)
			gnl_res[ft_strlen(gnl_res) - 1] = 0;
	}
}

int	main(int argc, char const **argv)
{
	t_piles	p;

	init_stack(argc, (char **)argv, &p);
	wait_instructions(&p);
	if (is_sorted(p.pa) && !p.pb)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(*p.pa);
	free_stack(*p.pb);
	free(p.pa);
	free(p.pb);
	return (EXIT_SUCCESS);
}
