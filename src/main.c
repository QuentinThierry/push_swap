/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/14 17:34:00 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	main(int argc, char const **argv)
{
	t_stack	**root_a;
	t_stack	**root_b;

	init_stack(argc, (char **)argv, &root_a, &root_b);

	printf("---------a---------\n");
	print_stack(root_a);
	printf("---------b---------\n");
	print_stack(root_b);

	free(root_a);
	free(root_b);
	return (0);
}
