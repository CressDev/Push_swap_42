/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:43:43 by cress             #+#    #+#             */
/*   Updated: 2025/07/18 18:30:37 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = ft_lstlast(*stack_b);
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = ft_lstlast(*stack_a);
	second_last = *stack_a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*second_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	second_last = *stack_b;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}
