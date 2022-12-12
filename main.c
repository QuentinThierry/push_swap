/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 19:27:37 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*parsing(const char *string)
{
	t_stack	*root;
	t_stack	*stack;
	t_stack	*tmp;
	char	**args;

	root = NULL;
	stack = NULL;
	args = ft_split(string, ' ');
	while (*args)
	{
		tmp = list_new(atoi(*args)); //
		if (!tmp)
			return (NULL);
		list_insert_after(&stack, tmp);
		if (root == NULL)
			root = stack;
		stack = stack->next;
		args++;
	}
	return (root);
}

int main(int argc, char const **argv)
{
	t_stack	**root_a;
	t_stack	**root_b;
	t_stack	*it;

	root_a = malloc(sizeof(t_stack *));
	root_b = malloc(sizeof(t_stack *));

	if (argc < 2)
	{
		printf("Error.\n");
		exit(EXIT_FAILURE);
	}
	*root_a = parsing(argv[1]); //
	*root_b = parsing(argv[1]); //
	// swap(&root_a);
	push_a(root_a, root_b); //bug quand b vide

	it = *root_a;
	printf("-----------a-----------\n");
	while (1)
	{
		printf("%d\n", it->value);
		it = it->next;
		if (it == *root_a)
			break;
	}
	printf("-----------b-----------\n");
	it = *root_b;
	while (1)
	{
		printf("%d\n", it->value);
		it = it->next;
		if (it == *root_b)
			break;
	}
	// printf("Reverse : \n");

	// it = root_a;
	// while (1)
	// {
	// 	printf("%d\n", it->value);
	// 	it = it->prev;
	// 	if (it == root_a)
	// 		break;
	// }
	return (0);
}
