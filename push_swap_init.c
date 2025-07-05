/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:15:05 by cress             #+#    #+#             */
/*   Updated: 2025/07/05 19:03:49 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_init(char **split_a)
{
	int		i;
	t_list	*st_a;
	void	*st;
	int		num;

	i = 0;
	st_a = NULL;
	write (1, "inicio init\n", 12);
	while (split_a[i] != NULL)
	{
		num = ft_atoi(split_a[i]);
		st = ft_lstnew((void *)(long)num);
		if (!st)
			write (1, "Error in init", 14);
		ft_lstadd_back(&st_a, st);
		i++;
	}
	return (st_a);
}
