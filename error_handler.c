/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:14:01 by cress             #+#    #+#             */
/*   Updated: 2025/07/21 11:31:58 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

int	error_no_digit(char **s_a)
{
	int	i;
	int	j;

	i = 0;
	while (s_a[i])
	{
		j = 0;
		if (s_a[i][0] == '-' || s_a[i][0] == '+')
			j++;
		while (s_a[i][j])
		{
			if (!ft_isdigit(s_a[i][j]))
			{
				free_mem(s_a);
				error_exit();
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	error_str(char **s_a)
{
	int	i;

	i = 0;
	while (s_a[i])
	{
		if (s_a[i][0] == '\0')
			error_exit();
		i++;
	}
	return (1);
}

int	error_dup(char	**s_a)
{
	int	i;
	int	j;

	i = 0;
	while (s_a[i])
	{
		j = i + 1;
		while (s_a[j])
		{
			if (ft_strncmp(s_a[i], s_a[j], ft_strlen(s_a[i])) == 0
				&& ft_strlen(s_a[i]) == ft_strlen(s_a[j]))
			{
				free_mem(s_a);
				error_exit();
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	error_handler(char **s_a)
{
	int	no_dig;
	int	dup;
	int	max;
	int	str;

	no_dig = error_no_digit(s_a);
	dup = error_dup(s_a);
	str = error_str(s_a);
	max = error_max(s_a);
	if ((no_dig == 1) && (dup == 1) && (max == 1) && (str == 1))
		return (1);
	else
		return (0);
}
