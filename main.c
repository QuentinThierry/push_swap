/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:09:14 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 02:50:48 by qthierry         ###   ########.fr       */
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
		list_insert(&stack, tmp);
		if (root == NULL)
			root = stack;
		stack = stack->next;
		args++;
	}
	return (root);
}

int main(int argc, char const **argv)
{
	t_stack	*root;
	t_stack	*it;

	root = parsing(argv[1]); //
	swap(&root);
	it = root;
	while (1)
	{
		printf("%d\n", it->value);
		it = it->next;
		if (it == root)
			break;
	}

	it = root;
	while (1)
	{
		printf("%d\n", it->value);
		it = it->prev;
		if (it == root)
			break;
	}
	return (0);
}
