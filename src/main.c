/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/13 18:23:27 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/get_next_line.h"

void	print_list(t_stack **root)
{
	t_stack	*it;

	it = *root;
	if (!it)
	{
		printf("EMPTY\n");
		return ;
	}
	while (1)
	{
		printf("%d\n", it->value);
		it = it->next;
		if (it == *root)
			break;
	}
}

void	free_stack(t_stack **root)
{
	t_stack	*it;
	t_stack	*tmp;

	if (!*root)
		return ;
	it = *root;
	while (1)
	{
		tmp = it;
		it = it->next;
		free(tmp);
		if (it == *root)
			break;
	}
}

int main(int argc, char const **argv)
{
	t_stack	**root_a;
	t_stack	**root_b;
	char	*gnl_res;

	root_a = malloc(sizeof(t_stack *)); // protect
	root_b = malloc(sizeof(t_stack *)); // protect

	if (argc < 2)
	{
		printf("No args\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		*root_a = parsing_one(argv[1]);
	else
		*root_a = parsing_mult(argc, (char **)argv);
	*root_b = NULL;
	// *root_a = parsing(argv[1]); // protect and check entry errors

	printf("-----------a-----------\n");
	print_list(root_a);
	printf("-----------b-----------\n");
	print_list(root_b);

	gnl_res = get_next_line(1);
	if (gnl_res)
		gnl_res[strlen(gnl_res) - 1] = 0;

	while (gnl_res)
	{
		get_instruction(gnl_res, root_a, root_b);
		printf("-----------a-----------\n");
		print_list(root_a);
		printf("-----------b-----------\n");
		print_list(root_b);

		free(gnl_res);
		gnl_res = get_next_line(1);
		if (gnl_res)
			gnl_res[ft_strlen(gnl_res) - 1] = 0;
	}
	if (is_sorted(root_a) && !*root_b)
		printf("SORTED !!\n");

	free_stack(root_a);
	free_stack(root_b);
	free(root_a);
	free(root_b);
	return (0);
}
