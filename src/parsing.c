/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:17:19 by qthierry          #+#    #+#             */
/*   Updated: 2023/01/04 16:03:56 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static t_stack	*list_from_str(char *string)
{
	long	value;
	t_stack	*tmp;

	value = ft_atol(string);
	if (value >= 2147483648)
		return (NULL);
	value = (int)value;
	tmp = list_new(value);
	return (tmp);
}

static void	free_split(char **args)
{
	size_t	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

t_stack	*parsing_one(const char *string)
{
	t_stack		*root;
	t_stack		*stack;
	t_stack		*tmp;
	size_t		i;
	char		**args;

	root = NULL;
	stack = NULL;
	args = ft_split(string, ' ');
	if (!args || has_duplicated_elem(args))
		return (free_split(args), NULL);
	i = 0;
	while (args[i])
	{
		tmp = list_from_str(args[i]);
		if (!tmp)
			return (free_stack(root), free_split(args), NULL);
		list_insert_after(&stack, tmp);
		if (root == NULL)
			root = stack;
		stack = stack->next;
		i++;
	}
	free_split(args);
	return (root);
}

t_stack	*parsing_mult(int argc, char **argv)
{
	t_stack	*root;
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	root = NULL;
	stack = NULL;
	if (has_duplicated_elem(argv))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		tmp = list_from_str(argv[i]);
		if (!tmp)
			return (free_stack(root), NULL);
		list_insert_after(&stack, tmp);
		if (root == NULL)
			root = stack;
		stack = stack->next;
		i++;
	}
	return (root);
}
