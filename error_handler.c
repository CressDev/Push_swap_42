/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:14:01 by cress             #+#    #+#             */
/*   Updated: 2025/07/08 21:34:53 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_no_digit(char **s_a, int out_free)
{
	int	i;
	int	j;

	write (1, "inicio no digit\n", 16);
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
				write (2, "ERRORd\n", 7);
				if (out_free)
					free_mem(s_a);
				exit(1);
			}¡p
			j++;
		}
		i++;
	}
	return (1);
}

int	error_str(char **s_a)
{
	int	i;

	write (1, "inicio str\n", 11);
	i = 0;
	while (s_a[i])
	{
		if (s_a[i][0] == '\0' || s_a[i][0] == '"')
		{
			write (2, "ERRORs\n", 7);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	error_dup(char	**s_a, int out_free)
{
	int	i;
	int	j;

	write (1, "inicio dup\n", 11);
	i = 0;
	while (s_a[i])
	{
		j = i + 1;
		while (s_a[j])
		{
			if (ft_strncmp(s_a[i], s_a[j], ft_strlen(s_a[i])) == 0
				&& ft_strlen(s_a[i]) == ft_strlen(s_a[j]))
			{
				write (2, "ERRORdup\n", 9);
				if (out_free)
					free_mem(s_a);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	error_handler(char **s_a, int out_free)
{
	int	no_dig;
	int	dup;
	int	max;
	int	str;

	no_dig = error_no_digit(s_a, out_free);
	dup = error_dup(s_a, out_free);
	str = error_str(s_a);
	max = error_max(s_a, out_free);
	if ((no_dig == 1) && (dup == 1) && (max == 1) && str == 1)
		return (1);
	else
		return (0);
}