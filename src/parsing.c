/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:17:19 by qthierry          #+#    #+#             */
/*   Updated: 2023/03/02 22:57:58 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static t_stack	*list_from_str(char *string)
{
	long	value;
	t_stack	*tmp;
	int		error;

	error = 0;
	value = ft_atoi_sec(string, &error);
	if (error)
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
	if (!args)
		return (NULL);
	i = -1;
	while (args[++i])
	{
		tmp = list_from_str(args[i]);
		if (!tmp)
			return (free_stack(root), free_split(args), NULL);
		list_insert_after(&stack, tmp);
		if (root == NULL)
			root = stack;
		stack = stack->next;
	}
	if (has_duplicated_elem(root))
		return (free_split(args), free_stack(root), NULL);
	return (free_split(args), root);
}

t_stack	*parsing_mult(int argc, char **argv)
{
	t_stack	*root;
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	root = NULL;
	stack = NULL;
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
	if (has_duplicated_elem(root))
		return (free_stack(root), NULL);
	return (root);
}
