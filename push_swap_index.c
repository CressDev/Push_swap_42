/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:41:16 by cress             #+#    #+#             */
/*   Updated: 2025/07/18 18:13:17 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

t_list	*get_stack_index(char **original, char **sorted)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		i;
	int		j;

	i = 0;
	stack_a = NULL;
	while (original[i] != NULL)
	{
		new_node = ft_lstnew((void *)(long)ft_atoi(original[i]));
		j = 0;
		while (sorted[j] != NULL)
		{
			if (ft_atoi(original[i]) == ft_atoi(sorted[j]))
			{
				new_node->index = j;
				break ;
			}
			j++;
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}
