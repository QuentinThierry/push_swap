/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:59:40 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/14 17:34:22 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	wait_instructions(t_stack **root_a, t_stack **root_b)
{
	char	*gnl_res;

	gnl_res = get_next_line(0);
	if (gnl_res)
		gnl_res[strlen(gnl_res) - 1] = 0;
	while (gnl_res)
	{
		get_instruction(gnl_res, root_a, root_b, 0);
		free(gnl_res);
		gnl_res = get_next_line(0);
		if (gnl_res)
			gnl_res[ft_strlen(gnl_res) - 1] = 0;
	}
}

int	main(int argc, char const **argv)
{
	t_stack	**root_a;
	t_stack	**root_b;

	init_stack(argc, (char **)argv, &root_a, &root_b);
	wait_instructions(root_a, root_b);
	if (is_sorted(root_a) && !*root_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (EXIT_SUCCESS);
}
