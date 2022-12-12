/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:47 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 02:32:59 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

// stack_operations
t_stack	*list_new(int value);
void	list_insert(t_stack **at_elem, t_stack *added);

//instructions
void	swap(t_stack **root);

// ft_split
char	**ft_split(const char *string, char c);

#endif