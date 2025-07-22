/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:15:05 by cress             #+#    #+#             */
/*   Updated: 2025/07/18 21:02:31 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_split(char **split_a)
{
	int	i;
	int	current;
	int	next;

	i = 0;
	while (split_a[i] != NULL && split_a[i + 1] != NULL)
	{
		current = ft_atoi(split_a[i]);
		next = ft_atoi(split_a[i + 1]);
		if (current > next)
			return (0);
		i++;
	}
	return (1);
}

char	**sorted_split(char **split_a)
{
	int		i;
	int		j;
	int		current;
	int		next;
	char	*aux;

	i = 0;
	while (split_a[i] != NULL )
	{
		j = 0;
		while (split_a[j] != NULL && split_a[j + 1] != NULL)
		{
			current = ft_atoi(split_a[j]);
			next = ft_atoi(split_a[j + 1]);
			if (current > next)
			{
				aux = split_a[j];
				split_a[j] = split_a[j + 1];
				split_a[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
	return (split_a);
}

char	**dup_array(char **split_a, int size)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		error_exit();
	i = 0;
	while (split_a[i] && i < size)
	{
		copy[i] = ft_strdup(split_a[i]);
		if (!copy[i])
		{
			free_mem(copy);
			error_exit();
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	ft_count(char **split_a)
{
	int	i;

	i = 0;
	while (split_a[i])
		i++;
	return (i);
}

t_list	*stack_init_radix(char **split_a)
{
	char	**original_copy;
	char	**sorted_copy;
	t_list	*stack_a;

	if (is_sorted_split(split_a) == 1)
		return (NULL);
	original_copy = dup_array(split_a, ft_count(split_a));
	sorted_copy = dup_array(split_a, ft_count(split_a));
	sorted_copy = sorted_split(sorted_copy);
	stack_a = get_stack_index(original_copy, sorted_copy);
	free_mem(original_copy);
	free_mem(sorted_copy);
	return (stack_a);
}
