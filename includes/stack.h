/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:47 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/14 17:34:54 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// list_operations
t_stack	*list_new(int value);
void	list_insert_after(t_stack **at_elem, t_stack *added);
void	list_insert_before(t_stack **at_elem, t_stack *added);
t_stack	*list_pop(t_stack **root);
void	list_addtop(t_stack **root, t_stack *added);

// list_operations2
void	free_stack(t_stack	*root);
void	print_stack(t_stack **root);
void	init_stack(int argc, char **argv, t_stack ***root_a, t_stack ***root_b);

// internal_instructions
void	swap(t_stack **root);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **root);
void	rrotate(t_stack **root);

// parsing
t_stack	*parsing_one(const char *string);
t_stack	*parsing_mult(int argc, char **argv);

// parser operations
void	get_instruction(char *string, t_stack **root_a,
			t_stack **root_b, int show);

//checker
int		is_sorted(t_stack **root);

// utils
int		equals(char	*s1, char *s2);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		has_duplicated_elem(char **string);

// ft_split
char	**ft_split(const char *string, char c);

#endif