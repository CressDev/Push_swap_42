/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:54:24 by cress             #+#    #+#             */
/*   Updated: 2025/07/20 11:17:19 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	error_exit(void);
void	free_mem(char **s);
void	free_list(t_list *lst);
void	cmp_argv_empty(char **argv);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	sort_by_bit(t_list **stack_a, t_list **stack_b, int bit_pos);
void	three_sort(t_list **stack_a);
void	five_sort(t_list **stack_a, t_list **stack_b);
int		error_handler(char **s_a);
int		error_str(char **s_a);
int		error_max(char **s_a);
int		error_dup(char	**s_a);
int		error_no_digit(char **s_a);
int		cmp_str_empty(char *argv);
int		ft_count(char **split_a);
int		get_max_bits(t_list *stack);
int		is_negative(char *str, int *is_po_or_ne);
int		cmp_max_min(char *str, int start, int len, int is_po_or_ne);
int		is_more_or_less(char *str);
int		is_sorted_split(char **split_a);
char	*ft_strjoin_multiple(char **argv);
char	**sorted_split(char **split_a);
char	**dup_array(char **split_a, int size);
t_list	*stack_init(char **split_a);
t_list	*stack_init_radix(char **split_a);
t_list	*get_stack_index(char **original, char **sorted);
#endif
