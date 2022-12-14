/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/14 02:16:30 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	main(int argc, char const **argv)
{
	t_stack	**root_a;
	t_stack	**root_b;
	char	*gnl_res;

	if (argc < 2)
		exit(EXIT_FAILURE);
	root_a = malloc(sizeof(t_stack *)); // protect
	root_b = malloc(sizeof(t_stack *)); // protect
	if (argc == 2)
		*root_a = parsing_one(argv[1]);
	else
		*root_a = parsing_mult(argc, (char **)argv);
	*root_b = NULL;
	if (!*root_a)
	{
		free(root_a);
		free(root_b);
		return (EXIT_FAILURE);
	}
	// printf("-----------a-----------\n");
	// print_list(root_a);
	// printf("-----------b-----------\n");
	// print_list(root_b);
	gnl_res = get_next_line(0);
	if (gnl_res)
		gnl_res[strlen(gnl_res) - 1] = 0;
	while (gnl_res)
	{
		get_instruction(gnl_res, root_a, root_b, 1);
		// printf("-----------a-----------\n");
		// print_list(root_a);
		// printf("-----------b-----------\n");
		// print_list(root_b);
		free(gnl_res);
		gnl_res = get_next_line(0);
		if (gnl_res)
			gnl_res[ft_strlen(gnl_res) - 1] = 0;
	}
	if (is_sorted(root_a) && !*root_b)
		printf("OK\n");
	else
		printf("KO\n");
	free_stack(*root_a);
	free_stack(*root_b);
	free(root_a);
	free(root_b);
	return (0);
}
