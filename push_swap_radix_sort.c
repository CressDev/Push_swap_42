/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:42:22 by cress             #+#    #+#             */
/*   Updated: 2025/07/21 18:55:47 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack_a)
{
	int		max_index;
	t_list	*current;

	if (*stack_a == NULL)
		error_exit();
	max_index = (*stack_a)->index;
	current = (*stack_a)->next;
	while (current)
	{
		if (max_index < current->index)
			max_index = current->index;
		current = current->next;
	}
	if ((*stack_a)->index == max_index)
		ra(stack_a);
	if ((*stack_a)->next->index == max_index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	five_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = 0;
	while (min < 2)
	{
		while ((*stack_a)->index != min)
		{
			if ((*stack_a)->next->index == min
				|| (*stack_a)->next->next->index == min)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		min++;
	}
	three_sort(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_by_bit(t_list **stack_a, t_list **stack_b, int bit_pos)
{
	int	stack_size;
	int	i;

	stack_size = ft_lstsize(*stack_a);
	i = 0;
	while (i < stack_size)
	{
		if ((((*stack_a)->index >> bit_pos) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

int	get_max_bits(t_list *stack)
{
	int		max_index;
	int		bits;
	t_list	*current;

	max_index = 0;
	current = stack;
	bits = 0;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	bit_position;

	if (ft_lstsize(*stack_a) == 3)
		three_sort(stack_a);
	else if (ft_lstsize(*stack_a) == 5)
		five_sort(stack_a, stack_b);
	else
	{
		max_bits = get_max_bits(*stack_a);
		bit_position = 0;
		while (bit_position < max_bits)
		{
			sort_by_bit(stack_a, stack_b, bit_position);
			bit_position++;
		}
	}
}
