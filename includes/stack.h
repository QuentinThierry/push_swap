/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:47 by qthierry          #+#    #+#             */
/*   Updated: 2022/12/25 21:03:08 by qthierry         ###   ########.fr       */
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
	char	*buffer;
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

//utils2
char	*mini_join(char *str, char letter);
void	get_double_instruction(char *str1, char *str2, t_piles *p, int show);
void	int_swap(int *a, int *b);

// algo_operations
int		split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size, int *size_b);
void	rec_algo(t_piles *p, t_stack **stack, int nb_elem);

// printers
void	send_instruction(t_piles *p, char *str);

//sort_at_3
int		sort_at_3(t_piles *p, t_stack **root);

//sort_at_2
void	sort_at_2(t_piles *p, t_stack **root);

// pivot_finder
t_stack	*find_pivot(t_stack **root, int size);

// ft_split
char	**ft_split(const char *string, char c);

#endif