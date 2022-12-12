/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:47 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/12 19:25:08 by qthierry         ###   ########.fr       */
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
void	list_insert_after(t_stack **at_elem, t_stack *added);
void	list_insert_before(t_stack **at_elem, t_stack *added);
t_stack	*list_delfirst(t_stack **root);
void	list_addtop(t_stack **root, t_stack *added);

//internal_instructions
void	swap(t_stack **root);
void	push_a(t_stack **root_a, t_stack **root_b);


// ft_split
char	**ft_split(const char *string, char c);

#endif