/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:14:01 by cress             #+#    #+#             */
/*   Updated: 2025/07/05 20:35:43 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	error_no_digit(char **s_a)
{
	int	i;
	int	j;

	write (1, "inicio no digit\n", 16);
	i = 0;
	while (s_a[i])
	{
		j = 0;
		while (s_a[i][j])
		{
			if (s_a[i][0] == '-' || s_a[i][0] == '+')
				j++;
			if (ft_isdigit(s_a[i][j]) == 1)
				j++;
			else
			{
				write (2, "ERRORd\n", 7);
				free_mem(s_a);
				exit(1);
			}
		}
		i++;
	}
	return (1);
}

int	error_dup(char	**s_a)
{
	int	i;
	int	j;
	int	cmp_ok;

	write (1, "inicio dup\n", 11);
	i = 0;
	cmp_ok = 0;
	while (s_a[cmp_ok])
		cmp_ok++;
	j = i + 1;
	while (s_a[i])
	{
		while (s_a[j])
		{
			if (ft_strncmp(s_a[i], s_a[j], ft_strlen(s_a[j]) == 0))
				return (0);
			j++;
		}
		i++;
		if (cmp_ok == i)
			return (1);
	}
	return (0);
}


int error_handler(char **s_a)
{
	int	no_dig;
	int	dup;

	no_dig = error_no_digit(s_a);
	dup = error_dup(s_a);
	if ((no_dig == 1) && (dup == 1))
		return (1);
	else 
		return (0);
}