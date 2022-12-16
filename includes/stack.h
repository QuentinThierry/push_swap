/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:47 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/16 18:29:30 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_piles
{
	t_stack	**pa;
	t_stack	**pb;
	int		pa_size;
	int		pb_size;
}	t_piles;

// list_operations
t_stack	*list_new(int value);
void	list_insert_after(t_stack **at_elem, t_stack *added);
void	list_insert_before(t_stack **at_elem, t_stack *added);
t_stack	*list_pop(t_stack **root);
void	list_push(t_stack **root, t_stack *added);

// list_operations2
void	free_stack(t_stack	*root);
void	print_stack(t_stack **root);
void	init_stack(int argc, char **argv, t_piles *p);
int		list_count(t_stack **root);

// internal_instructions
void	swap(t_stack **root);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **root);
void	rrotate(t_stack **root);

// parsing
t_stack	*parsing_one(const char *string);
t_stack	*parsing_mult(int argc, char **argv);

// parser operations
void	get_instruction(char *str, t_piles *p, int show);

//checker
int		is_sorted(t_stack **root);

// utils
int		equals(char	*s1, char *s2);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		has_duplicated_elem(char **string);

// algo_operations
void	split_stack_pivot(t_stack **dest, t_stack **src, t_stack *pivot);

// pivot_finder
t_stack	*find_pivot(t_stack **root, int size);

// ft_split
char	**ft_split(const char *string, char c);

#endif