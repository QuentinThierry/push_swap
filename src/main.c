/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 23:04:45 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_list(t_stack **root)
{
	t_stack	*it;

	it = *root;
	while (1)
	{
		printf("%d\n", it->value);
		it = it->next;
		if (it == *root)
			break;
	}
}

int main(int argc, char const **argv)
{
	t_stack	**root_a;
	t_stack	**root_b;
	t_stack	*it;

	root_a = malloc(sizeof(t_stack *)); // protect
	root_b = malloc(sizeof(t_stack *)); // protect

	if (argc < 2)
	{
		printf("Error.\n");
		exit(EXIT_FAILURE);
	}
	*root_a = parsing(argv[1]); // protect
	*root_b = parsing(argv[1]); // protect

	get_instruction("rb", root_a, root_b);
	it = *root_a;
	printf("-----------a-----------\n");
	print_list(root_a);
	printf("-----------b-----------\n");
	print_list(root_b);

	return (0);
}
