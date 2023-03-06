/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:47 by qthierry          #+#    #+#             */
/*   Updated: 2023/03/02 21:37:50 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

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
	t_list	*instruc;
	t_list	*buffer_a;
	t_list	*buffer_b;
}	t_piles;

// list_operations.c
t_stack	*list_new(int value);
void	list_insert_after(t_stack **at_elem, t_stack *added);
void	list_insert_before(t_stack **at_elem, t_stack *added);
t_stack	*list_pop(t_stack **root);
void	list_push(t_stack **root, t_stack *added);

// list_operations2.c
void	free_stack(t_stack	*root);
void	print_stack(t_stack **root);
void	init_stack(int argc, char **argv, t_piles *p);
int		list_count(t_stack **root);

// internal_instructions.c
void	swap(t_stack **root);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **root);
void	rrotate(t_stack **root);

// parsing.c
t_stack	*parsing_one(const char *string);
t_stack	*parsing_mult(int argc, char **argv);

// parser operations.c
void	get_instruction(char *str, t_piles *p, int show);

//checker.c
int		is_sorted(t_stack **root, int is_descending);

// utils.c
int		equals(char	*s1, char *s2);
int		ft_isdigit(int c);
int		ft_atoi_sec(const char *nptr, int *error);
size_t	ft_strlen(const char *s);
int		has_duplicated_elem(t_stack *stack);

//utils2.c
void	get_double_instruction(char *str1, char *str2, t_piles *p, int show);
void	int_swap(int *a, int *b);
char	*get_merge(char *str);

// algo_operations.c
int		find_pos_of_last(t_piles *p, t_stack **src, int pivot_value, int size);
int		split_stack_pivot(t_piles *p, t_stack **src, t_stack *pivot, int size);
void	rec_algo(t_piles *p, t_stack **stack, int nb_elem);

// split_on_a.c
int		split_on_a(t_piles *p, t_stack **root, t_stack *pivot, int size);

// split_on_b.c
int		split_on_b(t_piles *p, t_stack **root, t_stack *pivot, int size);

// printers.c
void	send_instruction(t_piles *p, char *str);
void	append_instruction(t_piles *p);

//special_sort.c
void	special_sort_3(t_piles *p, t_stack **root);

//sort_at_3.c
int		sort_at_3(t_piles *p, t_stack **root);

//sort_at_2.c
void	sort_at_2(t_piles *p, t_stack **root);

// pivot_finder.c
t_stack	*find_pivot(t_stack **root, int size, int is_first);

// ft_split.c
char	**ft_split(const char *string, char c);

// list_utils.c
t_list	*ft_lst_new(char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_tlist(t_list **lst);

// merge_instruction.c
t_list	*merge_matches(t_piles *p);
void	add_instruction(t_piles *p, char *instruc);

// final_merge.c
void	final_merge(t_list **instruc);

#endif
